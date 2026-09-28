// ??0Rva0034B0DD@@QAE@PAVStateMachine@@EEEH@Z
// partial score=0.94 date=2026-09-28
// cl: /O1 /MD /arch:SSE
//
// ?rva0034B0DD@Rva0034B0DD@@QAE@PAVStateMachine@@EEEH@Z @0x0034B0DD (115B).
// State-derived ctor with base State hash 0xE7D2F1FF, vtable 0x813B78,
// member vtable at +0x20 0x813B64, ints/floats/bytes per retail order.
// Evidence: single base call to rowed State 0x4D73FC, ret 0x14 with 5 args,
// size 0x50 via caller new at 0x34B977 and 0x34C714, callers pass (0,1,0,0).

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

extern "C" char Rva0034B0DD_vftable;
extern "C" char Rva0034B0DD_20_vftable;

class __declspec(novtable) Rva0034B0DD : public State
{
public:
	Rva0034B0DD(StateMachine *machine, unsigned char a2, unsigned char a3, unsigned char a4, int a5);

private:
	const void *m_20_vtable;
	int m_24;
	int m_28;
	int m_2c;
	float m_30;
	float m_34;
	float m_38;
	int m_3c;
	unsigned char m_40;
	unsigned char m_41;
	unsigned char m_42;
	char m_pad43;
	int m_44;
	unsigned char m_48;
	unsigned char m_49;
	char m_pad4a[2];
	int m_4c;
};

// ?rva0034B0DD@Rva0034B0DD@@QAE@PAVStateMachine@@EEEH@Z present-unmatched
Rva0034B0DD::Rva0034B0DD(StateMachine *machine, unsigned char a2, unsigned char a3, unsigned char a4, int a5)
	: State(machine, 0xE7D2F1FFu)
{
	m_20_vtable = &Rva0034B0DD_20_vftable;
	m_24 = 0;
	m_28 = a5;
	m_2c = 0;
	*reinterpret_cast<char **>(this) = &Rva0034B0DD_vftable;
	m_3c = 0;
	m_40 = a2;
	m_41 = a3;
	m_44 = 0;
	m_48 = 0;
	m_49 = 0;
	m_42 = a4;
	m_4c = 3;
	m_30 = 0.0f;
	m_34 = 0.0f;
	m_38 = 0.0f;
}
