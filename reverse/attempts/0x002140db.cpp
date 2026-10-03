// ?rva002140DB@Rva002140DB@@QAEPAVRva00402BE3@@ABVAsciiString@@@Z
// partial score=0.92 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva002140DB@Rva002140DB@@QAEPAVRva00402BE3@@ABVAsciiString@@@Z retail 0x002140DB 123 bytes.
// LivingWorldManager factory: news 0x1C-byte Rva00402BE3 from AsciiString arg
// then inserts AsciiString-copy plus new ptr pair into Rva000427195 table at
// this+0x280 via rowed 0x00213925 and returns the new object. Evidence: chain
// from just-landed 0x00213925 plus rowed new 0x0002FDA0 and rowed ctor
// 0x00402BE3 and rowed StringBase copy 0x000365F0 and release 0x00036410.
// Precedent: Rva00402BE3Ctor layout and Rva00213925Insert table shape.
#include "ascii_string.h"
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class Rva00402BE3
{
public:
	Rva00402BE3(const AsciiString &name);
private:
	AsciiString m_name;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_vec;
	int m_10;
	int m_14;
	int m_18;
};

#pragma pack(push, 1)
struct InsertRet00212A5A
{
	InsertRet00212A5A(void *node, void *owner, unsigned char found)
		: m_node(node), m_owner(owner), m_found(found) {}
	void *m_node;
	void *m_owner;
	unsigned char m_found;
};
#pragma pack(pop)

class Rva000427195
{
public:
	InsertRet00212A5A rva00213925(const void *key);
	void *m_unused00;
	void **m_beginBuckets;
	void **m_endBuckets;
	void **m_storageEnd;
	unsigned int m_numElements;
};

struct Rva002140DBPair
{
	AsciiString first;
	Rva00402BE3 *second;
	Rva002140DBPair(const AsciiString &a, Rva00402BE3 *b) : first(a), second(b) {}
};

class Rva002140DB
{
public:
	Rva00402BE3 *rva002140DB(const AsciiString &name);
private:
	char m_pad[0x280];
	Rva000427195 m_map;
};

Rva00402BE3 *Rva002140DB::rva002140DB(const AsciiString &name)
{
	Rva00402BE3 *obj = new Rva00402BE3(name);
	Rva002140DBPair p(name, obj);
	m_map.rva00213925(&p);
	return obj;
}
