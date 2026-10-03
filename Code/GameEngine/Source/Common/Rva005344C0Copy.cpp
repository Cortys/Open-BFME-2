// cl: /O1 /EHs /MD
//
// ??0Rva005344C0@@QAE@ABU0@@Z @0x00534676 (29B).
// Pair copy: copy first int then copy-construct second via rowed Rb_tree copy
// 0x00534581 (dup_00534581 object-symbol). Evidence: gap between erase
// 0x00534641 and clear 0x00534693 in RvaTreeValueEraseFamily.cpp with same
// /O1 /EHs /MD; callee rowed; caller 0x005346F5; returns this (MSVC ctor).
namespace _STL
{
template <class T> class allocator;
template <class T1, class T2> struct pair { ~pair(); };
template <class T> struct less;
template <class P> struct _Select1st;
template <class K, class V, class S, class C, class A> class _Rb_tree
{
public:
	_Rb_tree(const _Rb_tree &o);
};
}

typedef _STL::_Rb_tree<int, _STL::pair<const int, int>, _STL::_Select1st<_STL::pair<const int, int> >, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > IntTree00534581;

struct Rva005344C0
{
	int m_first;
	IntTree00534581 m_second;
	Rva005344C0(const Rva005344C0 &o);
};

Rva005344C0::Rva005344C0(const Rva005344C0 &o) : m_first(o.m_first), m_second(o.m_second)
{
}
