// cl: /O1 /MD /G7
// ?rva00531E14@Rva00531E14@@QAEEG@Z @ 0x00531E14 (71B): __thiscall table-walk predicate over two word chains.
// Words at +2/+4 start each chain, +6 limit, +8 word table; returns 0 when val hits either chain else 1.
// Caller at 0x00534397. Owner unknown so honest address name. /G7 drops the redundant movzx.
// ?rva00531D52@Rva00531E14@@QAEGXZ @ 0x00531D52 (75B): same class pop/alloc helper; callers at 0x00532AFB 0x00533C4B.
class Rva00531E14
{
public:
	unsigned char rva00531E14(unsigned short val);
	unsigned short rva00531D52();
	unsigned short m_pad0;
	unsigned short m_start1;
	unsigned short m_start2;
	unsigned short m_end;
	unsigned short *m_table;
};
unsigned char Rva00531E14::rva00531E14(unsigned short val)
{
	unsigned short cur = m_start1;
	while (cur < m_end)
	{
		if (cur == val)
			return 0;
		cur = m_table[cur];
	}
	cur = m_start2;
	while (cur < m_end)
	{
		if (cur == val)
			return 0;
		cur = m_table[cur];
	}
	return 1;
}
unsigned short Rva00531E14::rva00531D52()
{
	unsigned short cur = m_start1;
	if (cur < m_end)
	{
		unsigned short *p = &m_table[cur];
		unsigned short nxt = *p;
		m_start1 = nxt;
		*p = 1;
		return cur;
	}
	if (m_end >= m_pad0)
		return (unsigned short)(m_pad0 - 1);
	m_table[m_end] = 1;
	unsigned short old = m_start1;
	++m_end;
	m_start1 = (unsigned short)(old + 1);
	return old;
}
