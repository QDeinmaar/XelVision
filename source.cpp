#include "headers.h"

BOOL ProcessList()
{
    HANDLE hProcessSnap;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE) //
    {
        
    }
}