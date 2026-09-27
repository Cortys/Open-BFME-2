// ?Rva0058AF47Check@@YG_NPAVRva002A9BF2@@@Z
// partial score=0.95 date=2026-09-27
// ?Rva0058AF47Check@@YG_NPAVRva002A9BF2@@@Z
// partial score=0.95 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?Rva0058AF47Check@@YG_NPAVRva002A9BF2@@@Z @ 0x0058AF47 (108B). Chain lane via
// landed 0x002A9BF2 difficulty getter. Evidence: shl eax,5 indexes 32B table
// at [0x009FEEF8]+0x888, rep movsd 8 dwords to stack, ratio num/den at +12/+16
// vs 1.0f at 0x00BBB8D8, else GetGameLogicRandomValue(0 den-1 file 0x40) with
// AIDifficulty.cpp literal, return random<num. Callers use free stdcall.

class Rva002A9BF2
{
public:
	void *rva002A9BF2();
};

struct AIDiffEntry
{
	char _pad0[12];
	int m_num;
	int m_den;
	char _pad1[12];
};

struct AIDiffHolder
{
	char _pad[0x888];
	AIDiffEntry m_table[4];
};

#define TheAIDiffHolder (*(AIDiffHolder **)0x00DFEEF8)
#define One (*(volatile float const *)0x00BBB8D8)

int GetGameLogicRandomValue(int lo, int hi, char *file, int line);

// ?Rva0058AF47Check@@YG_NPAVRva002A9BF2@@@Z present-unmatched
bool __stdcall Rva0058AF47Check(Rva002A9BF2 *p)
{
	int diff = (int)p->rva002A9BF2();
	AIDiffEntry e = TheAIDiffHolder->m_table[diff];
	float num = (float)e.m_num;
	float den = (float)e.m_den;
	float ratio = num / den;
	if (ratio >= One)
		return true;
	int deni = e.m_den;
	int numi = e.m_num;
	int r = GetGameLogicRandomValue(0, deni - 1, (char *)"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AIDifficulty.cpp", 0x40);
	return r < numi;
}
