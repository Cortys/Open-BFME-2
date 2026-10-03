// ?rva003641F2@Path@@QAEPAUCoord3D@@PAU2@@Z
// partial score=0.98 date=2026-10-03
// ?rva003641F2@Path@@QAEPAUCoord3D@@PAU2@@Z
// partial score=0.96 date=2026-10-01
// ?rva003641F2@Path@@QAEPAUCoord3D@@PAU2@@Z
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// Path::rva003641F2, retail 0x003641F2, 124 bytes: walk selected node +0x10
// via previous +0x4 while waypoint +0x20 != 0x7fffffff and TerrainLogic
// slot +0x8c returns 0, then position-out from selected or head +0x4 or zero.
// Evidence: neighbours PathRva00363DF9/PathRva003649B1 prove Path/PathNode
// layout and /O1 /arch:SSE flags; BFME1 donor PathGetLastValidWaypointPosition
// proves volatile unused=0 at [ebp-4] plus waypoint local and zero-tmp shape;
// TheTerrainLogic global at VA 0x009FEC50; LINK BONUS via 0x00269566.
struct Coord3D
{
	float x;
	float y;
	float z;
};

class PathNode
{
public:
	PathNode *m_next;
	PathNode *m_previous;
	PathNode *m_nextOptimized;
	Coord3D m_position;
	int m_layer;
	bool m_canOptimize;
	int m_waypointID;
};

class Waypoint;

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
	virtual Waypoint *getWaypointByID(int waypointID);
};

extern TerrainLogic *TheTerrainLogic;

class Path
{
public:
	Coord3D *rva003641F2(Coord3D *out);

private:
	void *m_unknown00;
	PathNode *m_path;
	PathNode *m_pathTail;
	bool m_isOptimized;
	bool m_unknown0D;
	PathNode *m_unknown10;
	float m_unknown14;
	float m_unknown18;
	float m_unknown1C;
	float m_unknown20;
	int m_unknown24;
};

Coord3D *Path::rva003641F2(Coord3D *out)
{
volatile bool unused = 0;
	Coord3D tmp;
	PathNode *sel = m_unknown10;
	Waypoint *waypoint = 0;
	while (sel != 0) {
		int wp = sel->m_waypointID;
		if (wp == 0x7fffffff)
			break;
		waypoint = TheTerrainLogic->getWaypointByID(wp);
		if (waypoint != 0)
			break;
		sel = sel->m_previous;
	}
	const Coord3D *src;
	if (sel != 0)
		src = &sel->m_position;
	else if (m_path != 0)
		src = &m_path->m_position;
	else {
		tmp.x = 0.0f;
		tmp.y = 0.0f;
		tmp.z = 0.0f;
		src = &tmp;
	}
	out->x = src->x;
	out->y = src->y;
	out->z = src->z;
	return out;
}
