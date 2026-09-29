// ?rva00531132@Rva00531132@@QAEX_NH@Z
// partial score=0.97 date=2026-09-29
// ?rva00531132@Rva00531132@@QAEX_NH@Z
// partial score=0.97 date=2026-09-29
// cl: /O1 /MD
class Rva00531132
{
public:
	void rva00531132(bool add, int value);
	int m_count;
	int m_items[12];
};
void Rva00531132::rva00531132(bool add, int value)
{
	if (value == 0)
		return;
	int count = m_count;
	int index = 0;
	if (count > 0)
	{
		int *p = m_items;
		do
		{
			if (*p == value)
				break;
			++index;
			++p;
		} while (index < m_count);
	}
	if (add)
	{
		if (index < count)
			return;
		if (count >= 12)
			return;
		m_items[count] = value;
		++m_count;
	}
	else
	{
		if (index >= count)
			return;
		int last = count - 1;
		m_count = last;
		m_items[index] = m_items[last];
	}
}
