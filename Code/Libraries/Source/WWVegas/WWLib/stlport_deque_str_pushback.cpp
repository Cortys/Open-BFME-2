// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva00058B90@Rva00058B90@@QAEXABVRva0036CA00Str@@@Z @0x00058B90 45B: deque<Rva0036CA00Str> push_back fast path; cur vs last-1 plus _Construct plus aux slow path; caller chain from 0x0005800A landing; callees rowed _Construct 0x2393AA plus aux 0x5800A.
class OpaqueRefCounted { public: void Release_Ref(); };
class Rva0036CA00Str {
	void *m_item;
public:
	__declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &o);
	~Rva0036CA00Str();
};
// ??1Rva0036CA00Str@@QAE@XZ present-unmatched
inline Rva0036CA00Str::~Rva0036CA00Str()
{
	if (m_item)
		((OpaqueRefCounted *)m_item)->Release_Ref();
}
namespace _STL {
template <class T1, class T2> void _Construct(T1 *p, const T2 &v);
template <class T> struct _Deque_it {
	T *_M_cur; T *_M_first; T *_M_last; T **_M_node;
};
}
class Rva0005800A {
public:
	void rva0005800A(const Rva0036CA00Str &t);
};
class Rva00058B90 {
public:
	void rva00058B90(const Rva0036CA00Str &t);
private:
	_STL::_Deque_it<Rva0036CA00Str> _M_start;
	_STL::_Deque_it<Rva0036CA00Str> _M_finish;
	Rva0036CA00Str **_M_map;
	unsigned int _M_map_size;
};
void Rva00058B90::rva00058B90(const Rva0036CA00Str &t)
{
	if (_M_finish._M_cur != _M_finish._M_last - 1) {
		_STL::_Construct(_M_finish._M_cur, t);
		++_M_finish._M_cur;
	} else {
		((Rva0005800A *)this)->rva0005800A(t);
	}
}
