// ??0Rva0022C9F6@@QAE@XZ
// partial score=0.93 date=2026-10-03
// ??0Rva0022C9F6@@QAE@XZ
// partial score=0.93 date=2026-10-03
// ??0Rva0022C9F6@@QAE@XZ
// partial score=0.93 date=2026-10-02
// cl: /O1 /EHsc /MD
// stlport
// ??0Rva0022C9F6@@QAE@XZ @0x0022C987 75B
// Ctor for Rva0022C9F6 whose dtor lives rowed at 0x0022C9F6. Calls rowed
// baseConstruct 0x001B4E63 via novtable base, stores vtable 0xBE74F0,
// constructs BitFlags<11> at +0xC via rowed 0x003B31AD then List_base at
// +0x10 via rowed 0x0035C9A6, then or 0x28. Evidence: leaf packet calls
// rowed baseConstruct plus rowed BitFlags and List_base; vtable matches
// rowed dtor; caller at 0x0022F405.
#include <list>

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

class __declspec(novtable) Rva0022C987Base
{
public:
	Rva0022C987Base() { ((BFME2NativeNetwork *)this)->baseConstruct(); }
	virtual ~Rva0022C987Base();
private:
	char m_pad[8];
};

template <int NUM_BITS>
class BitFlags
{
public:
	BitFlags();
private:
	unsigned int m_word;
};

struct BfmePod8 { int a[2]; };

class Rva0022C9F6 : public Rva0022C987Base
{
public:
	Rva0022C9F6();
	virtual ~Rva0022C9F6();
private:
	BitFlags<11> m_flags0C;
	_STL::_List_base<BfmePod8, _STL::allocator<BfmePod8> > m_list10;
};

// ??0Rva0022C9F6@@QAE@XZ present-unmatched
Rva0022C9F6::Rva0022C9F6()
	: m_flags0C()
	, m_list10(_STL::allocator<BfmePod8>())
{
	*(int *)&m_flags0C |= 0x28;
}
