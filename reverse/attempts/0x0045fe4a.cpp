// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z
// partial score=0.9 date=2026-10-04
// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z
// Walk the spawn-ID list at this+0x20, resolve each entry through
// TheGameLogic->findObjectByID, drop nulls and entries failing the 0x004A1828
// filter, and run the callback on the survivors. Returns 0 on the first
// callback false, else 1.
// cl: /O1 /DNDEBUG /MD /EHsc- /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport

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
	unsigned char m_pad00[0x20];
	_STL::list<ObjectID> m_spawnIDs;
};

// ?rva0045FE4A@SpawnBehavior@@UAEHP6AHPAVObject@@PAX@Z1@Z present-unmatched
int SpawnBehavior::rva0045FE4A(Rva0045FE4ACallback func, void *data)
{
	SpawnBehavior *self = this;
	_STL::list<ObjectID> *ids = &self->m_spawnIDs;
	for (_STL::list<ObjectID>::iterator it = ids->begin(); it != ids->end(); ++it)
	{
		Object *obj = TheGameLogic->findObjectByID(*it);
		if (obj && Rva004A1828Get((struct Rva004A1828Owner *)obj))
		{
			if (!func(obj, data))
				return 0;
		}
	}
	return 1;
}