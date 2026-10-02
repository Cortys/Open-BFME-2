// ?rva002C8B9B@WeaponSet@@QAEXH@Z
// partial score=0.92 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
//
// ?rva002C8B9B@WeaponSet@@QAEXH@Z, retail 0x002C8B9B (107 bytes).
// Identity: WeaponSet method sharing the WeaponSetSetWeaponLock layout
// (m_curWeaponLockedStatus +0x24, m_ownerID +0x3C); called with arg 2 by the
// matched placeholder WeaponSet::updateWeaponSet 0x002C8C97 and via
// lea ecx,[esi+0x330] with the caller's arg by 0x0028D8B6. Clears the lock
// status to 0 and clears model-condition bits 0x90..0x94 on the owner through
// the matched placeholder rows 0x000B6253 and 0x001E42F2. Arg 2 always clears
// when locked; arg 1 only clears TEMPORARY lock, matching the early guards.

enum ObjectID
{
	INVALID_ID = 0
};
enum WeaponSlotType
{
	PRIMARY_WEAPON = 0
};
enum WeaponLockType
{
	NOT_LOCKED = 0,
	LOCKED_TEMPORARILY = 1,
	LOCKED_PERMANENTLY = 2
};
class Object;
class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};
extern GameLogic *TheGameLogic;
class Rva000B6253
{
public:
	Rva000B6253 *rva000B6253(int count, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
private:
	unsigned int m_words[19];
};
class Rva001E42F2
{
public:
	void rva001E42F2(const int *mask);
};
class Weapon;
class WeaponSet
{
public:
	void rva002C8B9B(int arg);
	WeaponLockType getLockStatus() const { return m_curWeaponLockedStatus; }
private:
	unsigned char m_pad00[8];
	Weapon *m_weapons[5]; // +0x08
	unsigned char m_pad1C[4];
	WeaponSlotType m_curWeapon; // +0x20
	WeaponLockType m_curWeaponLockedStatus; // +0x24
	unsigned char m_pad28[0x3C - 0x28];
	ObjectID m_ownerID; // +0x3C
};
// ?rva002C8B9B@WeaponSet@@QAEXH@Z present-unmatched
void WeaponSet::rva002C8B9B(int arg)
{
	Object *owner = TheGameLogic->findObjectByID(m_ownerID);
	if (getLockStatus() == NOT_LOCKED)
		return;
	if (arg != LOCKED_PERMANENTLY)
	{
		if (arg != LOCKED_TEMPORARILY)
			return;
		if (getLockStatus() != LOCKED_TEMPORARILY)
			return;
	}
	m_curWeaponLockedStatus = NOT_LOCKED;
	if (owner == 0)
		return;
	Rva000B6253 mask;
	Rva000B6253 *mp = mask.rva000B6253(0, 0x90, 0x91, 0x92, 0x93, 0x94);
	((Rva001E42F2 *)owner)->rva001E42F2((const int *)mp);
}
