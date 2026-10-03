// cl: /O2 /MD
// Apt array helpers from the retail ABI at 0x006D94A0..0x006DA557. Layout
// (m_data +0x20, mnCapacity +0x24, mnLength +0x28) and the array-value role
// follow the rowed helpers in AptValueArrayAt.cpp and Rva006D94A0Cluster.cpp;
// the assert string and file spelling are read from each body's own operands.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;

extern "C" void *__cdecl memmove(void *, const void *, unsigned int);

class BfmeAptValue006DCD20;

class AptBasePtrStack
{
public:
	BfmeAptValue006DCD20 *At(int nPos);

	int m_nElements;
	int m_nCapacity;
	BfmeAptValue006DCD20 **m_aElements;
};

// The interpreter value stack at VA 0x00E182E0. The matched bodies use it only
// through AptBasePtrStack::At, so the object name is TU-local.
extern AptBasePtrStack g_aptValueStackAtE182E0;

class AptInteger
{
public:
	static BfmeAptValue006DCD20 *Create(int value);
};

class BfmeAptValue006DCD20
{
public:
	virtual void slot0();
	virtual void slot1();

	int isArray() const;
	BfmeAptValue006DCD20 *rva006DCFA0();
	BfmeAptValue006DCD20 *rva006DCEE0();
	void rva006D9500(int nCapacity);
	void rva006D8AD0(int nIndex, BfmeAptValue006DCD20 *pNewValue);
	void rva006D95E0(int nIndex, BfmeAptValue006DCD20 *pValue);

	unsigned int m_flags;
	char m_pad[0x18];
	BfmeAptValue006DCD20 **m_data;
	int mnCapacity;
	int mnLength;
};

extern BfmeAptValue006DCD20 *g_aptUndefinedAtE18078;

class EAStringC;

// The qsort comparators at VA 0x00AD9D70 / 0x00AD9E40; only their addresses
// reach this body, and both pushes are DIR32 sites masked at verify.
extern "C" int __cdecl rva006D9D70Comparator(const void *, const void *);
extern "C" int __cdecl rva006D9E40Comparator(const void *, const void *);

// msvcr71 qsort reached through the import thunk at 0x00629B4A.
extern "C" void __cdecl qsort(void *, unsigned int, unsigned int, int (__cdecl *)(const void *, const void *));

// Scratch array handles published by the non-default sort path (VA 0x00E18044
// and 0x00E18048).
extern BfmeAptValue006DCD20 *g_rva006D9F00Handle;
extern BfmeAptValue006DCD20 **g_rva006D9F00Data;

// ?rva006D9CE0@@YAPAVBfmeAptValue006DCD20@@PAV1@H@Z @0x006D9CE0 (143 bytes).
// Prepends `count` interpreter-stack values to the array: the backing store is
// moved right by count, the slots are nulled, and each is filled through the
// checked store 0x006D95E0. Returns the new length as an AptInteger, or the
// shared undefined value when the receiver is not an array.
// Evidence: own immediates and callees isArray 0x006DC3A0, cast 0x006DCFA0,
// resize 0x006D9500, set 0x006D8AD0, store 0x006D95E0, At 0x006FE580 and
// AptInteger::Create 0x006D8520.
BfmeAptValue006DCD20 *rva006D9CE0(BfmeAptValue006DCD20 *pValue, int count)
{
	if (static_cast<unsigned char>(pValue->isArray()))
	{
		BfmeAptValue006DCD20 *array = pValue->rva006DCFA0();
		array->rva006D9500(array->mnLength + count);

		if (count != 0)
		{
			memmove(array->m_data + count, array->m_data, array->mnLength * 4);
			array->mnLength += count;
			for (int i = 0; i < count; ++i)
			{
				array->m_data[i] = 0;
				BfmeAptValue006DCD20 *value = g_aptValueStackAtE182E0.At(i);
				array->rva006D95E0(i, value);
			}
		}

		return AptInteger::Create(array->mnLength);
	}

	return g_aptUndefinedAtE18078;
}

// ?rva006D9F00@@YAPAVBfmeAptValue006DCD20@@PAV1@H@Z @0x006D9F00 (103 bytes).
// Array sort native: sorts the element pointer vector in place with qsort.
// mode 0 uses the comparator at 0x00AD9D70; any other mode first reads stack
// slot 0, publishes it and its element pointer through the two handle globals
// and uses the comparator at 0x00AD9E40. Non-arrays and the sort both return
// the shared undefined value.
// Evidence: own immediates; callees isArray 0x006DC3A0, cast 0x006DCFA0,
// checked cast 0x006DCEE0, At 0x006FE580 and qsort 0x00629B4A.
BfmeAptValue006DCD20 *rva006D9F00(BfmeAptValue006DCD20 *pValue, int mode)
{
	if (static_cast<unsigned char>(pValue->isArray()))
	{
		BfmeAptValue006DCD20 *array = pValue->rva006DCFA0();

		if (mode == 0)
		{
			qsort(array->m_data, array->mnLength, 4, rva006D9D70Comparator);
		}
		else
		{
			BfmeAptValue006DCD20 *value = g_aptValueStackAtE182E0.At(0);
			g_rva006D9F00Handle = value;
			g_rva006D9F00Data = value->rva006DCEE0()->m_data;
			qsort(array->m_data, array->mnLength, 4, rva006D9E40Comparator);
		}
	}

	return g_aptUndefinedAtE18078;
}
