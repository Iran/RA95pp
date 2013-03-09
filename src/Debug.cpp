#include "src/Debug.h"

#include <windows.h>
#include <stdio.h>

void Debug::Log(const char *Format, ...)
{
    char buffer[1024];
    va_list va;
    va_start(va, Format);
    vsnprintf(buffer, 1024, Format, va);
    va_end(va);

    char time[256];
    GetTimeFormat(LOCALE_SYSTEM_DEFAULT,TIME_FORCE24HOURFORMAT,0,"'['HH':'mm':'ss'] '",time,0xFF);

    char date[256];
    GetDateFormatA(LOCALE_SYSTEM_DEFAULT,0,0,"'['yyyy'/'MMMM'/'dd']'",date,0xFF);

    FILE* File;
    File = fopen ("RA95++.log","a+");

    if (File != NULL)
    {
        fprintf (File, "%s %s %s", date, time, buffer);
        fclose (File);
    }
}