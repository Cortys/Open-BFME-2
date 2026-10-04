// ??0Rva0034290D@@QAE@PAVStateMachine@@_N11@Z
// partial score=0.95 date=2026-10-04
// ??0Rva0034290D@@QAE@PAVStateMachine@@_N11@Z
// partial score=0.95 date=2026-10-03
// ??0Rva0034290D@@QAE@PAVStateMachine@@_N11@Z
// partial score=0.94 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ??0Rva0034290D@@QAE@PAVStateMachine@@_N11@Z @0x0034290D 101B: AIInternalMoveToState-derived ctor, hash 0xCC44C7B1, vtable 0x00812610, 6 floats + 2 ints zero, bytes from 3 bool params, 0x6F=1.
// Donor Code/GameEngine/Source/GameLogic/AI/AIStatesSmallUpdates.cpp AIFollowWaypointPathExactState ctor pattern (base + vtable + members).
// Callers 0x003434FB 0x00346EFF 0x00346F23 unclaimed.
class StateMachine;
struct Coord3D
{
	float x, y, z;
};
class State
{
public:
	virtual ~State();
	virtual void slot01();
	virtual void slot02();
	virtual void xfer();
	virtual int onEnter();
	virtual void onExit();
	virtual int update();
protected:
	unsigned char m_pad04[0x18 - 0x04];
	StateMachine *m_machine;
};
class AIInternalMoveToState : public State
{
public:
	AIInternalMoveToState(StateMachine *machine, unsigned int hash);
	virtual ~AIInternalMoveToState();
	virtual void xfer();
	virtual int onEnter();
	virtual void onExit();
	virtual int update();
protected:
	unsigned char m_pad1C[0x20 - 0x1C];
	Coord3D m_goalPosition;
	unsigned char m_pad2C[0x48 - (0x20 + sizeof(Coord3D))];
	bool m_adjustsDestination;
};
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class Rva0034290D : public AIInternalMoveToState
{
public:
	Rva0034290D(StateMachine *machine, bool a, bool b, bool c);
private:
	float m_4C;
	float m_50;
	float m_54;
	float m_58;
	float m_5C;
	float m_60;
	int m_64;
	int m_68;
	bool m_6C;
	bool m_6D;
	bool m_6E;
	bool m_6F;
	bool m_70;
	bool m_71;
};
// ??0Rva0034290D@@QAE@PAVStateMachine@@_N11@Z present-unmatched
// The m_6C store leads the body so cl issues the incoming byte load at +0x14,
// where retail has it, rather than at the point of use.
Rva0034290D::Rva0034290D(StateMachine *machine, bool a, bool b, bool c)
	: AIInternalMoveToState(machine, 0xCC44C7B1u)
{
	m_6C = a;
	m_4C = 0.0f;
	m_50 = 0.0f;
	m_54 = 0.0f;
	m_58 = 0.0f;
	m_5C = 0.0f;
	m_60 = 0.0f;
	_ReadWriteBarrier();
	m_6D = b;
	m_64 = 0;
	m_68 = 0;
	m_6E = false;
	m_71 = false;
	m_6F = true;
	m_70 = c;
	_ReadWriteBarrier();
}
