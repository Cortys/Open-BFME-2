// ?Create@AptInteger@@SAPAVAptValue@@H@Z
// partial score=0.95 date=2026-10-01
// cl: /O2 /MD /EHsc
#include <new>
// ?Create@AptInteger@@SAPAVAptValue@@H@Z, retail 0x006D8520, 263 bytes.
// AptInteger::Create(int): pooled Apt value (type 7 Integer, vtable 0x008EA4C0).
// Fast path reuses head of free list at g_00E18020, checks vtbl index 7 and
// refcount 0 via rowed getters with AptInteger.inl asserts, sets defined bit
// via rowed apply 0x006DBDB0, pushes to release vector, stores int at +8.
// Slow path allocates 0xC via pinned allocBlock, constructs base with type 7,
// overwrites vtable, stores int. Evidence: callers aptKeyCode/aptKeyValue,
// LINK unblocks 6 files via this callee, donor EA Apt usages of Create.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class AptValue;
class AptValueVector
{
public:
	void rva006E6C00(AptValue *pValue);
};
extern AptValueVector *g_releaseVectorAtE17710;

class Rva006DB270;
extern Rva006DB270 *g_pChainBlockAllocator;
class Rva006DB160
{
public:
	void *allocBlock(int blockSize);
};

class Rva006DBB30SarDwordField
{
public:
	int get() const;
};

class AptValue
{
public:
	unsigned int getRefCount() const;
};

class Rva006DBDB0DwordOrSetter
{
public:
	void apply();
};

class BfmeAptValue006DCD20
{
public:
	virtual void vtableSlot0();
	BfmeAptValue006DCD20(int type);
	unsigned int m_flags;
	int m_intValue;
};

class AptInteger : public BfmeAptValue006DCD20
{
public:
	static AptValue *Create(int value);
};

extern AptInteger *g_00E18020;
extern const void *const g_00CEA4C0[];

// ?Create@AptInteger@@SAPAVAptValue@@H@Z present-unmatched
AptValue *AptInteger::Create(int value)
{
	AptInteger *pNewInt = g_00E18020;
	if (pNewInt != 0)
	{
		g_00E18020 = *(AptInteger **)((char *)pNewInt + 8);
		if (!(((Rva006DBB30SarDwordField *)pNewInt)->get() == 7))
		{
			g_bfmeAptAssertAtE17734("pNewInt->getVtblIndex() == AptVFT_Integer", ".\\AptValue/AptInteger.inl", 0x4B);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
		if (!(((AptValue *)pNewInt)->getRefCount() == 0))
		{
			g_bfmeAptAssertAtE17734("pNewInt->getRefCount() == 0", ".\\AptValue/AptInteger.inl", 0x4D);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
		((Rva006DBDB0DwordOrSetter *)pNewInt)->apply();
		g_releaseVectorAtE17710->rva006E6C00((AptValue *)pNewInt);
		pNewInt->m_intValue = value;
		return (AptValue *)pNewInt;
	}
	pNewInt = (AptInteger *)((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock(0xC);
	if (pNewInt != 0)
	{
		new ((void *)pNewInt) BfmeAptValue006DCD20(7);
		*(const void *const **)pNewInt = g_00CEA4C0;
		pNewInt->m_intValue = value;
		return (AptValue *)pNewInt;
	}
	return 0;
}
