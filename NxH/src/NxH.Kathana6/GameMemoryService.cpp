#include "GameMemoryService.h"

GameMemoryService::GameMemoryService() {
    pm = gcnew PointerManager();
    pm->AddPointer("LootBug", "HTLauncher.exe", 0x00A1F6B0, gcnew array<DWORD>{ 0x1D8 });
    pm->AddPointer("NoMP", "HTLauncher.exe", 0x00A1F6B0, gcnew array<DWORD>{ 0x19C });

    pm->AddPointer("HpCurrent", "HTLauncher.exe", 0x00A1F6B0, gcnew array<DWORD>{ 0x114 });
    pm->AddPointer("HpMax", "HTLauncher.exe", 0x00A1F6B0, gcnew array<DWORD>{ 0x110 });
    pm->AddPointer("MpCurrent", "HTLauncher.exe", 0x00A1F7A0, gcnew array<DWORD>{ 0x330 });    
    pm->AddPointer("MpMax", "HTLauncher.exe", 0x00A1F7A0, gcnew array<DWORD>{ 0x32C });
    
    
    pm->AddPointer("CoordX", "HTLauncher.exe", 0x0003272C, gcnew array<DWORD>{ 0xA8 });
    pm->AddPointer("CoordY", "HTLauncher.exe", 0x0003272C, gcnew array<DWORD>{ 0xB0 });
    pm->AddPointer("CoordZ", "HTLauncher.exe", 0x0003272C, gcnew array<DWORD>{ 0xB4 });
}

void GameMemoryService::SetLootBug(bool enabled) {
    if (!enabled) return;

    pm->WriteInt("NoMP", 4);

    int currentValue = pm->ReadInt("LootBug");
    if (currentValue == 2) {
        pm->WriteInt("LootBug", 3);
    }
}

int GameMemoryService::GetHpMax()
{
    return pm->ReadInt("HpMax");
}

int GameMemoryService::GetHpCurrent()
{
    return pm->ReadInt("HpCurrent");
}

int GameMemoryService::GetMpMax()
{
    return pm->ReadInt("MpMax");
}

int GameMemoryService::GetMpCurrent()
{
    return pm->ReadInt("MpCurrent");
}

float GameMemoryService::GetCoordX()
{
    return pm->ReadFloat("CoordX");
}

float GameMemoryService::GetCoordY()
{
    return pm->ReadFloat("CoordY");
}

float GameMemoryService::GetCoordZ()
{
    return pm->ReadFloat("CoordZ");
}