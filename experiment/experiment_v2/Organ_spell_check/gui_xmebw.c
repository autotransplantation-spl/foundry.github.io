static void free_pixmaps (XmEnhancedButtonWidget eb) {
    Pixmap norm_pix = eb->enhancedbutton.normal_pixmap;
    Pixmap arm_pix = eb->enhancedbutton.armed_pixmap;
    Pixmap insen_pix = eb->enhancedbutton.insensitive_pixmap;
    Pixmap high_pix = eb->enhancedbutton.highlight_pixmap;
    if (norm_pix != None && norm_pix != XmUNSPECIFIED_PIXMAP)
        XFreePixmap (XtDisplay (eb), norm_pix);
    if (arm_pix != None && arm_pix != XmUNSPECIFIED_PIXMAP)
        XFreePixmap (XtDisplay (eb), arm_pix);
    if (insen_pix != None && insen_pix != XmUNSPECIFIED_PIXMAP)
        XFreePixmap (XtDisplay (eb), insen_pix);
    if (high_pix != None && high_pix != XmUNSPECIFIED_PIXMAP)
        XFreePixmap (XtDisplay (eb), high_pix);
}

static void set_pixmap (XmEnhancedButtonWidget eb) {
    XPMATTRIBUTES_TYPE attr;
    Pixmap sen_pix;
    Window root;
    static XpmColorSymbol color [8] = {{"none", "none", 0}, {"None", "none", 0}, {"background", NULL, 0}, {"foreground", NULL, 0}, {"bottomShadowColor", NULL, 0}, {"topShadowColor", NULL, 0}, {"highlightColor", NULL, 0}, {"armColor", NULL, 0}};
    int scr;
    Display *dpy = XtDisplay (eb);
    int x;
    int y;
    unsigned  int height, width, border, depth;
    int status = 0;
    Pixmap mask;
    Pixmap pix = None;
    Pixmap arm_pix = None;
    Pixmap ins_pix = None;
    Pixmap high_pix = None;
    char **data = (char **) eb->enhancedbutton.pixmap_data;
    char *fname = (char *) eb->enhancedbutton.pixmap_file;
    int shift;
    GC gc;
    if (!data)
        return;
    gc = XtGetGC ((Widget) eb, (XtGCMask) 0, NULL);
    scr = DefaultScreen (dpy);
    root = RootWindow (dpy, scr);
    eb->label.pixmap = None;
    eb->enhancedbutton.pixmap_depth = 0;
    eb->enhancedbutton.pixmap_width = 0;
    eb->enhancedbutton.pixmap_height = 0;
    eb->enhancedbutton.normal_pixmap = None;
    eb->enhancedbutton.armed_pixmap = None;
    eb->enhancedbutton.highlight_pixmap = None;
    eb->enhancedbutton.insensitive_pixmap = None;
    motif_get_toolbar_colors (& eb -> core.background_pixel, & eb -> primitive.foreground, & eb -> primitive.bottom_shadow_color, & eb -> primitive.top_shadow_color, & eb -> primitive.highlight_color);
    color[0].pixel = eb->core.background_pixel;
    color[1].pixel = eb->core.background_pixel;
    color[2].pixel = eb->core.background_pixel;
    color[3].pixel = eb->primitive.foreground;
    color[4].pixel = eb->core.background_pixel;
    color[5].pixel = eb->primitive.top_shadow_color;
    color[6].pixel = eb->primitive.highlight_color;
    color[7].pixel = eb->pushbutton.arm_color;
    attr.valuemask = XpmColorSymbols | XpmCloseness;
    attr.closeness = 65535;
    attr.colorsymbols = color;
    attr.numsymbols = XtNumber (color);
    if (fname)
        status = XpmReadFileToPixmap (dpy, root, fname, &pix, &mask, &attr);
    if (!fname || status != XpmSuccess)
        status = XpmCreatePixmapFromData (dpy, root, data, &pix, &mask, &attr);
    if (status != XpmSuccess)
        status = XpmCreatePixmapFromData (dpy, root, blank_xpm, &pix, &mask, &attr);
    XpmFreeAttributes (& attr);
    XGetGeometry (dpy, pix, & root, & x, & y, & width, & height, & border, & depth);
    shift = eb->primitive.shadow_thickness / 2;
    if (shift < 1)
        shift = 1;
    sen_pix = XCreatePixmap (dpy, root, width +shift, height +shift, depth);
    XSetForeground (dpy, gc, eb -> core.background_pixel);
    XFillRectangle (dpy, sen_pix, gc, 0, 0, width + shift, height + shift);
    XSetClipMask (dpy, gc, mask);
    XSetClipOrigin (dpy, gc, shift, shift);
    XCopyArea (dpy, pix, sen_pix, gc, 0, 0, width, height, shift, shift);
    color[4].pixel = eb->primitive.bottom_shadow_color;
    attr.valuemask = XpmColorSymbols | XpmCloseness;
    attr.closeness = 65535;
    attr.colorsymbols = color;
    attr.numsymbols = XtNumber (color);
    status = XpmCreatePixmapFromData (dpy, root, data, &pix, NULL, &attr);
    XpmFreeAttributes (& attr);
    high_pix = XCreatePixmap (dpy, root, width +shift, height +shift, depth);
    XSetForeground (dpy, gc, eb -> primitive.top_shadow_color);
    XSetClipMask (dpy, gc, None);
    XFillRectangle (dpy, high_pix, gc, 0, 0, width + shift, height + shift);
    XSetClipMask (dpy, gc, mask);
    XSetClipOrigin (dpy, gc, 0, 0);
    XCopyArea (dpy, pix, high_pix, gc, 0, 0, width, height, 0, 0);
    arm_pix = XCreatePixmap (dpy, pix, width +shift, height +shift, depth);
    if (eb->pushbutton.fill_on_arm)
        XSetForeground (dpy, gc, eb->pushbutton.arm_color);
    else
        XSetForeground (dpy, gc, eb->core.background_pixel);
    XSetClipOrigin (dpy, gc, shift, shift);
    XSetClipMask (dpy, gc, None);
    XFillRectangle (dpy, arm_pix, gc, 0, 0, width + shift, height + shift);
    XSetClipMask (dpy, gc, mask);
    XSetClipOrigin (dpy, gc, 2 * shift, 2 * shift);
    XCopyArea (dpy, pix, arm_pix, gc, 0, 0, width, height, 2 * shift, 2 * shift);
    XFreePixmap (dpy, pix);
    XFreePixmap (dpy, mask);
    attr.valuemask = XpmColorSymbols | XpmCloseness | XpmColorKey;
    attr.closeness = 65535;
    attr.colorsymbols = color;
    attr.numsymbols = sizeof (color) / sizeof (color[0]);
    attr.color_key = XPM_MONO;
    status = XpmCreatePixmapFromData (dpy, root, data, &pix, &mask, &attr);
    ins_pix = XCreatePixmap (dpy, root, width +shift, height +shift, depth);
    XSetForeground (dpy, gc, eb -> core.background_pixel);
    XSetClipOrigin (dpy, gc, 0, 0);
    XSetClipMask (dpy, gc, None);
    XFillRectangle (dpy, ins_pix, gc, 0, 0, width + shift, height + shift);
    XSetClipMask (dpy, gc, mask);
    XSetForeground (dpy, gc, eb -> primitive.top_shadow_color);
    XSetClipOrigin (dpy, gc, 2 * shift, 2 * shift);
    XFillRectangle (dpy, ins_pix, gc, 2 * shift, 2 * shift, width, height);
    XSetForeground (dpy, gc, eb -> primitive.bottom_shadow_color);
    XSetClipOrigin (dpy, gc, shift, shift);
    XFillRectangle (dpy, ins_pix, gc, 0, 0, width + shift, height + shift);
    XtReleaseGC ((Widget) eb, gc);
    XpmFreeAttributes (& attr);
    eb->enhancedbutton.pixmap_depth = depth;
    eb->enhancedbutton.pixmap_width = width;
    eb->enhancedbutton.pixmap_height = height;
    eb->enhancedbutton.normal_pixmap = sen_pix;
    eb->enhancedbutton.highlight_pixmap = high_pix;
    eb->enhancedbutton.insensitive_pixmap = ins_pix;
    eb->enhancedbutton.armed_pixmap = arm_pix;
    eb->enhancedbutton.doing_setvalues = True;
    eb->enhancedbutton.doing_setvalues = False;
    XFreePixmap (dpy, pix);
    XFreePixmap (dpy, mask);
}

