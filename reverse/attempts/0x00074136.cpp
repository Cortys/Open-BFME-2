// ??0Rva00074136@@QAE@XZ
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// stlport
//
// ??0Rva00074136@@QAE@XZ, retail 0x00074136, 138 bytes.
// Evidence: __thiscall ctor (no stack args, returns this via mov eax,esi).
// Zeroes ints, loads floats +0x10/+0x14 from shared 10.0f g_Va00BC2428,
// sets +0x28=4, zeroes +0x2c/+0x30 via xorps, bytes +0x34=0 +0x35=1
// +0x36 from TheWritableGlobalData+0xc04, +0x38/+0x3c=0 +0x40=1,
// constructs set<AsciiString> at +0x44 via rowed 0x000D3A71.
// Callees rowed __EH_prolog 0x00629188 and set ctor. Callers at 0x0006CD9C.
#include "ascii_string.h"
#include <set>

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL {
template <> struct less<AsciiString> {
	bool operator()(const AsciiString &left, const AsciiString &right) const {
		return left < right;
	}
};
}

extern float g_Va00BC2428;

class GlobalData
{
public:
	unsigned char m_pad[0xC04];
	unsigned char m_flag04;
};

extern GlobalData *TheWritableGlobalData;

class EmptyBase74136
{
public:
	EmptyBase74136() {}
	~EmptyBase74136();
};

class Rva00074136 : public EmptyBase74136
{
public:
	Rva00074136();

private:
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	float m_10;
	float m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	int m_28;
	float m_2c;
	float m_30;
	unsigned char m_34;
	unsigned char m_35;
	unsigned char m_36;
	unsigned char m_pad37;
	int m_38;
	int m_3c;
	unsigned char m_40;
	unsigned char m_pad41[3];
	_STL::set<AsciiString> m_set44;
};

// ??0Rva00074136@@QAE@XZ present-unmatched
Rva00074136::Rva00074136()
	: m_00(0)
	, m_04(0)
	, m_08(0)
	, m_0c(0)
	, m_10(g_Va00BC2428)
	, m_14(m_10)
	, m_18(0)
	, m_1c(0)
	, m_20(0)
	, m_24(0)
	, m_28(4)
	, m_2c(0.0f)
	, m_30(0.0f)
	, m_34(0)
	, m_35(1)
	, m_36(TheWritableGlobalData->m_flag04)
	, m_38(0)
	, m_3c(0)
	, m_40(1)
{
}
