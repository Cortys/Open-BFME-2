// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// The same map<int,int> instantiation as stlport_map_int_int.cpp, built for
// SIZE rather than speed. Retail is not uniform about this: the bodies that
// unit already holds are speed-optimised, but _M_erase is not - it pushes the
// child straight from memory with `ff 76 0c` and cleans with a one-byte pop,
// where the speed build loads into eax and cleans with `add esp, 4`.
//
// Rather than change that unit's flags, which sixteen landed rows depend on,
// this is a second unit with identical defines and /O1, claiming only the
// bodies the size build reproduces.
// stlport

#include <map>

template class _STL::map<int, int, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > >;

typedef _STL::pair<const int, int> IntIntValue;
typedef _STL::_Rb_tree_node<IntIntValue> IntIntNode;
typedef _STL::_Rb_tree<int, IntIntValue, _STL::_Select1st<IntIntValue>, _STL::less<int>, _STL::allocator<IntIntValue> > MapIntIntTree;

namespace _STL
{

template <> class allocator<char>
{
public:
	static char *allocate(unsigned int bytes, const void *hint) throw();
};

}

void __cdecl dup_00382BC3() throw();

// ?Rva003834CDCreate@@YGPAU?$_Rb_tree_node@U?$pair@$$CBHH@_STL@@@_STL@@ABU?$pair@$$CBHH@2@@Z @ 0x003834CD (34B).
// Map<int,int> node create: 0x18-byte node via the rowed byte allocator
// 0x000307F0, value copy through the rowed dup fold 0x00382BC3 at +0x10.
// Callers 0x003834EF (+0x10 color-copy clone) and 0x00383BAC x2.
IntIntNode * __stdcall Rva003834CDCreate(const IntIntValue &value)
{
	IntIntNode *node = (IntIntNode *)_STL::allocator<char>::allocate(sizeof(IntIntNode), 0);
	IntIntValue *slot = &node->_M_value_field;
	((void (__cdecl *)(IntIntValue *, const IntIntValue *))&dup_00382BC3)(slot, &value);
	return node;
}

// Map<int,int> node clone at 0x003834EF (30B): YG free spelling of the tree
// _M_clone_node body (thiscall with unused receiver); the address-scoped
// _M_copy_00383C34 in stlport_map_int_int_copy_os.cpp calls the member form
// through the symbols.csv pin, which reproduces retail's dead ecx reload.
IntIntNode * __stdcall Rva003834EFClone(IntIntNode *src)
{
	IntIntNode *node = Rva003834CDCreate(src->_M_value_field);
	node->_M_color = src->_M_color;
	node->_M_left = 0;
	node->_M_right = 0;
	return node;
}




// Whole-class instantiation of this tree: insert_equal (retail 0x004FF876) come byte-identical
// from it; their calls read the tree's matched STL helpers.
template class _STL::_Rb_tree<int,_STL::pair<int const ,int>,_STL::_Select1st<_STL::pair<int const ,int> >,_STL::less<int>,_STL::allocator<_STL::pair<int const ,int> > >;
