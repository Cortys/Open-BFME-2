// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z
// partial score=0.94 date=2026-09-30
// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z
// partial score=0.94 date=2026-09-30
// cl: /O1 /G7 /DNDEBUG /MD
//
// ?Rva00285F43Set@@YAXPAVRva00285F43Mgr@@HHPAURva00285F43Src@@@Z,
// retail 0x00285F43, 102 bytes. Bitfield pack helper: dest = mgr->arrays[idx2][idx1],
// word copy from src+0x314 to dest+4, then three masked replaces into dest+8 from
// src+0x31C/0x318/0x320 with masks 0x3FF/0x3FFC0000/0x3FC00. Callers at 0x00286413
// 0x002878EF 0x00287AC7; shares tail shape with 0x00285778.
class Rva00285F43Dest
{
public:
	int unk0;
	unsigned short w4;
	unsigned short pad6;
	unsigned int bits8;
	int padC[2];
};

struct Rva00285F43Src
{
	char pad[0x314];
	unsigned short w314;
	char pad316[2];
	unsigned int f318;
	unsigned int f31C;
	unsigned int f320;
};

class Rva00285F43Mgr
{
public:
	void rva00285F43(int arrIdx, int elemIdx, Rva00285F43Src *src);
private:
	char m_pad[0x70];
	Rva00285F43Dest **m_arrays;
};

void Rva00285F43Mgr::rva00285F43(int arrIdx, int elemIdx, Rva00285F43Src *src)
{
	int e = elemIdx;
	const unsigned short *pw = &src->w314;
	Rva00285F43Dest *base = m_arrays[arrIdx];
	Rva00285F43Dest *d = base + e;
	d->w4 = *pw;
	unsigned int t = src->f31C ^ d->bits8;
	t &= 0x3FF;
	d->bits8 ^= t;
	d->bits8 = (((src->f318 << 18) ^ d->bits8) & 0x3FFC0000) ^ d->bits8;
	d->bits8 = (((src->f320 << 10) ^ d->bits8) & 0x3FC00) ^ d->bits8;
}

// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z present-unmatched
