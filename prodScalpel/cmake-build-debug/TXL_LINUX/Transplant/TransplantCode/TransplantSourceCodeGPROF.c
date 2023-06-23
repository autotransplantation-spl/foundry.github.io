#include "TransplantHeader.h"
#include <system.h>
#include <system-ioctl.h>
#include <signal.h>
#include <closeout.h>
#include <fnmatch.h>
#include <human.h>
#include <quotearg.h>
#include <rmt.h>
#include <regex.h>
#include <hash.h>
#include <inttostr.h>
#include <wordsplit.h>
#include <argp.h>
#include <priv-set.h>
#include <config.h>
# include <sys/acl.h>
#include <xgetcwd.h>
#include <unlinkdir.h>
#include <utimens.h>

void mv_begin_write (const char *file_name, off_t totsize, off_t sizeleft) {
    if (multi_volume_option) {
        struct bufmap *bp = xmalloc (sizeof bp[0]);
        if (bufmap_tail)
            bufmap_tail->next = bp;
        else
            bufmap_head = bp;
        bufmap_tail = bp;
        bp->next = NULL;
        bp->start = current_block - record_start;
        bp->file_name = xstrdup (file_name);
        bp->sizetotal = totsize;
        bp->sizeleft = sizeleft;
    }
}

static void bufmap_free (struct bufmap *mark) {
    struct bufmap *map;
    for (map = bufmap_head; map && map != mark;) {
        struct bufmap *next = map->next;
        free (map->file_name);
        free (map);
        map = next;
    }
    bufmap_head = map;
    if (!bufmap_head)
        bufmap_tail = bufmap_head;
}

void buffer_write_global_xheader (void) {
    xheader_write_global (&dummy.xhdr);
}

static void set_volume_start_time (void) {
    gettime (&volume_start_time);
    last_stat_time = volume_start_time;
}

void compute_duration (void) {
    struct timespec now;
    gettime (&now);
    duration += ((now.tv_sec - last_stat_time.tv_sec) + (now.tv_nsec - last_stat_time.tv_nsec) / 1e9);
    gettime (&last_stat_time);
}

off_t current_block_ordinal (void) {
    return record_start_block + (current_block - record_start);
}

void set_next_block_after (union block *block) {
    while (block >= current_block)
        current_block++;
    if (current_block > record_end)
        abort ();
}

size_t available_space_after (union block *pointer) {
    return record_end->buffer - pointer->buffer;
}

void xclose (int fd) {
    if (close (fd) != 0)
        close_error (_ ("(pipe)"));
}

static void init_buffer (void) {
    if (!record_buffer_aligned[record_index])
        record_buffer_aligned[record_index] = page_aligned_alloc (&record_buffer[record_index], record_size);
    record_start = record_buffer_aligned[record_index];
    current_block = record_start;
    record_end = record_start + blocking_factor;
}

static void _open_archive (enum access_mode wanted_access) {
    int backed_up_flag = 0;
    if (record_size == 0)
        FATAL_ERROR ((0, 0, _ ("Invalid value for record_size")));
    if (archive_names == 0)
        FATAL_ERROR ((0, 0, _ ("No archive name given")));
    tar_stat_destroy (&current_stat_info);
    record_index = 0;
    init_buffer ();
    access_mode = wanted_access == ACCESS_UPDATE ? ACCESS_READ : wanted_access;
    read_full_records = read_full_records_option;
    records_read = 0;
    if (use_compress_program_option) {
        switch (wanted_access) {
        case ACCESS_READ :
            child_pid = sys_child_open_for_uncompress ();
            read_full_records = true;
            record_end = record_start;
            break;
        case ACCESS_WRITE :
            child_pid = sys_child_open_for_compress ();
            break;
        case ACCESS_UPDATE :
            abort ();
            break;
        }
        if (!index_file_name && wanted_access == ACCESS_WRITE && strcmp (archive_name_array[0], "-") == 0)
            stdlis = stderr;
    }
    else if (strcmp (archive_name_array[0], "-") == 0) {
        read_full_records = true;
        if (verify_option)
            FATAL_ERROR ((0, 0, _ ("Cannot verify stdin/stdout archive")));
        switch (wanted_access) {
        case ACCESS_READ :
            {
                bool shortfile;
                enum compress_type type;
                archive = STDIN_FILENO;
                type = check_compressed_archive (&shortfile);
                if (type != ct_tar && type != ct_none)
                    FATAL_ERROR ((0, 0, _ ("Archive is compressed. Use %s option"), compress_option (type)));
                if (shortfile)
                    ERROR ((0, 0, _ ("This does not look like a tar archive")));
            }
            break;
        case ACCESS_WRITE :
            archive = STDOUT_FILENO;
            if (!index_file_name)
                stdlis = stderr;
            break;
        case ACCESS_UPDATE :
            archive = STDIN_FILENO;
            write_archive_to_stdout = true;
            record_end = record_start;
            if (!index_file_name)
                stdlis = stderr;
            break;
        }
    }
    else
        switch (wanted_access) {
        case ACCESS_READ :
            archive = open_compressed_archive ();
            if (archive >= 0)
                guess_seekable_archive ();
            break;
        case ACCESS_WRITE :
            if (backup_option) {
                maybe_backup_file (archive_name_array[0], 1);
                backed_up_flag = 1;
            }
            if (verify_option)
                archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY, MODE_RW, rsh_command_option);
            else
                archive = rmtcreat (archive_name_array[0], MODE_RW, rsh_command_option);
            break;
        case ACCESS_UPDATE :
            archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY, MODE_RW, rsh_command_option);
            switch (check_compressed_archive (NULL)) {
            case ct_none :
            case ct_tar :
                break;
            default :
                FATAL_ERROR ((0, 0, _ ("Cannot update compressed archives")));
            }
            break;
        }
    if (archive < 0 || (!_isrmt (archive) && !sys_get_archive_stat ())) {
        int saved_errno = errno;
        if (backed_up_flag)
            undo_last_backup ();
        errno = saved_errno;
        open_fatal (archive_name_array [0]);
    }
    sys_detect_dev_null_output ();
    sys_save_archive_dev_ino ();
    SET_BINARY_MODE (archive);
    switch (wanted_access) {
    case ACCESS_READ :
        find_next_block ();
        break;
    case ACCESS_UPDATE :
    case ACCESS_WRITE :
        records_written = 0;
        break;
    }
}

static ssize_t _flush_write (void) {
    ssize_t status;
    checkpoint_run (true);
    if (tape_length_option && tape_length_option <= bytes_written) {
        errno = ENOSPC;
        status = 0;
    }
    else if (dev_null_output)
        status = record_size;
    else
        status = sys_write_archive_buffer ();
    if (status && multi_volume_option && !inhibit_map) {
        struct bufmap *map = bufmap_locate (status);
        if (map) {
            size_t delta = status - map->start * BLOCKSIZE;
            if (delta > map->sizeleft)
                delta = map->sizeleft;
            map->sizeleft -= delta;
            if (map->sizeleft == 0)
                map = map->next;
            bufmap_reset (map, map ? (-map->start) : 0);
        }
    }
    return status;
}

