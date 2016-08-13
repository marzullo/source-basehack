#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include <iostream>


// SDK
#define CLIENT_DLL

#include "public\cdll_int.h"
#include "game\client\cdll_client_int.h"
#include "public\mathlib\mathlib.h"
#include "game\client\cbase.h"
#include "game\client\iclientmode.h"
#include "game\client\input.h"
#include "public\con_nprint.h"
#include "public\vgui_controls\controls.h"
#include "public\vgui\ISurface.h"
#include "public\ienginevgui.h"
#include "public\vgui\IPanel.h"
#include "public\vgui\IClientPanel.h"
#include "game\client\game_controls\commandmenu.h"
#include "public\VGuiMatSurface\IMatSystemSurface.h"
#include "game\shared\in_buttons.h"
//#include "public\basehandle.h"
#include "game\shared\predictioncopy.h"

//#include "public\icliententitylist.h"

// other
#pragma comment ( lib, "vstdlib.lib" )
#pragma comment ( lib, "vgui_controls.lib" )
#pragma comment ( lib, "matsys_controls.lib" )
#pragma comment ( lib, "mathlib.lib" )
#pragma comment ( lib, "tier0.lib" )
#pragma comment ( lib, "tier1.lib" )
#pragma comment ( lib, "tier2.lib" )
#pragma comment ( lib, "tier3.lib" )

// 
#include "vmthooks.h"

// game

#define CSS


DWORD WINAPI HookMain( LPVOID args );

bool ScreenTransform( const Vector &point, Vector &screen, const VMatrix &worldToScreen );
bool WorldToScreen( const Vector &origin, Vector &screen, const VMatrix &worldToScreen );

namespace Entity {
	bool IsOnSameTeam( C_BaseEntity*, C_BaseEntity* );
	int GetFlags( C_BaseEntity* );
	C_BasePlayer *GetLocalPlayer();
}

static Vector vecOldestPunch = Vector( 0, 0, 0 );
static Vector vecOldPunch = Vector( 0, 0, 0 );

#ifdef DODS
static int lastmedic = 0;
#endif
