#include "headers.h"

set<DWORD> seenPIDs;

BOOL DetectNewProcess (set<DWORD> &seenPIDs)
{
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if( hProcessSnap == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }
    if(Process32First(hProcessSnap, &pe32))
    {
        do
    {
        DWORD pid = pe32.th32ProcessID;

        if(seenPIDs.find(pid) == seenPIDs.end())
        {
            seenPIDs.insert(pid);
        }
    } 
    while (Process32Next(hProcessSnap, &pe32));
    }
    CloseHandle(hProcessSnap);
}