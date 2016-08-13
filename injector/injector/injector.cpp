// injector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}*/

#include <Windows.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <TlHelp32.h>

bool FindProcessByName( const char* pszName, DWORD& dwProcessID )
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );

	if ( hSnapshot == INVALID_HANDLE_VALUE )
		return false;

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	if ( Process32First( hSnapshot, &pe32 ) )
	{
		do 
		{
			if ( !_stricmp( pe32.szExeFile, pszName ) )
			{
				dwProcessID = pe32.th32ProcessID;
				CloseHandle( hSnapshot );

				return true;
			}
		} while ( Process32Next( hSnapshot, &pe32 ) );
	}

	CloseHandle( hSnapshot );

	return false;
}

bool ReadConfig( const char* pszFileName, char* pszProcess, char* pszDllName )
{
	WIN32_FIND_DATA FindFileData;
	
	if ( FindFirstFile( pszFileName, &FindFileData ) != INVALID_HANDLE_VALUE )
	{
		GetPrivateProfileString( "KynJector", "Process", "notepad.exe", pszProcess, 64-1, pszFileName );
		GetPrivateProfileString( "KynJector", "DLL", "leethax.dll", pszDllName, MAX_PATH-1, pszFileName );
		return true;
	}
	return false;
}

int main( int argc, char* argv[] )
{
	char szProcess[64]			= { 0 };
	char szDllName[MAX_PATH]	= { 0 };
	std::string sConfigFile		= "";
	std::string sDirectory		= "";
	DWORD dwProcessID			= 0;

	SetConsoleTitle( "Injector" );
	printf( "********************************************************************\r\n" );
	printf( "   App:     KynJector\r\n" );
	printf( "   Version: 1.0\r\n" );
	printf( "   Author:  kynox\r\n" );
	printf( "   Website: http://www.gamedeception.net\r\n" );
	printf( "*********************************************************************\r\n" );

	sDirectory = argv[0];
	sDirectory = sDirectory.substr( 0, sDirectory.rfind( "\\" ) ) + "\\";
	
	sConfigFile = argv[0];
	sConfigFile = sConfigFile.substr( sConfigFile.rfind( "\\" ) + 1 );
	sConfigFile = sConfigFile.substr( 0, sConfigFile.rfind( "." ) ) + ".ini";

	if ( !ReadConfig( (sDirectory + sConfigFile).c_str(), szProcess, szDllName ) )
	{
		printf( "* Failed to read %s\r\n", sConfigFile.c_str() );

		_getch();

		return 1;
	}

	printf( "* Waiting on %s..\r\n", szProcess );
	printf( " * Press [Enter] to cancel\r\n" );
	while( !FindProcessByName( szProcess, dwProcessID ) )
	{
		if ( GetAsyncKeyState( VK_RETURN )&1 )
			return 0;

		Sleep( 10 );
	}

	printf( "* Process Found (0x%X)\r\n", dwProcessID );

	HANDLE hHandle = OpenProcess( PROCESS_ALL_ACCESS, FALSE, dwProcessID );

	if ( hHandle == INVALID_HANDLE_VALUE )
	{
		printf( "* Failed to open process\r\n" );

		_getch();

		return 1;
	}

	sDirectory.append( szDllName );
	const char* pszFullDllName	= sDirectory.c_str();
	const int iDllLen			= strlen( pszFullDllName ) + 1;
	DWORD dwBaseAddr = (DWORD)VirtualAllocEx( hHandle, NULL, iDllLen, MEM_COMMIT, PAGE_EXECUTE_READWRITE );

	if ( !dwBaseAddr )
	{
		CloseHandle( hHandle );
		printf( "* Failed to allocate 0x%X bytes in process\r\n", iDllLen );

		_getch();

		return 1;
	}

	HMODULE hKernel32 = (HMODULE)GetModuleHandle( "kernel32" );

	if ( !dwBaseAddr )
	{
		CloseHandle( hHandle );
		printf( "* Failed to find Kernel32.dll module handler\r\n", iDllLen );

		_getch();

		return 1;
	}

	DWORD dwLoadLibrary			= (DWORD)GetProcAddress( hKernel32, "LoadLibraryA" );
	DWORD dwFreeLibrary			= (DWORD)GetProcAddress( hKernel32, "FreeLibrary" );
	DWORD dwBytesWritten		= 0;

	WriteProcessMemory( hHandle, (LPVOID)dwBaseAddr, pszFullDllName, strlen( pszFullDllName ) + 1, &dwBytesWritten );
	
	if ( dwBytesWritten == 0 )
	{
		printf( "* Failed writing DllName process\r\n" );

		VirtualFreeEx( hHandle, (LPVOID)dwBaseAddr, iDllLen, MEM_DECOMMIT );
		CloseHandle( hHandle );

		_getch();

		return 1;
	}

	DWORD dwExitCode	= 0;
	HANDLE hThread		= CreateRemoteThread( hHandle, NULL, 0, (LPTHREAD_START_ROUTINE)dwLoadLibrary, (LPVOID)dwBaseAddr, 0, NULL );
	
	if ( hThread != INVALID_HANDLE_VALUE )
	{
		WaitForSingleObject( hThread, INFINITE );
		GetExitCodeThread( hThread, &dwExitCode );
	}

	if ( dwExitCode )
		printf( "* Successfully injected - Base Addr: [0x%X]\r\n", dwExitCode );
	else
		printf( "* Failed to inject!\r\n" );

	printf( "* Press [Enter] to Exit or [Alt] + [Enter] to Eject and Exit\r\n" );

	while( 1 )
	{
		if ( GetForegroundWindow() == GetConsoleWindow() )
		{
			if ( GetAsyncKeyState( VK_RETURN ) & 1 )
			{
				if ( !GetAsyncKeyState( VK_MENU )&1 )
				{
					break;
				} else
				{
					hThread		= CreateRemoteThread( hHandle, NULL, 0, (LPTHREAD_START_ROUTINE)dwFreeLibrary, (LPVOID)dwExitCode, 0, NULL );
					if ( hThread != INVALID_HANDLE_VALUE )
						WaitForSingleObject( hThread, INFINITE );

					break;
				}
			}
		}
		Sleep( 10 );
	}

	VirtualFreeEx( hHandle, (LPVOID)dwBaseAddr, iDllLen, MEM_RELEASE );
	CloseHandle( hHandle );

	return 0;
}