// cl: /Ireference/shims/bfmelist /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva0039225E@@UAE@XZ 89B @0x0039225E: virtual dtor storing vtable 0x0081A088. Layout base 0xC plus list<int> at +0xC (size 4) plus Rva0039205C at +0x10 (size 12). Retail calls the Rva dtor twice on the same address (explicit early destroy plus implicit) then list base then GameEngineDeletingBase. Evidence: vptr store plus rowed callees plus ??_G caller at 0x00392DA4. /EHs keeps the list state store.
#include <list>

class Rva004D9A3C
{
public:
	~Rva004D9A3C();
};

class Rva0039205C
{
public:
	~Rva0039205C();
private:
	int m_unk00; // +0
	unsigned char m_pad04[4]; // +4
	Rva004D9A3C *m_array08; // +8
};

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
private:
	char m_pad04[4];
	void *m_member08;
};

class Rva0039225E : public GameEngineDeletingBase
{
public:
	virtual ~Rva0039225E();
private:
	_STL::list<int, _STL::allocator<int> > m_list0C;
	Rva0039205C m_obj10;
};

Rva0039225E::~Rva0039225E()
{
	m_obj10.~Rva0039205C();
}
