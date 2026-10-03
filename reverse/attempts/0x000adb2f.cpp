// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z
// partial score=0.55 date=2026-10-03
// cl: /O1 /MD
// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z @0x000ADB2F 90B
// Bitmap set/clear by pitch: width at +0x8, height at +0xC, pitch at +0x34,
// base at +0x38, end at +0x3C.  Callers 0x000ADDC2 (unclaimed), unblocks
// 0x000ADCE3.  Layout from the retail body; class identity unproven, so the
// class is address-named.
//
// Gap remaining: retail materialises the span as `mov edx,[ecx+0x3c] / sub
// edx,[ecx+0x38]` (end loaded FIRST) while this spelling loads +0x38 first and
// folds the subtraction the other way, so cl keeps three instructions where
// retail has two and the whole tail shifts 3 bytes.  Retail then holds the
// read-modify-write byte in bl (with a push/pop ebx pair) where this emits
// cl; both are register-allocation choices, not spelling differences, so the
// `char bit` local below is the only change that reproduces `mov al,1 / shl
// al,cl` (an int bit gives `xor eax,eax / inc eax / shl eax,cl`).
// Refuted: /O1 /O2 /Ot /Os /Ob0 /Ob1 /Gs /Gr /GF /Zp1 /Zp8 /Zp16 (identical
// except /Ot and /O2, which reorder the two argument loads and break the
// prologue); volatile span members, volatile byte load, split pointer, nested
// vs chained bound tests, unsigned vs int offset, signed vs char bit.
class Rva000ADB2F
{
public:
	void rva000ADB2F(int x, int y, bool set);

private:
	char m_pad0[8];
	int m_8;
	int m_c;
	char m_pad1[0x34 - 0x10];
	int m_34;
	int m_38;
	int m_3C;
};

// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z present-unmatched
void Rva000ADB2F::rva000ADB2F(int x, int y, bool set)
{
	if (x < 0 || y < 0 || y >= m_c || x >= m_8)
		return;
	int off = m_34 * y + (x >> 3);
	if ((unsigned int)off >= (unsigned int)(m_3C - m_38))
		return;
	unsigned char *slot = (unsigned char *)(m_38 + off);
	char bit = 1;
	bit = (char)(bit << (x & 7));
	unsigned char b = *slot;
	if (set)
		b |= (unsigned char)bit;
	else
		b &= (unsigned char)~bit;
	*slot = b;
}