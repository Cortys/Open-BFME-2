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
