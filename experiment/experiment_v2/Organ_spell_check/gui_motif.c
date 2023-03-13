
#include "InterfaceHeader.h"
Widget toolBar;

void motif_get_toolbar_colors (Pixel *bgp, Pixel *fgp, Pixel *bsp, Pixel *tsp, Pixel *hsp) {
    XtVaGetValues (toolBar, XmNbackground, bgp, XmNforeground, fgp, XmNbottomShadowColor, bsp, XmNtopShadowColor, tsp, XmNhighlightColor, hsp, NULL);
}