void flush_archive (void) {
    size_t buffer_level = current_block->buffer - record_start->buffer;
    record_start_block += record_end - record_start;
    current_block = record_start;
    record_end = record_start + blocking_factor;
    if (access_mode == ACCESS_READ && time_to_start_writing) {
        access_mode = ACCESS_WRITE;
        time_to_start_writing = false;
        backspace_output ();
    }
    switch (access_mode) {
    case ACCESS_READ :
        flush_read ();
        break;
    case ACCESS_WRITE :
        flush_write_ptr (buffer_level);
        break;
    case ACCESS_UPDATE :
        abort ();
    }
}

void close_archive (void) {
    if (time_to_start_writing || access_mode == ACCESS_WRITE) {
        flush_archive ();
        if (current_block > record_start)
            flush_archive ();
    }
    compute_duration ();
    if (verify_option)
        verify_volume ();
    if (rmtclose (archive) != 0)
        close_error (*archive_name_cursor);
    sys_wait_for_child (child_pid, hit_eof);
    tar_stat_destroy (&current_stat_info);
    free (record_buffer [0]);
    free (record_buffer [1]);
    bufmap_free (NULL);
}

static void _gnu_flush_write (size_t buffer_level) {
    ssize_t status;
    union block *header;
    char *copy_ptr;
    size_t copy_size;
    size_t bufsize;
    struct bufmap *map;
    status = _flush_write ();
    if (status != record_size && !multi_volume_option)
        archive_write_error (status);
    else {
        if (status)
            records_written++;
        bytes_written += status;
    }
    if (status == record_size) {
        return;
    }
    map = bufmap_locate (status);
    if (status % BLOCKSIZE) {
        ERROR ((0, 0, _ ("write did not end on a block boundary")));
        archive_write_error (status);
    }
    if (status < 0 && errno != ENOSPC && errno != EIO && errno != ENXIO)
        archive_write_error (status);
    if (!new_volume (ACCESS_WRITE))
        return;
    tar_stat_destroy (&dummy);
    increase_volume_number ();
    prev_written += bytes_written;
    bytes_written = 0;
    copy_ptr = record_start->buffer + status;
    copy_size = buffer_level - status;
    record_index = !record_index;
    init_buffer ();
    inhibit_map = 1;
    if (volume_label_option)
        add_volume_label ();
    if (map)
        add_multi_volume_header (map);
    write_extended (true, &dummy, find_next_block ());
    tar_stat_destroy (&dummy);
    if (map)
        add_chunk_header (map);
    header = find_next_block ();
    bufmap_reset (map, header -record_start);
    bufsize = available_space_after (header);
    inhibit_map = 0;
    while (bufsize < copy_size) {
        memcpy (header->buffer, copy_ptr, bufsize);
        copy_ptr += bufsize;
        copy_size -= bufsize;
        set_next_block_after (header +(bufsize - 1) / BLOCKSIZE);
        header = find_next_block ();
        bufsize = available_space_after (header);
    }
    memcpy (header->buffer, copy_ptr, copy_size);
    memset (header->buffer + copy_size, 0, bufsize -copy_size);
    set_next_block_after (header +(copy_size - 1) / BLOCKSIZE);
    find_next_block ();
}

static void gnu_flush_write (size_t buffer_level) {
    flush_write_ptr = simple_flush_write;
    _gnu_flush_write (buffer_level);
    flush_write_ptr = gnu_flush_write;
}

void open_archive (enum access_mode wanted_access) {
    flush_read_ptr = gnu_flush_read;
    flush_write_ptr = gnu_flush_write;
    _open_archive (wanted_access);
    switch (wanted_access) {
    case ACCESS_READ :
    case ACCESS_UPDATE :
        if (volume_label_option)
            match_volume_label ();
        break;
    case ACCESS_WRITE :
        records_written = 0;
        if (volume_label_option)
            write_volume_label ();
        break;
    }
    set_volume_start_time ();
}

static bool _transform_name_to_obstack (int flags, char *input, char **output) {
    struct transform *tf;
    bool alloced = false;
    if (!stk_init) {
        obstack_init (&stk);
        stk_init = true;
    }
    for (tf = transform_head; tf; tf = tf->next) {
        if (tf->flags & flags) {
            _single_transform_name_to_obstack (tf, input);
            input = obstack_finish (&stk);
            alloced = true;
        }
    }
    *output = input;
    return alloced;
}

bool transform_name_fp (char **pinput, int flags, char * (*fun) (char *, void *), void *dat) {
    char *str;
    bool ret = _transform_name_to_obstack (flags, *pinput, &str);
    if (ret) {
        assign_string (pinput, fun ? fun (str, dat) : str);
        obstack_free (&stk, str);
    }
    else if (fun) {
        *pinput = NULL;
        assign_string (pinput, fun (str, dat));
        free (str);
        ret = true;
    }
    return ret;
}

bool transform_name (char **pinput, int type) {
    return transform_name_fp (pinput, type, NULL, NULL);
}

void xheader_write_global (struct xheader *xhdr) {
    if (keyword_global_override_list) {
        struct keyword_list *kp;
        xheader_init (xhdr);
        for (kp = keyword_global_override_list; kp; kp = kp->next)
            code_string (kp->value, kp->pattern, xhdr);
    }
    if (xhdr->stk) {
        char *name;
        xheader_finish (xhdr);
        name = xheader_ghdr_name ();
        xheader_write (XGLTYPE, name, start_time.tv_sec, xhdr);
        free (name);
    }
}

void xheader_xattr_free (struct xattr_array *xattr_map, size_t xattr_map_size) {
    size_t scan = 0;
    while (scan < xattr_map_size) {
        free (xattr_map[scan].xkey);
        free (xattr_map[scan].xval_ptr);
        ++scan;
    }
    free (xattr_map);
}

void xheader_destroy (struct xheader *xhdr) {
    if (xhdr->stk) {
        obstack_free (xhdr->stk, NULL);
        free (xhdr->stk);
        xhdr->stk = NULL;
    }
    else
        free (xhdr->buffer);
    xhdr->buffer = 0;
    xhdr->size = 0;
}

void uid_to_uname (uid_t uid, char **uname) {
    struct passwd *passwd;
    if (uid != 0 && uid == cached_no_such_uid) {
        *uname = xstrdup ("");
        return;
    }
    if (!cached_uname || uid != cached_uid) {
        passwd = getpwuid (uid);
        if (passwd) {
            cached_uid = uid;
            assign_string (&cached_uname, passwd->pw_name);
        }
        else {
            cached_no_such_uid = uid;
            *uname = xstrdup ("");
            return;
        }
    }
    *uname = xstrdup (cached_uname);
}

void gid_to_gname (gid_t gid, char **gname) {
    struct group *group;
    if (gid != 0 && gid == cached_no_such_gid) {
        *gname = xstrdup ("");
        return;
    }
    if (!cached_gname || gid != cached_gid) {
        group = getgrgid (gid);
        if (group) {
            cached_gid = gid;
            assign_string (&cached_gname, group->gr_name);
        }
        else {
            cached_no_such_gid = gid;
            *gname = xstrdup ("");
            return;
        }
    }
    *gname = xstrdup (cached_gname);
}

static void name_list_advance (void) {
    struct name_elt *elt = name_head;
    name_head = elt->next;
    if (name_head)
        name_head->prev = NULL;
    free (elt);
}

