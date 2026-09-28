// cl: /O2 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
//
// STLport 4.5.3 _Rb_tree<int,int,_Identity<int>,less<int>> copy constructor at
// retail 0x00620CA0 (207B).
//
// Target evidence: the header node is a 0x14-byte allocation through the byte
// allocator 0x307F0, and the recursive copy it calls (0x002CF6CF) clones nodes
// through 0x004ABCC9, which the ledger owns as the integer-set _M_create_node
// (single dword value at +0x10). That makes this the set<int> tree copy. The
// ledger still spells 0x002CF6CF and its assignment caller 0x002CF742 as
// pair<const int,int> names; the pin below adds the set<int> spelling for the
// same address rather than editing those rows.
#include <set>

typedef _STL::_Rb_tree<int, int, _STL::_Identity<int>, _STL::less<int>, _STL::allocator<int> > IntSetTree;

template IntSetTree::_Rb_tree(const IntSetTree &);
