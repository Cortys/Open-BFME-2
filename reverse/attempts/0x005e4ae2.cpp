// ??0Rva005E4AE2@@QAE@PAXPAU_Rva005E4AE2In@@H@Z
// partial score=0.91 date=2026-09-29
// ??0Rva005E4AE2@@QAE@PAXPAU_Rva005E4AE2In@@H@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /D_STLP_USE_STATIC_LIB /D_BFME_RETAIL_TREE_INSERT_LAYOUT /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/open-bfme-1/reference/shims/nat /Ireference/open-bfme-1/reference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main
// stlport
// ??0Rva005E4AE2@@QAE@PAXPAU_Rva005E4AE2In@@H@Z retail 0x005E4AE2 141B
// Ctor for 0x30-byte GameSpy object: Root writes +4 via volatile then +8,
// Base overwrites +0/+4 plain, derived inits +C/+10/+14/+18 and map at +1C,
// zeroes +28/+2C, flag +2D from [arg2[2]+0x14], registers Listener at +4 via
// rowed append 0x005A0B4C. Volatile-base lever per shape_levers (0x007F7FA0).
// Evidence: caller 0x005E4F6D does new 0x30.
#include <map>

struct Rva002BA8F1Listener { char opaque[4]; };

class Rva005A0B4CList
{
public:
	void append(Rva002BA8F1Listener *p);
private:
	char m_pad[12];
};

struct Rva005E4AE2Holder
{
	Rva005A0B4CList m_list;
	char m_pad0C[8];
	int m_14;
};

struct _Rva005E4AE2In
{
	int m_00;
	int m_04;
	Rva005E4AE2Holder *m_08;
};

class Root005E4AE2
{
public:
	__forceinline Root005E4AE2(void *a1)
	{
		*(volatile unsigned *)&m_04 = 0x00879544;
		m_08 = a1;
	}
	~Root005E4AE2();

	unsigned m_00;
	unsigned m_04;
	void *m_08;
};

class Base005E4AE2 : public Root005E4AE2
{
public:
	__forceinline Base005E4AE2(void *a1) : Root005E4AE2(a1)
	{
		m_00 = 0x00877CEC;
		m_04 = 0x00877CE0;
	}
	~Base005E4AE2();
};

class Rva005E4AE2 : public Base005E4AE2
{
public:
	Rva005E4AE2(void *a1, _Rva005E4AE2In *a2, int a3);
private:
	int m_0C;
	int m_10;
	Rva005E4AE2Holder *m_14;
	int m_18;
	_STL::map<int, void *> m_1C;
	int m_28;
	unsigned char m_2C;
	unsigned char m_2D;
	char m_2E[2];
};

// ??0Rva005E4AE2@@QAE@PAXPAU_Rva005E4AE2In@@H@Z present-unmatched
Rva005E4AE2::Rva005E4AE2(void *a1, _Rva005E4AE2In *a2, int a3)
	: Base005E4AE2(a1)
	, m_0C(a2->m_00)
	, m_10(a2->m_04)
	, m_14(a2->m_08)
	, m_18(a3)
	, m_1C()
{
	m_28 = 0;
	m_2C = 0;
	m_2D = (a2->m_08->m_14 != 0);
	((Rva005A0B4CList *)m_14)->append((Rva002BA8F1Listener *)(void *)((char *)this + 4));
}
