
#include "InterfaceHeader.h"
char *tent;
char PC = 0;
long  _bauds [16] = {0, 50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800, 2400, 4800, 9600, 19200, 19200};
short  ospeed;

int tputs (char *cp, int affcnt, void (*outc) (unsigned  int)) {
    long  frac, counter, atol (const char *);
    if (VIM_ISDIGIT (*cp)) {
        counter = 0;
        frac = 1000;
        while (VIM_ISDIGIT (*cp))
            counter = counter * 10L + (long ) (*cp++ - '0');
        if (*cp == '.')
            while (VIM_ISDIGIT (*++cp)) {
                counter = counter * 10L + (long ) (*cp++ - '0');
                frac = frac * 10;
            }
        if (*cp != '*') {
            if (affcnt > 1)
                affcnt = 1;
        }
        else
            cp++;
        if (ospeed)
            counter = (counter * _bauds[ospeed] * (long ) affcnt) / frac;
        while (*cp)
            (*outc) (*cp++);
        if (ospeed)
            while (counter--)
                (*outc) (PC);
    }
    else
        while (*cp)
            (*outc) (*cp++);
    return 0;
}

int tgetflag (char *id) {
    char buf [256], *ptr = buf;
    return tgetstr (id, &ptr) ? 1 : 0;
}

char *tgetstr (char *id, char **buf) {
    int len = strlen (id);
    char *tmp = tent;
    char *hold;
    int i;
    do {
        tmp = _find (tmp, ":");
        while (*tmp == ':')
            tmp++;
        if (!*tmp)
            break;
        if (_match (id, tmp) == len) {
            tmp += len;
            if (*tmp == '@')
                return 0;
            hold = *buf;
            while (*++tmp && *tmp != ':') {
                switch (*tmp) {
                case '\\' :
                    switch (*++tmp) {
                    case 0 :
                        tmp--;
                        break;
                    case 'e' :
                    case 'E' :
                        *(*buf)++ = ESC;
                        break;
                    case 'n' :
                        *(*buf)++ = '\n';
                        break;
                    case 'r' :
                        *(*buf)++ = '\r';
                        break;
                    case 't' :
                        *(*buf)++ = '\t';
                        break;
                    case 'b' :
                        *(*buf)++ = '\b';
                        break;
                    case 'f' :
                        *(*buf)++ = '\f';
                        break;
                    case '0' :
                    case '1' :
                    case '2' :
                    case '3' :
                    case '4' :
                    case '5' :
                    case '6' :
                    case '7' :
                    case '8' :
                    case '9' :
                        **buf = 0;
                        for (i = 0; i < 3 && VIM_ISDIGIT (*tmp); ++i)
                            **buf = **buf * 8 + *tmp++ - '0';
                        (*buf)++;
                        tmp--;
                        break;
                    default :
                        *(*buf)++ = *tmp;
                    }
                    break;
                case '^' :
                    ++tmp;
                    *(*buf)++ = Ctrl_chr (*tmp);
                    break;
                default :
                    *(*buf)++ = *tmp;
                }
            }
            *(*buf)++ = 0;
            return hold;
        }
    }
    while (*tmp);
    return 0;
}

static char *_find (char *s, char *set) {
    for (; *s; s++) {
        char *ptr = set;
        while (*ptr && *s != *ptr)
            ptr++;
        if (*ptr)
            return s;
    }
    return s;
}

static int _match (char *s1, char *s2) {
    int i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return i;
}

int tgetnum (char *id) {
    char *ptr, buf [256];
    ptr = buf;
    if (tgetstr (id, &ptr))
        return atoi (buf);
    else
        return 0;
}

