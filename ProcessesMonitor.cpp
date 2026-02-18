#include "headers.h"

HANDLE hProcessSnap;

BOOL DetectNewProcess (DWORD &seenPIDs)
{
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    
}