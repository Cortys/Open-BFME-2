// ?rva005AD964@Rva005AD964@@QAE_NXZ
// partial score=0.95 date=2026-09-27
// ?rva005AD964@Rva005AD964@@QAE_NXZ
// partial score=0.95 date=2026-09-27
// cl: /O1 /MD
class AsciiString
{
	void *m_data;
};

class GameSlot
{
public:
	char m_pad0[0x10];
	int m_startPos;
};

struct Rva00506C82Arg
{
	char m_pad[0x50];
	int m_50;
};

class GameSlot;
GameSlot *__cdecl Rva00506C82Find(const Rva00506C82Arg *arg);

struct Rva005AD964Holder
{
	char m_pad[0x864];
	int *m_864;
	int *m_868;
};

extern Rva005AD964Holder *g_Rva00DFEEF8;

class Rva005AD964
{
public:
	bool rva005AD964();
private:
	char m_00[0x14];
	const Rva00506C82Arg *m_14;
};

bool Rva005AD964::rva005AD964()
{
	GameSlot *slot = Rva00506C82Find(m_14);
	if (slot == 0)
		return true;
	int key = slot->m_startPos;
	Rva005AD964Holder *h = g_Rva00DFEEF8;
	int *end = h->m_868;
	++key;
	int *begin = h->m_864;
	for (int *p = begin; p != end; ++p) {
		if (*p == key)
			return false;
	}
	return true;
}
