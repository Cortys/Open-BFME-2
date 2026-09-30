// ?rva003AFA0B@Rva003AFA0B@@QAEXPAVCoord3D@@PAX0M1@Z
// partial score=0.9 date=2026-09-30
// ?rva003AFA0B@Rva003AFA0B@@QAEXPAVCoord3D@@PAX0M1@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /MD /arch:SSE
// ?rva003AFA0B@Rva003AFA0B@@QAEXPAVCoord3D@@PAX0M1@Z @0x003AFA0B (89B)
// Thiscall method scaling an input vector by a virtual basis plus a float.
// Calls slot 4 at +0x10 with 12-byte out plus two pointer args then out
// equals in times basis times scale componentwise via movss mulss. Ret 0x14
// pops five stack args. Caller 0x001F54C5. Evidence unlock lane virtual call
// plus SSE plus ret N prove thiscall next FillUnitVector proves Coord3D flags.
class Coord3D
{
public:
	float x;
	float y;
	float z;
};
class Rva003AFA0B
{
public:
	virtual ~Rva003AFA0B();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void slot4(Coord3D *out, void *a, void *b);
	void rva003AFA0B(Coord3D *dst, void *a, Coord3D *src, float scale, void *b);
};
// ?rva003AFA0B@Rva003AFA0B@@QAEXPAVCoord3D@@PAX0M1@Z present-unmatched
void Rva003AFA0B::rva003AFA0B(Coord3D *dst, void *a, Coord3D *src, float scale, void *b)
{
	Coord3D basis;
	this->slot4(&basis, a, b);
	float x = src->x;
	float y = src->y;
	float z = src->z;
	x *= basis.x;
	y *= basis.y;
	z *= basis.z;
	x *= scale;
	y *= scale;
	z *= scale;
	dst->x = x;
	dst->y = y;
	dst->z = z;
}
