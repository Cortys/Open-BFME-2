// cl: /O2 /DNDEBUG /MD
//
// Apt display-list / AptCIH neighbourhood cluster at 0x006F6A50.  Class
// layouts come from the recovered BFME2 siblings in this directory
// (Rva006E1DD0Cluster.cpp AptCIH layout, Rva006F8060Assert.cpp head holder)
// and the BFME1 donor tree (AptDisplayList.cpp / AptCIH.cpp).  Identity of the
// node class is AptCIH: the 0x006E24E0/0x006E2560/0x006E2D60 callees assert
// through AptCIH.h.  Names stay address-derived until a caller proves more.

class AptCIH
{
public:
	bool rva006E24E0();
	void rva006E2560(int arg);
	void rva006E2D60();

	char m_pad00[0x54];
	AptCIH *m_next;
};

// ?rva006F7AC0@Rva006F7AC0List@@QAE_NXZ @0x006F7AC0 33B
class Rva006F7AC0List
{
public:
	bool rva006F7AC0();
	void rva006F7AF0(int arg);

	AptCIH *m_head;
};

bool Rva006F7AC0List::rva006F7AC0()
{
	AptCIH *node = m_head;
	if (node == 0)
		return false;
	do
	{
		if (node->rva006E24E0())
			return true;
		node = node->m_next;
	} while (node != 0);
	return false;
}

// ?rva006F7AF0@Rva006F7AC0List@@QAEXH@Z @0x006F7AF0 36B
void Rva006F7AC0List::rva006F7AF0(int arg)
{
	AptCIH *node = m_head;
	if (node == 0)
		return;
	do
	{
		node->rva006E2560(arg);
		node = node->m_next;
	} while (node != 0);
}

// ---------------------------------------------------------------------------
// AptDisplayList.cpp bodies: BfmeQuery1279 root holder and the BfmeWrapper1279
// owner that allocates it.  The BFME1 donor names both classes.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class BfmeAptValue006DCD20
{
public:
	bool isUndefined() const;
};

class Rva006DB270
{
public:
	void freeBlock(void *block, int size);
};

class Rva006DB160
{
public:
	void *allocBlock(int size);
};

extern Rva006DB270 *g_pChainBlockAllocator; // VA 0x00E176E8

class BfmeNestedBE
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	int m_pad04[(0x4C / 4) - 1];
	int m4C;
};

class BfmeQuery1279
{
public:
	BfmeQuery1279();
	~BfmeQuery1279();

	static void *operator new(unsigned int size)
	{
		return ((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock((int)size);
	}

	static void operator delete(void *block, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(block, (int)size);
	}

	BfmeNestedBE *m_root;
};

// ?BfmeQuery1279::~BfmeQuery1279 @0x006F7BC0 65B: assert the root sentinel is
// undefined, clear its +0x4C then tail-call its second virtual.
BfmeQuery1279::~BfmeQuery1279()
{
	if (!((const BfmeAptValue006DCD20 *)m_root)->isUndefined()) {
		g_bfmeAptAssertAtE17734("pHead->isUndefined()", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptDisplayList.cpp", 0x8A4);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	m_root->m4C = 0;
	m_root->v2();
}

class BfmeWrapper1279
{
public:
	BfmeWrapper1279();
	~BfmeWrapper1279();
	void rva006F80C0(bool flag);
	void rva006F8190();

	BfmeQuery1279 *m_query;
};

// ??0BfmeWrapper1279@@QAE@XZ @0x006F7FF0 103B: allocate the 4-byte BfmeQuery1279
// through the pool and construct it; the EH frame is the throwing new.
BfmeWrapper1279::BfmeWrapper1279() : m_query(new BfmeQuery1279())
{
}

// ??1BfmeWrapper1279@@QAE@XZ @0x006F84F0 93B
BfmeWrapper1279::~BfmeWrapper1279()
{
	rva006F80C0(false);
	delete m_query;
}

// ?rva006F8190@BfmeWrapper1279@@QAEXXZ @0x006F8190 142B
void BfmeWrapper1279::rva006F8190()
{
	if (m_query == 0) {
		g_bfmeAptAssertAtE17734("pState", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptDisplayList.cpp", 0x602);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	rva006F80C0(false);
	delete m_query;
	m_query = 0;
}
