// cl: /O1 /MD
// ?rva001FD751@Rva001FD751@@QAEPAURva001FD751Node@@PAU2@0@Z @0x001FD751 115B.
// Tree copy for map<int,int> nodes: clones the top through the twin of the
// rowed _M_clone_node 0x0053444F, links the parent, recurses right, then
// walks the left spine cloning. Same 115B shape as the rowed 0x002CFCEE
// copy and Rva002CFD96Copy precedent. Node layout (color +0 parent +4
// left +8 right +12 value +10) proven by the retail offsets.
// Landing this unblocks 0x001FDA0B and 0x001FD8DF; callers at 0x001FD77A
// 0x001FD7A7 (self) and 0x001FD916 0x001FDA66.
struct Rva001FD751Node
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva001FD751Node *m_parent;
	Rva001FD751Node *m_left;
	Rva001FD751Node *m_right;
	unsigned char m_value[8];
};

struct Rva001FD751
{
	Rva001FD751Node *rva0053444F(Rva001FD751Node *x);
	Rva001FD751Node *rva001FD751(Rva001FD751Node *x, Rva001FD751Node *p);
};

Rva001FD751Node *Rva001FD751::rva001FD751(Rva001FD751Node *x, Rva001FD751Node *p)
{
	Rva001FD751Node *top = rva0053444F(x);
	top->m_parent = p;
	if (x->m_right != 0)
		top->m_right = rva001FD751(x->m_right, top);
	p = top;
	x = x->m_left;
	while (x != 0) {
		Rva001FD751Node *y = rva0053444F(x);
		p->m_left = y;
		y->m_parent = p;
		if (x->m_right != 0)
			y->m_right = rva001FD751(x->m_right, y);
		p = y;
		x = x->m_left;
	}
	return top;
}
