
#include "InterfaceHeader.h"
static struct {
    FMFontFamily family;
    FMFontSize size;
    FMFontStyle style;
    Boolean isPanelVisible;
} gFontPanelInfo = {0, 0, 0, false};
static struct {
    KeySym key_sym;
    char_u vim_code0;
    char_u vim_code1;
} special_keys [] = {{vk_Up, 'k', 'u'}, {vk_Down, 'k', 'd'}, {vk_Left, 'k', 'l'}, {vk_Right, 'k', 'r'}, {vk_F1, 'k', '1'}, {vk_F2, 'k', '2'}, {vk_F3, 'k', '3'}, {vk_F4, 'k', '4'}, {vk_F5, 'k', '5'}, {vk_F6, 'k', '6'}, {vk_F7, 'k', '7'}, {vk_F8, 'k', '8'}, {vk_F9, 'k', '9'}, {vk_F10, 'k', ';'}, {vk_F11, 'F', '1'}, {vk_F12, 'F', '2'}, {vk_F13, 'F', '3'}, {vk_F14, 'F', '4'}, {vk_F15, 'F', '5'}, {vk_Insert, 'k', 'I'}, {vk_FwdDelete, 'k', 'D'}, {vk_Home, 'k', 'h'}, {vk_End, '@', '7'}, {vk_PageUp, 'k', 'P'}, {vk_PageDown, 'k', 'N'}, {(KeySym) 0, 0, 0}};
RGBColor specialColor;
short  dragRectEnbl;
long  lastMouseTick = 0;
short  clickIsPopup;
ControlActionUPP gScrollAction;
Rect dragRect;
RgnHandle cursorRgn;
RgnHandle dragRgn;
short  dragRectControl;
int allow_scrollbar = FALSE;
ControlHandle dragged_sb = NULL;
EventHandlerUPP mouseWheelHandlerUPP = NULL;
SInt32 gMacSystemVersion;

void gui_mch_update (void) {
    EventRecord theEvent;
    if (EventAvail (everyEvent, &theEvent))
        if (theEvent.what != nullEvent)
            gui_mch_wait_for_chars (0);
}

int gui_mch_wait_for_chars (int wtime) {
    EventMask mask = (everyEvent);
    EventRecord event;
    long  entryTick;
    long  currentTick;
    long  sleeppyTick;
    if (dragged_sb != NULL)
        return FAIL;
    entryTick = TickCount ();
    allow_scrollbar = TRUE;
    do {
        if (dragRectControl == kCreateRect) {
            dragRgn = cursorRgn;
            RectRgn (dragRgn, & dragRect);
            dragRectControl = kNothing;
        }
        if (wtime > -1)
            sleeppyTick = 60 * wtime / 1000;
        else
            sleeppyTick = 32767;
        if (WaitNextEventWrp (mask, &event, sleeppyTick, dragRgn)) {
            gui_mac_handle_event (& event);
            if (input_available ()) {
                allow_scrollbar = FALSE;
                return OK;
            }
        }
        currentTick = TickCount ();
    }
    while ((wtime == -1) || ((currentTick - entryTick) < 60 * wtime / 1000));
    allow_scrollbar = FALSE;
    return FAIL;
}

pascal Boolean WaitNextEventWrp (EventMask eventMask, EventRecord *theEvent, UInt32 sleep, RgnHandle mouseRgn) {
    if (((long ) sleep) < -1)
        sleep = 32767;
    return WaitNextEvent (eventMask, theEvent, sleep, mouseRgn);
}

void gui_mac_handle_event (EventRecord *event) {
    OSErr error;
    if (IsShowContextualMenuClick (event)) {
        gui_mac_doMouseDownEvent (event);
        return;
    }
    switch (event->what) {
    case (keyDown) :
    case (autoKey) :
        gui_mac_doKeyEvent (event);
        break;
    case (keyUp) :
        break;
    case (mouseDown) :
        gui_mac_doMouseDownEvent (event);
        break;
    case (mouseUp) :
        gui_mac_doMouseUpEvent (event);
        break;
    case (updateEvt) :
        gui_mac_doUpdateEvent (event);
        break;
    case (diskEvt) :
        break;
    case (activateEvt) :
        gui_mac_doActivateEvent (event);
        break;
    case (osEvt) :
        switch ((event->message >> 24) & 0xFF) {
        case (0xFA) :
            gui_mac_doMouseMovedEvent (event);
            break;
        case (0x01) :
            gui_mac_doSuspendEvent (event);
            break;
        }
        break;
    }
}

void gui_mac_handle_menu (long  menuChoice) {
    short  menu = HiWord (menuChoice);
    short  item = LoWord (menuChoice);
    vimmenu_T *theVimMenu = root_menu;
    if (menu == 256) {
        if (item == 1)
            gui_mch_beep ();
    }
    else if (item != 0) {
        theVimMenu = gui_mac_get_vim_menu (menu, item, root_menu);
        if (theVimMenu)
            gui_menu_cb (theVimMenu);
    }
    HiliteMenu (0);
}

void gui_mch_beep (void) {
    SysBeep (1);
}

static vimmenu_T *gui_mac_get_vim_menu (short  menuID, short  itemIndex, vimmenu_T *pMenu) {
    short  index;
    vimmenu_T *pChildMenu;
    vimmenu_T *pElder = pMenu->parent;
    if ((pElder) &&(pElder->submenu_id == menuID)) {
        for (index = 1; (index != itemIndex) && (pMenu != NULL); index++)
            pMenu = pMenu->next;
    }
    else {
        for (; pMenu != NULL; pMenu = pMenu->next) {
            if (pMenu->children != NULL) {
                pChildMenu = gui_mac_get_vim_menu (menuID, itemIndex, pMenu->children);
                if (pChildMenu) {
                    pMenu = pChildMenu;
                    break;
                }
            }
        }
    }
    return pMenu;
}

void gui_mac_doMouseDownEvent (EventRecord *theEvent) {
    short  thePart;
    WindowPtr whichWindow;
    thePart = FindWindow (theEvent->where, &whichWindow);
    switch (thePart) {
    case (inDesk) :
        break;
    case (inMenuBar) :
        gui_mac_handle_menu (MenuSelect (theEvent->where));
        break;
    case (inContent) :
        gui_mac_doInContentClick (theEvent, whichWindow);
        break;
    case (inDrag) :
        gui_mac_doInDragClick (theEvent->where, whichWindow);
        break;
    case (inGrow) :
        gui_mac_doInGrowClick (theEvent->where, whichWindow);
        break;
    case (inGoAway) :
        if (TrackGoAway (whichWindow, theEvent->where))
            gui_shell_closed ();
        break;
    case (inZoomIn) :
    case (inZoomOut) :
        gui_mac_doInZoomClick (theEvent, whichWindow);
        break;
    }
}

