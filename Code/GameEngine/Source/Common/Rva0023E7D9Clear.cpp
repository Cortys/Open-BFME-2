// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva0023E7D9@Rva0023E7D9@@QAEXXZ — RVA 0x0023E7D9, 97B.
// Two-list clear: delete-list at +0x48 with next at +0x14, then STL int
// list at +0x50 walked via member iterator at +0x4c, each nonzero entry
// emptied through BfmeThingEC::bfmeTakeEC and free, then list cleared.
// Evidence: retail loop bytes; callees 0x0002FD60 0x006021A4 0x00030830
// 0x0023DAA5; callers at 0x0023F88C 0x00243BA0 0x002442A4.
#include <list>

class BfmeThingEC
{
public:
	virtual void bfmeSpare000EC(void) = 0;
	virtual void bfmeSpare001EC(void) = 0;
	virtual void bfmeDoEC(void) = 0;

	int bfmeTakeEC(int *out);
};

extern "C" void __cdecl free(void *block);
void __cdecl operator delete(void *block);

struct Rva0023E7D9Link
{
	char m_pad[0x14];
	Rva0023E7D9Link *m_next;
};

class Rva0023E7D9
{
public:
	void rva0023E7D9();
	char m_lead[0x48];
	Rva0023E7D9Link *m_head;
	_STL::list<int, _STL::allocator<int> >::iterator m_cur;
	_STL::list<int, _STL::allocator<int> > m_list;
};

void Rva0023E7D9::rva0023E7D9()
{
	while (m_head != 0)
	{
		Rva0023E7D9Link *next = m_head->m_next;
		operator delete(m_head);
		m_head = next;
	}
	for (m_cur = m_list.begin(); m_cur != m_list.end(); ++m_cur)
	{
		int v = *m_cur;
		if (v != 0)
		{
			int tmp;
			int r = ((BfmeThingEC *)v)->bfmeTakeEC(&tmp);
			free((void *)r);
		}
	}
	m_list.clear();
	m_head = 0;
}
