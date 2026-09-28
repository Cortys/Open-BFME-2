// cl: /O1 /arch:SSE
//
// ??0Rva00540E82@@QAE@XZ, retail 0x00540E82 27B.
// Constructor: int at +0 = 2, floats at +4 +8 +0xC = 0.0 via xorps/movss.
// Evidence: no calls; callers at 0x00540FFE (outer init constructs +4
// subobject after zeroing +0) and 0x00542351 (stack temp in waypoint
// array loop); unblocks 0x00540FF6 and 0x00542314.

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
