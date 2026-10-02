// ?rva00300D7A@Rva00300D7A@@QAE?AVAsciiString@@XZ
// partial score=0.98 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /DNDEBUG /MD /EHsc
// ?rva00300D7A@Rva00300D7A@@QAE?AVAsciiString@@XZ retail 0x00300D7A 200B
// Maps-directory getter: local "UserData\Maps" when GetRegistryUseLocalUserMaps,
// else GlobalData user dir plus the "Maps" virtual 0x00300489. Rowed format 0x38150,
// StringBase ctor 0x37BA0, set 0x55F5, copy ctor 0x365F0, concat 0x6987,
// releaseBuffer 0x36410, GlobalData::rva002360DE 0x2360DE, Rva00300489::rva00300489
// 0x300489, GetRegistryUseLocalUserMaps 0x235159; globals TheWritableGlobalData,
// g_Rva0107301CEmptyString; callers 0x002DC946 0x002DCAE4 0x00300E67 0x00303441.
#include "ascii_string.h"

bool GetRegistryUseLocalUserMaps();

class GlobalData
{
public:
	AsciiString rva002360DE() const;
};
extern GlobalData *TheWritableGlobalData;

extern const char g_Rva0107301CEmptyString[];

class Rva00300489
{
public:
	virtual AsciiString rva00300489() const;
};

class Rva00300D7A : public Rva00300489
{
public:
	AsciiString rva00300D7A();
};

// ?rva00300D7A@Rva00300D7A@@QAE?AVAsciiString@@XZ present-unmatched
AsciiString Rva00300D7A::rva00300D7A()
{
	AsciiString path;
	if (GetRegistryUseLocalUserMaps()) {
		path.format("%s", "UserData\\Maps");
	} else {
		{
			const AsciiString base = TheWritableGlobalData->rva002360DE();
			char *t = *(char **)&base;
			path.set(t ? t + 8 : g_Rva0107301CEmptyString);
		}
		path.concat(Rva00300489::rva00300489());
	}
	return path;
}
