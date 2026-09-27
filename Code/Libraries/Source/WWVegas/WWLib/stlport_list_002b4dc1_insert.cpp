// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?insert@?$list@UBfmeStringRecord002B4DC1@@V?$allocator@UBfmeStringRecord002B4DC1@@@_STL@@@_STL@@QAE?AU?$_List_iterator@UBfmeStringRecord002B4DC1@@U?$_Nonconst_traits@UBfmeStringRecord002B4DC1@@@_STL@@@2@U32@ABUBfmeStringRecord002B4DC1@@@Z retail 0x002B70DC 37B
// Evidence: identical 37B shape to list<int>::insert at 0x005925E2 calling rowed _M_create_node;
// here calls rowed 002B4DC1 _M_create_node at 0x002B60D7 then list hook insertion; callers 0x002B7120 and 0x002B8117.
#include <list>

struct BfmeStringRecord002B4DC1 { unsigned char m_data[12]; };

bool operator==(const BfmeStringRecord002B4DC1 &a, const BfmeStringRecord002B4DC1 &b);
bool operator<(const BfmeStringRecord002B4DC1 &a, const BfmeStringRecord002B4DC1 &b);

template class _STL::list<BfmeStringRecord002B4DC1, _STL::allocator<BfmeStringRecord002B4DC1> >;
