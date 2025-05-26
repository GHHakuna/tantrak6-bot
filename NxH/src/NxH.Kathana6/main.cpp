#include <Windows.h>
extern void ShowMenuView();

DWORD WINAPI MainThread(HMODULE hModule) {
    // Aquí inicializas el formulario
    ShowMenuView();
        
    // Liberar DLL (opcional)
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);
    }
    return TRUE;
}