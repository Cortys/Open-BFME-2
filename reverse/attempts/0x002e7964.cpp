// ?Rva002E7964@Pathfinder@@QAEXPAUICoord2D@@_NPBUCoord3D@@@Z
// partial score=0.93 date=2026-09-27
// ?Rva002E7964@Pathfinder@@QAEXPAUICoord2D@@_NPBUCoord3D@@@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
typedef int Int;
typedef float Real;
struct ICoord2D { Int x, y; };
struct Coord3D { Real x, y, z; };
struct IRegion2D { ICoord2D lo, hi; };
ICoord2D* __cdecl Rva002E7875WorldToCell(ICoord2D* out, bool center, const Coord3D* pos);
class Pathfinder
{
public:
	void Rva002E7964(ICoord2D* out, bool center, const Coord3D* pos);
private:
	unsigned char m_pad[0x14];
	IRegion2D m_extent;
};
void Pathfinder::Rva002E7964(ICoord2D* out, bool center, const Coord3D* pos)
{
	ICoord2D tmp;
	Rva002E7875WorldToCell(&tmp, center, pos);
	if (tmp.x < m_extent.lo.x || tmp.y < m_extent.lo.y || tmp.x > m_extent.hi.x || tmp.y > m_extent.hi.y)
		tmp.x = -1;
	out->x = tmp.x;
	out->y = tmp.y;
}