static void copy_name (struct name_elt *ep) {
    const char *source;
    size_t source_len;
    char *cursor;
    source = ep->v.name;
    source_len = strlen (source);
    if (name_buffer_length < source_len) {
        do {
            name_buffer_length *= 2;
            if (!name_buffer_length)
                xalloc_die ();
        }
        while (name_buffer_length < source_len);
        free (name_buffer);
        name_buffer = xmalloc (name_buffer_length +2);
    }
    strcpy (name_buffer, source);
    cursor = name_buffer + strlen (name_buffer) - 1;
    while (cursor > name_buffer && ISSLASH (*cursor))
        *cursor-- = '\0';
}

bool excluded_name (char const *name) {
    return excluded_file_name (excluded, name +FILE_SYSTEM_PREFIX_LEN (name));
}

static void to_octal (uintmax_t value, char *where, size_t size) {
    uintmax_t v = value;
    size_t i = size;
    do {
        where[--i] = '0' + (v & ((1 << LG_8) - 1));
        v >>= LG_8;
    }
    while (i);
}

static void tar_copy_str (char *dst, const char *src, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        if (!(dst[i] = src[i]))
            break;
}

static void tar_name_copy_str (char *dst, const char *src, size_t len) {
    tar_copy_str (dst, src, len);
    if (archive_format == OLDGNU_FORMAT)
        dst[len - 1] = 0;
}

static bool to_chars (int negative, uintmax_t value, size_t valsize, uintmax_t (*substitute) (int *), char *where, size_t size, const char *type);

static bool to_chars (int negative, uintmax_t value, size_t valsize, uintmax_t (*substitute) (int *), char *where, size_t size, const char *type) {
    int gnu_format = (archive_format == GNU_FORMAT || archive_format == OLDGNU_FORMAT);
    if (!negative && value <= MAX_VAL_WITH_DIGITS (size -1, LG_8)) {
        where[size - 1] = '\0';
        to_octal (value, where, size -1);
        return true;
    }
    else if (gnu_format) {
        if (((negative ? -1 - value : value) <= MAX_VAL_WITH_DIGITS (size -1, LG_256))) {
            where[0] = negative ? -1 : 1 << (LG_256 - 1);
            to_base256 (negative, value, where +1, size -1);
            return true;
        }
        else if (negative && valsize * CHAR_BIT <= (size - 1) * LG_8) {
            static int warned_once;
            if (!warned_once) {
                warned_once = 1;
                WARN ((0, 0, _ ("Generating negative octal headers")));
            }
            where[size - 1] = '\0';
            to_octal (value &MAX_VAL_WITH_DIGITS (valsize *CHAR_BIT, 1), where, size -1);
            return true;
        }
    }
    else
        substitute = NULL;
    return to_chars_subst (negative, gnu_format, value, valsize, substitute, where, size, type);
}

static bool gid_to_chars (gid_t v, char *p, size_t s) {
    return to_chars (v < 0, (uintmax_t) v, sizeof v, gid_substitute, p, s, "gid_t");
}

static bool mode_to_chars (mode_t v, char *p, size_t s) {
    int negative;
    uintmax_t u;
    if (S_ISUID == TSUID && S_ISGID == TSGID && S_ISVTX == TSVTX && S_IRUSR == TUREAD && S_IWUSR == TUWRITE && S_IXUSR == TUEXEC && S_IRGRP == TGREAD && S_IWGRP == TGWRITE && S_IXGRP == TGEXEC && S_IROTH == TOREAD && S_IWOTH == TOWRITE && S_IXOTH == TOEXEC && archive_format != POSIX_FORMAT && archive_format != USTAR_FORMAT && archive_format != GNU_FORMAT) {
        negative = v < 0;
        u = v;
    }
    else {
        negative = 0;
        u = ((v & S_ISUID ? TSUID : 0) | (v & S_ISGID ? TSGID : 0) | (v & S_ISVTX ? TSVTX : 0) | (v & S_IRUSR ? TUREAD : 0) | (v & S_IWUSR ? TUWRITE : 0) | (v & S_IXUSR ? TUEXEC : 0) | (v & S_IRGRP ? TGREAD : 0) | (v & S_IWGRP ? TGWRITE : 0) | (v & S_IXGRP ? TGEXEC : 0) | (v & S_IROTH ? TOREAD : 0) | (v & S_IWOTH ? TOWRITE : 0) | (v & S_IXOTH ? TOEXEC : 0));
    }
    return to_chars (negative, u, sizeof v, 0, p, s, "mode_t");
}

bool off_to_chars (off_t v, char *p, size_t s) {
    return to_chars (v < 0, (uintmax_t) v, sizeof v, 0, p, s, "off_t");
}

bool time_to_chars (time_t v, char *p, size_t s) {
    return to_chars (v < 0, (uintmax_t) v, sizeof v, 0, p, s, "time_t");
}

static bool uid_to_chars (uid_t v, char *p, size_t s) {
    return to_chars (v < 0, (uintmax_t) v, sizeof v, uid_substitute, p, s, "uid_t");
}

static bool uintmax_to_chars (uintmax_t v, char *p, size_t s) {
    return to_chars (0, v, sizeof v, 0, p, s, "uintmax_t");
}

static void string_to_chars (char const *str, char *p, size_t s) {
    tar_copy_str (p, str, s);
    p[s - 1] = '\0';
}

static bool file_dumpable_p (struct stat const *st) {
    if (S_ISDIR (st->st_mode))
        return true;
    if (!(S_ISREG (st->st_mode) || S_ISCTG (st->st_mode)))
        return false;
    if (dev_null_output)
        return totals_option && sparse_option && ST_IS_SPARSE (*st);
    return !(st->st_size == 0 && (st->st_mode & MODE_R) == MODE_R);
}

void write_eot (void) {
    union block *pointer = find_next_block ();
    memset (pointer->buffer, 0, BLOCKSIZE);
    set_next_block_after (pointer);
    pointer = find_next_block ();
    memset (pointer->buffer, 0, available_space_after (pointer));
    set_next_block_after (pointer);
}

void simple_finish_header (union block *header) {
    size_t i;
    int sum;
    char *p;
    memcpy (header->header.chksum, CHKBLANKS, sizeof header->header.chksum);
    sum = 0;
    p = header->buffer;
    for (i = sizeof *header; i-- != 0;)
        sum += 0xFF & *p++;
    uintmax_to_chars ((uintmax_t) sum, header->header.chksum, 7);
    set_next_block_after (header);
}

void finish_header (struct tar_stat_info *st, union block *header, off_t block_ordinal) {
    if (verbose_option && header->header.typeflag != GNUTYPE_LONGLINK && header->header.typeflag != GNUTYPE_LONGNAME && header->header.typeflag != XHDTYPE && header->header.typeflag != XGLTYPE) {
        current_format = archive_format;
        print_header (st, header, block_ordinal);
    }
    header = write_extended (false, st, header);
    simple_finish_header (header);
}

