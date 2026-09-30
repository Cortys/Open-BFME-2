// ?rva001EB6A5@Rva001EB6A5@@QAE_NPAURva001EB6A5Out@@@Z
// partial score=0.93 date=2026-09-30
// ?rva001EB6A5@Rva001EB6A5@@QAE_NPAURva001EB6A5Out@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD
// ?rva001EB6A5@Rva001EB6A5@@QAE_NPAURva001EB6A5Out@@@Z @0x001EB6A5 (89B)
// Thiscall bool takes out struct with two AsciiStrings plus flag byte.
// Copies m_C0 to out+8 then add is (m_C3==0 and m_C0!=0) ? 1 : 0. Idx is
// m_0C plus add via rowed rva001EB3A6 returning BfmeAssignRecord36. Null
// gives false else out strings from rec+0 and rec+0xc via pinned AsciiString
// assign and true. Ret 4. Caller 0x001EB74B. Evidence unlock lane plus prev
// Rva001EB435Check models plus bounds row plus pin assigns.
class AsciiString
{
public:
	AsciiString &operator=(const AsciiString &other);
private:
	void *m_data;
};
struct BfmeAssignRecord36
{
	AsciiString s;
	int a[8];
};
class Rva001EB3A6
{
public:
	BfmeAssignRecord36 *rva001EB3A6(int i);
};
struct Rva001EB6A5Out
{
	AsciiString m_s0;
	AsciiString m_s1;
	unsigned char m_flag;
};
class Rva001EB6A5
{
public:
	bool rva001EB6A5(Rva001EB6A5Out *out);
private:
	char m_00[4];
	Rva001EB3A6 *m_04;
	char m_08[4];
	int m_0C;
	char m_10[0xB0];
	unsigned char m_C0;
	char m_pad[2];
	unsigned char m_C3;
};
// ?rva001EB6A5@Rva001EB6A5@@QAE_NPAURva001EB6A5Out@@@Z present-unmatched
bool Rva001EB6A5::rva001EB6A5(Rva001EB6A5Out *out)
{
	unsigned char *pC0 = &m_C0;
	out->m_flag = *pC0;
	int base;
	int add;
	if (m_C3 == 0 && *pC0 != 0)
		add = 1;
	else
		add = 0;
	base = m_0C;
	int idx = add + base;
	BfmeAssignRecord36 *rec = m_04->rva001EB3A6(idx);
	if (rec == 0)
		return false;
	out->m_s0 = rec->s;
	out->m_s1 = *(AsciiString *)((char *)rec + 0xc);
	return true;
}
