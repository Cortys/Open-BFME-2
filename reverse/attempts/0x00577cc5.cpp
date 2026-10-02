// ?rva00577CC5@Rva00577CC5@@QAEXHHHH@Z
// partial score=0.97 date=2026-10-02
// cl: /O1 /arch:SSE /MD
// ?rva00577CC5@Rva00577CC5@@QAEXHHHH@Z @0x00577CC5 206B: thiscall move-button if 4 ints differ.
// Compares 4 int args against +0x18/0x1c/0x20/0x24 and returns when all equal.
// Else gets x/y scale via TheRva00222A8BTarget vtable slot 0x40 then converts
// the 4 ints to floats scaled and forwards with label from +0x8 chain or empty
// plus MoveButton plus int at +0x10 to rowed 0x00577AE9 with argc 2. Evidence:
// chain packet calls just-landed 0x00577AE9 plus TheRva00222A8BTarget pin plus
// empty 0x007BAC1C plus MoveButton literal plus SetPos precedent.
class Rva00222A8BTarget
{
public:
	virtual void d0();
	virtual void d1();
	virtual void d2();
	virtual void d3();
	virtual void d4();
	virtual void d5();
	virtual void d6();
	virtual void d7();
	virtual void d8();
	virtual void d9();
	virtual void d10();
	virtual void d11();
	virtual void d12();
	virtual void d13();
	virtual void d14();
	virtual void d15();
	virtual float *getScale();
};

extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];

struct InnerBox
{
	char _p0[4];
	void *m_4;
	char *m_8data;
};

struct MidBox
{
	InnerBox *m_0;
};

struct OuterBox
{
	char _p[0x40];
	MidBox *m_40;
};

int __cdecl Rva00577AE9AptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, int *pInt, float *pF1, float *pF2, float *pF3, float *pF4);

class Rva00577CC5
{
public:
	void rva00577CC5(int a0, int a1, int a2, int a3);
private:
	char _p0[8];
	OuterBox *m_8;
	char _pC[4];
	int m_10;
	char _p14[4];
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
};

// ?rva00577CC5@Rva00577CC5@@QAEXHHHH@Z present-unmatched
void Rva00577CC5::rva00577CC5(int a0, int a1, int a2, int a3)
{
	if (a0 != m_18 || a1 != m_1c || a2 != m_20 || a3 != m_24) {
		float *scale = TheRva00222A8BTarget->getScale();
		float f3 = (float)a3 * scale[1];
		float f2 = (float)a2 * scale[0];
		float f1 = (float)a1 * scale[1];
		float f0 = (float)a0 * scale[0];
		InnerBox *box = m_8->m_40->m_0;
		char *raw = *(char **)((char *)box + 8);
		const char *s;
		if (raw)
			s = raw + 8;
		else
			s = g_Rva0107301CEmptyString;
		Rva00577AE9AptCall(TheRva00222A8BTarget, box->m_4, s, "MoveButton", &m_10, &f0, &f1, &f2, &f3);
		m_18 = a0;
		m_1c = a1;
		m_20 = a2;
		m_24 = a3;
	}
}
