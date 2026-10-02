// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// Range erases of int-keyed pointer maps: STLport's _Rb_tree::erase(first, last)
// (the rowed set<AsciiString> instance in stlport_asciistring_set_base.cpp is
// the template, 68 bytes), copied whole. Each copy calls the rowed clear of its
// own tree, a placeholder member, and the ICF-folded STLport
// map<int, void *> erase(iterator) every one of these trees shares. Owners are
// the classes of those rowed clears; names keep the addresses.

#include <map>

typedef _STL::_Rb_tree<int, _STL::pair<const int, void *>, _STL::_Select1st<_STL::pair<const int, void *> >,
	_STL::less<int>, _STL::allocator<_STL::pair<const int, void *> > > IntPtrTree;

#define RANGE_ERASE(OWNER, CLEAR, SELF) \
class OWNER \
{ \
public: \
	void CLEAR(); \
	void SELF(IntPtrTree::iterator first, IntPtrTree::iterator last); \
}; \
\
void OWNER::SELF(IntPtrTree::iterator first, IntPtrTree::iterator last) \
{ \
	IntPtrTree *tree = reinterpret_cast<IntPtrTree *>(this); \
	if (first == tree->begin() && last == tree->end()) \
		CLEAR(); \
	else \
		while (first != last) \
			tree->erase(first++); \
}

RANGE_ERASE(Rva0007E971, rva0007FAC1, rva0007FB07)
RANGE_ERASE(Rva000D20A9, rva000D2294, rva000D22BD)
RANGE_ERASE(Rva00388EAE, rva00389129, rva003891E8)
RANGE_ERASE(Rva002EE9B7, rva002EE9B7, rva0046A967)
RANGE_ERASE(Rva004E7B13, rva004E7BAF, rva004E7BD8)
RANGE_ERASE(Rva001E6731, rva001E6731, rva001E675A)
RANGE_ERASE(Rva00362AB5, rva00362AB5, rva00362ADE)
