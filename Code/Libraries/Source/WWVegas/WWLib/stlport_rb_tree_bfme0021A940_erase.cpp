// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT /Ireference/shims/bfmealloc
// stlport
// ?_M_erase@?$_Rb_tree@UBfmeStringRecord0021A940@@U1@U?$_Identity@UBfmeStringRecord0021A940@@@_STL@@U?$less@UBfmeStringRecord0021A940@@@3@V?$allocator@UBfmeStringRecord0021A940@@@3@@_STL@@AAEXPAU?$_Rb_tree_node@UBfmeStringRecord0021A940@@@2@@Z @0x0021C3B2 53B recurse-right via +0xC walk-left via +0x8 destroy value at +0x10 via rowed dtor 0x0021A90F free 0x00030830.
// Evidence: chain lane all callees rowed; value layout 0x14 from 2-arg ctor 0x0021A940 in StringRecordInlineCopyBFME2.cpp; same 53B shape as rowed 0x001DD894 and 0x005C6A40. Donor vendor/stlport/stl/_tree.c::_M_erase.
#include <map>
struct BfmeStringRecord0021A940 {
	~BfmeStringRecord0021A940();
	unsigned char m_data[20];
};
bool operator<(const BfmeStringRecord0021A940 &a, const BfmeStringRecord0021A940 &b);
typedef _STL::_Rb_tree<BfmeStringRecord0021A940, BfmeStringRecord0021A940, _STL::_Identity<BfmeStringRecord0021A940>, _STL::less<BfmeStringRecord0021A940>, _STL::allocator<BfmeStringRecord0021A940> > BfmeStringRecord0021A940SetTree;
template void BfmeStringRecord0021A940SetTree::_M_erase(BfmeStringRecord0021A940SetTree::_Link_type);
