#include "Zion.h"
#include "hooks.h"
#include "netvars.h"

namespace Entity {
	bool IsOnSameTeam( C_BaseEntity *bEnt, C_BaseEntity *lPlr ) {
		if( *MakePointerGEN2<int>( (DWORD)bEnt, 0x98 ) ==  *MakePointerGEN2<int>( (DWORD)lPlr, 0x98 ) ) {
			return true;
		}
		return false;
	}

	int GetFlags( C_BaseEntity *bEnt ) {
		return *MakePointerGEN2<int>( (DWORD)bEnt, 0x2E4 );
	}

	C_BasePlayer *GetLocalPlayer() {
		return (CBasePlayer*)(Zion::m_pClientEntList->GetClientEntity(Zion::m_pEngine->GetLocalPlayer())->GetBaseEntity());
	}
}