// ?rva001E3F4D@Rva001E3F4D@@QAEMPAURva001E3F4DArg@@H@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /MD /arch:SSE
//
// ?rva001E3F4D@Rva001E3F4D@@QAEMPAURva001E3F4DArg@@H@Z, retail 0x001E3F4D, 96 bytes.
// Same arg+this offsets as sibling 0x001E3F08 ([arg+0x258]->+0x1f8, [this+4]).
// Uses g_secondsPerLogicFrame squared, TheWritableGlobalData+0xb3c compare,
// [this+4]+0x48/0x4c factor, [this+0x24] clamp. Called at 0x001E558A.
// Owner identity unproven, honest Rva name.

extern float g_secondsPerLogicFrame;

class GlobalData
{
public:
	int m_pad00[719]; // +0x00..+0xB3B
	int m_valB3C; // +0xB3C
};

extern GlobalData *TheWritableGlobalData;

struct Rva001E3F4DMidA
{
	int m_pad00[18]; // +0x00..+0x47
	float m_val48; // +0x48
	float m_val4C; // +0x4C
};

struct Rva001E3F4DMidB
{
	int m_pad00[126]; // +0x00..+0x1F7
	float m_val1F8; // +0x1F8
};

struct Rva001E3F4DArg
{
	int m_pad00[150]; // +0x00..+0x257
	Rva001E3F4DMidB *m_p258; // +0x258
};

class Rva001E3F4D
{
public:
	float rva001E3F4D(Rva001E3F4DArg *p, int n);
private:
	int m_pad00; // +0x00
	Rva001E3F4DMidA *m_p04; // +0x04
	int m_pad08[7]; // +0x08..+0x23
	float m_max24; // +0x24
};

// ?rva001E3F4D@Rva001E3F4D@@QAEMPAURva001E3F4DArg@@H@Z present-unmatched
float Rva001E3F4D::rva001E3F4D(Rva001E3F4DArg *p, int n)
{
	float base = p->m_p258->m_val1F8;
	float sec = g_secondsPerLogicFrame;
	sec *= sec;
	if (n < TheWritableGlobalData->m_valB3C)
		sec *= m_p04->m_val48;
	else
		sec *= m_p04->m_val4C;
	sec *= base;
	if (sec > m_max24)
		sec = m_max24;
	return sec;
}
