// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ?rva00407E28@Rva00407E28@@QAEHH@Z retail 0x00407E28 43B
// Evidence: unlock lane; map<int int> at +0x14 via rowed _M_find 0x00388F63 and operator[] 0x0028932C; callers 0x005B05E8 0x005B07C1 0x005B0EE6 0x005B1B5E; prev-next Rb_tree hint same flags.
#include <map>

class Rva00407E28
{
public:
	int rva00407E28(int key);
private:
	char m_pad[0x14];
	_STL::map<int, int> m_map;
};

int Rva00407E28::rva00407E28(int key)
{
	_STL::map<int, int>::iterator it = m_map.find(key);
	if (it == m_map.end())
		return -1;
	return m_map[key];
}
