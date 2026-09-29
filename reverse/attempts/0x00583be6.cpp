// ?rva00583BE6@Rva005843DA@@QAE_NH@Z
// partial score=0.94 date=2026-09-29
// ?rva00583BE6@Rva005843DA@@QAE_NH@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva00583BE6@Rva005843DA@@QAE_NH@Z 52B @0x00583BE6: virtual slot 7
// (offset 0x1C) of vtable 0x0086FC80 installed by rowed ctor 0x005843DA.
// Bounds-checked predicate on field +0 of the 28-byte element at the given
// index in the byte buffer at +8/+0x0C; false for negative or out-of-range
// indices. Sibling of banked slot-11 store at 0x00583CB4; same honest-address
// placeholders and 0x1C stride from retail immediates.

struct Rva00583BE6Elem
{
	int m_00;
	unsigned char m_pad04[24];
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva005843DA
{
public:
	bool rva00583BE6(int index);
private:
	unsigned char m_pad00[8];
	char *m_start; // +8
	char *m_finish; // +0x0C
};

// ?rva00583BE6@Rva005843DA@@QAE_NH@Z present-unmatched
bool Rva005843DA::rva00583BE6(int index)
{
	if (index >= 0)
	{
		int count = (m_finish - m_start) / 28;
		if ((unsigned int)index < (unsigned int)count)
		{
			_ReadWriteBarrier();
			return ((Rva00583BE6Elem *)m_start)[index].m_00 == 1;
		}
	}
	return false;
}
