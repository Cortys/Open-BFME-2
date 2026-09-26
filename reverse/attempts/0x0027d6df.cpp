// ?Rva0027D6DF@Rva0062AF7@@UAEXPAMPBM@Z
// partial score=0.9 date=2026-09-26
// ?Rva0027D6DF@Rva0062AF7@@UAEXPAMPBM@Z
// partial score=0.9 date=2026-09-26
// cl: /O1 /MD /arch:SSE /G7
//
// ?Rva0027D815@Rva0062AF7@@UAEMMM@Z retail 0x0027D815 70 bytes.
// Vslot 25 (offset 0x64) of vtable 0x007C5890 primary of ??1Rva0062AF7@@UAE@XZ
// whose slot 2 returns W3DTerrainLogic and slot 15 is isClearLineOfSight.
// Shared with base TerrainLogic vtable 0x007FB2C8 at same address. Calls slot
// 19 (offset 0x4C unclaimed 0x0027D77D 5-arg bool) with x y and two float outs
// plus 0 and returns a minus b on true else pooled 0.0f at retail 0x007BAEAC.
// Identity is class plus slot and method name is honest address name.
// Secondary MI vptrs plus 0x04 plus 0x10 plus 0x14 omitted as body touches
// primary only. Flags per section 4.1: /O1 for EBP frame plus /arch:SSE for
// xorps and movss float zeroing.
struct Rva0027D6DFBox
{
	float loX;
	float loY;
	float loZ;
	float hiX;
	float hiY;
	float hiZ;
};
struct Rva0027D6DFRes
{
	float out1;
	float out2;
	float m_spare;
};
class Rva0062AF7
{
public:
	virtual void slot00();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual float slot06(float x, float y, int z);
	virtual void slot07();
	virtual void slot08(Rva0027D6DFBox *box);
	virtual void slot09();
	virtual void slot10();
	virtual void slot11();
	virtual void slot12();
	virtual void slot13();
	virtual void Rva0027D6DF(float *out, const float *in);
	virtual void slot15();
	virtual void slot16();
	virtual void slot17();
	virtual void slot18();
	virtual bool Rva0027D77D(float x, float y, float *a, float *b, bool *c);
	virtual void slot20();
	virtual void slot21();
	virtual void slot22();
	virtual void slot23();
	virtual void slot24();
	virtual float Rva0027D815(float x, float y);
	virtual void *slot26(float x, float y, float z);
	virtual void slot27();
	virtual void slot28();
	virtual void slot29();
	virtual float Rva0027D85B(void *water);
	virtual void slot31();
	virtual void Rva0027D88E(void *water, float finalHeight, float transitionTime, float damageAmount);

private:
	char m_pad04[0x64];
	struct WaterEntry
	{
		void *waterTable;
		float changePerFrame;
		float targetHeight;
		float damageAmount;
		float currentHeight;
	};
	WaterEntry m_entries[64];
	int m_count;
};
float Rva0062AF7::Rva0027D815(float x, float y)
{
	float a = 0.0f;
	float b = 0.0f;
	if (!Rva0027D77D(x, y, &a, &b, 0))
		return 0.0f;
	return a - b;
}

//
// ?Rva0027D85B@Rva0062AF7@@UAEMPAX@Z retail 0x0027D85B 51 bytes.
// Vslot 30 (offset 0x78) of vtable 0x007C5890 primary of ??1Rva0062AF7@@UAE@XZ.
// Null or grid-handle (global 0x00DBB710) returns pooled 0.0f at 0x007BAEAC.
// Else water+0x18 holds inner, inner+0x04 holds byte offset, real object at
// water+0x18+offset exposes int at slot 2 (offset 8) converted via fild.
// Layout witnessed from retail bytes only; helper view names are honest
// address-derived, not donor claims. Identity class plus slot, honest name.
// Flags: /O1 plus /arch:SSE plus /G7 (section 4.1, same TU as neighbours).
extern void *g_Va00DBB710;
struct Rva0027D85BPolyView
{
	virtual void slot00();
	virtual void slot01();
	virtual int slot08();
};
struct Rva0027D85BInnerView
{
	char m_pad00[4];
	int m_off04;
};
struct Rva0027D85BWaterView
{
	char m_pad00[0x18];
	Rva0027D85BInnerView *m_inner18;
};
float Rva0062AF7::Rva0027D85B(void *water)
{
	Rva0027D85BWaterView *view = (Rva0027D85BWaterView *)water;
	if (water == 0)
		return 0.0f;
	if (water == g_Va00DBB710)
		return 0.0f;
	int off = view->m_inner18->m_off04;
	Rva0027D85BPolyView *real = (Rva0027D85BPolyView *)((char *)water + 0x18 + off);
	return (float)real->slot08();
}

