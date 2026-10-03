// ??1Rva005DCE08@@QAE@XZ
// partial score=0.95 date=2026-10-03
// ??1Rva005DCE08@@QAE@XZ
// partial score=0.95 date=2026-09-29
// ??1Rva005DCE08@@QAE@XZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHs
// ??1Rva005DCE08@@QAE@XZ retail 0x005DCE08 90B
// Evidence: caller 0x005AD948 deleting-dtor shape calls it then operator delete; callers 0x005AD948 0x005ADA66; vector +4/+8 freed via rowed free 0x00030830; elements via virtual slot0(0) plus rowed delete 0x0002FD60
extern "C" void __cdecl free(void *block);
void __cdecl operator delete(void *block);

class Rva005DCE08Elem
{
public:
	virtual void *v00(int v);
};

struct MallocPtr005DCE08
{
	void *p;
	~MallocPtr005DCE08() { if (p) free(p); }
};

class Rva005DCE08
{
public:
	~Rva005DCE08();
private:
	char m_pad00[4];
	MallocPtr005DCE08 m_buf;
	Rva005DCE08Elem **m_end;
};

Rva005DCE08::~Rva005DCE08()
{
	for (Rva005DCE08Elem **p = (Rva005DCE08Elem **)m_buf.p; p != m_end; ++p)
		::operator delete(*p ? (*p)->v00(0) : 0);
}
