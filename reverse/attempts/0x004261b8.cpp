// ??0Rva004261B8@@QAE@XZ
// partial score=0.9 date=2026-09-29
// ??0Rva004261B8@@QAE@XZ
// partial score=0.90 date=2026-09-29
// cl: /O1 /EHsc /MD
// stlport
//
// ??0Rva004261B8@@QAE@XZ, retail 0x004261B8, 55 bytes.
// BFME2NativeNetwork-derived ctor: the head member's inline ctor emits the
// rowed baseConstruct call at 0x001B4E63 plus the vptr store 0x0083C2AC on
// the object address, then the PristineBoneInfoMap member at +0x0C runs
// through the rowed _STL::map ctor 0x004260FD. The head's declared-only
// destructor is what forces the single-state EH frame retail shows: it is
// the only object needing unwind when the map member constructs, so the
// state map stays at the single state 0. Evidence: chain lane (calls
// 0x004260FD just landed); vptr store proves the ctor; caller 0x0022F025
// in 0x0062E2E4; same baseConstruct+vptr recipe as Rva0026201CCtor.cpp and
// Rva0098477Ctor.cpp, with the map member ordered after the head by
// declaration order.
#include <map>

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

struct PristineBoneInfo
{
	unsigned char m_data[52];
};

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

struct Rva004261B8Head
{
	__forceinline Rva004261B8Head()
	{
		((BFME2NativeNetwork *)this)->baseConstruct();
		*(void volatile **)this = (void *)0x0083C2AC;
	}
	~Rva004261B8Head();
};

class Rva004261B8 : public BFME2NativeNetwork
{
	Rva004261B8Head m_head;
	char m_pad[10];
	_STL::map<NameKeyType, PristineBoneInfo> m_map;
public:
	Rva004261B8();
};

Rva004261B8::Rva004261B8()
{
}
