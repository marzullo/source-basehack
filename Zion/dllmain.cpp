// dllmain.cpp : Defines the entry point for the DLL application.

#include "Zion.h"
#include <iostream>

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  reason, LPVOID lpReserved )
{
	HWND window = FindWindow( NULL, "Injector" );
	if( reason == DLL_PROCESS_ATTACH ) {
		CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE) HookMain, NULL, 0, NULL ); 
		if( AllocConsole() ) {
			SetConsoleTitle( "Zion Debug Console" );
			freopen("conin$", "r+t", stdin);  
			freopen("conout$", "w+t", stdout);  
			freopen("conout$", "w+t", stderr);
			std::cout<<"Zion 0.0.0\n";
		}
	}

	return TRUE;
}