static enum dump_status dump_regular_file (int fd, struct tar_stat_info *st) {
    off_t size_left = st->stat.st_size;
    off_t block_ordinal;
    union block *blk;
    block_ordinal = current_block_ordinal ();
    blk = start_header (st);
    if (!blk)
        return dump_status_fail;
    if (archive_format != V7_FORMAT && S_ISCTG (st->stat.st_mode))
        blk->header.typeflag = CONTTYPE;
    finish_header (st, blk, block_ordinal);
    mv_begin_write (st->file_name, st->stat.st_size, st->stat.st_size);
    while (size_left > 0) {
        size_t bufsize, count;
        blk = find_next_block ();
        bufsize = available_space_after (blk);
        if (size_left < bufsize) {
            bufsize = size_left;
            count = bufsize % BLOCKSIZE;
            if (count)
                memset (blk->buffer + size_left, 0, BLOCKSIZE -count);
        }
        count = (fd <= 0) ? bufsize : blocking_read (fd, blk->buffer, bufsize);
        if (count == SAFE_READ_ERROR) {
            read_diag_details (st->orig_file_name, st->stat.st_size - size_left, bufsize);
            pad_archive (size_left);
            return dump_status_short;
        }
        size_left -= count;
        set_next_block_after (blk +(bufsize - 1) / BLOCKSIZE);
        if (count != bufsize) {
            char buf [UINTMAX_STRSIZE_BOUND];
            memset (blk->buffer + count, 0, bufsize -count);
            WARNOPT (WARN_FILE_SHRANK, (0, 0, ngettext ("%s: File shrank by %s byte; padding with zeros", "%s: File shrank by %s bytes; padding with zeros", size_left), quotearg_colon (st->orig_file_name), STRINGIFY_BIGINT (size_left, buf)));
            if (!ignore_failed_read_option)
                set_exit_status (TAREXIT_DIFFERS);
            pad_archive (size_left -(bufsize - count));
            return dump_status_short;
        }
    }
    return dump_status_ok;
}

void create_archive (void) {
    __ADDGRAFTHERE__JUSTHERE struct name const *p;
    trivial_link_count = name_count <= 1 && !dereference_option;
    open_archive (ACCESS_WRITE);
    buffer_write_global_xheader ();
    if (incremental_option) {
        size_t buffer_size = 1000;
        char *buffer = xmalloc (buffer_size);
        const char *q;
        collect_and_sort_names ();
        while ((p = name_from_list ()) != NULL)
            if (!excluded_name (p->name))
                dump_file (0, p->name, p->name);
        blank_name_list ();
        while ((p = name_from_list ()) != NULL)
            if (!excluded_name (p->name)) {
                struct tar_stat_info st;
                size_t plen = strlen (p->name);
                if (buffer_size <= plen) {
                    while ((buffer_size *= 2) <= plen)
                        continue;
                    buffer = xrealloc (buffer, buffer_size);
                }
                memcpy (buffer, p->name, plen);
                if (!ISSLASH (buffer[plen - 1]))
                    buffer[plen++] = DIRECTORY_SEPARATOR;
                tar_stat_init (&st);
                q = directory_contents (gnu_list_name->directory);
                if (q)
                    while (*q) {
                        size_t qlen = strlen (q);
                        if (*q == 'Y') {
                            if (!st.orig_file_name) {
                                int fd = openat (chdir_fd, p->name, open_searchdir_flags);
                                if (fd < 0) {
                                    open_diag (p->name);
                                    break;
                                }
                                st.fd = fd;
                                if (fstat (fd, &st.stat) != 0) {
                                    stat_diag (p->name);
                                    break;
                                }
                                st.orig_file_name = xstrdup (p->name);
                            }
                            if (buffer_size < plen + qlen) {
                                while ((buffer_size *= 2) < plen + qlen)
                                    continue;
                                buffer = xrealloc (buffer, buffer_size);
                            }
                            strcpy (buffer +plen, q +1);
                            dump_file (&st, q +1, buffer);
                        }
                        q += qlen + 1;
                    }
                tar_stat_destroy (&st);
            }
        free (buffer);
    }
    else {
        const char *name;
        while ((name = name_next (1)) != NULL)
            if (!excluded_name (name))
                dump_file (0, name, name);
    }
    write_eot ();
    close_archive ();
    finish_deferred_unlinks ();
    if (listed_incremental_option)
        write_directory_file ();
}

static size_t hash_link (void const *entry, size_t n_buckets) {
    struct link const *l = entry;
    uintmax_t num = l->dev ^ l->ino;
    return num % n_buckets;
}

static bool compare_links (void const *entry1, void const *entry2) {
    struct link const *link1 = entry1;
    struct link const *link2 = entry2;
    return ((link1->dev ^ link2->dev) | (link1->ino ^ link2->ino)) == 0;
}

static bool dump_hard_link (struct tar_stat_info *st) {
    if (link_table && (trivial_link_count < st->stat.st_nlink || remove_files_option)) {
        struct link lp;
        struct link *duplicate;
        off_t block_ordinal;
        union block *blk;
        lp.ino = st->stat.st_ino;
        lp.dev = st->stat.st_dev;
        if ((duplicate = hash_lookup (link_table, &lp))) {
            char const *link_name = safer_name_suffix (duplicate->name, true, absolute_names_option);
            duplicate->nlink--;
            block_ordinal = current_block_ordinal ();
            assign_string (&st->link_name, link_name);
            if (NAME_FIELD_SIZE - (archive_format == OLDGNU_FORMAT) < strlen (link_name))
                write_long_link (st);
            st->stat.st_size = 0;
            blk = start_header (st);
            if (!blk)
                return false;
            tar_copy_str (blk->header.linkname, link_name, NAME_FIELD_SIZE);
            blk->header.typeflag = LNKTYPE;
            finish_header (st, blk, block_ordinal);
            if (remove_files_option)
                queue_deferred_unlink (st->orig_file_name, false);
            return true;
        }
    }
    return false;
}

static void file_count_links (struct tar_stat_info *st) {
    if (hard_dereference_option)
        return;
    if (trivial_link_count < st->stat.st_nlink) {
        struct link *duplicate;
        char *linkname = NULL;
        struct link *lp;
        assign_string (&linkname, st->orig_file_name);
        transform_name (&linkname, XFORM_LINK);
        lp = xmalloc (offsetof (struct link, name) + strlen (linkname) + 1);
        lp->ino = st->stat.st_ino;
        lp->dev = st->stat.st_dev;
        lp->nlink = st->stat.st_nlink;
        strcpy (lp->name, linkname);
        free (linkname);
        if (!((link_table || (link_table = hash_initialize (0, 0, hash_link, compare_links, 0))) && (duplicate = hash_insert (link_table, lp))))
            xalloc_die ();
        if (duplicate != lp)
            abort ();
        lp->nlink--;
    }
}

int subfile_open (struct tar_stat_info const *dir, char const *file, int flags) {
    int fd;
    static bool initialized;
    if (!initialized) {
        initialized = true;
        strerror (ENOENT);
        gettext ("");
    }
    while ((fd = openat (dir ? dir->fd : chdir_fd, file, flags)) < 0 && open_failure_recover (dir))
        continue;
    return fd;
}

