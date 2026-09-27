// ??0Rva004D759C@@QAE@PAVObject@@VAsciiString@@_N@Z
// partial score=0.93 date=2026-09-27
// ??0Rva004D759C@@QAE@PAVObject@@VAsciiString@@_N@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE /G7 /D_STLP_USE_STATIC_LIB
// stlport
//
// ??0Rva004D759C@@QAE@PAVObject@@VAsciiString@@_N@Z at retail 0x004D79E1 (120B).
// StateMachine base ctor (same vtable 0x00C60740 and layout as dtor 0x004D759C
// pinned ??1Rva004D759C and deleting dtor 0x004D7A59 rowed ??_GRva004D759C).
// Evidence: vtable entries match StateMachine methods (update 0x004D7321 clear
// 0x004D72C5 reset 0x004D7A75 init 0x004D770F setState 0x004D7ACD); layout matches
// StateMachineGoal.cpp (map +8 owner +14 defaultID +1C goalID +20 goalPos +24
// goalRange FLT_MAX +30 unk34 +34 locked +38 inited +39); callers are derived
// StateMachine ctors forwarding owner/name/bool then setting derived vtables
// (e.g. 0x0034316A sets 0x00811AC0). BFME1 donor StateMachine.cpp ctor takes
// (Object* AsciiString); BFME2 adds bool at +3A and goalRange/unk34. Second arg
// name unused in release (like State ctor). SleepTill +18 left uninitialized
// to match retail (no store emitted).

#include <cfloat>
#include <map>

typedef int StateID;
enum { INVALID_STATE_ID = 999999 };

class Object;

class AsciiString
{
public:
	void *m_data;
};

struct Coord3D
{
	float x;
	float y;
	float z;
};

class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};

class Rva004D759C : public EmptyBase
{
public:
	Rva004D759C(Object *owner, AsciiString name, bool unk3A);
	virtual ~Rva004D759C();

	void *m_currentState; // +0x04
	_STL::map<int, void *> m_stateMap; // +0x08
	Object *m_owner; // +0x14
	unsigned int m_sleepTill; // +0x18 (uninitialized to match retail)
	StateID m_defaultStateID; // +0x1C
	int m_goalObjectID; // +0x20
	Coord3D m_goalPosition; // +0x24
	float m_goalRange; // +0x30
	int m_unk34; // +0x34
	bool m_locked; // +0x38
	bool m_defaultStateInited; // +0x39
	bool m_unk3A; // +0x3A
};

// ??1Rva004D759C@@UAE@XZ present-unmatched
Rva004D759C::~Rva004D759C()
{
}

Rva004D759C::Rva004D759C(Object *owner, AsciiString name, bool unk3A)
	: m_currentState(0),
	  m_owner(owner),
	  m_defaultStateID(INVALID_STATE_ID),
	  m_goalObjectID(0)
{
	m_goalPosition.x = 0.0f;
	m_goalPosition.y = 0.0f;
	m_goalPosition.z = 0.0f;
	m_goalRange = FLT_MAX;
	m_unk3A = unk3A;
	m_unk34 = 0;
	m_locked = false;
	m_defaultStateInited = false;
}
