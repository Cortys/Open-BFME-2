// ?wrapper@Rva00034C90@@QAEXXZ
// partial score=0.96 date=2026-10-03
// cl: /O2 /MD
extern void (__stdcall *g_bfmeAddRefAtBBA200)(void *);
extern void (__stdcall *g_bfmeReleaseAtBBA204)(void *);

class Rva00034C90Lock
{
public:
	void *m_obj;
	Rva00034C90Lock(void *obj) throw() : m_obj(obj)
	{
		if (m_obj)
		{
			g_bfmeAddRefAtBBA200(m_obj);
			++*(volatile int *)((char *)m_obj + 0x18);
		}
	}
	__declspec(nothrow) ~Rva00034C90Lock()
	{
		if (m_obj)
		{
			--*(volatile int *)((char *)m_obj + 0x18);
			g_bfmeReleaseAtBBA204(m_obj);
		}
	}
};

class Rva00034C90
{
public:
	void body();
	void wrapper();
private:
	char m_pad[0x4e4];
	void *m_pLock;
};

void Rva00034C90::wrapper()
{
	Rva00034C90Lock lock(m_pLock);
	body();
}
