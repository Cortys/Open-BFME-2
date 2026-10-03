// cl: /O2 /MD
// Apt array bodies recovered from the retail ABI at 0x006D94A0..0x006DA557.
// The class name and member offsets follow the rowed array helpers in
// Code/Libraries/Source/Apt/AptValue/AptValueArrayAt.cpp (m_data +0x20,
// mnCapacity +0x24, mnLength +0x28); the assert triple and file spelling are
// read from each body's own immediate operands.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;

class BfmeAptValue006DCD20
{
public:
	virtual void slot0();
	virtual void slot1();

	int isArray() const;
	BfmeAptValue006DCD20 *rva006DCFA0();
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

// ?rva006DA130@@YAPAVBfmeAptValue006DCD20@@PAV1@@Z @0x006DA130 (104 bytes).
// In-place reversal of the array's element vector: swap element i with
// mnLength-1-i for i < mnLength/2, returning the original value; a non-array
// returns the shared undefined singleton. Evidence: rowed isArray 0x006DC3A0
// and checked array cast 0x006DCFA0; layout shared with AptValueArrayAt.cpp.
BfmeAptValue006DCD20 *rva006DA130(BfmeAptValue006DCD20 *pValue)
{
	if (static_cast<unsigned char>(pValue->isArray()))
	{
		BfmeAptValue006DCD20 *array = pValue->rva006DCFA0();

		for (int i = 0; i < array->mnLength / 2; ++i)
		{
			BfmeAptValue006DCD20 **data = array->m_data;
			BfmeAptValue006DCD20 *temp = data[i];
			data[i] = data[array->mnLength - i - 1];
			array->m_data[array->mnLength - i - 1] = temp;
		}

		return pValue;
	}

	return g_aptUndefinedAtE18078;
}

// ?rva006D95E0@BfmeAptValue006DCD20@@QAEXHPAV1@@Z @0x006D95E0 (92 bytes).
// Checked array store at an explicit index: negative indices return, the
// backing store is grown to nIndex+1 through the pinned resize 0x006D9500,
// nIndex < mnCapacity is asserted at AptArray.cpp:0x10C, the element is
// assigned through the rowed setter 0x006D8AD0, and mnLength becomes
// max(nIndex+1, mnLength). Evidence: five caller sites push (index, value)
// and this body's own immediate operands; flags shared with the 0x006DA130
// body in this TU.
void BfmeAptValue006DCD20::rva006D95E0(int nIndex, BfmeAptValue006DCD20 *pValue)
{
	if (nIndex < 0)
		return;

	int newLength = nIndex + 1;
	rva006D9500(newLength);

	if (!(nIndex < mnCapacity)) {
		g_bfmeAptAssertAtE17734("nIndex < mnCapacity", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptArray.cpp", 0x10c);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__asm int 3
	}

	rva006D8AD0(nIndex, pValue);
	mnLength = (newLength > mnLength) ? newLength : mnLength;
}