static void dump_file0 (struct tar_stat_info *st, char const *name, char const *p) {
    union block *header;
    char type;
    off_t original_size;
    struct timespec original_ctime;
    off_t block_ordinal = -1;
    int fd = 0;
    bool is_dir;
    struct tar_stat_info const *parent = st->parent;
    bool top_level = !parent;
    int parentfd = top_level ? chdir_fd : parent->fd;
    void (*diag) (char const *) = 0;
    if (interactive_option && !confirm ("add", p))
        return;
    assign_string (&st->orig_file_name, p);
    assign_string (&st->file_name, safer_name_suffix (p, false, absolute_names_option));
    transform_name (&st->file_name, XFORM_REGFILE);
    if (parentfd < 0 && !top_level) {
        errno = -parentfd;
        diag = open_diag;
    }
    else if (fstatat (parentfd, name, &st->stat, fstatat_flags) != 0)
        diag = stat_diag;
    else if (file_dumpable_p (&st->stat)) {
        fd = subfile_open (parent, name, open_read_flags);
        if (fd < 0)
            diag = open_diag;
        else {
            st->fd = fd;
            if (fstat (fd, &st->stat) != 0)
                diag = stat_diag;
        }
    }
    if (diag) {
        file_removed_diag (p, top_level, diag);
        return;
    }
    st->archive_file_size = original_size = st->stat.st_size;
    st->atime = get_stat_atime (&st->stat);
    st->mtime = get_stat_mtime (&st->stat);
    st->ctime = original_ctime = get_stat_ctime (&st->stat);
#ifdef S_ISHIDDEN
    if (S_ISHIDDEN (st->stat.st_mode)) {
        char *new = (char *) alloca (strlen (p) +2);
        if (new) {
            strcpy (new, p);
            strcat (new, "@");
            p = new;
        }
    }
#endif
    if (!(incremental_option && !top_level) && !S_ISDIR (st->stat.st_mode) && OLDER_TAR_STAT_TIME (*st, m) && (!after_date_option || OLDER_TAR_STAT_TIME (*st, c))) {
        if (!incremental_option && verbose_option)
            WARNOPT (WARN_FILE_UNCHANGED, (0, 0, _ ("%s: file is unchanged; not dumped"), quotearg_colon (p)));
        return;
    }
    if (sys_file_is_archive (st)) {
        WARNOPT (WARN_IGNORE_ARCHIVE, (0, 0, _ ("%s: file is the archive; not dumped"), quotearg_colon (p)));
        return;
    }
    is_dir = S_ISDIR (st->stat.st_mode) != 0;
    if (!is_dir && dump_hard_link (st))
        return;
    if (is_dir || S_ISREG (st->stat.st_mode) || S_ISCTG (st->stat.st_mode)) {
        bool ok;
        struct stat final_stat;
        xattrs_acls_get (parentfd, name, st, 0, !is_dir);
        xattrs_selinux_get (parentfd, name, st, fd);
        xattrs_xattrs_get (parentfd, name, st, fd);
        if (is_dir) {
            const char *tag_file_name;
            ensure_slash (&st->orig_file_name);
            ensure_slash (&st->file_name);
            if (check_exclusion_tags (st, &tag_file_name) == exclusion_tag_all) {
                exclusion_tag_warning (st->orig_file_name, tag_file_name, _ ("directory not dumped"));
                return;
            }
            ok = dump_dir (st);
            fd = st->fd;
            parentfd = top_level ? chdir_fd : parent->fd;
        }
        else {
            enum dump_status status;
            if (fd && sparse_option && ST_IS_SPARSE (st->stat)) {
                status = sparse_dump_file (fd, st);
                if (status == dump_status_not_implemented)
                    status = dump_regular_file (fd, st);
            }
            else
                status = dump_regular_file (fd, st);
            switch (status) {
            case dump_status_ok :
            case dump_status_short :
                file_count_links (st);
                break;
            case dump_status_fail :
                break;
            case dump_status_not_implemented :
                abort ();
            }
            ok = status == dump_status_ok;
        }
        if (ok) {
            if (fd < 0) {
                errno = -fd;
                ok = false;
            }
            else if (fd == 0) {
                if (parentfd < 0 && !top_level) {
                    errno = -parentfd;
                    ok = false;
                }
                else
                    ok = fstatat (parentfd, name, &final_stat, fstatat_flags) == 0;
            }
            else
                ok = fstat (fd, &final_stat) == 0;
            if (!ok)
                file_removed_diag (p, top_level, stat_diag);
        }
        if (ok) {
            if ((timespec_cmp (get_stat_ctime (&final_stat), original_ctime) != 0 && !(remove_files_option && is_dir)) || original_size < final_stat.st_size) {
                WARNOPT (WARN_FILE_CHANGED, (0, 0, _ ("%s: file changed as we read it"), quotearg_colon (p)));
                set_exit_status (TAREXIT_DIFFERS);
            }
            else if (atime_preserve_option == replace_atime_preserve && fd && (is_dir || original_size != 0) && set_file_atime (fd, parentfd, name, st->atime) != 0)
                utime_error (p);
        }
        ok &= tar_stat_close (st);
        if (ok && remove_files_option)
            queue_deferred_unlink (p, is_dir);
        return;
    }
#ifdef HAVE_READLINK
    else if (S_ISLNK (st->stat.st_mode)) {
        char *buffer;
        int size;
        size_t linklen = st->stat.st_size;
        if (linklen != st->stat.st_size || linklen + 1 == 0)
            xalloc_die ();
        buffer = (char *) alloca (linklen +1);
        size = readlinkat (parentfd, name, buffer, linklen +1);
        if (size < 0) {
            file_removed_diag (p, top_level, readlink_diag);
            return;
        }
        buffer[size] = '\0';
        assign_string (&st->link_name, buffer);
        transform_name (&st->link_name, XFORM_SYMLINK);
        if (NAME_FIELD_SIZE - (archive_format == OLDGNU_FORMAT) < size)
            write_long_link (st);
        xattrs_selinux_get (parentfd, name, st, 0);
        xattrs_xattrs_get (parentfd, name, st, 0);
        block_ordinal = current_block_ordinal ();
        st->stat.st_size = 0;
        header = start_header (st);
        if (!header)
            return;
        tar_copy_str (header->header.linkname, st->link_name, NAME_FIELD_SIZE);
        header->header.typeflag = SYMTYPE;
        finish_header (st, header, block_ordinal);
        if (remove_files_option)
            queue_deferred_unlink (p, false);
        file_count_links (st);
        return;
    }
#endif
    else if (S_ISCHR (st->stat.st_mode)) {
        type = CHRTYPE;
        xattrs_acls_get (parentfd, name, st, 0, true);
        xattrs_selinux_get (parentfd, name, st, 0);
        xattrs_xattrs_get (parentfd, name, st, 0);
    }
    else if (S_ISBLK (st->stat.st_mode)) {
        type = BLKTYPE;
        xattrs_acls_get (parentfd, name, st, 0, true);
        xattrs_selinux_get (parentfd, name, st, 0);
        xattrs_xattrs_get (parentfd, name, st, 0);
    }
    else if (S_ISFIFO (st->stat.st_mode)) {
        type = FIFOTYPE;
        xattrs_acls_get (parentfd, name, st, 0, true);
        xattrs_selinux_get (parentfd, name, st, 0);
        xattrs_xattrs_get (parentfd, name, st, 0);
    }
    else if (S_ISSOCK (st->stat.st_mode)) {
        WARNOPT (WARN_FILE_IGNORED, (0, 0, _ ("%s: socket ignored"), quotearg_colon (p)));
        return;
    }
    else if (S_ISDOOR (st->stat.st_mode)) {
        WARNOPT (WARN_FILE_IGNORED, (0, 0, _ ("%s: door ignored"), quotearg_colon (p)));
        return;
    }
    else {
        unknown_file_error (p);
        return;
    }
    if (archive_format == V7_FORMAT) {
        unknown_file_error (p);
        return;
    }
    block_ordinal = current_block_ordinal ();
    st->stat.st_size = 0;
    header = start_header (st);
    if (!header)
        return;
    header->header.typeflag = type;
    if (type != FIFOTYPE) {
        MAJOR_TO_CHARS (major (st->stat.st_rdev), header->header.devmajor);
        MINOR_TO_CHARS (minor (st->stat.st_rdev), header->header.devminor);
    }
    finish_header (st, header, block_ordinal);
    if (remove_files_option)
        queue_deferred_unlink (p, false);
}

