// ?rva006EC6F0@@YAPAVBfmeAptValue006DCD20@@PAV1@@Z
// partial score=0.9 date=2026-10-03
// cl: /O2 /MD /EHsc
// Rva006EC6F0 (retail 0x006EC6F0, 59 bytes): CIH-to-integer conversion helper.
// Takes an Apt value; a non-CIH value yields the shared undefined singleton at
// 0x00E18078, otherwise the value's CIH payload word at +0x58 is sign-extended
// from 17 bits and biased by -0x4000 into a new AptInteger. Evidence: the
// direct calls resolve to the rowed isCIH 0x006DC580, the checked isCIH cast
// 0x006DCF60 and AptInteger::Create 0x006D8520; +0x58 is the body's own
// displacement. Address-derived free-function name.

class BfmeAptValue006DCD20
{
public:
	virtual void slot0();
	virtual void slot1();

	int isCIH(bool bUndefOK) const;
	BfmeAptValue006DCD20 *rva006DCF60(bool bUndefOK);

	unsigned int m_flags;
	char m_pad[0x50];
	int m_cihValue;
};

class AptInteger
{
public:
	static BfmeAptValue006DCD20 *Create(int nValue);
};

extern BfmeAptValue006DCD20 *g_aptUndefinedAtE18078;

BfmeAptValue006DCD20 *rva006EC6F0(BfmeAptValue006DCD20 *pValue)
{
	if (static_cast<unsigned char>(pValue->isCIH(false)))
	{
		BfmeAptValue006DCD20 *cih = pValue->rva006DCF60(false);
		int value = *reinterpret_cast<int *>(reinterpret_cast<char *>(cih) + 0x58);
		value = (value << 15) >> 15;
		value = value - 0x4000;
		return AptInteger::Create(value);
	}

	return g_aptUndefinedAtE18078;
}
