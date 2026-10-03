// ?rva00485C86@CreateObjectDieIfEldestKindof@@QAEXPBVDamageInfo@@@Z
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /MD
// stlport
//
// ?rva00485C86@CreateObjectDieIfEldestKindof@@QAEXPBVDamageInfo@@@Z, retail 0x00485C86 139B: upgrade-gated create helper called by onDie 0x00485D11.
// Evidence: string CreateObjectDieIfEldestKindof in caller 0x00485D11 which passes same this; vtable slot 12 class; callees rowed findUpgrade/getControllingPlayer/PlayerRva/ObjectRva/findObjectByID/OCL-rva001F08D3/isDieApplicable; ModuleData +0x38 OCL +0x40 upgrade vector.
#include "ascii_string.h"

class UpgradeTemplate
{
public:
	int m_00;
	int m_04;
};

class UpgradeCenter
{
public:
	const UpgradeTemplate *findUpgrade(const AsciiString &name) const;
};
extern "C" UpgradeCenter *TheUpgradeCenter;
#pragma comment(linker, "/alternatename:_TheUpgradeCenter=?TheUpgradeCenter@@3PAVUpgradeCenter@@A")

class Player
{
public:
	bool rva002AB87D(const UpgradeTemplate *t) const;
};

class Object
{
public:
	Player *getControllingPlayer() const;
	bool rva00290D2B(const UpgradeTemplate *t) const;
};

enum ObjectID
{
	INVALID_ID = 0
};

class DamageInfo
{
public:
	int m_pad00[2];
	ObjectID m_sourceID08;
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};
extern GameLogic *TheGameLogic;

class ObjectCreationList
{
public:
	void rva001F08D3(void *a1, void *a2, void *a3);
};

class DieModule
{
	friend class CreateObjectDieIfEldestKindof;
protected:
	bool isDieApplicable(const DamageInfo *damageInfo) const;
public:
	void *m_04;
	Object *m_08;
};

struct CreateObjectDieModuleDataView
{
	char m_pad00[0x38];
	ObjectCreationList *m_ocl38;
	char m_pad3C[4];
	AsciiString *m_begin40;
	AsciiString *m_end44;
};

class CreateObjectDieIfEldestKindof
{
public:
	void rva00485C86(const DamageInfo *damageInfo);
};

// ?rva00485C86@CreateObjectDieIfEldestKindof@@QAEXPBVDamageInfo@@@Z present-unmatched
void CreateObjectDieIfEldestKindof::rva00485C86(const DamageInfo *damageInfo)
{
	if (!((DieModule *)((char *)this - 0x10))->isDieApplicable(damageInfo))
		return;
	Object *obj = *(Object **)((char *)this - 8);
	CreateObjectDieModuleDataView *data = *(CreateObjectDieModuleDataView **)((char *)this - 0x0C);
	for (AsciiString *cur = data->m_begin40; cur != data->m_end44; ++cur)
	{
		const UpgradeTemplate *t = TheUpgradeCenter->findUpgrade(*cur);
		if (t == 0)
			continue;
		bool ok;
		if (t->m_04 == 0)
		{
			Player *p = obj->getControllingPlayer();
			ok = p->rva002AB87D(t);
		}
		else
		{
			ok = obj->rva00290D2B(t);
		}
		if (!ok)
			return;
	}
	ObjectCreationList *ocl = data->m_ocl38;
	if (ocl == 0)
		return;
	ocl->rva001F08D3(obj, TheGameLogic->findObjectByID(damageInfo->m_sourceID08), (void *)0);
}
