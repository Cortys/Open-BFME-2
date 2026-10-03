// ?rva002966A0@Object@@QAEXPAVPlayer@@0@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /GX /arch:SSE
// ?rva002966A0@Object@@QAEXPAVPlayer@@0@Z @0x002966A0 169B.
// Evidence: caller 0x00297530; callees rowed aiIdle 0x001E8A38, DoXfer 0x0047A69C,
// makeDirty 0x0073A0F0, init 0x007584C0, rva00625840 0x00625840,
// setScriptStatus 0x00292969, isLocalPlayer 0x002A9D89 (x2); global g_bfmeWorldRV.
// Offsets +0x258/+0x244/+0x4C4/+0x4CC/+0x4C8 read from retail; virtual slot 0x24 takes two Players.

class Xfer;
class Player;
class PartitionData;
class Rva009A2350;
class Rva00625840;

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT = 1,
	CMD_FROM_AI = 2
};

enum ObjectScriptStatusBit
{
	OBJECT_STATUS_BIT_4 = 4
};

class AICommandInterface
{
public:
	void aiIdle(CommandSourceType cmdSource);
};

class Rva002966A0Holder
{
public:
	char m_pad[0x20];
	AICommandInterface m_ai;
};

namespace FXParticleSystem
{
class EmissionVelocityInfo
{
public:
	virtual void DoXfer(Xfer &xfer);
};
}

class PartitionData
{
public:
	void makeDirty();
};

class Rva009A2350
{
public:
	void init();
};

class Rva00625840
{
public:
	void rva00625840();
};

class Player
{
public:
	bool isLocalPlayer() const;
};

struct BfmeWorldRV
{
	unsigned char m_pad[0x28];
	unsigned char m_28;
};

extern struct BfmeWorldRV *g_bfmeWorldRV;

class Rva002966A0Item
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void rva002966A0Call(Player *a, Player *b);
};

class Object
{
public:
	void setScriptStatus(ObjectScriptStatusBit bit, bool set);
	void rva002966A0(Player *a, Player *b);
};

// ?rva002966A0@Object@@QAEXPAVPlayer@@0@Z present-unmatched
void Object::rva002966A0(Player *a, Player *b)
{
	Rva002966A0Holder *holder = *(Rva002966A0Holder **)((char *)this + 0x258);
	if (holder != 0 && a != b)
		holder->m_ai.aiIdle(CMD_FROM_AI);
	((FXParticleSystem::EmissionVelocityInfo *)((char *)b + 0x3bc))->DoXfer(*(Xfer *)this);
	Rva002966A0Item **arr = *(Rva002966A0Item ***)((char *)this + 0x244);
	for (; *arr != 0; ++arr)
		(*arr)->rva002966A0Call(a, b);
	PartitionData *part = *(PartitionData **)((char *)this + 0x4c4);
	if (part != 0)
		part->makeDirty();
	Rva009A2350 *pcc = *(Rva009A2350 **)((char *)this + 0x4cc);
	if (pcc != 0)
		pcc->init();
	Rva00625840 *pc8 = *(Rva00625840 **)((char *)this + 0x4c8);
	if (pc8 != 0)
		pc8->rva00625840();
	setScriptStatus(OBJECT_STATUS_BIT_4, false);
	if (a->isLocalPlayer() || b->isLocalPlayer())
		g_bfmeWorldRV->m_28 = 1;
}
