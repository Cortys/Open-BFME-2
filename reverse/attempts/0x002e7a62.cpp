// ?computeNormalRadialOffset@@YAXABUCoord3D@@AAU1@0PAVObject@@M@Z
// partial score=0.9 date=2026-09-30
// ?computeNormalRadialOffset@@YAXABUCoord3D@@AAU1@0PAVObject@@M@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?computeNormalRadialOffset@@YAXABUCoord3D@@AAU1@0PAVObject@@M@Z @0x002E7A62 160B
// Donor: BFME1 AIPathfind.cpp computeNormalRadialOffset (from+insert+to+obj+radius)
// Callers 0x002E9BE5 and 0x002F3392 pass from+to in ecx+eax and insert in ebx plus obj+radius on stack.
// Retail cross=dx*objDy-dy*objDx plus perp+normalize+insert=pos+scale matches donor exactly.
// Current __fastcall probe is 165B vs 160B: retail uses eax not edx for to and ebx not stack for insert plus ret not ret 0xc.
typedef float Real;
struct Coord3D { Real x; Real y; Real z; void normalize(); };
class Object { public: unsigned char pad[0x38]; Coord3D position; const Coord3D* getPosition() const { return &position; } };
void __fastcall fastOffset5(const Coord3D& from, const Coord3D& to, Coord3D& insert, Object* obj, Real radius)
{
	Real dx = to.x - from.x;
	Real dy = to.y - from.y;
	Real objDx = obj->getPosition()->x - from.x;
	Real objDy = obj->getPosition()->y - from.y;
	Real crossProduct = dx*objDy - dy*objDx;
	Coord3D fromToNormal;
	fromToNormal.z = 0;
	if (crossProduct>0) {
		fromToNormal.x = dy;
		fromToNormal.y = -dx;
	} else {
		fromToNormal.x = -dy;
		fromToNormal.y = dx;
	}
	fromToNormal.normalize();
	insert = *obj->getPosition();
	insert.x += fromToNormal.x*radius;
	insert.y += fromToNormal.y*radius;
}