//
// ?Rva0027D88E@Rva0062AF7@@UAEXPAXMMM@Z retail 0x0027D88E 210 bytes.
// Vslot 32 (offset 0x80) of vtable 0x007C5890 primary of ??1Rva0062AF7@@UAE@XZ.
// Donor: BFME1 TerrainLogic::changeWaterHeightOverTime in
// reference/open-bfme-1/Code/GameEngine/Source/GameLogic/Map/TerrainLogic.cpp
// (dedup swap-with-last via rep movsd, getWaterHeight via slot 0x78, then
// (final-current)/(LogicFrames*transition) with LogicFrames global 0x00DBA4E4).
// Array at +0x68 stride 0x14 count at +0x568 max 64. Identity class plus slot,
// honest address name. Flags: /O1 for EBP frame plus /arch:SSE for movss
// float moves plus /G7 for imul 0x14 and edx loop index (section 4.1).
void Rva0062AF7::Rva0027D88E(void *water, float finalHeight, float transitionTime, float damageAmount)
{
#define LogicFramesPerSecond (*(const int *)0x00DBA4E4)
	enum { MAX_DYNAMIC_WATER = 64 };
	if (m_count >= MAX_DYNAMIC_WATER)
		return;
	if (water == 0)
		return;
	for (int i = 0; i < m_count; ++i)
	{
		if (m_entries[i].waterTable == water)
		{
			m_entries[i] = m_entries[m_count - 1];
			--m_count;
			--i;
		}
	}
	float currentHeight = Rva0027D85B(water);
	m_entries[m_count].waterTable = water;
	m_entries[m_count].changePerFrame = (finalHeight - currentHeight) / (LogicFramesPerSecond * transitionTime);
	m_entries[m_count].targetHeight = finalHeight;
	m_entries[m_count].damageAmount = damageAmount;
	m_entries[m_count].currentHeight = currentHeight;
	++m_count;
}

//
// ?Rva0027D77D@Rva0062AF7@@UAE_NMMPAM0PA_N@Z retail 0x0027D77D 152 bytes.
// Vslot 19 (offset 0x4C) of vtable 0x007C5890 primary of ??1Rva0062AF7@@UAE@XZ.
// Ground height via slot 6 (offset 0x18) with x y and 0, water via slot 26
// (offset 0x68) with x y and ground, null water returns false, else height
// via slot 30 Rva0027D85B into *a, ground into *b, water slot 1 into *c,
// returns height above ground. Identity class plus slot, honest address name.
// Flags: /O1 plus /arch:SSE plus /G7 (same TU as neighbours).
struct Rva0027D77DWaterView
{
	virtual void slot00();
	virtual bool slot01();
};
bool Rva0062AF7::Rva0027D77D(float x, float y, float *a, float *b, bool *c)
{
	float ground = slot06(x, y, 0);
	void *water = slot26(x, y, ground);
	if (water == 0)
		return false;
	float h = Rva0027D85B(water);
	if (a != 0)
		*a = h;
	if (b != 0)
		*b = ground;
	if (c != 0)
		*c = ((Rva0027D77DWaterView *)water)->slot01();
	return h > ground;
}

//
// ?Rva0027D6DF@Rva0062AF7@@UAEXPAMPBM@Z retail 0x0027D6DF 158 bytes.
// Vslot 14 (offset 0x38) of vtable 0x007C5890 primary of ??1Rva0062AF7@@UAE@XZ.
// Slot 8 (offset 0x20) fills six-float extents, each axis picks hi or lo by
// comparing the factor-scaled span against in, slot 6 grounds the pair, out
// gets the pair plus the ground height. Six-float box plus result triple give
// the 36B frame with out1 at -0xC and out2 at -0x8. Identity class plus slot,
// honest address name. Flags: /O1 plus /arch:SSE plus /G7 (same TU).
void Rva0062AF7::Rva0027D6DF(float *out, const float *in)
{
#define Rva0027D6DFFactor (*(const float *)0x00BC26F0)
	Rva0027D6DFBox box;
	Rva0027D6DFRes res;
	slot08(&box);
	res.out1 = (Rva0027D6DFFactor * (box.hiX - box.loX) > in[0]) ? box.hiX : box.loX;
	res.out2 = (Rva0027D6DFFactor * (box.hiY - box.loY) > in[1]) ? box.hiY : box.loY;
	out[2] = slot06(res.out1, res.out2, 0);
	out[0] = res.out1;
	out[1] = res.out2;
}
