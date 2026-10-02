// ??0Rva00542E13@@QAE@PAVStateMachine@@@Z
// partial score=0.94 date=2026-10-02
// cl: /O1 /MD /arch:SSE
// ??0Rva00542E13@@QAE@PAVStateMachine@@@Z @0x00542E13 73B
// Derived State ctor with hash 0x25457F62: base State(machine hash) via pinned
// ICF twin then vtable g_00C69780 g_00C69778 plus int and float zeroing.
// Caller 0x00543257. Evidence: retail bytes unlock lane plus StateCtor donor
// hash pattern and movss with /arch:SSE volatile pins store order per lever.
// ??0Rva00542E13@@QAE@PAVStateMachine@@@Z present-unmatched
class StateMachine;

class State
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
	char m_pad1D[0x20 - 0x1D];
};

extern const void *const g_00C69780[];
extern const void *const g_00C69778[];

class Rva00542E13 : public State
{
public:
	Rva00542E13(StateMachine *machine);
private:
	const void *volatile m_20vtable;
	volatile int m_24;
	volatile float m_28;
	volatile float m_2C;
	volatile float m_30;
	volatile float m_34;
	volatile int m_38;
	volatile int m_3C;
	volatile unsigned char m_40;
};

Rva00542E13::Rva00542E13(StateMachine *machine) : State(machine, 0x25457F62u)
{
	*(const void *volatile *)this = g_00C69780;
	m_24 = 0;
	m_38 = 0;
	m_20vtable = g_00C69778;
	m_34 = 0.0f;
	m_28 = 0.0f;
	m_2C = 0.0f;
	m_30 = 0.0f;
	m_3C = 0;
	m_40 = 0;
}
