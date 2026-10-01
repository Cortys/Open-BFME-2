// ?Rva005D839BCheck@@YI_NHPAURva005D839BParam@@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?Rva005D839BCheck@@YI_NHPAURva005D839BParam@@@Z RVA 0x005D839B size 168 evidence vector BfmeE8 TheGameLogic+0x40 caller 0x005D8443
#include <vector>

struct BfmeE8 { unsigned int a, b; };

class GameLogic
{
public:
	char m_pad00[0x40];
	unsigned int m_40;
};

extern GameLogic *TheGameLogic;
extern _STL::vector<BfmeE8> g_00E06654;
extern int g_00E06650;
extern int g_00E06660;

int GetGameLogicRandomValue(int lo, int hi, char *file, int line);

struct Rva005D839BParam
{
	char m_pad00[0x54];
	int m_54;
};

// ?Rva005D839BCheck@@YI_NHPAURva005D839BParam@@@Z present-unmatched
bool __fastcall Rva005D839BCheck(int dummy, Rva005D839BParam *p)
{
	_STL::vector<BfmeE8>::iterator first = g_00E06654.begin();
	_STL::vector<BfmeE8>::iterator last = g_00E06654.end();
	BfmeE8 *found = 0;
	if (first != last)
	{
		for (BfmeE8 *it = first; it != last; ++it)
		{
			if (found != 0)
				break;
			if (it != 0 && it->a == (unsigned int)p->m_54)
				found = it;
		}
	}
	if (found == 0)
	{
		BfmeE8 tmp;
		tmp.a = (unsigned int)p->m_54;
		tmp.b = TheGameLogic->m_40;
		g_00E06654.push_back(tmp);
		found = &g_00E06654[g_00E06654.size() - 1];
	}
	if (found->b <= TheGameLogic->m_40)
	{
		unsigned int r = (unsigned int)GetGameLogicRandomValue(g_00E06650, g_00E06660, "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\AI\\AIStates.cpp", 0x4D);
		found->b = TheGameLogic->m_40 + r;
		return true;
	}
	return false;
}
