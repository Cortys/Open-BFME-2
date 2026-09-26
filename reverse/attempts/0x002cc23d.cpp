// ??0Weapon@@IAE@PBVWeaponTemplate@@W4WeaponSlotType@@@Z
// partial score=0.97 date=2026-09-26
// ??0Weapon@@IAE@PBVWeaponTemplate@@W4WeaponSlotType@@@Z
// partial score=0.97 date=2026-09-26
// cl: /O1 /DNDEBUG /MD /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Weapon@@IAE@PBVWeaponTemplate@@W4WeaponSlotType@@@Z @0x002CC23D 185B
// Donor: reference/open-bfme-1/Code/GameEngine/Source/GameLogic/Object/WeaponConstructor.cpp
//   (BFME1 Weapon::Weapon protected ctor) plus ZH Weapon.h friendship.
// Target evidence: vtable 0x0080214C at +0; caller 0x0028AAA8 in
//   WeaponStore::allocateNewWeapon (news 0x60); sizes match 0x60.
//   Template floats at +0x88/+0x8C, shots at +0x108, suspend delay at +0x150,
//   GameLogic frame at TheGameLogic+0x40 via 0x00DFE78C.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

enum WeaponSlotType
{
	WEAPON_SLOT_PRIMARY = 0
};

class WeaponTemplate
{
public:
	float getMinTargetPitch() const { return m_minPitch; }
	float getMaxTargetPitch() const { return m_maxPitch; }
	int getShotsPerBarrel() const { return m_shotsPerBarrel; }
	unsigned int getSuspendFXDelay() const { return m_suspendFXDelay; }

private:
	char m_pad00[0x88];
	float m_minPitch; // +0x88
	float m_maxPitch; // +0x8C
	char m_pad90[0x108 - 0x90];
	int m_shotsPerBarrel; // +0x108
	char m_pad10C[0x150 - 0x10C];
	unsigned int m_suspendFXDelay; // +0x150
};

class GameLogic
{
public:
	unsigned int getFrame() const { return m_frame; }

private:
	char m_pad00[0x40];
	unsigned int m_frame; // +0x40
};

extern GameLogic *TheGameLogic;

class Weapon
{
protected:
	Weapon(const WeaponTemplate *tmpl, WeaponSlotType wslot);
	virtual void unused();

private:
	const WeaponTemplate *m_template; // +4
	unsigned int m_ownerID; // +8
	WeaponSlotType m_wslot; // +0xC
	unsigned int m_status; // +0x10
	unsigned int m_ammoInClip; // +0x14
	unsigned int m_whenWeCanFireAgain; // +0x18
	unsigned int m_whenPreAttackFinished; // +0x1C
	unsigned int m_whenLastReloadStarted; // +0x20
	unsigned int m_lastFireFrame; // +0x24
	unsigned int m_projectileStreamID; // +0x28
	unsigned int m_unknown2C; // +0x2C
	unsigned int m_suspendFXFrame; // +0x30
	int m_maxShotCount; // +0x34
	int m_curBarrel; // +0x38
	int m_numShotsForCurBarrel; // +0x3C
	_STL::vector<BfmeE16> m_scatterTargets; // +0x40
	bool m_pitchLimited; // +0x4C
	char m_pad4D[3];
	unsigned int m_leechWeaponRangeActive; // +0x50
	unsigned int m_unknown54; // +0x54
	unsigned int m_tailState; // +0x58
	unsigned int m_extra5C; // +0x5C
};

// ??0Weapon@@IAE@PBVWeaponTemplate@@W4WeaponSlotType@@@Z present-unmatched
Weapon::Weapon(const WeaponTemplate *tmpl, WeaponSlotType wslot)
	: m_scatterTargets(_STL::allocator<BfmeE16>())
{
	m_wslot = wslot;
	m_tailState = 0;
	m_template = tmpl;
	m_ownerID = 0;
	m_status = 1;
	m_ammoInClip = 0;
	m_whenWeCanFireAgain = 0;
	m_whenPreAttackFinished = 0;
	m_whenLastReloadStarted = 0;
	m_lastFireFrame = 0;
	m_projectileStreamID = 0;
	m_leechWeaponRangeActive = 0;
	m_unknown54 = 0;
	m_pitchLimited = tmpl && (tmpl->getMinTargetPitch() > -3.14159265f || tmpl->getMaxTargetPitch() < 3.14159265f);
	m_maxShotCount = 0x7fffffff;
	m_curBarrel = 0;
	m_numShotsForCurBarrel = tmpl ? tmpl->getShotsPerBarrel() : 1;
	m_unknown2C = 0;
	unsigned int suspend = tmpl ? TheGameLogic->getFrame() + tmpl->getSuspendFXDelay() : 0;
	m_extra5C = 0;
	m_suspendFXFrame = suspend;
}
