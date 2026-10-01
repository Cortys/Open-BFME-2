// ?rva005DBBC1@Rva005DBBC1@@QAE_NGG@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /G7 /DNDEBUG /MD
// ?rva005DBBC1@Rva005DBBC1@@QAE_NGG@Z 0x005DBBC1 109B
// Bounds-checked ally/human check: slots at +0x8b8 via GameSlot::isHuman, 8x8 rel at +0x18 == 3.
// Evidence: callers 0x005A6CFD 0x005A6F4A 0x005A7032 0x005A70B7; callee 0x003FF0F1 GameSlot::isHuman rowed.
class GameSlot
{
public:
	bool isHuman() const;
};

class Rva005DBBC1
{
	char m_pad0[0x18];
	int m_rel[64];
	char m_pad1[0x8b8 - 0x18 - 64 * 4];
	GameSlot **m_slots;
public:
	bool rva005DBBC1(unsigned short a, unsigned short b);
};

// ?rva005DBBC1@Rva005DBBC1@@QAE_NGG@Z present-unmatched
bool Rva005DBBC1::rva005DBBC1(unsigned short a, unsigned short b)
{
	if (a >= 8)
		return false;
	if (b >= 8)
		return false;
	if (a == b)
		return false;
	GameSlot *s1 = m_slots[a];
	if (s1 != 0 && s1->isHuman())
	{
		GameSlot *s2 = m_slots[b];
		if (s2 != 0 && s2->isHuman())
		{
			if (m_rel[b + a * 8] != 3)
				return false;
		}
	}
	return true;
}
