#pragma once
#include <windows.h>
template<typename T> inline T* MakePointerGEN( PVOID thisptr, int offset ) { return reinterpret_cast<T*>( reinterpret_cast<UINT_PTR>( thisptr ) + offset ); }
struct GenDT_BaseEntity
{
	struct CAnimTimeMustBeFirst
	{
		inline float* flAnimTime() { return MakePointerGEN< float >( this, 0x60 ); }
	};
	struct CCollisionProperty
	{
		inline Vector* vecMins() { return MakePointerGEN< Vector >( this, 0x8 ); }
		inline Vector* vecMaxs() { return MakePointerGEN< Vector >( this, 0x14 ); }
		inline int* nSolidType() { return MakePointerGEN< int >( this, 0x29 ); }
		inline int* usSolidFlags() { return MakePointerGEN< int >( this, 0x24 ); }
		inline int* nSurroundType() { return MakePointerGEN< int >( this, 0x28 ); }
		inline int* triggerBloat() { return MakePointerGEN< int >( this, 0x2a ); }
		inline Vector* vecSpecifiedSurroundingMins() { return MakePointerGEN< Vector >( this, 0x2c ); }
		inline Vector* vecSpecifiedSurroundingMaxs() { return MakePointerGEN< Vector >( this, 0x38 ); }
	};
	struct CPredictableId
	{
		inline int* PredictableID() { return MakePointerGEN< int >( this, 0x9c ); }
		inline bool* bIsPlayerSimulated() { return MakePointerGEN< bool >( this, 0x45c ); }
	};
	inline CAnimTimeMustBeFirst* AnimTimeMustBeFirst() { return MakePointerGEN< CAnimTimeMustBeFirst >( this, 0x0 ); }
	inline float* flSimulationTime() { return MakePointerGEN< float >( this, 0x68 ); }
	inline int* ubInterpolationFrame() { return MakePointerGEN< int >( this, 0x74 ); }
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline QAngle* angRotation() { return MakePointerGEN< QAngle >( this, 0x2d8 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x8c ); }
	inline int* fEffects() { return MakePointerGEN< int >( this, 0x78 ); }
	inline int* nRenderMode() { return MakePointerGEN< int >( this, 0x7c ); }
	inline int* nRenderFX() { return MakePointerGEN< int >( this, 0x54 ); }
	inline int* clrRender() { return MakePointerGEN< int >( this, 0x58 ); }
	inline int* iTeamNum() { return MakePointerGEN< int >( this, 0x98 ); }
	inline int* CollisionGroup() { return MakePointerGEN< int >( this, 0x2e8 ); }
	inline float* flElasticity() { return MakePointerGEN< float >( this, 0x1e4 ); }
	inline float* flShadowCastDistance() { return MakePointerGEN< float >( this, 0x1e8 ); }
	inline EHANDLE* hOwnerEntity() { return MakePointerGEN< EHANDLE >( this, 0x46c ); }
	inline EHANDLE* hEffectEntity() { return MakePointerGEN< EHANDLE >( this, 0x470 ); }
	inline int* moveparent() { return MakePointerGEN< int >( this, 0x15c ); }
	inline int* iParentAttachment() { return MakePointerGEN< int >( this, 0x146 ); }
	inline int* movetype() { return MakePointerGEN< int >( this, 0x0 ); }
	inline int* movecollide() { return MakePointerGEN< int >( this, 0x0 ); }
	inline CCollisionProperty* Collision() { return MakePointerGEN< CCollisionProperty >( this, 0x168 ); }
	inline int* iTextureFrameIndex() { return MakePointerGEN< int >( this, 0x460 ); }
	inline CPredictableId* predictable_id() { return MakePointerGEN< CPredictableId >( this, 0x0 ); }
	inline bool* bSimulatedEveryTick() { return MakePointerGEN< bool >( this, 0x45d ); }
	inline bool* bAnimatedEveryTick() { return MakePointerGEN< bool >( this, 0x45e ); }
	inline bool* bAlternateSorting() { return MakePointerGEN< bool >( this, 0x45f ); }
};
struct GenDT_BaseAnimating : public GenDT_BaseEntity
{
	struct CServerAnimationData
	{
		inline float* flCycle() { return MakePointerGEN< float >( this, 0x750 ); }
	};
	inline int* nSequence() { return MakePointerGEN< int >( this, 0x748 ); }
	inline int* nForceBone() { return MakePointerGEN< int >( this, 0x4f0 ); }
	inline Vector* vecForce() { return MakePointerGEN< Vector >( this, 0x4e4 ); }
	inline int* nSkin() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline int* nBody() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* nHitboxSet() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline float* flModelWidthScale() { return MakePointerGEN< float >( this, 0x5b0 ); }
	inline float* flPoseParameter() { return MakePointerGEN< float >( this, 0x5b4 ); } // Array size = 24
	inline float* flPlaybackRate() { return MakePointerGEN< float >( this, 0x4d8 ); }
	inline float* flEncodedController() { return MakePointerGEN< float >( this, 0x6cc ); } // Array size = 4
	inline bool* bClientSideAnimation() { return MakePointerGEN< bool >( this, 0x718 ); }
	inline bool* bClientSideFrameReset() { return MakePointerGEN< bool >( this, 0x520 ); }
	inline int* nNewSequenceParity() { return MakePointerGEN< int >( this, 0x71c ); }
	inline int* nResetEventsParity() { return MakePointerGEN< int >( this, 0x720 ); }
	inline int* nMuzzleFlashParity() { return MakePointerGEN< int >( this, 0x7c8 ); }
	inline EHANDLE* hLightingOrigin() { return MakePointerGEN< EHANDLE >( this, 0x7c0 ); }
	inline EHANDLE* hLightingOriginRelative() { return MakePointerGEN< EHANDLE >( this, 0x7c4 ); }
	inline CServerAnimationData* serveranimdata() { return MakePointerGEN< CServerAnimationData >( this, 0x0 ); }
	inline int* fadeMinDist() { return MakePointerGEN< int >( this, 0x558 ); }
	inline int* fadeMaxDist() { return MakePointerGEN< int >( this, 0x55c ); }
	inline float* flFadeScale() { return MakePointerGEN< float >( this, 0x560 ); }
};
struct GenDT_BaseCombatWeapon : public GenDT_BaseAnimating
{
	struct CLocalWeaponData
	{
		inline int* iClip1() { return MakePointerGEN< int >( this, 0x834 ); }
		inline int* iClip2() { return MakePointerGEN< int >( this, 0x838 ); }
		inline int* iPrimaryAmmoType() { return MakePointerGEN< int >( this, 0x82c ); }
		inline int* iSecondaryAmmoType() { return MakePointerGEN< int >( this, 0x830 ); }
		inline int* nViewModelIndex() { return MakePointerGEN< int >( this, 0x7ec ); }
		inline bool* bFlipViewModel() { return MakePointerGEN< bool >( this, 0x864 ); }
	};
	struct CLocalActiveWeaponData
	{
		inline float* flNextPrimaryAttack() { return MakePointerGEN< float >( this, 0x7f0 ); }
		inline float* flNextSecondaryAttack() { return MakePointerGEN< float >( this, 0x7f4 ); }
		inline int* nNextThinkTick() { return MakePointerGEN< int >( this, 0x84 ); }
		inline float* flTimeWeaponIdle() { return MakePointerGEN< float >( this, 0x7f8 ); }
	};
	inline CLocalWeaponData* LocalWeaponData() { return MakePointerGEN< CLocalWeaponData >( this, 0x0 ); }
	inline CLocalActiveWeaponData* LocalActiveWeaponData() { return MakePointerGEN< CLocalActiveWeaponData >( this, 0x0 ); }
	inline int* iViewModelIndex() { return MakePointerGEN< int >( this, 0x800 ); }
	inline int* iWorldModelIndex() { return MakePointerGEN< int >( this, 0x804 ); }
	inline int* iState() { return MakePointerGEN< int >( this, 0x824 ); }
	inline EHANDLE* hOwner() { return MakePointerGEN< EHANDLE >( this, 0x7e8 ); }
};
struct GenDT_WeaponDODBase : public GenDT_BaseCombatWeapon
{
	inline int* iReloadModelIndex() { return MakePointerGEN< int >( this, 0x888 ); }
	inline Vector* vInitialDropVelocity() { return MakePointerGEN< Vector >( this, 0x88c ); }
	inline float* flSmackTime() { return MakePointerGEN< float >( this, 0x8ac ); }
};
struct GenDT_WeaponIFMBase : public GenDT_WeaponDODBase
{
};
struct GenDT_WeaponIFMBaseCamera : public GenDT_WeaponIFMBase
{
	inline float* flRenderAspectRatio() { return MakePointerGEN< float >( this, 0x954 ); }
	inline float* flRenderFOV() { return MakePointerGEN< float >( this, 0x958 ); }
	inline float* flRenderArmLength() { return MakePointerGEN< float >( this, 0x95c ); }
	inline Vector* vecRenderPosition() { return MakePointerGEN< Vector >( this, 0x960 ); }
	inline QAngle* angRenderAngles() { return MakePointerGEN< QAngle >( this, 0x96c ); }
};
struct GenDT_WeaponIFMSteadyCam : public GenDT_WeaponIFMBaseCamera
{
};
struct GenDT_WeaponDODBaseGun : public GenDT_WeaponDODBase
{
	struct CLocalActiveWeaponBaseGunData
	{
	};
	inline CLocalActiveWeaponBaseGunData* LocalActiveWeaponBaseGunData() { return MakePointerGEN< CLocalActiveWeaponBaseGunData >( this, 0x0 ); }
};
struct GenDT_FullAutoWeapon : public GenDT_WeaponDODBaseGun
{
};
struct GenDT_FullAutoPunchWeapon : public GenDT_FullAutoWeapon
{
};
struct GenDT_WeaponThompson : public GenDT_FullAutoPunchWeapon
{
};
struct GenDT_WeaponDODBaseGrenade : public GenDT_WeaponDODBase
{
	inline bool* bPinPulled() { return MakePointerGEN< bool >( this, 0x921 ); }
	inline bool* bArmed() { return MakePointerGEN< bool >( this, 0x922 ); }
};
struct GenDT_WeaponStickGrenade : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_SemiAutoWeapon : public GenDT_WeaponDODBaseGun
{
};
struct GenDT_SniperWeapon : public GenDT_SemiAutoWeapon
{
	inline bool* bZoomed() { return MakePointerGEN< bool >( this, 0x920 ); }
	inline bool* bDoViewAnim() { return MakePointerGEN< bool >( this, 0x928 ); }
};
struct GenDT_WeaponSpring : public GenDT_SniperWeapon
{
};
struct GenDT_WeaponDODBaseMelee : public GenDT_WeaponDODBase
{
};
struct GenDT_WeaponSpade : public GenDT_WeaponDODBaseMelee
{
};
struct GenDT_WeaponSmokeGrenadeUS : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_WeaponSmokeGrenadeGER : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_WeaponRifleGrenadeUS_Live : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_WeaponBaseRifleGrenade : public GenDT_WeaponDODBaseGun
{
};
struct GenDT_WeaponRifleGrenadeUS : public GenDT_WeaponBaseRifleGrenade
{
};
struct GenDT_WeaponRifleGrenadeGER_Live : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_WeaponRifleGrenadeGER : public GenDT_WeaponBaseRifleGrenade
{
};
struct GenDT_BaseRocketWeapon : public GenDT_WeaponDODBase
{
	inline bool* bDeployed() { return MakePointerGEN< bool >( this, 0x920 ); }
};
struct GenDT_WeaponPschreck : public GenDT_BaseRocketWeapon
{
};
struct GenDT_WeaponP38 : public GenDT_SemiAutoWeapon
{
};
struct GenDT_FireSelectWeapon : public GenDT_WeaponDODBaseGun
{
	inline bool* bSemiAuto() { return MakePointerGEN< bool >( this, 0x928 ); }
};
struct GenDT_WeaponMP44 : public GenDT_FireSelectWeapon
{
};
struct GenDT_WeaponMP40 : public GenDT_FullAutoPunchWeapon
{
};
struct GenDT_BipodWeapon : public GenDT_FullAutoWeapon
{
	inline bool* bDeployed() { return MakePointerGEN< bool >( this, 0x928 ); }
	inline int* iDeployedReloadModelIndex() { return MakePointerGEN< int >( this, 0x930 ); }
};
struct GenDT_WeaponMG42 : public GenDT_BipodWeapon
{
	inline int* iWeaponHeat() { return MakePointerGEN< int >( this, 0x958 ); }
	inline float* flNextCoolTime() { return MakePointerGEN< float >( this, 0x95c ); }
	inline bool* bOverheated() { return MakePointerGEN< bool >( this, 0x960 ); }
};
struct GenDT_WeaponM1Carbine : public GenDT_SemiAutoWeapon
{
};
struct GenDT_WeaponK98Scoped : public GenDT_SniperWeapon
{
};
struct GenDT_WeaponK98 : public GenDT_SniperWeapon
{
};
struct GenDT_WeaponHandGrenade : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_WeaponGarand : public GenDT_SniperWeapon
{
};
struct GenDT_WeaponExplodingStickGrenade : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_WeaponExplodingHandGrenade : public GenDT_WeaponDODBaseGrenade
{
};
struct GenDT_BaseBombWeapon : public GenDT_WeaponDODBase
{
};
struct GenDT_WeaponColt : public GenDT_SemiAutoWeapon
{
};
struct GenDT_WeaponC96 : public GenDT_FullAutoWeapon
{
};
struct GenDT_WeaponBazooka : public GenDT_BaseRocketWeapon
{
};
struct GenDT_WeaponBAR : public GenDT_FireSelectWeapon
{
};
struct GenDT_WeaponAmerKnife : public GenDT_WeaponDODBaseMelee
{
};
struct GenDT_Weapon30cal : public GenDT_BipodWeapon
{
};
struct GenDT_BaseViewModel
{
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x8c ); }
	inline int* nSkin() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline int* nBody() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* nSequence() { return MakePointerGEN< int >( this, 0x748 ); }
	inline int* nViewModelIndex() { return MakePointerGEN< int >( this, 0x7f8 ); }
	inline float* flPlaybackRate() { return MakePointerGEN< float >( this, 0x4d8 ); }
	inline int* fEffects() { return MakePointerGEN< int >( this, 0x78 ); }
	inline int* nAnimationParity() { return MakePointerGEN< int >( this, 0x808 ); }
	inline EHANDLE* hWeapon() { return MakePointerGEN< EHANDLE >( this, 0x818 ); }
	inline EHANDLE* hOwner() { return MakePointerGEN< EHANDLE >( this, 0x7fc ); }
	inline int* nNewSequenceParity() { return MakePointerGEN< int >( this, 0x71c ); }
	inline int* nResetEventsParity() { return MakePointerGEN< int >( this, 0x720 ); }
	inline int* nMuzzleFlashParity() { return MakePointerGEN< int >( this, 0x7c8 ); }
	inline float* flPoseParameter0() { return MakePointerGEN< float >( this, 0x5b4 ); }
	inline float* flPoseParameter() { return MakePointerGEN< float >( this, 0x0 ); } // Array size = 24
};
struct GenDT_DODViewModel : public GenDT_BaseViewModel
{
};
struct GenDT_DODRoundTimer
{
	inline bool* bTimerPaused() { return MakePointerGEN< bool >( this, 0x4a8 ); }
	inline float* flTimeRemaining() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline float* flTimerEndTime() { return MakePointerGEN< float >( this, 0x4b0 ); }
};
struct GenDT_FuncNewTeamWall : public GenDT_BaseEntity
{
};
struct GenDT_GameRulesProxy
{
};
struct GenDT_DODGameRulesProxy : public GenDT_GameRulesProxy
{
	struct CDODGameRules
	{
		inline int* iRoundState() { return MakePointerGEN< int >( this, 0x38 ); }
		inline bool* bInWarmup() { return MakePointerGEN< bool >( this, 0xa4 ); }
		inline bool* bAwaitingReadyRestart() { return MakePointerGEN< bool >( this, 0xa5 ); }
		inline float* flMapResetTime() { return MakePointerGEN< float >( this, 0xac ); }
		inline float* flRestartRoundTime() { return MakePointerGEN< float >( this, 0xa8 ); }
		inline bool* bAlliesAreBombing() { return MakePointerGEN< bool >( this, 0xb0 ); }
		inline bool* bAxisAreBombing() { return MakePointerGEN< bool >( this, 0xb1 ); }
		inline int* iAlliesRespawnHead() { return MakePointerGEN< int >( this, 0x8c ); }
		inline int* iAlliesRespawnTail() { return MakePointerGEN< int >( this, 0x90 ); }
		inline int* iAxisRespawnHead() { return MakePointerGEN< int >( this, 0x94 ); }
		inline int* iAxisRespawnTail() { return MakePointerGEN< int >( this, 0x98 ); }
	}; // Fail count = 2
	inline CDODGameRules* dod_gamerules_data() { return MakePointerGEN< CDODGameRules >( this, 0x0 ); }
};
struct GenDT_BaseTempEntity
{
};
struct GenDT_TEDODExplosion : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin0() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecOrigin1() { return MakePointerGEN< Vector >( this, 0x14 ); }
	inline Vector* vecOrigin2() { return MakePointerGEN< Vector >( this, 0x18 ); }
	inline Vector* vecNormal() { return MakePointerGEN< Vector >( this, 0x1c ); }
};
struct GenDT_TEFireBullets
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x14 ); }
	inline Vector* vecAngles0() { return MakePointerGEN< Vector >( this, 0x20 ); }
	inline Vector* vecAngles1() { return MakePointerGEN< Vector >( this, 0x24 ); }
	inline int* iWeaponID() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* iMode() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* iSeed() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* iPlayer() { return MakePointerGEN< int >( this, 0x10 ); }
	inline float* flSpread() { return MakePointerGEN< float >( this, 0x38 ); }
};
struct GenDT_BaseParticleEntity : public GenDT_BaseEntity
{
};
struct GenDT_GrenadeTrail : public GenDT_BaseParticleEntity
{
	inline float* SpawnRate() { return MakePointerGEN< float >( this, 0x594 ); }
	inline float* ParticleLifetime() { return MakePointerGEN< float >( this, 0x5b4 ); }
	inline float* StopEmitTime() { return MakePointerGEN< float >( this, 0x5b8 ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5e4 ); }
	inline int* nAttachment() { return MakePointerGEN< int >( this, 0x5e8 ); }
};
struct GenDT_Team
{
	inline int* iTeamNum() { return MakePointerGEN< int >( this, 0x4f0 ); }
	inline int* iScore() { return MakePointerGEN< int >( this, 0x4dc ); }
	inline int* iRoundsWon() { return MakePointerGEN< int >( this, 0x4e0 ); }
	inline char** szTeamname() { return MakePointerGEN< char* >( this, 0x4bc ); }
}; // Fail count = 2
struct GenDT_DODTeam : public GenDT_Team
{
};
struct GenDT_DODTeam_Axis : public GenDT_DODTeam
{
};
struct GenDT_DODTeam_Allies : public GenDT_DODTeam
{
};
struct GenDT_BaseGrenade : public GenDT_BaseAnimating
{
	inline float* flDamage() { return MakePointerGEN< float >( this, 0x7fc ); }
	inline float* DmgRadius() { return MakePointerGEN< float >( this, 0x7ec ); }
	inline bool* bIsLive() { return MakePointerGEN< bool >( this, 0x7e9 ); }
	inline EHANDLE* hThrower() { return MakePointerGEN< EHANDLE >( this, 0x804 ); }
	inline Vector* vecVelocity() { return MakePointerGEN< Vector >( this, 0xf0 ); }
	inline int* fFlags() { return MakePointerGEN< int >( this, 0x2e4 ); }
};
struct GenDT_DODBaseGrenade : public GenDT_BaseGrenade
{
	inline Vector* vInitialVelocity() { return MakePointerGEN< Vector >( this, 0x814 ); }
};
struct GenDT_DODSmokeGrenade : public GenDT_DODBaseGrenade
{
	inline float* flSmokeSpawnTime() { return MakePointerGEN< float >( this, 0x820 ); }
};
struct GenDT_PlayerResource
{
	inline int* iPing() { return MakePointerGEN< int >( this, 0x534 ); } // Array size = 34
	inline int* iScore() { return MakePointerGEN< int >( this, 0x5bc ); } // Array size = 34
	inline int* iDeaths() { return MakePointerGEN< int >( this, 0x644 ); } // Array size = 34
	inline bool* bConnected() { return MakePointerGEN< bool >( this, 0x6cc ); } // Array size = 34
	inline int* iTeam() { return MakePointerGEN< int >( this, 0x6f0 ); } // Array size = 34
	inline bool* bAlive() { return MakePointerGEN< bool >( this, 0x778 ); } // Array size = 34
	inline int* iHealth() { return MakePointerGEN< int >( this, 0x79c ); } // Array size = 34
};
struct GenDT_DODPlayerResource : public GenDT_PlayerResource
{
	inline int* iObjScore() { return MakePointerGEN< int >( this, 0x8a8 ); } // Array size = 34
	inline int* iPlayerClass() { return MakePointerGEN< int >( this, 0x930 ); } // Array size = 34
};
struct GenDT_DODRagdoll
{
	inline Vector* vecRagdollOrigin() { return MakePointerGEN< Vector >( this, 0x860 ); }
	inline EHANDLE* hPlayer() { return MakePointerGEN< EHANDLE >( this, 0x850 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x8c ); }
	inline int* nForceBone() { return MakePointerGEN< int >( this, 0x4f0 ); }
	inline Vector* vecForce() { return MakePointerGEN< Vector >( this, 0x4e4 ); }
	inline Vector* vecRagdollVelocity() { return MakePointerGEN< Vector >( this, 0x854 ); }
};
struct GenDT_BaseAnimatingOverlay : public GenDT_BaseAnimating
{
	struct COverlayVars
	{
	}; // Fail count = 1
	inline COverlayVars* overlay_vars() { return MakePointerGEN< COverlayVars >( this, 0x0 ); }
};
struct GenDT_BaseFlex : public GenDT_BaseAnimatingOverlay
{
	inline float* flexWeight() { return MakePointerGEN< float >( this, 0x88c ); } // Array size = 96
	inline bool* blinktoggle() { return MakePointerGEN< bool >( this, 0xa38 ); }
	inline Vector* viewtarget() { return MakePointerGEN< Vector >( this, 0x854 ); }
};
struct GenDT_BaseCombatCharacter : public GenDT_BaseFlex
{
	struct CBCCLocalPlayerExclusive
	{
		inline float* flNextAttack() { return MakePointerGEN< float >( this, 0xba0 ); }
	};
	inline CBCCLocalPlayerExclusive* bcc_localdata() { return MakePointerGEN< CBCCLocalPlayerExclusive >( this, 0x0 ); }
	inline EHANDLE* hActiveWeapon() { return MakePointerGEN< EHANDLE >( this, 0xce8 ); }
	inline EHANDLE* hMyWeapons() { return MakePointerGEN< EHANDLE >( this, 0xc28 ); } // Array size = 48
};
struct GenDT_BasePlayer : public GenDT_BaseCombatCharacter
{
	struct CLocalPlayerExclusive
	{
		struct CLocal
		{
			inline char* chAreaBits() { return MakePointerGEN< char >( this, 0x4 ); } // Array size = 32
			inline char* chAreaPortalBits() { return MakePointerGEN< char >( this, 0x24 ); } // Array size = 24
			inline int* iHideHUD() { return MakePointerGEN< int >( this, 0x3c ); }
			inline float* flFOVRate() { return MakePointerGEN< float >( this, 0x40 ); }
			inline bool* bDucked() { return MakePointerGEN< bool >( this, 0x44 ); }
			inline bool* bDucking() { return MakePointerGEN< bool >( this, 0x45 ); }
			inline bool* bInDuckJump() { return MakePointerGEN< bool >( this, 0x46 ); }
			inline float* flDucktime() { return MakePointerGEN< float >( this, 0x48 ); }
			inline float* flDuckJumpTime() { return MakePointerGEN< float >( this, 0x4c ); }
			inline float* flJumpTime() { return MakePointerGEN< float >( this, 0x50 ); }
			inline float* flFallVelocity() { return MakePointerGEN< float >( this, 0x58 ); }
			inline Vector* vecPunchAngle() { return MakePointerGEN< Vector >( this, 0x6c ); }
			inline Vector* vecPunchAngleVel() { return MakePointerGEN< Vector >( this, 0xa4 ); }
			inline bool* bDrawViewmodel() { return MakePointerGEN< bool >( this, 0xdc ); }
			inline bool* bWearingSuit() { return MakePointerGEN< bool >( this, 0xdd ); }
			inline bool* bPoisoned() { return MakePointerGEN< bool >( this, 0xde ); }
			inline float* flStepSize() { return MakePointerGEN< float >( this, 0xe0 ); }
			inline bool* bAllowAutoMovement() { return MakePointerGEN< bool >( this, 0xe4 ); }
			inline int* skybox3d_scale() { return MakePointerGEN< int >( this, 0xec ); }
			inline Vector* skybox3d_origin() { return MakePointerGEN< Vector >( this, 0xf0 ); }
			inline int* skybox3d_area() { return MakePointerGEN< int >( this, 0xfc ); }
			inline int* skybox3d_fog_enable() { return MakePointerGEN< int >( this, 0x140 ); }
			inline int* skybox3d_fog_blend() { return MakePointerGEN< int >( this, 0x141 ); }
			inline Vector* skybox3d_fog_dirPrimary() { return MakePointerGEN< Vector >( this, 0x104 ); }
			inline int* skybox3d_fog_colorPrimary() { return MakePointerGEN< int >( this, 0x110 ); }
			inline int* skybox3d_fog_colorSecondary() { return MakePointerGEN< int >( this, 0x114 ); }
			inline float* skybox3d_fog_start() { return MakePointerGEN< float >( this, 0x120 ); }
			inline float* skybox3d_fog_end() { return MakePointerGEN< float >( this, 0x124 ); }
			inline float* skybox3d_fog_maxdensity() { return MakePointerGEN< float >( this, 0x12c ); }
			inline int* PlayerFog_m_hCtrl() { return MakePointerGEN< int >( this, 0x148 ); }
			inline Vector* audio_localSound0() { return MakePointerGEN< Vector >( this, 0x16c ); }
			inline Vector* audio_localSound1() { return MakePointerGEN< Vector >( this, 0x178 ); }
			inline Vector* audio_localSound2() { return MakePointerGEN< Vector >( this, 0x184 ); }
			inline Vector* audio_localSound3() { return MakePointerGEN< Vector >( this, 0x190 ); }
			inline Vector* audio_localSound4() { return MakePointerGEN< Vector >( this, 0x19c ); }
			inline Vector* audio_localSound5() { return MakePointerGEN< Vector >( this, 0x1a8 ); }
			inline Vector* audio_localSound6() { return MakePointerGEN< Vector >( this, 0x1b4 ); }
			inline Vector* audio_localSound7() { return MakePointerGEN< Vector >( this, 0x1c0 ); }
			inline int* audio_soundscapeIndex() { return MakePointerGEN< int >( this, 0x1cc ); }
			inline int* audio_localBits() { return MakePointerGEN< int >( this, 0x1d0 ); }
			inline int* audio_ent() { return MakePointerGEN< int >( this, 0x1d4 ); }
		};
		inline CLocal* Local() { return MakePointerGEN< CLocal >( this, 0xd3c ); }
		inline Vector* vecViewOffset0() { return MakePointerGEN< Vector >( this, 0xe4 ); }
		inline Vector* vecViewOffset1() { return MakePointerGEN< Vector >( this, 0xe8 ); }
		inline Vector* vecViewOffset2() { return MakePointerGEN< Vector >( this, 0xec ); }
		inline float* flFriction() { return MakePointerGEN< float >( this, 0x1f8 ); }
		inline int* iAmmo() { return MakePointerGEN< int >( this, 0xba8 ); } // Array size = 32
		inline int* fOnTarget() { return MakePointerGEN< int >( this, 0xf40 ); }
		inline int* nTickBase() { return MakePointerGEN< int >( this, 0x1040 ); }
		inline int* nNextThinkTick() { return MakePointerGEN< int >( this, 0x84 ); }
		inline EHANDLE* hLastWeapon() { return MakePointerGEN< EHANDLE >( this, 0x1054 ); }
		inline EHANDLE* hGroundEntity() { return MakePointerGEN< EHANDLE >( this, 0x1f0 ); }
		inline Vector* vecVelocity0() { return MakePointerGEN< Vector >( this, 0xf0 ); }
		inline Vector* vecVelocity1() { return MakePointerGEN< Vector >( this, 0xf4 ); }
		inline Vector* vecVelocity2() { return MakePointerGEN< Vector >( this, 0xf8 ); }
		inline Vector* vecBaseVelocity() { return MakePointerGEN< Vector >( this, 0x124 ); }
		inline EHANDLE* hConstraintEntity() { return MakePointerGEN< EHANDLE >( this, 0xf78 ); }
		inline Vector* vecConstraintCenter() { return MakePointerGEN< Vector >( this, 0xf7c ); }
		inline float* flConstraintRadius() { return MakePointerGEN< float >( this, 0xf88 ); }
		inline float* flConstraintWidth() { return MakePointerGEN< float >( this, 0xf8c ); }
		inline float* flConstraintSpeedFactor() { return MakePointerGEN< float >( this, 0xf90 ); }
		inline float* flDeathTime() { return MakePointerGEN< float >( this, 0xfb8 ); }
		inline int* nWaterLevel() { return MakePointerGEN< int >( this, 0x148 ); }
		inline float* flLaggedMovementValue() { return MakePointerGEN< float >( this, 0x1190 ); }
	};
	struct CPlayerState
	{
		inline int* deadflag() { return MakePointerGEN< int >( this, 0x4 ); }
	};
	inline CLocalPlayerExclusive* localdata() { return MakePointerGEN< CLocalPlayerExclusive >( this, 0x0 ); }
	inline CPlayerState* pl() { return MakePointerGEN< CPlayerState >( this, 0xf18 ); }
	inline int* iFOV() { return MakePointerGEN< int >( this, 0xf2c ); }
	inline int* iFOVStart() { return MakePointerGEN< int >( this, 0xf30 ); }
	inline float* flFOVTime() { return MakePointerGEN< float >( this, 0xf34 ); }
	inline int* iDefaultFOV() { return MakePointerGEN< int >( this, 0xf38 ); }
	inline EHANDLE* hZoomOwner() { return MakePointerGEN< EHANDLE >( this, 0xf3c ); }
	inline EHANDLE* hVehicle() { return MakePointerGEN< EHANDLE >( this, 0xfc4 ); }
	inline EHANDLE* hUseEntity() { return MakePointerGEN< EHANDLE >( this, 0xfcc ); }
	inline int* iHealth() { return MakePointerGEN< int >( this, 0x90 ); }
	inline int* lifeState() { return MakePointerGEN< int >( this, 0x8f ); }
	inline int* iBonusProgress() { return MakePointerGEN< int >( this, 0xfd4 ); }
	inline int* iBonusChallenge() { return MakePointerGEN< int >( this, 0xfd8 ); }
	inline float* flMaxspeed() { return MakePointerGEN< float >( this, 0xfd0 ); }
	inline int* fFlags() { return MakePointerGEN< int >( this, 0x2e4 ); }
	inline int* iObserverMode() { return MakePointerGEN< int >( this, 0xf94 ); }
	inline EHANDLE* hObserverTarget() { return MakePointerGEN< EHANDLE >( this, 0xf98 ); }
	inline EHANDLE* hViewModel0() { return MakePointerGEN< EHANDLE >( this, 0x106c ); }
	inline EHANDLE* hViewModel() { return MakePointerGEN< EHANDLE >( this, 0x0 ); } // Array size = 2
	inline char** szLastPlaceName() { return MakePointerGEN< char* >( this, 0x11b0 ); }
};
struct GenDT_DODPlayer : public GenDT_BasePlayer
{
	struct CDODPlayerShared
	{
		struct CDODSharedLocalPlayerExclusive
		{
			inline int* iPlayerClass() { return MakePointerGEN< int >( this, 0x8 ); }
			inline int* iDesiredPlayerClass() { return MakePointerGEN< int >( this, 0xc ); }
			inline float* flDeployedYawLimitLeft() { return MakePointerGEN< float >( this, 0x1c ); }
			inline float* flDeployedYawLimitRight() { return MakePointerGEN< float >( this, 0x20 ); }
			inline int* iCPIndex() { return MakePointerGEN< int >( this, 0x4c ); }
			inline bool* bPlayerDominated() { return MakePointerGEN< bool >( this, 0x5c ); } // Array size = 34
			inline bool* bPlayerDominatingMe() { return MakePointerGEN< bool >( this, 0x7e ); } // Array size = 34
		};
		inline float* flStamina() { return MakePointerGEN< float >( this, 0x10 ); }
		inline float* flSlowedUntilTime() { return MakePointerGEN< float >( this, 0x14 ); }
		inline bool* bProne() { return MakePointerGEN< bool >( this, 0x4 ); }
		inline bool* bIsSprinting() { return MakePointerGEN< bool >( this, 0x18 ); }
		inline float* flGoProneTime() { return MakePointerGEN< float >( this, 0x40 ); }
		inline float* flUnProneTime() { return MakePointerGEN< float >( this, 0x3c ); }
		inline float* flDeployChangeTime() { return MakePointerGEN< float >( this, 0x44 ); }
		inline float* flDeployedHeight() { return MakePointerGEN< float >( this, 0x38 ); }
		inline bool* bPlanting() { return MakePointerGEN< bool >( this, 0x24 ); }
		inline bool* bDefusing() { return MakePointerGEN< bool >( this, 0x25 ); }
		inline CDODSharedLocalPlayerExclusive* dodsharedlocaldata() { return MakePointerGEN< CDODSharedLocalPlayerExclusive >( this, 0x0 ); }
	};
	struct CDODLocalPlayerExclusive
	{
		inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
		inline float* flStunDuration() { return MakePointerGEN< float >( this, 0x1438 ); }
		inline float* flStunMaxAlpha() { return MakePointerGEN< float >( this, 0x1434 ); }
		inline int* iProgressBarDuration() { return MakePointerGEN< int >( this, 0x143c ); }
		inline float* flProgressBarStartTime() { return MakePointerGEN< float >( this, 0x1440 ); }
	};
	struct CDODNonLocalPlayerExclusive
	{
		inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	};
	inline CDODPlayerShared* Shared() { return MakePointerGEN< CDODPlayerShared >( this, 0x136c ); }
	inline CDODLocalPlayerExclusive* dodlocaldata() { return MakePointerGEN< CDODLocalPlayerExclusive >( this, 0x0 ); }
	inline CDODNonLocalPlayerExclusive* dodnonlocaldata() { return MakePointerGEN< CDODNonLocalPlayerExclusive >( this, 0x0 ); }
	inline QAngle* angEyeAngles0() { return MakePointerGEN< QAngle >( this, 0x1334 ); }
	inline QAngle* angEyeAngles1() { return MakePointerGEN< QAngle >( this, 0x1338 ); }
	inline EHANDLE* hRagdoll() { return MakePointerGEN< EHANDLE >( this, 0x141c ); }
	inline bool* bSpawnInterpCounter() { return MakePointerGEN< bool >( this, 0x1469 ); }
	inline int* iAchievementAwardsMask() { return MakePointerGEN< int >( this, 0x14d4 ); }
};
struct GenDT_TEPlayerAnimEvent
{
	inline EHANDLE* hPlayer() { return MakePointerGEN< EHANDLE >( this, 0x10 ); }
	inline int* iEvent() { return MakePointerGEN< int >( this, 0x14 ); }
	inline int* nData() { return MakePointerGEN< int >( this, 0x18 ); }
};
struct GenDT_DODObjectiveResource
{
	inline int* iNumControlPoints() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline Vector* vCPPositions0() { return MakePointerGEN< Vector >( this, 0x4ac ); }
	inline bool* bCPIsVisible() { return MakePointerGEN< bool >( this, 0x50c ); } // Array size = 8
	inline int* iAlliesIcons() { return MakePointerGEN< int >( this, 0x514 ); } // Array size = 8
	inline int* iAxisIcons() { return MakePointerGEN< int >( this, 0x534 ); } // Array size = 8
	inline int* iNeutralIcons() { return MakePointerGEN< int >( this, 0x554 ); } // Array size = 8
	inline int* iTimerCapIcons() { return MakePointerGEN< int >( this, 0x574 ); } // Array size = 8
	inline int* iBombedIcons() { return MakePointerGEN< int >( this, 0x594 ); } // Array size = 8
	inline int* iAlliesReqCappers() { return MakePointerGEN< int >( this, 0x5b4 ); } // Array size = 8
	inline int* iAxisReqCappers() { return MakePointerGEN< int >( this, 0x5d4 ); } // Array size = 8
	inline float* flAlliesCapTime() { return MakePointerGEN< float >( this, 0x5f4 ); } // Array size = 8
	inline float* flAxisCapTime() { return MakePointerGEN< float >( this, 0x614 ); } // Array size = 8
	inline bool* bBombPlanted() { return MakePointerGEN< bool >( this, 0x634 ); } // Array size = 8
	inline int* iBombsRequired() { return MakePointerGEN< int >( this, 0x63c ); } // Array size = 8
	inline int* iBombsRemaining() { return MakePointerGEN< int >( this, 0x65c ); } // Array size = 8
	inline bool* bBombBeingDefused() { return MakePointerGEN< bool >( this, 0x67c ); } // Array size = 8
	inline int* iNumAllies() { return MakePointerGEN< int >( this, 0x684 ); } // Array size = 8
	inline int* iNumAxis() { return MakePointerGEN< int >( this, 0x6a4 ); } // Array size = 8
	inline int* iCappingTeam() { return MakePointerGEN< int >( this, 0x6c4 ); } // Array size = 8
	inline int* iOwner() { return MakePointerGEN< int >( this, 0x6e4 ); } // Array size = 8
}; // Fail count = 1
struct GenDT_DODBombTarget : public GenDT_BaseAnimating
{
	inline int* iState() { return MakePointerGEN< int >( this, 0x7e8 ); }
	inline int* iBombingTeam() { return MakePointerGEN< int >( this, 0x7ec ); }
	inline int* iTargetModel() { return MakePointerGEN< int >( this, 0x7f0 ); }
	inline int* iUnavailableModel() { return MakePointerGEN< int >( this, 0x7f4 ); }
};
struct GenDT_DODBombDispenserMapIcon : public GenDT_BaseEntity
{
};
struct GenDT_DODBaseRocket : public GenDT_BaseAnimating
{
	inline Vector* vInitialVelocity() { return MakePointerGEN< Vector >( this, 0x7e8 ); }
};
struct GenDT_DODRifleGrenadeGER : public GenDT_DODBaseGrenade
{
};
struct GenDT_DODRifleGrenadeUS : public GenDT_DODBaseGrenade
{
};
struct GenDT_NextBot : public GenDT_BaseCombatCharacter
{
};
struct GenDT_TestTraceline
{
	inline int* clrRender() { return MakePointerGEN< int >( this, 0x58 ); }
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline QAngle* angRotation0() { return MakePointerGEN< QAngle >( this, 0x2d8 ); }
	inline QAngle* angRotation1() { return MakePointerGEN< QAngle >( this, 0x2dc ); }
	inline QAngle* angRotation2() { return MakePointerGEN< QAngle >( this, 0x2e0 ); }
	inline int* moveparent() { return MakePointerGEN< int >( this, 0x15c ); }
};
struct GenDT_TEWorldDecal : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline int* nIndex() { return MakePointerGEN< int >( this, 0x1c ); }
};
struct GenDT_TESpriteSpray : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecDirection() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* fNoise() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* nCount() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* nSpeed() { return MakePointerGEN< int >( this, 0x2c ); }
};
struct GenDT_TESprite : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* fScale() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* nBrightness() { return MakePointerGEN< int >( this, 0x24 ); }
};
struct GenDT_TEParticleSystem : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin0() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecOrigin1() { return MakePointerGEN< Vector >( this, 0x14 ); }
	inline Vector* vecOrigin2() { return MakePointerGEN< Vector >( this, 0x18 ); }
};
struct GenDT_TESparks : public GenDT_TEParticleSystem
{
	inline int* nMagnitude() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* nTrailLength() { return MakePointerGEN< int >( this, 0x20 ); }
	inline Vector* vecDir() { return MakePointerGEN< Vector >( this, 0x24 ); }
};
struct GenDT_TESmoke : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* fScale() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* nFrameRate() { return MakePointerGEN< int >( this, 0x24 ); }
};
struct GenDT_TEShowLine : public GenDT_TEParticleSystem
{
	inline Vector* vecEnd() { return MakePointerGEN< Vector >( this, 0x1c ); }
};
struct GenDT_TEProjectedDecal : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline QAngle* angRotation() { return MakePointerGEN< QAngle >( this, 0x1c ); }
	inline float* flDistance() { return MakePointerGEN< float >( this, 0x28 ); }
	inline int* nIndex() { return MakePointerGEN< int >( this, 0x2c ); }
};
struct GenDT_TEPlayerDecal : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x14 ); }
	inline int* nEntity() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* nPlayer() { return MakePointerGEN< int >( this, 0x10 ); }
};
struct GenDT_TEPhysicsProp : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline QAngle* angRotation0() { return MakePointerGEN< QAngle >( this, 0x1c ); }
	inline QAngle* angRotation1() { return MakePointerGEN< QAngle >( this, 0x20 ); }
	inline QAngle* angRotation2() { return MakePointerGEN< QAngle >( this, 0x24 ); }
	inline Vector* vecVelocity() { return MakePointerGEN< Vector >( this, 0x28 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* nFlags() { return MakePointerGEN< int >( this, 0x3c ); }
	inline int* nSkin() { return MakePointerGEN< int >( this, 0x38 ); }
	inline int* nEffects() { return MakePointerGEN< int >( this, 0x40 ); }
};
struct GenDT_TEMuzzleFlash : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecAngles() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline float* flScale() { return MakePointerGEN< float >( this, 0x28 ); }
	inline int* nType() { return MakePointerGEN< int >( this, 0x2c ); }
};
struct GenDT_TELargeFunnel : public GenDT_TEParticleSystem
{
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* nReversed() { return MakePointerGEN< int >( this, 0x20 ); }
};
struct GenDT_TEKillPlayerAttachments : public GenDT_BaseTempEntity
{
	inline int* nPlayer() { return MakePointerGEN< int >( this, 0x10 ); }
};
struct GenDT_TEImpact : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecNormal() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* iType() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* ucFlags() { return MakePointerGEN< int >( this, 0x2c ); }
};
struct GenDT_TEGlowSprite : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* fScale() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* fLife() { return MakePointerGEN< int >( this, 0x24 ); }
	inline int* nBrightness() { return MakePointerGEN< int >( this, 0x28 ); }
};
struct GenDT_TEShatterSurface : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecAngles() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline Vector* vecForce() { return MakePointerGEN< Vector >( this, 0x28 ); }
	inline Vector* vecForcePos() { return MakePointerGEN< Vector >( this, 0x34 ); }
	inline float* flWidth() { return MakePointerGEN< float >( this, 0x40 ); }
	inline float* flHeight() { return MakePointerGEN< float >( this, 0x44 ); }
	inline float* flShardSize() { return MakePointerGEN< float >( this, 0x48 ); }
	inline int* nSurfaceType() { return MakePointerGEN< int >( this, 0x50 ); }
	inline uchar* uchFrontColor0() { return MakePointerGEN< uchar >( this, 0x54 ); }
	inline uchar* uchFrontColor1() { return MakePointerGEN< uchar >( this, 0x55 ); }
	inline uchar* uchFrontColor2() { return MakePointerGEN< uchar >( this, 0x56 ); }
	inline uchar* uchBackColor0() { return MakePointerGEN< uchar >( this, 0x57 ); }
	inline uchar* uchBackColor1() { return MakePointerGEN< uchar >( this, 0x58 ); }
	inline uchar* uchBackColor2() { return MakePointerGEN< uchar >( this, 0x59 ); }
};
struct GenDT_TEFootprintDecal : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecDirection() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* nEntity() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* nIndex() { return MakePointerGEN< int >( this, 0x38 ); }
	inline char* chMaterialType() { return MakePointerGEN< char >( this, 0x3c ); }
};
struct GenDT_TEFizz : public GenDT_BaseTempEntity
{
	inline int* nEntity() { return MakePointerGEN< int >( this, 0x10 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x14 ); }
	inline int* nDensity() { return MakePointerGEN< int >( this, 0x18 ); }
	inline int* nCurrent() { return MakePointerGEN< int >( this, 0x1c ); }
};
struct GenDT_TEExplosion : public GenDT_TEParticleSystem
{
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* fScale() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* nFrameRate() { return MakePointerGEN< int >( this, 0x24 ); }
	inline int* nFlags() { return MakePointerGEN< int >( this, 0x28 ); }
	inline Vector* vecNormal() { return MakePointerGEN< Vector >( this, 0x2c ); }
	inline char* chMaterialType() { return MakePointerGEN< char >( this, 0x38 ); }
	inline int* nRadius() { return MakePointerGEN< int >( this, 0x3c ); }
	inline int* nMagnitude() { return MakePointerGEN< int >( this, 0x40 ); }
};
struct GenDT_TEEnergySplash
{
	inline Vector* vecPos() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecDir() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline bool* bExplosive() { return MakePointerGEN< bool >( this, 0x28 ); }
};
struct GenDT_TEEffectDispatch : public GenDT_BaseTempEntity
{
	struct CEffectData
	{
		inline float* vOrigin0() { return MakePointerGEN< float >( this, 0x0 ); }
		inline float* vOrigin1() { return MakePointerGEN< float >( this, 0x4 ); }
		inline float* vOrigin2() { return MakePointerGEN< float >( this, 0x8 ); }
		inline float* vStart0() { return MakePointerGEN< float >( this, 0xc ); }
		inline float* vStart1() { return MakePointerGEN< float >( this, 0x10 ); }
		inline float* vStart2() { return MakePointerGEN< float >( this, 0x14 ); }
		inline Vector* vAngles() { return MakePointerGEN< Vector >( this, 0x24 ); }
		inline Vector* vNormal() { return MakePointerGEN< Vector >( this, 0x18 ); }
		inline int* fFlags() { return MakePointerGEN< int >( this, 0x30 ); }
		inline float* flMagnitude() { return MakePointerGEN< float >( this, 0x3c ); }
		inline float* flScale() { return MakePointerGEN< float >( this, 0x38 ); }
		inline int* nAttachmentIndex() { return MakePointerGEN< int >( this, 0x44 ); }
		inline int* nSurfaceProp() { return MakePointerGEN< int >( this, 0x48 ); }
		inline int* iEffectName() { return MakePointerGEN< int >( this, 0x88 ); }
		inline int* nMaterial() { return MakePointerGEN< int >( this, 0x4c ); }
		inline int* nDamageType() { return MakePointerGEN< int >( this, 0x50 ); }
		inline int* nHitBox() { return MakePointerGEN< int >( this, 0x54 ); }
		inline int* entindex() { return MakePointerGEN< int >( this, 0x0 ); }
		inline int* nColor() { return MakePointerGEN< int >( this, 0x58 ); }
		inline float* flRadius() { return MakePointerGEN< float >( this, 0x40 ); }
		inline bool* bCustomColors() { return MakePointerGEN< bool >( this, 0x59 ); }
		inline Vector* CustomColors_m_vecColor1() { return MakePointerGEN< Vector >( this, 0x5c ); }
		inline Vector* CustomColors_m_vecColor2() { return MakePointerGEN< Vector >( this, 0x68 ); }
		inline bool* bControlPoint1() { return MakePointerGEN< bool >( this, 0x74 ); }
		inline int* ControlPoint1_m_eParticleAttachment() { return MakePointerGEN< int >( this, 0x78 ); }
		inline float* ControlPoint1_m_vecOffset0() { return MakePointerGEN< float >( this, 0x7c ); }
		inline float* ControlPoint1_m_vecOffset1() { return MakePointerGEN< float >( this, 0x80 ); }
		inline float* ControlPoint1_m_vecOffset2() { return MakePointerGEN< float >( this, 0x84 ); }
	};
	inline CEffectData* EffectData() { return MakePointerGEN< CEffectData >( this, 0x10 ); }
};
struct GenDT_TEDynamicLight : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline int* r() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* g() { return MakePointerGEN< int >( this, 0x24 ); }
	inline int* b() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* exponent() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* fRadius() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* fTime() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* fDecay() { return MakePointerGEN< int >( this, 0x34 ); }
};
struct GenDT_TEDecal : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecStart() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* nEntity() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* nHitbox() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* nIndex() { return MakePointerGEN< int >( this, 0x30 ); }
};
struct GenDT_TEClientProjectile : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecVelocity() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* nLifeTime() { return MakePointerGEN< int >( this, 0x2c ); }
	inline EHANDLE* hOwner() { return MakePointerGEN< EHANDLE >( this, 0x30 ); }
};
struct GenDT_TEBubbleTrail : public GenDT_BaseTempEntity
{
	inline Vector* vecMins() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecMaxs() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x2c ); }
	inline float* flWaterZ() { return MakePointerGEN< float >( this, 0x28 ); }
	inline int* nCount() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* fSpeed() { return MakePointerGEN< int >( this, 0x34 ); }
};
struct GenDT_TEBubbles : public GenDT_BaseTempEntity
{
	inline Vector* vecMins() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecMaxs() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* fHeight() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* nCount() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* fSpeed() { return MakePointerGEN< int >( this, 0x34 ); }
};
struct GenDT_TEBSPDecal : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline int* nEntity() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* nIndex() { return MakePointerGEN< int >( this, 0x20 ); }
};
struct GenDT_TEBreakModel : public GenDT_BaseTempEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline QAngle* angRotation0() { return MakePointerGEN< QAngle >( this, 0x1c ); }
	inline QAngle* angRotation1() { return MakePointerGEN< QAngle >( this, 0x20 ); }
	inline QAngle* angRotation2() { return MakePointerGEN< QAngle >( this, 0x24 ); }
	inline Vector* vecSize() { return MakePointerGEN< Vector >( this, 0x28 ); }
	inline Vector* vecVelocity() { return MakePointerGEN< Vector >( this, 0x34 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x44 ); }
	inline int* nRandomization() { return MakePointerGEN< int >( this, 0x40 ); }
	inline int* nCount() { return MakePointerGEN< int >( this, 0x48 ); }
	inline int* fTime() { return MakePointerGEN< int >( this, 0x4c ); }
	inline int* nFlags() { return MakePointerGEN< int >( this, 0x50 ); }
};
struct GenDT_TEBloodStream : public GenDT_TEParticleSystem
{
	inline Vector* vecDirection() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* r() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* g() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* b() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* a() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* nAmount() { return MakePointerGEN< int >( this, 0x38 ); }
};
struct GenDT_TEBloodSprite
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecDirection() { return MakePointerGEN< Vector >( this, 0x1c ); }
	inline int* r() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* g() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* b() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* a() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* nSprayModel() { return MakePointerGEN< int >( this, 0x3c ); }
	inline int* nDropModel() { return MakePointerGEN< int >( this, 0x38 ); }
	inline int* nSize() { return MakePointerGEN< int >( this, 0x40 ); }
};
struct GenDT_TEBeamSpline
{
	inline int* nPoints() { return MakePointerGEN< int >( this, 0xd0 ); }
	inline Vector* vecPoints0() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecPoints() { return MakePointerGEN< Vector >( this, 0x0 ); } // Array size = 16
};
struct GenDT_BaseBeam
{
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x10 ); }
	inline int* nHaloIndex() { return MakePointerGEN< int >( this, 0x14 ); }
	inline int* nStartFrame() { return MakePointerGEN< int >( this, 0x18 ); }
	inline int* nFrameRate() { return MakePointerGEN< int >( this, 0x1c ); }
	inline int* fLife() { return MakePointerGEN< int >( this, 0x20 ); }
	inline int* fWidth() { return MakePointerGEN< int >( this, 0x24 ); }
	inline int* fEndWidth() { return MakePointerGEN< int >( this, 0x28 ); }
	inline int* nFadeLength() { return MakePointerGEN< int >( this, 0x2c ); }
	inline int* fAmplitude() { return MakePointerGEN< int >( this, 0x30 ); }
	inline int* nSpeed() { return MakePointerGEN< int >( this, 0x44 ); }
	inline int* r() { return MakePointerGEN< int >( this, 0x34 ); }
	inline int* g() { return MakePointerGEN< int >( this, 0x38 ); }
	inline int* b() { return MakePointerGEN< int >( this, 0x3c ); }
	inline int* a() { return MakePointerGEN< int >( this, 0x40 ); }
	inline int* nFlags() { return MakePointerGEN< int >( this, 0x48 ); }
};
struct GenDT_TEBeamRingPoint : public GenDT_BaseBeam
{
	inline Vector* vecCenter() { return MakePointerGEN< Vector >( this, 0x4c ); }
	inline float* flStartRadius() { return MakePointerGEN< float >( this, 0x58 ); }
	inline float* flEndRadius() { return MakePointerGEN< float >( this, 0x5c ); }
};
struct GenDT_TEBeamRing : public GenDT_BaseBeam
{
	inline int* nStartEntity() { return MakePointerGEN< int >( this, 0x4c ); }
	inline int* nEndEntity() { return MakePointerGEN< int >( this, 0x50 ); }
};
struct GenDT_TEBeamPoints : public GenDT_BaseBeam
{
	inline Vector* vecStartPoint() { return MakePointerGEN< Vector >( this, 0x4c ); }
	inline Vector* vecEndPoint() { return MakePointerGEN< Vector >( this, 0x58 ); }
};
struct GenDT_TEBeamLaser : public GenDT_BaseBeam
{
	inline int* nStartEntity() { return MakePointerGEN< int >( this, 0x4c ); }
	inline int* nEndEntity() { return MakePointerGEN< int >( this, 0x50 ); }
};
struct GenDT_TEBeamFollow : public GenDT_BaseBeam
{
	inline int* iEntIndex() { return MakePointerGEN< int >( this, 0x4c ); }
};
struct GenDT_TEBeamEnts : public GenDT_BaseBeam
{
	inline int* nStartEntity() { return MakePointerGEN< int >( this, 0x4c ); }
	inline int* nEndEntity() { return MakePointerGEN< int >( this, 0x50 ); }
};
struct GenDT_TEBeamEntPoint : public GenDT_BaseBeam
{
	inline int* nStartEntity() { return MakePointerGEN< int >( this, 0x4c ); }
	inline int* nEndEntity() { return MakePointerGEN< int >( this, 0x50 ); }
	inline Vector* vecStartPoint() { return MakePointerGEN< Vector >( this, 0x54 ); }
	inline Vector* vecEndPoint() { return MakePointerGEN< Vector >( this, 0x60 ); }
};
struct GenDT_TEMetalSparks
{
	inline Vector* vecPos() { return MakePointerGEN< Vector >( this, 0x10 ); }
	inline Vector* vecDir() { return MakePointerGEN< Vector >( this, 0x1c ); }
};
struct GenDT_TEArmorRicochet : public GenDT_TEMetalSparks
{
};
struct GenDT_SteamJet : public GenDT_BaseParticleEntity
{
	inline float* SpreadSpeed() { return MakePointerGEN< float >( this, 0x594 ); }
	inline float* Speed() { return MakePointerGEN< float >( this, 0x598 ); }
	inline float* StartSize() { return MakePointerGEN< float >( this, 0x59c ); }
	inline float* EndSize() { return MakePointerGEN< float >( this, 0x5a0 ); }
	inline float* Rate() { return MakePointerGEN< float >( this, 0x5a4 ); }
	inline float* JetLength() { return MakePointerGEN< float >( this, 0x5a8 ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5ac ); }
	inline bool* bFaceLeft() { return MakePointerGEN< bool >( this, 0x5b4 ); }
	inline int* nType() { return MakePointerGEN< int >( this, 0x5b0 ); }
	inline int* spawnflags() { return MakePointerGEN< int >( this, 0x5b8 ); }
	inline float* flRollSpeed() { return MakePointerGEN< float >( this, 0x5bc ); }
};
struct GenDT_SmokeStack : public GenDT_BaseParticleEntity
{
	inline float* SpreadSpeed() { return MakePointerGEN< float >( this, 0x5e4 ); }
	inline float* Speed() { return MakePointerGEN< float >( this, 0x5e8 ); }
	inline float* StartSize() { return MakePointerGEN< float >( this, 0x5ec ); }
	inline float* EndSize() { return MakePointerGEN< float >( this, 0x5f0 ); }
	inline float* Rate() { return MakePointerGEN< float >( this, 0x5f4 ); }
	inline float* JetLength() { return MakePointerGEN< float >( this, 0x5f8 ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5fc ); }
	inline float* flBaseSpread() { return MakePointerGEN< float >( this, 0x600 ); }
	inline float* flTwist() { return MakePointerGEN< float >( this, 0x654 ); }
	inline float* flRollSpeed() { return MakePointerGEN< float >( this, 0x690 ); }
	inline int* iMaterialModel() { return MakePointerGEN< int >( this, 0x658 ); }
	inline Vector* AmbientLight_m_vPos() { return MakePointerGEN< Vector >( this, 0x604 ); }
	inline Vector* AmbientLight_m_vColor() { return MakePointerGEN< Vector >( this, 0x610 ); }
	inline float* AmbientLight_m_flIntensity() { return MakePointerGEN< float >( this, 0x61c ); }
	inline Vector* DirLight_m_vPos() { return MakePointerGEN< Vector >( this, 0x620 ); }
	inline Vector* DirLight_m_vColor() { return MakePointerGEN< Vector >( this, 0x62c ); }
	inline float* DirLight_m_flIntensity() { return MakePointerGEN< float >( this, 0x638 ); }
	inline Vector* vWind() { return MakePointerGEN< Vector >( this, 0x648 ); }
};
struct GenDT_DustTrail : public GenDT_BaseParticleEntity
{
	inline float* SpawnRate() { return MakePointerGEN< float >( this, 0x594 ); }
	inline Vector* Color() { return MakePointerGEN< Vector >( this, 0x598 ); }
	inline float* ParticleLifetime() { return MakePointerGEN< float >( this, 0x5a8 ); }
	inline float* StopEmitTime() { return MakePointerGEN< float >( this, 0x5b0 ); }
	inline float* MinSpeed() { return MakePointerGEN< float >( this, 0x5b4 ); }
	inline float* MaxSpeed() { return MakePointerGEN< float >( this, 0x5b8 ); }
	inline float* MinDirectedSpeed() { return MakePointerGEN< float >( this, 0x5bc ); }
	inline float* MaxDirectedSpeed() { return MakePointerGEN< float >( this, 0x5c0 ); }
	inline float* StartSize() { return MakePointerGEN< float >( this, 0x5c4 ); }
	inline float* EndSize() { return MakePointerGEN< float >( this, 0x5c8 ); }
	inline float* SpawnRadius() { return MakePointerGEN< float >( this, 0x5cc ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5dc ); }
	inline float* Opacity() { return MakePointerGEN< float >( this, 0x5a4 ); }
};
struct GenDT_FireTrail : public GenDT_BaseParticleEntity
{
	inline int* nAttachment() { return MakePointerGEN< int >( this, 0x594 ); }
	inline float* flLifetime() { return MakePointerGEN< float >( this, 0x598 ); }
};
struct GenDT_SporeTrail : public GenDT_BaseParticleEntity
{
	inline float* flSpawnRate() { return MakePointerGEN< float >( this, 0x59c ); }
	inline Vector* vecEndColor() { return MakePointerGEN< Vector >( this, 0x590 ); }
	inline float* flParticleLifetime() { return MakePointerGEN< float >( this, 0x5a0 ); }
	inline float* flStartSize() { return MakePointerGEN< float >( this, 0x5a4 ); }
	inline float* flEndSize() { return MakePointerGEN< float >( this, 0x5a8 ); }
	inline float* flSpawnRadius() { return MakePointerGEN< float >( this, 0x5ac ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5bc ); }
};
struct GenDT_SporeExplosion : public GenDT_BaseParticleEntity
{
	inline float* flSpawnRate() { return MakePointerGEN< float >( this, 0x594 ); }
	inline float* flParticleLifetime() { return MakePointerGEN< float >( this, 0x598 ); }
	inline float* flStartSize() { return MakePointerGEN< float >( this, 0x59c ); }
	inline float* flEndSize() { return MakePointerGEN< float >( this, 0x5a0 ); }
	inline float* flSpawnRadius() { return MakePointerGEN< float >( this, 0x5a4 ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5ac ); }
	inline bool* bDontRemove() { return MakePointerGEN< bool >( this, 0x5ad ); }
};
struct GenDT_RocketTrail : public GenDT_BaseParticleEntity
{
	inline float* SpawnRate() { return MakePointerGEN< float >( this, 0x594 ); }
	inline Vector* StartColor() { return MakePointerGEN< Vector >( this, 0x598 ); }
	inline Vector* EndColor() { return MakePointerGEN< Vector >( this, 0x5a4 ); }
	inline float* ParticleLifetime() { return MakePointerGEN< float >( this, 0x5b4 ); }
	inline float* StopEmitTime() { return MakePointerGEN< float >( this, 0x5b8 ); }
	inline float* MinSpeed() { return MakePointerGEN< float >( this, 0x5bc ); }
	inline float* MaxSpeed() { return MakePointerGEN< float >( this, 0x5c0 ); }
	inline float* StartSize() { return MakePointerGEN< float >( this, 0x5c4 ); }
	inline float* EndSize() { return MakePointerGEN< float >( this, 0x5c8 ); }
	inline float* SpawnRadius() { return MakePointerGEN< float >( this, 0x5cc ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5dc ); }
	inline int* nAttachment() { return MakePointerGEN< int >( this, 0x5e0 ); }
	inline float* Opacity() { return MakePointerGEN< float >( this, 0x5b0 ); }
	inline bool* bDamaged() { return MakePointerGEN< bool >( this, 0x5dd ); }
	inline float* flFlareScale() { return MakePointerGEN< float >( this, 0x5f0 ); }
};
struct GenDT_SmokeTrail : public GenDT_BaseParticleEntity
{
	inline float* SpawnRate() { return MakePointerGEN< float >( this, 0x594 ); }
	inline Vector* StartColor() { return MakePointerGEN< Vector >( this, 0x598 ); }
	inline Vector* EndColor() { return MakePointerGEN< Vector >( this, 0x5a4 ); }
	inline float* ParticleLifetime() { return MakePointerGEN< float >( this, 0x5b4 ); }
	inline float* StopEmitTime() { return MakePointerGEN< float >( this, 0x5b8 ); }
	inline float* MinSpeed() { return MakePointerGEN< float >( this, 0x5bc ); }
	inline float* MaxSpeed() { return MakePointerGEN< float >( this, 0x5c0 ); }
	inline float* MinDirectedSpeed() { return MakePointerGEN< float >( this, 0x5c4 ); }
	inline float* MaxDirectedSpeed() { return MakePointerGEN< float >( this, 0x5c8 ); }
	inline float* StartSize() { return MakePointerGEN< float >( this, 0x5cc ); }
	inline float* EndSize() { return MakePointerGEN< float >( this, 0x5d0 ); }
	inline float* SpawnRadius() { return MakePointerGEN< float >( this, 0x5d4 ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x5e4 ); }
	inline int* nAttachment() { return MakePointerGEN< int >( this, 0x5e8 ); }
	inline float* Opacity() { return MakePointerGEN< float >( this, 0x5b0 ); }
};
struct GenDT_PropVehicleDriveable : public GenDT_BaseAnimating
{
	inline EHANDLE* hPlayer() { return MakePointerGEN< EHANDLE >( this, 0x7ec ); }
	inline int* nSpeed() { return MakePointerGEN< int >( this, 0x7f0 ); }
	inline int* nRPM() { return MakePointerGEN< int >( this, 0x7f4 ); }
	inline float* flThrottle() { return MakePointerGEN< float >( this, 0x7f8 ); }
	inline int* nBoostTimeLeft() { return MakePointerGEN< int >( this, 0x7fc ); }
	inline int* nHasBoost() { return MakePointerGEN< int >( this, 0x800 ); }
	inline int* nScannerDisabledWeapons() { return MakePointerGEN< int >( this, 0x804 ); }
	inline int* nScannerDisabledVehicle() { return MakePointerGEN< int >( this, 0x808 ); }
	inline bool* bEnterAnimOn() { return MakePointerGEN< bool >( this, 0x828 ); }
	inline bool* bExitAnimOn() { return MakePointerGEN< bool >( this, 0x829 ); }
	inline bool* bUnableToFire() { return MakePointerGEN< bool >( this, 0x875 ); }
	inline Vector* vecEyeExitEndpoint() { return MakePointerGEN< Vector >( this, 0x868 ); }
	inline bool* bHasGun() { return MakePointerGEN< bool >( this, 0x874 ); }
	inline Vector* vecGunCrosshair() { return MakePointerGEN< Vector >( this, 0x830 ); }
};
struct GenDT_ParticleSmokeGrenade : public GenDT_BaseParticleEntity
{
	inline float* flSpawnTime() { return MakePointerGEN< float >( this, 0x5a4 ); }
	inline float* FadeStartTime() { return MakePointerGEN< float >( this, 0x5a8 ); }
	inline float* FadeEndTime() { return MakePointerGEN< float >( this, 0x5ac ); }
	inline int* CurrentStage() { return MakePointerGEN< int >( this, 0x594 ); }
};
struct GenDT_ParticleFire
{
	inline Vector* vOrigin() { return MakePointerGEN< Vector >( this, 0x59c ); }
	inline Vector* vDirection() { return MakePointerGEN< Vector >( this, 0x5a8 ); }
};
struct GenDT_MovieExplosion : public GenDT_BaseParticleEntity
{
};
struct GenDT_TEGaussExplosion : public GenDT_TEParticleSystem
{
	inline int* nType() { return MakePointerGEN< int >( this, 0x1c ); }
	inline Vector* vecDirection() { return MakePointerGEN< Vector >( this, 0x20 ); }
};
struct GenDT_QuadraticBeam : public GenDT_BaseEntity
{
	inline Vector* targetPosition() { return MakePointerGEN< Vector >( this, 0x4a8 ); }
	inline Vector* controlPosition() { return MakePointerGEN< Vector >( this, 0x4b4 ); }
	inline float* scrollRate() { return MakePointerGEN< float >( this, 0x4c0 ); }
	inline float* flWidth() { return MakePointerGEN< float >( this, 0x4c4 ); }
};
struct GenDT_Embers : public GenDT_BaseEntity
{
	inline int* nDensity() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline int* nLifetime() { return MakePointerGEN< int >( this, 0x4ac ); }
	inline int* nSpeed() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline bool* bEmit() { return MakePointerGEN< bool >( this, 0x4b4 ); }
};
struct GenDT_EnvWind : public GenDT_BaseEntity
{
	struct CEnvWindShared
	{
		inline int* iMinWind() { return MakePointerGEN< int >( this, 0xc ); }
		inline int* iMaxWind() { return MakePointerGEN< int >( this, 0x10 ); }
		inline int* iMinGust() { return MakePointerGEN< int >( this, 0x14 ); }
		inline int* iMaxGust() { return MakePointerGEN< int >( this, 0x18 ); }
		inline float* flMinGustDelay() { return MakePointerGEN< float >( this, 0x1c ); }
		inline float* flMaxGustDelay() { return MakePointerGEN< float >( this, 0x20 ); }
		inline int* iGustDirChange() { return MakePointerGEN< int >( this, 0x28 ); }
		inline int* iWindSeed() { return MakePointerGEN< int >( this, 0x8 ); }
		inline int* iInitialWindDir() { return MakePointerGEN< int >( this, 0x38 ); }
		inline float* flInitialWindSpeed() { return MakePointerGEN< float >( this, 0x3c ); }
		inline float* flStartTime() { return MakePointerGEN< float >( this, 0x4 ); }
		inline float* flGustDuration() { return MakePointerGEN< float >( this, 0x24 ); }
	};
	inline CEnvWindShared* EnvWindShared() { return MakePointerGEN< CEnvWindShared >( this, 0x4a8 ); }
};
struct GenDT_Precipitation : public GenDT_BaseEntity
{
	inline int* nPrecipType() { return MakePointerGEN< int >( this, 0x4d0 ); }
};
struct GenDT_HandleTest : public GenDT_BaseEntity
{
	inline int* Handle() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline bool* bSendHandle() { return MakePointerGEN< bool >( this, 0x4ac ); }
};
struct GenDT_TeamplayRoundBasedRulesProxy : public GenDT_GameRulesProxy
{
	struct CTeamplayRoundBasedRules
	{
		inline int* iRoundState() { return MakePointerGEN< int >( this, 0x28 ); }
		inline bool* bInWaitingForPlayers() { return MakePointerGEN< bool >( this, 0x38 ); }
		inline int* iWinningTeam() { return MakePointerGEN< int >( this, 0x30 ); }
		inline bool* bInOvertime() { return MakePointerGEN< bool >( this, 0x2c ); }
		inline bool* bInSetup() { return MakePointerGEN< bool >( this, 0x2d ); }
		inline bool* bSwitchedTeamsThisRound() { return MakePointerGEN< bool >( this, 0x2e ); }
		inline bool* bAwaitingReadyRestart() { return MakePointerGEN< bool >( this, 0x39 ); }
		inline float* flRestartRoundTime() { return MakePointerGEN< float >( this, 0x3c ); }
		inline float* flMapResetTime() { return MakePointerGEN< float >( this, 0x40 ); }
		inline float* flNextRespawnWave() { return MakePointerGEN< float >( this, 0x44 ); } // Array size = 32
		inline bool* bTeamReady() { return MakePointerGEN< bool >( this, 0xc4 ); } // Array size = 32
		inline bool* bStopWatch() { return MakePointerGEN< bool >( this, 0xe4 ); }
		inline bool* bMultipleTrains() { return MakePointerGEN< bool >( this, 0xe5 ); }
	}; // Fail count = 1
	inline CTeamplayRoundBasedRules* teamplayroundbased_gamerules_data() { return MakePointerGEN< CTeamplayRoundBasedRules >( this, 0x0 ); }
};
struct GenDT_Sprite : public GenDT_BaseEntity
{
	inline EHANDLE* hAttachedToEntity() { return MakePointerGEN< EHANDLE >( this, 0x4b8 ); }
	inline int* nAttachment() { return MakePointerGEN< int >( this, 0x4bc ); }
	inline float* flScaleTime() { return MakePointerGEN< float >( this, 0x4d8 ); }
	inline float* flSpriteScale() { return MakePointerGEN< float >( this, 0x4d4 ); }
	inline float* flSpriteFramerate() { return MakePointerGEN< float >( this, 0x4c0 ); }
	inline float* flGlowProxySize() { return MakePointerGEN< float >( this, 0x4e0 ); }
	inline float* flHDRColorScale() { return MakePointerGEN< float >( this, 0x4e4 ); }
	inline float* flFrame() { return MakePointerGEN< float >( this, 0x4c4 ); }
	inline float* flBrightnessTime() { return MakePointerGEN< float >( this, 0x4d0 ); }
	inline int* nBrightness() { return MakePointerGEN< int >( this, 0x4cc ); }
	inline bool* bWorldSpaceScale() { return MakePointerGEN< bool >( this, 0x4dc ); }
};
struct GenDT_SpriteTrail : public GenDT_Sprite
{
	inline float* flLifeTime() { return MakePointerGEN< float >( this, 0xb3c ); }
	inline float* flStartWidth() { return MakePointerGEN< float >( this, 0xb40 ); }
	inline float* flEndWidth() { return MakePointerGEN< float >( this, 0xb44 ); }
	inline float* flStartWidthVariance() { return MakePointerGEN< float >( this, 0xb48 ); }
	inline float* flTextureRes() { return MakePointerGEN< float >( this, 0xb4c ); }
	inline float* flMinFadeLength() { return MakePointerGEN< float >( this, 0xb50 ); }
	inline Vector* vecSkyboxOrigin() { return MakePointerGEN< Vector >( this, 0xb54 ); }
	inline float* flSkyboxScale() { return MakePointerGEN< float >( this, 0xb60 ); }
};
struct GenDT_SpriteOriented : public GenDT_Sprite
{
};
struct GenDT_Ragdoll : public GenDT_BaseAnimating
{
	inline Vector* ragAngles0() { return MakePointerGEN< Vector >( this, 0x908 ); }
	inline Vector* ragPos0() { return MakePointerGEN< Vector >( this, 0x7e8 ); }
	inline EHANDLE* hUnragdoll() { return MakePointerGEN< EHANDLE >( this, 0xae4 ); }
	inline float* flBlendWeight() { return MakePointerGEN< float >( this, 0xae8 ); }
	inline int* nOverlaySequence() { return MakePointerGEN< int >( this, 0xaf0 ); }
}; // Fail count = 2
struct GenDT_Ragdoll_Attached : public GenDT_Ragdoll
{
	inline bool* boneIndexAttached() { return MakePointerGEN< bool >( this, 0xb20 ); }
	inline int* ragdollAttachedObjectIndex() { return MakePointerGEN< int >( this, 0xb1c ); }
	inline Vector* attachmentPointBoneSpace() { return MakePointerGEN< Vector >( this, 0xaf8 ); }
	inline Vector* attachmentPointRagdollSpace() { return MakePointerGEN< Vector >( this, 0xb10 ); }
};
struct GenDT_PoseController : public GenDT_BaseEntity
{
	inline EHANDLE* hProps() { return MakePointerGEN< EHANDLE >( this, 0x4a8 ); } // Array size = 4
	inline char* chPoseIndex() { return MakePointerGEN< char >( this, 0x4b8 ); } // Array size = 4
	inline bool* bPoseValueParity() { return MakePointerGEN< bool >( this, 0x4bc ); }
	inline int* fPoseValue() { return MakePointerGEN< int >( this, 0x4c0 ); }
	inline int* fInterpolationTime() { return MakePointerGEN< int >( this, 0x4c4 ); }
	inline bool* bInterpolationWrap() { return MakePointerGEN< bool >( this, 0x4c8 ); }
	inline int* fCycleFrequency() { return MakePointerGEN< int >( this, 0x4cc ); }
	inline int* nFModType() { return MakePointerGEN< int >( this, 0x4d0 ); }
	inline int* fFModTimeOffset() { return MakePointerGEN< int >( this, 0x4d4 ); }
	inline int* fFModRate() { return MakePointerGEN< int >( this, 0x4d8 ); }
	inline int* fFModAmplitude() { return MakePointerGEN< int >( this, 0x4dc ); }
};
struct GenDT_InfoLadderDismount : public GenDT_BaseEntity
{
};
struct GenDT_FuncLadder : public GenDT_BaseEntity
{
	inline Vector* vecPlayerMountPositionTop() { return MakePointerGEN< Vector >( this, 0x4c8 ); }
	inline Vector* vecPlayerMountPositionBottom() { return MakePointerGEN< Vector >( this, 0x4d4 ); }
	inline Vector* vecLadderDir() { return MakePointerGEN< Vector >( this, 0x4a8 ); }
	inline bool* bFakeLadder() { return MakePointerGEN< bool >( this, 0x4e1 ); }
};
struct GenDT_DetailController
{
	inline float* flFadeStartDist() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* flFadeEndDist() { return MakePointerGEN< float >( this, 0x4ac ); }
};
struct GenDT_World : public GenDT_BaseEntity
{
	inline float* flWaveHeight() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline Vector* WorldMins() { return MakePointerGEN< Vector >( this, 0x4ac ); }
	inline Vector* WorldMaxs() { return MakePointerGEN< Vector >( this, 0x4b8 ); }
	inline bool* bStartDark() { return MakePointerGEN< bool >( this, 0x4c4 ); }
	inline float* flMaxOccludeeArea() { return MakePointerGEN< float >( this, 0x4c8 ); }
	inline float* flMinOccluderArea() { return MakePointerGEN< float >( this, 0x4cc ); }
	inline float* flMaxPropScreenSpaceWidth() { return MakePointerGEN< float >( this, 0x4d4 ); }
	inline float* flMinPropScreenSpaceWidth() { return MakePointerGEN< float >( this, 0x4d0 ); }
	inline int* iszDetailSpriteMaterial() { return MakePointerGEN< int >( this, 0x4d9 ); }
	inline bool* bColdWorld() { return MakePointerGEN< bool >( this, 0x4d8 ); }
};
struct GenDT_WaterLODControl : public GenDT_BaseEntity
{
	inline float* flCheapWaterStartDistance() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* flCheapWaterEndDistance() { return MakePointerGEN< float >( this, 0x4ac ); }
};
struct GenDT_WaterBullet : public GenDT_BaseAnimating
{
};
struct GenDT_VoteController : public GenDT_BaseEntity
{
	inline int* iActiveIssueIndex() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline int* iOnlyTeamToVote() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* nVoteOptionCount() { return MakePointerGEN< int >( this, 0x4b8 ); } // Array size = 5
	inline int* nPotentialVotes() { return MakePointerGEN< int >( this, 0x4d0 ); }
	inline bool* bIsYesNoVote() { return MakePointerGEN< bool >( this, 0x4d6 ); }
};
struct GenDT_VGuiScreen : public GenDT_BaseEntity
{
	inline float* flWidth() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline float* flHeight() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline int* fScreenFlags() { return MakePointerGEN< int >( this, 0x4dc ); }
	inline int* nPanelName() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline int* nAttachmentIndex() { return MakePointerGEN< int >( this, 0x4d4 ); }
	inline int* nOverlayMaterial() { return MakePointerGEN< int >( this, 0x4d8 ); }
	inline EHANDLE* hPlayerOwner() { return MakePointerGEN< EHANDLE >( this, 0x538 ); }
};
struct GenDT_PropJeep : public GenDT_PropVehicleDriveable
{
	inline bool* bHeadlightIsOn() { return MakePointerGEN< bool >( this, 0x934 ); }
};
struct GenDT_BreakableProp : public GenDT_BaseAnimating
{
};
struct GenDT_DynamicProp : public GenDT_BreakableProp
{
	inline bool* bUseHitboxesForRenderBox() { return MakePointerGEN< bool >( this, 0x7e8 ); }
};
struct GenDT_PropVehicleChoreoGeneric : public GenDT_DynamicProp
{
	inline EHANDLE* hPlayer() { return MakePointerGEN< EHANDLE >( this, 0x80c ); }
	inline bool* bEnterAnimOn() { return MakePointerGEN< bool >( this, 0x814 ); }
	inline bool* bExitAnimOn() { return MakePointerGEN< bool >( this, 0x815 ); }
	inline Vector* vecEyeExitEndpoint() { return MakePointerGEN< Vector >( this, 0x818 ); }
	inline int* vehicleView_bClampEyeAngles() { return MakePointerGEN< int >( this, 0x8a4 ); }
	inline float* vehicleView_flPitchCurveZero() { return MakePointerGEN< float >( this, 0x8a8 ); }
	inline float* vehicleView_flPitchCurveLinear() { return MakePointerGEN< float >( this, 0x8ac ); }
	inline float* vehicleView_flRollCurveZero() { return MakePointerGEN< float >( this, 0x8b0 ); }
	inline float* vehicleView_flRollCurveLinear() { return MakePointerGEN< float >( this, 0x8b4 ); }
	inline float* vehicleView_flFOV() { return MakePointerGEN< float >( this, 0x8b8 ); }
	inline float* vehicleView_flYawMin() { return MakePointerGEN< float >( this, 0x8bc ); }
	inline float* vehicleView_flYawMax() { return MakePointerGEN< float >( this, 0x8c0 ); }
	inline float* vehicleView_flPitchMin() { return MakePointerGEN< float >( this, 0x8c4 ); }
	inline float* vehicleView_flPitchMax() { return MakePointerGEN< float >( this, 0x8c8 ); }
};
struct GenDT_ProxyToggle : public GenDT_BaseEntity
{
	struct CProxyToggle_ProxiedData
	{
		inline int* WithProxy() { return MakePointerGEN< int >( this, 0x4a8 ); }
	};
	inline CProxyToggle_ProxiedData* blah() { return MakePointerGEN< CProxyToggle_ProxiedData >( this, 0x0 ); }
};
struct GenDT_Tesla : public GenDT_BaseEntity
{
	inline int* iszSpriteName() { return MakePointerGEN< int >( this, 0x510 ); }
}; // Fail count = 1
struct GenDT_Sun
{
	inline int* clrRender() { return MakePointerGEN< int >( this, 0x58 ); }
	inline int* clrOverlay() { return MakePointerGEN< int >( this, 0x5f8 ); }
	inline Vector* vDirection() { return MakePointerGEN< Vector >( this, 0x604 ); }
	inline bool* bOn() { return MakePointerGEN< bool >( this, 0x610 ); }
	inline int* nSize() { return MakePointerGEN< int >( this, 0x5fc ); }
	inline int* nOverlaySize() { return MakePointerGEN< int >( this, 0x600 ); }
	inline int* nMaterial() { return MakePointerGEN< int >( this, 0x614 ); }
	inline int* nOverlayMaterial() { return MakePointerGEN< int >( this, 0x618 ); }
	inline float* HDRColorScale() { return MakePointerGEN< float >( this, 0x0 ); }
};
struct GenDT_ParticlePerformanceMonitor : public GenDT_BaseEntity
{
	inline bool* bMeasurePerf() { return MakePointerGEN< bool >( this, 0x4a9 ); }
	inline bool* bDisplayPerf() { return MakePointerGEN< bool >( this, 0x4a8 ); }
};
struct GenDT_SpotlightEnd : public GenDT_BaseEntity
{
	inline float* flLightScale() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* Radius() { return MakePointerGEN< float >( this, 0x4ac ); }
};
struct GenDT_SlideshowDisplay : public GenDT_BaseEntity
{
	inline bool* bEnabled() { return MakePointerGEN< bool >( this, 0x4a8 ); }
	inline char** szDisplayText() { return MakePointerGEN< char* >( this, 0x4a9 ); }
	inline char** szSlideshowDirectory() { return MakePointerGEN< char* >( this, 0x529 ); }
	inline char* chCurrentSlideLists() { return MakePointerGEN< char >( this, 0x5c0 ); } // Array size = 16
	inline int* fMinSlideTime() { return MakePointerGEN< int >( this, 0x5d8 ); }
	inline int* fMaxSlideTime() { return MakePointerGEN< int >( this, 0x5dc ); }
	inline int* iCycleType() { return MakePointerGEN< int >( this, 0x5e4 ); }
	inline bool* bNoListRepeats() { return MakePointerGEN< bool >( this, 0x5e8 ); }
};
struct GenDT_ShadowControl : public GenDT_BaseEntity
{
	inline Vector* shadowDirection() { return MakePointerGEN< Vector >( this, 0x4a8 ); }
	inline int* shadowColor() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline float* flShadowMaxDist() { return MakePointerGEN< float >( this, 0x4b8 ); }
	inline bool* bDisableShadows() { return MakePointerGEN< bool >( this, 0x4bc ); }
};
struct GenDT_SceneEntity : public GenDT_BaseEntity
{
	inline int* nSceneStringIndex() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline bool* bIsPlayingBack() { return MakePointerGEN< bool >( this, 0x4ac ); }
	inline bool* bPaused() { return MakePointerGEN< bool >( this, 0x4ad ); }
	inline bool* bMultiplayer() { return MakePointerGEN< bool >( this, 0x4ae ); }
	inline float* flForceClientTime() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline EHANDLE* hActorList() { return MakePointerGEN< EHANDLE >( this, 0x0 ); } // Array size = 17
};
struct GenDT_RopeKeyframe
{
	inline int* iRopeMaterialModelIndex() { return MakePointerGEN< int >( this, 0x4e4 ); }
	inline EHANDLE* hStartPoint() { return MakePointerGEN< EHANDLE >( this, 0x774 ); }
	inline EHANDLE* hEndPoint() { return MakePointerGEN< EHANDLE >( this, 0x778 ); }
	inline int* iStartAttachment() { return MakePointerGEN< int >( this, 0x77c ); }
	inline int* iEndAttachment() { return MakePointerGEN< int >( this, 0x77e ); }
	inline int* fLockedPoints() { return MakePointerGEN< int >( this, 0x790 ); }
	inline int* Slack() { return MakePointerGEN< int >( this, 0x788 ); }
	inline int* RopeLength() { return MakePointerGEN< int >( this, 0x784 ); }
	inline int* RopeFlags() { return MakePointerGEN< int >( this, 0x4e0 ); }
	inline float* TextureScale() { return MakePointerGEN< float >( this, 0x78c ); }
	inline int* nSegments() { return MakePointerGEN< int >( this, 0x770 ); }
	inline bool* bConstrainBetweenEndpoints() { return MakePointerGEN< bool >( this, 0x818 ); }
	inline int* Subdiv() { return MakePointerGEN< int >( this, 0x780 ); }
	inline float* Width() { return MakePointerGEN< float >( this, 0x794 ); }
	inline float* flScrollSpeed() { return MakePointerGEN< float >( this, 0x4dc ); }
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline int* moveparent() { return MakePointerGEN< int >( this, 0x15c ); }
	inline int* iParentAttachment() { return MakePointerGEN< int >( this, 0x146 ); }
};
struct GenDT_RagdollManager
{
	inline int* iCurrentMaxRagdollCount() { return MakePointerGEN< int >( this, 0x4a8 ); }
};
struct GenDT_PhysicsProp : public GenDT_BreakableProp
{
	inline bool* bAwake() { return MakePointerGEN< bool >( this, 0x7e8 ); }
};
struct GenDT_PhysicsPropMultiplayer : public GenDT_PhysicsProp
{
	inline int* iPhysicsMode() { return MakePointerGEN< int >( this, 0x7f4 ); }
	inline int* fMass() { return MakePointerGEN< int >( this, 0x7f8 ); }
	inline Vector* collisionMins() { return MakePointerGEN< Vector >( this, 0x7fc ); }
	inline Vector* collisionMaxs() { return MakePointerGEN< Vector >( this, 0x808 ); }
};
struct GenDT_PhysBox : public GenDT_BaseEntity
{
	inline float* mass() { return MakePointerGEN< float >( this, 0x4a8 ); }
};
struct GenDT_PhysBoxMultiplayer : public GenDT_PhysBox
{
	inline int* iPhysicsMode() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* fMass() { return MakePointerGEN< int >( this, 0x4b8 ); }
};
struct GenDT_BasePropDoor : public GenDT_DynamicProp
{
};
struct GenDT_PointCommentaryNode : public GenDT_BaseAnimating
{
	inline bool* bActive() { return MakePointerGEN< bool >( this, 0x7e8 ); }
	inline float* flStartTime() { return MakePointerGEN< float >( this, 0x7ec ); }
	inline int* iszCommentaryFile() { return MakePointerGEN< int >( this, 0x7f0 ); }
	inline int* iszCommentaryFileNoHDR() { return MakePointerGEN< int >( this, 0x8f4 ); }
	inline int* iszSpeakers() { return MakePointerGEN< int >( this, 0x9f8 ); }
	inline int* iNodeNumber() { return MakePointerGEN< int >( this, 0xaf8 ); }
	inline int* iNodeNumberMax() { return MakePointerGEN< int >( this, 0xafc ); }
	inline EHANDLE* hViewPosition() { return MakePointerGEN< EHANDLE >( this, 0xb04 ); }
};
struct GenDT_PointCamera : public GenDT_BaseEntity
{
	inline float* FOV() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* Resolution() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline bool* bFogEnable() { return MakePointerGEN< bool >( this, 0x4b0 ); }
	inline int* FogColor() { return MakePointerGEN< int >( this, 0x4b1 ); }
	inline float* flFogStart() { return MakePointerGEN< float >( this, 0x4b8 ); }
	inline float* flFogEnd() { return MakePointerGEN< float >( this, 0x4bc ); }
	inline float* flFogMaxDensity() { return MakePointerGEN< float >( this, 0x4c0 ); }
	inline bool* bActive() { return MakePointerGEN< bool >( this, 0x4c4 ); }
	inline bool* bUseScreenAspectRatio() { return MakePointerGEN< bool >( this, 0x4c5 ); }
};
struct GenDT_Plasma : public GenDT_BaseEntity
{
	inline float* flStartScale() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* flScale() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline float* flScaleTime() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline int* nFlags() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* nPlasmaModelIndex() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline int* nPlasmaModelIndex2() { return MakePointerGEN< int >( this, 0x4bc ); }
	inline int* nGlowModelIndex() { return MakePointerGEN< int >( this, 0x4c0 ); }
};
struct GenDT_PhysMagnet : public GenDT_BaseAnimating
{
};
struct GenDT_ParticleSystem
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline EHANDLE* hOwnerEntity() { return MakePointerGEN< EHANDLE >( this, 0x46c ); }
	inline int* moveparent() { return MakePointerGEN< int >( this, 0x15c ); }
	inline int* iParentAttachment() { return MakePointerGEN< int >( this, 0x146 ); }
	inline QAngle* angRotation() { return MakePointerGEN< QAngle >( this, 0x2d8 ); }
	inline int* iEffectIndex() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline bool* bActive() { return MakePointerGEN< bool >( this, 0x4ac ); }
	inline float* flStartTime() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline EHANDLE* hControlPointEnts() { return MakePointerGEN< EHANDLE >( this, 0x4b4 ); } // Array size = 63
	inline int* iControlPointParents() { return MakePointerGEN< int >( this, 0x5b0 ); } // Array size = 63
	inline bool* bWeatherEffect() { return MakePointerGEN< bool >( this, 0x5ef ); }
};
struct GenDT_MaterialModifyControl : public GenDT_BaseEntity
{
	inline char** szMaterialName() { return MakePointerGEN< char* >( this, 0x4a8 ); }
	inline char** szMaterialVar() { return MakePointerGEN< char* >( this, 0x5a7 ); }
	inline char** szMaterialVarValue() { return MakePointerGEN< char* >( this, 0x6a6 ); }
	inline int* iFrameStart() { return MakePointerGEN< int >( this, 0x7b0 ); }
	inline int* iFrameEnd() { return MakePointerGEN< int >( this, 0x7b4 ); }
	inline bool* bWrap() { return MakePointerGEN< bool >( this, 0x7b8 ); }
	inline float* flFramerate() { return MakePointerGEN< float >( this, 0x7bc ); }
	inline bool* bNewAnimCommandsSemaphore() { return MakePointerGEN< bool >( this, 0x7c0 ); }
	inline float* flFloatLerpStartValue() { return MakePointerGEN< float >( this, 0x7c4 ); }
	inline float* flFloatLerpEndValue() { return MakePointerGEN< float >( this, 0x7c8 ); }
	inline float* flFloatLerpTransitionTime() { return MakePointerGEN< float >( this, 0x7cc ); }
	inline bool* bFloatLerpWrap() { return MakePointerGEN< bool >( this, 0x7d0 ); }
	inline int* nModifyMode() { return MakePointerGEN< int >( this, 0x7d8 ); }
};
struct GenDT_LightGlow
{
	inline int* clrRender() { return MakePointerGEN< int >( this, 0x58 ); }
	inline int* nHorizontalSize() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline int* nVerticalSize() { return MakePointerGEN< int >( this, 0x4ac ); }
	inline int* nMinDist() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline int* nMaxDist() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* nOuterMaxDist() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline int* spawnflags() { return MakePointerGEN< int >( this, 0x4bc ); }
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline QAngle* angRotation() { return MakePointerGEN< QAngle >( this, 0x2d8 ); }
	inline int* moveparent() { return MakePointerGEN< int >( this, 0x15c ); }
	inline float* flGlowProxySize() { return MakePointerGEN< float >( this, 0x58c ); }
	inline float* HDRColorScale() { return MakePointerGEN< float >( this, 0x0 ); }
};
struct GenDT_InfoOverlayAccessor
{
	inline int* iTextureFrameIndex() { return MakePointerGEN< int >( this, 0x460 ); }
	inline int* iOverlayID() { return MakePointerGEN< int >( this, 0x4a8 ); }
};
struct GenDT_FuncTrackTrain : public GenDT_BaseEntity
{
};
struct GenDT_FuncSmokeVolume : public GenDT_BaseParticleEntity
{
	inline int* Color1() { return MakePointerGEN< int >( this, 0x594 ); }
	inline int* Color2() { return MakePointerGEN< int >( this, 0x598 ); }
	inline float* ParticleDrawWidth() { return MakePointerGEN< float >( this, 0x69c ); }
	inline float* ParticleSpacingDistance() { return MakePointerGEN< float >( this, 0x6a0 ); }
	inline float* DensityRampSpeed() { return MakePointerGEN< float >( this, 0x6a4 ); }
	inline float* RotationSpeed() { return MakePointerGEN< float >( this, 0x6a8 ); }
	inline float* MovementSpeed() { return MakePointerGEN< float >( this, 0x6ac ); }
	inline float* Density() { return MakePointerGEN< float >( this, 0x6b0 ); }
	inline int* spawnflags() { return MakePointerGEN< int >( this, 0x6b4 ); }
	inline CCollisionProperty* Collision() { return MakePointerGEN< CCollisionProperty >( this, 0x168 ); }
}; // Fail count = 1
struct GenDT_FuncRotating : public GenDT_BaseEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline QAngle* angRotation0() { return MakePointerGEN< QAngle >( this, 0x2d8 ); }
	inline QAngle* angRotation1() { return MakePointerGEN< QAngle >( this, 0x2dc ); }
	inline QAngle* angRotation2() { return MakePointerGEN< QAngle >( this, 0x2e0 ); }
	inline float* flSimulationTime() { return MakePointerGEN< float >( this, 0x68 ); }
};
struct GenDT_FuncReflectiveGlass : public GenDT_BaseEntity
{
};
struct GenDT_FuncOccluder : public GenDT_BaseEntity
{
	inline bool* bActive() { return MakePointerGEN< bool >( this, 0x4ac ); }
	inline int* nOccluderIndex() { return MakePointerGEN< int >( this, 0x4a8 ); }
};
struct GenDT_FuncMonitor : public GenDT_BaseEntity
{
};
struct GenDT_Func_LOD : public GenDT_BaseEntity
{
	inline int* fDisappearDist() { return MakePointerGEN< int >( this, 0x4a8 ); }
};
struct GenDT_TEDust : public GenDT_TEParticleSystem
{
	inline float* flSize() { return MakePointerGEN< float >( this, 0x1c ); }
	inline float* flSpeed() { return MakePointerGEN< float >( this, 0x20 ); }
	inline Vector* vecDirection() { return MakePointerGEN< Vector >( this, 0x24 ); }
};
struct GenDT_Func_Dust
{
	struct CCollisionProperty
	{
		inline Vector* vecMins() { return MakePointerGEN< Vector >( this, 0x8 ); }
		inline Vector* vecMaxs() { return MakePointerGEN< Vector >( this, 0x14 ); }
		inline int* nSolidType() { return MakePointerGEN< int >( this, 0x29 ); }
		inline int* usSolidFlags() { return MakePointerGEN< int >( this, 0x24 ); }
		inline int* nSurroundType() { return MakePointerGEN< int >( this, 0x28 ); }
		inline int* triggerBloat() { return MakePointerGEN< int >( this, 0x2a ); }
		inline Vector* vecSpecifiedSurroundingMins() { return MakePointerGEN< Vector >( this, 0x2c ); }
		inline Vector* vecSpecifiedSurroundingMaxs() { return MakePointerGEN< Vector >( this, 0x38 ); }
	};
	inline int* Color() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline int* SpawnRate() { return MakePointerGEN< int >( this, 0x4ac ); }
	inline float* flSizeMin() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline float* flSizeMax() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline int* LifetimeMin() { return MakePointerGEN< int >( this, 0x4bc ); }
	inline int* LifetimeMax() { return MakePointerGEN< int >( this, 0x4c0 ); }
	inline int* DustFlags() { return MakePointerGEN< int >( this, 0x4cc ); }
	inline int* SpeedMax() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline int* DistMax() { return MakePointerGEN< int >( this, 0x4c4 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x8c ); }
	inline float* FallSpeed() { return MakePointerGEN< float >( this, 0x4c8 ); }
	inline CCollisionProperty* Collision() { return MakePointerGEN< CCollisionProperty >( this, 0x168 ); }
};
struct GenDT_FuncConveyor : public GenDT_BaseEntity
{
	inline float* flConveyorSpeed() { return MakePointerGEN< float >( this, 0x4a8 ); }
};
struct GenDT_BreakableSurface : public GenDT_BaseEntity
{
	inline int* nNumWide() { return MakePointerGEN< int >( this, 0x4ac ); }
	inline int* nNumHigh() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline float* flPanelWidth() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline float* flPanelHeight() { return MakePointerGEN< float >( this, 0x4b8 ); }
	inline Vector* vNormal() { return MakePointerGEN< Vector >( this, 0x4bc ); }
	inline Vector* vCorner() { return MakePointerGEN< Vector >( this, 0x4c8 ); }
	inline bool* bIsBroken() { return MakePointerGEN< bool >( this, 0x4d4 ); }
	inline int* nSurfaceType() { return MakePointerGEN< int >( this, 0x4d8 ); }
}; // Fail count = 1
struct GenDT_FuncAreaPortalWindow : public GenDT_BaseEntity
{
	inline float* flFadeStartDist() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* flFadeDist() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline float* flTranslucencyLimit() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline int* iBackgroundModelIndex() { return MakePointerGEN< int >( this, 0x4b4 ); }
};
struct GenDT_CFish
{
	inline Vector* poolOrigin() { return MakePointerGEN< Vector >( this, 0x844 ); }
	inline float* x() { return MakePointerGEN< float >( this, 0x82c ); }
	inline float* y() { return MakePointerGEN< float >( this, 0x830 ); }
	inline float* z() { return MakePointerGEN< float >( this, 0x834 ); }
	inline QAngle* angle() { return MakePointerGEN< QAngle >( this, 0x83c ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x8c ); }
	inline int* lifeState() { return MakePointerGEN< int >( this, 0x8f ); }
	inline float* waterLevel() { return MakePointerGEN< float >( this, 0x850 ); }
};
struct GenDT_EntityFlame : public GenDT_BaseEntity
{
	inline EHANDLE* hEntAttached() { return MakePointerGEN< EHANDLE >( this, 0x4ac ); }
};
struct GenDT_FireSmoke : public GenDT_BaseEntity
{
	inline float* flStartScale() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* flScale() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline float* flScaleTime() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline int* nFlags() { return MakePointerGEN< int >( this, 0x4b4 ); }
	inline int* nFlameModelIndex() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline int* nFlameFromAboveModelIndex() { return MakePointerGEN< int >( this, 0x4bc ); }
};
struct GenDT_EnvTonemapController : public GenDT_BaseEntity
{
	inline bool* bUseCustomAutoExposureMin() { return MakePointerGEN< bool >( this, 0x4a8 ); }
	inline bool* bUseCustomAutoExposureMax() { return MakePointerGEN< bool >( this, 0x4a9 ); }
	inline bool* bUseCustomBloomScale() { return MakePointerGEN< bool >( this, 0x4aa ); }
	inline float* flCustomAutoExposureMin() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline float* flCustomAutoExposureMax() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline float* flCustomBloomScale() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline float* flCustomBloomScaleMinimum() { return MakePointerGEN< float >( this, 0x4b8 ); }
};
struct GenDT_EnvScreenEffect : public GenDT_BaseEntity
{
	inline float* flDuration() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline int* nType() { return MakePointerGEN< int >( this, 0x4ac ); }
};
struct GenDT_EnvScreenOverlay : public GenDT_BaseEntity
{
	inline int* iszOverlayNames0() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline int* iszOverlayNames() { return MakePointerGEN< int >( this, 0x0 ); } // Array size = 10
	inline float* flOverlayTimes0() { return MakePointerGEN< float >( this, 0xea0 ); }
	inline float* flOverlayTimes() { return MakePointerGEN< float >( this, 0x0 ); } // Array size = 10
	inline float* flStartTime() { return MakePointerGEN< float >( this, 0xec8 ); }
	inline int* iDesiredOverlay() { return MakePointerGEN< int >( this, 0xecc ); }
	inline bool* bIsActive() { return MakePointerGEN< bool >( this, 0xed0 ); }
};
struct GenDT_EnvProjectedTexture : public GenDT_BaseEntity
{
	inline EHANDLE* hTargetEntity() { return MakePointerGEN< EHANDLE >( this, 0x4ac ); }
	inline bool* bState() { return MakePointerGEN< bool >( this, 0x4b0 ); }
	inline float* flLightFOV() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline bool* bEnableShadows() { return MakePointerGEN< bool >( this, 0x4b8 ); }
	inline bool* bLightOnlyTarget() { return MakePointerGEN< bool >( this, 0x4b9 ); }
	inline bool* bLightWorld() { return MakePointerGEN< bool >( this, 0x4ba ); }
	inline bool* bCameraSpace() { return MakePointerGEN< bool >( this, 0x4bb ); }
	inline Vector* LinearFloatLightColor() { return MakePointerGEN< Vector >( this, 0x4bc ); }
	inline float* flAmbient() { return MakePointerGEN< float >( this, 0x4c8 ); }
	inline int* nSpotlightTextureFrame() { return MakePointerGEN< int >( this, 0x5d8 ); }
	inline float* flNearZ() { return MakePointerGEN< float >( this, 0x4cc ); }
	inline float* flFarZ() { return MakePointerGEN< float >( this, 0x4d0 ); }
	inline int* nShadowQuality() { return MakePointerGEN< int >( this, 0x5dc ); }
}; // Fail count = 1
struct GenDT_EnvParticleScript : public GenDT_BaseAnimating
{
	inline float* flSequenceScale() { return MakePointerGEN< float >( this, 0x8cc ); }
};
struct GenDT_FogController
{
	inline int* fog_enable() { return MakePointerGEN< int >( this, 0x4e8 ); }
	inline int* fog_blend() { return MakePointerGEN< int >( this, 0x4e9 ); }
	inline int* fog_dirPrimary() { return MakePointerGEN< int >( this, 0x4ac ); }
	inline int* fog_colorPrimary() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline int* fog_colorSecondary() { return MakePointerGEN< int >( this, 0x4bc ); }
	inline int* fog_start() { return MakePointerGEN< int >( this, 0x4c8 ); }
	inline int* fog_end() { return MakePointerGEN< int >( this, 0x4cc ); }
	inline int* fog_farz() { return MakePointerGEN< int >( this, 0x4d0 ); }
	inline int* fog_maxdensity() { return MakePointerGEN< int >( this, 0x4d4 ); }
	inline int* fog_colorPrimaryLerpTo() { return MakePointerGEN< int >( this, 0x4c0 ); }
	inline int* fog_colorSecondaryLerpTo() { return MakePointerGEN< int >( this, 0x4c4 ); }
	inline int* fog_startLerpTo() { return MakePointerGEN< int >( this, 0x4d8 ); }
	inline int* fog_endLerpTo() { return MakePointerGEN< int >( this, 0x4dc ); }
	inline int* fog_lerptime() { return MakePointerGEN< int >( this, 0x4e0 ); }
	inline int* fog_duration() { return MakePointerGEN< int >( this, 0x4e4 ); }
};
struct GenDT_EntityParticleTrail : public GenDT_BaseParticleEntity
{
	struct CEntityParticleTrailInfo
	{
		inline float* flLifetime() { return MakePointerGEN< float >( this, 0x8 ); }
		inline float* flStartSize() { return MakePointerGEN< float >( this, 0xc ); }
		inline float* flEndSize() { return MakePointerGEN< float >( this, 0x10 ); }
	};
	inline int* iMaterialName() { return MakePointerGEN< int >( this, 0x590 ); }
	inline CEntityParticleTrailInfo* Info() { return MakePointerGEN< CEntityParticleTrailInfo >( this, 0x594 ); }
	inline EHANDLE* hConstraintEntity() { return MakePointerGEN< EHANDLE >( this, 0x5a8 ); }
};
struct GenDT_EntityDissolve : public GenDT_BaseEntity
{
	inline float* flStartTime() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline float* flFadeOutStart() { return MakePointerGEN< float >( this, 0x4b0 ); }
	inline float* flFadeOutLength() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline float* flFadeOutModelStart() { return MakePointerGEN< float >( this, 0x4b8 ); }
	inline float* flFadeOutModelLength() { return MakePointerGEN< float >( this, 0x4bc ); }
	inline float* flFadeInStart() { return MakePointerGEN< float >( this, 0x4c0 ); }
	inline float* flFadeInLength() { return MakePointerGEN< float >( this, 0x4c4 ); }
	inline int* nDissolveType() { return MakePointerGEN< int >( this, 0x4c8 ); }
	inline Vector* vDissolverOrigin() { return MakePointerGEN< Vector >( this, 0x4dc ); }
	inline int* nMagnitude() { return MakePointerGEN< int >( this, 0x4e8 ); }
};
struct GenDT_DynamicLight : public GenDT_BaseEntity
{
	inline int* Flags() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline int* LightStyle() { return MakePointerGEN< int >( this, 0x4a9 ); }
	inline float* Radius() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline int* Exponent() { return MakePointerGEN< int >( this, 0x4b0 ); }
	inline float* InnerAngle() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline float* OuterAngle() { return MakePointerGEN< float >( this, 0x4b8 ); }
	inline float* SpotRadius() { return MakePointerGEN< float >( this, 0x4bc ); }
};
struct GenDT_ColorCorrectionVolume : public GenDT_BaseEntity
{
	inline float* Weight() { return MakePointerGEN< float >( this, 0x4a8 ); }
}; // Fail count = 1
struct GenDT_ColorCorrection : public GenDT_BaseEntity
{
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x4a8 ); }
	inline float* minFalloff() { return MakePointerGEN< float >( this, 0x4b4 ); }
	inline float* maxFalloff() { return MakePointerGEN< float >( this, 0x4b8 ); }
	inline float* flCurWeight() { return MakePointerGEN< float >( this, 0x4bc ); }
	inline int* netLookupFilename() { return MakePointerGEN< int >( this, 0x4c0 ); }
	inline bool* bEnabled() { return MakePointerGEN< bool >( this, 0x5c4 ); }
};
struct GenDT_BaseDoor : public GenDT_BaseEntity
{
	inline float* flWaveHeight() { return MakePointerGEN< float >( this, 0x4a8 ); }
};
struct GenDT_BoneFollower : public GenDT_BaseEntity
{
	inline int* modelIndex() { return MakePointerGEN< int >( this, 0x4a8 ); }
	inline int* solidIndex() { return MakePointerGEN< int >( this, 0x4ac ); }
};
struct GenDT_InfoLightingRelative : public GenDT_BaseEntity
{
	inline EHANDLE* hLightingLandmark() { return MakePointerGEN< EHANDLE >( this, 0x4a8 ); }
};
struct GenDT_AI_BaseNPC : public GenDT_BaseCombatCharacter
{
	inline int* lifeState() { return MakePointerGEN< int >( this, 0x8f ); }
	inline bool* bPerformAvoidance() { return MakePointerGEN< bool >( this, 0xd04 ); }
	inline bool* bIsMoving() { return MakePointerGEN< bool >( this, 0xd05 ); }
	inline bool* bFadeCorpse() { return MakePointerGEN< bool >( this, 0xd06 ); }
	inline int* iDeathPose() { return MakePointerGEN< int >( this, 0xcf4 ); }
	inline int* iDeathFrame() { return MakePointerGEN< int >( this, 0xcf8 ); }
	inline int* iSpeedModRadius() { return MakePointerGEN< int >( this, 0xcfc ); }
	inline int* iSpeedModSpeed() { return MakePointerGEN< int >( this, 0xd00 ); }
	inline bool* bSpeedModActive() { return MakePointerGEN< bool >( this, 0xd07 ); }
	inline bool* bImportanRagdoll() { return MakePointerGEN< bool >( this, 0xd08 ); }
	inline float* flTimePingEffect() { return MakePointerGEN< float >( this, 0xcf0 ); }
};
struct GenDT_Beam
{
	struct CBeamPredictableId
	{
		inline int* PredictableID() { return MakePointerGEN< int >( this, 0x9c ); }
		inline bool* bIsPlayerSimulated() { return MakePointerGEN< bool >( this, 0x45c ); }
	};
	inline int* nBeamType() { return MakePointerGEN< int >( this, 0x4c4 ); }
	inline int* nBeamFlags() { return MakePointerGEN< int >( this, 0x4c8 ); }
	inline int* nNumBeamEnts() { return MakePointerGEN< int >( this, 0x4b8 ); }
	inline EHANDLE* hAttachEntity() { return MakePointerGEN< EHANDLE >( this, 0x4cc ); } // Array size = 10
	inline int* nAttachIndex() { return MakePointerGEN< int >( this, 0x4f4 ); } // Array size = 10
	inline int* nHaloIndex() { return MakePointerGEN< int >( this, 0x4c0 ); }
	inline int* fHaloScale() { return MakePointerGEN< int >( this, 0x528 ); }
	inline int* fWidth() { return MakePointerGEN< int >( this, 0x51c ); }
	inline int* fEndWidth() { return MakePointerGEN< int >( this, 0x520 ); }
	inline int* fFadeLength() { return MakePointerGEN< int >( this, 0x524 ); }
	inline int* fAmplitude() { return MakePointerGEN< int >( this, 0x52c ); }
	inline int* fStartFrame() { return MakePointerGEN< int >( this, 0x530 ); }
	inline int* fSpeed() { return MakePointerGEN< int >( this, 0x534 ); }
	inline float* flFrameRate() { return MakePointerGEN< float >( this, 0x4a8 ); }
	inline float* flHDRColorScale() { return MakePointerGEN< float >( this, 0x4ac ); }
	inline int* clrRender() { return MakePointerGEN< int >( this, 0x58 ); }
	inline int* nRenderFX() { return MakePointerGEN< int >( this, 0x54 ); }
	inline int* nRenderMode() { return MakePointerGEN< int >( this, 0x7c ); }
	inline float* flFrame() { return MakePointerGEN< float >( this, 0x53c ); }
	inline Vector* vecEndPos() { return MakePointerGEN< Vector >( this, 0x540 ); }
	inline int* nModelIndex() { return MakePointerGEN< int >( this, 0x8c ); }
	inline int* nMinDXLevel() { return MakePointerGEN< int >( this, 0x538 ); }
	inline Vector* vecOrigin() { return MakePointerGEN< Vector >( this, 0x2cc ); }
	inline int* moveparent() { return MakePointerGEN< int >( this, 0x15c ); }
	inline CBeamPredictableId* beampredictable_id() { return MakePointerGEN< CBeamPredictableId >( this, 0x0 ); }
};
