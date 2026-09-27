// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?Rva00056E8CNew@@YGPAUHashNode00056E8C@@ABUBfmeStringRecord00054F57@@@Z, retail 0x00056E8C (37B).
// Hashtable twin for BfmeStringRecord00054F57 (AsciiString+UnicodeString 8B):
// 12-byte node (next+0 plus value at +4) via rowed byte allocator 0x000307F0
// and rowed _Construct 0x000558EE. Caller at 0x00058D90 links the node.
// Same shape as the rowed-adjacent 0x00056E53 new-node; stdcall per ret-4.
#include <memory>
struct BfmeStringRecord00054F57
{
	void *m_a;
	void *m_b;
};
// BFME replaces STLport allocation with a static byte allocator (RVA 0x307F0).
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
template <typename T1, typename T2> void _Construct(T1 *p, const T2 &value);
}

struct HashNode00056E8C
{
	HashNode00056E8C *m_next;
	BfmeStringRecord00054F57 m_val;
};

HashNode00056E8C *__stdcall Rva00056E8CNew(const BfmeStringRecord00054F57 &value)
{
	HashNode00056E8C *node = (HashNode00056E8C *)_STL::allocator<char>::allocate(sizeof(HashNode00056E8C), 0);
	node->m_next = 0;
	_STL::_Construct(&node->m_val, value);
	return node;
}
