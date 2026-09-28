// cl: /O1 /DNDEBUG /MD /EHs-c-
// ?Rva00503D8EEvaluate@@YAMMMMMM@Z @0x00503D8E 93B: Catmull-Rom scalar evaluate(p0 p1 p2 p3 t).
// Donor: reference/open-bfme-1/Code/GameEngine/Source/Common/calc.cpp (Rva00064410Catmull::evaluate stub)
// and BfmeConv1266.cpp bfmeSpline1266 formula. Callers at 0x00503F61 0x00503F8B 0x00503FB1 0x00504477
// 0x005C718B 0x005C735C 0x005C7386 0x005C73AE. Constants 3.0 5.0 4.0 0.5 in .rdata.

float __cdecl Rva00503D8EEvaluate(float p0, float p1, float p2, float p3, float t)
{
	return ((((p1 * 3.0f - p0 - p2 * 3.0f + p3) * t + (p0 + p0 - p1 * 5.0f + p2 * 4.0f - p3)) * t + (p2 - p0)) * t + (p1 + p1)) * 0.5f;
}
