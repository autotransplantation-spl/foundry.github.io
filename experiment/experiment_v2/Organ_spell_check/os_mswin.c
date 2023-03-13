
#include "InterfaceHeader.h"
struct server_id {
    HWND hwnd;
    char_u *name;
};
garray_T reply_list = {0, 0, sizeof (reply_T), 5, 0};
HWND message_window = 0;
int reply_received = 0;
char_u *altname_buf_ptr = NULL;
int WSInitialized = FALSE;

void channel_init_winsock (void) {
    WSADATA wsaData;
    int wsaerr;
    if (WSInitialized)
        return;
    wsaerr = WSAStartup (MAKEWORD (2, 2), &wsaData);
    if (wsaerr == 0)
        WSInitialized = TRUE;
}

void serverForeground (char_u *name) {
    HWND target = findServer (name);
    if (target != 0)
        SetForegroundWindow (target);
}

static HWND findServer (char_u *name) {
    struct server_id id;
    id.name = name;
    id.hwnd = 0;
    EnumWindows (enumWindowsGetServer, (LPARAM) (& id));
    return id.hwnd;
}

static BOOL CALLBACK enumWindowsGetServer (HWND hwnd, LPARAM lparam) {
    struct server_id *id = (struct server_id *) lparam;
    char server [MAX_PATH];
    if (getVimServerName (hwnd, server, sizeof (server)) == 0)
        return TRUE;
    if (STRICMP (server, id->name) == 0) {
        id->hwnd = hwnd;
        return FALSE;
    }
    if (altname_buf_ptr != NULL && STRNICMP (server, id->name, STRLEN (id->name)) == 0 && vim_isdigit (server[STRLEN (id->name)])) {
        STRCPY (altname_buf_ptr, server);
        altname_buf_ptr = NULL;
    }
    return TRUE;
}

static int getVimServerName (HWND hwnd, char *name, int namelen) {
    int len;
    char buffer [VIM_CLASSNAME_LEN + 1];
    len = GetClassName (hwnd, buffer, sizeof (buffer));
    if (len != VIM_CLASSNAME_LEN || STRCMP (buffer, VIM_CLASSNAME) != 0)
        return 0;
    return GetWindowText (hwnd, name, namelen);
}

char_u *serverGetReply (HWND server, int *expr_res, int remove, int wait, int timeout) {
    int i;
    char_u *reply;
    reply_T *rep;
    int did_process = FALSE;
    time_t start;
    time_t now;
    time (& start);
    for (;;) {
        reply_received = 0;
        for (i = 0; i < REPLY_COUNT; ++i) {
            rep = REPLY_ITEM (i);
            if (rep->server == server && ((rep->expr_result != 0) == (expr_res != NULL))) {
                reply = rep->reply;
                if (expr_res != NULL)
                    *expr_res = rep->expr_result == 1 ? 0 : -1;
                if (remove) {
                    mch_memmove (rep, rep + 1, (REPLY_COUNT - i - 1) * sizeof (reply_T));
                    --REPLY_COUNT;
                }
                return reply;
            }
        }
        if (!wait) {
            if (!did_process) {
                did_process = TRUE;
                serverProcessPendingMessages ();
                continue;
            }
            break;
        }
        while (reply_received == 0) {
            check_due_timer ();
            time (& now);
            if (timeout > 0 && (now - start) >= timeout)
                break;
            MsgWaitForMultipleObjects (0, NULL, TRUE, 1000, QS_ALLINPUT);
            if (!IsWindow (server))
                return NULL;
            serverProcessPendingMessages ();
        }
    }
    return NULL;
}

void serverProcessPendingMessages (void) {
    MSG msg;
    while (pPeekMessage (&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage (& msg);
        pDispatchMessage (& msg);
    }
}

void serverSetName (char_u *name) {
    char_u *ok_name;
    HWND hwnd = 0;
    int i = 0;
    char_u *p;
    ok_name = alloc ((unsigned ) STRLEN (name) + 10);
    STRCPY (ok_name, name);
    p = ok_name + STRLEN (name);
    for (;;) {
        hwnd = findServer (ok_name);
        if (hwnd == 0)
            break;
        ++i;
        if (i >= 1000)
            break;
        sprintf ((char *) p, "%d", i);
    }
    if (hwnd != 0)
        vim_free (ok_name);
    else {
        serverName = ok_name;
        need_maketitle = TRUE;
        SetWindowText (message_window, (LPCSTR) ok_name);
        set_vim_var_string (VV_SEND_SERVER, serverName, - 1);
    }
}

