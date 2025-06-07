#include "window.h"
#include "nuklear.h"
#include "nuklear_gdi.h"
#include "blur.h"

HWND wnd;
HDC hdc;
struct nk_context* ctx;


LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static BOOL dragging = FALSE;
    static POINT offset;

    switch (msg) {
    case WM_LBUTTONDOWN:
        dragging = TRUE;
        GetCursorPos(&offset);
        ScreenToClient(hwnd, &offset);
        //SetCapture(hwnd);
        return 0;

    case WM_MOUSEMOVE:
        if (dragging) {
            POINT pos;
            GetCursorPos(&pos);
            //SetWindowPos(hwnd, NULL, pos.x - offset.x, pos.y - offset.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        return 0;

    case WM_LBUTTONUP:
        dragging = FALSE;
        //ReleaseCapture();
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

bool init_window(HINSTANCE hInstance) {
    WNDCLASSW wc = { 0 };
    RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    DWORD style = WS_OVERLAPPEDWINDOW;
    ////DWORD style = WS_POPUP;
    DWORD exstyle = WS_EX_APPWINDOW;
    ////DWORD exstyle = WS_EX_TOOLWINDOW;

    /*DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;
    DWORD exstyle = WS_EX_APPWINDOW;*/

    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"NuklearHUD";
    if (!RegisterClassW(&wc)) return false;

    AdjustWindowRectEx(&rect, style, FALSE, exstyle);

    int x = (GetSystemMetrics(SM_CXSCREEN) - (rect.right - rect.left)) / 2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - (rect.bottom - rect.top)) / 2;

    wnd = CreateWindowExW(exstyle, wc.lpszClassName, L"Tantra Kathana 6",
        style | WS_VISIBLE, x, y,
        //rect.right - rect.left,
        //rect.bottom - rect.top,
        600, 600,
        NULL, NULL, wc.hInstance, NULL);
    
    //apply_blur_effect(wnd);
    //SetWindowPos(wnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    //RedrawWindow(wnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME);

    hdc = GetDC(wnd);

    return true;
}
