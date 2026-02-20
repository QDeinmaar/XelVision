#include "headers.h"

HANDLE hProcessSnap;
set<DWORD> seenPIDs;

BOOL DetectNewProcess (set<DWORD> &seenPIDs)
{
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if(Process32First(hProcessSnap, &pe32))
    {
        do
    {

    } 
    while (Process32Next(hProcessSnap, &pe32));
    }
    
}