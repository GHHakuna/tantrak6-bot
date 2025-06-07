#pragma once
#include "nuklear/nuklear.h"

static void style_retro(struct nk_context* ctx) {
    struct nk_color table[NK_COLOR_COUNT];
    table[NK_COLOR_TEXT] = nk_rgb(255, 255, 255);
    table[NK_COLOR_WINDOW] = nk_rgb(40, 40, 40);
    table[NK_COLOR_HEADER] = nk_rgb(50, 50, 50);
    table[NK_COLOR_BORDER] = nk_rgb(60, 60, 60);
    table[NK_COLOR_BUTTON] = nk_rgb(70, 70, 70);
    table[NK_COLOR_BUTTON_HOVER] = nk_rgb(90, 90, 90);
    table[NK_COLOR_BUTTON_ACTIVE] = nk_rgb(110, 110, 110);
    table[NK_COLOR_TOGGLE] = nk_rgb(70, 70, 70);
    table[NK_COLOR_TOGGLE_HOVER] = nk_rgb(90, 90, 90);
    table[NK_COLOR_TOGGLE_CURSOR] = nk_rgb(255, 0, 0);
    table[NK_COLOR_SELECT] = nk_rgb(70, 70, 70);
    table[NK_COLOR_SELECT_ACTIVE] = nk_rgb(255, 0, 0);
    table[NK_COLOR_SLIDER] = nk_rgb(70, 70, 70);
    table[NK_COLOR_SLIDER_CURSOR] = nk_rgb(255, 0, 0);
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgb(255, 50, 50);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgb(255, 100, 100);
    table[NK_COLOR_PROPERTY] = nk_rgb(70, 70, 70);
    table[NK_COLOR_EDIT] = nk_rgb(70, 70, 70);
    table[NK_COLOR_EDIT_CURSOR] = nk_rgb(255, 255, 255);
    table[NK_COLOR_COMBO] = nk_rgb(70, 70, 70);
    table[NK_COLOR_CHART] = nk_rgb(70, 70, 70);
    table[NK_COLOR_CHART_COLOR] = nk_rgb(255, 0, 0);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgb(255, 255, 0);
    table[NK_COLOR_SCROLLBAR] = nk_rgb(60, 60, 60);
    table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgb(80, 80, 80);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgb(100, 100, 100);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgb(120, 120, 120);
    table[NK_COLOR_TAB_HEADER] = nk_rgb(60, 60, 60);
    nk_style_from_table(ctx, table);
}
