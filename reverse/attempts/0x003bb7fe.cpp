// ?Rva003BB7FESet@@YGXH_N@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /arch:SSE
// ?Rva003BB7FESet@@YGXH_N@Z @0x003BB7FE 154B leaf caller 0x003CC30D globals 0xDFEC50 0xDFEA3C slots 0x88 0xBC 0xB4 0x54 0xB8
// Evidence: TerrainLogic slot 0x88 Waypoint loc copy then TacticalView s47 s45 s21 s46 chain with bool selecting 8 vs 7.
struct Coord3D { float x, y, z; };
struct Waypoint { char m_pad[0x0c]; float x, y, z; };
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
	virtual Waypoint *s34(int a);
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
	virtual void s21(Coord3D *p);
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
	virtual unsigned char s45(int v);
	virtual void s46(Coord3D *p, int v);
	virtual unsigned char s47(int v);
};
extern TacticalView *TheTacticalView;
// ?Rva003BB7FESet@@YGXH_N@Z present-unmatched
void __stdcall Rva003BB7FESet(int a1, bool flag)
{
	Waypoint *r = TheTerrainLogic->s34(a1);
	if (!r)
		return;
	Coord3D c;
	c.x = r->x;
	c.y = r->y;
	c.z = r->z;
	if (!TheTacticalView->s47(2)) {
		TheTacticalView->s21(&c);
		return;
	}
	unsigned char r45;
	if (flag)
		r45 = TheTacticalView->s45(8);
	else
		r45 = TheTacticalView->s45(7);
	if (r45 != 0)
		TheTacticalView->s46(&c, 0);
	else {
		TheTacticalView->s47(0);
		TheTacticalView->s21(&c);
	}
}
