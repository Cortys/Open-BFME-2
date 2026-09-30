// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?Rva005832D0Set@@YGXABVAsciiString@@@Z @0x005832D0 137B
// Free file-transfer loading map-name setter: filename after last backslash
// via rowed reverseFind 0x00035930, fallback to inlined str() with empty at
// 0x00BBAC1C, then rowed BfmeAptWindowManager::rva00225375 0x00225375 with key
// "APT:FileTransferLoadingMapName" and globals 0x009FE4CC. Evidence: caller
// 0x0044C60C; callees all rowed; releaseBuffer 0x00036410; StringBase ctor 0x00037BA0.
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

#include "ascii_string.h"


class BfmeAptWindowManager
{
public:
	void rva00225375(const AsciiString &, const AsciiString &, bool);
};

extern BfmeAptWindowManager *g_Va009FE4CC;

void __stdcall Rva005832D0Set(const AsciiString &path)
{
	const char *slash = path.reverseFind('\\');
	const char *fname;
	if (slash)
		fname = slash + 1;
	else
		fname = path.str();
	AsciiString value(fname);
	AsciiString key("APT:FileTransferLoadingMapName");
	g_Va009FE4CC->rva00225375(key, value, false);
}
