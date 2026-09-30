// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z
// partial score=0.96 date=2026-09-30
// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /G7 /DNDEBUG /MD
// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z @ 0x00285F43 102B
// Bitfield pack helper: dest = mgr->arrays[idx2][idx1], word copy from src+0x314
// to dest+4, then three masked replaces into dest+8 from src+0x31C/0x318/0x320
// with masks 0x3FF/0x3FFC0000/0x3FC00. Callers at 0x00286413 0x002878EF 0x00287AC7.
class Rva00285F43Dest
{
public:
	int unk0;
	unsigned short w4;
	unsigned short pad6;
	unsigned int b10 : 10;
	unsigned int b8 : 8;
	unsigned int b12 : 12;
	unsigned int pad2 : 2;
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
	const unsigned short *pw = &src->w314;
	Rva00285F43Dest *d = m_arrays[arrIdx] + elemIdx;
	d->w4 = *pw;
	d->b10 = src->f31C;
	d->b12 = src->f318;
	d->b8 = src->f320;
}

// ?rva00285F43@Rva00285F43Mgr@@QAEXHHPAURva00285F43Src@@@Z present-unmatched
