// ?Rva005440F6Get@@YA_NPAVRva00544884State@@@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /MD
// ?Rva005440F6Get@@YA_NPAVRva00544884State@@@Z, retail 0x005440F6, 61 bytes.
// Virtual slot 18 (offset 0x48) of vtable 0x00C69C30, class of ??0Rva00544884@@QAE@PAVStateMachine@@@Z.
// Gets TurretStateMachine goal via rowed getGoalObject 0x004D7726, finds BEC via rowed bfmeFindBEC 0x0028BCB4, calls slot 0x10 with owner and machine+0x3C, returns bool. Evidence: vslot slot 18; ctor TU Rva00544884Ctor; prev Rva005440BCVSlot5440CD same call pair; next Rva005447EDOnEnter same machine+owner pattern.

class Object;
class BfmeGotBEC;

class TurretStateMachine
{
public:
	Object *getGoalObject();
};

class BfmeSubBEC
{
public:
	BfmeGotBEC *bfmeFindBEC();
};

class BfmeGotBEC
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual bool v04(Object *owner, int v);
};

class StateMachine
{
public:
	unsigned char m_pad00[0x14];
	Object *m_owner; // +0x14
};

class TurretMachine : public StateMachine
{
public:
	unsigned char m_pad18[0x3C - 0x18];
	int m_3C; // +0x3C
};

class Rva00544884State
{
public:
	unsigned char m_pad00[0x18];
	StateMachine *m_machine; // +0x18
};

// ?Rva005440F6Get@@YA_NPAVRva00544884State@@@Z present-unmatched
bool Rva005440F6Get(Rva00544884State *state)
{
	Rva00544884State *s = state;
	TurretMachine *machine = (TurretMachine *)(s->m_machine);
	Object *goal = ((TurretStateMachine *)machine)->getGoalObject();
	if (goal == 0)
		return false;
	BfmeGotBEC *bec = ((BfmeSubBEC *)goal)->bfmeFindBEC();
	if (bec == 0)
		return false;
	unsigned char ok = bec->v04(s->m_machine->m_owner, machine->m_3C);
	return ok != 0;
}
