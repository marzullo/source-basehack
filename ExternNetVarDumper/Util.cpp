#include "Util.h"

DWORD GetProcessIdByName(const std::string& Name)
{
	HANDLE Snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if (Snap == INVALID_HANDLE_VALUE){ return 0; }

	PROCESSENTRY32 ProcEntry = { sizeof(ProcEntry) };
	bool Found = false;
	BOOL MoreMods = Process32First(Snap, &ProcEntry);
	for (; MoreMods; MoreMods = Process32Next(Snap, &ProcEntry)) 
	{
		std::string CurrentProcess( ProcEntry.szExeFile );
		std::transform(CurrentProcess.begin(),CurrentProcess.end(),CurrentProcess.begin(),tolower);
		Found = (CurrentProcess == Name);
		if (Found) break;
	}

	if (!Found) { return 0; }

	return ProcEntry.th32ProcessID;
}

void pause()
{
	std::cin.sync();
	std::cin.get();
}


void GetRemoteModuleEntry( char *szModuleName, HANDLE hProcess, MODULEENTRY32& res )
{
	HANDLE tlh = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, GetProcessId( hProcess ) );

	MODULEENTRY32 modEntry;

	modEntry.dwSize = sizeof( MODULEENTRY32 );

	Module32First( tlh, &modEntry );
	do
	{
		std::string comp;
		comp.clear();

		comp = modEntry.szModule;

		if( !strcmp( szModuleName, comp.c_str() ) )
		{
			CloseHandle( tlh );
			res = modEntry;
			return;
		}
	}
	while(Module32Next( tlh, &modEntry ) );

	CloseHandle( tlh );
	throw new std::exception("Couldn't find module in remote process.");
	return;
}

HMODULE LoadRemoteModule( char* szModuleName, HANDLE hProcess )
{
	MODULEENTRY32 ent;
	try { GetRemoteModuleEntry( szModuleName, hProcess, ent ); }
	catch(...) {return NULL;}
	return LoadLibrary( ent.szExePath );
}

HMODULE GetRemoteModuleHandle( char* szModuleName, HANDLE hProcess )
{
	MODULEENTRY32 ent;
	try { GetRemoteModuleEntry( szModuleName, hProcess, ent ); }
	catch(...) {return NULL;}
	return ent.hModule;
}

UINT_PTR GetFuncAdd( PVOID pClass, int index )
{
	__try
	{
		PUINT_PTR ClassTable = *reinterpret_cast<PUINT_PTR*> ( pClass );
		return ClassTable[ index ];
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return 0;
	}
}