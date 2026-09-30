// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z
// partial score=0.96 date=2026-09-30
// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z
// partial score=0.96 date=2026-09-30
// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z, retail 0x002FE8CC, 116 bytes.
// Unlock: inserts arg into list at +0xF8 by name at +4 via rowed compare,
// replacing duplicate name moving +8 and deleting via virtual slot0 plus
// operator delete. Evidence: unlock lane, callers 0x002FEA67 0x002FFED9.

template <typename T> struct StringInlineData
{
	int m_refCount;
	int m_length;
	T m_text[1];
};

template <typename T> class StringBase
{
public:
	int compare(const StringBase<T> &other) const;
private:
	StringInlineData<T> *m_data;
};

struct DataVirt
{
	virtual void *f(int x);
};

struct Subsystem
{
	void *m_vptr00;
	StringBase<char> m_name04;
	DataVirt *m_08;
	Subsystem *m_next0C;
	virtual void *g(int x);
};

class Rva002FE8CC
{
public:
	void rva002FE8CC(void *arg);
	char m_padF8[0xF8];
	Subsystem *m_headF8;
};

// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z present-unmatched
void Rva002FE8CC::rva002FE8CC(void *arg)
{
	Subsystem *incoming = (Subsystem *)arg;
	Subsystem *cur = m_headF8;
	if (cur != 0) {
		StringBase<char> &want = *(StringBase<char> *)((char *)incoming + 4);
		for (; cur; cur = cur->m_next0C) {
			StringBase<char> &have = *(StringBase<char> *)((char *)cur + 4);
			if (want.compare(have) == 0)
				break;
		}
		if (cur != 0) {
			DataVirt *d = cur->m_08;
			if (d != 0) {
				void *p = d->f(0);
				::operator delete(p);
			}
			cur->m_08 = incoming->m_08;
			incoming->m_08 = 0;
			incoming->m_next0C = 0;
			void *q = incoming->g(0);
			::operator delete(q);
			return;
		}
	}
	incoming->m_next0C = cur;
	m_headF8 = incoming;
}
