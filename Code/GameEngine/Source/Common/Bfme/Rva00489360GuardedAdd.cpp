// cl: /O1 /arch:SSE
// 18-byte guarded offset addition getter
//
// ?rva001DBDA4@Rva001DBDA4@@QBEHXZ @0x001DBDA4 34B: the largest get() (floor
// 0) over the list whose sentinel node the owner holds at +0x00 (next at
// +0x00, value pointer at +0x08); callers 0x001DC18B and 0x001DC22D. Retail
// keeps the node in edx across the get() call, which cl only does when get()
// was compiled earlier in the same TU, so it joins this file; its cmovg and
// jump-to-test loop need /O1 /arch:SSE, which leave get() unchanged.

class Inner00489360
{
public:
	int m_pad0;
	int m_val;
};

class Rva00489360
{
public:
	int get() const;

	char            m_pad00[ 0x4 ];
	int             m_baseVal;
	char            m_pad08[ 0x8 ];
	Inner00489360 * m_inner;
};

int Rva00489360::get() const
{
	if( m_inner )
		return m_inner->m_val + m_baseVal;
	return m_baseVal;
}

struct Node001DBDA4
{
	Node001DBDA4 *m_next;
	Node001DBDA4 *m_prev;
	Rva00489360 *m_value;
};

class Rva001DBDA4
{
public:
	int rva001DBDA4() const;

	Node001DBDA4 *m_head;
};

int Rva001DBDA4::rva001DBDA4() const
{
	int best = 0;
	for( Node001DBDA4 *n = m_head->m_next; n != m_head; n = n->m_next )
	{
		int v = n->m_value->get();
		if( v > best )
			best = v;
	}
	return best;
}
