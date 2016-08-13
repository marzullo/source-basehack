#include "stdafx.h"
//--Variables
PVOID ClientInterface;
short cliversion;
int index;
//--Needed Modules
HMODULE steam_api = 0;
HMODULE tier0 = 0;
HMODULE vstdlib = 0;

void GetCliInterface(HMODULE Client)
{
	CI ClientFactory = reinterpret_cast<CI> ( GetProcAddress( Client, "CreateInterface" ) );

	for( short version = 0; version < 99; version ++ )
	{
		std::ostringstream o;
		o  << "VClient" << std::setfill('0') << std::setw( 3 ) << version;
		ClientInterface = ClientFactory( o.str().c_str(), NULL );
		if( ClientInterface )
		{
			// std::cout << "Client version string: " << o.str() << std::endl;
			cliversion = version;
			break;
		}
	}
	//--Determine index
	switch( cliversion )
	{
	case 11:
	case 12:
	case 15: // CSS Engine
		index = 5;
		break;
	case 16: // OB Engine
		index = 8;
		break;
	case 18: // L4D 1
		index = 7;
		break;
	case 17: // L4D 2
		index = 3;
		break;
	}
}

void DoWorkSon( HANDLE Proc )
{
	using namespace std;
	HMODULE lclmod = 0;
	short mode = 0;
	string path;
	//--
	cout << "Getting paths of modules in remote process and loading them." << endl;
	steam_api =	LoadRemoteModule( "steam_api.dll", Proc );
	tier0 =	LoadRemoteModule( "tier0.dll", Proc );
	vstdlib = LoadRemoteModule( "vstdlib.dll", Proc );
	lclmod = LoadRemoteModule( "client.dll", Proc );
	//--
	GetCliInterface( lclmod );
	GetAllClasses_t gac = reinterpret_cast<GetAllClasses_t> ( GetFuncAdd( ClientInterface, index ) );
	//--
	NetVars::Analyze( gac( ClientInterface ) );
	cout << "Enter path to where the file should be saved: ";
	cin >> path;
	while( !( mode == 1 || mode == 2 ) )
	{
		cout << "Type 1 to generate a header, 2 for a raw dump: ";
		cin >> mode;
	}
	//--
	if( mode == 1 ) { NetVars::GenCode( path.c_str() ); }
	else { NetVars::GenRaw( path.c_str() ); }
	cout << "Saved to " << path << endl;
	//--
	cout << "Freeing libraries." << endl;
	//--
	FreeLibrary( lclmod );
	FreeLibrary( vstdlib );
	FreeLibrary( tier0 );
	FreeLibrary( steam_api );
}

int main()
{
	using namespace std;
	string procname;
	DWORD procid;
	HANDLE prochandle;
	int err = 0;

	cout << "External Networked Var Dumper" << endl;
	cout << "by Xeno123" << endl;
	cout << "with obvious credit to Casual_Hacker for header generation" << endl;
	cout << "------------------------------------------------------------" << endl << endl;
	cout << "Please enter the name of the game process: ";
	cin >> procname;
	cout << "Opening process: " << procname << endl;
	procid = GetProcessIdByName( procname );
	if( procid == 0 ) 
	{
		cout << "Process not found, exiting." << endl;
		pause();
		return -1;
	}
	cout << "Process found, ID: " << procid << endl;
	prochandle = OpenProcess(procflags, FALSE, procid );
	err = GetLastError();

	if( err != 0 )
	{
		cout << "Error opening process, code: " << err << endl;
		pause();
		return -1;
	}
	
	DoWorkSon( prochandle );

	CloseHandle( prochandle );
	cout << "Done." << endl;
	pause();
	return 0;
}