void gui_mac_doInContentClick (EventRecord *theEvent, WindowPtr whichWindow) {
    Point thePoint;
    int_u vimModifiers;
    short  thePortion;
    ControlHandle theControl;
    int vimMouseButton;
    short  dblClick;
    thePoint = theEvent->where;
    GlobalToLocal (& thePoint);
    SelectWindow (whichWindow);
    thePortion = FindControl (thePoint, whichWindow, &theControl);
    if (theControl != NUL) {
        if (thePortion != kControlIndicatorPart) {
            dragged_sb = theControl;
            TrackControl (theControl, thePoint, gScrollAction);
            dragged_sb = NULL;
        }
        else {
            dragged_sb = theControl;
            TrackControl (theControl, thePoint, NULL);
            gui_mac_drag_thumb (theControl, 0);
            dragged_sb = NULL;
        }
    }
    else {
        vimModifiers = EventModifiers2VimMouseModifiers (theEvent->modifiers);
        vimMouseButton = MOUSE_LEFT;
        clickIsPopup = FALSE;
        if (mouse_model_popup () && IsShowContextualMenuClick (theEvent)) {
            vimMouseButton = MOUSE_RIGHT;
            vimModifiers &= ~MOUSE_CTRL;
            clickIsPopup = TRUE;
        }
        dblClick = ((theEvent->when - lastMouseTick) < GetDblTime ());
        gui_send_mouse_event (vimMouseButton, thePoint.h, thePoint.v, dblClick, vimModifiers);
        {
            SetRect (& dragRect, FILL_X (X_2_COL (thePoint.h)), FILL_Y (Y_2_ROW (thePoint.v)), FILL_X (X_2_COL (thePoint.h) + 1), FILL_Y (Y_2_ROW (thePoint.v) + 1));
            dragRectEnbl = TRUE;
            dragRectControl = kCreateRect;
        }
    }
}

pascal void gui_mac_drag_thumb (ControlHandle theControl, short  partCode) {
    scrollbar_T *sb;
    int value, dragging;
    ControlHandle theControlToUse;
    int dont_scroll_save = dont_scroll;
    theControlToUse = dragged_sb;
    sb = gui_find_scrollbar ((long ) GetControlReference (theControlToUse));
    if (sb == NULL)
        return;
    value = GetControl32BitValue (theControlToUse);
    dragging = (partCode != 0);
    dont_scroll = !allow_scrollbar;
    gui_drag_scrollbar (sb, value, dragging);
    dont_scroll = dont_scroll_save;
}

int gui_mch_haskey (char_u *name) {
    int i;
    for (i = 0; special_keys[i].key_sym != (KeySym) 0; i++)
        if (name[0] == special_keys[i].vim_code0 && name[1] == special_keys[i].vim_code1)
            return OK;
    return FAIL;
}

void gui_mch_clear_all (void) {
    Rect rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = Columns * gui.char_width + 2 * gui.border_width;
    rc.bottom = Rows * gui.char_height + 2 * gui.border_width;
    gui_mch_set_bg_color (gui.back_pixel);
    EraseRect (& rc);
}

void gui_mch_set_bg_color (guicolor_T color) {
    RGBColor TheColor;
    TheColor.red = Red (color) * 0x0101;
    TheColor.green = Green (color) * 0x0101;
    TheColor.blue = Blue (color) * 0x0101;
    RGBBackColor (& TheColor);
}

void gui_mch_invert_rectangle (int r, int c, int nr, int nc) {
    Rect rc;
    rc.left = FILL_X (c);
    rc.top = FILL_Y (r);
    rc.right = rc.left + nc * gui.char_width;
    rc.bottom = rc.top + nr * gui.char_height;
    InvertRect (& rc);
}

void gui_mch_clear_block (int row1, int col1, int row2, int col2) {
    Rect rc;
    rc.left = FILL_X (col1);
    rc.top = FILL_Y (row1);
    rc.right = FILL_X (col2 +1) + (col2 == Columns - 1);
    rc.bottom = FILL_Y (row2 +1);
    gui_mch_set_bg_color (gui.back_pixel);
    EraseRect (& rc);
}

void gui_mch_delete_lines (int row, int num_lines) {
    Rect rc;
    rc.left = FILL_X (gui.scroll_region_left);
    rc.right = FILL_X (gui.scroll_region_right + 1);
    rc.top = FILL_Y (row);
    rc.bottom = FILL_Y (gui.scroll_region_bot + 1);
    gui_mch_set_bg_color (gui.back_pixel);
    ScrollRect (& rc, 0, - num_lines * gui.char_height, (RgnHandle) nil);
    gui_clear_block (gui.scroll_region_bot - num_lines + 1, gui.scroll_region_left, gui.scroll_region_bot, gui.scroll_region_right);
}

void gui_mch_insert_lines (int row, int num_lines) {
    Rect rc;
    rc.left = FILL_X (gui.scroll_region_left);
    rc.right = FILL_X (gui.scroll_region_right + 1);
    rc.top = FILL_Y (row);
    rc.bottom = FILL_Y (gui.scroll_region_bot + 1);
    gui_mch_set_bg_color (gui.back_pixel);
    ScrollRect (& rc, 0, gui.char_height * num_lines, (RgnHandle) nil);
    if (gui.cursor_row >= gui.row && gui.cursor_col >= gui.scroll_region_left && gui.cursor_col <= gui.scroll_region_right) {
        if (gui.cursor_row <= gui.scroll_region_bot - num_lines)
            gui.cursor_row += num_lines;
        else if (gui.cursor_row <= gui.scroll_region_bot)
            gui.cursor_is_valid = FALSE;
    }
    gui_clear_block (row, gui.scroll_region_left, row + num_lines - 1, gui.scroll_region_right);
}

void gui_mch_flash (int msec) {
    Rect rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = gui.num_cols * gui.char_width;
    rc.bottom = gui.num_rows * gui.char_height;
    InvertRect (& rc);
    ui_delay ((long) msec, TRUE);
    InvertRect (& rc);
}

void gui_mch_menu_grey (vimmenu_T *menu, int grey) {
    short  index = gui_mac_get_menu_item_index (menu);
    if (grey) {
        if (menu->children)
            DisableMenuItem (menu->submenu_handle, index);
        if (menu->parent)
            if (menu->parent->submenu_handle)
                DisableMenuItem (menu->parent->submenu_handle, index);
    }
    else {
        if (menu->children)
            EnableMenuItem (menu->submenu_handle, index);
        if (menu->parent)
            if (menu->parent->submenu_handle)
                EnableMenuItem (menu->parent->submenu_handle, index);
    }
}

short  gui_mac_get_menu_item_index (vimmenu_T *pMenu) {
    short  index;
    short  itemIndex = -1;
    vimmenu_T *pBrother;
    if (pMenu->parent) {
        pBrother = pMenu->parent->children;
        index = 1;
        while ((pBrother) &&(itemIndex == -1)) {
            if (pBrother == pMenu)
                itemIndex = index;
            index++;
            pBrother = pBrother->next;
        }
    }
    return itemIndex;
}

void gui_mch_menu_hidden (vimmenu_T *menu, int hidden) {
    gui_mch_menu_grey (menu, hidden);
}

void gui_mch_draw_menubar (void) {
    DrawMenuBar ();
}

void gui_mch_flush (void) {
}

void gui_mch_start_blink (void) {
    gui_update_cursor (TRUE, FALSE);
}

