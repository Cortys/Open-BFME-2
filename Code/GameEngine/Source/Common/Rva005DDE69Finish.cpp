// cl: /O1 /G7 /MD
//
// ?rva005DDE69@Rva005DDE69@@QAEMIII@Z @0x005DDE69 54B. Bounds-checked wrapper
// over range-max 0x005DDCA5; count from byte range at +4/+8 divided by 0x18,
// returns 0x00BBB8DC float when index out of range, else delegates.
// Caller 0x005DE1B2. Honest address name. The read/write barrier keeps the
// compiler from caching m_begin across the idiv, which is the register shape
// retail uses; it emits no code.
extern float g_00BBB8DC;

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva005DDC6B
{
public:
	float rva005DDCA5(unsigned lo, unsigned hi);
};

class Rva005DDE69
{
public:
	float rva005DDE69(unsigned idx, unsigned lo, unsigned hi);
private:
	char m_pad00[4];
	char *m_begin;
	char *m_end;
};

float Rva005DDE69::rva005DDE69(unsigned idx, unsigned lo, unsigned hi)
{
	int count = (m_end - m_begin) / 0x18;
	_ReadWriteBarrier();
	if (idx >= (unsigned)count)
		return g_00BBB8DC;
	return ((Rva005DDC6B *)(m_begin + idx * 0x18))->rva005DDCA5(lo, hi);
}
