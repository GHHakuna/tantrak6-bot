#pragma once
#include <Windows.h>
using namespace System;
using namespace System::Collections::Generic;

public ref class PointerManager
{
private:
	ref struct PointerInfo {
		String^ moduleName;
		DWORD baseOffset;
		array<DWORD>^ offsets;
	};

	Dictionary<String^, PointerInfo^>^ pointers;

	DWORD GetModuleBaseAddress(String^ moduleName);
	DWORD ResolveAddress(DWORD baseAddr, array<DWORD>^ offsets);

public:
	PointerManager();

	void AddPointer(String^ name, String^ moduleName, DWORD baseOffset, array<DWORD>^ offsets);
	int ReadInt(String^ name);
	float ReadFloat(String^ name);
	bool ReadBool(String^ name);

	void WriteInt(String^ name, int value);
	void WriteFloat(String^ name, float value);
	void WriteBool(String^ name, bool value);
};