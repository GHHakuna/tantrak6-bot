#include "nuklear.h"
#include "nuklear_gdi.h"
#include "window.h"
#include "ui.h"
#include "blur.h"
#include "style.h"
    GdiFont* font;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    if (!init_window(hInstance)) return -1;

    font = nk_gdifont_create("Segoe UI", 14);

    //apply_blur_effect(wnd);
    ctx = nk_gdi_init(font, hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
    apply_ui_style(ctx);

    MSG msg;
    int running = 1;

    while (running) {
        nk_input_begin(ctx);
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                running = 0;
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            //nk_input_begin(ctx);
            nk_gdi_handle_event(msg.hwnd, msg.message, msg.wParam, msg.lParam);
            //nk_input_end(ctx);
        }

        nk_input_end(ctx);

        render_ui(ctx, &running);

        HDC hdcPaint = GetDC(wnd);
        RECT cabecera = { 0, 0, WINDOW_WIDTH, 40 };
        HBRUSH brush = CreateSolidBrush(RGB(167, 49, 70)); // Color oscuro opaco

        SetBkMode(hdcPaint, TRANSPARENT);
        SetTextColor(hdcPaint, RGB(255, 255, 255)); // Blanco

        HFONT hFont = CreateFontW(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
            L"Segoe UI");
        HFONT oldFont = (HFONT)SelectObject(hdcPaint, hFont);

        RECT textRect = cabecera;
        DrawTextW(hdcPaint, L"Tantra Kathana 6", -1, &textRect,
            DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS);

        SelectObject(hdcPaint, oldFont);
        DeleteObject(hFont);


        ReleaseDC(wnd, hdcPaint);
        FillRect(hdcPaint, &cabecera, brush);
        DeleteObject(brush);
        ReleaseDC(wnd, hdcPaint);


        InvalidateRect(wnd, NULL, FALSE);
        UpdateWindow(wnd);
        nk_gdi_render(nk_rgb(30, 30, 30));
    }

    nk_gdi_shutdown();
    nk_gdifont_del(font);
    ReleaseDC(wnd, hdc);
    DestroyWindow(wnd);
    return 0;
}
