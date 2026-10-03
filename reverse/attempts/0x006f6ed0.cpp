// ?rva006F6ED0@BfmeQuery1279@@QAEXHHPAX@Z
// partial score=0.7 date=2026-10-03
// cl: /O2 /DNDEBUG /MD
//
// ?rva006F6ED0@BfmeQuery1279@@QAEXHHPAX@Z, retail 0x006F6ED0 (221 bytes).
//
// BfmeQuery1279 insert-with-node: allocate a 0x60-byte Rva006CBDE0 display-list
// node from the 0xE176F4 chain allocator, construct it from the (type, pData)
// arguments, query the tree for the key through the rowed bfmeQuery1279, assert
// the located item is null or undefined (AptDisplayList.cpp:0x1FB), fold the
// 17-bit key into the node, store pData at +0x4C and splice the node after the
// query's previous item through the rowed 0x006F6D60 link helper.  Model and
// recipe follow the recovered sibling Rva006F6A50Cluster.cpp (rva006F6FB0).

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

class Rva006D2A60
{
public:
	void *allocBlock(int size);
};

extern Rva006DB270 *g_pChainBlockAllocator;   // VA 0x00E176E8
extern Rva006D2A60 *g_pChainBlockAllocatorF4; // VA 0x00E176F4

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
	void *m_4c;
	void *m_50;
	void *m_54;
	unsigned int m_58;
	unsigned int m_5c;
};

class AptCIH;

class BfmeQuery1279
{
public:
	void bfmeQuery1279(int nDepth, int name, void **ppPrev, void **ppItem);
	AptCIH *rva006F6D60(AptCIH *pOldItem, AptCIH *pNewItem);
	void rva006F6ED0(int key, int type, void *pData);

	Rva006CBDE0 *m_root;
};

// ?rva006F6ED0@BfmeQuery1279@@QAEXHHPAX@Z
void BfmeQuery1279::rva006F6ED0(int key, int type, void *pData)
{
	AptCIH *pOldItem;
	void *pPrev;
	Rva006CBDE0 *node = new Rva006CBDE0(type, pData, 0);

	bfmeQuery1279(key, 0, &pPrev, (void **)&pOldItem);
	if (pOldItem != 0 && !((const BfmeAptValue006DCD20 *)pOldItem)->isUndefined()) {
		g_bfmeAptAssertAtE17734("pItem == NULL || pItem->isUndefined()", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptDisplayList.cpp", 0x1FB);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	node->m_58 = node->m_58 ^ ((node->m_58 ^ (unsigned int)key) & 0x1FFFFu);
	node->m_4c = pData;
	rva006F6D60((AptCIH *)pPrev, (AptCIH *)node);
}
