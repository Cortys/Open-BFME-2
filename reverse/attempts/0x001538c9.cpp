// ?rva001538C9@?$vector@URva005F8F96@@V?$allocator@URva005F8F96@@@_STL@@@_STL@@QAEXPAURva00468520@@ABU4@ABUTag@@I_N@Z
// partial score=0.92 date=2026-10-03
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?rva001538C9@?$vector@URva005F8F96@@V?$allocator@URva005F8F96@@@_STL@@@_STL@@QAEXPAURva00468520@@ABU4@ABUTag@@I_N@Z, retail 0x001538C9, 178 bytes.
// Vector<Rva005F8F96> growth overflow with 8-byte stride (sar 3) reusing rowed
// Rva00468520 copy/fill/init helpers plus rowed allocator<BfmeE8> allocate and
// rowed vector<Rva005F8F96> _M_clear. Same ebp-tag shape as _M_allocate_and_copy
// 0x00153489; caller push_back 0x00153A27 with fill 1 atend true.
struct Rva00468520Obj
{
	int m_00;
	int m_04;
};
class Rva00468520
{
public:
	Rva00468520Obj *m_00;
	int m_04;
};
struct Tag
{
	Tag() {}
};
struct BfmeE8
{
	int a;
	int b;
};
struct TargetRef00217D4C
{
	virtual void *destroy(unsigned int flags);
	int references;
};
struct Rva005F8F96
{
	~Rva005F8F96();
	TargetRef00217D4C *m_00;
	int m_04;
};
void __cdecl Rva004F6B7BInit(Rva00468520 *dst, const Rva00468520 *src);
Rva00468520 *__cdecl Rva00153425Copy(Rva00468520 *first, Rva00468520 *last, Rva00468520 *result, const Tag &tag);
Rva00468520 *__cdecl Rva0015344BFillN(Rva00468520 *result, unsigned int count, const Rva00468520 &value, const Tag &tag);
namespace _STL
{
template <class T> class allocator
{
public:
	T *allocate(unsigned int n, const void *hint) const;
};
template <class T, class Alloc> class vector
{
public:
	typedef T *pointer;
	typedef unsigned int size_type;
protected:
	void _M_clear();
public:
	void rva001538C9(Rva00468520 *pos, const Rva00468520 &x, const Tag &tag, unsigned int fill_len, bool atend);
private:
	pointer m_start;
	pointer m_finish;
	struct Proxy : public allocator<T>
	{
		pointer m_data;
	};
	Proxy m_endOfStorage;
};
}
void _STL::vector<Rva005F8F96, _STL::allocator<Rva005F8F96> >::rva001538C9(Rva00468520 *pos, const Rva00468520 &x, const Tag &tag, unsigned int fill_len, bool atend)
{
	unsigned int old_size = (unsigned int)(m_finish - m_start);
	unsigned int len = old_size + *(old_size < fill_len ? &fill_len : &old_size);
	Rva00468520 *new_start = (Rva00468520 *)((allocator<BfmeE8> *)&m_endOfStorage)->allocate(len, 0);
	Rva00468520 *new_finish = new_start;
	new_finish = Rva00153425Copy((Rva00468520 *)m_start, pos, new_start, Tag());
	if (fill_len == 1)
	{
		Rva004F6B7BInit(new_finish, &x);
		++new_finish;
	}
	else
	{
		new_finish = Rva0015344BFillN(new_finish, fill_len, x, Tag());
	}
	if (!atend)
	{
		new_finish = Rva00153425Copy(pos, (Rva00468520 *)m_finish, new_finish, Tag());
	}
	_M_clear();
	m_start = (Rva005F8F96 *)new_start;
	m_finish = (Rva005F8F96 *)new_finish;
	m_endOfStorage.m_data = (Rva005F8F96 *)(new_start + len);
}
