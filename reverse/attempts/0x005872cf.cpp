// ?rva005872CF@Rva0058729D@@QAEXABUICoord2DBase@@@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /MD
//
// ?rva0058729D@Rva0058729D@@QAE_NABUICoord2DBase@@@Z, retail 0x0058729D 50B.
// Linear search: count at +0x10, inline ICoord2D array at +0x14 (8B each).
// For i in 0..count-1 if arr[i]==needle (rowed ??8ICoord2D 0x00004CAD)
// return true else false. Caller 0x00588553.
struct ICoord2DBase
{
	int x;
	int y;
};

struct ICoord2D : public ICoord2DBase
{
	bool operator==(const ICoord2DBase &that) const;
	ICoord2D &operator=(const ICoord2DBase &that);
};

struct Block24 { int w[6]; };

class Rva0058729D
{
public:
	bool rva0058729D(const ICoord2DBase &needle);
	void rva005872CF(const ICoord2DBase &p);
private:
	char _pad00[0x10];
	int m_count; // +0x10
	ICoord2D m_arr[4]; // +0x14 inline, cap 4
};

bool Rva0058729D::rva0058729D(const ICoord2DBase &needle)
{
	int n = m_count;
	for (int i = 0; i < n; ++i)
	{
		if (m_arr[i] == needle)
			return true;
	}
	return false;
}

void Rva0058729D::rva005872CF(const ICoord2DBase &p)
{
	if (m_count == 4)
	{
		Block24 *s = (Block24 *)(m_arr + 1);
		Block24 *d = (Block24 *)m_arr;
		*d = *s;
	}
	else
	{
		++m_count;
	}
	int n = m_count;
	const ICoord2DBase *q = &p;
	m_arr[n - 1].x = q->x;
	m_arr[n - 1].y = q->y;
}
