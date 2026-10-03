// ?Rva00300E42Check@@YA_NPAVGameInfo@@@Z
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?Rva00300E42Check@@YA_NPAVGameInfo@@@Z @0x00300E42 114B
// Free helper: if GameInfo flag+0x4d & 2 return false, else compare
// TheMapCache maps-dir (row 0x00300D7A) with GameInfo::getMap (row 0x0023E943)
// via StringBase::startsWithNoCase (row 0x0002C42F). Callers 0x0024998D
// 0x00440C84 0x00441BB1 0x00447183 0x0044A59D; TheMapCache 0x00DFF12C.
#include "ascii_string.h"

class Rva00300D7A
{
public:
	AsciiString rva00300D7A();
};

class MapCache : public Rva00300D7A
{
};

extern MapCache *TheMapCache;

class GameInfo
{
public:
	void *m_vtable;
	char m_pad04[0x0C];
	bool m_inGame;
	char m_pad11[0x2F];
	AsciiString m_map;
	unsigned int m_mapCRC;
	unsigned int m_mapSize;
	unsigned char m_pad4C;
	unsigned char m_flag4D;
	AsciiString getMap() const;
};

// ?Rva00300E42Check@@YA_NPAVGameInfo@@@Z present-unmatched
bool __cdecl Rva00300E42Check(GameInfo *info)
{
	if (info->m_flag4D & 2) {
		return false;
	}
	return ((const StringBase<char> *)&info->getMap())->startsWithNoCase(*(const StringBase<char> *)&TheMapCache->rva00300D7A());
}
