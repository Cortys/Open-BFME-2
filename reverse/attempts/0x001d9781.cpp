// ?rva001D9781@Rva001D98BD@@QAEHXZ
// partial score=0.92 date=2026-09-30
// ?rva001D9781@Rva001D98BD@@QAEHXZ
// partial score=0.92 date=2026-09-30
// cl: /Os /DNDEBUG /MD /arch:SSE
//
// ?rva001D9781@Rva001D98BD@@QAEHXZ retail 0x001D9781 88B unlock
// Same class as Rva001D98BD in Rva001D98BD.cpp: +0xB0 type 5 internal over
// +0x80/+0x84 8B entries. Evidence: self-call 0x001D97AC; callers 0x0005D869
// 0x00278378 0x0030DFE7 0x00433A78 0x00433ACC; +0x4C bit0 early-true; 0/3 early-true.

class Rva001D98BD
{
public:
	int rva001D9781();
private:
	unsigned char m_pad00[0x4C];
	unsigned char m_4C; // +0x4C bit0
	unsigned char m_pad4D[0x80 - 0x4D];
	struct Entry
	{
		Rva001D98BD *child;
		int unk;
	};
	Entry *m_begin; // +0x80
	Entry *m_end; // +0x84
	unsigned char m_pad88[0xB0 - 0x88];
	int m_B0; // +0xB0
};

// ?rva001D9781@Rva001D98BD@@QAEHXZ present-unmatched
int Rva001D98BD::rva001D9781()
{
	int t = m_B0;
	if (t == 5) {
		if ((m_4C & 1) == 0) {
			Entry *beg = m_begin;
			Entry *end = m_end;
			for (Entry *p = beg; p != end; ++p) {
				Rva001D98BD *child = p->child;
				if (child) {
					unsigned char c = (unsigned char)child->rva001D9781();
					if (c)
						return 1;
				}
			}
			return 0;
		} else {
			return 1;
		}
	} else {
		if (t == 0 || t == 3 || (m_4C & 1))
			return 1;
		return 0;
	}
}
