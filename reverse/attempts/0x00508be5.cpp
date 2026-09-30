// ??0Made002CC64B@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??0Made002CC64B@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /MD /DNDEBUG /arch:SSE /GX-
// ??0Made002CC64B@@QAE@XZ @0x00508BE5 97B: AttributeModifierNugget ctor over
// rowed base Rva00507823; vtable 0x864370, and-zero +0x128, BitFlags11 at
// +0x138 via rowed ctor, 0.0f at +0x130, pi at +0x134 via 0x7C7468, 0x1D at
// +0x12C, duplicate memset 4 at +0x138, and-zero +0x13C. Caller
// parseAttributeModifierNugget.
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

// ??0Made002CC64B@@QAE@XZ present-unmatched
Made002CC64B::Made002CC64B() : m_128(0)
{
	m_12C = 0x1D;
	m_130 = 0.0f;
	m_134 = 3.1415927f;
	memset(&m_138, 0, 4);
	m_13C &= 0;
}
