// ?rva004320B1@Rva004320B1@@QAEHPAVGameMessage@@@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /MD
// ?rva004320B1@Rva004320B1@@QAEHPAVGameMessage@@@Z @0x004320B1 160B: thiscall dispatcher on GameMessage+0x10 for 3 vs 6/0x10 via rowed Rva00431A4D Rva00431E95 plus TacticalView screenToTerrain and InGameUI slots. Evidence: chain via 0x00431E95; globals TheTacticalView TheInGameUI; rowed getArgument 0x0030F4EA rva0029AA27 0x0029AA27; prev Rva00431F61Ctor next Rva0043216DCtor same dir.
struct ICoord2D
{
	int m_x;
	int m_y;
};

struct Coord3D
{
	float m_x;
	float m_y;
	float m_z;
};

union GameMessageArgumentType
{
	int integer;
	struct Pix { int x; int y; } pixel;
};

class GameMessage
{
public:
	const GameMessageArgumentType *getArgument(int argIndex) const;
	char m_pad[0x10];
	int m_10;
};

class Rva00431A4D
{
	char m_00[4];
	unsigned char m_04;
	unsigned char m_05;
public:
	void rva00431A4D(GameMessage *msg);
};

class Rva00431E95
{
	void *m_00;
	void *m_04;
public:
	int rva00431E95(void *p);
};

class TacticalView
{
public:
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
	virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
	virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
	virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
	virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
	virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
	virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
	virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
	virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
	virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
	virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63();
	virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67();
	virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
	virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
	virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
	virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83();
	virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87();
	virtual void s88(); virtual void s89();
	virtual void screenToTerrain(const ICoord2D *pixel, Coord3D *world, bool clamp);
};

extern TacticalView *TheTacticalView;

struct S12_0029AA27
{
	int a;
	int b;
	int c;
};

class Rva0029AA27
{
public:
	void rva0029AA27(const S12_0029AA27 *src);
};

class InGameUI
{
public:
	virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
	virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
	virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
	virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
	virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
	virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
	virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
	virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
	virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
	virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
	virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
	virtual void slot48(); virtual void slot49();
	virtual void slot50(Coord3D *pos);
	virtual bool slot51();
private:
	char m_pad[0x9B4 - 4];
public:
	unsigned char m_9b4;
};

extern InGameUI *TheInGameUI;

class Rva004320B1
{
	void *m_00;
	Rva00431A4D *m_04;
public:
	int rva004320B1(GameMessage *msg);
};

int Rva004320B1::rva004320B1(GameMessage *msg)
{
	int t = msg->m_10;
	switch (t)
	{
	case 3:
	{
		const GameMessageArgumentType *a0 = msg->getArgument(0);
		ICoord2D pixel;
		pixel.m_x = a0->pixel.x;
		pixel.m_y = a0->pixel.y;
		Coord3D world;
		TheTacticalView->screenToTerrain(&pixel, &world, false);
		if (TheInGameUI->slot51())
			TheInGameUI->slot50(&world);
		if (TheInGameUI->m_9b4 != 0)
			((Rva0029AA27 *)TheInGameUI)->rva0029AA27((const S12_0029AA27 *)&world);
		return 0;
	}
	case 6:
	case 0x10:
		m_04->rva00431A4D(msg);
		return ((Rva00431E95 *)this)->rva00431E95(msg);
	default:
		return 0;
	}
}
