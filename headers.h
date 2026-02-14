#pragma once

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <stdio.h>
#include <tchar.h>

using namespace std;

BOOL GetProcessList( );
BOOL ListProcessModules( DWORD dwPID );
BOOL ListProcessThreads( DWORD dwOwnerPID );

void print_error(TCHAR const* msg){
     _tprintf(_T("Error: %s\n"), msg);
}
