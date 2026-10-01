// ?rva001E4015@Rva001E4015@@QAE_NPAVThing@@PAURva001E4015Vec2@@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /arch:SSE
//
// ?rva001E4015@Rva001E4015@@QAE_NPAVThing@@PAURva001E4015Vec2@@@Z @0x001E4015 94B
// __thiscall bool check via +0x4 object +0x74==1 and +0xd8!=0 then
// Thing::getUnitDirectionVector2D 0x0030A2A2 dot with second arg minus
// Thing +0x38/+0x3c; returns dot<0 via comiss; caller 0x00365F61 in 0x00365E98.
struct Coord3D
{
	float x, y, z;
};
class Thing
{
public:
	void getUnitDirectionVector2D(Coord3D &out) const;
	unsigned char m_pad[0x38];
	float m38;
	float m3c;
};
struct Rva001E4015Vec2
{
	float m00;
	float m04;
};
struct Rva001E4015A
{
	unsigned char m_pad[0x74];
	int m74;
	unsigned char m_pad2[0xd8 - 0x74 - 4];
	int mD8;
};
class Rva001E4015
{
public:
	bool rva001E4015(Thing *t, Rva001E4015Vec2 *v);
private:
	int m00;
	Rva001E4015A *m04;
};
// ?rva001E4015@Rva001E4015@@QAE_NPAVThing@@PAURva001E4015Vec2@@@Z present-unmatched
bool Rva001E4015::rva001E4015(Thing *t, Rva001E4015Vec2 *v)
{
	if (m04->m74 != 1 || m04->mD8 == 0)
		return false;
	Coord3D dir;
	t->getUnitDirectionVector2D(dir);
	float dx = v->m00 - t->m38;
	float dy = v->m04 - t->m3c;
	float dot = dy * dir.y + dx * dir.x;
	if (dot < 0.0f)
		return true;
	return false;
}