#define	BUTTON_MASK ( \
	Button1Mask | Button2Mask | Button3Mask | Button4Mask | Button5Mask \
)

static int alloc_color (Display *display, Colormap colormap, char *colorname, XColor *xcolor, void *closure) {
    int status;
    if (colorname)
        if (!XParseColor (display, colormap, colorname, xcolor))
            return -1;
    xcolor->red = bump_color (xcolor->red);
    xcolor->green = bump_color (xcolor->green);
    xcolor->blue = bump_color (xcolor->blue);
    status = XAllocColor (display, colormap, xcolor);
    return status != 0 ? 1 : 0;
}

static unsigned  short  bump_color (unsigned  short  value) {
    int tmp = 2 * (((int) value - 65535) / 3) + 65535;
    return tmp;
}

static void set_size (XmEnhancedButtonWidget newtb) {
    unsigned  int w = 0;
    unsigned  int h = 0;
    _XmCalcLabelDimensions ((Widget) newtb);
    if (newtb->enhancedbutton.pixmap_data && !IsNull (newtb->label.pixmap) && !IsNull (newtb->enhancedbutton.normal_pixmap)) {
        w = newtb->enhancedbutton.pixmap_width;
        h = newtb->enhancedbutton.pixmap_height;
    }
    if (Lab_IsMenupane (newtb)) {
        newtb->label.margin_left = w + 2 * (newtb->primitive.shadow_thickness + newtb->primitive.highlight_thickness) + newtb->label.margin_width;
    }
    else {
        newtb->label.margin_left = w;
        newtb->core.width = w + 2 * (newtb->primitive.shadow_thickness + newtb->primitive.highlight_thickness + newtb->label.margin_width) + newtb->label.TextRect.width;
        if (newtb->label.TextRect.width > 0) {
            newtb->label.margin_left += newtb->label.margin_width + newtb->primitive.shadow_thickness;
            newtb->core.width += newtb->label.margin_width + newtb->primitive.shadow_thickness;
        }
    }
    if (newtb->label.TextRect.height < h) {
        newtb->core.height = h + 2 * (newtb->primitive.shadow_thickness + newtb->primitive.highlight_thickness + newtb->label.margin_height);
    }
    else {
    }
    {
        XtWidgetProc resize;
        XtProcessLock ();
        resize = xmLabelClassRec.core_class.resize;
        XtProcessUnlock ();
        (*resize) ((Widget) newtb);
    }
}

