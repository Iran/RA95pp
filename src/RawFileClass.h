#pragma once

class RawFileClass 
{
public:
    //RawFileClass::RawFileClass(void)
    //RawFileClass::RawFileClass(char *FileName)
    //RawFileClass::~RawFileClass(void)
    char *Set_Name(char *Name);
    int Set_Date_Time(unsigned long DateTime);
    long Seek(long pos, int dir);
    long Read(void *buffer, int bytesToRead);
    long Size(void);
    long Write(void *Buffer, long size);
    long Raw_Seek(long pos, int dir);
    int Open(int mode);
    int Open(char *name, int mode);
    void Is_Disk_Inserted(void);
    int Is_Available(int handle);
    unsigned long Get_Date_Time(void);
    int Delete(void);
    int Create(void);
    void Close(void);
    void Bias(int Start, int Length);
    char * const File_Name(void);
    int const Is_Open(void);
    
    static void Init_Hooks();
};

char* RawFileClass__Set_Name_Hook();
int RawFileClass__Set_Date_Time_Hook();
long RawFileClass__Seek_Hook();
long RawFileClass__Read_Hook();
long RawFileClass__Size_Hook();
long RawFileClass__Write_Hook();
int RawFileClass__Raw_Seek_Hook();
int RawFileClass__Open_HookINT();
int RawFileClass__Open_HookCHARP_INT();
void RawFileClass__Is_Disk_Inserted_Hook();
int RawFileClass__Is_Available_Hook();
unsigned long RawFileClass__Get_Date_Time_Hook();
int RawFileClass__Delete_Hook();
int RawFileClass__Create_Hook();
void RawFileClass__Close_Hook();
void RawFileClass__Bias_Hook();
char * const RawFileClass__File_Name_Hook();
int const RawFileClass__Is_Open_Hook();