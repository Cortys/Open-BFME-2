// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z
// partial score=0.97 date=2026-10-01
// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z
// partial score=0.97 date=2026-10-01
// cl: /O1 /MD /Oy-
// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z @0x00238FF3 72B finish lane banked 0.96 frameless vs ebp plus edi esi swap.
// Evidence: leaf loop over m_head+0x14 calling w14 then v31 v06; caller 0x00245E59; string "drawables" at 0x007ED678.

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
	void rva00238FF3(Rva00238FF3Arg *arg);
private:
	char m_pad0[0x14];
	Rva00238FF3Node *m_head;
};

// ?rva00238FF3@Rva00238E1B@@QAEXPAVRva00238FF3Arg@@@Z present-unmatched
void Rva00238E1B::rva00238FF3(Rva00238FF3Arg *arg)
{
	Rva00238FF3Arg *host = arg;
	host->v05("drawables");
	Rva00238FF3Node *p = m_head;
	for (; p != 0; p = p->m_next)
		p->w14(host);
	arg = 0;
	host->v31((void **)&arg);
	host->v06();
}
