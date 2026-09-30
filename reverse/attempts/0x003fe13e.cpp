// ?rva003FE13E@Rva003FE13E@@QAEMXZ
// partial score=0.93 date=2026-09-30
// ?rva003FE13E@Rva003FE13E@@QAEMXZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /arch:SSE2 /MD
//
// ?rva003FE13E@Rva003FE13E@@QAEMXZ @0x003FE13E 129B. __thiscall float method:
// builds a Coord2D from ([+0x50]-[+0x18], [+0x54]-[+0x1C]), takes its rowed
// length as dist, loads [+0x58] as cap, gates a scale by the rowed AIPlayer
// check on g_009FE720 plus GlobalData +0x88, and returns min(dist, cap).
// Evidence: rowed length and AIPlayer callees; extern names from the packet;
// SSE shape needs arch:SSE2; caller 0x003FE2CF.
class Coord2D
{
public:
	float m_x;
	float m_y;
	float length() const;
};

class AIPlayer
{
public:
	bool rva00232683();
};

class Rva0025CEEFHost : public AIPlayer
{
};

extern Rva0025CEEFHost *g_009FE720;

struct GlobalData
{
	char m_pad00[0x88];
	unsigned char m_88;
};

extern GlobalData *TheWritableGlobalData;
extern float g_Va00BC2428;

class Rva003FE13E
{
	float m_pad00[6];
	float m_18;
	float m_1C;
	char m_pad20[0x50 - 0x20];
	float m_50;
	float m_54;
	float m_58;

public:
	float rva003FE13E();
};

// ?rva003FE13E@Rva003FE13E@@QAEMXZ present-unmatched
float Rva003FE13E::rva003FE13E()
{
	Coord2D d = { m_50 - m_18, m_54 - m_1C };
	d.m_y = d.length();
	float cap = m_58;
	if (g_009FE720->rva00232683()) {
		if (TheWritableGlobalData->m_88 != 0)
			cap *= g_Va00BC2428;
	}
	return *((d.m_y > cap) ? &cap : &d.m_y);
}
