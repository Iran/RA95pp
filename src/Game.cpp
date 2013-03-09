#pragma once

#include "src/Game.h"
#include "src/Debug.h"
#include "src/Macros.h"
#include "src/Hooking.h"
#include "src/CrateClass.h"

int Init_Game_JMP_Address = 0x004F4065;

NAKED_FUNC int Init_Game(int Unk1, char **Unk2)
{
    _asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
        jmp     Init_Game_JMP_Address
    }
}

int Init_Game_Hook()
{
    GET_EAX(int, Unk1);
    GET_EDX(char**, Unk2);
    
    int ret = Init_Game(Unk1, Unk2);

    Debug::Log("Init_Game_Hook() executed\n");
    
    return ret;
}

void Game__Init_Hooks()
{
    DEBUG_LOG_FUNC;
//    Debug::Log("Executing Game__Init_Hooks().\n");
    Hooking::JMP_Hook(0x4F4060, (int)&Init_Game_Hook);
}
