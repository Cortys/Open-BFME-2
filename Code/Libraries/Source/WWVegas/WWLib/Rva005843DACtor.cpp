// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva005843DA@@QAE@PAX@Z @0x005843DA 43B
// Derived ctor: base Rva005D6FCC at +0 via rowed 0x005D6FCC then vector<BfmeE16> at +8
// via rowed Vector_base 0x00211E58 with empty allocator temp at [ebp+0xb] plus bool at +0x14
// cleared; vtable 0x0086FC80 slot0; caller 0x00469319 news 0x18; same recipe as rowed
// ??0Rva00586D8E 0x00586D8E without the second ptr.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class Rva005D6FCC
{
public:
	Rva005D6FCC(void *held);
	virtual ~Rva005D6FCC();
	void *m_held;
};

class Rva005843DA : public Rva005D6FCC
{
public:
	Rva005843DA(void *held);
	virtual ~Rva005843DA();
private:
	_STL::vector<BfmeE16> m_vec; // +8
	bool m_flag; // +0x14
};

Rva005843DA::Rva005843DA(void *held)
	: Rva005D6FCC(held), m_vec(_STL::allocator<BfmeE16>())
{
	m_flag = false;
}
