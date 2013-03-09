#include "src/Macros.h"

// 

class BuildingClass
{
public:
     void AI();
};

int BuildingClass__AI_JMP_Address = 0x0045617F;

NAKED_FUNC void BuildingClass::AI()
{
    __asm
    {
        push    ebp
        mov     ebp, esp
        push    ebx
        push    ecx
        push    edx
        push    esi
        push    edi
        sub     esp, 3Ch
        jmp     BuildingClass__AI_JMP_Address
    }
}

SYRINGE_EXPORT BuildingClass__AI_Hook() {
    GET_EAX(BuildingClass*, Building);
    Building->AI();   
    return RETN_ADDRESS; }
