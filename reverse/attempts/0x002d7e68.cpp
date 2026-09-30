// ?rva002D7E68@Radar@@QAEXPAX@Z
// partial score=0.96 date=2026-09-30
// ?rva002D7E68@Radar@@QAEXPAX@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva002D7E68@Radar@@QAEXPAX@Z, retail 0x002D7E68, 326 bytes. Radar terrain
// refresh (vslot 6 of 0x0080363C): newMap, second-base refresh, extent fetch,
// sample steps, 128x128 radarToWorld sampling with ground-height and water
// query accumulation into +0x1C/+0x20 averages. Evidence: calls rowed
// ?newMap@Radar@@QAEXXZ and ?radarToWorld@Radar@@QAE_NPBUICoord2D@@PAUCoord3D@@@Z;
// extent at +0x1434 with width=[+0xC]-[+0] height=[+0x10]-[+4] matching
// Radar_findDrawPositions RadarExtent; samples at +0x24/+0x28, averages at
// +0x1C/+0x20 matching Radar_radarToWorld offsets; 0x80x0x80 loops.

struct ICoord2D
{
	int x;
	int y;
};

struct Coord3D
{
	float x;
	float y;
	float z;
};

struct RadarExtent
{
	float minX;
	float minY;
	int reserved;
	float maxX;
	float maxY;
};

class TerrainLogic
{
public:
	virtual void t00();
	virtual void t01();
	virtual void t02();
	virtual void t03();
	virtual void t04();
	virtual void t05();
	virtual float getGroundHeight(float x, float y, int unk);
	virtual void t07();
	virtual void t08();
	virtual void getMapExtent(RadarExtent *extent);
	virtual void t10();
	virtual void t11();
	virtual void t12();
	virtual void t13();
	virtual void t14();
	virtual void t15();
	virtual void t16();
	virtual void t17();
	virtual void t18();
	virtual bool queryWater(float x, float y, int *out, int a, int b);
};

class RadarSecond
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
	virtual void refresh();
};

class Radar
{
public:
	void newMap();
	bool radarToWorld(const ICoord2D *radar, Coord3D *world);
	void rva002D7E68(void *terrain);
private:
	int m_unk00; // +0x00
	RadarSecond m_second; // +0x04
	char m_pad08[0x1C - 0x08];
	float m_avgTerrain; // +0x1C
	float m_avgWater; // +0x20
	float m_xSample; // +0x24
	float m_ySample; // +0x28
	char m_pad2C[0x1430 - 0x2C];
	void *m_radarWindow; // +0x1430
	RadarExtent m_extent; // +0x1434
};

// ?rva002D7E68@Radar@@QAEXPAX@Z present-unmatched
void Radar::rva002D7E68(void *terrainParam)
{
	newMap();
	m_second.refresh();
	TerrainLogic *terrain = (TerrainLogic *)terrainParam;
	RadarExtent *ext = &m_extent;
	terrain->getMapExtent(ext);
	m_xSample = (ext->maxX - ext->minX) / 128.0f;
	m_ySample = (ext->maxY - ext->minY) / 128.0f;
	m_avgTerrain = 0.0f;
	m_avgWater = 0.0f;
	int countTerrain = 0;
	int countWater = 0;
	for (int y = 0; y < 128; ++y)
	{
		for (int x = 0; x < 128; ++x)
		{
			ICoord2D cell;
			cell.y = y;
			cell.x = x;
			Coord3D world;
			radarToWorld(&cell, &world);
			int hi = (int)terrain->getGroundHeight(world.x, world.y, 0);
			int tmp;
			bool water = terrain->queryWater(world.x, world.y, &tmp, 0, 0);
			if (water)
			{
				m_avgWater += (float)hi;
				++countWater;
			}
			else
			{
				m_avgTerrain += (float)hi;
				++countTerrain;
			}
		}
	}
	if (countTerrain == 0)
		countTerrain = 1;
	if (countWater == 0)
		countWater = 1;
	m_avgTerrain /= (float)countTerrain;
	m_avgWater /= (float)countWater;
}
