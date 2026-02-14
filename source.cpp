#include "headers.h"
 
BOOL ProcessList()
{
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE) 
    {
        print_error(TEXT("Createtoolhelp32Snapshot (of process)"));
        return (FALSE);
    }

    pe32.dwSize = sizeof ( PROCESSENTRY32 );

    if( !Process32First(hProcessSnap , &pe32)){

        print_error(TEXT("Process32First")); // showing the error
        CloseHandle(hProcessSnap);
        return(FALSE);
    }

    do 
    {
        _tprintf("\n\n-------------------------------------------------------");
        _tprintf( TEXT("\nPROCESS NAME:  %s"), pe32.szExeFile );
        _tprintf( TEXT("\n-------------------------------------------------------"));

    }
    while();
}