#include "src/RawFileClass.h"
#include "src/Hooking.h"
#include "src/Debug.h"
#include "src/Macros.h"

NAKED_FUNC long RawFileClass::Write(void* buffer, long size)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
    }
    FANCY_JMP(0x005C0435);
}

NAKED_FUNC long RawFileClass::Size(void)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C0571);
}

NAKED_FUNC char *RawFileClass::Set_Name(char *Name)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C0071);
}

NAKED_FUNC int RawFileClass::Set_Date_Time(unsigned long)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C06F5);
}

NAKED_FUNC long RawFileClass::Seek(long pos, int dir)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
    }
    FANCY_JMP(0x005C04ED);
}

NAKED_FUNC long RawFileClass::Read(void *buffer, int bytesToRead)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
    }
    FANCY_JMP(0x005C0319);
}

NAKED_FUNC long RawFileClass::Raw_Seek(long, int)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
    }
    FANCY_JMP(0x005C07D1);
}

NAKED_FUNC int RawFileClass::Open(int)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C0105);
}
NAKED_FUNC int RawFileClass::Open(char *, int)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
    }
    FANCY_JMP(0x005C00E9);
}

NAKED_FUNC void RawFileClass::Is_Disk_Inserted(void)
{
    return;
}

NAKED_FUNC int RawFileClass::Is_Available(int)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C0215);
}

NAKED_FUNC unsigned long RawFileClass::Get_Date_Time(void)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    edx
    }
    FANCY_JMP(0x0005C06AD);
}

NAKED_FUNC int RawFileClass::Delete(void)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C0641);
}

NAKED_FUNC int RawFileClass::Create(void)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
    }
    FANCY_JMP(0x005C05FD);
}

NAKED_FUNC void RawFileClass::Close(void)
{
    PROLOG(ebx, ecx, 0x005C02CD);
}

NAKED_FUNC void RawFileClass::Bias(int, int)
{
    PROLOG(ecx, esi, 0x005C0765);
}

NAKED_FUNC char * const RawFileClass::File_Name(void)
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        mov     eax, [eax+14h]
        mov     esp, ebp
        pop     ebp
        retn  
    }
}

NAKED_FUNC int const RawFileClass::Is_Open(void)
{
    _asm 
    {
        push    ebp
        mov     ebp, esp
        cmp     dword ptr [eax+10h], 0FFFFFFFFh
        setnz   al
        and     eax, 0FFh
        mov     esp, ebp
        pop     ebp
        retn   
    }
}

void RawFileClass::Init_Hooks()
{
    DEBUG_LOG_FUNC;
    Hooking::JMP_Hook(0x005C006C, (int)&RawFileClass__Set_Name_Hook);
    
    Hooking::JMP_Hook(0x005C04E8, (int)&RawFileClass__Seek_Hook);
    Hooking::JMP_Hook(0x005C0314, (int)&RawFileClass__Read_Hook);
    Hooking::JMP_Hook(0x005C056C, (int)&RawFileClass__Size_Hook);
    Hooking::JMP_Hook(0x005C0430, (int)&RawFileClass__Write_Hook);
    Hooking::JMP_Hook(0x005C07CC, (int)&RawFileClass__Raw_Seek_Hook);
    Hooking::JMP_Hook(0x005C0100, (int)&RawFileClass__Open_HookINT);
    Hooking::JMP_Hook(0x005C00E4, (int)&RawFileClass__Open_HookCHARP_INT);
//    Hooking::JMP_Hook(0x005C0020, (int)&RawFileClass__Is_Disk_Inserted_Hook);
    Hooking::JMP_Hook(0x005C0210, (int)&RawFileClass__Is_Available_Hook);
    Hooking::JMP_Hook(0x005C06A8, (int)&RawFileClass__Get_Date_Time_Hook);
    Hooking::JMP_Hook(0x005C063C, (int)&RawFileClass__Delete_Hook);
    Hooking::JMP_Hook(0x005C05F8, (int)&RawFileClass__Create_Hook);
    Hooking::JMP_Hook(0x005C02C8, (int)&RawFileClass__Close_Hook);
    Hooking::JMP_Hook(0x005C0760, (int)&RawFileClass__Bias_Hook);
    Hooking::JMP_Hook(0x00426390, (int)&RawFileClass__File_Name_Hook);
    Hooking::JMP_Hook(0x004F89F0, (int)&RawFileClass__Is_Open_Hook);
}

char* RawFileClass__Set_Name_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(char*, Name);
    Debug::Log("calling RawFileClass::Set_Name(), arg = %s.\n", Name);
    return File->Set_Name(Name);
}

int RawFileClass__Set_Date_Time_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(unsigned long, DateTime);
    return File->Set_Date_Time(DateTime);
}

long RawFileClass__Seek_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(long, Pos);
    GET_EBX(int, Dir);
    Debug::Log("calling RawFileClass::Seek(), arg1 = %d, arg2 = %d.\n", Pos, Dir);
    return File->Seek(Pos, Dir);
}

long RawFileClass__Read_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(void*, Buffer);
    GET_EBX(int, BytesToRead);
    return File->Read(Buffer, BytesToRead);
}

long RawFileClass__Size_Hook()
{
    GET_EAX(RawFileClass*, File);
    return File->Size();
}

long RawFileClass__Write_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(void*, Buffer);
    GET_EBX(long, Size);
    return File->Write(Buffer, Size);
}

int RawFileClass__Raw_Seek_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(long, Pos);
    GET_EBX(int, Dir);
    return File->Raw_Seek(Pos, Dir);
}
int RawFileClass__Open_HookINT()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(int, Mode); 
    return File->Open(Mode);
}

int RawFileClass__Open_HookCHARP_INT()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(char*, Name);
    GET_EBX(int, Mode); 
    return File->Open(Name, Mode);
}

int RawFileClass__Is_Available_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(int, Handle);
    return File->Is_Available(Handle);
}

unsigned long RawFileClass__Get_Date_Time_Hook()
{
    GET_EAX(RawFileClass*, File);
    return File->Get_Date_Time();
}

int RawFileClass__Delete_Hook()
{
    GET_EAX(RawFileClass*, File);
    return File->Delete();
}
int RawFileClass__Create_Hook()
{
    GET_EAX(RawFileClass*, File);
    return File->Create();
}
void RawFileClass__Close_Hook()
{
    GET_EAX(RawFileClass*, File);
    File->Close();
}
void RawFileClass__Bias_Hook()
{
    GET_EAX(RawFileClass*, File);
    GET_EDX(int, Start);
    GET_EBX(int, Length);
    File->Bias(Start, Length);
}
char * const RawFileClass__File_Name_Hook()
{
    GET_EAX(RawFileClass*, File);
    return File->File_Name();
}

int const RawFileClass__Is_Open_Hook()
{
    GET_EAX(RawFileClass*, File);
    return File->Is_Open();
}