// cl: /O1 /arch:SSE /Ob0
//
// ??0Rva00540E82@@QAE@XZ, retail 0x00540E82 27B.
// Constructor: int at +0 = 2, floats at +4 +8 +0xC = 0.0 via xorps/movss.
// Evidence: no calls; callers at 0x00540FFE (outer init constructs +4
// subobject after zeroing +0) and 0x00542351 (stack temp in waypoint
// array loop); unblocks 0x00540FF6 and 0x00542314.
// ??0Rva00540FF6@@QAE@XZ, retail 0x00540FF6 16B: outer ctor with int at +0
// = 0 and inner Rva00540E82 at +4 via rowed ctor. /Ob0 keeps the inner
// call from inlining so retail keeps lea ecx,[edx+4] call.
// ??0Rva00540FDB@@QAE@HABURegion3D@@@Z, retail 0x00540FDB 27B: ctor with
// int at +0 and Region3D at +4 via rowed copy ctor 0x0009AC04.

class Rva00540E82
{
public:
	Rva00540E82();
	int m_00;
	float m_04;
	float m_08;
	float m_0c;
};

Rva00540E82::Rva00540E82() : m_00(2), m_04(0.0f), m_08(0.0f), m_0c(0.0f)
{
}

class Rva00540FF6
{
public:
	Rva00540FF6();
	int m_00;
	Rva00540E82 m_04;
};

Rva00540FF6::Rva00540FF6() : m_00(0)
{
}

struct Region3D
{
	Region3D(const Region3D &that);
};

class Rva00540FDB
{
public:
	Rva00540FDB(int v, const Region3D &r);
	int m_00;
	Region3D m_04;
};

Rva00540FDB::Rva00540FDB(int v, const Region3D &r) : m_00(v), m_04(r)
{
}
