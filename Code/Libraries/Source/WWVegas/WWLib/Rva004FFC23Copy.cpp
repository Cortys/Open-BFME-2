// cl: /O1 /MD
// ?rva004FFC23@Rva004FFC23@@QAEPAURva004FFC23Node@@PAU2@0@Z @0x004FFC23 115B.
// Tree copy for map<int void*> nodes: clones the top through the twin of the
// rowed _M_clone_node 0x0053444F, links the parent, recurses right, then
// walks the left spine cloning. Same 115B shape as the rowed 0x002CF6CF
// copy and Rva002CFD96Copy precedent. Node layout (color +0 parent +4
// left +8 right +12) proven by the retail offsets. Callers at 0x004FFC4C
// 0x004FFC79 (self) and 0x004FFF0A in 0x004FFEAF; landing this unblocks
// 0x004FFEAF.
struct Rva004FFC23Node
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva004FFC23Node *m_parent;
	Rva004FFC23Node *m_left;
	Rva004FFC23Node *m_right;
	unsigned char m_value[8];
};

struct Rva004FFC23
{
	Rva004FFC23Node *rva0053444F(Rva004FFC23Node *x);
	Rva004FFC23Node *rva004FFC23(Rva004FFC23Node *x, Rva004FFC23Node *p);
};

Rva004FFC23Node *Rva004FFC23::rva004FFC23(Rva004FFC23Node *x, Rva004FFC23Node *p)
{
	Rva004FFC23Node *top = rva0053444F(x);
	top->m_parent = p;
	if (x->m_right != 0)
		top->m_right = rva004FFC23(x->m_right, top);
	p = top;
	x = x->m_left;
	while (x != 0) {
		Rva004FFC23Node *y = rva0053444F(x);
		p->m_left = y;
		y->m_parent = p;
		if (x->m_right != 0)
			y->m_right = rva004FFC23(x->m_right, y);
		p = y;
		x = x->m_left;
	}
	return top;
}
