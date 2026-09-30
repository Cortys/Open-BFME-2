// cl: /O1 /EHsc /MD
// ?rva0042C936@Rva0042C936@@QAEPAV1@UHolder0042C936@@@Z, retail 0x0042C936, 65 bytes.
// Setter with ownership-transfer holder: takes old at +0, stores released holder ptr,
// calls old virtual slot0 with 0, deletes returned pointer via rowed operator delete,
// returns this. Evidence: single caller 0x0042CA4B, __thiscall via ecx plus ret 4,
// chain sibling of 0x0042C1F9 with identical 65B shape and same // cl.
void __cdecl operator delete(void *p);

struct Rva0042C936Helper
{
	virtual void *virt0(int x);
};

struct Holder0042C936
{
	Rva0042C936Helper *p;
	~Holder0042C936();
	Rva0042C936Helper *release();
};

class Rva0042C936
{
public:
	Rva0042C936Helper *m_ptr;
	Rva0042C936 *rva0042C936(Holder0042C936 h);
};

// ??1Holder0042C936@@QAE@XZ present-unmatched
inline Holder0042C936::~Holder0042C936()
{
	if (p)
		::operator delete(p);
}

// ?release@Holder0042C936@@QAEPAURva0042C936Helper@@XZ present-unmatched
inline Rva0042C936Helper *Holder0042C936::release()
{
	Rva0042C936Helper *t = p;
	p = 0;
	return t;
}

Rva0042C936 *Rva0042C936::rva0042C936(Holder0042C936 h)
{
	Rva0042C936Helper *old = m_ptr;
	m_ptr = h.release();
	void *q = old ? old->virt0(0) : 0;
	::operator delete(q);
	return this;
}