void dump_file (struct tar_stat_info *parent, char const *name, char const *fullname) {
    struct tar_stat_info st;
    tar_stat_init (&st);
    st.parent = parent;
    dump_file0 (&st, name, fullname);
    if (parent && listed_incremental_option)
        update_parent_directory (parent);
    tar_stat_destroy (&st);
}

bool sys_get_archive_stat (void) {
    return 0;
}

bool sys_file_is_archive (struct tar_stat_info *p) {
    return false;
}

void sys_save_archive_dev_ino (void) {
}

void sys_detect_dev_null_output (void) {
    static char const dev_null [] = "nul";
    dev_null_output = (strcmp (archive_name_array[0], dev_null) == 0 || (!_isrmt (archive)));
}

void sys_wait_for_child (pid_t child_pid, bool eof) {
}

size_t sys_write_archive_buffer (void) {
    return full_write (archive, record_start->buffer, record_size);
}

void sys_child_open_for_compress (void) {
    FATAL_ERROR ((0, 0, _ ("Cannot use compressed or remote archives")));
}

bool sys_get_archive_stat (void) {
    return fstat (archive, &archive_stat) == 0;
}

bool sys_file_is_archive (struct tar_stat_info *p) {
    return (ar_dev && p->stat.st_dev == ar_dev && p->stat.st_ino == ar_ino);
}

void sys_save_archive_dev_ino (void) {
    if (!_isrmt (archive) && S_ISREG (archive_stat.st_mode)) {
        ar_dev = archive_stat.st_dev;
        ar_ino = archive_stat.st_ino;
    }
    else
        ar_dev = 0;
}

void sys_detect_dev_null_output (void) {
    static char const dev_null [] = "/dev/null";
    struct stat dev_null_stat;
    dev_null_output = (strcmp (archive_name_array[0], dev_null) == 0 || (!_isrmt (archive) && S_ISCHR (archive_stat.st_mode) && stat (dev_null, &dev_null_stat) == 0 && archive_stat.st_dev == dev_null_stat.st_dev && archive_stat.st_ino == dev_null_stat.st_ino));
}

void sys_wait_for_child (pid_t child_pid, bool eof) {
    if (child_pid) {
        int wait_status;
        while (waitpid (child_pid, &wait_status, 0) == -1)
            if (errno != EINTR) {
                waitpid_error (use_compress_program_option);
                break;
            }
        if (WIFSIGNALED (wait_status)) {
            int sig = WTERMSIG (wait_status);
            if (!(!eof && sig == SIGPIPE))
                FATAL_ERROR ((0, 0, _ ("Child died with signal %d"), sig));
        }
        else if (WEXITSTATUS (wait_status) != 0)
            FATAL_ERROR ((0, 0, _ ("Child returned status %d"), WEXITSTATUS (wait_status)));
    }
}

size_t sys_write_archive_buffer (void) {
    return rmtwrite (archive, record_start->buffer, record_size);
}
#define	PREAD 0			/* read file descriptor from pipe() */
#define	PWRITE 1		/* write file descriptor from pipe() */

pid_t sys_child_open_for_compress (void) {
    int parent_pipe [2];
    int child_pipe [2];
    pid_t grandchild_pid;
    pid_t child_pid;
    xpipe (parent_pipe);
    child_pid = xfork ();
    if (child_pid > 0) {
        archive = parent_pipe[PWRITE];
        xclose (parent_pipe [PREAD]);
        return child_pid;
    }
    set_program_name (_ ("tar (child)"));
    signal (SIGPIPE, SIG_DFL);
    xdup2 (parent_pipe[PREAD], STDIN_FILENO);
    xclose (parent_pipe [PWRITE]);
    if (!_remdev (archive_name_array[0]) && is_regular_file (archive_name_array[0])) {
        if (backup_option)
            maybe_backup_file (archive_name_array[0], 1);
        if (strcmp (archive_name_array[0], "-")) {
            archive = creat (archive_name_array[0], MODE_RW);
            if (archive < 0) {
                int saved_errno = errno;
                if (backup_option)
                    undo_last_backup ();
                errno = saved_errno;
                open_fatal (archive_name_array [0]);
            }
            xdup2 (archive, STDOUT_FILENO);
        }
        priv_set_restore_linkdir ();
        xexec (use_compress_program_option);
    }
    xpipe (child_pipe);
    grandchild_pid = xfork ();
    if (grandchild_pid == 0) {
        set_program_name (_ ("tar (grandchild)"));
        xdup2 (child_pipe[PWRITE], STDOUT_FILENO);
        xclose (child_pipe [PREAD]);
        priv_set_restore_linkdir ();
        xexec (use_compress_program_option);
    }
    xdup2 (child_pipe[PREAD], STDIN_FILENO);
    xclose (child_pipe [PWRITE]);
    if (strcmp (archive_name_array[0], "-") == 0)
        archive = STDOUT_FILENO;
    else {
        archive = rmtcreat (archive_name_array[0], MODE_RW, rsh_command_option);
        if (archive < 0)
            open_fatal (archive_name_array[0]);
    }
    while (1) {
        size_t status = 0;
        char *cursor;
        size_t length;
        for (length = 0, cursor = record_start->buffer; length < record_size; length += status, cursor += status) {
            size_t size = record_size - length;
            status = safe_read (STDIN_FILENO, cursor, size);
            if (status == SAFE_READ_ERROR)
                read_fatal (use_compress_program_option);
            if (status == 0)
                break;
        }
        if (status == 0) {
            if (length > 0) {
                memset (record_start->buffer + length, 0, record_size -length);
                status = sys_write_archive_buffer ();
                if (status != record_size)
                    archive_write_error (status);
            }
            break;
        }
        status = sys_write_archive_buffer ();
        if (status != record_size)
            archive_write_error (status);
    }
    wait_for_grandchild (grandchild_pid);
}

static void flush_deferred_unlinks (bool force) {
    struct deferred_unlink *p, *prev = NULL;
    int saved_chdir = chdir_current;
    for (p = dunlink_head; p;) {
        struct deferred_unlink *next = p->next;
        if (force || records_written > p->records_written + deferred_unlink_delay) {
            chdir_do (p->dir_idx);
            if (p->is_dir) {
                const char *fname;
                if (p->file_name[0] == 0 || strcmp (p->file_name, ".") == 0) {
                    fname = tar_dirname ();
                    chdir_do (p->dir_idx - 1);
                }
                else
                    fname = p->file_name;
                if (unlinkat (chdir_fd, fname, AT_REMOVEDIR) != 0) {
                    switch (errno) {
                    case ENOENT :
                        break;
                    case ENOTEMPTY :
                        if (!force) {
                            prev = p;
                            p = next;
                            continue;
                        }
                    default :
                        rmdir_error (fname);
                    }
                }
            }
            else {
                if (unlinkat (chdir_fd, p->file_name, 0) != 0 && errno != ENOENT)
                    unlink_error (p->file_name);
            }
            dunlink_reclaim (p);
            dunlink_count--;
            p = next;
            if (prev)
                prev->next = p;
            else
                dunlink_head = p;
        }
        else {
            prev = p;
            p = next;
        }
    }
    if (!dunlink_head)
        dunlink_tail = NULL;
    chdir_do (saved_chdir);
}

