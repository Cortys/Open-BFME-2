// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva0036804F@@QAE@PAVStateMachine@@@Z @0x0036804F 24B
// Rva00342B87-derived ctor, vtable 0x0086A250, no extra members. Recipe from
// sibling Rva00342826Ctor.cpp (29B, same base + vtable shape) chaining the
// just-landed base 0x00342B87. Donor AIStatesSmallUpdates.cpp ctor pattern.
// Evidence: base row 0x00342B87 Rva00342B87 ctor; callers 0x005432C5 0x00546141.
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
class Rva00342B87 : public AIInternalMoveToState
{
public:
	Rva00342B87(StateMachine *machine);
private:
	int m_4C;
};
class Rva0036804F : public Rva00342B87
{
public:
	Rva0036804F(StateMachine *machine);
};
Rva0036804F::Rva0036804F(StateMachine *machine)
	: Rva00342B87(machine)
{
}
