// ?rva005DBA9C@Rva005DB98E@@QAE_N_N@Z
// partial score=0.97 date=2026-10-03
// cl: /O1 /G7 /DNDEBUG /MD
// ?rva005DB98E@Rva005DB98E@@QAEPAXGG@Z 0x005DB98E 46B
// Bounds-checked 2D index into 20B elements at +0x218.
// Evidence: callers 0x5A6D0A 0x5DB570 etc.; unblocks 8.
struct Elem005DB98E
{
	char m_data[20];
};

class GameSlot
{
public:
	bool isHuman() const;
};

class Rva005DB98E
{
	char m_pad0[0x14];
	unsigned short m_cur;
	char m_pad0b[2];
	int m_arr2[81];
	char m_pad1[0x218 - 0x18 - 81 * 4];
	Elem005DB98E m_arr[81];
	char m_pad2[0x8b8 - 0x86c];
	GameSlot **m_slots;
public:
	void* rva005DB98E(unsigned short x, unsigned short y);
	int rva005DB9BC(unsigned short x, unsigned short y);
	bool rva005DBA60(unsigned short x);
	bool rva005DBA9C(bool flag);
};

void* Rva005DB98E::rva005DB98E(unsigned short x, unsigned short y)
{
	if (x > 8)
		return 0;
	if (y > 8)
		return 0;
	return &m_arr[y + x * 8];
}

int Rva005DB98E::rva005DB9BC(unsigned short x, unsigned short y)
{
	if (x > 8)
		return 0;
	if (y > 8)
		return 0;
	return m_arr2[y + x * 8];
}

// ?rva005DBA60@Rva005DB98E@@QAE_NG@Z 0x005DBA60 60B
// Unlock row/col scan for value 2 in m_arr2; same class/offsets as neighbours.
// Evidence: neighbours 0x005DB9BC/0x005DBBA5 same cl; offset +0x18 int[81]; callers 0x005DC655/0x005DC661.
bool Rva005DB98E::rva005DBA60(unsigned short x)
{
	if (x < 8)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (i != x && m_arr2[i + x * 8] == 2)
				return true;
			if (m_arr2[x + i * 8] == 2)
				return true;
		}
	}
	return false;
}

// ?rva005DBA9C@Rva005DB98E@@QAE_N_N@Z present-unmatched
// ?rva005DBA9C@Rva005DB98E@@QAE_N_N@Z 0x005DBA9C 177B
// Unlock human/slot scan with m_arr2 value 3; same class/offsets as neighbours.
// Evidence: neighbours 0x005DBA60/0x005DBBA5 same cl; offsets +0x14 +0x18 +0x8b8; callee isHuman row; callers 0x005A908A/0x005BA3B9.
bool Rva005DB98E::rva005DBA9C(bool flag)
{
	if (m_cur >= 8)
		return true;
	if (flag)
	{
		for (int bx = 0; bx < 8; ++bx)
		{
			for (int bp = 0; bp < 8; ++bp)
			{
				if (bx == bp)
					continue;
				GameSlot *a = m_slots[bx];
				if (!a)
					continue;
				if (!a->isHuman())
					continue;
				GameSlot *b = m_slots[bp];
				if (!b)
					continue;
				if (!b->isHuman())
					continue;
				if (m_arr2[bp + bx * 8] != 3)
					return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			if (i == m_cur)
				continue;
			GameSlot *s = m_slots[i];
			if (!s)
				continue;
			if (!s->isHuman())
				continue;
			if (m_arr2[m_cur + i * 8] != 3)
				return false;
			if (m_arr2[i + m_cur * 8] != 3)
				return false;
		}
		return true;
	}
}