void finish_deferred_unlinks (void) {
    flush_deferred_unlinks (true);
    while (dunlink_avail) {
        struct deferred_unlink *next = dunlink_avail->next;
        free (dunlink_avail);
        dunlink_avail = next;
    }
}

void xattrs_acls_get (int parentfd, char const *file_name, struct tar_stat_info *st, int fd, int xisfile) {
    if (acls_option > 0) {
#ifndef HAVE_POSIX_ACLS
        static int done = 0;
        if (!done)
            WARN ((0, 0, _ ("POSIX ACL support is not available")));
        done = 1;
#else
        int err = file_has_acl_at (parentfd, file_name, &st->stat);
        if (err == 0)
            return;
        if (err == -1) {
            call_arg_warn ("file_has_acl_at", file_name);
            return;
        }
        xattrs__acls_get_a (parentfd, file_name, st, &st->acls_a_ptr, &st->acls_a_len);
        if (!xisfile)
            xattrs__acls_get_d (parentfd, file_name, st, &st->acls_d_ptr, &st->acls_d_len);
#endif
    }
}

void xattrs_xattrs_get (int parentfd, char const *file_name, struct tar_stat_info *st, int fd) {
    if (xattrs_option > 0) {
#ifndef HAVE_XATTRS
        static int done = 0;
        if (!done)
            WARN ((0, 0, _ ("XATTR support is not available")));
        done = 1;
#else
        static size_t xsz = 1024;
        static char *xatrs = NULL;
        ssize_t xret = -1;
        if (!xatrs)
            xatrs = x2nrealloc (xatrs, &xsz, 1);
        while (((fd == 0) ? ((xret = llistxattrat (parentfd, file_name, xatrs, xsz)) == -1) : ((xret = flistxattr (fd, xatrs, xsz)) == -1)) && (errno == ERANGE)) {
            xatrs = x2nrealloc (xatrs, &xsz, 1);
        }
        if (xret == -1)
            call_arg_warn ((fd == 0) ? "llistxattrat" : "flistxattr", file_name);
        else {
            const char *attr = xatrs;
            static size_t asz = 1024;
            static char *val = NULL;
            if (!val)
                val = x2nrealloc (val, &asz, 1);
            while (xret > 0) {
                size_t len = strlen (attr);
                ssize_t aret = 0;
                while (((fd == 0) ? ((aret = lgetxattrat (parentfd, file_name, attr, val, asz)) == -1) : ((aret = fgetxattr (fd, attr, val, asz)) == -1)) && (errno == ERANGE)) {
                    val = x2nrealloc (val, &asz, 1);
                }
                if (aret != -1)
                    xheader_xattr_add (st, attr, val, aret);
                else if (errno != ENOATTR)
                    call_arg_warn ((fd == 0) ? "lgetxattrat" : "fgetxattr", file_name);
                attr += len + 1;
                xret -= len + 1;
            }
        }
#endif
    }
}
#ifdef HAVE_XATTRS

void xattrs_selinux_get (int parentfd, char const *file_name, struct tar_stat_info *st, int fd) {
    if (selinux_context_option > 0) {
#if HAVE_SELINUX_SELINUX_H != 1
        static int done = 0;
        if (!done)
            WARN ((0, 0, _ ("SELinux support is not available")));
        done = 1;
#else
        int result = fd ? fgetfilecon (fd, &st->cntx_name) : lgetfileconat (parentfd, file_name, &st->cntx_name);
        if (result == -1 && errno != ENODATA && errno != ENOTSUP)
            call_arg_warn (fd ? "fgetfilecon" : "lgetfileconat", file_name);
#endif
    }
}

void xattrs_print (struct tar_stat_info const *st) {
    if (verbose_option < 3)
        return;
    if (selinux_context_option && st->cntx_name)
        fprintf (stdlis, "  s: %s\n", st->cntx_name);
    if (acls_option && (st->acls_a_len || st->acls_d_len)) {
        fprintf (stdlis, "  a: ");
        acls_one_line ("", ',', st->acls_a_ptr, st->acls_a_len);
        acls_one_line ("default:", ',', st->acls_d_ptr, st->acls_d_len);
        fprintf (stdlis, "\n");
    }
    if (xattrs_option && st->xattr_map_size) {
        int i;
        for (i = 0; i < st->xattr_map_size; ++i) {
            char *keyword = st->xattr_map[i].xkey + strlen ("SCHILY.xattr.");
            if (!xattrs_masked_out (keyword, false))
                fprintf (stdlis, "  x: %lu %s\n", (unsigned long) st->xattr_map[i].xval_len, keyword);
        }
    }
}

void assign_string (char **string, const char *value) {
    free (*string);
    *string = value ? xstrdup (value) : 0;
}
#if 0

int unquote_string (char *string) {
    int result = 1;
    char *source = string;
    char *destination = string;
    while (*source)
        if (*source == '\\')
            switch (*++source) {
            case '\\' :
                *destination++ = '\\';
                source++;
                break;
            case 'a' :
                *destination++ = '\a';
                source++;
                break;
            case 'b' :
                *destination++ = '\b';
                source++;
                break;
            case 'f' :
                *destination++ = '\f';
                source++;
                break;
            case 'n' :
                *destination++ = '\n';
                source++;
                break;
            case 'r' :
                *destination++ = '\r';
                source++;
                break;
            case 't' :
                *destination++ = '\t';
                source++;
                break;
            case 'v' :
                *destination++ = '\v';
                source++;
                break;
            case '?' :
                *destination++ = 0177;
                source++;
                break;
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
                {
                    int value = *source++ - '0';
                    if (*source < '0' || *source > '7') {
                        *destination++ = value;
                        break;
                    }
                    value = value * 8 + *source++ - '0';
                    if (*source < '0' || *source > '7') {
                        *destination++ = value;
                        break;
                    }
                    value = value * 8 + *source++ - '0';
                    *destination++ = value;
                    break;
                }
            default :
                result = 0;
                *destination++ = '\\';
                if (*source)
                    *destination++ = *source++;
                break;
            }
        else if (source != destination)
            *destination++ = *source++;
        else
            source++, destination++;
    if (source != destination)
        *destination = '\0';
    return result;
}

size_t blocking_read (int fd, void *buf, size_t count) {
    size_t bytes = safe_read (fd, buf, count);
#if defined F_SETFL && O_NONBLOCK
    if (bytes == SAFE_READ_ERROR && errno == EAGAIN) {
        int flags = fcntl (fd, F_GETFL);
        if (0 <= flags && flags & O_NONBLOCK && fcntl (fd, F_SETFL, flags &~O_NONBLOCK) != -1)
            bytes = safe_read (fd, buf, count);
    }
#endif
    return bytes;
}

void chdir_do (int i) {
    if (chdir_current != i) {
        struct wd *curr = &wd[i];
        int fd = curr->fd;
        if (!fd) {
            if (!IS_ABSOLUTE_FILE_NAME (curr->name))
                chdir_do (i -1);
            fd = openat (chdir_fd, curr->name, open_searchdir_flags &~O_NOFOLLOW);
            if (fd < 0)
                open_fatal (curr->name);
            curr->fd = fd;
            if (wdcache_count < CHDIR_CACHE_SIZE)
                wdcache[wdcache_count++] = i;
            else {
                struct wd *stale = &wd[wdcache[CHDIR_CACHE_SIZE - 1]];
                if (close (stale->fd) != 0)
                    close_diag (stale->name);
                stale->fd = 0;
                wdcache[CHDIR_CACHE_SIZE - 1] = i;
            }
        }
        if (0 < fd) {
            size_t ci;
            int prev = wdcache[0];
            for (ci = 1; prev != i; ci++) {
                int cur = wdcache[ci];
                wdcache[ci] = prev;
                if (cur == i)
                    break;
                prev = cur;
            }
            wdcache[0] = i;
        }
        chdir_current = i;
        chdir_fd = fd;
    }
}

