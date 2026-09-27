// cl: /O1 /DNDEBUG /MD /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Weapon@@IAE@ABV0@@Z @0x002CC2FC 162B
// Donor: reference/open-bfme-1/Code/GameEngine/Source/GameLogic/Object/WeaponCopyConstructor.cpp
//   (BFME1 Weapon copy ctor) plus ZH GeneralsMD Weapon.h (protected copy ctor, no default ctor).
// Target evidence: vtable 0x0080214C at +0; single-arg ret 4; copies +4/+8/+0xC/+0x30
//   from src, recomputes pitch (+0x88/+0x8C) and shots (+0x108) from template.
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

private:
	char m_pad00[0x88];
	float m_minPitch; // +0x88
	float m_maxPitch; // +0x8C
	char m_pad90[0x108 - 0x90];
	int m_shotsPerBarrel; // +0x108
};

class Weapon
{
protected:
	Weapon(const Weapon &that);
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

Weapon::Weapon(const Weapon &that)
	: m_scatterTargets(_STL::allocator<BfmeE16>())
{
	m_tailState = 0;
	m_template = that.m_template;
	m_ownerID = that.m_ownerID;
	m_wslot = that.m_wslot;
	m_status = 1;
	m_ammoInClip = 0;
	m_whenPreAttackFinished = 0;
	m_whenLastReloadStarted = 0;
	m_lastFireFrame = 0;
	m_projectileStreamID = 0;
	m_whenWeCanFireAgain = 0;
	m_leechWeaponRangeActive = 0;
	m_unknown54 = 0;
	m_pitchLimited = m_template->getMinTargetPitch() > -3.14159265f || m_template->getMaxTargetPitch() < 3.14159265f;
	m_curBarrel = 0;
	m_maxShotCount = 0x7fffffff;
	m_numShotsForCurBarrel = m_template->getShotsPerBarrel();
	m_unknown2C = 0;
	unsigned int suspend = that.m_suspendFXFrame;
	m_extra5C = 0;
	m_suspendFXFrame = suspend;
}
