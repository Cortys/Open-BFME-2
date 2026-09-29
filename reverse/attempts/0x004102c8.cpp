// ?Rva004102C8Update@@YAXPAURva004102C8Arg@@PAM1@Z
// partial score=0.92 date=2026-09-29
// ?Rva004102C8Update@@YAXPAURva004102C8Arg@@PAM1@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /arch:SSE /MD
// ?Rva004102C8Update@@YAXPAURva004102C8Arg@@PAM1@Z, retail 0x004102C8 225B.
// Position/size sync using GameWindow calls plus RingRenderObj Get_Flags row
// 0x3140A4. Evidence: winGetPosition 0x313AE4 winSetPosition 0x313A9E
// winSetSize 0x313B87 callers 0x4117C3 0x41206C prev 0x4102A4 next 0x4103BE.

class RingRenderObjClass
{
public:
	unsigned int Get_Flags();
};

class GameWindow
{
public:
	int winGetPosition(int *x, int *y);
	int winSetPosition(int x, int y);
	int winSetSize(int w, int h);
};

struct Rva004102C8Arg
{
	char m_00[0x10];
	RingRenderObjClass *m_10;
	float m_14;
	float m_18;
	float m_1C;
	float m_20;
};

// ?Rva004102C8Update@@YAXPAURva004102C8Arg@@PAM1@Z present-unmatched
void Rva004102C8Update(Rva004102C8Arg *a1, float *a2, float *a3)
{
	float f0;
	float f1;
	int ix;
	int iy;
	unsigned int f;
	f0 = a2[0];
	f1 = a2[1];
	f = a1->m_10->Get_Flags();
	if (f != 0) {
		((GameWindow *)f)->winGetPosition(&ix, &iy);
		f0 -= (float)ix;
		f1 -= (float)iy;
	}
	if (f0 != a1->m_14 || f1 != a1->m_18) {
		a1->m_14 = f0;
		a1->m_18 = f1;
		if (a1->m_10 != 0)
			((GameWindow *)a1->m_10)->winSetPosition((int)f0, (int)f1);
	}
	if (a3[0] != a1->m_1C || a3[1] != a1->m_20) {
		a1->m_1C = a3[0];
		a1->m_20 = a3[1];
		if (a1->m_10 != 0)
			((GameWindow *)a1->m_10)->winSetSize((int)a3[0], (int)a3[1]);
	}
}
