#include "src/CrateClass.h"
#include "src/Hooking.h"
#include "src/Debug.h"
#include "src/Macros.h"
#include <stdio.h>
#include <string.h>

char const *CrateNames[18] = 
{ 
    "Money", // 0
    "Unit", // 1
    "ParaBomb", // 2
    "HealBase", // 3
    "Cloak",  // 4
    "Explosion", // 5
    "Napalm", // 6
    "Squad", // 7
    "Darkness", // 8
    "Reveal", // 9
    "Sonar", // 10
    "Armor", // 11
    "Speed", // 12
    "Firepower", // 13
    "ICBM", // 14
    "TimeQuake", // 15
    "Invulnerability", // 16
    "ChronalVortex", // 17
};

CrateType Crate_From_Name(char *CrateName)
{
    Debug::Log("Crate_From_Name() called with arg: \"%s\".\n", CrateName);
    if (CrateName == NULL) return 0;
    
    for(int i = 0; i < 18; i++)
    {
        if (strcmpi(CrateName, CrateNames[i]) == 0)
        {
            return i;
        }
    }
    return 0;
}

NAKED_FUNC void CrateClass::Constructor()
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        sub     esp, 4
        mov     word ptr [eax+9], 0FFFFh
        mov     esp, ebp
        pop     ebp
        retn
    }
}

const int CrateClass__Create_Crate_JMP_Address = 0x004AC922;

NAKED_FUNC int CrateClass::Create_Crate(short)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
        push    esi
        jmp     CrateClass__Create_Crate_JMP_Address
    }
}

NAKED_FUNC int CrateClass::Get_Crate(short)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    edx
    }
    FANCY_JMP(0x004ACB21);
}
const int CrateClass__Put_Crate_JMP_Address = 0x004AC9B9;

NAKED_FUNC bool CrateClass::Put_Crate(short *)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }    
    FANCY_JMP(0x004AC9B9);
}
const int CrateClass__Remove_It_JMP_Address = 0x004AC8E6;

NAKED_FUNC int CrateClass::Remove_It(void)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    edx
        mov     edx, eax
        jmp     CrateClass__Remove_It_JMP_Address
    }
}

void CrateClass::Init_Hooks()
{
    DEBUG_LOG_FUNC;
    Hooking::JMP_Hook(0x004AC9B4, (int)&CrateClass__Put_Crate_Hook);
    Hooking::JMP_Hook(0x004AB5AC, (int)&Crate_From_Name_Hook);   
    Hooking::JMP_Hook(0x00404120, (int)&CrateClass__Constructor_Hook);  
    Hooking::JMP_Hook(0x004AC91C, (int)&CrateClass__Create_Crate_Hook);
    Hooking::JMP_Hook(0x004ACB1C, (int)&CrateClass__Get_Crate_Hook);  
    Hooking::JMP_Hook(0x004AC8E0, (int)&CrateClass__Remove_It_Hook);
    Hooking::JMP_Hook(0x004054D0, (int)&CrateClass__Destructor_Hook);
}

CrateType Crate_From_Name_Hook() 
{
    GET_EAX(char*, CrateName);
    CrateType Crate = Crate_From_Name(CrateName);
    return Crate; 
}
        
void CrateClass__Constructor_Hook() 
{
    GET_EAX(CrateClass*, Crate);
    Debug::Log("calling CrateClass Constructor.\n");
    Crate->Constructor();
}
        
int CrateClass__Create_Crate_Hook() 
{
    GET_EAX(CrateClass*, Crate);
    GET_DX(short, Unk1);
    return Crate->Create_Crate(Unk1); 
}

int CrateClass__Get_Crate_Hook()
{
    GET_AX(short, Unk1);
    int UnkRet = CrateClass::Get_Crate(Unk1);
    MOV_EAX(UnkRet);
    return UnkRet;
}
        
bool CrateClass__Put_Crate_Hook()
{
    GET_EAX(short*, Unk1);
    int UnkRet = CrateClass::Put_Crate(Unk1);
    Debug::Log("CrateClass::Put_Crate called, ret = %d\n", UnkRet);
    return UnkRet;
}
        
int CrateClass__Remove_It_Hook() 
{
    GET_EAX(CrateClass*, Crate);
    int UnkRet = Crate->Remove_It();
    return UnkRet;
}

void CrateClass__Destructor_Hook() 
{
    GET_EAX(CrateClass*, Crate);
    Crate->Destructor();
    return;
}
