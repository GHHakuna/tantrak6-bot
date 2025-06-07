#pragma once
#include "PointerManager.h"
#include <string>

class GameMemoryService {
public:
    GameMemoryService();

    bool AttachToProcess(DWORD pid);
    void AddWatch(const std::string& name, const std::string& moduleName, DWORD baseOffset, const std::vector<DWORD>& offsets);

    int ReadInt(const std::string& name);
    float ReadFloat(const std::string& name);
    bool ReadBool(const std::string& name);

    void WriteInt(const std::string& name, int value);
    void WriteFloat(const std::string& name, float value);
    void WriteBool(const std::string& name, bool value);

private:
    PointerManager pointerManager;
};
