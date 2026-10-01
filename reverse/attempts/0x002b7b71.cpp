// ?rva002B7B71@Rva002B7B71@@QAEXXZ
// partial score=0.9 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002B7B71@Rva002B7B71@@QAEXXZ @0x002B7B71 74B clear vector at +0x124 via slot-0 virtual plus operator delete then rowed voidptr erase.
// Evidence: callees rowed 0x0002FD60 plus 0x0031BD55; callers 0x002B83E5 0x002B96CA 0x002B990A; same deleteInstance-plus-delete free path as Glo012F1028TypeClearEntries 0x002B7D50.
namespace _STL
{
template <class T>
class allocator
{
};
template <class T, class A>
class vector
{
public:
	T *m_start;
	T *m_finish;
	T *m_end_of_storage;
	T *erase(T *first, T *last);
};
}
void __cdecl operator delete(void *p);
struct Val002B7B71
{
	virtual void *virt0(int arg);
};
class Rva002B7B71
{
	char m_pad[0x124];
	_STL::vector<void *, _STL::allocator<void *> > m_vec124;
public:
	void rva002B7B71();
};
// ?rva002B7B71@Rva002B7B71@@QAEXXZ present-unmatched
void Rva002B7B71::rva002B7B71()
{
	_STL::vector<void *, _STL::allocator<void *> > *vec = &m_vec124;
	for (unsigned int i = 0; i < (unsigned int)(((char *)vec->m_finish - (char *)vec->m_start) >> 2); ++i)
	{
		Val002B7B71 *p = (Val002B7B71 *)vec->m_start[i];
		::operator delete(p ? p->virt0(0) : 0);
	}
	vec->erase(vec->m_start, vec->m_finish);
}