void gui_mch_set_font (GuiFont font) {
    TextSize (font >> 16);
    TextFont (font & 0xFFFF);
}

void gui_mch_set_fg_color (guicolor_T color) {
    RGBColor TheColor;
    TheColor.red = Red (color) * 0x0101;
    TheColor.green = Green (color) * 0x0101;
    TheColor.blue = Blue (color) * 0x0101;
    RGBForeColor (& TheColor);
}

void gui_mch_set_sp_color (guicolor_T color) {
    specialColor.red = Red (color) * 0x0101;
    specialColor.green = Green (color) * 0x0101;
    specialColor.blue = Blue (color) * 0x0101;
}

void gui_mch_draw_string (int row, int col, char_u *s, int len, int flags) {
    draw_string_QD (row, col, s, len, flags);
}

static void draw_undercurl (int flags, int row, int col, int cells) {
    int x;
    int offset;
    const static int val [8] = {1, 0, 0, 0, 1, 2, 2, 2};
    int y = FILL_Y (row +1) - 1;
    RGBForeColor (& specialColor);
    offset = val[FILL_X (col) % 8];
    MoveTo (FILL_X (col), y - offset);
    for (x = FILL_X (col); x < FILL_X (col +cells); ++x) {
        offset = val[x % 8];
        LineTo (x, y - offset);
    }
}

static void draw_string_QD (int row, int col, char_u *s, int len, int flags) {
    if (gMacSystemVersion >= 0x1020) {
        UInt32 qd_flags = (p_antialias ? kQDUseCGTextRendering | kQDUseCGTextMetrics : 0);
        QDSwapTextFlags (qd_flags);
    }
    if (((gMacSystemVersion >= 0x1020 && p_antialias) || p_linespace != 0) && !(flags & DRAW_TRANSP)) {
        Rect rc;
        rc.left = FILL_X (col);
        rc.top = FILL_Y (row);
        rc.right = FILL_X (col +len) + (col + len == Columns);
        rc.bottom = FILL_Y (row +1);
        EraseRect (& rc);
    }
    if (gMacSystemVersion >= 0x1020 && p_antialias) {
        StyleParameter face;
        face = normal;
        if (flags & DRAW_BOLD)
            face |= bold;
        if (flags & DRAW_UNDERL)
            face |= underline;
        TextFace (face);
        TextMode (srcOr);
        MoveTo (TEXT_X (col), TEXT_Y (row));
        DrawText ((char *) s, 0, len);
    }
    else {
        TextMode (srcCopy);
        TextFace (normal);
        if (flags & DRAW_TRANSP) {
            TextMode (srcOr);
        }
        MoveTo (TEXT_X (col), TEXT_Y (row));
        DrawText ((char *) s, 0, len);
        if (flags & DRAW_BOLD) {
            TextMode (srcOr);
            MoveTo (TEXT_X (col) + 1, TEXT_Y (row));
            DrawText ((char *) s, 0, len);
        }
        if (flags & DRAW_UNDERL) {
            MoveTo (FILL_X (col), FILL_Y (row + 1) - 1);
            LineTo (FILL_X (col + len) - 1, FILL_Y (row + 1) - 1);
        }
        if (flags & DRAW_STRIKE) {
            MoveTo (FILL_X (col), FILL_Y (row + 1) - gui.char_height / 2);
            LineTo (FILL_X (col + len) - 1, FILL_Y (row + 1) - gui.char_height / 2);
        }
    }
    if (flags & DRAW_UNDERC)
        draw_undercurl (flags, row, col, len);
}

void gui_mch_getmouse (int *x, int *y) {
    Point where;
    GetMouse (& where);
    *x = where.h;
    *y = where.v;
}

void gui_mch_set_blinking (long  wait, long  on, long  off) {
}

void gui_mch_stop_blink (int may_call_gui_update_cursor) {
    if (may_call_gui_update_cursor)
        gui_update_cursor (TRUE, FALSE);
}

void gui_mch_draw_hollow_cursor (guicolor_T color) {
    Rect rc;
    rc.left = FILL_X (gui.col);
    rc.top = FILL_Y (gui.row);
    rc.right = rc.left + gui.char_width;
    rc.bottom = rc.top + gui.char_height;
    gui_mch_set_fg_color (color);
    FrameRect (& rc);
}

void gui_mch_draw_part_cursor (int w, int h, guicolor_T color) {
    Rect rc;
    if (CURSOR_BAR_RIGHT)
        rc.left = FILL_X (gui.col + 1) - w;
    else
        rc.left = FILL_X (gui.col);
    rc.top = FILL_Y (gui.row) + gui.char_height - h;
    rc.right = rc.left + w;
    rc.bottom = rc.top + h;
    gui_mch_set_fg_color (color);
    FrameRect (& rc);
}

int clip_mch_own_selection (VimClipboard *cbd) {
    return OK;
}

void clip_mch_set_selection (VimClipboard *cbd) {
    Handle textOfClip;
    long  scrapSize;
    int type;
    ScrapRef scrap;
    char_u *str = NULL;
    if (!cbd->owned)
        return;
    clip_get_selection (cbd);
    cbd->owned = FALSE;
    type = clip_convert_selection (&str, (long_u *) &scrapSize, cbd);
    size_t utf16_len = 0;
    UniChar *to = mac_enc_to_utf16 (str, scrapSize, &utf16_len);
    if (to) {
        scrapSize = utf16_len;
        vim_free (str);
        str = (char_u *) to;
    }
    if (type >= 0) {
        ClearCurrentScrap ();
        textOfClip = NewHandle (scrapSize +1);
        HLock (textOfClip);
        **textOfClip = type;
        mch_memmove (* textOfClip + 1, str, scrapSize);
        GetCurrentScrap (& scrap);
        PutScrapFlavor (scrap, SCRAPTEXTFLAVOR, kScrapFlavorMaskNone, scrapSize, * textOfClip + 1);
        PutScrapFlavor (scrap, VIMSCRAPFLAVOR, kScrapFlavorMaskNone, scrapSize + 1, * textOfClip);
        HUnlock (textOfClip);
        DisposeHandle (textOfClip);
    }
    vim_free (str);
}

int gui_mch_get_winpos (int *x, int *y) {
    Rect bounds;
    OSStatus status;
    status = GetWindowBounds (gui.VimWindow, kWindowStructureRgn, &bounds);
    if (status != noErr)
        return FAIL;
    *x = bounds.left;
    *y = bounds.top;
    return OK;
}

void gui_mch_get_screen_dimensions (int *screen_w, int *screen_h) {
    GDHandle dominantDevice = GetMainDevice ();
    Rect screenRect = (**dominantDevice).gdRect;
    *screen_w = screenRect.right - 10;
    *screen_h = screenRect.bottom - 40;
}

