// ?Rva002E0D02Get@@YAHPAURva002E0D02Arg@@@Z
// partial score=0.93 date=2026-09-30
// ?Rva002E0D02Get@@YAHPAURva002E0D02Arg@@@Z
// partial score=0.93 date=2026-09-29
// cl: /O1
// ?Rva002E0D02Get@@YAHPAUArg@@@Z @ 0x002E0D02 100B sum via indexed get.
// Evidence: neighbours Rva002E0CD4Get plus Rva002E08A2Insert share /O1; rowed get@Rva0040CB2CIndexedField 0x0040CB2C plus EBP frame plus and-mem-zero plus sar-3 so /O1; ret is cdecl 1 arg; unblocks 0x005235D5 plus 0x005D13E2.
struct Entry8
{
	int first;
	void *second;
};
class Rva0040CB2CIndexedField
{
public:
	int get(int index) const;
	char m_pad[0x40];
	Entry8 *m_begin;
	Entry8 *m_end;
};
struct Mid78Holder
{
	char m_pad[0x78];
	Rva0040CB2CIndexedField *m_78;
};
struct ElemInner
{
	Mid78Holder *m_00;
};
struct Elem
{
	ElemInner *m_ptr;
};
struct Rva002E0D02Arg
{
	char m_pad[0x1B8];
	Elem *m_1B8;
	Elem *m_1BC;
};
// ?Rva002E0D02Get@@YAHPAURva002E0D02Arg@@@Z present-unmatched
int __cdecl Rva002E0D02Get(Rva002E0D02Arg *arg)
{
	int total;
	int i;
	char *base = (char *)arg;
	Elem *end = *(Elem **)(base + 0x1BC);
	base += 0x1B8;
	Elem *b = *(Elem **)base;
	total = 0;
	if (b != end) {
		while (true) {
			Rva0040CB2CIndexedField *f = b->m_ptr->m_00->m_78;
			int cnt = (int)((char *)f->m_end - (char *)f->m_begin) >> 3;
			i = 0;
			if (cnt > 0) {
				while (true) {
					int v = f->get(i);
					total += *(int *)((char *)v + 0x90);
					++i;
					if (i >= cnt)
						break;
				}
			}
			b = (Elem *)((char *)b + 4);
			if (b == end)
				break;
		}
	}
	return total;
}
