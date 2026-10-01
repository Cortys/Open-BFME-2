// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /DNDEBUG /MD
// ?Rva00559B64GetImage@@YAPBVImage@@HH@Z, retail 0x00559B64, 193 bytes.
// Free-function Apt rank icon lookup with side-name table and fallback.
// Evidence: BFME1 donor Rva0046F910RankDisplay.cpp same sprintf shapes "AptRankIcon%s%d" and "AptRankIcon%d" via rowed StringBase ctor 0x00037BA0 releaseBuffer 0x00036410 and rowed findImageByName 0x002D92F6; IAT sprintf; global g_00DFF078 ?g_00DFF078@@3PAVImageCollection@@A; table g_00DBE9B0; callers 0x00559C25 0x0043A5F6 0x005DD48C.
#include "ascii_string.h"
#include <stdio.h>

extern "C" __declspec(dllimport) int __cdecl sprintf(char *buffer, const char *format, ...);

class Image;
class ImageCollection
{
public:
	const Image *findImageByName(const AsciiString &name);
};

// g_00DFF078: matched references place it at VA 0xdff078 (retail .data initial value 0).
ImageCollection * g_00DFF078 = 0;
extern const char *g_00DBE9B0[];

const Image *__cdecl Rva00559B64GetImage(int side, int rank)
{
	char imageNameBuffer[256];
	const Image *image;

	sprintf(imageNameBuffer, "AptRankIcon%s%d", g_00DBE9B0[side], rank);
	{
		AsciiString imageName(imageNameBuffer);
		image = g_00DFF078->findImageByName(imageName);
	}
	if (image == 0) {
		sprintf(imageNameBuffer, "AptRankIcon%d", rank);
		AsciiString fallbackImageName(imageNameBuffer);
		image = g_00DFF078->findImageByName(fallbackImageName);
	}
	return image;
}
