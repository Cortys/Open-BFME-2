// ?rva004B4DBF@Rva004B4DBF@@QAEXPAM0@Z
// partial score=0.95 date=2026-10-01
// ?rva004B4DBF@Rva004B4DBF@@QAEXPAM0@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib
// ?rva004B4DBF@Rva004B4DBF@@QAEXPAM0@Z @0x004B4DBF 151B: thiscall with two float outs.
// Evidence: adjacent to 0x004B4DA3/0x004B4E56; callers 0x004B5020/0x004B5101; uses TheGameLogic+0x40 frame check, g_Va00BBB8D8 float const, g_00DBA4E8 int divisor.

class GameLogic
{
public:
	char m_pad[0x40];
	unsigned int m_frame;
};

extern GameLogic *TheGameLogic;
extern float g_Va00BBB8D8;
extern int g_00DBA4E8;

struct SubA004B4DBF
{
	char m_pad[0x148];
	float m_148;
	float m_14C;
	char m_gap150;
	unsigned char m_151;
};

struct SubB004B4DBF
{
	char m_pad[0x78];
	int m_78;
};

class Rva004B4DBF
{
public:
	void rva004B4DBF(float *p1, float *p2);
private:
	char m_pad0[4];
	SubA004B4DBF *m_a;
	SubB004B4DBF *m_b;
	char m_padC[0x1C - 0x0C];
	unsigned int m_1C;
};

// ?rva004B4DBF@Rva004B4DBF@@QAEXPAM0@Z present-unmatched
void Rva004B4DBF::rva004B4DBF(float *p1, float *p2)
{
	SubA004B4DBF *a = m_a;
	if (a->m_151 != 0)
		return;
	SubB004B4DBF *b = m_b;
	if (b->m_78 == 0) {
		unsigned int v = m_1C + 3;
		if (TheGameLogic->m_frame < v)
			return;
	}
	float c = g_Va00BBB8D8;
	if (a->m_148 != 0.0f) {
		float t = c / a->m_148;
		t /= (float)g_00DBA4E8;
		*p1 = t;
	} else {
		*p1 = 0.0f;
	}
	if (a->m_14C == 0.0f)
		return;
	float t2 = c / a->m_14C;
	t2 /= (float)g_00DBA4E8;
	*p2 = t2;
}
