// ?rva0020F5B3@Rva0020F5B3@@QAEXXZ
// partial score=0.97 date=2026-10-03
// cl: /O1 /EHsc
// ?rva0020F5B3@Rva0020F5B3@@QAEXXZ @0x0020F5B3 210B
// Unlock callee of 0x002102CA 0x0052C161 0x0020F712; clear helper vector then re-append listeners then indexed collect.
// Evidence: retail mov ecx [esi+0x4c] test je; push [ecx+4] push [ecx] call vector erase 0x0031BD55; outer vec at +0x2c/+0x30 sar 2 loops; push [eax+0x198] call List append 0x005A0B4C; inner (end-begin)/24 via push 0x18 cdq idiv with +0x1a8/+0x1ac and +8 int then call rva 0x003EF7DF; callers unclaimed.
namespace _STL {
template <typename T> class allocator;
template <typename T, typename A> class vector
{
public:
	void **erase(void **first, void **last);
	void **begin() const { return m_begin; }
	void **end() const { return m_end; }
private:
	void **m_begin;
	void **m_end;
	void **m_cap;
};
}
struct Rva002BA8F1Listener;
class Rva005A0B4CList
{
public:
	void append(Rva002BA8F1Listener *p);
};
struct Rva003EF7DFDest;
class Rva003EF7DF
{
public:
	void rva003EF7DF(Rva003EF7DFDest *dest, int value);
};
struct Rva0020F5B3Elem
{
	char m_pad00[0x198];
	void *m_ptr198;
	char m_pad19C[0xC];
	char *m_arrBegin;
	char *m_arrEnd;
};
template <typename T> struct SimpleVec
{
	T *m_begin;
	T *m_end;
	T *m_cap;
	unsigned int size() const { return (unsigned int)(m_end - m_begin); }
	T operator[](unsigned int i) const { return m_begin[i]; }
};
class Rva0020F5B3
{
public:
	void rva0020F5B3();
private:
	char m_pad00[0x2C];
	SimpleVec<Rva0020F5B3Elem *> m_2C;
	char m_pad38[0x14];
	void *m_4C;
};
void Rva0020F5B3::rva0020F5B3()
{
	if (m_4C == 0)
		return;
	_STL::vector<void *, _STL::allocator<void *> > *vec = (_STL::vector<void *, _STL::allocator<void *> > *)m_4C;
	vec->erase(vec->begin(), vec->end());
	for (unsigned int i = 0; i < m_2C.size(); ++i)
	{
		Rva0020F5B3Elem *e = m_2C[i];
		((Rva005A0B4CList *)m_4C)->append((Rva002BA8F1Listener *)e->m_ptr198);
	}
	for (unsigned int j = 0; j < m_2C.size(); ++j)
	{
		Rva0020F5B3Elem *e = m_2C[j];
		unsigned int off = 0;
		unsigned int k = 0;
		for (k = 0, off = 0; k < (unsigned int)((e->m_arrEnd - e->m_arrBegin) / 24); ++k, off += 24)
		{
			int v = *(int *)(off + e->m_arrBegin + 8);
			((Rva003EF7DF *)m_4C)->rva003EF7DF((Rva003EF7DFDest *)e->m_ptr198, v);
		}
	}
}
