// ?rva00472CA9@HordeContain@@QAEXPAVObject@@@Z
// partial score=0.99 date=2026-10-01
// cl: /O1 /MD
// stlport
//
// ?rva00472CA9@HordeContain@@QAEXPAVObject@@@Z, retail 0x00472CA9, 154 bytes.
// Vtable slot 32 of HorseHordeContain/AODHordeContain; neighbours are landed
// chain 0x00472B54 and HordeContainRva00473125.
// Evidence: rowed map<int,int>::operator[] 0x0028932C, Rva00469294 0x00469294,
// BfmeObject872Header copy 0x002CF108, Object set/clearWeaponSetFlag;
// Object +0x74 ID, map at +0x17C, array at +0x188 stride 0x1C,
// entry+0x14/+0x24 headers, +0x34 flag, 0x68 weapon loop.
#include <map>

enum WeaponSetType
{
	WST_0 = 0
};

class Object
{
public:
	void setWeaponSetFlag(WeaponSetType t);
	void clearWeaponSetFlag(WeaponSetType t);
	unsigned char m_pad[0x74];
	int m_id;
};

class Rva00469294
{
public:
	void *rva00469294(int key);
};

class BfmeObject872Header
{
	char m_bytes[16];
public:
	BfmeObject872Header(const BfmeObject872Header &other);
};

struct HordeContainSlot
{
	int m_key;
	char m_pad[0x18];
};

class HordeContain
{
public:
	void rva00472CA9(Object *obj);
private:
	unsigned char m_pad0[4];
	Rva00469294 *m_4;
	unsigned char m_pad2[0x17C - 0x8];
	_STL::map<int, int> m_map;
	HordeContainSlot *m_slots;
};

// ?rva00472CA9@HordeContain@@QAEXPAVObject@@@Z present-unmatched
void HordeContain::rva00472CA9(Object *obj)
{
	int id = obj->m_id;
	int v = m_map[id];
	int key = *(int *)(v * 0x1C + (unsigned int)m_slots);
	void *e = m_4->rva00469294(key);
	if (!e)
		return;
	if (*(unsigned char *)((char *)e + 0x34) == 0)
		return;
	BfmeObject872Header h1(*(BfmeObject872Header *)((char *)e + 0x14));
	BfmeObject872Header h2(*(BfmeObject872Header *)((char *)e + 0x24));
	for (int i = 0; i < 0x68; ++i) {
		unsigned int bit = 1u << (i & 31);
		unsigned int word = ((unsigned int)i >> 5) * 4;
		if (*(unsigned int *)((char *)&h1 + word) & bit)
			obj->setWeaponSetFlag((WeaponSetType)i);
		else if (*(unsigned int *)((char *)&h2 + word) & bit)
			obj->clearWeaponSetFlag((WeaponSetType)i);
	}
}
