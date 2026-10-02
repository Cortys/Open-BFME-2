// ??0Rva0043B1C9Tree@@QAE@XZ
// partial score=0.96 date=2026-10-02
// ??0Rva0043B1C9Tree@@QAE@XZ @0x0043B69C 25B
// partial score=0.96 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHsc
// Ctor for 0x9c-header tree (25B retail): EBP frame, calls rowed
// rva0043B214 with two stack dummies, returns this. Two distinct dummies
// give lea+push+lea+push 25B like retail but second lea is [ebp-2] vs
// retail [ebp-1]; single dummy CSEs to one lea+two pushes 22B. Trivial
// header handle (no dtor) keeps it EH-free like retail. Same class as
// rowed 0x43B1C9/0x43B214 siblings. Caller 0x0043B6F5.
namespace _STL
{
void __cdecl free(void *block);
template <class _Tp> class allocator
{
public:
	static _Tp *allocate(unsigned int __n, void const *__hint);
};
template <class _P, class _T, class _A> class _STLP_alloc_proxy
{
public:
	_STLP_alloc_proxy(const _A &__a, _P __p);
	_P _M_data;
};
}

inline void *__cdecl operator new(unsigned int, void *__p)
{
	return __p;
}

typedef unsigned int ProxyUInt;

class Rva0043B1C9HeaderHandle
{
public:
	void *m_header;
};

class Rva0043B1C9Tree
{
public:
	Rva0043B1C9Tree();
	Rva0043B1C9Tree *rva0043B1C9(void const *dummy);
	Rva0043B1C9Tree *rva0043B214(void const *d1, void const *d2);

private:
	Rva0043B1C9HeaderHandle m_handle;
	unsigned int m_count;
};

Rva0043B1C9Tree::Rva0043B1C9Tree()
{
	char dummy1;
	char dummy2;
	rva0043B214(&dummy1, &dummy2);
}
