// cl: /Ireference/shims/bfmerendobj /O2 /G7 /MD /arch:SSE /DNDEBUG /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
// BFME1 donor 4367fc698990427e26cc1c399989d074d8ee9bbe:
// game/Libraries/Source/WWVegas/WWMath/Matrix3D_Rotate_Vector.cpp,
// retail RVA 0x00924480 (103B). BFME2 O2/G7/SSE reproduces 175B at
// 0x0071CD60: int3 boundaries and a terminal ret 12.
// Target reads nine float coefficients in three rows 16B apart, writes
// three products summed per output coordinate, and advances both arrays 12B.
// Fourth row components are unused. There are no calls or relocations.
// Shared Matrix3D/Vector3 are structural views; this adapter adds no layout.
// Original target class and method names remain unproven.

// Same first-array anchor as Matrix3DUnmatchedSSE.cpp: keep the emitted
// compiler vector constructor iterator at retail's 34B /O1 shape.
// This static driver is unemitted and has no retail claim.
struct BfmeVciAnchorElem { BfmeVciAnchorElem(); };
#pragma optimize("gsy", on)
// ?bfmeArrayRotateVciAnchor absent-from-retail
static void bfmeArrayRotateVciAnchor() { BfmeVciAnchorElem anchor[2]; (void)anchor; }
#pragma optimize("", on)

#include "matrix3d.h"

class Rva0071CD60MatrixArrayRotate : public Matrix3D
{
public:
 void rotate_vectors(const Vector3 *in, Vector3 *out, int count) const;
};

void Rva0071CD60MatrixArrayRotate::rotate_vectors(const Vector3 *in,
	Vector3 *out, int count) const
{
	while (count--)
	{
		out->X = (Row[0].X * in->X + Row[0].Y * in->Y + Row[0].Z * in->Z);
		out->Y = (Row[1].X * in->X + Row[1].Y * in->Y + Row[1].Z * in->Z);
		out->Z = (Row[2].X * in->X + Row[2].Y * in->Y + Row[2].Z * in->Z);
		++in;
		++out;
	}
}
