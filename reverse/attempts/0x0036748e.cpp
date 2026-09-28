// ?rva0036748E@Rva0036748E@@QAEXH_N@Z
// partial score=0.93 date=2026-09-28
// ?rva0036748E@Rva0036748E@@QAEXH_N@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// ?rva0036748E@Rva0036748E@@QAEXH_N@Z @0x0036748E (37B).
// Rva0036748E::rva0036748E(): sets or clears bit (1u<<bit) in the dword at
// +0x4b8 based on the bool enable flag. Retail computes mask via xor/inc/shl,
// then or for set or not/and for clear. Landing this unblocks three 14B
// wrappers at 0x368654 (bit 7) 0x36940A (bit 5) 0x36C897 (bit 3) which pass
// through ECX and fix the bit arg. Callers include 0x3685C7 0x36865A 0x369410
// 0x36C89D. No donor; identity is honest-address (thiscall proven by ECX use).

typedef unsigned int UnsignedInt;

class Rva0036748E
{
public:
	void rva0036748E(int bit, bool enabled);

private:
	unsigned char m_pad[0x4b8];
	UnsignedInt m_flags;
};

void Rva0036748E::rva0036748E(int bit, bool enabled)
{
	UnsignedInt mask = 1u << bit;
	if (enabled)
		m_flags |= mask;
	else
		m_flags &= ~mask;
}
