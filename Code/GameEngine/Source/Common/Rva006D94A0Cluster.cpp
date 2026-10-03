// cl: /O2 /MD
// Rva006DA130 (retail 0x006DA130, 104 bytes): in-place reversal of the Apt
// array value's element vector. Free function taking the value; if it is not
// an array the shared undefined singleton at 0x00E18078 is returned, else the
// checked array cast (rva006DCFA0) is reversed by swapping element i with
// element mnLength-1-i for i < mnLength/2, and the original value is returned.
// Evidence: retail layout m_data +0x20 / mnLength +0x28 and the rowed callees
// isArray 0x006DC3A0 and rva006DCFA0 0x006DCFA0, shared with the rowed array
// bodies in AptValueArrayAt.cpp (same class and flags). Name address-derived;
// class name follows that TU.

class BfmeAptValue006DCD20
{
public:
	virtual void slot0();
	virtual void slot1();

	int isArray() const;
	BfmeAptValue006DCD20 *rva006DCFA0();

	unsigned int m_flags;
	char m_pad[0x18];
	BfmeAptValue006DCD20 **m_data;
	int mnCapacity;
	int mnLength;
};

extern BfmeAptValue006DCD20 *g_aptUndefinedAtE18078;

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
