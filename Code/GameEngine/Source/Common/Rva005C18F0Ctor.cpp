// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHs
#include "unicode_string.h"

// ??0Rva005C18F0@@QAE@XZ, RVA 0x005C1896, 62B. Unlock lane: default ctor
// storing g_00E06034 at +4 via the base, constructing the member at +8
// through rowed ??0StrategicStatsPreferences@@QAE@ABVUnicodeString@@@Z at
// 0x00537DBC with UnicodeString::TheEmptyString, storing vtable 0x008743C4
// under EH state 0. Base carries the scalar so its store lands before the
// derived EH state and vtable. Caller at 0x005C19FD in 0x005C19B6. Flags
// copy Rva005C18F0Dtor.cpp with the shared ascii shim first.
extern char g_00E06034[];

class StrategicStatsPreferences
{
public:
	StrategicStatsPreferences(const UnicodeString &);
private:
	char m_pad[4];
};

class Rva005C18F0Base
{
public:
	Rva005C18F0Base() : m_04(g_00E06034) {}
	virtual ~Rva005C18F0Base() {}
protected:
	char *m_04;
};

class Rva005C18F0 : public Rva005C18F0Base
{
public:
	Rva005C18F0();
private:
	StrategicStatsPreferences m_08;
};

Rva005C18F0::Rva005C18F0()
	: m_08(UnicodeString::TheEmptyString)
{
}
