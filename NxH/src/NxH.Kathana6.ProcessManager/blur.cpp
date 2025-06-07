#include "blur.h"

typedef struct _ACCENT_POLICY {
    int nAccentState;
    int nFlags;
    int nColor;
    int nAnimationId;
} ACCENT_POLICY;

typedef struct _WINDOWCOMPOSITIONATTRIBDATA {
    int nAttrib;
    PVOID pvData;
    SIZE_T cbData;
} WINDOWCOMPOSITIONATTRIBDATA;

enum AccentState {
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_GRADIENT = 1,
    ACCENT_ENABLE_TRANSPARENTGRADIENT = 2,
    ACCENT_ENABLE_BLURBEHIND = 3,
    ACCENT_ENABLE_ACRYLICBLURBEHIND = 4, // Solo en Windows 10 build 1803+
    ACCENT_ENABLE_HOSTBACKDROP = 5,      // Windows 11+
    ACCENT_ENABLE_INVALID_STATE = 6
};

enum WINDOW_COMPOSITION_ATTRIB {
    WCA_ACCENT_POLICY = 19
};


extern "C" BOOL __stdcall SetWindowCompositionAttribute(HWND, WINDOWCOMPOSITIONATTRIBDATA*);
typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINDOWCOMPOSITIONATTRIBDATA*);

DWORD argb_color_from_opacity(int opacityPercent, BYTE r = 0, BYTE g = 0, BYTE b = 0) {
    if (opacityPercent < 0) opacityPercent = 0;
    if (opacityPercent > 100) opacityPercent = 100;

    BYTE alpha = static_cast<BYTE>((opacityPercent * 255) / 100);
    return (alpha << 24) | (r << 16) | (g << 8) | b;
}

void apply_blur_effect(HWND hwnd) {
    //DWORD color = argb_color_from_opacity(0, 192, 128, 255);
    DWORD color = argb_color_from_opacity(0);
    HMODULE hUser = GetModuleHandleW(L"user32.dll");
    pSetWindowCompositionAttribute SetWindowCompositionAttribute =
        (pSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");

    if (SetWindowCompositionAttribute) {
        ACCENT_POLICY policy = { ACCENT_ENABLE_BLURBEHIND, 0, color, 0 };
        WINDOWCOMPOSITIONATTRIBDATA data = { WCA_ACCENT_POLICY, &policy, sizeof(policy) };
        SetWindowCompositionAttribute(hwnd, &data);
    }
}
