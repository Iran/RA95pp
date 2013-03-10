#define SYRINGE_EXPORT extern "C" __declspec(dllexport) int
#define NAKED_FUNC __declspec(naked)
#define ASM_INT3       { _asm { int 3 } }
#define RETN_ADDRESS     0x004F4479 // Address where a RETN opcode is located
#define RETN_OPCODE_ADDRESS     RETN_ADDRESS // Address where a RETN opcode is located
#define GET_REGISTER(type, var, register) \
 \
    type var; \
    _asm {mov var, register} 

#define GET_EDX(type, var)    GET_REGISTER(type, var, EDX) 
#define GET_EAX(type, var)    GET_REGISTER(type, var, EAX)
#define GET_ECX(type, var)    GET_REGISTER(type, var, ECX)
#define GET_EBX(type, var)    GET_REGISTER(type, var, EBX)
#define GET_DX(type, var)    GET_REGISTER(type, var, DX) 
#define GET_AX(type, var)    GET_REGISTER(type, var, AX)
#define GET_REG(reg, type, var) GET_REGISTER(type, var, reg)

#define MOV_EAX(var)         __asm { mov eax, var }
#define MOV_AX(var)         __asm { mov ax, var }
#define MOV_DX(var)         __asm { mov dx, var }
#define MOV_EDX(var)         __asm { mov edx, var }
#define MOV_DL(var)         __asm { mov dl, var }
#define MOV_EDX(var)         __asm { mov edx, var }

#define FANCY_JMP(var1)  __asm{ push var1 }; \
                         __asm{ retn };
     
#define PUSH_ECX(var) _asm{ push ecx };

#define DECLARE_VAR(type, name, address) type & name = *((type*)(address))

#define DEBUG_LOG_FUNC 	 Debug::Log("Executing function: \"%s\".\n", __FUNCTION__)

#define PROLOG(reg1, reg2, jmploc)  __asm{ push    ebp  } \
                                      __asm{ mov     ebp, esp } \
                                      __asm{ push   reg1 } \
                                      __asm{ push   reg2 } \
                                      __asm{ push    jmploc } \
                                      __asm { retn }
                             
