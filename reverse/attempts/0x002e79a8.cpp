// ?Rva002E79A8CellToWorld@@YAPAUCoord3D@@PAU1@_NHHH@Z
// partial score=0.91 date=2026-09-28
// ?Rva002E79A8CellToWorld@@YAPAUCoord3D@@PAU1@_NHHH@Z
// partial score=0.91 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?Rva002E79A8CellToWorld@@YAPAUCoord3D@@PAU1@_NHHH@Z @0x002E79A8 186B
// Cell-to-world converter beside Pathfinder clamp callers 0x002E7B29 0x002E7BF0 0x002E7ED6.
// Scale 10.0 at 0xBC2428, half 0.5 at 0xBC26F0, corner at 0xBC7838. Layer 1 (ground)
// tries TerrainLogic slot 0x4c water check then falls back to slot 0x1c getLayerHeight.

struct Coord3D
{
	float x;
	float y;
	float z;
};

class TerrainLogic
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual float s06(float x, float y, int dummy);
	virtual float getLayerHeight(float x, float y, int layer, void *normal, int clip);
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
	virtual bool waterCheck(float x, float y, float *a, float *b, bool *c);
};

#define TheTerrainLogic (*(TerrainLogic **)0x00DFEC50)
#define CellScale (*(const float *)0x00BC2428)
#define CellHalf (*(const float *)0x00BC26F0)
#define CellBase (*(const float *)0x00BC7838)

// ?Rva002E79A8CellToWorld@@YAPAUCoord3D@@PAU1@_NHHH@Z present-unmatched
Coord3D *__cdecl Rva002E79A8CellToWorld(Coord3D *out, bool center, int cellX, int cellY, int layer)
{
	float scale = CellScale;
	float fx = (float)cellX;
	float off = CellHalf;
	if (!center)
		off = CellBase;
	fx = (fx + off) * scale;
	float fy = (float)cellY;
	fy = (fy + off) * scale;
	float z;
	if (layer == 1 && TheTerrainLogic->waterCheck(fx, fy, &z, 0, 0)) {
	} else {
		z = TheTerrainLogic->getLayerHeight(fx, fy, layer, 0, 1);
	}
	out->x = fx;
	out->y = fy;
	out->z = z;
	return out;
}
