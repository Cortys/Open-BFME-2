// ?Rva0055CAACFillScaled@@YGXPAVCoord3D@@IMI@Z
// partial score=0.91 date=2026-09-28
// ?Rva0055CAACFillScaled@@YGXPAVCoord3D@@IMI@Z
// partial score=0.91 date=2026-09-28
// cl: /O1 /MD /arch:SSE
// ?Rva0055CAACFillScaled@@YGXPAVCoord3D@@IMI@Z probe 67B
class Coord3D
{
public:
	float x;
	float y;
	float z;
};

Coord3D *__cdecl Rva003AFA64FillUnitVector(Coord3D *out);

void __stdcall Rva0055CAACFillScaled(Coord3D *out, unsigned int a, float scale, unsigned int b)
{
	Coord3D dir;
	Rva003AFA64FillUnitVector(&dir);
	out->x = dir.x * scale;
	out->y = dir.y * scale;
	out->z = dir.z * scale;
}
