// ?Rva002EBC14Cell@@YAPAUICoord2D@@PAU1@PAXPBUCoord3D@@@Z
// partial score=0.86 date=2026-10-03
// cl: /O1 /MD
// ?Rva002EBBFBIsOdd@@YAEPAX@Z @0x002EBBFB 25B
// Free __cdecl unsigned char (void*) wrapping ?Rva002E9B31Get@@YAHPAX@Z parity test.
// Evidence: 12 callers pass single pointer and use result as bool for WorldToCell;
// retail cdq/idiv 2 plus dec/neg/sbb/inc is (Get(p)%2)==1; unblocks 0x002EBC14 etc.
int __cdecl Rva002E9B31Get(void *p);
unsigned char __cdecl Rva002EBBFBIsOdd(void *p)
{
	int v = Rva002E9B31Get(p) % 2;
	return (unsigned char)(v == 1 ? 1 : 0);
}
// ?Rva002EBCA7Split@@YAXPAXPAHPAE@Z @0x002EBCA7 47B
// Free __cdecl void (void* int* uchar*) splitting Get(p) into half and odd bit.
// Evidence: caller 0x002ED7B6 passes p plus [esi+0xC] int and [esi+0x8] byte and ignores eax;
// retail stores Get then (rem==1) byte then v/2 via cdq/sub/sar; unblocks 0x002ECD63 etc.
void __cdecl Rva002EBCA7Split(void *p, int *outHalf, unsigned char *outOdd)
{
	int v = Rva002E9B31Get(p);
	*outHalf = v;
	*outOdd = (v % 2 == 1);
	*outHalf /= 2;
}
// ?Rva002EBC14Cell@@YAPAUICoord2D@@PAU1@PAXPBUCoord3D@@@Z, retail 0x002EBC14 (32 bytes).
// Free __cdecl (ICoord2D*, void*, const Coord3D*) -> ICoord2D*: odd = IsOdd(p),
// WorldToCell(out, odd, pos), return out. Evidence: retail pushes pos then p,
// calls IsOdd, pops p dead into ecx (ecx never read, so not __thiscall despite
// the naming hint), pushes eax/out, calls WorldToCell, reloads out into eax,
// caller-cleans 0xc; callees both rowed (IsOdd above, WorldToCell in
// PathfindShimWorldToCell.cpp); unblocks 0x002EC9E1 etc.
struct ICoord2D;
struct Coord3D;
struct ICoord2D *__cdecl Rva002E7875WorldToCell(struct ICoord2D *out, bool center, const struct Coord3D *pos);
// ?Rva002EBC14Cell@@YAPAUICoord2D@@PAU1@PAXPBUCoord3D@@@Z present-unmatched
struct ICoord2D *__cdecl Rva002EBC14Cell(struct ICoord2D *out, void *p, const struct Coord3D *pos)
{
	Rva002E7875WorldToCell(out, Rva002EBBFBIsOdd(p), pos);
	return out;
}
