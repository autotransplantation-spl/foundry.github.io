
#include "InterfaceHeader.h"
char_u *exe_path = NULL;

int mch_remove (char_u *name) {
    if (mch_isdir (name) && mch_is_symbolic_link (name))
        return mch_rmdir (name);
    win32_setattrs (name, FILE_ATTRIBUTE_NORMAL);
    return DeleteFile ((LPCSTR) name) ? 0 : -1;
}

int mch_isdir (char_u *name) {
    int f = win32_getattrs (name);
    if (f == -1)
        return FALSE;
    return (f & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

static int win32_getattrs (char_u *name) {
    int attr;
    attr = GetFileAttributes ((char *) name);
    return attr;
}

int mch_is_symbolic_link (char_u *name) {
    HANDLE hFind;
    int res = FALSE;
    WIN32_FIND_DATAA findDataA;
    DWORD fileFlags = 0, reparseTag = 0;
    {
        hFind = FindFirstFile ((LPCSTR) name, &findDataA);
        if (hFind != INVALID_HANDLE_VALUE) {
            fileFlags = findDataA.dwFileAttributes;
            reparseTag = findDataA.dwReserved0;
        }
    }
    if (hFind != INVALID_HANDLE_VALUE)
        FindClose (hFind);
    if ((fileFlags & FILE_ATTRIBUTE_REPARSE_POINT) && (reparseTag == IO_REPARSE_TAG_SYMLINK || reparseTag == IO_REPARSE_TAG_MOUNT_POINT))
        res = TRUE;
    return res;
}

int mch_rmdir (char_u *name) {
    return _rmdir ((const char *) name);
}

static int win32_setattrs (char_u *name, int attrs) {
    int res;
    res = SetFileAttributes ((char *) name, attrs);
    return res ? 0 : -1;
}

int mch_access (char *n, int p) {
    HANDLE hFile;
    DWORD am;
    int retval = -1;
    if (mch_isdir ((char_u *) n)) {
        char TempName [_MAX_PATH + 16] = "";
        if (p & R_OK) {
            {
                char *pch;
                WIN32_FIND_DATA d;
                vim_strncpy ((char_u *) TempName, (char_u *) n, _MAX_PATH);
                pch = TempName + STRLEN (TempName) - 1;
                if (*pch != '\\' && *pch != '/')
                    *++pch = '\\';
                *++pch = '*';
                *++pch = NUL;
                hFile = FindFirstFile (TempName, &d);
                if (hFile == INVALID_HANDLE_VALUE)
                    goto getout;
                (void) FindClose (hFile);
            }
        }
        if (p & W_OK) {
            {
                if (!GetTempFileName (n, "VIM", 0, TempName))
                    goto getout;
                mch_remove ((char_u *) TempName);
            }
        }
    }
    else {
        am = ((p & W_OK) ? GENERIC_WRITE : 0) | ((p & R_OK) ? GENERIC_READ : 0);
        hFile = CreateFile (n, am, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            goto getout;
        CloseHandle (hFile);
    }
    retval = 0;
getout :
    return retval;
}

static void get_exe_name (void) {

    #define MAX_ENV_PATH_LEN 8192
    char temp [MAX_ENV_PATH_LEN];
    char_u *p;
    if (exe_name == NULL) {
        GetModuleFileName (NULL, temp, MAX_ENV_PATH_LEN - 1);
        if (*temp != NUL)
            exe_name = FullName_save ((char_u *) temp, FALSE);
    }
    if (exe_path == NULL && exe_name != NULL) {
        exe_path = vim_strnsave (exe_name, (int) (gettail_sep (exe_name) - exe_name));
        if (exe_path != NULL) {
            p = mch_getenv ("PATH");
            if (p == NULL || STRLEN (p) + STRLEN (exe_path) + 2 < MAX_ENV_PATH_LEN) {
                if (p == NULL || *p == NUL)
                    temp[0] = NUL;
                else {
                    STRCPY (temp, p);
                    STRCAT (temp, ";");
                }
                STRCAT (temp, exe_path);
                vim_setenv ((char_u *) "PATH", (char_u *) temp);
            }
        }
    }
}

