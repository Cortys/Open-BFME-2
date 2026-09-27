// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?_M_insert@?$_Rb_tree@UBfmePod20@@U1@U?$_Identity@UBfmePod20@@@_STL@@U?$less@UBfmePod20@@@3@V?$allocator@UBfmePod20@@@3@@_STL@@AAE?AU?$_Rb_tree_iterator@UBfmePod20@@U?$_Nonconst_traits@UBfmePod20@@@_STL@@@2@PAU_Rb_tree_node_base@2@0ABUBfmePod20@@0@Z
// retail 0x004AF3E6 136 bytes plus ?insert_unique@?$_Rb_tree@UBfmePod20@@U1@U?$_Identity@UBfmePod20@@@_STL@@U?$less@UBfmePod20@@@3@V?$allocator@UBfmePod20@@@3@@_STL@@QAE?AU?$pair@U?$_Rb_tree_iterator@UBfmePod20@@U?$_Nonconst_traits@UBfmePod20@@@_STL@@@_STL@@_N@2@ABUBfmePod20@@@Z
// retail 0x004AF4A6 134 bytes plus ?_M_erase@?$_Rb_tree@UBfmePod20@@U1@U?$_Identity@UBfmePod20@@@_STL@@U?$less@UBfmePod20@@@3@V?$allocator@UBfmePod20@@@3@@_STL@@AAEXPAU?$_Rb_tree_node@UBfmePod20@@@2@@Z
// retail 0x004AF28F 45 bytes. _Rb_tree set _M_insert plus insert_unique plus _M_erase for the 20-byte
// RespawnRule value (BfmePod20 size view). Called once by the unique-insert
// worker 0x004AF4A6. Calls the rowed BfmePod20 _M_create_node 0x004AF2BC
// twice and the rowed _Rebalance 0x00025490. Unsigned first-dword level key
// at value+0x10 gives jb/setb shape. Recipe from STLport _tree.c _M_insert
// with _BFME_RETAIL_TREE_INSERT_LAYOUT and the horde_rank_set odr-use unit.
#define _BFME_RETAIL_TREE_INSERT_LAYOUT
#include <set>
struct BfmePod20 { unsigned a[5]; };
inline bool operator<(const BfmePod20 &x, const BfmePod20 &y) { return x.a[0] < y.a[0]; }
typedef _STL::_Rb_tree<BfmePod20, BfmePod20, _STL::_Identity<BfmePod20>, _STL::less<BfmePod20>, _STL::allocator<BfmePod20> > UBfmePod20SetTree;
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
}
template _STL::pair<UBfmePod20SetTree::iterator, bool> UBfmePod20SetTree::insert_unique(const UBfmePod20SetTree::value_type &);
template void UBfmePod20SetTree::_M_erase(UBfmePod20SetTree::_Link_type);
