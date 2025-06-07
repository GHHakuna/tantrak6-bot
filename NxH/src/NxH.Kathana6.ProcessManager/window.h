#pragma once
#include <windows.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300

extern HWND wnd;
extern HDC hdc;
extern struct nk_context* ctx;
extern struct GdiFont* font;

bool init_window(HINSTANCE hInstance);
