// ?Rva005E936AGet@@YAPBVImage@@PBX@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /GX
// ?Rva005E936AGet@@YAPBVImage@@PBX@Z @0x005E936A 149B free image lookup with BuildingNoArt default.
// Evidence: static init flag g_Va00E06774 bit0 plus cached default g_00E06770 via rowed StringBase ctor 0x00037BA0 and rowed findImageByName 0x002D92F6 through g_00DFF078 and rowed releaseBuffer 0x00036410; member AsciiString at +0x14 via rowed isEmpty 0x00001E2F; caller 0x005E946A pushes one pointer and cleans with pop.
#include "ascii_string.h"

class Image;
class ImageCollection
{
public:
	const Image *findImageByName(const AsciiString &name);
};

extern ImageCollection *g_00DFF078;
extern unsigned int g_Va00E06774;
extern const Image *g_00E06770;

// ?Rva005E936AGet@@YAPBVImage@@PBX@Z present-unmatched
const Image *__cdecl Rva005E936AGet(const void *p)
{
	if ((g_Va00E06774 & 1) == 0) {
		g_Va00E06774 |= 1u;
		AsciiString tmp = "BuildingNoArt";
		g_00E06770 = g_00DFF078->findImageByName(tmp);
	}
	const AsciiString &name = *(const AsciiString *)((const char *)p + 0x14);
	const Image *result = g_00E06770;
	if (!((const StringBase<char> *)&name)->isEmpty()) {
		result = g_00DFF078->findImageByName(name);
		if (result == 0)
			result = g_00E06770;
	}
	return result;
}