static void draw_label (XmEnhancedButtonWidget eb, XEvent *event, Region region) {
    GC tmp_gc = NULL;
    Boolean replaceGC = False;
    Boolean deadjusted = False;
    Boolean etched_in = False;
    if (eb->pushbutton.armed && ((!Lab_IsMenupane (eb) && eb->pushbutton.fill_on_arm) || (Lab_IsMenupane (eb) && etched_in))) {
        if (eb->label.label_type == (int) XmSTRING && eb->pushbutton.arm_color == eb->primitive.foreground) {
            tmp_gc = eb->label.normal_GC;
            eb->label.normal_GC = eb->pushbutton.background_gc;
            replaceGC = True;
        }
    }
    if (eb->label.label_type == (int) XmPIXMAP) {
        if (eb->pushbutton.armed) {
            if (eb->pushbutton.arm_pixmap != XmUNSPECIFIED_PIXMAP)
                eb->label.pixmap = eb->pushbutton.arm_pixmap;
            else
                eb->label.pixmap = eb->pushbutton.unarm_pixmap;
        }
        else
            eb->label.pixmap = eb->pushbutton.unarm_pixmap;
    }
    if (eb->pushbutton.default_button_shadow_thickness > 0) {
        deadjusted = True;
        Lab_MarginLeft (eb) -= Xm3D_ENHANCE_PIXEL;
        Lab_MarginRight (eb) -= Xm3D_ENHANCE_PIXEL;
        Lab_MarginTop (eb) -= Xm3D_ENHANCE_PIXEL;
        Lab_MarginBottom (eb) -= Xm3D_ENHANCE_PIXEL;
    }
    {
        XtExposeProc expose;
        XtProcessLock ();
        expose = xmLabelClassRec.core_class.expose;
        XtProcessUnlock ();
        (*expose) ((Widget) eb, event, region);
    }
    if (deadjusted) {
        Lab_MarginLeft (eb) += Xm3D_ENHANCE_PIXEL;
        Lab_MarginRight (eb) += Xm3D_ENHANCE_PIXEL;
        Lab_MarginTop (eb) += Xm3D_ENHANCE_PIXEL;
        Lab_MarginBottom (eb) += Xm3D_ENHANCE_PIXEL;
    }
    if (replaceGC)
        eb->label.normal_GC = tmp_gc;
}

