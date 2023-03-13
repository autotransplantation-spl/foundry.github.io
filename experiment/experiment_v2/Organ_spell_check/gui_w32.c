
#include "InterfaceHeader.h"
struct tagTOOLINFOA_NEW {
    UINT cbSize;
    UINT uFlags;
    HWND hwnd;
    UINT_PTR uId;
    RECT rect;
    HINSTANCE hinst;
    LPSTR lpszText;
    LPARAM lParam;
} TOOLINFO_NEW;
HWND vim_parent_hwnd = NULL;
LPARAM s_lParam = 0;
HWND s_toolbarhwnd = NULL;
void _OnPaint (HWND hwnd);
HINSTANCE s_hinst = NULL;
DWORD LastActivity = 0;
BalloonEval *cur_beval = NULL;
UINT_PTR BevalTimerId = 0;
HWND s_textArea = NULL;
HMENU s_menuBar = NULL;
HWND s_hwnd = NULL;
HDC s_hdc = NULL;

void netbeans_draw_multisign_indicator (int row) {
    int i;
    int y;
    int x;
    if (!netbeans_active ())
        return;
    x = 0;
    y = TEXT_Y (row);
    for (i = 0; i < gui.char_height - 3; i++)
        SetPixel (s_hdc, x +2, y++, gui.currFgColor);
    SetPixel (s_hdc, x + 0, y, gui.currFgColor);
    SetPixel (s_hdc, x + 2, y, gui.currFgColor);
    SetPixel (s_hdc, x + 4, y ++, gui.currFgColor);
    SetPixel (s_hdc, x + 1, y, gui.currFgColor);
    SetPixel (s_hdc, x + 2, y, gui.currFgColor);
    SetPixel (s_hdc, x + 3, y ++, gui.currFgColor);
    SetPixel (s_hdc, x + 2, y, gui.currFgColor);
}

int gui_mch_maximized (void) {
    WINDOWPLACEMENT wp;
    wp.length = sizeof (WINDOWPLACEMENT);
    if (GetWindowPlacement (s_hwnd, &wp))
        return wp.showCmd == SW_SHOWMAXIMIZED || (wp.showCmd == SW_SHOWMINIMIZED && wp.flags == WPF_RESTORETOMAXIMIZED);
    return 0;
}

void gui_mch_newfont (void) {
    RECT rect;
    GetWindowRect (s_hwnd, & rect);
    if (win_socket_id == 0) {
        gui_resize_shell (rect.right - rect.left - (GetSystemMetrics (SM_CXFRAME) + GetSystemMetrics (SM_CXPADDEDBORDER)) * 2, rect.bottom - rect.top - (GetSystemMetrics (SM_CYFRAME) + GetSystemMetrics (SM_CXPADDEDBORDER)) * 2 - GetSystemMetrics (SM_CYCAPTION) - gui_mswin_get_menu_height (FALSE));
    }
    else {
        gui_resize_shell (rect.right - rect.left, rect.bottom - rect.top - gui_mswin_get_menu_height (FALSE));
    }
}

static int gui_mswin_get_menu_height (int fix_window) {
    static int old_menu_height = -1;
    RECT rc1, rc2;
    int num;
    int menu_height;
    if (gui.menu_is_active)
        num = GetMenuItemCount (s_menuBar);
    else
        num = 0;
    if (num == 0)
        menu_height = 0;
    else if (IsMinimized (s_hwnd)) {
        menu_height = old_menu_height == -1 ? 0 : old_menu_height;
    }
    else {
        GetMenuItemRect (s_hwnd, s_menuBar, 0, & rc1);
        if (gui.starting)
            menu_height = rc1.bottom - rc1.top + 1;
        else {
            GetMenuItemRect (s_hwnd, s_menuBar, num - 1, & rc2);
            menu_height = rc2.bottom - rc1.top + 1;
        }
    }
    if (fix_window && menu_height != old_menu_height) {
        gui_set_shellsize (FALSE, FALSE, RESIZE_VERT);
    }
    old_menu_height = menu_height;
    return menu_height;
}

void gui_mch_enable_beval_area (BalloonEval *beval) {
    if (beval == NULL)
        return;
    BevalTimerId = SetTimer (s_textArea, 0, (UINT) (p_bdlay / 2), BevalTimerProc);
}

static VOID CALLBACK BevalTimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
    POINT pt;
    RECT rect;
    if (cur_beval == NULL || cur_beval->showState == ShS_SHOWING || !p_beval)
        return;
    GetCursorPos (& pt);
    if (WindowFromPoint (pt) != s_textArea)
        return;
    ScreenToClient (s_textArea, & pt);
    GetClientRect (s_textArea, & rect);
    if (!PtInRect (&rect, pt))
        return;
    if (LastActivity > 0 && (dwTime - LastActivity) >= (DWORD) p_bdlay && (cur_beval->showState != ShS_PENDING || abs (cur_beval->x - pt.x) > 3 || abs (cur_beval->y - pt.y) > 3)) {
        cur_beval->showState = ShS_PENDING;
        cur_beval->x = pt.x;
        cur_beval->y = pt.y;
        if (cur_beval->msgCB != NULL)
            (*cur_beval->msgCB) (cur_beval, 0);
    }
}

void gui_mch_disable_beval_area (BalloonEval *beval) {
    KillTimer (s_textArea, BevalTimerId);
}

void gui_mch_destroy_beval_area (BalloonEval *beval) {
    vim_free (beval);
}

