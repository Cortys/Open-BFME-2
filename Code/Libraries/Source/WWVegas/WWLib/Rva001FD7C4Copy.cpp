// cl: /O1 /MD
// ?rva001FD7C4@Rva001FD7C4@@QAEPAURva001FD7C4Node@@PAU2@0@Z @0x001FD7C4 115B.
// Tree copy for map<int,int> nodes: clones the top through the twin of the
// rowed _M_clone_node 0x0053444F, links the parent, recurses right, then
// walks the left spine cloning. Same 115B shape as Rva001FD751Copy precedent.
// Node layout (color +0 parent +4 left +8 right +12 value +10) proven by the
// retail offsets. Landing this unblocks 0x001FDAB0 and 0x001FD952; callers at
// 0x001FD7ED 0x001FD81A (self) and 0x001FD989 0x001FDB0B.
struct Rva001FD7C4Node
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva001FD7C4Node *m_parent;
	Rva001FD7C4Node *m_left;
	Rva001FD7C4Node *m_right;
	unsigned char m_value[8];
};

struct Rva001FD7C4
{
	Rva001FD7C4Node *rva0053444F(Rva001FD7C4Node *x);
	Rva001FD7C4Node *rva001FD7C4(Rva001FD7C4Node *x, Rva001FD7C4Node *p);
};

Rva001FD7C4Node *Rva001FD7C4::rva001FD7C4(Rva001FD7C4Node *x, Rva001FD7C4Node *p)
{
	Rva001FD7C4Node *top = rva0053444F(x);
	top->m_parent = p;
	if (x->m_right != 0)
		top->m_right = rva001FD7C4(x->m_right, top);
	p = top;
	x = x->m_left;
	while (x != 0) {
		Rva001FD7C4Node *y = rva0053444F(x);
		p->m_left = y;
		y->m_parent = p;
		if (x->m_right != 0)
			y->m_right = rva001FD7C4(x->m_right, y);
		p = y;
		x = x->m_left;
	}
	return top;
}
