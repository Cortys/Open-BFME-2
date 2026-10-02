// ??0Rva002A8D49@@QAE@XZ
// partial score=0.97 date=2026-10-02
// cl: /O2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
// ??0Rva002A8D49@@QAE@XZ @ 0x002A8D49 (283B). Inner member at +0x10 of the
// outer ctor at 0x002A9725 (which passes ECX=outer+0x10 and then builds a
// map at +0x908). Owns CombatChainEntry[16] at +0x0 (rowed ctor 0x2A88C7 via
// ??_H size 0x84 count 0x10), floats/bools at +0x840-0x850, vector<BfmeE16>
// at +0x854 (rowed Vector_base 0x211E58), six float defaults at +0x860-0x874
// and Rva002A8823Tuning[4] at +0x878 (pinned ctor 0x2A8823 via ??_H size
// 0x20 count 4, then difficulty=i loop). Evidence: caller 0x002A9725,
// parsers using +0x878 (0x2A89D2) and CombatChainEntry layout (0x2A88C7).
#include <vector>

extern "C" float INV;
extern float g_bfmePickupScanRange;
extern float g_00BC7508;
extern float g_00BC7500;
extern float g_00BFDB80;
extern float g_00BC3EE8;

struct CombatChainEntry
{
	CombatChainEntry();
	int unit;
	int targetTypes[16];
	float targetPriorityModifiers[16];
};

class Rva002A8823Tuning
{
public:
	Rva002A8823Tuning();
	int difficulty;
	int economyUpgradeProbability;
	int field8;
	int specialPowerActivationProbability;
	int field10;
	int offensiveTacticActivationProbability;
	int field18;
	int economyMaxFarms;
};

struct BfmeE16 { float x, y, z, w; };

class Rva002A8D49
{
public:
	Rva002A8D49();
	CombatChainEntry m_combat[16];
	float m_840;
	float m_844;
	bool m_848;
	bool m_849;
	bool m_84a;
	bool m_84b;
	bool m_84c;
	bool m_84d;
	bool m_84e;
	bool m_84f;
	bool m_850;
	_STL::vector<BfmeE16> m_vec;
	float m_860;
	float m_864;
	float m_868;
	float m_86c;
	float m_870;
	float m_874;
	Rva002A8823Tuning m_tuning[4];
};

// ??0Rva002A8D49@@QAE@XZ present-unmatched
Rva002A8D49::Rva002A8D49()
	: m_840(0.0f)
	, m_844(INV)
	, m_848(false)
	, m_849(false)
	, m_84a(false)
	, m_84b(false)
	, m_84c(false)
	, m_84d(false)
	, m_84e(false)
	, m_84f(false)
	, m_850(false)
	, m_860(50.0f)
	, m_864(g_00BC7508)
	, m_868(g_bfmePickupScanRange)
	, m_86c(g_00BC7500)
	, m_870(g_00BFDB80)
	, m_874(g_00BC3EE8)
{
	for (int i = 0; i < 4; ++i)
		m_tuning[i].difficulty = i;
}
