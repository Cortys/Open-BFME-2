// cl: /O1 /DNDEBUG /MD /EHs-c-
// ?createAndFireTempWeapon@WeaponStore@@QAEXPBVWeaponTemplate@@PBVObject@@PBUCoord3D@@@Z @0x002CE904 96B
// Donor: ZH Weapon.h WeaponStore::createAndFireTempWeapon plus BFME1 Weapon.cpp
//   (allocate plus loadAmmoNow plus fireWeapon plus deleteInstance). Target adds
//   ownerID at +8 from Object+0x74 and frame+1 at +0x50 from TheGameLogic+0x40.
//   Callers 0x0033541C (lua template plus object plus +0x38 pos) 0x00495A2B and
//   0x001F0188 prove (template object pos); sibling 0x002CE964 is the target
//   overload firing at an object. Virtual deleteInstance(0) fed to operator
//   delete follows FireWeaponWhenDamagedBehaviorDtor.
struct Coord3D { float x, y, z; };

class Object
{
public:
	char m_pad00[0x38]; // +0x00..0x38
	Coord3D m_position; // +0x38
	char m_pad44[0x30]; // +0x44..0x74
	int m_id; // +0x74
};

class WeaponTemplate
{
};

enum WeaponSlotType
{
	WEAPON_SLOT_PRIMARY = 0
};

class Weapon
{
public:
	virtual void *deleteInstance(int flags);
	void loadAmmoNow(const Object *source);
	bool fireWeapon(const Object *source, const Coord3D *pos, int *projectileID);
	const WeaponTemplate *m_template; // +4
	unsigned int m_ownerID; // +8
	char m_pad0C[0x50 - 0x0C]; // +0x0C..0x50
	unsigned int m_50; // +0x50
};

class GameLogic
{
public:
	char m_pad00[0x40]; // +0x00..0x40
	unsigned int m_frame; // +0x40
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class WeaponStore
{
public:
	Weapon *allocateNewWeapon(const WeaponTemplate *tmpl, WeaponSlotType slot) const;
	void createAndFireTempWeapon(const WeaponTemplate *wt, const Object *source, const Coord3D *pos);
};

#define TheWeaponStore (*(WeaponStore **)0x00DFEFDC)

void WeaponStore::createAndFireTempWeapon(const WeaponTemplate *wt, const Object *source, const Coord3D *pos)
{
	if (wt == 0)
		return;
	Weapon *w = TheWeaponStore->allocateNewWeapon(wt, WEAPON_SLOT_PRIMARY);
	if (source != 0)
		w->m_ownerID = (unsigned int)source->m_id;
	w->loadAmmoNow(source);
	w->m_50 = TheGameLogic->m_frame + 1;
	w->fireWeapon(source, pos, 0);
	::operator delete(w->deleteInstance(0));
}
