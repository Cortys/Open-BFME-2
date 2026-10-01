// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/bfmelist /O1 /DNDEBUG /MD /EHsc /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva0035CC36@@QAE@XZ, retail 0x0035CC36 (148B).
// Ctor for Rva0035CCCAModuleData (vtable 0x00C16394, dtor at 0x0035CCCA):
// base trivial (4/8/0C), string +0x10 zeroed then set to empty,
// float +0x14 0.0, int +0x18 5, member +0x1C via rowed Rva0024C7B3Member
// ctor then memset 0x1C (double zero is retail), int +0x38 -1 (or),
// list +0x3C via rowed BfmePod8 ctor then AsciiString clear (same storage,
// union; Bfme spelling required for 0x35C9A6 bytes though object is the
// AsciiString list the dtor clears), byte +0x40 0 via direct store
// (overlaps list prev low byte in retail).

#include "ascii_string.h"
#include <list>

#pragma function(memset)

extern "C" void *memset(void *dst, int value, unsigned int size);
extern const char g_Rva0107301CEmptyString[];

class Rva0024C7B3Member
{
public:
	Rva0024C7B3Member();
	unsigned char m_data[0x1C];
};

struct BfmePod8 { int a[2]; };

class Rva001E3624
{
public:
	Rva001E3624() : m_unk04(0), m_unk08(0), m_unk0C(-1) {}
	virtual ~Rva001E3624();
	void *m_unk04;
	unsigned char m_unk08;
	int m_unk0C;
};

class Rva0035CC36 : public Rva001E3624
{
public:
	Rva0035CC36();
	AsciiString m_str10;
	float m_flt14;
	int m_int18;
	Rva0024C7B3Member m_mem1C;
	int m_neg38;
	_STL::list<BfmePod8> m_list3C;
};

Rva0035CC36::Rva0035CC36()
{
	m_str10.set(g_Rva0107301CEmptyString);
	m_flt14 = 0.0f;
	memset(&m_mem1C, 0, 0x1C);
	m_neg38 = -1;
	m_int18 = 5;
	((_STL::list<AsciiString> *)&m_list3C)->clear();
	*(unsigned char *)((char *)this + 0x40) = 0;
}
