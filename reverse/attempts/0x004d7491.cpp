// ??0Rva004D7491@@QAE@PAVStateMachine@@@Z
// partial score=0.93 date=2026-09-27
// ??0Rva004D7491@@QAE@PAVStateMachine@@@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /GX /arch:SSE /D_STLP_USE_STATIC_LIB
// Two 27B State-derived ctors calling ??0State@@QAE@PAVStateMachine@@I@Z
// (0x004D73FC ICF twin) then installing their own vtable. Same recipe as
// StateDerivedCtors_muse-a7a4.cpp but retail uses edx for this (leaf callee
// preserves edx) giving 27B not 29B. Hashes and vtables from retail bytes.
// 0x004D7491 hash 0xC17A0A70 vtable 0x00860668
// 0x004D74AC hash 0xDF4D3EB3 vtable 0x008606B0

class StateMachine;

class State
{
public:
	State(StateMachine *machine, unsigned int hash);
	virtual ~State();
};

extern "C" char Rva004D7491_vftable;
extern "C" char Rva004D74AC_vftable;

class __declspec(novtable) Rva004D7491 : public State
{
public:
	Rva004D7491(StateMachine *machine);
	virtual ~Rva004D7491();
};

class __declspec(novtable) Rva004D74AC : public State
{
public:
	Rva004D74AC(StateMachine *machine);
	virtual ~Rva004D74AC();
};

// ??0Rva004D7491@@QAE@PAVStateMachine@@@Z present-unmatched
Rva004D7491::Rva004D7491(StateMachine *machine) : State(machine, 0xC17A0A70u)
{
	*reinterpret_cast<char **>(this) = &Rva004D7491_vftable;
}

// ??0Rva004D74AC@@QAE@PAVStateMachine@@@Z present-unmatched
Rva004D74AC::Rva004D74AC(StateMachine *machine) : State(machine, 0xDF4D3EB3u)
{
	*reinterpret_cast<char **>(this) = &Rva004D74AC_vftable;
}
