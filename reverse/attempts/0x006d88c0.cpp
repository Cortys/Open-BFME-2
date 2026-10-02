// ?Rva006D88C0MakeBool@@YAPAVAptValue@@_N@Z
// partial score=0.95 date=2026-10-01
// cl: /O2 /MD /EHsc
#include <new>
// ?Rva006D88C0MakeBool@@YAPAVAptValue@@_N@Z, retail 0x006D88C0, 263 bytes.
// Pooled Apt Boolean value (type 5, vtable 0x008EA600). Fast path reuses head
// of free list at g_00E18028, checks vtbl index 5 and refcount 0 via rowed
// getters with AptBoolean.inl asserts, sets defined bit via rowed apply
// 0x006DBDB0, pushes to release vector, stores bool at +8. Slow path
// allocates 0xC via pinned allocBlock, constructs base with type 5,
// overwrites vtable, stores bool. Evidence: 12 callers incl FUN_00ae8a90,
// LINK unblocks 10 functions, sibling Integer/Float same shape.
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
	bool m_boolValue;
};

class AptBool : public BfmeAptValue006DCD20
{
public:
	static AptValue *Create(bool value);
};

extern AptBool *g_00E18028;
extern const void *const g_00CEA600[];

// ?Rva006D88C0MakeBool@@YAPAVAptValue@@_N@Z present-unmatched
AptValue *Rva006D88C0MakeBool(bool value)
{
	AptBool *pNewBool = g_00E18028;
	if (pNewBool != 0)
	{
		g_00E18028 = *(AptBool **)((char *)pNewBool + 8);
		if (!(((Rva006DBB30SarDwordField *)pNewBool)->get() == 5))
		{
			g_bfmeAptAssertAtE17734("pNewBool->getVtblIndex() == AptVFT_Boolean", ".\\AptValue/AptBoolean.inl", 0x4B);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
		if (!(((AptValue *)pNewBool)->getRefCount() == 0))
		{
			g_bfmeAptAssertAtE17734("pNewBool->getRefCount() == 0", ".\\AptValue/AptBoolean.inl", 0x4D);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
		((Rva006DBDB0DwordOrSetter *)pNewBool)->apply();
		g_releaseVectorAtE17710->rva006E6C00((AptValue *)pNewBool);
		pNewBool->m_boolValue = value;
		return (AptValue *)pNewBool;
	}
	pNewBool = (AptBool *)((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock(0xC);
	if (pNewBool != 0)
	{
		new ((void *)pNewBool) BfmeAptValue006DCD20(5);
		*(const void *const **)pNewBool = g_00CEA600;
		pNewBool->m_boolValue = value;
		return (AptValue *)pNewBool;
	}
	return 0;
}
