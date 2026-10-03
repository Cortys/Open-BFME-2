// ?rva006F7A30@BfmeWrapper1279@@QAEXXZ
// partial score=0.99 date=2026-10-03
// cl: /O2 /DNDEBUG /MD
//
// Apt display-list / AptCIH neighbourhood cluster at 0x006F6A50.  Class
// layouts come from the recovered BFME2 siblings in this directory
// (Rva006E1DD0Cluster.cpp AptCIH layout, Rva006F8060Assert.cpp head holder)
// and the BFME1 donor tree (AptDisplayList.cpp / AptCIH.cpp).  Identity of the
// node class is AptCIH: the 0x006E24E0/0x006E2560/0x006E2D60 callees assert
// through AptCIH.h.  Names stay address-derived until a caller proves more.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class Rva006DBB30SarDwordField
{
public:
	int get() const;
};

class AptCIH
{
public:
	virtual void v0();
	bool rva006E24E0();
	void rva006E2560(int arg);
	void rva006E2D60();
	void rva006E1C40(void *a, void *b);
	bool rva006CFCD0() const;

	char m_pad04[0x4c - 0x4];
	void *pData;
	AptCIH *m_prev;
	AptCIH *m_next;
	unsigned int m_key;
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
	virtual void v0();
	virtual void v1();
	virtual void v2();
	bool isUndefined() const;
	void setGCRootCount(unsigned int n);
	unsigned int m_flags;
};

class AptValue : public BfmeAptValue006DCD20
{
public:
	void setIsDefined(bool defined);
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

class Rva006D2A60
{
public:
	void *allocBlock(int size);
};

extern Rva006DB270 *g_pChainBlockAllocator;   // VA 0x00E176E8
extern Rva006D2A60 *g_pChainBlockAllocatorF4; // VA 0x00E176F4

// The sentinel/display-list node.  Its out-of-line constructor is the rowed
// ??0Rva006CBDE0@@QAE@HPAXPAVAptValue@@@Z; the fields below are the ones this
// cluster touches (prev +0x50, next +0x54, key/GC word +0x58).
class Rva006CBDE0 : public AptValue
{
public:
	Rva006CBDE0(int type, void *p1, AptValue *p2);

	static void *operator new(unsigned int size)
	{
		return g_pChainBlockAllocatorF4->allocBlock((int)size);
	}

	char m_pad08[0x48 - 0x08];
	AptValue *m_48;
	void *m4C;
	Rva006CBDE0 *m_50;
	Rva006CBDE0 *m_54;
	unsigned int m_58;
	unsigned int m_5c;
};

class BfmeQuery1279
{
public:
	BfmeQuery1279();
	~BfmeQuery1279();

	void bfmeQuery1279(int nDepth, int name, void **ppPrev, void **ppItem);
	void rva006F6FB0(int key, AptCIH *pNewItem);
	AptCIH *rva006F6D60(AptCIH *pOldItem, AptCIH *pNewItem);

