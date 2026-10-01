// ?bfmeUseFDE@BfmeThingFDE@@QAEXPAX@Z
// partial score=0.96 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /DNDEBUG /DWIN32 /D_WINDOWS /DBFME_MODULE_NO_MPO /MD /EHsc /Ireference/open-bfme-1/reference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad
// BFME1 donor: reference/open-bfme-1/Code/GameEngine/Source/Common/BfmeConv893.cpp (FDE part only)
// Near-miss repair: BfmeHeldFDE head 0x200 in BFME1, 0x254 in BFME2
// (+0x54 drift verified at +0x0C: [eax+0x200] vs [eax+0x254]).
#include "ascii_string.h"

struct BfmeSubFDE
{
	virtual void bfmeV0();
	virtual void bfmeV1();
	virtual void bfmeV2();
	virtual void bfmeV3();
	virtual void bfmeV4();
	virtual void bfmeV5();
	virtual void bfmeV6();
	virtual void bfmeV7();
	virtual void *bfmeVirt8FDE();
};

struct BfmeHeldFDE
{
	unsigned char m_bfmeHead[0x254];
	BfmeSubFDE *m_bfmeS;
};

class Drawable
{
public:
	void rva002724FD(const AsciiString &a, int b, int c, float d, float e);
};

class Thing
{
public:
	Drawable *getDrawable() const;
};

struct BfmeEntry
{
	char m_bfmeFields[4];
};

struct BfmeRangeFDE
{
	BfmeEntry *m_bfmeBegin;
	BfmeEntry *m_bfmeEnd;
	void *m_bfmeUnused;
};

struct BfmeTableFDE
{
	unsigned char m_bfmeHead[0xfd4];
	BfmeRangeFDE m_bfmeFirst[4];
	BfmeRangeFDE m_bfmeSecond[4];
};

struct BfmeThingFDE
{
	void bfmeGoFDE();
	void bfmeUseFDE(void *r);
	unsigned char m_bfmeHead[4];
	BfmeTableFDE *m_bfmeTable;
	BfmeHeldFDE *m_bfmeP;
};

void BfmeThingFDE::bfmeGoFDE()
{
	BfmeHeldFDE *h = m_bfmeP;
	if (h)
	{
		BfmeSubFDE *s = h->m_bfmeS;
		if (s)
			bfmeUseFDE(s->bfmeVirt8FDE());
	}
}

// ?bfmeUseFDE@BfmeThingFDE@@QAEXPAX@Z, retail 0x004B9B99, 173 bytes.
// Target evidence: LINK BONUS caller bfmeGoFDE above plus UNCLAIMED 0x004B9F9C;
// rowed getDrawable 0x005508E2 and rowed rva002724FD 0x002724FD twice with
// (0,1,0.0,0.0) then (1,1,0.0,0.0); table First at +0xfd4 Second at +0x1004.
// Donor facts: BFME1 BfmeConv893.cpp bfmeUseFDE(int r) gives the two-range
// do-while over First/Second with bfmeApply(first,0,1,0,0); BFME2 retargets
// the sink through Thing::getDrawable to Drawable::rva002724FD with floats.
// Row types: rva002724FD takes AsciiStringHHMM so the 4-byte BfmeEntry is
// passed as AsciiString for byte purposes; void* r is the int range index.
void BfmeThingFDE::bfmeUseFDE(void *r)
{
	int idx = (int)r;
	BfmeHeldFDE *held = m_bfmeP;
	if (held != 0)
	{
		Drawable *sink = ((Thing *)held)->getDrawable();
		if (sink != 0)
		{
			BfmeTableFDE *table = m_bfmeTable;
			BfmeEntry *first = table->m_bfmeFirst[idx].m_bfmeBegin;
			BfmeEntry **firstEnd = &table->m_bfmeFirst[idx].m_bfmeEnd;
			if (first != *firstEnd)
			{
				do
				{
					sink->rva002724FD(*(const AsciiString *)first, 0, 1, 0.0f, 0.0f);
					++first;
				} while (first != *firstEnd);
			}

			BfmeEntry *second = table->m_bfmeSecond[idx].m_bfmeBegin;
			BfmeEntry **secondEnd = &table->m_bfmeSecond[idx].m_bfmeEnd;
			if (second != *secondEnd)
			{
				do
				{
					sink->rva002724FD(*(const AsciiString *)second, 1, 1, 0.0f, 0.0f);
					++second;
				} while (second != *secondEnd);
			}
		}
	}
}