static void draw_pixmap (XmEnhancedButtonWidget eb, XEvent *event, Region region) {
    Pixmap pix;
    GC gc = eb->label.normal_GC;
    int depth;
    Cardinal width;
    Cardinal height;
    Cardinal w;
    Cardinal h;
    int x;
    int y;
    if (!XtIsSensitive ((Widget) eb))
        pix = eb->enhancedbutton.insensitive_pixmap;
    else {
        if (eb->primitive.highlighted && !eb->pushbutton.armed)
            pix = eb->enhancedbutton.highlight_pixmap;
        else if (eb->pushbutton.armed)
            pix = eb->enhancedbutton.armed_pixmap;
        else
            pix = eb->enhancedbutton.normal_pixmap;
    }
    if (pix == None || !eb->enhancedbutton.pixmap_data)
        return;
    depth = eb->enhancedbutton.pixmap_depth;
    w = eb->enhancedbutton.pixmap_width;
    h = eb->enhancedbutton.pixmap_height;
    gc = eb->label.normal_GC;
    x = eb->primitive.highlight_thickness + eb->primitive.shadow_thickness + eb->label.margin_width;
    y = eb->primitive.highlight_thickness + eb->primitive.shadow_thickness + eb->label.margin_height;
    width = eb->core.width - 2 * x;
    if (w < width)
        width = w;
    height = eb->core.height - 2 * y;
    if (h < height)
        height = h;
    if (depth == (int) eb->core.depth)
        XCopyArea (XtDisplay (eb), pix, XtWindow (eb), gc, 0, 0, width, height, x, y);
    else if (depth == 1)
        XCopyPlane (XtDisplay (eb), pix, XtWindow (eb), gc, 0, 0, width, height, x, y, (unsigned  long ) 1);
}

static void draw_shadows (XmEnhancedButtonWidget eb) {
    GC top_gc;
    GC bottom_gc;
    Boolean etched_in;
    if (!eb->primitive.shadow_thickness)
        return;
    if ((eb->core.width <= 2 * eb->primitive.highlight_thickness) || (eb->core.height <= 2 * eb->primitive.highlight_thickness))
        return;
    etched_in = False;
    if (!etched_in ^ eb->pushbutton.armed) {
        top_gc = eb->primitive.top_shadow_GC;
        bottom_gc = eb->primitive.bottom_shadow_GC;
    }
    else {
        top_gc = eb->primitive.bottom_shadow_GC;
        bottom_gc = eb->primitive.top_shadow_GC;
    }
    XmeDrawShadows (XtDisplay (eb), XtWindow (eb), top_gc, bottom_gc, eb -> primitive.highlight_thickness, eb -> primitive.highlight_thickness, eb -> core.width - 2 * eb -> primitive.highlight_thickness, eb -> core.height - 2 * eb -> primitive.highlight_thickness, eb -> primitive.shadow_thickness, (unsigned) (etched_in ? XmSHADOW_IN : XmSHADOW_OUT));
}

