#include "headers.h"
 
BOOL ProcessList()
{

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE) 
    {
        print_error(TEXT("Createtoolhelp32Snapshot (of process)"));
        return (FALSE);
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

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

        dwPriorityClass = 0;
        hProcessSnap = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pe32.th32ProcessID);

        if(hProcessSnap == NULL)
        {
            _tprintf(TEXT("OpenProcess !"));
        } 
        else 
        {
            dwPriorityClass = GetPriorityClass(hProcessSnap);
            if(!dwPriorityClass)
            {
                _tprintf(TEXT("dwPriorityClass!"));
                CloseHandle(hProcessSnap);
            }
        }

        
    }
    while(Process32Next(hProcessSnap, &pe32));
}