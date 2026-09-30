// ??0Rva004A7010@@QAE@PAVObject@@@Z
// partial score=0.96 date=2026-09-30
// ??0Rva004A7010@@QAE@PAVObject@@@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /MD /EHsc
// ??0Rva004A7010@@QAE@PAVObject@@@Z @0x004A7010 373B
// StateMachine-derived ctor: base Rva004D759C(owner, hash F95C8C34, false),
// vtable 0x008532A8, then six 0x20 State news with defineState ids
// 1,0,2,3,4,5 and conds C53330/C53390/C53360/C53330/C53300/C53300.
// Evidence: unlock packet (all callees rowed), caller SupplyTruckAIUpdate
// ctor 0x004A71A1 news 0x3C then calls here, callees Rva004D759C base,
// six Rva004A6xxx State ctors, defineState, operator new.
class Object;
class AsciiString
{
public:
	AsciiString(unsigned int h) : m_hash(h) {}
	unsigned int m_hash;
};
class Rva004D759C
{
public:
	Rva004D759C(Object *owner, AsciiString name, bool flag);
	virtual ~Rva004D759C();
};
struct State;
struct StateConditionInfo
{
	void *m_test;
	unsigned int m_toState;
	void *m_userData;
};
class StateMachine
{
public:
	void defineState(unsigned int id, State *state, unsigned int success, unsigned int failure, const StateConditionInfo *conds);
};
class Rva004A6BCA
{
public:
	Rva004A6BCA(StateMachine *m);
	virtual ~Rva004A6BCA();
	char m_pad[0x20 - 4];
};
class Rva004A6C13
{
public:
	Rva004A6C13(StateMachine *m);
	virtual ~Rva004A6C13();
	char m_pad[0x20 - 4];
};
class Rva004A6933
{
public:
	Rva004A6933(StateMachine *m);
	virtual ~Rva004A6933();
	char m_pad[0x20 - 4];
};
class Rva004A6956
{
public:
	Rva004A6956(StateMachine *m);
	virtual ~Rva004A6956();
	char m_pad[0x20 - 4];
};
class Rva004A6979
{
public:
	Rva004A6979(StateMachine *m);
	virtual ~Rva004A6979();
	char m_pad[0x20 - 4];
};
class Rva004A699C
{
public:
	Rva004A699C(StateMachine *m);
	virtual ~Rva004A699C();
	char m_pad[0x20 - 4];
};
void *__cdecl operator new(unsigned int size) throw();
extern const StateConditionInfo g_00C53330[];
extern const StateConditionInfo g_00C53390[];
extern const StateConditionInfo g_00C53360[];
extern const StateConditionInfo g_00C53300[];
class Rva004A7010 : public Rva004D759C
{
public:
	Rva004A7010(Object *owner);
	virtual ~Rva004A7010();
	char m_pad[0x3C - 4];
};
// ??0Rva004A7010@@QAE@PAVObject@@@Z present-unmatched
Rva004A7010::Rva004A7010(Object *owner) : Rva004D759C(owner, AsciiString(0xF95C8C34u), false)
{
	StateMachine *machine = (StateMachine *)this;
	machine->defineState(1, (State *)new Rva004A6BCA(machine), 1, 1, g_00C53330);
	machine->defineState(0, (State *)new Rva004A6C13(machine), 1, 1, g_00C53390);
	machine->defineState(2, (State *)new Rva004A6933(machine), 1, 3, g_00C53360);
	machine->defineState(3, (State *)new Rva004A6956(machine), 2, 1, g_00C53330);
	machine->defineState(4, (State *)new Rva004A6979(machine), 1, 1, g_00C53300);
	machine->defineState(5, (State *)new Rva004A699C(machine), 1, 1, g_00C53300);
}
