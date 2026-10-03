// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z
// partial score=0.9 date=2026-10-04
// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z
// partial score=0.9 date=2026-09-30
// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z
// partial score=0.9 date=2026-09-29
// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc- /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
//
// ?rva0045FE4A@SpawnBehavior@@QAEH..., retail 0x0045FE4A, 80 bytes.
// Iterates m_spawnIDs at secondary-this+0x20 (primary+0x4C), resolves each
// through TheGameLogic (0x009FE78C) findObjectByID (rowed 0x00049DC5),
// filters via rowed 0x004A1828 Rva004A1828Get, applies callback
// (arg1) with (Object*, arg2). Returns 0 on first callback false, else 1.
// Evidence: vtable slot 18 of 0x00842550 in SpawnBehavior ctor TU,
// prev 0x0045FCFB onSpawnDeath, retail loop with [esi+8] ID plus
// 0x004A1828 filter plus indirect call plus ret 8.

#define _STLP_NO_EXCEPTIONS 1
#include <list>

enum ObjectID
{
	INVALID_OBJECT_ID = 0
};

class Object;

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

struct Rva004A1828Owner;
int Rva004A1828Get(struct Rva004A1828Owner *owner);

typedef int (__cdecl *Rva0045FE4ACallback)(Object *obj, void *data);

class SpawnBehavior
{
public:
	virtual int rva0045FE4A(Rva0045FE4ACallback func, void *data);

private:
	unsigned char m_pad00[0x1C];
	_STL::list<ObjectID> m_spawnIDs;
};

// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z present-unmatched
int SpawnBehavior::rva0045FE4A(Rva0045FE4ACallback func, void *data)
{
	for (_STL::list<ObjectID>::iterator it = m_spawnIDs.begin(); it != m_spawnIDs.end(); ++it)
	{
		Object *obj = TheGameLogic->findObjectByID(*it);
		if (!obj)
			continue;
		if (!Rva004A1828Get((struct Rva004A1828Owner *)obj))
			continue;
		if (!func(obj, data))
			return 0;
	}
	return 1;
}