void gui_mch_set_shellsize (int width, int height, int min_width, int min_height, int base_width, int base_height, int direction) {
    CGrafPtr VimPort;
    Rect VimBound;
    if (gui.which_scrollbars[SBAR_LEFT]) {
        VimPort = GetWindowPort (gui.VimWindow);
        GetPortBounds (VimPort, & VimBound);
        VimBound.left = -gui.scrollbar_width;
        SetPortBounds (VimPort, & VimBound);
    }
    else {
        VimPort = GetWindowPort (gui.VimWindow);
        GetPortBounds (VimPort, & VimBound);
        VimBound.left = 0;
        SetPortBounds (VimPort, & VimBound);
    }
    SizeWindow (gui.VimWindow, width, height, TRUE);
    gui_resize_shell (width, height);
}

void gui_mch_set_winpos (int x, int y) {
    MoveWindowStructure (gui.VimWindow, x, y);
}

void gui_mch_mousehide (int hide) {
}

int gui_mch_init_check (void) {
    if (disallow_gui)
        return FAIL;
    return OK;
}

int gui_mch_init (void) {
    Rect windRect;
    MenuHandle pomme;
    EventHandlerRef mouseWheelHandlerRef;
    EventTypeSpec eventTypeSpec;
    ControlRef rootControl;
    if (Gestalt (gestaltSystemVersion, &gMacSystemVersion) != noErr)
        gMacSystemVersion = 0x1000;
    display_errors ();
    gui.norm_pixel = 0x00000000;
    gui.back_pixel = 0x00FFFFFF;
    set_normal_colors ();
    gui_check_colors ();
    gui.def_norm_pixel = gui.norm_pixel;
    gui.def_back_pixel = gui.back_pixel;
    highlight_gui_started ();
    gui.menu_height = 0;
    gui.scrollbar_height = gui.scrollbar_width = 15;
    gui.border_offset = gui.border_width = 2;
    vim_setenv ((char_u *) "QDTEXT_MINSIZE", (char_u *) "1");
    eventTypeSpec.eventClass = kEventClassMouse;
    eventTypeSpec.eventKind = kEventMouseWheelMoved;
    mouseWheelHandlerUPP = NewEventHandlerUPP (gui_mac_mouse_wheel);
    if (noErr != InstallApplicationEventHandler (mouseWheelHandlerUPP, 1, &eventTypeSpec, NULL, &mouseWheelHandlerRef)) {
        mouseWheelHandlerRef = NULL;
        DisposeEventHandlerUPP (mouseWheelHandlerUPP);
        mouseWheelHandlerUPP = NULL;
    }
    return OK;
}

char_u **new_fnames_from_AEDesc (AEDesc *theList, long  *numFiles, OSErr *error) {
    char_u **fnames = NULL;
    OSErr newError;
    long  fileCount;
    FSSpec fileToOpen;
    long  actualSize;
    AEKeyword dummyKeyword;
    DescType dummyType;
    *error = AECountItems (theList, numFiles);
    if (*error)
        return fnames;
    fnames = (char_u **) alloc (*numFiles * sizeof (char_u *));
    for (fileCount = 0; fileCount < *numFiles; fileCount++)
        fnames[fileCount] = NULL;
    for (fileCount = 1; fileCount <= *numFiles; fileCount++) {
        newError = AEGetNthPtr (theList, fileCount, typeFSS, &dummyKeyword, &dummyType, (Ptr) &fileToOpen, sizeof (FSSpec), &actualSize);
        if (newError) {
            return fnames;
        }
        fnames[fileCount - 1] = FullPathFromFSSpec_save (fileToOpen);
    }
    return (fnames);
}

char_u *FullPathFromFSSpec_save (FSSpec file) {
    CInfoPBRec theCPB;
    char_u fname [256];
    char_u *filenamePtr = fname;
    OSErr error;
    int folder = 1;
    Str255 directoryName;
    char_u temporary [255];
    char_u *temporaryPtr = temporary;
    vim_strncpy (filenamePtr, & file.name [1], file.name [0]);
    theCPB.dirInfo.ioFDirIndex = 0;
    theCPB.dirInfo.ioNamePtr = file.name;
    theCPB.dirInfo.ioVRefNum = file.vRefNum;
    theCPB.dirInfo.ioDrDirID = file.parID;
    error = PBGetCatInfo (&theCPB, false);
    if ((error) &&(error != fnfErr))
        return NULL;
    if (((theCPB.hFileInfo.ioFlAttrib & ioDirMask) == 0) || (error))
        folder = 0;
    else
        folder = 1;
    theCPB.dirInfo.ioNamePtr = directoryName;
    theCPB.dirInfo.ioDrParID = file.parID;
    theCPB.dirInfo.ioDrDirID = file.parID;
    if ((TRUE) &&(file.parID != fsRtDirID))
        do {
            theCPB.dirInfo.ioFDirIndex = -1;
            theCPB.dirInfo.ioVRefNum = file.vRefNum;
            theCPB.dirInfo.ioDrDirID = theCPB.dirInfo.ioDrParID;
            error = PBGetCatInfo (&theCPB, false);
            if (error)
                return NULL;
            STRCPY (temporaryPtr, filenamePtr);
            vim_strncpy (filenamePtr, & directoryName [1], directoryName [0]);
            STRCAT (filenamePtr, ":");
            STRCAT (filenamePtr, temporaryPtr);
        }
        while (theCPB.dirInfo.ioDrDirID != fsRtDirID);
    theCPB.dirInfo.ioFDirIndex = -1;
    theCPB.dirInfo.ioVRefNum = file.vRefNum;
    theCPB.dirInfo.ioDrDirID = theCPB.dirInfo.ioDrParID;
    error = PBGetCatInfo (&theCPB, false);
    if (error)
        return NULL;
    {
        STRCPY (temporaryPtr, filenamePtr);
        vim_strncpy (filenamePtr, & directoryName [1], directoryName [0]);
        STRCAT (filenamePtr, ":");
        STRCAT (filenamePtr, temporaryPtr);
    }
    if (folder)
        STRCAT (fname, ":");
    return (vim_strsave (fname));
}

void gui_mch_free_font (GuiFont font) {
}

GuiFont gui_mch_get_font (char_u *name, int giveErrorIfMissing) {
    GuiFont font;
    font = gui_mac_find_font (name);
    if (font == NOFONT) {
        if (giveErrorIfMissing)
            EMSG2 (_ (e_font), name);
        return NOFONT;
    }
    return font;
}

GuiFont gui_mac_find_font (char_u *font_name) {
    char_u c;
    char_u *p;
    char_u pFontName [256];
    Str255 systemFontname;
    short  font_id;
    short  size = 9;
    GuiFont font;
    for (p = font_name; ((*p != 0) && (*p != ':')); p++)
        ;
    c = *p;
    *p = 0;
    fontNamePtr = C2Pascal_save_and_remove_backslash (font_name);
    GetFNum (fontNamePtr, & font_id);
    if (font_id == 0) {
        if (FMGetFontFamilyName (systemFont, systemFontname) != noErr)
            return NOFONT;
        if (!EqualString (pFontName, systemFontname, false, false))
            return NOFONT;
    }
    if (*p == ':') {
        p++;
        while (*p) {
            switch (*p++) {
            case 'h' :
                size = points_to_pixels (p, &p, TRUE);
                break;
            }
            while (*p == ':')
                p++;
        }
    }
    if (size < 1)
        size = 1;
    font = (size << 16) + ((long ) font_id & 0xFFFF);
    return font;
}

