// ??0Rva005CB35A@@QAE@XZ
// partial score=0.9 date=2026-10-01
// cl: /O1 /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
//
// ??0Rva005CB35A@@QAE@XZ @0x005CB35A 100B probe.
// Evidence: RegionDisplay literal via shared AsciiString plus Rva00221635 pin
// call plus releaseBuffer plus vptr g_00C74D90 plus six zeroed members.
// ??0Rva005CB35A@@QAE@XZ present-unmatched

#include "string_base.h"

#include "ascii_string.h"

extern const void *const g_00C74D90[];

class Rva00221635
{
public:
	virtual ~Rva00221635();
	Rva00221635(int v);
	int m_04;
};

inline void *__cdecl operator new(unsigned int, void *where)
{
	return where;
}

class Rva005CB35A
{
public:
	Rva005CB35A();

private:
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
};

Rva005CB35A::Rva005CB35A()
{
	{
		AsciiString tmp("RegionDisplay");
		new (this) Rva00221635((int)&tmp);
	}
	*(const void **)this = g_00C74D90;
	m_08 = 0;
	m_0c = 0;
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
	m_1c = 0;
}
