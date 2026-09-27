// cl: /O1 /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ?rva005F2278@Rva005F2278@@QBE_NH@Z, retail 0x005F2278, 29 bytes.
// Map<int int> contains-check at this+0x10 via rowed _M_find 0x00388F63.
// Callees all rowed. Callers 7 unclaimed (0x005E4D60 0x005E4E32 0x005E50FD 0x005E5119 0x005E5146 jmp 0x005E39A9 jmp 0x005E3B20).
// Prev Disp8PtrChase getter / next OpaqueScalarDeletingDtor. Honest address name; class and method identity unproven.
#include <map>

class Rva005F2278
{
public:
	bool rva005F2278(int key) const;
private:
	char m_pad[0x10];
	_STL::map<int, int> m_map;
};

bool Rva005F2278::rva005F2278(int key) const
{
	return m_map.find(key) != m_map.end();
}
