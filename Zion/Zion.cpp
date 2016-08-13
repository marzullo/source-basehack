// Zion.cpp : Defines the exported functions for the DLL application.
//

#include "Zion.h"
#include "hooks.h"
#include "netvars.h"
#include "public\tier1\checksum_md5.h"
#include <iostream>

#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

inline bool DataCompare( const BYTE* pData, const BYTE* bSig, const char* szMask )
{
    for( ; *szMask; ++szMask, ++pData, ++bSig)
    {
        if( *szMask == 'x' && *pData != *bSig)
            return false;
    }

    return ( *szMask ) == NULL;
}

// Finds a pattern at the specified address
inline DWORD FindPattern ( DWORD dwAddress, DWORD dwSize, BYTE* pbSig, char* szMask )
{
    for( DWORD i = NULL; i < dwSize; i++ )
    {
        if( DataCompare( (BYTE*) ( dwAddress + i ), pbSig, szMask ) )
            return (DWORD)( dwAddress + i );
    }
    return 0;
}  

float GetWeaponSpread( C_BaseCombatWeapon* pWeapon )
{
    __asm
    {
        MOV ESI, pWeapon;
        MOV EDX, DWORD PTR DS:[ ESI ];
        MOV EAX, DWORD PTR DS:[ EDX + 680 ];
        MOV ECX, ESI;
        CALL EAX;
    }
}


namespace Zion {

	CreateInterfaceFn EngineInterface;
	CreateInterfaceFn ClientInterface;
	CreateInterfaceFn VGUIInterface;
	CreateInterfaceFn MatSurfaceInterface;

	IBaseClientDLL *m_pClient;
	IVEngineClient *m_pEngine;
	CInput *m_pInput;
	vgui::IPanel *m_pPanel;
	vgui::ISurface *m_pSurface;
	IClientEntityList *m_pClientEntList;
	toolkit::VMTManager *PTHook;
	toolkit::VMTManager *CMHook;
	toolkit::VMTManager *SVAHook;

	void Init( HMODULE Engine, HMODULE Client )
	{
		EngineInterface = (CreateInterfaceFn)GetProcAddress( Engine, "CreateInterface" );
		ClientInterface = (CreateInterfaceFn)GetProcAddress( Client, "CreateInterface" );
		VGUIInterface	= (CreateInterfaceFn)GetProcAddress( GetModuleHandle( "vgui2.dll" ), "CreateInterface" );
		MatSurfaceInterface = (CreateInterfaceFn)GetProcAddress( GetModuleHandle( "vguimatsurface.dll" ), "CreateInterface" );

		m_pEngine			=	(IVEngineClient*)EngineInterface( "VEngineClient013", NULL );
		m_pClient			=	(IBaseClientDLL*)ClientInterface( "VClient016", NULL );
		m_pPanel			=	(vgui::IPanel*)VGUIInterface( "VGUI_Panel009", NULL );

		m_pSurface			=	(vgui::ISurface*)MatSurfaceInterface( "VGUI_Surface030", NULL );
		m_pClientEntList	=	(IClientEntityList*)ClientInterface( "VClientEntityList003", NULL );

		static toolkit::VMTManager PTH( m_pPanel ); // must be static
		PTHook = &PTH;
		PTH.HookMethod( &Hooked_Paint, 40 );

		static toolkit::VMTManager CMH( m_pClient );
		CMHook = &CMH;
		CMH.HookMethod( &Hooked_CM, 21 );
		
//#ifdef DODS
		static toolkit::VMTManager SVAH( m_pEngine );
		SVAHook = &SVAH;
		SVAH.HookMethod( &Hooked_SVA, 20 );
//#endif

		Init_NetVars();
		std::cout<<NetVars::m_vecPunchAngle;

		m_pInput = (CInput*)**(DWORD**)( CMH.GetMethodAddress( 21 ) + 0x28 );
	}

}

DWORD WINAPI HookMain( LPVOID args ) {

	HMODULE Engine = NULL;
	HMODULE Client = NULL;

	while( !Engine || !Client ) {
		Engine = GetModuleHandleA( "engine.dll" );
		Client = GetModuleHandleA( "client.dll" );
		Zion::Init( Engine, Client );
		Sleep(100);
	}

	return TRUE;
}

using namespace Zion;

