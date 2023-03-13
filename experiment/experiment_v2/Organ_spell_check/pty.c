int OpenPTY (char **ttyn) {
    char *p, *q, *l, *d;
    int f;
    static char PtyName [32];
    static char TtyName [32];
    strcpy (PtyName, PtyProto);
    strcpy (TtyName, TtyProto);
    for (p = PtyName; *p != 'X'; p++)
        ;
    for (q = TtyName; *q != 'X'; q++)
        ;
    for (l = PTYRANGE0; (*p = *l) != '\0'; l++) {
        for (d = PTYRANGE1; (p[1] = *d) != '\0'; d++) {
            if ((f = open (PtyName, O_RDWR | O_NOCTTY | O_EXTRA, 0)) == -1)
                continue;
            q[0] = *l;
            q[1] = *d;
            if (geteuid () != ROOT_UID && mch_access (TtyName, R_OK | W_OK)) {
                close (f);
                continue;
            }
            initmaster (f);
            *ttyn = TtyName;
            return f;
        }
    }
    return -1;
}

static void initmaster (int f) {
}

int SetupSlavePTY (int fd) {
    if (fd < 0)
        return 0;
    return 0;
}

