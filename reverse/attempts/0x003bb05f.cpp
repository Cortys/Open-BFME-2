// ?Rva003BB05FSet@@YGXHMMMH@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /arch:SSE
// ?Rva003BB05FSet@@YGXHMMMH@Z @0x003BB05F 104B leaf caller 0x003CAFAB globals 0xDFEC50 0xDFEA3C 0xBBE358 slots 0x88 0xD4
// Evidence: TerrainLogic slot 0x88 returns ptr then null-checked; +0xc passed to TacticalView slot 0xD4 with scaled floats and int.
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
	virtual char *s34(int a);
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
	virtual void s37();
	virtual void s38();
	virtual void s39();
	virtual void s40();
	virtual void s41();
	virtual void s42();
	virtual void s43();
	virtual void s44();
	virtual void s45();
	virtual void s46();
	virtual void s47();
	virtual void s48();
	virtual void s49();
	virtual void s50();
	virtual void s51();
	virtual void s52();
	virtual void s53(void *p, int i, float f1, float f2, int j);
};
extern TacticalView *TheTacticalView;
extern float g_00BBE358;
// ?Rva003BB05FSet@@YGXHMMMH@Z present-unmatched
void __stdcall Rva003BB05FSet(int a1, float a2, float a3, float a4, int a5)
{
	char *r = TheTerrainLogic->s34(a1);
	if (!r)
		return;
	float s = g_00BBE358;
	float a4v = *(const volatile float *)&a4;
	float a3v = *(const volatile float *)&a3;
	float a2v = *(const volatile float *)&a2;
	TheTacticalView->s53(r + 12, (int)(a2v * s), a3v * s, a4v * s, a5);
}
