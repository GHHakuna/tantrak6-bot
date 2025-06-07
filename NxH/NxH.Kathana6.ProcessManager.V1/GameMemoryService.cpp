#include "GameMemoryService.h"
#include <locale>
#include <codecvt>

GameMemoryService::GameMemoryService() {
    
}

std::wstring ToWString(const std::string& str) {
    if (str.empty()) return std::wstring();

    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    if (size_needed <= 0) return std::wstring();

    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);

    // Elimina el carácter nulo final
    if (!wstr.empty() && wstr.back() == L'\0') {
        wstr.pop_back();
    }

    return wstr;
}

bool GameMemoryService::AttachToProcess(DWORD pid) {
    return pointerManager.AttachToProcess(pid);
}

void GameMemoryService::AddWatch(const std::string& name, const std::string& moduleName, DWORD baseOffset, const std::vector<DWORD>& offsets) {
    pointerManager.AddPointer(ToWString(name), ToWString(moduleName), baseOffset, offsets);
}

int GameMemoryService::ReadInt(const std::string& name) {
    return pointerManager.ReadInt(ToWString(name));
}

float GameMemoryService::ReadFloat(const std::string& name) {
    return pointerManager.ReadFloat(ToWString(name));
}

bool GameMemoryService::ReadBool(const std::string& name) {
    return pointerManager.ReadBool(ToWString(name));
}

void GameMemoryService::WriteInt(const std::string& name, int value) {
    pointerManager.WriteInt(ToWString(name), value);
}

void GameMemoryService::WriteFloat(const std::string& name, float value) {
    pointerManager.WriteFloat(ToWString(name), value);
}

void GameMemoryService::WriteBool(const std::string& name, bool value) {
    pointerManager.WriteBool(ToWString(name), value);
}
