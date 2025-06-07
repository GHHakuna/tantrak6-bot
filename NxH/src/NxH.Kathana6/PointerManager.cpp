#include <vcclr.h> 
#include <Psapi.h> 
#include "PointerManager.h"
#pragma comment(lib, "Psapi.lib")

PointerManager::PointerManager() {
    pointers = gcnew Dictionary<String^, PointerInfo^>();
}

DWORD PointerManager::GetModuleBaseAddress(String^ moduleName) {
    pin_ptr<const wchar_t> wname = PtrToStringChars(moduleName);
    HMODULE hModule = GetModuleHandleW(wname);
    return (DWORD)hModule;
}

DWORD PointerManager::ResolveAddress(DWORD baseAddr, array<DWORD>^ offsets) {
    DWORD addr = baseAddr;
    for each (DWORD offset in offsets) {
        addr = *(DWORD*)addr;
        if (addr == 0) break;
        addr += offset;
    }
    return addr;
}

void PointerManager::AddPointer(String^ name, String^ moduleName, DWORD baseOffset, array<DWORD>^ offsets) {
    PointerInfo^ info = gcnew PointerInfo();
    info->moduleName = moduleName;
    info->baseOffset = baseOffset;
    info->offsets = offsets;
    pointers[name] = info;
}

int PointerManager::ReadInt(String^ name) {
    if (!pointers->ContainsKey(name)) return 0;
    auto info = pointers[name];
    DWORD base = GetModuleBaseAddress(info->moduleName);
    if (!base) return 0;
    DWORD addr = ResolveAddress(base + info->baseOffset, info->offsets);
    return *(int*)addr;
}

float PointerManager::ReadFloat(String^ name) {
    if (!pointers->ContainsKey(name)) return 0;
    auto info = pointers[name];
    DWORD base = GetModuleBaseAddress(info->moduleName);
    if (!base) return 0;
    DWORD addr = ResolveAddress(base + info->baseOffset, info->offsets);
    return *(float*)addr;
}

bool PointerManager::ReadBool(String^ name) {
    if (!pointers->ContainsKey(name)) return false;
    auto info = pointers[name];
    DWORD base = GetModuleBaseAddress(info->moduleName);
    if (!base) return false;
    DWORD addr = ResolveAddress(base + info->baseOffset, info->offsets);
    return *(bool*)addr;
}

void PointerManager::WriteInt(String^ name, int value) {
    if (!pointers->ContainsKey(name)) return;
    auto info = pointers[name];
    DWORD base = GetModuleBaseAddress(info->moduleName);
    if (!base) return;
    DWORD addr = ResolveAddress(base + info->baseOffset, info->offsets);
    *(int*)addr = value;
}

void PointerManager::WriteFloat(String^ name, float value) {
    if (!pointers->ContainsKey(name)) return;
    auto info = pointers[name];
    DWORD base = GetModuleBaseAddress(info->moduleName);
    if (!base) return;
    DWORD addr = ResolveAddress(base + info->baseOffset, info->offsets);
    *(float*)addr = value;
}

void PointerManager::WriteBool(String^ name, bool value) {
    if (!pointers->ContainsKey(name)) return;
    auto info = pointers[name];
    DWORD base = GetModuleBaseAddress(info->moduleName);
    if (!base) return;
    DWORD addr = ResolveAddress(base + info->baseOffset, info->offsets);
    *(bool*)addr = value;
}

bool PointerManager::FindAndPatchBytes(String^ moduleName, array<Byte>^ pattern, array<Byte>^ replace, int offset)
{
    // Convertir nombre de módulo a LPCWSTR
    IntPtr ptrToModuleName = System::Runtime::InteropServices::Marshal::StringToHGlobalUni(moduleName);
    LPCWSTR modName = (LPCWSTR)ptrToModuleName.ToPointer();

    // Obtener el módulo base
    HMODULE hModule = GetModuleHandle(modName);
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToModuleName);

    if (!hModule) return false;

    BYTE* baseAddress = reinterpret_cast<BYTE*>(hModule);


    const SIZE_T scanSize = 0x100000;

    for (SIZE_T i = 0; i < scanSize - pattern->Length; ++i)
    {
        bool match = true;
        for (int j = 0; j < pattern->Length; ++j)
        {
            BYTE expected = pattern[j];
            if (expected != 0xCC && baseAddress[i + j] != expected)
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            for (int k = 0; k < replace->Length; ++k)
            {
                baseAddress[i + offset + k] = replace[k];
            }

            return true;
        }
    }

    return false;
}