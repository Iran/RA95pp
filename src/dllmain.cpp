#include <Windows.h>
#include "src/Hooking.h"

bool FirstDLLAttach = true;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:       
                DeleteFile("RA95++.log");
                
                Debug::Log("Starting RA95++.\n");
                
                Debug::Log("Initializing all hooks.\n");
                Hooking::Init_All_Hooks();
                Debug::Log("Done initializing hooks.\n");

                break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}