void __fastcall Hooked_Paint( void *thisptr, int edx, vgui::VPANEL vguiPanel , bool forceRepaint, bool allowForce ) {

	Zion::PTHook->GetMethod<PaintTraverseFn>( 40 )( thisptr, vguiPanel, forceRepaint, allowForce );

	const char* PanelName = Zion::m_pPanel->GetName( vguiPanel );

	if( !strcmp(PanelName, "MatSystemTopPanel") ) {

		for( int i=0; i <= Zion::m_pClientEntList->GetHighestEntityIndex(); i++ ) {
			if( i==Zion::m_pEngine->GetLocalPlayer() ) { continue; }
			IClientEntity *ent = Zion::m_pClientEntList->GetClientEntity( i );
			IClientEntity *lpl = Zion::m_pClientEntList->GetClientEntity( m_pEngine->GetLocalPlayer() );
			C_BaseEntity *bEnt;
			C_BaseEntity *blpl;
			//C_BasePlayer *bPly = (C_BasePlayer*)bEnt;

			if( ent && !ent->IsDormant() && lpl ) {
				bEnt = ent->GetBaseEntity();
				blpl = lpl->GetBaseEntity();
				//Vector PunchAng = *MakePointerGEN<Vector>( (DWORD)bPly, 0xD90 );
				//std::cout<<PunchAng.x<<"/"<<PunchAng.y<<"\n";
			}

			std::cout<<bEnt->IsPlayer();

			if( bEnt && bEnt->IsPlayer() && bEnt->IsAlive() ) {

				Vector scrPos;
				Vector plPos = bEnt->GetAbsOrigin();

				plPos.z += 50;

				const VMatrix &worldToScreen = Zion::m_pEngine->WorldToScreenMatrix();

				WorldToScreen( plPos, scrPos, worldToScreen );

				if( *MakePointerGEN2<int>( (DWORD)bEnt, 0x98 ) == *MakePointerGEN2<int>( (DWORD)blpl, 0x98 ) ) {
					Zion::m_pSurface->DrawSetColor( 0, 0, 255, 255 );
				} else {
					Zion::m_pSurface->DrawSetColor( 255, 0, 0, 255 );
				}

				Zion::m_pSurface->DrawOutlinedRect( scrPos.x-15, scrPos.y-15, scrPos.x+15, scrPos.y+15 );
			}
		}
	}
}

//int iSeed;
//bool SetSeed = false;
int nSeed = 1;

