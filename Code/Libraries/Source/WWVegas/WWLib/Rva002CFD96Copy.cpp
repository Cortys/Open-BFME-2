// cl: /O1 /MD
// ?rva002CFD96@Rva002CFD96@@QAEPAURva002CFD96Node@@PAU2@0@Z @0x002CFD96 115B.
// Tree copy for map<int,int> nodes: clones the top through the twin of the
// rowed _M_clone_node 0x0053444F, links the parent, recurses right, then
// walks the left spine cloning. Same 115B shape as the rowed 0x002CFCEE
// copy. Node layout (color +0 parent +4 left +8 right +12 value +10) proven
// by the retail offsets. Caller at 0x002D0253 unblocks 0x002D021C.
struct Rva002CFD96Node
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva002CFD96Node *m_parent;
	Rva002CFD96Node *m_left;
	Rva002CFD96Node *m_right;
	unsigned char m_value[8];
};

struct Rva002CFD96
{
	Rva002CFD96Node *rva0053444F(Rva002CFD96Node *x);
	Rva002CFD96Node *rva002CFD96(Rva002CFD96Node *x, Rva002CFD96Node *p);
};

// ?rva0053444F@Rva002CFD96@@QAEPAURva002CFD96Node@@PAU2@@Z present-unmatched
Rva002CFD96Node *Rva002CFD96::rva002CFD96(Rva002CFD96Node *x, Rva002CFD96Node *p)
{
	Rva002CFD96Node *top = rva0053444F(x);
	top->m_parent = p;
	if (x->m_right != 0)
		top->m_right = rva002CFD96(x->m_right, top);
	p = top;
	x = x->m_left;
	while (x != 0) {
		Rva002CFD96Node *y = rva0053444F(x);
		p->m_left = y;
		y->m_parent = p;
		if (x->m_right != 0)
			y->m_right = rva002CFD96(x->m_right, y);
		p = y;
		x = x->m_left;
	}
	return top;
}
