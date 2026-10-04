// ??$_M_allocate_and_copy@PAURva004F6986@@@?$vector@URva004F6986@@V?$allocator@URva004F6986@@@_STL@@@_STL@@IAEPAURva004F6986@@IPAU2@0@Z
// partial score=0.97 date=2026-10-04
// cl: /O1
//
// ??$_M_allocate_and_copy@PAURva004F6986@@@?$vector@URva004F6986@@V?$allocator@URva004F6986@@@_STL@@@_STL@@IAEPAURva004F6986@@IPAU2@0@Z @0x004F6BD8 45B
// vector<Rva004F6986>::_M_allocate_and_copy, 8-byte element.
// Allocates n slots through the end-of-storage proxy (allocator pinned at
// 0x00523D6C as ICF twin of rowed BfmeE8 allocate) and copies the range with
// the rowed copy at 0x004F6A88. Spelled after Rva004F6352AllocateCopy.
// Caller at 0x004F8B53 in reserve 0x004F8B21 with sar 3 stride 8.

struct Rva004F6986
{
	char _m[8];

public:
	Rva004F6986(const Rva004F6986 &that);
};

namespace _STL
{

struct __false_type
{
	__false_type()
	{
	}
};

template <class Type>
class allocator
{
public:
	Type *allocate(unsigned int n, const void *hint) const;
};

struct RvaAllocProxy
{
	allocator<Rva004F6986> m_alloc;
	Rva004F6986 *m_data;
};

template <class Type, class Allocator>
class vector
{
public:
	typedef Type *pointer;
	typedef unsigned int size_type;

protected:
	template <class ForwardIter>
	pointer _M_allocate_and_copy(size_type n, ForwardIter first,
		ForwardIter last);

private:
	pointer m_start;
	pointer m_finish;
	RvaAllocProxy m_endOfStorage;
};

template <class InputIter, class OutputIter>
OutputIter __uninitialized_copy(InputIter first, InputIter last,
	OutputIter result, const __false_type &tag);

}

template <class Type, class Allocator>
template <class ForwardIter>
Type *_STL::vector<Type, Allocator>::_M_allocate_and_copy(size_type n,
	ForwardIter first, ForwardIter last)
{
	Type *result = m_endOfStorage.m_alloc.allocate(n, 0);
	__uninitialized_copy(first, last, result, __false_type());
	return result;
}

template Rva004F6986 *_STL::vector<Rva004F6986, _STL::allocator<Rva004F6986> >::_M_allocate_and_copy<Rva004F6986 *>(unsigned int, Rva004F6986 *, Rva004F6986 *);
