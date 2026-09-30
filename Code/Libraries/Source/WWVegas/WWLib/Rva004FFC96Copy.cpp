// cl: /O1 /MD
// ?rva004FFC96@Rva004FFC96@@QAEPAURva004FFC96Node@@PAU2@0@Z @0x004FFC96 115B.
// Tree copy for map<int void*> nodes: clones the top through the twin of the
// rowed _M_clone_node 0x0053444F, links the parent, recurses right, then
// walks the left spine cloning. Same 115B shape as the rowed 0x002CF6CF
// copy and Rva004FFC23Copy precedent. Node layout (color +0 parent +4
// left +8 right +12) proven by the retail offsets. Callers at 0x004FFCBF
// 0x004FFCEC (self) and 0x004FFFAF in 0x004FFF54; landing this unblocks
// 0x004FFF54.
struct Rva004FFC96Node
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva004FFC96Node *m_parent;
	Rva004FFC96Node *m_left;
	Rva004FFC96Node *m_right;
	unsigned char m_value[8];
};

struct Rva004FFC96
{
	Rva004FFC96Node *rva0053444F(Rva004FFC96Node *x);
	Rva004FFC96Node *rva004FFC96(Rva004FFC96Node *x, Rva004FFC96Node *p);
};

Rva004FFC96Node *Rva004FFC96::rva004FFC96(Rva004FFC96Node *x, Rva004FFC96Node *p)
{
	Rva004FFC96Node *top = rva0053444F(x);
	top->m_parent = p;
	if (x->m_right != 0)
		top->m_right = rva004FFC96(x->m_right, top);
	p = top;
	x = x->m_left;
	while (x != 0) {
		Rva004FFC96Node *y = rva0053444F(x);
		p->m_left = y;
		y->m_parent = p;
		if (x->m_right != 0)
			y->m_right = rva004FFC96(x->m_right, y);
		p = y;
		x = x->m_left;
	}
	return top;
}
