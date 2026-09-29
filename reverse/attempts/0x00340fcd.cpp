// ?rva00340FCD@Rva00340FCD@@QAEMXZ
// partial score=0.95 date=2026-09-29
// ?rva00340FCD@Rva00340FCD@@QAEMXZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD /arch:SSE
// ?rva00340FCD@Rva00340FCD@@QAEMXZ, retail 0x00340FCD, 110 bytes.
// Unlock float method: waypoint chain at +0x5C, 5 steps max, accumulate
// Coord2D distances from 1.0f at 0x00BBB8D8. Evidence: Waypoint getLink
// 0x00085404, Coord2D length 0x00003755, globals, callers 0x00345D4C etc.
class Waypoint
{
public:
	Waypoint *getLink(int index) const;
public:
	char m_pad00[0x0C];
	float m_0C;
	float m_10;
	char m_pad14[0x20 - 0x14];
	Waypoint *m_links[8];
	Waypoint *m_linkSource;
	char m_pad44[8];
	int m_numLinks;
};

struct Coord2D
{
	float x;
	float y;
	float length() const;
};

class Rva00340FCD
{
public:
	float rva00340FCD();
private:
	char m_00[0x5C];
	Waypoint *m_5C;
};

// ?rva00340FCD@Rva00340FCD@@QAEMXZ present-unmatched
float Rva00340FCD::rva00340FCD()
{
	float total = *(float *)0x00BBB8D8;
	Waypoint *cur = m_5C;
	Waypoint *next = cur;
	int n = 5;
	if (cur == 0)
		return total;
	while (n > 0)
	{
		--n;
		if (cur->m_numLinks == 0)
			break;
		next = cur->getLink(0);
		Coord2D d;
		d.x = next->m_0C - cur->m_0C;
		d.y = next->m_10 - cur->m_10;
		total += d.length();
		cur = next;
	}
	return total;
}
