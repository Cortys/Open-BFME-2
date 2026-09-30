// ?rva001DD604@Rva001DD604@@QAE_NHPAH@Z
// partial score=0.95 date=2026-09-30
// ?rva001DD604@Rva001DD604@@QAE_NHPAH@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /EHsc /MD
// ?rva001DD604@Rva001DD604@@QAE_NHPAH@Z @0x001DD604 (108B).
// Indexed lookup over two parallel arrays (0x34 and 0x30 element sizes).
// Returns false for -1/negative/out-of-range/mismatched counts/clear flag,
// else stores dword at [elem+0x30] to *out and returns true.
// Evidence: caller at 0x003E547C (this=g_00DFDC30, index from Eva, out=ebp+0xC); no callees.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
struct Elem001DD604_34
{
	char m_pad00[0x22];
	unsigned char m_flag22;
	char m_pad23[0x30 - 0x22 - 1];
	int m_value30;
};

class Rva001DD604
{
public:
	bool rva001DD604(int index, int *out);

private:
	char m_pad00[0x1C];
	char *m_1CBase;
	char *m_20End;
	char m_pad24[0x5C - 0x24];
	char *m_5CBase;
	char *m_60End;
};

// ?rva001DD604@Rva001DD604@@QAE_NHPAH@Z present-unmatched
bool Rva001DD604::rva001DD604(int index, int *out)
{
	*out = 0;
	if (index == -1)
		return false;
	if (index < 0)
		return false;
	int count1 = (m_60End - m_5CBase) / 0x34;
	if ((unsigned int)index >= (unsigned int)count1)
		return false;
	_ReadWriteBarrier();
	int count2 = (m_20End - m_1CBase) / 0x30;
	_ReadWriteBarrier();
	int count1b = (m_60End - m_5CBase) / 0x34;
	if (count1b != count2)
		return false;
	Elem001DD604_34 *elem = (Elem001DD604_34 *)(m_5CBase + index * 0x34);
	if (elem->m_flag22 == 0)
		return false;
	*out = elem->m_value30;
	return true;
}
