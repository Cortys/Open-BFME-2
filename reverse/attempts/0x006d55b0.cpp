// ?Left@EAStringC@@QBE?AV1@H@Z
// partial score=0.94 date=2026-09-30
// ?Left@EAStringC@@QBE?AV1@H@Z
// partial score=0.94 date=2026-09-30
// cl: /O2 /DNDEBUG /MD /EHsc
// ?Left@EAStringC@@QBE?AV1@H@Z @0x006D55B0 211B: EAStringC::Left(count) returning
// first count chars by value; empty when count<=0, copy when count>=size via
// rowed copy ctor 0x006D2FC0, else ChangeBuffer(count 0 count PUSH_ZERO count)
// via rowed 0x006D4AA0 then copy and FreeData via rowed 0x006D2EB0.
// Evidence: g_eaEmptyStringData 0x009DC020, length at +2, ChangeBuffer args,
// callers 0x006D5BE5 and 0x006D5E15, prev/next AptString /O2 /DNDEBUG /MD,
// BFME1 EAStringCMid.cpp donor shape for Mid/Left family.
class EAStringC
{
public:
	class StringDataC
	{
	public:
		unsigned short m_refCount;
		unsigned short m_size;
		unsigned short m_maxSize;
		unsigned short m_hash;
	};
	enum CBPushZero
	{
		CB_NO_PUSH_ZERO,
		CB_PUSH_ZERO
	};
	EAStringC();
	EAStringC(const EAStringC &other);
	EAStringC(StringDataC *data);
	~EAStringC();
	static void FreeData(StringDataC *data);
private:
	void ChangeBuffer(unsigned int reserve, unsigned int offset, unsigned int copy, CBPushZero pushZero, unsigned int internalSize);
	StringDataC *m_data;
public:
	EAStringC Left(int count) const;
};

extern EAStringC::StringDataC g_eaEmptyStringData;

inline EAStringC::EAStringC() { m_data = &g_eaEmptyStringData; ++g_eaEmptyStringData.m_refCount; }
inline EAStringC::EAStringC(StringDataC *data) { ++data->m_refCount; m_data = data; }
inline EAStringC::~EAStringC() { FreeData(m_data); }

// ?Left@EAStringC@@QBE?AV1@H@Z present-unmatched
EAStringC EAStringC::Left(int count) const
{
	if (count <= 0)
		return EAStringC();
	if ((unsigned int)count >= m_data->m_size)
		return *this;
	EAStringC result(m_data);
	result.ChangeBuffer((unsigned int)count, 0, (unsigned int)count, CB_PUSH_ZERO, (unsigned int)count);
	return result;
}