char_u *C2Pascal_save_and_remove_backslash (char_u *Cstring) {
    char_u *PascalString;
    int len;
    char_u *p, *c;
    len = STRLEN (Cstring);
    if (len > 255)
        len = 255;
    PascalString = alloc (len +1);
    if (PascalString != NULL) {
        for (c = Cstring, p = PascalString + 1, len = 0; (*c != 0) && (len < 255); c++) {
            if ((*c == '\\') && (c[1] != 0)) {
                c++;
            }
            *p = *c;
            p++;
            len++;
        }
        PascalString[0] = len;
    }
    return PascalString;
}

static int points_to_pixels (char_u *str, char_u **end, int vertical) {
    int pixels;
    int points = 0;
    int divisor = 0;
    while (*str) {
        if (*str == '.' && divisor == 0) {
            divisor = 1;
            continue;
        }
        if (!isdigit (*str))
            break;
        points *= 10;
        points += *str - '0';
        divisor *= 10;
        ++str;
    }
    if (divisor == 0)
        divisor = 1;
    pixels = points / divisor;
    *end = str;
    return pixels;
}

int gui_mch_init_font (char_u *font_name, int fontset) {
    Str255 suggestedFont = "\pMonaco";
    int suggestedSize = 10;
    FontInfo font_info;
    short  font_id;
    GuiFont font;
    char_u used_font_name [512];
    if (font_name == NULL) {
        GetFNum (suggestedFont, & font_id);
        if (font_id == 0) {
            font_id = GetAppFont ();
            STRCPY (used_font_name, "default");
        }
        else
            STRCPY (used_font_name, "Monaco");
        font = (suggestedSize << 16) + ((long ) font_id & 0xFFFF);
    }
    else if (STRCMP (font_name, "*") == 0) {
        char_u *new_p_guifont;
        font = gui_mac_select_font (used_font_name);
        if (font == NOFONT)
            return FAIL;
        new_p_guifont = alloc (STRLEN (used_font_name) +1);
        if (new_p_guifont != NULL) {
            STRCPY (new_p_guifont, used_font_name);
            vim_free (p_guifont);
            p_guifont = new_p_guifont;
            for (; *new_p_guifont; ++new_p_guifont) {
                if (*new_p_guifont == ' ')
                    *new_p_guifont = '_';
            }
        }
    }
    else {
        font = gui_mac_find_font (font_name);
        vim_strncpy (used_font_name, font_name, sizeof (used_font_name) - 1);
        if (font == NOFONT)
            return FAIL;
    }
    gui.norm_font = font;
    hl_set_font_name (used_font_name);
    TextSize (font >> 16);
    TextFont (font & 0xFFFF);
    GetFontInfo (& font_info);
    gui.char_ascent = font_info.ascent;
    gui.char_width = p_columnspace + CharWidth ('_');
    gui.char_height = font_info.ascent + font_info.descent + p_linespace;
    return OK;
}

static GuiFont gui_mac_select_font (char_u *font_name) {
    GuiFont selected_font = NOFONT;
    OSStatus status;
    FontSelectionQDStyle curr_font;
    curr_font.instance.fontFamily = gui.norm_font & 0xFFFF;
    curr_font.size = (gui.norm_font >> 16);
    curr_font.instance.fontStyle = 0;
    curr_font.hasColor = false;
    curr_font.version = 0;
    status = SetFontInfoForSelection (kFontSelectionQDType, 1, &curr_font, NULL);
    gFontPanelInfo.family = curr_font.instance.fontFamily;
    gFontPanelInfo.style = curr_font.instance.fontStyle;
    gFontPanelInfo.size = curr_font.size;
    status = FPShowHideFontPanel ();
    if (status == noErr) {
        gFontPanelInfo.isPanelVisible = true;
        while (gFontPanelInfo.isPanelVisible) {
            EventRecord e;
            WaitNextEvent (everyEvent, & e, 20, NULL);
        }
        GetFontPanelSelection (font_name);
        selected_font = gui_mac_find_font (font_name);
    }
    return selected_font;
}

static void GetFontPanelSelection (char_u *outName) {
    Str255 buf;
    ByteCount fontNameLen = 0;
    ATSUFontID fid;
    char_u styleString [FONT_STYLE_BUFFER_SIZE];
    if (!outName)
        return;
    if (FMGetFontFamilyName (gFontPanelInfo.family, buf) == noErr) {
        if (FMGetFontFromFontFamilyInstance (gFontPanelInfo.family, gFontPanelInfo.style, &fid, NULL) != noErr)
            return;
        if (ATSUFindFontName (fid, kFontFullName, kFontMacintoshPlatform, kFontNoScriptCode, kFontNoLanguageCode, 255, (char *) outName, &fontNameLen, NULL) != noErr)
            return;
        vim_snprintf ((char *) styleString, FONT_STYLE_BUFFER_SIZE, ":h%d", gFontPanelInfo.size);
        if ((fontNameLen + STRLEN (styleString)) < 255)
            STRCPY (outName +fontNameLen, styleString);
    }
    else {
        *outName = NUL;
    }
}

void gui_mch_new_colors (void) {
}

int gui_mch_adjust_charheight (void) {
    FontInfo font_info;
    GetFontInfo (& font_info);
    gui.char_height = font_info.ascent + font_info.descent + p_linespace;
    gui.char_ascent = font_info.ascent + p_linespace / 2;
    return OK;
}

int gui_mch_adjust_charwidth (void) {
    gui.char_width = p_columnspace + CharWidth ('_');
    return OK;
}

guicolor_T gui_mch_get_rgb (guicolor_T pixel) {
    return (guicolor_T) ((Red (pixel) << 16) + (Green (pixel) << 8) + Blue (pixel));
}

guicolor_T gui_mch_get_rgb_color (int r, int g, int b) {
    return gui_get_rgb_color_cmn (r, g, b);
}

static OSErr receiveHandler (WindowRef theWindow, void *handlerRefCon, DragRef theDrag) {
    int x, y;
    int_u modifiers;
    char_u **fnames = NULL;
    int count;
    int i, j;
    {
        Point point;
        SInt16 mouseUpModifiers;
        UInt16 countItem;
        GetDragMouse (theDrag, & point, NULL);
        GlobalToLocal (& point);
        x = point.h;
        y = point.v;
        GetDragModifiers (theDrag, NULL, NULL, & mouseUpModifiers);
        modifiers = EventModifiers2VimMouseModifiers (mouseUpModifiers);
        CountDragItems (theDrag, & countItem);
        count = countItem;
    }
    fnames = (char_u **) alloc (count * sizeof (char_u *));
    if (fnames == NULL)
        return dragNotAcceptedErr;
    for (i = j = 0; i < count; ++i) {
        DragItemRef item;
        OSErr err;
        Size size;
        FlavorType type = flavorTypeHFS;
        HFSFlavor hfsFlavor;
        fnames[i] = NULL;
        GetDragItemReferenceNumber (theDrag, i + 1, & item);
        err = GetFlavorDataSize (theDrag, item, type, &size);
        if (err != noErr || size > sizeof (hfsFlavor))
            continue;
        err = GetFlavorData (theDrag, item, type, &hfsFlavor, &size, 0);
        if (err != noErr)
            continue;
        fnames[j++] = FullPathFromFSSpec_save (hfsFlavor.fileSpec);
    }
    count = j;
    gui_handle_drop (x, y, modifiers, fnames, count);
    PostEvent (mouseUp, 0);
    return noErr;
}

