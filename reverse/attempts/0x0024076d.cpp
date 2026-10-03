// ??0Rva0024076D@@QAE@XZ
// partial score=0.9 date=2026-10-03
// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc /arch:SSE
// ??0Rva0024076D@@QAE@XZ, retail 0x0024076D, 162 bytes.
// Ctor: int +0x00, Region3D[3] +0x04 (0x10 each via vector iterator), ints +0x34..0x40, list base +0x44, ints +0x48/+0x4C, 3x4 identity floats over +0x04.
// Evidence: EH_prolog cookie 0xb71272, vector ctor (3 x 0x10 with Region3D ctor 0x47A6A9), List_base ctor 0x4EC36C, float const g_Va00BBB8D8, caller 0x248869.
struct Region3D
{
	Region3D();
	float a;
	float b;
	float c;
	float d;
};
extern float g_Va00BBB8D8;
namespace _STL
{
	template <class T> class allocator
	{
	};
	template <class T, class A> class _List_base
	{
	public:
		_List_base(const A &);
		~_List_base();
		void *m_node;
	};
}
class Rva0024076D_EmptyBase
{
public:
	Rva0024076D_EmptyBase() {}
	~Rva0024076D_EmptyBase();
};
class Rva0024076D : public Rva0024076D_EmptyBase
{
public:
	Rva0024076D();
private:
	int m_00;
	Region3D m_04[3];
	int m_34;
	int m_38;
	int m_3C;
	int m_40;
	_STL::_List_base<int, _STL::allocator<int> > m_44;
	int m_48;
	int m_4C;
};
// ??0Rva0024076D@@QAE@XZ present-unmatched
Rva0024076D::Rva0024076D()
	: m_00(0)
	, m_44(_STL::allocator<int>())
{
	float one = g_Va00BBB8D8;
	m_04[0].a = one;
	m_04[0].b = 0.0f;
	m_04[0].c = 0.0f;
	m_04[0].d = 0.0f;
	m_04[1].a = 0.0f;
	m_04[1].b = one;
	m_04[1].c = 0.0f;
	m_04[1].d = 0.0f;
	m_04[2].a = 0.0f;
	m_04[2].b = 0.0f;
	m_04[2].c = one;
	m_04[2].d = 0.0f;
	m_34 = 0;
	m_38 = 0;
	m_3C = 0;
	m_40 = 0;
	m_48 = 0;
	m_4C = 0;
}
