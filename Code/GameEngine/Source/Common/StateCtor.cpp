// cl: /O1 /MD
// ??0State@@QAE@PAVStateMachine@@VAsciiString@@@Z at retail 0x004D73FC (43B).
// Base State ctor: three INVALID_STATE_IDs (999999), owner machine, vector
// homes zeroed, base vtable. BFME1 donor
// reference/open-bfme-1/Code/GameEngine/Source/Common/StateMachine.cpp
// State::State(StateMachine *machine, AsciiString name) verbatim minus debug
// (name unused in release, hence ret 8 with second arg untouched). Vtable
// 0x008605D8 overwritten by 40+ derived State ctors (0x004A6933 0x004A6BCA
// 0x004A6C13 plus 0x0033Fxxx family); callees none (leaf, gate-ready).

class StateMachine;

class AsciiString
{
public:
	void *m_data;
};

extern "C" char State_vftable;

class __declspec(novtable) State
{
public:
	State(StateMachine *machine, AsciiString name);
	virtual ~State();

	int m_id; // +0x04
	int m_successStateID; // +0x08
	int m_failureStateID; // +0x0C
	void *m_transitionsFirst; // +0x10
	void *m_transitionsLast; // +0x14
	StateMachine *m_machine; // +0x18
	bool m_tail1C; // +0x1C
};

State::State(StateMachine *machine, AsciiString name)
{
	m_id = 999999;
	m_successStateID = 999999;
	m_failureStateID = 999999;
	m_machine = machine;
	*reinterpret_cast<char **>(this) = &State_vftable;
	m_tail1C = false;
	m_transitionsFirst = 0;
	m_transitionsLast = 0;
}
