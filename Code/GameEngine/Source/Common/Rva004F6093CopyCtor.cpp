// ??0Rva004F6093Holder@@QAE@ABV0@@Z @0x004F6093 23B
// Copy ctor for ref-counted pointer holder (m_ptr at +0); pointee refcount at +0xB0.
// Evidence: 12 callers incl 0x0040CB21 and 0x0040CC01 (which passes &entry.second as const Holder&);
// shared Holder layout with 0x0040CBD7 keyed copy-out.
struct Rva004F6093Ref
{
	char m_pad[0xB0];
	int m_refCount;
};

class Rva004F6093Holder
{
public:
	Rva004F6093Holder(const Rva004F6093Holder &other);
private:
	Rva004F6093Ref *m_ptr;
};

Rva004F6093Holder::Rva004F6093Holder(const Rva004F6093Holder &other)
{
	Rva004F6093Ref *t = other.m_ptr;
	m_ptr = t;
	if (t)
		++t->m_refCount;
}
