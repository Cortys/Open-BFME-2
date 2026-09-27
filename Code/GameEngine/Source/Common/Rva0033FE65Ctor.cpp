// cl: /O1 /MD
//
// ??0Rva0033FE65@@QAE@PAVStateMachine@@H@Z, retail 0x0033FE65, 56 bytes.
// State-derived ctor forwarding (machine, 0x8821F22E) to the unsigned-hash
// twin ??0State@@QAE@PAVStateMachine@@I@Z at 0x004D73FC then installing
// vtable 0x00811E08. Sets word at +0x20 via OR FFFF, byte at +0x24 to
// (val==0), word at +0x22 to 5, byte at +0x25 to 0. Callers pass 0 as val
// (0x00342FCD) plus machine pointers. Recipe is StateDerivedCtors_muse-a7a4
// hash-plus-vtable with the extra word/bool tail.

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

extern "C" char Rva0033FE65_vftable;

class __declspec(novtable) Rva0033FE65 : public State
{
public:
	Rva0033FE65(StateMachine *machine, int val);

private:
	unsigned short m_20;
	unsigned short m_22;
	bool m_24;
	bool m_25;
};

Rva0033FE65::Rva0033FE65(StateMachine *machine, int val) : State(machine, 0x8821F22Eu)
{
	m_20 |= 0xFFFF;
	*reinterpret_cast<char **>(this) = &Rva0033FE65_vftable;
	m_24 = (val == 0);
	m_22 = 5;
	m_25 = 0;
}