int_u EventModifiers2VimMouseModifiers (EventModifiers macModifiers) {
    int_u vimModifiers = 0x00;
    if (macModifiers & (shiftKey | rightShiftKey))
        vimModifiers |= MOUSE_SHIFT;
    if (macModifiers & (controlKey | rightControlKey))
        vimModifiers |= MOUSE_CTRL;
    if (macModifiers & (optionKey | rightOptionKey))
        vimModifiers |= MOUSE_ALT;
    return (vimModifiers);
}

pascal void gui_mac_scroll_action (ControlHandle theControl, short  partCode) {
    scrollbar_T *sb, *sb_info;
    long  data;
    long  value;
    int page;
    int dragging = FALSE;
    int dont_scroll_save = dont_scroll;
    sb = gui_find_scrollbar ((long ) GetControlReference (theControl));
    if (sb == NULL)
        return;
    if (sb->wp != NULL) {
        sb_info = &sb->wp->w_scrollbars[0];
        if (sb_info->size > 5)
            page = sb_info->size - 2;
        else
            page = sb_info->size;
    }
    else {
        sb_info = sb;
        page = curwin->w_width - 5;
    }
    switch (partCode) {
    case kControlUpButtonPart :
        data = -1;
        break;
    case kControlDownButtonPart :
        data = 1;
        break;
    case kControlPageDownPart :
        data = page;
        break;
    case kControlPageUpPart :
        data = -page;
        break;
    default :
        data = 0;
        break;
    }
    value = sb_info->value + data;
    dont_scroll = !allow_scrollbar;
    gui_drag_scrollbar (sb, value, dragging);
    dont_scroll = dont_scroll_save;
    out_flush ();
    gui_mch_set_scrollbar_thumb (sb, value, sb_info -> size, sb_info -> max);
}

void gui_mch_set_scrollbar_thumb (scrollbar_T *sb, long  val, long  size, long  max) {
    SetControl32BitMaximum (sb -> id, max);
    SetControl32BitMinimum (sb -> id, 0);
    SetControl32BitValue (sb -> id, val);
    SetControlViewSize (sb -> id, size);
}

static void InstallFontPanelHandler (void) {
    EventTypeSpec eventTypes [2];
    EventHandlerUPP handlerUPP;
    eventTypes[0].eventClass = kEventClassFont;
    eventTypes[0].eventKind = kEventFontSelection;
    eventTypes[1].eventClass = kEventClassFont;
    eventTypes[1].eventKind = kEventFontPanelClosed;
    handlerUPP = NewEventHandlerUPP (FontPanelHandler);
    InstallApplicationEventHandler (handlerUPP, 2, eventTypes, NULL, NULL);
}

#define FONT_STYLE_BUFFER_SIZE 32

static OSStatus FontPanelHandler (EventHandlerCallRef inHandlerCallRef, EventRef inEvent, void *inUserData) {
    if (GetEventKind (inEvent) == kEventFontPanelClosed) {
        gFontPanelInfo.isPanelVisible = false;
        return noErr;
    }
    if (GetEventKind (inEvent) == kEventFontSelection) {
        OSStatus status;
        FMFontFamily newFamily;
        FMFontSize newSize;
        FMFontStyle newStyle;
        status = GetEventParameter (inEvent, kEventParamFMFontFamily, typeFMFontFamily, NULL, sizeof (FMFontFamily), NULL, &newFamily);
        if (status == noErr)
            gFontPanelInfo.family = newFamily;
        status = GetEventParameter (inEvent, kEventParamFMFontSize, typeFMFontSize, NULL, sizeof (FMFontSize), NULL, &newSize);
        if (status == noErr)
            gFontPanelInfo.size = newSize;
        status = GetEventParameter (inEvent, kEventParamFMFontStyle, typeFMFontStyle, NULL, sizeof (FMFontStyle), NULL, &newStyle);
        if (status == noErr)
            gFontPanelInfo.style = newStyle;
    }
    return noErr;
}

guicolor_T gui_mch_get_color (char_u *name) {
    RGBColor MacColor;
    if (STRICMP (name, "hilite") == 0) {
        LMGetHiliteRGB (& MacColor);
        return (RGB (MacColor.red >> 8, MacColor.green >> 8, MacColor.blue >> 8));
    }
    return gui_get_color_cmn (name);
}

static pascal OSStatus gui_mac_mouse_wheel (EventHandlerCallRef nextHandler, EventRef theEvent, void *data) {
    Point point;
    Rect bounds;
    UInt32 mod;
    SInt32 delta;
    int_u vim_mod;
    EventMouseWheelAxis axis;
    if (noErr == GetEventParameter (theEvent, kEventParamMouseWheelAxis, typeMouseWheelAxis, NULL, sizeof (axis), NULL, &axis) && axis != kEventMouseWheelAxisY)
        goto bail;
    if (noErr != GetEventParameter (theEvent, kEventParamMouseWheelDelta, typeSInt32, NULL, sizeof (SInt32), NULL, &delta))
        goto bail;
    if (noErr != GetEventParameter (theEvent, kEventParamMouseLocation, typeQDPoint, NULL, sizeof (Point), NULL, &point))
        goto bail;
    if (noErr != GetEventParameter (theEvent, kEventParamKeyModifiers, typeUInt32, NULL, sizeof (UInt32), NULL, &mod))
        goto bail;
    vim_mod = 0;
    if (mod & shiftKey)
        vim_mod |= MOUSE_SHIFT;
    if (mod & controlKey)
        vim_mod |= MOUSE_CTRL;
    if (mod & optionKey)
        vim_mod |= MOUSE_ALT;
    if (noErr == GetWindowBounds (gui.VimWindow, kWindowContentRgn, &bounds)) {
        point.h -= bounds.left;
        point.v -= bounds.top;
    }
    gui_send_mouse_event ((delta > 0) ? MOUSE_4 : MOUSE_5, point.h, point.v, FALSE, vim_mod);
    PostEvent (keyUp, 0);
    return noErr;
bail :
    return CallNextEventHandler (nextHandler, theEvent);
}

static int_u EventModifiers2VimModifiers (EventModifiers macModifiers) {
    int_u vimModifiers = 0x00;
    if (macModifiers & (shiftKey | rightShiftKey))
        vimModifiers |= MOD_MASK_SHIFT;
    if (macModifiers & (controlKey | rightControlKey))
        vimModifiers |= MOD_MASK_CTRL;
    if (macModifiers & (optionKey | rightOptionKey))
        vimModifiers |= MOD_MASK_ALT;
    return (vimModifiers);
}

