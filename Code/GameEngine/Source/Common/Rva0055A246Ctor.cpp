// cl: /O1 /G7 /arch:SSE /MD /EHsc
// New constructor family from clean BFME1 6d9434269164392c5ba62aaa7c15a86b5b020d76,
// game/GameEngine/Source/Common/Bezier/BezierSegmentConstructionAndLength.cpp.
// Compiled with original header directory first and resolved donor inputs,
// /O1 /G7 /arch:SSE /MD /EHsc. Target facts: three adjacent full bodies
// 55A27E+152, 55A316+103, 55A37D+72 meet the existing copy at 55A3C5.
// Each initializes four 12B elements via the same proven callbacks/iterator,
// then writes or copies the twelve float slots already established here.
// Donor carries Bezier semantics; target original class/method names and
// full object identity remain unknown. Retain the existing address view.
// Copyright 2025 Electronic Arts Inc.; GPL-3.0-or-later, as in the donor.
// ??0Rva0055A246@@QAE@XZ @ 0x0055A246, 56 bytes.
// Default ctor for 4x12-byte array holder: array-new via empty Coord3D
// ctor/dtor then zero 12 floats. Evidence: ??_L call pushes size 0xC count 4
// ctor 0x47A6A9 dtor 0xB3FD0 both rowed empty folds for Coord3D; zero loop
// push-4-pop-ecx plus xorps-movss matches retail; caller 0x5C76CD passes
// this+8 and zeroes surrounding ints/floats.

#include <math.h>

class Coord3D
{
public:
	Coord3D();
	~Coord3D();
	float x;
	float y;
	float z;
};

class Rva0055A246
{
public:
	Rva0055A246();
	Rva0055A246(const Rva0055A246 &other);
	Rva0055A246(float x0, float y0, float z0, float x1, float y1, float z1,
	             float x2, float y2, float z2, float x3, float y3, float z3);
	Rva0055A246(float coordinates[12]);
	Rva0055A246(const Coord3D &cp0, const Coord3D &cp1,
	             const Coord3D &cp2, const Coord3D &cp3);
	void rva0055A0DD(float t, Coord3D *result) const;
	float rva0055A627(float tolerance) const;
	void rva0055A40C(float t, Rva0055A246 &left, Rva0055A246 &right) const;
	Coord3D m_arr[4];
};

Rva0055A246::Rva0055A246()
{
	for (int i = 0; i < 4; ++i) {
		m_arr[i].x = 0.0f;
		m_arr[i].y = 0.0f;
		m_arr[i].z = 0.0f;
	}
}

// ??0Rva0055A246@@QAE@ABV0@@Z @0x0055A3C5 (71B): copy ctor that array-news the
// 4 Coord3Ds via the rowed empty ctor/dtor then copies 12 floats via movsd.
// Evidence: same ??_L pushes as default ctor plus 4x3 movsd matching 4x12;
// callers at 0x00390488 0x0045B87F 0x0048DEDF pass source; returns this.
Rva0055A246::Rva0055A246(const Rva0055A246 &other)
{
	m_arr[0] = other.m_arr[0];
	m_arr[1] = other.m_arr[1];
	m_arr[2] = other.m_arr[2];
	m_arr[3] = other.m_arr[3];
}

Rva0055A246::Rva0055A246(float x0, float y0, float z0,
																					 float x1, float y1, float z1,
																					 float x2, float y2, float z2,
																					 float x3, float y3, float z3)
{
		m_arr[0].x = x0;
		m_arr[0].y = y0;
		m_arr[0].z = z0;

		m_arr[1].x = x1;
		m_arr[1].y = y1;
		m_arr[1].z = z1;

		m_arr[2].x = x2;
		m_arr[2].y = y2;
		m_arr[2].z = z2;

		m_arr[3].x = x3;
		m_arr[3].y = y3;
		m_arr[3].z = z3;
}

Rva0055A246::Rva0055A246(float controlPointCoordinates[12])
{
		m_arr[0].x = controlPointCoordinates[0];
		m_arr[0].y = controlPointCoordinates[1];
		m_arr[0].z = controlPointCoordinates[2];

		m_arr[1].x = controlPointCoordinates[3];
		m_arr[1].y = controlPointCoordinates[4];
		m_arr[1].z = controlPointCoordinates[5];

		m_arr[2].x = controlPointCoordinates[6];
		m_arr[2].y = controlPointCoordinates[7];
		m_arr[2].z = controlPointCoordinates[8];

		m_arr[3].x = controlPointCoordinates[9];
		m_arr[3].y = controlPointCoordinates[10];
		m_arr[3].z = controlPointCoordinates[11];
}

Rva0055A246::Rva0055A246(const Coord3D& cp0,
																			 const Coord3D& cp1,
																			 const Coord3D& cp2,
																			 const Coord3D& cp3)
{
		m_arr[0] = cp0;
		m_arr[1] = cp1;
		m_arr[2] = cp2;
		m_arr[3] = cp3;
}

// Donor6d943 ConstructionAndLength supplies the adaptive length formula.
// Target55A627+436 has four69B length calls to3571, default construction
// of two48B holders, split55A40C and two recursive calls. Ghidra boundary
// and exact EH operands are retained. Original method/class identity unknown.
// The local float-triple difference type keeps temporary lifetime separate from the
// ctor/dtor-bearing stored Coord3D elements. Its full69B length copy matches
// the existing Coord3D::length range3571; no new range or ICF claim for it.
struct Rva0055A627Difference
{
	float x, y, z;

	Rva0055A627Difference( float _x, float _y, float _z ) { x = _x; y = _y; z = _z; }

	// ?Rva0055A627Difference::length present-unmatched
	float length( void ) const { return (float)sqrt( x*x + y*y + z*z ); }
};


float Rva0055A246::rva0055A627(float withinTolerance) const
{
	Rva0055A627Difference p0p1( m_arr[1].x - m_arr[0].x, m_arr[1].y - m_arr[0].y, m_arr[1].z - m_arr[0].z );

	Rva0055A627Difference p1p2( m_arr[2].x - m_arr[1].x, m_arr[2].y - m_arr[1].y, m_arr[2].z - m_arr[1].z );

	Rva0055A627Difference p2p3( m_arr[3].x - m_arr[2].x, m_arr[3].y - m_arr[2].y, m_arr[3].z - m_arr[2].z );

	Rva0055A627Difference p0p3( m_arr[3].x - m_arr[0].x, m_arr[3].y - m_arr[0].y, m_arr[3].z - m_arr[0].z );

	float chordLength = p0p3.length();
	float controlPolygonLength = p0p1.length() + p1p2.length() + p2p3.length();

	if ((controlPolygonLength - chordLength) > withinTolerance) {
		Rva0055A246 firstHalf, secondHalf;
		rva0055A40C(0.5f, firstHalf, secondHalf);
		return (firstHalf.rva0055A627(withinTolerance) + secondHalf.rva0055A627(withinTolerance));
	}

	return ((chordLength + controlPolygonLength) / 2.0f);
}
