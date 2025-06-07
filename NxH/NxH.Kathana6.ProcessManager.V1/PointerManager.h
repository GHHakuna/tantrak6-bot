#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <map>

struct PointerInfo {
    DWORD moduleBaseAddress;
    DWORD baseOffset;
    std::vector<DWORD> offsets;
};

class PointerManager {
public:
    PointerManager();
    bool AttachToProcess(DWORD pid);
    DWORD GetModuleBaseAddress(const std::wstring& moduleName);
    DWORD ResolveAddress(DWORD baseAddr, const std::vector<DWORD>& offsets);
    void AddPointer(const std::wstring& name, const std::wstring& moduleName, DWORD baseOffset, const std::vector<DWORD>& offsets);
    int ReadInt(const std::wstring& name);
    float ReadFloat(const std::wstring& name);
    bool ReadBool(const std::wstring& name);
    void WriteInt(const std::wstring& name, int value);
    void WriteFloat(const std::wstring& name, float value);
    void WriteBool(const std::wstring& name, bool value);

private:
    HANDLE hProcess;
    std::map<std::wstring, PointerInfo> pointers;
};

