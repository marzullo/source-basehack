#ifndef stdafx_h__
#define stdafx_h__

//--Windows API
#include <windows.h>
#include <TlHelp32.h>
//--C++ Standard Library
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
//--Valve
#include "client_class.h"
#include "dt_common.h"
#include "dt_recv.h"
//--Util functions
#include "Util.h"
//--NetVar Dumper
#include "NetVars.h"

typedef ClientClass* (__thiscall* GetAllClasses_t)(PVOID pThis);
typedef void* (*CI)(const char *pName, int *pReturnCode);

#define procflags ( PROCESS_QUERY_INFORMATION | PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ )

#endif // stdafx_h__