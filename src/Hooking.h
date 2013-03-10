#pragma once

#include <Windows.h>
#include "src/Debug.h"
#include "src/Macros.h"
#include "src/CrateClass.h"
#include "src/RawFileClass.h"
#include "src/Game.h"


class Hooking
{
public:

    static void Init_All_Hooks()
    {
        DEBUG_LOG_FUNC;
        Game__Init_Hooks();
        RawFileClass::Init_Hooks();
        CrateClass::Init_Hooks();
    }
    
        static bool Hooking::WriteMemory(int Address, const void* Buffer, int Size)
    {
        bool ret = 1;
        DWORD OldProtect;
        HANDLE Process = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, GetCurrentProcessId());
        VirtualProtectEx(Process, (LPVOID)Address, Size, PAGE_EXECUTE_READWRITE, &OldProtect);
        if (!WriteProcessMemory(Process, (LPVOID)Address, Buffer, Size, NULL))
        {
            Debug::Log("Writing memory address 0x%x failed.\n", Address);
            ret = 0;
        }
        VirtualProtectEx(Process, (LPVOID)Address, Size, OldProtect, NULL);
        CloseHandle(Process);
        return ret;
    };
    
        static void Hooking::JMP_Hook(int Addr, int Function)
    {
        int HookAddress;
        int Offset;
        char OpCode = '\xE9';
        HookAddress = Addr;
        Offset = Function - HookAddress - 5;
        Hooking::WriteMemory(HookAddress, &OpCode, 1);
        Hooking::WriteMemory(HookAddress+1, &Offset, 4);
 /*       Debug::Log("HookAddress = 0x%x, Function = 0x%x, Offset = %d\n",
            HookAddress, Function, Offset); */
    };
};
