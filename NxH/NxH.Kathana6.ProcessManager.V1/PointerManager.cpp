#include "PointerManager.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

PointerManager::PointerManager() {
	hProcess = nullptr;
}

bool PointerManager::AttachToProcess(DWORD pid) {
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	return hProcess != nullptr;
}

DWORD PointerManager::GetModuleBaseAddress(const std::wstring& moduleName) {
	DWORD moduleBase = 0;

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, GetProcessId(hProcess));
	if (hSnap == INVALID_HANDLE_VALUE) return 0;

	MODULEENTRY32W modEntry = { 0 };  // Usa la versión "W" (wide/Unicode)
	modEntry.dwSize = sizeof(modEntry);

	if (Module32FirstW(hSnap, &modEntry)) {
		do {
			if (moduleName == modEntry.szModule) {
				moduleBase = (DWORD)(uintptr_t)modEntry.modBaseAddr;
				break;
			}
		} while (Module32NextW(hSnap, &modEntry));
	}

	CloseHandle(hSnap);
	return moduleBase;
}

DWORD PointerManager::ResolveAddress(DWORD baseAddr, const std::vector<DWORD>& offsets) {
	DWORD addr = baseAddr;
	for (DWORD offset : offsets) {
		SIZE_T bytesRead = 0;
		if (!ReadProcessMemory(hProcess, (LPCVOID)addr, &addr, sizeof(addr), &bytesRead) || bytesRead != sizeof(addr)) {
			return 0;
		}
		addr += offset;
	}
	return addr;
}

void PointerManager::AddPointer(const std::wstring& name, const std::wstring& moduleName, DWORD baseOffset, const std::vector<DWORD>& offsets) {
	DWORD moduleBase = GetModuleBaseAddress(moduleName);
	if (moduleBase == 0) return; // Falla si no se encuentra

	pointers[name] = { moduleBase, baseOffset, offsets };
}


int PointerManager::ReadInt(const std::wstring& name) {
	if (pointers.find(name) == pointers.end()) return 0;
	const auto& info = pointers[name];
	if (!info.moduleBaseAddress) return 0;
	DWORD addr = ResolveAddress(info.moduleBaseAddress + info.baseOffset, info.offsets);
	int value = 0;
	SIZE_T bytesRead = 0;
	ReadProcessMemory(hProcess, (LPCVOID)addr, &value, sizeof(value), &bytesRead);
	return value;
}

float PointerManager::ReadFloat(const std::wstring& name) {
	if (pointers.find(name) == pointers.end()) return 0;
	const auto& info = pointers[name];
	if (!info.moduleBaseAddress) return 0;
	DWORD addr = ResolveAddress(info.moduleBaseAddress + info.baseOffset, info.offsets);
	float value = 0;
	SIZE_T bytesRead = 0;
	ReadProcessMemory(hProcess, (LPCVOID)addr, &value, sizeof(value), &bytesRead);
	return value;
}

bool PointerManager::ReadBool(const std::wstring& name) {
	if (pointers.find(name) == pointers.end()) return false;
	const auto& info = pointers[name];
	if (!info.moduleBaseAddress) return false;
	DWORD addr = ResolveAddress(info.moduleBaseAddress + info.baseOffset, info.offsets);
	bool value = false;
	SIZE_T bytesRead = 0;
	ReadProcessMemory(hProcess, (LPCVOID)addr, &value, sizeof(value), &bytesRead);
	return value;
}

void PointerManager::WriteInt(const std::wstring& name, int value) {
	if (pointers.find(name) == pointers.end()) return;
	const auto& info = pointers[name];
	if (!info.moduleBaseAddress) return;
	DWORD addr = ResolveAddress(info.moduleBaseAddress + info.baseOffset, info.offsets);
	SIZE_T bytesWritten = 0;
	WriteProcessMemory(hProcess, (LPVOID)addr, &value, sizeof(value), &bytesWritten);
}

void PointerManager::WriteFloat(const std::wstring& name, float value) {
	if (pointers.find(name) == pointers.end()) return;
	const auto& info = pointers[name];
	if (!info.moduleBaseAddress) return;
	DWORD addr = ResolveAddress(info.moduleBaseAddress + info.baseOffset, info.offsets);
	SIZE_T bytesWritten = 0;
	WriteProcessMemory(hProcess, (LPVOID)addr, &value, sizeof(value), &bytesWritten);
}

void PointerManager::WriteBool(const std::wstring& name, bool value) {
	if (pointers.find(name) == pointers.end()) return;
	const auto& info = pointers[name];
	if (!info.moduleBaseAddress) return;
	DWORD addr = ResolveAddress(info.moduleBaseAddress + info.baseOffset, info.offsets);
	SIZE_T bytesWritten = 0;
	WriteProcessMemory(hProcess, (LPVOID)addr, &value, sizeof(value), &bytesWritten);
}
