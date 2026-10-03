// cl: /O1 /MD
// ??0Rva00544C03@@QAE@PAVStateMachine@@@Z, retail 0x00544C03, 33 bytes.
// Derived State ctor via rowed State hash ctor 0x004D73FC with hash
// 0xA2C0BF2B then zero of +0x20 then vtable 0x00C69C98. Evidence:
// vtable store at [this]; base StateCtor row; prev 0x00544AD2 same dir.
class StateMachine;

class __declspec(novtable) State
{
public:
	State(StateMachine *machine, unsigned int hash);
	virtual ~State();
	int m_id;
	int m_successStateID;
	int m_failureStateID;
	void *m_transitionsFirst;
	void *m_transitionsLast;
	StateMachine *m_machine;
	bool m_tail1C;
	unsigned char m_pad1D[0x20 - 0x1D];
};

extern const void *const g_00C69C98[];

class Rva00544C03 : public State
{
public:
	Rva00544C03(StateMachine *machine);
private:
	int m_20;
};

Rva00544C03::Rva00544C03(StateMachine *machine) : State(machine, 0xA2C0BF2Bu)
{
	m_20 = 0;
	*(const void **)this = g_00C69C98;
}