	static void *operator new(unsigned int size)
	{
		return ((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock((int)size);
	}

	static void operator delete(void *block, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(block, (int)size);
	}

	Rva006CBDE0 *m_root;
};

// ??0BfmeQuery1279@@QAE@XZ @0x006F7B20 153B: construct the root sentinel from
// the 0xE176F4 pool, mark it undefined with one GC root, clear its key link.
BfmeQuery1279::BfmeQuery1279()
{
	m_root = new Rva006CBDE0(0x2e, (void *)0xbaadf00d, 0);
	m_root->setIsDefined(false);
	m_root->setGCRootCount(1);
	m_root->v0();
	m_root->m_58 |= 0x1ffff;
	m_root->m_54 = 0;
	m_root->m_50 = 0;
}

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
	void rva006F76B0();
	void rva006F79B0(void *arg1, void *arg2);
	void rva006F7A30();

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

// ---------------------------------------------------------------------------
// AptCIH descriptor wrapper at 0x006F6A50: holds a descriptor pointer and builds
// a 0x1C interpretation of it only when the descriptor reports kind 3.

class Rva006F69D0
{
public:
	Rva006F69D0(void *descriptor, int second, int fourth) throw();

	char m_pad[0x1c];

	static void *operator new(unsigned int size)
	{
		return ((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock((int)size);
	}
};

class Rva006F6A50
{
public:
	Rva006F6A50(void *descriptor, int second, int third, int fourth);

	void *m_00;
	Rva006F69D0 *m_04;
	int m_08;
	int m_0c;
	int m_10;
};

// ??0Rva006F6A50@@QAE@PAXHHH@Z @0x006F6A50 101B
Rva006F6A50::Rva006F6A50(void *descriptor, int second, int third, int fourth)
{
	m_00 = descriptor;
	m_10 = third;
	if (descriptor != 0 && *(int *)descriptor == 3)
		m_04 = new Rva006F69D0(descriptor, second, fourth);
	else
		m_04 = 0;
	m_08 = 0;
	m_0c = 0;
}

// ---------------------------------------------------------------------------
// Rva006F8D70 (0x20 bytes) ctor: vtable + a BfmeWrapper1279 sub-object at +0x1C
// and an AptNativeHash at +0x10.  Its deleting dtor (0x006F8D70), complete dtor
// (0x006F8DA0) and the vtable RVA 0x008ED398 already exist in the ledger.

extern const void *const g_00CED398[];

class AptNativeHash
{
public:
	AptNativeHash(int size);

	static void *operator new(unsigned int size)
	{
		return ((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock((int)size);
	}

	char m_pad[0x14];
};

// The base's inlined ctor writes +0x14, +0x04, +0x0C and +0x10; its vtable store
// is dead and dropped, so the derived vtable store below is the only one left.
class Rva006F8D70Base
{
public:
	Rva006F8D70Base()
	{
		m_14 = 0;
		m_04 = -1;
		m_0c = 0;
		m_10 = 0;
	}

	virtual ~Rva006F8D70Base();

	int m_04;
	int m_pad08;
	int m_0c;
	AptNativeHash *m_10;
	unsigned char m_14;
	char m_pad15[3];
};

class Rva006F8D70 : public Rva006F8D70Base
{
public:
	Rva006F8D70();
	virtual ~Rva006F8D70();

	char m_pad18[4];
	BfmeWrapper1279 m_holder;
};

// ??0Rva006F8D70@@QAE@XZ @0x006F8550 134B
Rva006F8D70::Rva006F8D70()
{
	m_10 = new AptNativeHash(4);
}

// ---------------------------------------------------------------------------
// AptDisplayList list-link helper at 0x006F6D60: asserts pNewItem's data then
// splices pNewItem in after pOldItem.  The inline type-14 predicate carries the
// AptCIH.h:0xB5 "this" assertion that the byte stream shows.

static __forceinline int rva006F6D60IsType14(const AptCIH *pNewItem)
{
	if (pNewItem == 0) {
		g_bfmeAptAssertAtE17734("this", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0xB5);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	if (((const Rva006DBB30SarDwordField *)pNewItem)->get() == 0xe) {
		if (!((const BfmeAptValue006DCD20 *)pNewItem)->isUndefined())
			return 1;
	}
	return 0;
}

// ?rva006F6D60@@YGPAVAptCIH@@PAV1@0@Z @0x006F6D60 159B
AptCIH *BfmeQuery1279::rva006F6D60(AptCIH *pOldItem, AptCIH *pNewItem)
{
	if (pNewItem->rva006CFCD0() || rva006F6D60IsType14(pNewItem)) {
		if (pNewItem->pData == 0) {
			g_bfmeAptAssertAtE17734("pNewItem->pData != NULL", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptDisplayList.cpp", 0x1D8);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
	}
	pNewItem->m_next = pOldItem->m_next;
	pNewItem->m_prev = pOldItem;
	pNewItem->v0();
	if (pNewItem->m_next != 0)
		pNewItem->m_next->m_prev = pNewItem;
	pNewItem->m_prev->m_next = pNewItem;
	return pNewItem;
}

// ?rva006F6FB0@BfmeQuery1279@@QAEXHPAVAptCIH@@@Z @0x006F6FB0 122B: query the
// key, assert the found old item is undefined, splice the new item after the
// query's previous node and set its 17-bit key.
void BfmeQuery1279::rva006F6FB0(int key, AptCIH *pNewItem)
{
	AptCIH *pOldItem;
	void *pPrev;
	bfmeQuery1279(key, 0, &pPrev, (void **)&pOldItem);
	if (pOldItem != 0 && !((const BfmeAptValue006DCD20 *)pOldItem)->isUndefined()) {
		g_bfmeAptAssertAtE17734("pOldItem == NULL || pOldItem->isUndefined()", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptDisplayList.cpp", 0x208);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	AptCIH *node = rva006F6D60((AptCIH *)pPrev, pNewItem);
	node->m_key = node->m_key ^ ((node->m_key ^ (unsigned int)key) & 0x1FFFFu);
}

// ---------------------------------------------------------------------------
// BfmeWrapper1279 child-list walks at 0x006F79B0 and 0x006F7A30.  Both start at
// m_query->m_root->next and dispatch on the node's kind.  The kind-19 inline
// predicate carries the AptCIH.h:0xD8 "this" assertion; kind-14 reuses the
// 0x006F6D60 helper above.

static __forceinline int rva006F79B0IsType19(const AptCIH *pNode)
{
	if (pNode == 0) {
		g_bfmeAptAssertAtE17734("this", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0xD8);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	if (((const Rva006DBB30SarDwordField *)pNode)->get() == 0x13) {
		if (!((const BfmeAptValue006DCD20 *)pNode)->isUndefined())
			return 1;
	}
	return 0;
}

// ?rva006F79B0@BfmeWrapper1279@@QAEXPAX0@Z @0x006F79B0 126B
void BfmeWrapper1279::rva006F79B0(void *arg1, void *arg2)
{
	AptCIH *node = (AptCIH *)m_query->m_root->m_54;
	while (node != 0) {
		if (!((const BfmeAptValue006DCD20 *)node)->isUndefined()) {
			if (!rva006F79B0IsType19(node)) {
				if (*(int *)((char *)node->pData + 4) < 0)
					node->rva006E1C40(arg1, arg2);
			}
		}
		node = node->m_next;
	}
}

// ?rva006F7A30@BfmeWrapper1279@@QAEXXZ @0x006F7A30 127B
void BfmeWrapper1279::rva006F7A30()
{
	AptCIH *node = (AptCIH *)m_query->m_root->m_54;
	for (;;) {
		if (node == 0)
			break;
		if (!((const BfmeAptValue006DCD20 *)node)->isUndefined() &&
			(((const Rva006DBB30SarDwordField *)node)->get() == 0xd ||
			 ((const Rva006DBB30SarDwordField *)node)->get() == 0x12)) {
			node->rva006E2D60();
		} else if (rva006F6D60IsType14(node)) {
			node->rva006E2D60();
		}
		node = node->m_next;
	}
}
