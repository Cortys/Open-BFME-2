// ??0Rva0053FDE6@@QAE@ABV0@@Z
// partial score=0.86 date=2026-10-02
// Target copy [0x0053FF5F-0x0053FF92) returns receiver and pops 4.
// Native owner relationship: outer default at0x54000B calls landed0x53FDE6;
// outer copy0x540036 calls0x53FF5F; construct0x540070 calls outer copy.
// Four leading scalar copies then16-byte block then final scalar motivate
// block view; no original subobject type/name is asserted. Existing68B/16B
// initializers remain exact. New51B copy differs only save-placement; outer
// 29B copy matches its non-relocation bytes with inner copy pin unresolved.
// ??0Rva0053FDE6@@QAE@XZ
// partial score=0.90 date=2026-09-29
// cl: /O1 /arch:SSE /Ob0 /Oi /G7
// ??0Rva0053FDE6@@QAE@XZ, retail 0x0053FDE6, 68 bytes.
// Constructor: int 2 at +0, six floats 0.0 at +4 +8 +0xC +0x10 +0x14 +0x18
// via xorps/movss, 1.0f at +0x1C, global float 0x00BC74F0 at +0x20.
// Same int-2-plus-zeros-plus-global shape as rowed Rva00540D67 (45B) and
// Rva00540E82 (27B) in Rva00540E82Init.cpp. Evidence: no calls; callers at
// 0x00540013 and 0x00540B85; unblocks 0x0054000B and 0x00540B48.
#include <string.h>
extern float g_Va00BBB8D8;
extern float g_Va00BC74F0;

struct Rva0053FDE6Block16 { float m_10, m_14, m_18, m_1c; };

class Rva0053FDE6
{
public:
	Rva0053FDE6();
	Rva0053FDE6(const Rva0053FDE6 &);
	int m_00;
	float m_04;
	float m_08;
	float m_0c;
	Rva0053FDE6Block16 m_block;
	float m_20;
};

Rva0053FDE6::Rva0053FDE6()
{
    m_00=2; m_04=0.0f; m_08=0.0f; m_0c=0.0f;
    m_block.m_10=0.0f; m_block.m_14=0.0f; m_block.m_18=0.0f;
    m_block.m_1c=g_Va00BBB8D8; m_20=g_Va00BC74F0;
}

// ??0Rva0054000B@@QAE@XZ, retail 0x0054000B, 16 bytes.
// Outer ctor with int at +0 = 0 and inner Rva0053FDE6 at +4 via rowed ctor.
// /Ob0 keeps the inner call from inlining so retail keeps lea ecx [edx+4] call.
// Evidence: calls landed 0x0053FDE6; caller at 0x00540A54; unblocks 0x00540A26.
class Rva0054000B
{
public:
	Rva0054000B();
	Rva0054000B(const Rva0054000B &);
	int m_00;
	Rva0053FDE6 m_04;
};

Rva0054000B::Rva0054000B() : m_00(0)
{
}

Rva0054000B::Rva0054000B(const Rva0054000B &other)
    : m_00(other.m_00), m_04(other.m_04) {}

Rva0053FDE6::Rva0053FDE6(const Rva0053FDE6 &other)
    : m_00(other.m_00), m_04(other.m_04), m_08(other.m_08),
      m_0c(other.m_0c), m_block(other.m_block), m_20(other.m_20) {}

