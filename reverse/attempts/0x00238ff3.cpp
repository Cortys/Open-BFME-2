// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z
// partial score=0.96 date=2026-09-29
// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /MD
// ?rva00238E1B@Rva00238E1B@@QAEHXZ @0x00238E1B 10B post-inc counter at +0x2C returns old value.
// Evidence: unlock lane leaf increment; callers 0x00280176 0x00283642; lea shape not inc.
// ?rva00238E25@Rva00238E1B@@QAEX PAV Rva002714E6 chain: inc +0x2C then registry via 0x00271058 then list push via 0x002714E6.

class Rva00271058
{
public:
	void rva00271058(void *p);
};

class Rva002714E6
{
public:
	void rva002714E6(Rva002714E6 **head);
};

class Rva00238FF3Arg
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05(const char *s);
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
	virtual void v29();
	virtual void v30();
	virtual void v31(void **pp);
};

class Rva00238FF3Node
{
public:
	virtual void w00();
	virtual void w01();
	virtual void w02();
	virtual void w03();
	virtual void w04();
	virtual void w05();
	virtual void w06();
	virtual void w07();
	virtual void w08();
	virtual void w09();
	virtual void w10();
	virtual void w11();
	virtual void w12();
	virtual void w13();
	virtual void w14(Rva00238FF3Arg *a);
private:
	char m_pad[0x100];
public:
	Rva00238FF3Node *m_next;
};

class Rva00238E1B
{
public:
	int rva00238E1B();
	void rva00238E25(Rva002714E6 *node);
	void rva00238FF3(Rva00238FF3Arg *arg);
private:
	int m_pad[5];
	Rva002714E6 *m_head;
	int m_pad2[5];
	int m_counter;
};
int Rva00238E1B::rva00238E1B()
{
	int t = m_counter;
	m_counter = t + 1;
	return t;
}

void Rva00238E1B::rva00238E25(Rva002714E6 *node)
{
	int old = m_counter;
	m_counter = old + 1;
	((Rva00271058 *)node)->rva00271058((void *)old);
	node->rva002714E6(&m_head);
}

// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z present-unmatched
void Rva00238E1B::rva00238FF3(Rva00238FF3Arg *arg)
{
	arg->v05("drawables");
	Rva00238FF3Arg *host = arg;
	Rva00238FF3Node *p = (Rva00238FF3Node *)m_head;
	for (; p != 0; p = p->m_next)
		p->w14(host);
	arg = 0;
	host->v31((void **)&arg);
	host->v06();
}
