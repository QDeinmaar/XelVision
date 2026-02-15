#include "headers.h"

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