int gui_mch_open (void) {
    ShowWindow (gui.VimWindow);
    if (gui_win_x != -1 && gui_win_y != -1)
        gui_mch_set_winpos (gui_win_x, gui_win_y);
    {
        ProcessSerialNumber psn;
        if (GetCurrentProcess (&psn) == noErr)
            SetFrontProcess (&psn);
    }
    return OK;
}

void gui_mch_setmouse (int x, int y) {
}

int GetFSSpecFromPath (char_u *file, FSSpec *fileFSSpec) {
    Str255 filePascal;
    CInfoPBRec myCPB;
    OSErr err;
    (void) C2PascalString (file, &filePascal);
    myCPB.dirInfo.ioNamePtr = filePascal;
    myCPB.dirInfo.ioVRefNum = 0;
    myCPB.dirInfo.ioFDirIndex = 0;
    myCPB.dirInfo.ioDrDirID = 0;
    err = PBGetCatInfo (&myCPB, false);
    FSMakeFSSpec (0, 0, filePascal, fileFSSpec);
    return 0;
}

int C2PascalString (char_u *CString, Str255 *PascalString) {
    char_u *PascalPtr = (char_u *) PascalString;
    int len;
    int i;
    PascalPtr[0] = 0;
    if (CString == NULL)
        return 0;
    len = STRLEN (CString);
    if (len > 255)
        len = 255;
    for (i = 0; i < len; i++)
        PascalPtr[i + 1] = CString[i];
    PascalPtr[0] = len;
    return 0;
}

int gui_mch_is_blink_off (void) {
    return FALSE;
}

void gui_mch_set_foreground (void) {
}

void clip_mch_request_selection (VimClipboard *cbd) {
    Handle textOfClip;
    int flavor = 0;
    Size scrapSize;
    ScrapFlavorFlags scrapFlags;
    ScrapRef scrap = nil;
    OSStatus error;
    int type;
    char *searchCR;
    char_u *tempclip;
    error = GetCurrentScrap (&scrap);
    if (error != noErr)
        return;
    error = GetScrapFlavorFlags (scrap, VIMSCRAPFLAVOR, &scrapFlags);
    if (error == noErr) {
        error = GetScrapFlavorSize (scrap, VIMSCRAPFLAVOR, &scrapSize);
        if (error == noErr && scrapSize > 1)
            flavor = 1;
    }
    if (flavor == 0) {
        error = GetScrapFlavorFlags (scrap, SCRAPTEXTFLAVOR, &scrapFlags);
        if (error != noErr)
            return;
        error = GetScrapFlavorSize (scrap, SCRAPTEXTFLAVOR, &scrapSize);
        if (error != noErr)
            return;
    }
    ReserveMem (scrapSize);
    textOfClip = NewHandle (scrapSize);
    HLock (textOfClip);
    error = GetScrapFlavorData (scrap, flavor ? VIMSCRAPFLAVOR : SCRAPTEXTFLAVOR, &scrapSize, *textOfClip);
    scrapSize -= flavor;
    if (flavor)
        type = **textOfClip;
    else
        type = MAUTO;
    tempclip = lalloc (scrapSize +1, TRUE);
    mch_memmove (tempclip, * textOfClip + flavor, scrapSize);
    tempclip[scrapSize] = 0;
    {
        size_t encLen = 0;
        char_u *to = mac_utf16_to_enc ((UniChar *) tempclip, scrapSize, &encLen);
        if (to != NULL) {
            scrapSize = encLen;
            vim_free (tempclip);
            tempclip = to;
        }
    }
    searchCR = (char *) tempclip;
    while (searchCR != NULL) {
        searchCR = strchr (searchCR, '\r');
        if (searchCR != NULL)
            *searchCR = '\n';
    }
    clip_yank_selection (type, tempclip, scrapSize, cbd);
    vim_free (tempclip);
    HUnlock (textOfClip);
    DisposeHandle (textOfClip);
}

void gui_mac_doInDragClick (Point where, WindowPtr whichWindow) {
    Rect movingLimits;
    Rect *movingLimitsPtr = &movingLimits;
    movingLimitsPtr = GetRegionBounds (GetGrayRgn (), &movingLimits);
    DragWindow (whichWindow, where, movingLimitsPtr);
}

void gui_mac_doInGrowClick (Point where, WindowPtr whichWindow) {
    long  newSize;
    unsigned  short  newWidth;
    unsigned  short  newHeight;
    Rect resizeLimits;
    Rect *resizeLimitsPtr = &resizeLimits;
    Rect NewContentRect;
    resizeLimitsPtr = GetRegionBounds (GetGrayRgn (), &resizeLimits);
    resizeLimits.top = 100;
    resizeLimits.left = 100;
    newSize = ResizeWindow (whichWindow, where, &resizeLimits, &NewContentRect);
    newWidth = NewContentRect.right - NewContentRect.left;
    newHeight = NewContentRect.bottom - NewContentRect.top;
    gui_resize_shell (newWidth, newHeight);
    gui_mch_set_bg_color (gui.back_pixel);
    gui_set_shellsize (TRUE, FALSE, RESIZE_BOTH);
}

static void gui_mac_doInZoomClick (EventRecord *theEvent, WindowPtr whichWindow) {
    Rect r;
    Point p;
    short  thePart;
    p.h = Columns * gui.char_width + 2 * gui.border_offset;
    if (gui.which_scrollbars[SBAR_LEFT])
        p.h += gui.scrollbar_width;
    if (gui.which_scrollbars[SBAR_RIGHT])
        p.h += gui.scrollbar_width;
    p.v = 15 * 1024;
    thePart = IsWindowInStandardState (whichWindow, &p, &r) ? inZoomIn : inZoomOut;
    if (!TrackBox (whichWindow, theEvent->where, thePart))
        return;
    p.h = r.right - r.left;
    p.v = r.bottom - r.top - 2 * gui.border_offset;
    if (gui.which_scrollbars[SBAR_BOTTOM])
        p.v -= gui.scrollbar_height;
    p.v -= p.v % gui.char_height;
    p.v += 2 * gui.border_width;
    if (gui.which_scrollbars[SBAR_BOTTOM])
        p.v += gui.scrollbar_height;
    ZoomWindowIdeal (whichWindow, thePart, & p);
    GetWindowBounds (whichWindow, kWindowContentRgn, & r);
    gui_resize_shell (r.right - r.left, r.bottom - r.top);
    gui_mch_set_bg_color (gui.back_pixel);
    gui_set_shellsize (TRUE, FALSE, RESIZE_BOTH);
}

