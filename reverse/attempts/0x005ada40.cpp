// ??1Rva005ADA40@@QAE@XZ
// partial score=0.96 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva005ADA40@@QAE@XZ @0x005ADA40 114B. Non-virtual dtor clearing holder
// array at +0/+4 (Rva005DCE08 elems via rowed dtor plus operator delete),
// then virtual v00(0) on +0x28 with delete and null, then free of buffer.
// Evidence: deleting dtor at 0x00506B58 calls here, rowed callee 0x005DCE08
// plus rowed delete 0x002FD60 plus rowed free 0x00030830, prev TU same array.
#include <vector>

class Rva005DCE08
{
public:
	~Rva005DCE08();
};

class Rva005DCE08Elem
{
public:
	virtual void *v00(int v);
};

void operator delete(void *p);

class Rva005ADA40
{
public:
	~Rva005ADA40();
private:
	_STL::vector<Rva005DCE08 *> m_vec; // +0
	char m_pad[0x28 - 12]; // +0xC..+0x27
	Rva005DCE08Elem *m_28; // +0x28
};

// ??1Rva005ADA40@@QAE@XZ present-unmatched
Rva005ADA40::~Rva005ADA40()
{
	for (Rva005DCE08 **it = m_vec.begin(); it != m_vec.end(); ++it) {
		Rva005DCE08 *p = *it;
		if (p) {
			p->~Rva005DCE08();
			::operator delete(p);
		}
	}
	if (m_28)
		::operator delete(m_28->v00(0));
	m_28 = 0;
}
