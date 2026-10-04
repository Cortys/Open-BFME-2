// ??0BridgeBehavior@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.97 date=2026-10-04
// ??0BridgeBehavior@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.91 date=2026-09-24
// partial score=0.91 date=2026-09-24
// cl: /O1 /DNDEBUG /MD /Oi
//
// BANKED partial: 193/196. Writing the third Mid-slot store (+0x28) through a
// local pointer instead of a volatile char-cast store pins it ahead of the
// freelist call-setup cluster, which is what the banked 178/196 lacked: the
// lea eax,[ebp+0xF] / lea edi,[esi+0x100] / xor ebx,ebx group now lands where
// retail has it rather than hoisting above the store. Still 3 bytes out at
// offset +0x01: the base-ctor arg push order. All else is exact - UpdateModule
// rowed call, freelist init/reset pins plus ebp+0xF context, six explicit
// secondary installs, memset zero cluster, nested 4x3 zero loops, tail bytes.
class Thing;
class ModuleData;

class BehaviorModuleBase
{
public:
	virtual void unusedBase();
	int m_a;
	int m_b;
};

class BehaviorModuleOther
{
public:
	virtual void unusedOther();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};

class UpdateModuleInterface
{
public:
	virtual void update();
};

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
public:
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();
	virtual void update();
};


class Rva0029FB3BMember
{
public:
	void init(void *context);
	void reset();
	void *m_head;
};

extern "C" void *memset(void *dst, int val, unsigned int size);

class BridgeBehavior : public UpdateModule
{
	void *m_20;
	int m_24;
	int m_28;
	int m_2C;
	int m_30;
	int m_34;
	int m_38;
	int m_a3C[4][3];
	int m_a6C[4][3];
	int m_a9C[4][3];
	int m_aCC[4][3];
	bool m_FC;
	bool m_FD;
	char m_padFE[2];
	Rva0029FB3BMember m_free; // +0x100
	int m_104;
public:
	BridgeBehavior(Thing *thing, const ModuleData *moduleData);
};

BridgeBehavior::BridgeBehavior(Thing *thing, const ModuleData *moduleData)
	: UpdateModule(thing, moduleData)
{
	*(volatile unsigned int *)((char *)this + 0x20) = 0x00C40818;
	*(volatile unsigned int *)((char *)this + 0x24) = 0x00BE2B78;
	int *p28 = (int *)((char *)this + 0x28);
	*p28 = 0x00C1C780;
	void *context = (void *)((char *)&moduleData + 3);
	Rva0029FB3BMember *free = &m_free;
	*(unsigned int *)this = 0x00C409DC;
	*(unsigned int *)((char *)this + 0x0C) = 0x00C40920;
	*(unsigned int *)((char *)this + 0x10) = 0x00C40914;
	*(unsigned int *)((char *)this + 0x20) = 0x00C408FC;
	*(unsigned int *)((char *)this + 0x24) = 0x00C408F0;
	*(unsigned int *)((char *)this + 0x28) = 0x00C408EC;
	free->init(context);
	free->reset();
	m_FD = false;
	memset(&m_2C, 0, 16);
	m_FC = false;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			m_a3C[i][j] = 0;
			m_a6C[i][j] = 0;
			m_a9C[i][j] = 0;
			m_aCC[i][j] = 0;
		}
	m_104 = 0;
}
