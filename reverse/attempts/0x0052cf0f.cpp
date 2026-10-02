// ??0Rva0052CFB1@@QAE@ABVAsciiString@@@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0052CFB1@@QAE@ABVAsciiString@@@Z @0x0052CF0F 156B: ctor stores vtable 0x00868780 copies name zeroes vectors sets ints floats.
// Evidence: vtable 0x00868780 at +0 (same as dtor 0x0052CFB1 own unit), StringBase copy 0x000365F0 from param, vector_base 0x00211E58 twice, floats g_00C686F4 g_00C686F8, ints 0xb4 0x1d4c 0x9c4, caller 0x0052D0CD in 0x0052D04E.
#include "ascii_string.h"
#include <vector>
struct BfmeE16 { float x, y, z, w; };
extern float g_00C686F4;
extern float g_00C686F8;
struct EmptyBase0052CF0F {
	EmptyBase0052CF0F() {}
	~EmptyBase0052CF0F();
};
class Rva0052CFB1 : public EmptyBase0052CF0F {
public:
	Rva0052CFB1(const AsciiString &s);
	virtual ~Rva0052CFB1();
private:
	AsciiString m_04;
	int m_08;
	_STL::vector<BfmeE16> m_0c;
	int m_18;
	void *m_1c;
	void *m_20;
	_STL::vector<BfmeE16> m_24;
	AsciiString m_30;
	AsciiString m_34;
	int m_38;
	int m_3c;
	int m_40;
	float m_44;
	float m_48;
	bool m_4c;
	bool m_4d;
	bool m_4e;
};
Rva0052CFB1::Rva0052CFB1(const AsciiString &s)
	: EmptyBase0052CF0F()
	, m_04(s)
	, m_08(0)
	, m_0c()
	, m_18(0)
	, m_1c(0)
	, m_20(0)
	, m_24()
	, m_30()
	, m_34()
	, m_38(0xb4)
	, m_3c(0x1d4c)
	, m_40(0x9c4)
	, m_44(g_00C686F4)
	, m_48(g_00C686F8)
	, m_4c(false)
	, m_4d(false)
	, m_4e(false)
{
}