void gui_mac_doKeyEvent (EventRecord *theEvent) {
    long  menu;
    unsigned  char string [20];
    short  num, i;
    short  len = 0;
    KeySym key_sym;
    int key_char;
    int modifiers;
    int simplify = FALSE;
    if (p_mh)
        ObscureCursor ();
    key_sym = ((theEvent->message & keyCodeMask) >> 8);
    key_char = theEvent->message & charCodeMask;
    num = 1;
    if (theEvent->modifiers & controlKey) {
        if (key_char == Ctrl_C && ctrl_c_interrupts)
            got_int = TRUE;
        else if ((theEvent->modifiers & ~(controlKey | shiftKey)) == 0 && (key_char == '2' || key_char == '6')) {
            if (key_char == '2')
                key_char = Ctrl_AT;
            else
                key_char = Ctrl_HAT;
            theEvent->modifiers = 0;
        }
    }
    if (theEvent->modifiers & cmdKey)
        if (key_char == '.')
            got_int = TRUE;
    if (theEvent->modifiers & cmdKey)
        if ((theEvent->modifiers & (~(cmdKey | btnState | alphaLock))) == 0) {
            menu = MenuKey (key_char);
            if (HiWord (menu)) {
                gui_mac_handle_menu (menu);
                return;
            }
        }
    modifiers = EventModifiers2VimModifiers (theEvent->modifiers);
    {
        if ((key_char < 0x20) || (key_char == 0x7f))
            for (i = 0; special_keys[i].key_sym != (KeySym) 0; i++)
                if (special_keys[i].key_sym == key_sym) {
                    key_char = TO_SPECIAL (special_keys[i].vim_code0, special_keys[i].vim_code1);
                    simplify = TRUE;
                    break;
                }
    }
    if (simplify || key_char == TAB || key_char == ' ')
        key_char = simplify_key (key_char, &modifiers);
    if (!IS_SPECIAL (key_char) && key_sym != vk_Space && key_sym != vk_Tab && key_sym != vk_Return && key_sym != vk_Enter && key_sym != vk_Esc) {
        if (modifiers & MOD_MASK_CTRL)
            modifiers = modifiers & ~MOD_MASK_CTRL;
        if (modifiers & MOD_MASK_ALT)
            modifiers = modifiers & ~MOD_MASK_ALT;
        if (modifiers & MOD_MASK_SHIFT)
            modifiers = modifiers & ~MOD_MASK_SHIFT;
    }
    if (modifiers) {
        string[len++] = CSI;
        string[len++] = KS_MODIFIER;
        string[len++] = modifiers;
    }
    if (IS_SPECIAL (key_char)) {
        string[len++] = CSI;
        string[len++] = K_SECOND (key_char);
        string[len++] = K_THIRD (key_char);
    }
    else {
        string[len++] = key_char;
    }
    if (len == 1 && string[0] == CSI) {
        string[len++] = KS_EXTRA;
        string[len++] = KE_CSI;
    }
    add_to_input_buf (string, len);
}

void gui_mac_doMouseUpEvent (EventRecord *theEvent) {
    Point thePoint;
    int_u vimModifiers;
    lastMouseTick = theEvent->when;
    dragRectEnbl = FALSE;
    dragRectControl = kCreateEmpty;
    thePoint = theEvent->where;
    GlobalToLocal (& thePoint);
    vimModifiers = EventModifiers2VimMouseModifiers (theEvent->modifiers);
    if (clickIsPopup) {
        vimModifiers &= ~MOUSE_CTRL;
        clickIsPopup = FALSE;
    }
    gui_send_mouse_event (MOUSE_RELEASE, thePoint.h, thePoint.v, FALSE, vimModifiers);
}

void gui_mac_doUpdateEvent (EventRecord *event) {
    WindowPtr whichWindow;
    GrafPtr savePort;
    RgnHandle updateRgn;
    Rect updateRect;
    Rect *updateRectPtr;
    Rect rc;
    Rect growRect;
    RgnHandle saveRgn;
    updateRgn = NewRgn ();
    if (updateRgn == NULL)
        return;
    whichWindow = (WindowPtr) event->message;
    GetPort (& savePort);
    SetPortWindowPort (whichWindow);
    BeginUpdate (whichWindow);
    GetPortVisibleRegion (GetWindowPort (whichWindow), updateRgn);
    HLock ((Handle) updateRgn);
    updateRectPtr = GetRegionBounds (updateRgn, &updateRect);
    gui_redraw (updateRectPtr -> left, updateRectPtr -> top, updateRectPtr -> right - updateRectPtr -> left, updateRectPtr -> bottom - updateRectPtr -> top);
    gui_mch_set_bg_color (gui.back_pixel);
    if (updateRectPtr->left < FILL_X (0)) {
        SetRect (& rc, 0, 0, FILL_X (0), FILL_Y (Rows));
        EraseRect (& rc);
    }
    if (updateRectPtr->top < FILL_Y (0)) {
        SetRect (& rc, 0, 0, FILL_X (Columns), FILL_Y (0));
        EraseRect (& rc);
    }
    if (updateRectPtr->right > FILL_X (Columns)) {
        SetRect (& rc, FILL_X (Columns), 0, FILL_X (Columns) + gui.border_offset, FILL_Y (Rows));
        EraseRect (& rc);
    }
    if (updateRectPtr->bottom > FILL_Y (Rows)) {
        SetRect (& rc, 0, FILL_Y (Rows), FILL_X (Columns) + gui.border_offset, FILL_Y (Rows) + gui.border_offset);
        EraseRect (& rc);
    }
    HUnlock ((Handle) updateRgn);
    DisposeRgn (updateRgn);
    DrawControls (whichWindow);
    saveRgn = NewRgn ();
    GetWindowBounds (whichWindow, kWindowGrowRgn, & growRect);
    GetClip (saveRgn);
    ClipRect (& growRect);
    DrawGrowIcon (whichWindow);
    SetClip (saveRgn);
    DisposeRgn (saveRgn);
    EndUpdate (whichWindow);
    SetPort (savePort);
}

void gui_mac_doActivateEvent (EventRecord *event) {
    WindowPtr whichWindow;
    whichWindow = (WindowPtr) event->message;
    if (whichWindow == gui.VimWindow) {
        ControlRef rootControl;
        GetRootControl (gui.VimWindow, & rootControl);
        if ((event->modifiers) & activeFlag)
            ActivateControl (rootControl);
        else
            DeactivateControl (rootControl);
    }
    gui_focus_change ((event -> modifiers) & activeFlag);
}

void gui_mac_doMouseMovedEvent (EventRecord *event) {
    Point thePoint;
    int_u vimModifiers;
    thePoint = event->where;
    GlobalToLocal (& thePoint);
    vimModifiers = EventModifiers2VimMouseModifiers (event->modifiers);
    if (!Button ())
        gui_mouse_moved (thePoint.h, thePoint.v);
    else if (!clickIsPopup)
        gui_send_mouse_event (MOUSE_DRAG, thePoint.h, thePoint.v, FALSE, vimModifiers);
    SetRect (& dragRect, FILL_X (X_2_COL (thePoint.h)), FILL_Y (Y_2_ROW (thePoint.v)), FILL_X (X_2_COL (thePoint.h) + 1), FILL_Y (Y_2_ROW (thePoint.v) + 1));
    if (dragRectEnbl)
        dragRectControl = kCreateRect;
}

void gui_mac_doSuspendEvent (EventRecord *event) {
    if (event->message & 1)
        gui_focus_change (TRUE);
    else
        gui_focus_change (FALSE);
}

char_u *gui_mch_get_fontname (GuiFont font, char_u *name) {
    if (name == NULL)
        return NULL;
    return vim_strsave (name);
}

