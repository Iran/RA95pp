#pragma once

typedef int CrateType;

CrateType Crate_From_Name(char *CrateName);

class CrateClass 
{
public:

    void Constructor();
    int Create_Crate(short);
    static int Get_Crate(short);
    static bool Put_Crate(short *);
    int Remove_It(void);
//	void * CrateClass::operator`__arrdtorblk'(unsigned int)
    void Destructor() {}
    
    static void Init_Hooks();
};

int Crate_From_Name_Hook();
void CrateClass__Constructor_Hook();
int CrateClass__Create_Crate_Hook();
int CrateClass__Get_Crate_Hook();
bool CrateClass__Put_Crate_Hook();
int  CrateClass__Remove_It_Hook();
void CrateClass__Destructor_Hook();