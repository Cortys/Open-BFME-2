// ??0Made002CC64B@@QAE@XZ
// partial score=0.93 date=2026-09-29
// ??0Made002CC64B@@QAE@XZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD /DNDEBUG /arch:SSE /GX-
//
// ??0Made002CC64B@@QAE@XZ @0x00508BE5 (97B).
// AttributeModifierNugget ctor: base Rva00507823 at 0x0050775B, vtable
// 0x00864370, int 0 at +0x128, BitFlags<11> at +0x138 via rowed 0x003B31AD,
// ints 0x1D at +0x12C and 0 at +0x13C, floats 0.0 at +0x130 and constant
// at +0x134 via 0x007C7468, duplicate memset 4 at +0x138 via 0x006291AE.
// Size 0x140 from WeaponNuggetParse news. Caller parseAttributeModifierNugget.
// Same duplicate-memset idiom as Made002CC5E1 precedent.
#include <string.h>

typedef int Int;
typedef unsigned int UnsignedInt;

template <int NUM_BITS>
class BitFlags
{
public:
	BitFlags() throw();
private:
	UnsignedInt m_words[1];
};

class Rva00507823
{
public:
	virtual ~Rva00507823();
	Rva00507823();
private:
	unsigned char m_pad[0x128 - 4];
};

class Made002CC64B : public Rva00507823
{
public:
	Made002CC64B();
private:
	int m_128;
	int m_12C;
	float m_130;
	float m_134;
	BitFlags<11> m_138;
	int m_13C;
};

Made002CC64B::Made002CC64B()
	: m_128(0)
{
	m_12C = 0x1D;
	m_130 = 0.0f;
	m_134 = 1.0f;
	memset(&m_138, 0, 4);
	m_13C = 0;
}
