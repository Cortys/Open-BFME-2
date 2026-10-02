// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT /Ireference/shims/bfmealloc
// stlport
//
// The insert path of map<int, Gen_004E9FD0>: its pair copy (0x00416055) copies
// one key word, then calls the rowed Gen_004E9FD0 copy constructor (0x00415FAB,
// BfmeMixedSixCopyWN.cpp) for the value, and its node constructor (0x004168FD)
// allocates 0x30 bytes, a 0x10-byte tree header plus the 0x20-byte pair. The
// value is 28 bytes; only its copy constructor is used here. The key is a
// signed 32-bit type (the inserts compare it signed); int stands in, as in
// stlport_map_int_int_os.cpp. Recipe and flags are
// stlport_map_int_vector_pod128.cpp's. Only the insert overloads are
// instantiated: the rest of the class would need the value's destructor.

#include <map>

class Gen_004E9FD0
{
public:
	Gen_004E9FD0(const Gen_004E9FD0 &other);
private:
	char m_bytes[0x1C];
};

typedef _STL::map<int, Gen_004E9FD0> IntGen004E9FD0Map;

template _STL::pair<IntGen004E9FD0Map::iterator, bool> IntGen004E9FD0Map::insert(const IntGen004E9FD0Map::value_type &);
template IntGen004E9FD0Map::iterator IntGen004E9FD0Map::insert(IntGen004E9FD0Map::iterator, const IntGen004E9FD0Map::value_type &);
