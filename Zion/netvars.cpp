#include "Zion.h"
#include "hooks.h"
#include "netvars.h"
#include <string>

#define GetNetVar(table, netvar) NetVars::##netvar = GetNetvarOffset(#table, #netvar); 
    //OutputLog("%s: +0x%X\n", #netvar, NetVars::##netvar );

#define NetVar(entity, netvar, type) ( *reinterpret_cast<##type*>( reinterpret_cast< DWORD >( ##entity ) + NetVars::##netvar ) )

int CrawlTableForOffset( RecvTable *pTable, const char *name )
    {
            int addOffset = 0;
     
            for( int i = 0; i < pTable->GetNumProps(); i++ )
            {
                    RecvProp *pProp = pTable->GetProp( i );
     
                    if( pProp->GetDataTable() && pProp->GetDataTable()->GetNumProps() > 0 )
                    {
                            int iOffset = CrawlTableForOffset( pProp->GetDataTable(), name );
     
                            if( iOffset )
                            {
                                    addOffset += pProp->GetOffset() + iOffset;
                            }
                    }
					
                    std::string propName( pProp->GetName() );
					
                    if( propName.find( "[0]" ) != propName.npos )
                            propName.replace( propName.find( "[0]" ), 3, "\0\0\0" );
     
                    if( stricmp( name, propName.c_str() ) )
                            continue;
     
                    return pProp->GetOffset() + addOffset;
            }
            return addOffset;
    }
     
    int GetNetvarOffset( const char *table, const char *name )
    {
            ClientClass *pClass = Zion::m_pClient->GetAllClasses();
			
            for( ; pClass; pClass = pClass->m_pNext )
            {
                    RecvTable *pTable = pClass->m_pRecvTable;
     
                    if( pTable->GetNumProps() <= 1 )
                            continue;
     
                    if( stricmp( table, pTable->GetName() ) )
                            continue;
     
                    int iResult = CrawlTableForOffset( pTable, name );
                   
                    return iResult;
            }
            return NULL;
    }
     
namespace NetVars
{
    int m_iHealth;
    int m_iTeamNum;
    int m_LifeState;
    int m_fFlags;
    int m_vecViewOffset;
    int m_hActiveWeapon;
    int m_bDucked;
    int m_ArmorValue;
    int m_vecPunchAngle;
    int m_nTickBase;
    int m_flNextPrimaryAttack;
    int m_flFlashDuration;
    int m_flFlashMaxAlpha;
    int m_iFOV;
    int m_vecVelocity;
    int m_angEyeAngles;
	int flSpread;
};

void Init_NetVars()
{
    GetNetVar( DT_BasePlayer, m_iHealth );
    GetNetVar( DT_BasePlayer, m_iTeamNum );
    GetNetVar( DT_BasePlayer, m_LifeState );
    GetNetVar( DT_BasePlayer, m_fFlags );
    GetNetVar( DT_BasePlayer, m_vecViewOffset );
    GetNetVar( DT_BasePlayer, m_bDucked );
    GetNetVar( DT_BasePlayer, m_vecPunchAngle );
    GetNetVar( DT_BasePlayer, m_nTickBase );
    GetNetVar( DT_BasePlayer, m_iFOV );
    GetNetVar( DT_BasePlayer, m_vecVelocity );
    GetNetVar( DT_BasePlayer, m_angEyeAngles );

    /*if(g_appID == 240)
    {
        GetNetVar( DT_CSPlayer, m_ArmorValue );
        GetNetVar( DT_CSPlayer, m_flFlashDuration );
        GetNetVar( DT_CSPlayer, m_flFlashMaxAlpha );
    }*/

    GetNetVar( DT_BaseCombatCharacter, m_hActiveWeapon );
    GetNetVar( DT_BaseCombatWeapon, m_flNextPrimaryAttack );
	GetNetVar( DT_TEFireBullets, flSpread );
}

