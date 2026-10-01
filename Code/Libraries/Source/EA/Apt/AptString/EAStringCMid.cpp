// cl: /O2 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?Mid@EAStringC@@QBE?AV1@H@Z, retail 0x006D5770, 217 bytes.
// EAStringC::Mid(int start) const: substr from start to end. BFME1 donor
// EAStringCMid.cpp Mid(int start): start<=0 returns *this; size=m_size-start;
// size<=0 returns empty via g_eaEmptyStringData; else copy *this to temp and
// ChangeBuffer(size start size PUSH_ZERO size) then copy temp to output.
// Callers 0x006D5A81 0x006D5D46 0x006D5F1B 0x006D5FB5 unclaimed.
// Neighbour EAStringCase.cpp shares flags and ChangeBuffer/FreeData rows.
class EAStringC
{
public:
	class StringDataC
	{
	public:
		unsigned short m_uRefCount;
		unsigned short m_uSize;
		unsigned short m_uMaxSize;
		unsigned short m_uHash;
	};

	static void FreeData(StringDataC *data);

	StringDataC *m_pData;

private:
	enum CBPushZero
	{
		CB_NO_PUSH_ZERO,
		CB_PUSH_ZERO
	};

	void ChangeBuffer(unsigned int uSizeToReserve, unsigned int uOffsetCopy,
		unsigned int uSizeCopy, CBPushZero ePushZero, unsigned int uInternalSize);

public:
	EAStringC()
	{
		extern StringDataC g_eaEmptyStringData;
		m_pData = &g_eaEmptyStringData;
		++g_eaEmptyStringData.m_uRefCount;
	}
	EAStringC(const EAStringC &other);
	~EAStringC()
	{
		FreeData(m_pData);
	}
	EAStringC Mid(int start) const;
};

extern EAStringC::StringDataC g_eaEmptyStringData;

EAStringC EAStringC::Mid(int start) const
{
	if (start <= 0)
		return *this;
	int size = m_pData->m_uSize - start;
	if (size <= 0)
		return EAStringC();
	EAStringC result(*this);
	result.ChangeBuffer(size, start, size, CB_PUSH_ZERO, size);
	return result;
}
