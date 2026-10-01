// ?rva001DBDC6@Rva001DBDA4@@QAEXXZ
// partial score=0.75 date=2026-10-01
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
	virtual void v00();
	virtual void v04();
	virtual void v08();
	virtual void v0C(); // +0x0C
	virtual void v10(); // +0x10
	virtual void v14(); // +0x14
	virtual void v18(); // +0x18
	int m_val; // +0x04
	bool m_flag; // +0x08
};

class Rva00489360
{
public:
	bool rva001DBAF6() const;
	void rva001DBB04(int value);
	void rva001DBB15();
	void rva001DBB24();
	void rva001DBB33();
	int get() const;

	char            m_pad00[ 0x4 ];
	int             m_baseVal;
	char            m_pad08[ 0x8 ];
	Inner00489360 * m_inner;
};

bool Rva00489360::rva001DBAF6() const
{
	if( m_inner )
		return m_inner->m_flag;
	return true;
}

void Rva00489360::rva001DBB04(int)
{
	if( m_inner )
		m_inner->v0C();
}

void Rva00489360::rva001DBB15()
{
	if( m_inner )
		m_inner->v14();
}

void Rva00489360::rva001DBB24()
{
	if( m_inner )
		m_inner->v18();
}

void Rva00489360::rva001DBB33()
{
	if( m_inner )
		m_inner->v10();
}

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
	bool rva001DBD83() const;
	int rva001DBDA4() const;
	void rva001DBDC6();
	void rva001DBE17();
	void rva001DBE34();
	void rva001DBE51();

	Node001DBDA4 *m_head;
	int m_04;
	int m_08;
};

bool Rva001DBDA4::rva001DBD83() const
{
	for( Node001DBDA4 *n = m_head->m_next; n != m_head; n = n->m_next )
	{
		if( !n->m_value->rva001DBAF6() )
			return false;
	}
	return true;
}

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

void Rva001DBDA4::rva001DBDC6()
{
	int best = 0;
	m_04 = -1;
	Node001DBDA4 *head = m_head;
	Node001DBDA4 *first = head->m_next;
	for( Node001DBDA4 *n = first; n != m_head; n = n->m_next )
	{
		int v = n->m_value->get();
		if( v > best )
			best = v;
	}
	for( Node001DBDA4 *m = first; m != head && m != m_head; m = m->m_next )
		m->m_value->rva001DBB04( best );
	m_08 = best;
}

void Rva001DBDA4::rva001DBE17()
{
	for( Node001DBDA4 *n = m_head->m_next; n != m_head; n = n->m_next )
		n->m_value->rva001DBB15();
}

void Rva001DBDA4::rva001DBE34()
{
	for( Node001DBDA4 *n = m_head->m_next; n != m_head; n = n->m_next )
		n->m_value->rva001DBB24();
}

void Rva001DBDA4::rva001DBE51()
{
	for( Node001DBDA4 *n = m_head->m_next; n != m_head; n = n->m_next )
		n->m_value->rva001DBB33();
}
