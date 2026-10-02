// ?rva00270B0F@Rva00270B0F@@QAEXHPAM@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /MD /GX- /arch:SSE
//
// ?rva00270B0F@Rva00270B0F@@QAEXHPAM@Z, retail 0x00270B0F, 153 bytes.
// Unlock lane: this+0xFC holder, +0x258 mid with virtuals at +0x168 (bool)
// and +0x188 (returns Ret with float at +0x53C). Computes
// v = m_140*g_high + ret->f*g_a*g_b, clamps to [g_low,g_high], stores to
// m_140 and out[1]. Two stack args (ret 8), first unused. Globals are all
// no-name-yet floats. Flags copied from prev Rva002707FASet.cpp and next
// Rva00270BA8.cpp (/O1 /MD /GX-).

struct Rva00270B0FRet
{
	unsigned char m_pad[0x53C];
	float m_53C;
};

class Rva00270B0FMid
{
public:
	virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00C();
	virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01C();
	virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02C();
	virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03C();
	virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04C();
	virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05C();
	virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06C();
	virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07C();
	virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08C();
	virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09C();
	virtual void v0A0(); virtual void v0A4(); virtual void v0A8(); virtual void v0AC();
	virtual void v0B0(); virtual void v0B4(); virtual void v0B8(); virtual void v0BC();
	virtual void v0C0(); virtual void v0C4(); virtual void v0C8(); virtual void v0CC();
	virtual void v0D0(); virtual void v0D4(); virtual void v0D8(); virtual void v0DC();
	virtual void v0E0(); virtual void v0E4(); virtual void v0E8(); virtual void v0EC();
	virtual void v0F0(); virtual void v0F4(); virtual void v0F8(); virtual void v0FC();
	virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
	virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
	virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12C();
	virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13C();
	virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14C();
	virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15C();
	virtual void v160(); virtual void v164();
	virtual bool v168();
	virtual void v16C(); virtual void v170(); virtual void v174(); virtual void v178();
	virtual void v17C(); virtual void v180(); virtual void v184();
	virtual Rva00270B0FRet *v188();
};

struct Rva00270B0FHolder
{
	unsigned char m_pad[0x258];
	Rva00270B0FMid *m_258;
};

extern float g_00BC2918;
extern float g_00BC8990;
extern float g_00BC4DD8;
extern float g_00BFAD90;

class Rva00270B0F
{
public:
	void rva00270B0F(int unused, float *out);
private:
	unsigned char m_pad00[0xFC];
	Rva00270B0FHolder *m_fc;
	unsigned char m_pad100[0x140 - 0x100];
	float m_140;
};

// ?rva00270B0F@Rva00270B0F@@QAEXHPAM@Z present-unmatched
void Rva00270B0F::rva00270B0F(int unused, float *out)
{
	(void)unused;
	Rva00270B0FHolder *h = m_fc;
	if (!h)
		return;
	Rva00270B0FMid *m = h->m_258;
	if (!m)
		return;
	if (!m->v168())
		return;
	Rva00270B0FRet *r = m->v188();
	float v = r->m_53C * g_00BC2918 * g_00BC4DD8 + m_140 * g_00BC8990;
	float low = g_00BFAD90;
	float high = g_00BC8990;
	float res = v;
	if (v < low || v > high)
	{
		if (v < low)
			res = low;
		else
			res = high;
	}
	m_140 = res;
	out[1] = res;
}
