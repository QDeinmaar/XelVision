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
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pe32.th32ProcessID);

        TCHAR FullPath[MAX_PATH] = TEXT("N/A");

        if(hProcess == NULL)
        {
             _tcscpy_s(FullPath, TEXT("OpenProcess !")); 
        } 
        else 
        {
            dwPriorityClass = GetPriorityClass(hProcess);

            if(!dwPriorityClass)
            {
                _tcscpy_s(FullPath,TEXT("dwPriorityClass!"));
            }

            DWORD size = MAX_PATH;

            if(!QueryFullProcessImageName(hProcess, 0, FullPath, &size))
            {
                    _tcscpy_s(FullPath, TEXT("ACCESS DENIED"));
            }
                CloseHandle(hProcess); 
        }

        _tprintf( TEXT("\n  Process ID        = 0x%08X"), pe32.th32ProcessID );
        _tprintf( TEXT("\n  Thread count      = %d"),   pe32.cntThreads );
        _tprintf( TEXT("\n  Parent process ID = 0x%08X"), pe32.th32ParentProcessID );
        _tprintf( TEXT("\n  Priority base     = %d"), pe32.pcPriClassBase );
        if(dwPriorityClass)
        _tprintf(TEXT("\n   Priority Class    = %d"), dwPriorityClass);
        _tprintf( TEXT("\n  Full Path        =  %s"), FullPath);

        ListProcessModules(pe32.th32ProcessID);
        ListProcessThreads(pe32.th32ProcessID);
    }
    while(Process32Next(hProcessSnap, &pe32));
    CloseHandle(hProcessSnap);
    return(TRUE);
}