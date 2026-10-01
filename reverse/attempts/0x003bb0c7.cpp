// ?Rva003BB0C7Set@@YGXHMHMMMH@Z
// partial score=0.94 date=2026-10-01
// cl: /O1 /arch:SSE
// ?Rva003BB0C7Set@@YGXHMHMMMH@Z @0x003BB0C7 122B leaf caller 0x003CADF5 globals 0xDFEC50 0xDFEA3C 0xBBE358 slots 0x94 0x64
// Evidence: TerrainLogic slot 0x94 returns ptr null-checked and m_60==6; +eax passed to TacticalView slot 0x64 with scaled floats and int and 1.
class TerrainLogic
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual void s16();
	virtual void s17();
	virtual void s18();
	virtual void s19();
	virtual void s20();
	virtual void s21();
	virtual void s22();
	virtual void s23();
	virtual void s24();
	virtual void s25();
	virtual void s26();
	virtual void s27();
	virtual void s28();
	virtual void s29();
	virtual void s30();
	virtual void s31();
	virtual void s32();
	virtual void s33();
	virtual void s34();
	virtual void s35();
	virtual void s36();
	virtual struct Ret *s37(int a);
};
struct Ret
{
	char m_pad[0x60];
	int m_60;
};
extern TerrainLogic *TheTerrainLogic;
class TacticalView
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual void s16();
	virtual void s17();
	virtual void s18();
	virtual void s19();
	virtual void s20();
	virtual void s21();
	virtual void s22();
	virtual void s23();
	virtual void s24();
	virtual void s25(void *p, int i, int one, float f4, float f5, float f6, int last);
};
extern TacticalView *TheTacticalView;
extern float g_00BBE358;
// ?Rva003BB0C7Set@@YGXHMHMMMH@Z present-unmatched
void __stdcall Rva003BB0C7Set(int a1, float a2, int a3, float a4, float a5, float a6, int a7)
{
	Ret *r = (Ret *)TheTerrainLogic->s37(a1);
	if (!r || r->m_60 != 6)
		return;
	float s = g_00BBE358;
	float a6v = *(const volatile float *)&a6;
	float a5v = *(const volatile float *)&a5;
	float a4v = *(const volatile float *)&a4;
	float a2v = *(const volatile float *)&a2;
	TheTacticalView->s25(r, (int)(a2v * s), 1, a4v * s, a5v * s, a6v * s, a7);
}
