#pragma once

#include "PointerManager.h"

public ref class GameMemoryService
{
private:
    PointerManager^ pm;

public:
    GameMemoryService();

    void SetLootBug(bool enabled);    
    int GetHpMax();
    int GetHpCurrent();
    int GetMpMax();
    int GetMpCurrent();
    float GetCoordX();
    float GetCoordY();
    float GetCoordZ();

    void PatchStaticArray(Byte newByte1, Byte newByte2);
};
