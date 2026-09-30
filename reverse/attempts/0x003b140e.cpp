// ??0Rva003B1101@@QAE@XZ
// partial score=0.93 date=2026-09-30
// ??0Rva003B1101@@QAE@XZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /G7 /EHs /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ??0Rva003B1101@@QAE@XZ @0x003B140E (284B):
// Default ctor for Rva003B1101 (vtable 0x00C1ED18, dtor at 0x003B1101,
// assign at 0x003B1337). Empty Rva001E3624 base (inline ctor,
// declared-only dtor pins EH state 0), all scalar/string/vector-base
// defaults in mem-init in declaration order so they emit interleaved
// with the Rva ctors and bitset reset (whose user ctor calls reset).
// FixedStorage initFromStorages plus Science vector erase in body.
// Evidence: gap lane between assign and deleting dtor, same vtable,
// all callees rowed or pinned, callers 0x003B164F/0x003B1699/0x003B1751.
#include <vector>

typedef int Int;

enum ScienceType
{
	SCIENCE_NONE = 0
};

class Rva001E3624
{
public:
	Rva001E3624() : m_04(0), m_08(0), m_0c(-1) {}
	~Rva001E3624();
private:
	Int m_04; // +0x04
	unsigned char m_08; // +0x08
	Int m_0c; // +0x0C
};

class AsciiString
{
public:
	AsciiString(int zero) : m_data(reinterpret_cast<void *>(zero)) {}
	~AsciiString();
private:
	void *m_data;
};

class Rva003623E5Member
{
public:
	Rva003623E5Member();
	~Rva003623E5Member();
	void initFromStorages(class BfmeFixedStorage0004543D first, class BfmeFixedStorage0004543D second);
private:
	Int m_x;
};

class BfmeFixedStorage0004543D
{
public:
	__declspec(nothrow) BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other);
private:
	unsigned char m_bytes[28];
};

namespace _STL
{
template <unsigned _Bits>
class bitset
{
public:
	bitset() { reset(); }
	bitset<_Bits> &reset();
private:
	unsigned long m_words[(_Bits + 31) / 32];
};
}

extern const void *const g_00C1ED18[];
extern Int g_Va00DBA4E4;
extern const BfmeFixedStorage0004543D g_defaultStorage009FEFA4;

class Rva003B1101 : public Rva001E3624
{
public:
	Rva003B1101();
private:
	const void *m_vtable; // +0x00
	AsciiString m_10; // +0x10
	Int m_14; // +0x14
	Int m_18; // +0x18
	Int m_1c; // +0x1C
	Int m_20; // +0x20
	_STL::vector<ScienceType, _STL::allocator<ScienceType> > m_24; // +0x24
	Int m_30; // +0x30
	Int m_34; // +0x34
	Int m_38; // +0x38
	AsciiString m_3c; // +0x3C
	AsciiString m_40; // +0x40
	Int m_44; // +0x44
	Int m_48; // +0x48
	Int m_4c; // +0x4C
	float m_50; // +0x50
	float m_54; // +0x54
	unsigned char m_58; // +0x58
	unsigned char m_59; // +0x59
	AsciiString m_5c; // +0x5C
	Rva003623E5Member m_60; // +0x60
	_STL::bitset<128> m_64; // +0x64
	float m_74; // +0x74
	Rva003623E5Member m_78; // +0x78
	float m_7c; // +0x7C
};

Rva003B1101::Rva003B1101()
	: Rva001E3624()
	, m_vtable(g_00C1ED18)
	, m_10(0)
	, m_14(0)
	, m_18(0)
	, m_1c(0)
	, m_20(0)
	, m_30(0)
	, m_34(0)
	, m_38(0)
	, m_3c(0)
	, m_40(0)
	, m_44(-1)
	, m_48(g_Va00DBA4E4 * 10)
	, m_4c(0)
	, m_50(0.0f)
	, m_54(0.0f)
	, m_58(0)
	, m_59(0)
	, m_5c(0)
	, m_74(0.0f)
	, m_7c(0.0f)
{
	_STL::vector<ScienceType, _STL::allocator<ScienceType> > &vec24 = m_24;
	m_60.initFromStorages(g_defaultStorage009FEFA4, g_defaultStorage009FEFA4);
	vec24.erase(vec24.begin(), vec24.end());
	m_78.initFromStorages(g_defaultStorage009FEFA4, g_defaultStorage009FEFA4);
}