BalloonEval *gui_mch_create_beval_area (void *target, char_u *mesg, void (*mesgCB) (BalloonEval *, int), void *clientData) {
    BalloonEval *beval;
    if (mesg != NULL && mesgCB != NULL) {
        IEMSG (_ ("E232: Cannot create BalloonEval with both message and callback"));
        return NULL;
    }
    beval = (BalloonEval *) alloc (sizeof (BalloonEval));
    if (beval != NULL) {
        beval->target = s_textArea;
        beval->balloon = NULL;
        beval->showState = ShS_NEUTRAL;
        beval->x = 0;
        beval->y = 0;
        beval->msg = mesg;
        beval->msgCB = mesgCB;
        beval->clientData = clientData;
        InitCommonControls ();
        cur_beval = beval;
        if (p_beval)
            gui_mch_enable_beval_area (beval);
    }
    return beval;
}

void gui_mch_post_balloon (BalloonEval *beval, char_u *mesg) {
    POINT pt;
    if (beval->showState == ShS_SHOWING)
        return;
    GetCursorPos (& pt);
    ScreenToClient (s_textArea, & pt);
    if (abs (beval->x - pt.x) < 3 && abs (beval->y - pt.y) < 3) {
        gui_mch_disable_beval_area (cur_beval);
        beval->showState = ShS_SHOWING;
        make_tooltip (beval, (char *) mesg, pt);
    }
}

static void make_tooltip (BalloonEval *beval, char *text, POINT pt) {
    TOOLINFO *pti;
    int ToolInfoSize;
    if (multiline_balloon_available () == TRUE)
        ToolInfoSize = sizeof (TOOLINFO_NEW);
    else
        ToolInfoSize = sizeof (TOOLINFO);
    pti = (TOOLINFO *) alloc (ToolInfoSize);
    if (pti == NULL)
        return;
    beval->balloon = CreateWindowEx (WS_EX_TOPMOST, TOOLTIPS_CLASS, NULL, WS_POPUP | TTS_NOPREFIX | TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, beval->target, NULL, s_hinst, NULL);
    SetWindowPos (beval -> balloon, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    pti->cbSize = ToolInfoSize;
    pti->uFlags = TTF_SUBCLASS;
    pti->hwnd = beval->target;
    pti->hinst = 0;
    pti->uId = ID_BEVAL_TOOLTIP;
    if (multiline_balloon_available () == TRUE) {
        RECT rect;
        TOOLINFO_NEW *ptin = (TOOLINFO_NEW *) pti;
        pti->lpszText = LPSTR_TEXTCALLBACK;
        ptin->lParam = (LPARAM) text;
        if (GetClientRect (s_textArea, &rect))
            SendMessage (beval->balloon, TTM_SETMAXTIPWIDTH, 0, (LPARAM) rect.right);
    }
    else
        pti->lpszText = text;
    pti->rect.left = pt.x - 3;
    pti->rect.top = pt.y - 3;
    pti->rect.right = pt.x + 3;
    pti->rect.bottom = pt.y + 3;
    SendMessage (beval -> balloon, TTM_ADDTOOL, 0, (LPARAM) pti);
    SendMessage (beval -> balloon, TTM_SETDELAYTIME, TTDT_INITIAL, 10);
    SendMessage (beval -> balloon, TTM_SETDELAYTIME, TTDT_AUTOPOP, 30000);
    mouse_event (MOUSEEVENTF_MOVE, 2, 2, 0, 0);
    mouse_event (MOUSEEVENTF_MOVE, (DWORD) - 1, (DWORD) - 1, 0, 0);
    vim_free (pti);
}

int multiline_balloon_available (void) {
    HINSTANCE hDll;
    static char comctl_dll [] = "comctl32.dll";
    static int multiline_tip = MAYBE;
    if (multiline_tip != MAYBE)
        return multiline_tip;
    hDll = GetModuleHandle (comctl_dll);
    if (hDll != NULL) {
        DLLGETVERSIONPROC pGetVer;
        pGetVer = (DLLGETVERSIONPROC) GetProcAddress (hDll, "DllGetVersion");
        if (pGetVer != NULL) {
            DLLVERSIONINFO dvi;
            HRESULT hr;
            ZeroMemory (& dvi, sizeof (dvi));
            dvi.cbSize = sizeof (dvi);
            hr = (*pGetVer) (&dvi);
            if (SUCCEEDED (hr) && (dvi.dwMajorVersion > 4 || (dvi.dwMajorVersion == 4 && dvi.dwMinorVersion >= 70))) {
                multiline_tip = TRUE;
                return multiline_tip;
            }
        }
        else {
            DWORD dwHandle = 0;
            DWORD len = GetFileVersionInfoSize (comctl_dll, &dwHandle);
            if (len > 0) {
                VS_FIXEDFILEINFO *ver;
                UINT vlen = 0;
                void *data = alloc (len);
                if ((data != NULL && GetFileVersionInfo (comctl_dll, 0, len, data) && VerQueryValue (data, "\\", (void **) &ver, &vlen) && vlen && HIWORD (ver->dwFileVersionMS) > 4) || ((HIWORD (ver->dwFileVersionMS) == 4 && LOWORD (ver->dwFileVersionMS) >= 70))) {
                    vim_free (data);
                    multiline_tip = TRUE;
                    return multiline_tip;
                }
                vim_free (data);
            }
        }
    }
    multiline_tip = FALSE;
    return multiline_tip;
}

