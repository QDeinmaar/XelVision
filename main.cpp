#include "headers.h"



int _tmain()
{
    set<DWORD> seenPIDs;

    while(true)
    {
        DetectNewProcess(seenPIDs);
        Sleep(2000); // check every 2 seconds
    }
}





/*
int _tmain(int argc, TCHAR* argv[])
{
    while(TRUE)
    {
        if(GetProcessList())
        {
            _tprintf(TEXT("\nProcess listing completed successfully.\n"));
        }
        else
        {
            _tprintf(TEXT("\nProcess listing failed.\n"));
        }

        Sleep(2000); // wait 2 seconds
    }

    return 0;
}
*/
/*
BOOL GetProcessList( );

int _tmain(int argc, TCHAR* argv[])
{
    if(GetProcessList())
    {
        _tprintf(TEXT("\n\nProcess listing completed successfully.\n"));
    }
    else
    {
        _tprintf(TEXT("\n\nProcess listing failed.\n"));
    }

    return 0;
}
*/



