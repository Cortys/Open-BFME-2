// ?rva004C4E93@Rva004C4E93@@QAEXPBUCoord3D@@@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /arch:SSE /MD /DNDEBUG /DWIN32 /D_WINDOWS
// ?rva004C4E93@Rva004C4E93@@QAEXPBUCoord3D@@@Z @0x004C4E93 137B
// Weather-gated terrain-center FX: early out when GlobalWeatherSystem+0x10==1 or data FX null then getExtent center scaled by g_Va007C26F0 with z from arg.
// Evidence: globals TheGlobalWeatherSystem TheTerrainLogic g_Va007C26F0 packet names; getExtent slot 8 precedent TerrainLogic_setActiveBoundary.cpp; doFXPos row 0x94C29; caller 0x4C4F4E unclaimed.
typedef float Real;

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Matrix3D
{
public:
	float m[12];
};

struct Region3D
{
	Real lo[3];
	Real hi[3];
};

class __declspec(novtable) TerrainLogic
{
public:
	virtual void slot00() = 0;
	virtual void slot01() = 0;
	virtual void slot02() = 0;
	virtual void slot03() = 0;
	virtual void slot04() = 0;
	virtual void slot05() = 0;
	virtual void slot06() = 0;
	virtual void slot07() = 0;
	virtual void getExtent(Region3D *extent) const = 0;
};

extern TerrainLogic *TheTerrainLogic;

class GlobalWeatherSystem
{
public:
	char m_pad00[0x10];
	int m_10;
};

extern GlobalWeatherSystem *TheGlobalWeatherSystem;

extern float g_Va007C26F0;

class FXList
{
public:
	static void doFXPos(const FXList *fx, const Coord3D *primary, const Matrix3D *mtx, float speed, const Coord3D *secondary);
};

class Rva004C4E93Inner
{
public:
	char m_pad[0x80];
	FXList *m_fx;
};

class Rva004C4E93
{
public:
	char m_pad[4];
	Rva004C4E93Inner *m_inner;
	void rva004C4E93(const Coord3D *arg);
};

// ?rva004C4E93@Rva004C4E93@@QAEXPBUCoord3D@@@Z present-unmatched
void Rva004C4E93::rva004C4E93(const Coord3D *arg)
{
	if (TheGlobalWeatherSystem->m_10 == 1)
		return;
	Rva004C4E93Inner *inner = m_inner;
	if (inner->m_fx == 0)
		return;
	Region3D extent;
	TheTerrainLogic->getExtent(&extent);
	Coord3D pos;
	Real hx = extent.lo[0];
	hx += extent.hi[0];
	hx *= g_Va007C26F0;
	pos.x = hx;
	Real hy = extent.lo[1];
	hy += extent.hi[1];
	hy *= g_Va007C26F0;
	pos.y = hy;
	pos.z = arg->z;
	FXList::doFXPos(inner->m_fx, &pos, 0, 0.0f, 0);
}
