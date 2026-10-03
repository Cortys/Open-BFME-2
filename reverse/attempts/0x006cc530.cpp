// ?Rva006CC530Get@@YAPAXH@Z
// partial score=0.89 date=2026-10-03
// cl: /O2 /MD /EHsc
// ?Rva006CC530Get@@YAPAXH@Z @0x006CC530 192B Apt display-list find-or-create type-19 node.
// Retail searches [[g_bfmeAptPtr+0x30]] list via +0x54 with 17-bit key at +0x58
// (shl 15 sar 15) for the int key; on hit returns node, else allocs 0x60 via
// 0x00E176F4 pool, constructs Rva006CBDE0(0x13,0,0), marks one GC root and
// inserts via BfmeQuery1279::rva006F6FB0 with reloaded query. Evidence: unlock
// lane; callees rowed (ctor 0x006CBDE0 setGCRoot 0x006DBC70 rva006F6FB0
// 0x006F6FB0) plus pin allocBlock 0x006D29E0; callers 0x006CCA50 0x006CCAF0.
class AptCIH;
class AptValue
{
public:
	virtual void AddRef();
	virtual void Release();
};
class BfmeAptValue006DCD20
{
	virtual void vtableSlot0();
public:
	void setGCRootCount(unsigned int n);
	unsigned int m_flags;
};
class EAStringC
{
public:
	EAStringC() { clear(); }
	EAStringC &clear();
	~EAStringC();
};
class Rva006D2A60
{
public:
	void *allocBlock(int size);
};
extern Rva006D2A60 *g_00E176F4;
class Rva006CBDE0 : public BfmeAptValue006DCD20
{
public:
	EAStringC m_str;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	int m_28;
	int m_2c;
	int m_30;
	int m_34;
	int m_38;
	int m_3c;
	int m_40;
	int m_44;
	AptValue *m_48;
	void *m_4c;
	Rva006CBDE0 *m_50;
	Rva006CBDE0 *m_54;
	unsigned int m_58;
	unsigned int m_5c;
public:
	Rva006CBDE0(int type, void *p1, AptValue *p2);
	static void *operator new(unsigned int size);
	static void operator delete(void *p);
};
class BfmeQuery1279
{
public:
	Rva006CBDE0 *m_root;
	void rva006F6FB0(int key, AptCIH *pNewItem);
};
class Rva006E34D0
{
public:
	unsigned char m_pad[0x30];
	BfmeQuery1279 *m_30;
};
extern Rva006E34D0 *g_bfmeAptPtrAtE176D0;
void *Rva006CBDE0::operator new(unsigned int size)
{
	return g_00E176F4->allocBlock((int)size);
}
void Rva006CBDE0::operator delete(void *p)
{
	(void)p;
}
// ?Rva006CC530Get@@YAPAXH@Z present-unmatched
void *Rva006CC530Get(int key)
{
	Rva006E34D0 *apt = g_bfmeAptPtrAtE176D0;
	BfmeQuery1279 *query = apt != 0 ? apt->m_30 : 0;
	if (query == 0)
		return 0;
	Rva006CBDE0 *cur = query->m_root;
	if (cur != 0) {
		do {
			if ((((int)(cur->m_58 << 15)) >> 15) == key)
				return cur;
			cur = cur->m_54;
		} while (cur != 0);
	}
	Rva006CBDE0 *p = new Rva006CBDE0(0x13, 0, 0);
	p->setGCRootCount(1);
	g_bfmeAptPtrAtE176D0->m_30->rva006F6FB0(key, (AptCIH *)p);
	return p;
}
