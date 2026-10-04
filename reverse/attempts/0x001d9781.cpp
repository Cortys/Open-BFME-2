// ?rva001D9781@Rva001D98BD@@QAEHXZ
// partial score=0.97 date=2026-10-04
// cl: /Os /DNDEBUG /MD /arch:SSE
class Rva001D98BD
{
public:
	bool rva001D9781();
private:
	unsigned char m_pad00[0x4C];
	unsigned char m_4C;
	unsigned char m_pad4D[0x80 - 0x4D];
	struct Entry { Rva001D98BD *child; int unk; };
	Entry *m_begin;
	Entry *m_end;
	unsigned char m_pad88[0xB0 - 0x88];
	int m_B0;
};
bool Rva001D98BD::rva001D9781()
{
	if (m_B0 == 5) {
		if (m_4C & 1)
			return true;
		Entry *beg = m_begin;
		Entry *end = m_end;
		for (Entry *p = beg; p != end; ++p) {
			Rva001D98BD *child = p->child;
			if (child && child->rva001D9781())
				return true;
		}
		return false;
	}
	return (m_B0 == 0 || m_B0 == 3 || (m_4C & 1));
}
