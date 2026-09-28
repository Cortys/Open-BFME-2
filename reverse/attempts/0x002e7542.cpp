// ?rva002E7542@Rva002E7542@@QAEXHPBUCoord3D@@H@Z
// partial score=0.95 date=2026-09-28
// ?rva002E7542@Rva002E7542@@QAEXHPBUCoord3D@@H@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc
struct Coord3D { float x; float y; float z; };
class Rva002E7542 {
public:
 void rva002E7542(int a1, const Coord3D *a2, int a3);
private:
 int m_00;
 int m_04;
 int m_08;
 int m_0c;
 int m_10;
};
void Rva002E7542::rva002E7542(int a1, const Coord3D *a2, int a3)
{
 m_00 = a1;
 m_04 = a3;
 m_08 = *(int*)&a2->x;
 m_0c = *(int*)&a2->y;
 m_10 = *(int*)&a2->z;
}
