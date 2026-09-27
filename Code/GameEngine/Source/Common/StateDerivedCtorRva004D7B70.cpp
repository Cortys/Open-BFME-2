// cl: /O1 /MD
// ??0Rva004D7B70@@QAE@PAVStateMachine@@VAsciiString@@@Z at retail 0x004D7B70 (28B).
// State-derived ctor forwarding (machine, name) to ??0State@@QAE@PAVStateMachine@@VAsciiString@@@Z
// 0x004D73FC then installing vtable 0x00860790. Same esi-homing recipe as
// StateDerivedCtors_muse-a7a4.cpp six (29B) but with AsciiString passthrough
// (ret 8) not hash immediate. Callers in BoxEmissionVolumeInfo dtors.

class StateMachine;

class AsciiString
{
public:
	void *m_data;
};

class State
{
public:
	State(StateMachine *machine, AsciiString name);
	virtual ~State();
};

extern "C" char Rva004D7B70_vftable;

class __declspec(novtable) Rva004D7B70 : public State
{
public:
	Rva004D7B70(StateMachine *machine, AsciiString name);
	virtual ~Rva004D7B70();
};

Rva004D7B70::Rva004D7B70(StateMachine *machine, AsciiString name) : State(machine, name)
{
	*reinterpret_cast<char **>(this) = &Rva004D7B70_vftable;
}
