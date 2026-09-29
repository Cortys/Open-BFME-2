// ?rva00583CB4@Rva005843DA@@QAEXH@Z
// partial score=0.93 date=2026-09-29
// ?rva00583CB4@Rva005843DA@@QAEXH@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva00583CB4@Rva005843DA@@QAEXH@Z 44B @0x00583CB4: virtual slot 11
// (offset 0x2C) of vtable 0x0086FC80 installed by rowed ctor 0x005843DA.
// Bounds-checked store of 3 to field +0 of the 28-byte element at the given
// index in the byte buffer at +8/+0x0C; early-out for negative or
// out-of-range indices. Element type and method name are honest-address
// placeholders; offsets and 0x1C stride come from retail immediates.

struct Rva00583CB4Elem
{
	int m_00;
	unsigned char m_pad04[24];
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva005843DA
{
public:
	void rva00583CB4(int index);
private:
	unsigned char m_pad00[8];
	char *m_start; // +8
	char *m_finish; // +0x0C
};

// ?rva00583CB4@Rva005843DA@@QAEXH@Z present-unmatched
void Rva005843DA::rva00583CB4(int index)
{
	if (index < 0)
		return;
	int count = (m_finish - m_start) / 28;
	if ((unsigned int)index >= (unsigned int)count)
		return;
	_ReadWriteBarrier();
	char *start = m_start;
	int scaled = index * 28;
	*(int *)(start + scaled) = 3;
}
