#include "Zion.h"

extern void __fastcall Hooked_Paint( void *thisptr, int edx, vgui::VPANEL vguiPanel , bool forceRepaint, bool allowForce );
extern void __fastcall Hooked_CM( void *thisptr, int edx, int sequence_number, float input_sample_frametime, bool active ); 
extern void __fastcall Hooked_SVA( void *thisptr, int edx, QAngle &va );
typedef void (__thiscall *PaintTraverseFn)( void *thisptr, vgui::VPANEL vguiPanel, bool forceRepaint, bool allowForce);
typedef void (__thiscall *CreateMoveFn)( void *thisptr, int sequence_number, float input_sample_frametime, bool active );
typedef void (__thiscall *SetViewAnglesFn)( void *thisptr, QAngle &va );

namespace Zion {
	// hooks
	extern IBaseClientDLL *m_pClient;
	extern IVEngineClient *m_pEngine;
	extern CInput *m_pInput;
	extern vgui::IPanel *m_pPanel;
	extern vgui::ISurface *m_pSurface;
	extern IClientEntityList *m_pClientEntList;
	extern toolkit::VMTManager *PTHook;
	extern toolkit::VMTManager *CMHook;
#ifdef DODS
	extern toolkit::VMTManager *SVAHook;
#endif
}

class CVerifiedUserCmd
{
public:
	CUserCmd	m_cmd;
	CRC32_t		m_crc;
};