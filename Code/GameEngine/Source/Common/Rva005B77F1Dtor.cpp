// cl: /Ireference/shims/bfmelist /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva005B77F1@@UAE@XZ @0x005B77F1 151B.
// Outer dtor over vtable 0x873918: clear list +0x14 then delete pointees in list +0xC via 0x005B72E7 plus erase then base GameEngineDeletingBase.
// Evidence: chain from 0x005B72E7 you landed; callers 0x005B7888 deleting dtor; lists via rowed list<int> clear erase base dtor.
#include <list>

void __cdecl operator delete(void *p);

class AsciiStringMember
{
public:
	~AsciiStringMember();
};

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

class Rva005B72E7
{
public:
	~Rva005B72E7();
};

class Rva005B77F1 : public GameEngineDeletingBase
{
public:
	virtual ~Rva005B77F1();
private:
	_STL::list<int, _STL::allocator<int> > m_listC;
	int m_pad10;
	_STL::list<int, _STL::allocator<int> > m_list14;
};

Rva005B77F1::~Rva005B77F1()
{
	m_list14.clear();
	for (_STL::list<int, _STL::allocator<int> >::iterator it = m_listC.begin(); it != m_listC.end(); )
	{
		Rva005B72E7 *p = (Rva005B72E7 *)(int)*it;
		if (p != 0)
		{
			p->~Rva005B72E7();
			::operator delete(p);
		}
		it = m_listC.erase(it);
	}
}