void __fastcall Hooked_CM( void *thisptr, int edx, int sequence_number, float input_sample_frametime, bool active ) {
	Zion::CMHook->GetMethod<CreateMoveFn>( 21 )( thisptr, sequence_number, input_sample_frametime, active );

	CVerifiedUserCmd *pVerifiedCommands = *(CVerifiedUserCmd**)( (DWORD) m_pInput + 0xB8 );
	if( !pVerifiedCommands )
		return;
	CVerifiedUserCmd *pVerified = &pVerifiedCommands[ sequence_number % MULTIPLAYER_BACKUP ];
	if ( !pVerified )
		return;
	CUserCmd* pCmd = m_pInput->GetUserCmd( sequence_number );
	
	//if ( m_pClientEntList->GetClientEntityFromHandle( NetVar( Zion::m_pClientEntList->GetClientEntity( m_pEngine->GetLocalPlayer() )->GetBaseEntity(), m_hActiveWeapon, CBaseHandle ) ) ) {
	//	GetWeaponSpread( reinterpret_cast< C_BaseCombatWeapon* >( m_pClientEntList->GetClientEntityFromHandle( NetVar( Zion::m_pClientEntList->GetClientEntity( m_pEngine->GetLocalPlayer() )->GetBaseEntity(), m_hActiveWeapon, CBaseHandle ) ) ) );
	//}

	if(reinterpret_cast<GenDT_TFPlayer*>(Entity::GetLocalPlayer())->hActiveWeapon()->GetEntryIndex()) {
		int weaponIndex = reinterpret_cast<GenDT_TFPlayer*>(Entity::GetLocalPlayer())->hActiveWeapon()->GetEntryIndex();
		C_BaseCombatWeapon* pBaseEntity = (C_BaseCombatWeapon*)m_pClientEntList->GetClientEntity(weaponIndex); 
		if( pBaseEntity ) {
			//GetWeaponSpread( pBaseEntity );
		}
	}

	//EHANDLE hActiveWeapon = NetVar( Zion::m_pClientEntList->GetClientEntity( m_pEngine->GetLocalPlayer() )->GetBaseEntity(), m_hActiveWeapon, EHANDLE );
	//if( NetVar( Entity::GetLocalPlayer(), m_hActiveWeapon, EHANDLE ) ) {
		//int Index = NetVar( Entity::GetLocalPlayer(), m_hActiveWeapon, int );// & 0xFFF;
		//std::cout<<Index;
	//}

	//m_pClientEntList->GetClientEntityFromHandle( NetVar( Entity::GetLocalPlayer(), m_hActiveWeapon, EHANDLE ) );
	//GetWeaponSpread( dynamic_cast< C_BaseCombatWeapon* >( m_pClientEntList->GetClientEntityFromHandle( NetVar( Entity::GetLocalPlayer(), m_hActiveWeapon, EHANDLE ) ) ) );

	//dynamic_cast< C_BaseCombatWeapon* >( m_pClientEntList->GetClientEntityFromHandle( NetVar( Entity::GetLocalPlayer(), m_hActiveWeapon, EHANDLE ) ) );

#ifdef DODS
	if( (NetVar( Entity::GetLocalPlayer(), m_iHealth, int ) < 25) && (Entity::GetLocalPlayer()->IsAlive() == true) 
		&& (Zion::m_pEngine->Time() > (lastmedic+10))) {
		Zion::m_pEngine->ExecuteClientCmd( "say_team !medic" );
		lastmedic = Zion::m_pEngine->Time();
	}
#endif

#ifdef CSS
	/*Vector PunchAng = NetVar( Entity::GetLocalPlayer(), m_vecPunchAngle, Vector );//*MakePointerGEN<Vector>( (DWORD)(Entity::GetLocalPlayer()), 0xD98 );

	//std::cout<<PunchAng.x<<"/"<<PunchAng.y<<"\n";

	Vector vecDeltaPunch = PunchAng + vecOldestPunch;

	vecOldestPunch = vecOldPunch;
	vecOldPunch = PunchAng;

	Vector vecNextPunch = PunchAng + vecDeltaPunch;*/
#endif

	if(pCmd) {

#ifdef CSS
		/*pCmd->viewangles[0] -=  ( PunchAng[0] + vecNextPunch[0] );

		pCmd->viewangles[1] -=	( PunchAng[1] + vecNextPunch[1] );*/
#endif

		/*if(!SetSeed) {
			iSeed = pCmd->random_seed;
			SetSeed = true;
			std::cout<<"Finding match for seed: "<<pCmd->random_seed<<"\n";
		} else if(iSeed == pCmd->random_seed) {
			std::cout<<"Seed Match Found! "<<pCmd->random_seed<<"\n";
		}*/

		//std::cout<<sequence_number<<"\n";

		//std::cout<<pCmd->random_seed<<"\n";

		/*if(nSeed <= 2) {
			pCmd->random_seed = 142;
			/*nSeed++;
			std::cout<<"call";
		}*/


		if(pCmd->buttons & IN_JUMP && (Entity::GetFlags( m_pClientEntList->GetClientEntity(m_pEngine->GetLocalPlayer())->GetBaseEntity() )&FL_ONGROUND)==1) {
			pCmd->buttons |= IN_JUMP;
		} else {
			pCmd->buttons &= ~IN_JUMP;
		}

	}

	pVerified->m_cmd = *pCmd;
	pVerified->m_crc = pCmd->GetChecksum();
	
}


DWORD addresses[200];

void __fastcall Hooked_SVA( void *thisptr, int edx, QAngle &va ) {
	if((DWORD)_ReturnAddress()!=addresses[1]) {
		Zion::SVAHook->GetMethod<SetViewAnglesFn>(20)( thisptr, va );
	}
	bool addrused = false;
	for(int i=1; i<=200; i++) {
		if(addresses[i] == (DWORD)_ReturnAddress()) {
			addrused = true;
			break;
		}
	}

	if(addrused == false) {
		for(int i=1; i<=200; i++) {
			if(addresses[i] == NULL) {
				addresses[i] = (DWORD)_ReturnAddress();
				break;
			}
		}
		std::cout<<(DWORD)_ReturnAddress()<<"\n";
	}

}
