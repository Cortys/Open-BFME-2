// ??0Rva001ECF66@@QAE@ABV0@@Z
// partial score=0.97 date=2026-09-30
// ??0Rva001ECF66@@QAE@ABV0@@Z
// partial score=0.97 date=2026-09-30
// cl: /G7 /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??0Rva001ECF66@@QAE@ABVRva001ECF66@@@Z at 0x001ECF66 96B: vector range copy-ctor over 36B elements.
// Evidence: get_allocator 0x21983A plus count idiv 0x24 plus _Vector_base 0x10E5A2 plus __uninitialized_copy 0x1ECD84 plus finish store; callees rowed; unblocks 0x001ED03C caller 0x001ED092. Helper names are the rowed generic spellings.

namespace _STL
{
template <class _Tp> struct allocator
{
	allocator();
	allocator(const allocator<_Tp> &);
};
struct AsciiString;
struct GeometryShape;
struct __false_type
{
	__false_type()
	{
	}
};
template <class _Tp, class _Alloc> class vector;
template <> class vector<AsciiString, allocator<AsciiString> >
{
public:
	allocator<AsciiString> get_allocator() const;
};
template <class _Tp, class _Alloc> struct _Vector_base;
template <> struct _Vector_base<GeometryShape, allocator<GeometryShape> >
{
	_Vector_base(unsigned int count, const allocator<GeometryShape> &alloc);
	~_Vector_base();
	GeometryShape *m_begin;
	GeometryShape *m_finish;
};
template <class _InputIter, class _ForwardIter>
_ForwardIter __uninitialized_copy(_InputIter first, _InputIter last, _ForwardIter dest, const __false_type &tag);
}

struct BfmeRecord001ECAF9
{
	char m_pad[36];
};

class Rva001ECF66 : public _STL::_Vector_base<_STL::GeometryShape, _STL::allocator<_STL::GeometryShape> >
{
public:
	Rva001ECF66(const Rva001ECF66 &src);
};

// ??0Rva001ECF66@@QAE@ABVRva001ECF66@@@Z present-unmatched
Rva001ECF66::Rva001ECF66(const Rva001ECF66 &src)
	: _STL::_Vector_base<_STL::GeometryShape, _STL::allocator<_STL::GeometryShape> >(
		(unsigned int)(((BfmeRecord001ECAF9 *)src.m_finish) - ((BfmeRecord001ECAF9 *)src.m_begin)),
		reinterpret_cast<const _STL::allocator<_STL::GeometryShape> &>(
			((const _STL::vector<_STL::AsciiString, _STL::allocator<_STL::AsciiString> > &)src).get_allocator()))
{
	m_finish = (_STL::GeometryShape *)_STL::__uninitialized_copy(
		(BfmeRecord001ECAF9 *)src.m_begin,
		(BfmeRecord001ECAF9 *)src.m_finish,
		(BfmeRecord001ECAF9 *)m_begin,
		_STL::__false_type());
}
