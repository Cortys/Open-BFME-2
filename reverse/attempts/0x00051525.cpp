// ?rva00051525@Rva00051525@@QAE_NXZ
// partial score=0.93 date=2026-10-01
// cl: /O1
// ?rva00051525@Rva00051525@@QAE_NXZ @ 0x00051525 57B
// Evidence: __thiscall via ecx plus ret no stack args; +0xBF0 range 1-5 check; TheGameLODManager null check plus +0x1770 index plus +0x21C byte table with stride 8; callers 0x000605A9 plus 0x00060828; neighbour Rva000514EBDec TU flags /O1.
class GameLODManager
{
public:
	char m_pad21C[0x21C];
	struct LODFlag
	{
		unsigned char flag;
		char m_pad[7];
	};
	LODFlag m_flags[2];
	char m_padAfter[0x1770 - (0x21C + 16)];
	int m_idx1770;
};

extern GameLODManager *TheGameLODManager;

class Rva00051525
{
public:
	bool rva00051525();

private:
	char m_pad[0xBF0];
	int m_valBF0;
};

// ?rva00051525@Rva00051525@@QAE_NXZ present-unmatched
bool Rva00051525::rva00051525()
{
	int v = m_valBF0;
	if (v <= 0 || v > 5)
		return false;
	GameLODManager *mgr = TheGameLODManager;
	if (!mgr)
		return true;
	int idx = mgr->m_idx1770;
	if (idx < 0 || idx >= 2)
		return true;
	return !!mgr->m_flags[idx].flag;
}