pid_t xfork (void) {
    pid_t p = fork ();
    if (p == (pid_t) -1)
        call_arg_fatal ("fork", _ ("child process"));
    return p;
}

void xpipe (int fd [2]) {
    if (pipe (fd) < 0)
        call_arg_fatal ("pipe", _ ("interprocess channel"));
}

void checkpoint_run (bool do_write) {
    if (checkpoint_option && !(++checkpoint % checkpoint_option))
        run_checkpoint_actions (do_write);
}

static void simple_print_header (struct tar_stat_info *st, union block *blk, off_t block_ordinal) {
    char modes [12];
    char const *time_stamp;
    int time_stamp_len;
    char *temp_name;
    char uform [max (INT_BUFSIZE_BOUND (intmax_t), UINTMAX_STRSIZE_BOUND)];
    char gform [sizeof uform];
    char *user, *group;
    char size [2 * UINTMAX_STRSIZE_BOUND];
    char uintbuf [UINTMAX_STRSIZE_BOUND];
    int pad;
    int sizelen;
    if (show_transformed_names_option)
        temp_name = st->file_name ? st->file_name : st->orig_file_name;
    else
        temp_name = st->orig_file_name ? st->orig_file_name : st->file_name;
    if (block_number_option) {
        char buf [UINTMAX_STRSIZE_BOUND];
        if (block_ordinal < 0)
            block_ordinal = current_block_ordinal ();
        block_ordinal -= recent_long_name_blocks;
        block_ordinal -= recent_long_link_blocks;
        fprintf (stdlis, _ ("block %s: "), STRINGIFY_BIGINT (block_ordinal, buf));
    }
    if (verbose_option <= 1) {
        fprintf (stdlis, "%s\n", quotearg (temp_name));
    }
    else {
        modes[0] = '?';
        switch (blk->header.typeflag) {
        case GNUTYPE_VOLHDR :
            volume_label_printed = true;
            modes[0] = 'V';
            break;
        case GNUTYPE_MULTIVOL :
            modes[0] = 'M';
            break;
        case GNUTYPE_LONGNAME :
        case GNUTYPE_LONGLINK :
            modes[0] = 'L';
            ERROR ((0, 0, _ ("Unexpected long name header")));
            break;
        case GNUTYPE_SPARSE :
        case REGTYPE :
        case AREGTYPE :
            modes[0] = '-';
            if (temp_name[strlen (temp_name) - 1] == '/')
                modes[0] = 'd';
            break;
        case LNKTYPE :
            modes[0] = 'h';
            break;
        case GNUTYPE_DUMPDIR :
            modes[0] = 'd';
            break;
        case DIRTYPE :
            modes[0] = 'd';
            break;
        case SYMTYPE :
            modes[0] = 'l';
            break;
        case BLKTYPE :
            modes[0] = 'b';
            break;
        case CHRTYPE :
            modes[0] = 'c';
            break;
        case FIFOTYPE :
            modes[0] = 'p';
            break;
        case CONTTYPE :
            modes[0] = 'C';
            break;
        }
        pax_decode_mode (st->stat.st_mode, modes +1);
        xattrs_print_char (st, modes +10);
        time_stamp = tartime (st->mtime, full_time_option);
        time_stamp_len = strlen (time_stamp);
        if (datewidth < time_stamp_len)
            datewidth = time_stamp_len;
        if (st->uname && st->uname[0] && current_format != V7_FORMAT && !numeric_owner_option)
            user = st->uname;
        else {
            uintmax_t u = from_header (blk->header.uid, sizeof blk->header.uid, 0, 0, UINTMAX_MAX, false, false);
            user = (u != -1 ? STRINGIFY_BIGINT (u, uform) : imaxtostr (UID_FROM_HEADER (blk->header.uid), uform));
        }
        if (st->gname && st->gname[0] && current_format != V7_FORMAT && !numeric_owner_option)
            group = st->gname;
        else {
            uintmax_t g = from_header (blk->header.gid, sizeof blk->header.gid, 0, 0, UINTMAX_MAX, false, false);
            group = (g != -1 ? STRINGIFY_BIGINT (g, gform) : imaxtostr (GID_FROM_HEADER (blk->header.gid), gform));
        }
        switch (blk->header.typeflag) {
        case CHRTYPE :
        case BLKTYPE :
            strcpy (size, STRINGIFY_BIGINT (major (st->stat.st_rdev), uintbuf));
            strcat (size, ",");
            strcat (size, STRINGIFY_BIGINT (minor (st->stat.st_rdev), uintbuf));
            break;
        default :
            strcpy (size, STRINGIFY_BIGINT (st->stat.st_size, uintbuf));
            break;
        }
        sizelen = strlen (size);
        pad = strlen (user) + 1 + strlen (group) + 1 + sizelen;
        if (pad > ugswidth)
            ugswidth = pad;
        fprintf (stdlis, "%s %s/%s %*s %-*s", modes, user, group, ugswidth -pad + sizelen, size, datewidth, time_stamp);
        fprintf (stdlis, " %s", quotearg (temp_name));
        switch (blk->header.typeflag) {
        case SYMTYPE :
            fprintf (stdlis, " -> %s\n", quotearg (st->link_name));
            break;
        case LNKTYPE :
            fprintf (stdlis, _ (" link to %s\n"), quotearg (st->link_name));
            break;
        default :
            {
                char type_string [2];
                type_string[0] = blk->header.typeflag;
                type_string[1] = '\0';
                fprintf (stdlis, _ (" unknown file type %s\n"), quote (type_string));
            }
            break;
        case AREGTYPE :
        case REGTYPE :
        case GNUTYPE_SPARSE :
        case CHRTYPE :
        case BLKTYPE :
        case DIRTYPE :
        case FIFOTYPE :
        case CONTTYPE :
        case GNUTYPE_DUMPDIR :
            putc ('\n', stdlis);
            break;
        case GNUTYPE_LONGLINK :
            fprintf (stdlis, _ ("--Long Link--\n"));
            break;
        case GNUTYPE_LONGNAME :
            fprintf (stdlis, _ ("--Long Name--\n"));
            break;
        case GNUTYPE_VOLHDR :
            fprintf (stdlis, _ ("--Volume Header--\n"));
            break;
        case GNUTYPE_MULTIVOL :
            strcpy (size, STRINGIFY_BIGINT (UINTMAX_FROM_HEADER (blk->oldgnu_header.offset), uintbuf));
            fprintf (stdlis, _ ("--Continued at byte %s--\n"), size);
            break;
        }
    }
    fflush (stdlis);
    xattrs_print (st);
}

void print_header (struct tar_stat_info *st, union block *blk, off_t block_ordinal) {
    if (current_format == POSIX_FORMAT && !volume_label_printed && volume_label) {
        print_volume_label ();
        volume_label_printed = true;
    }
    simple_print_header (st, blk, block_ordinal);
}

