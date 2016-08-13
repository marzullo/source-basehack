#ifndef Util_h__
#define Util_h__

#include "stdafx.h"

DWORD GetProcessIdByName(const std::string& Name);
void pause();
void GetRemoteModuleEntry( char *szModuleName, HANDLE hProcess, MODULEENTRY32& res );
HMODULE LoadRemoteModule( char* szModuleName, HANDLE hProcess );
HMODULE GetRemoteModuleHandle( char* szModuleName, HANDLE hProcess );

UINT_PTR GetFuncAdd( PVOID pClass, int index );

#endif // Util_h__