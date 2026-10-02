// ?rva004723F2@Rva004723F2@@QAE_NPAVObject@@ABVAsciiString@@@Z
// partial score=0.99 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /MD
// stlport
//
// ?rva004723F2@Rva004723F2@@QAE_NPAVObject@@ABVAsciiString@@@Z, retail 0x004723F2, 82 bytes.
// Unlock body between HordeContain neighbours; next is landed chain 0x00472B54.
// Evidence: rowed map<int,int>::operator[] 0x0028932C, Rva00469294::rva00469294
// 0x00469294, StringBase::compare; Object +0x74 ID, map at +0x17C,
// array at +0x188 with 0x1C stride, entry+4 AsciiString; callers in 0x00472444.
#include "ascii_string.h"
#include <map>

class Object
{
public:
	unsigned char m_pad[0x74];
	int m_id;
};

class Rva00469294
{
public:
	void *rva00469294(int key);
};

class Rva004723F2
{
public:
	bool rva004723F2(Object *obj, const AsciiString &name);
private:
	unsigned char m_pad0[4];
	Rva00469294 *m_4;
	unsigned char m_pad2[0x17C - 0x8];
	_STL::map<int, int> m_map;
	char *m_188;
};

// ?rva004723F2@Rva004723F2@@QAE_NPAVObject@@ABVAsciiString@@@Z present-unmatched
bool Rva004723F2::rva004723F2(Object *obj, const AsciiString &name)
{
	int id = obj->m_id;
	int v = m_map[id];
	int key = *(int *)((unsigned int)m_188 + v * 0x1C);
	void *e = m_4->rva00469294(key);
	if (e) {
		StringBase<char> *s = (StringBase<char> *)((char *)e + 4);
		if (s->compare(*(const StringBase<char> *)&name) == 0)
			return true;
	}
	return false;
}
