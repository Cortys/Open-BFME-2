// ??$_M_find@UBfmeStringRecord00448113@@@?$_Rb_tree@UBfmeStringRecord00448113@@U1@U?$_Identity@UBfmeStringRecord00448113@@@_STL@@U?$less@UBfmeStringRecord00448113@@@3@V?$allocator@UBfmeStringRecord00448113@@@3@@_STL@@ABEPAU?$_Rb_tree_node@UBfmeStringRecord00448113@@@1@ABUBfmeStringRecord00448113@@@Z
// partial score=0.92 date=2026-09-28
// ??$_M_find@UBfmeStringRecord00448113@@@?$_Rb_tree@UBfmeStringRecord00448113@@U1@U?$_Identity@UBfmeStringRecord00448113@@@_STL@@U?$less@UBfmeStringRecord00448113@@@3@V?$allocator@UBfmeStringRecord00448113@@@3@@_STL@@ABEPAU?$_Rb_tree_node@UBfmeStringRecord00448113@@@1@ABUBfmeStringRecord00448113@@@Z
// partial score=0.92 date=2026-09-28
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
#include <set>
struct BfmeStringRecord00448113 { public: unsigned char m_data[8]; };
bool operator<(const BfmeStringRecord00448113 &, const BfmeStringRecord00448113 &);
typedef _STL::_Rb_tree<BfmeStringRecord00448113, BfmeStringRecord00448113, _STL::_Identity<BfmeStringRecord00448113>, _STL::less<BfmeStringRecord00448113>, _STL::allocator<BfmeStringRecord00448113> > UBfmeStringRecord00448113SetTree;
template UBfmeStringRecord00448113SetTree::_Link_type UBfmeStringRecord00448113SetTree::_M_find(const UBfmeStringRecord00448113SetTree::key_type &) const;
