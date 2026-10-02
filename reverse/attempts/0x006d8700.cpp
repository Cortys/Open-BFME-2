// ?Rva008A4EA0MakeFloat@@YAPAVAptValue@@M@Z
// partial score=0.95 date=2026-10-01
// cl: /O2 /MD /EHsc
#include <new>
// ?Rva008A4EA0MakeFloat@@YAPAVAptValue@@M@Z, retail 0x006D8700, 263 bytes.
// Pooled Apt Float value (type 6, vtable 0x008EA560). Fast path reuses head
// of free list at g_00E18024, checks vtbl index 6 and refcount 0 via rowed
// getters with AptFloat.inl asserts, sets defined bit via rowed apply
// 0x006DBDB0, pushes to release vector, stores float bits at +8. Slow path
// allocates 0xC via pinned allocBlock, constructs base with type 6,
// overwrites vtable, stores float. Evidence: donor Rva008A4EA0MakeFloat,
// 12 callers in FUN_00ae83f0, LINK via apply callee.
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
	float m_floatValue;
};

class AptFloat : public BfmeAptValue006DCD20
{
public:
	static AptValue *Create(float value);
};

extern AptFloat *g_00E18024;
extern const void *const g_00CEA560[];

// ?Rva008A4EA0MakeFloat@@YAPAVAptValue@@M@Z present-unmatched
AptValue *Rva008A4EA0MakeFloat(float value)
{
	AptFloat *pNewFloat = g_00E18024;
	if (pNewFloat != 0)
	{
		g_00E18024 = *(AptFloat **)((char *)pNewFloat + 8);
		if (!(((Rva006DBB30SarDwordField *)pNewFloat)->get() == 6))
		{
			g_bfmeAptAssertAtE17734("pNewFloat->getVtblIndex() == AptVFT_Float", ".\\AptValue/AptFloat.inl", 0x4B);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
		if (!(((AptValue *)pNewFloat)->getRefCount() == 0))
		{
			g_bfmeAptAssertAtE17734("pNewFloat->getRefCount() == 0", ".\\AptValue/AptFloat.inl", 0x4D);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
		((Rva006DBDB0DwordOrSetter *)pNewFloat)->apply();
		g_releaseVectorAtE17710->rva006E6C00((AptValue *)pNewFloat);
		pNewFloat->m_floatValue = value;
		return (AptValue *)pNewFloat;
	}
	pNewFloat = (AptFloat *)((Rva006DB160 *)g_pChainBlockAllocator)->allocBlock(0xC);
	if (pNewFloat != 0)
	{
		new ((void *)pNewFloat) BfmeAptValue006DCD20(6);
		*(const void *const **)pNewFloat = g_00CEA560;
		pNewFloat->m_floatValue = value;
		return (AptValue *)pNewFloat;
	}
	return 0;
}
