// ?rva002B68AA@Rva002B68AA@@QAEPAUFindElem002B68AA@@ABVAsciiString@@@Z
// partial score=0.91 date=2026-09-29
// ?rva002B68AA@Rva002B68AA@@QAEPAUFindElem002B68AA@@ABVAsciiString@@@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /MD
// Near miss for 0x002B68AA 86B (unlock lane). Linear find over pointer
// vector at +0xBC/+0xC0 with key StringBase at +0x10 via rowed compare
// 0x000069D6; caller at 0x002B7791. Ours 78B/28insns vs retail 86B/28insns:
// count in ecx vs retail eax (two-reg vs single-reg: mov eax,begin +
// mov ecx,end + sub ecx,eax vs mov eax,end + sub eax,begin); reload of begin
// hoisted above je vs retail late (extra mov before branch, missing 2-insn
// reload on found path). Tried /Os /G7 /O2 and cast-vs-member key address
// (member access gives retail add ecx,0x10); no ebx after making elem dead
// across call (reload on found). Next: single-reg end-first count and late
// reload placement; see shape_levers #13 (empty tag sharing) #75-#78.
// Evidence: StringBase compare row; vector offsets +0xBC +0xC0 +0x10;
// AsciiString 4B layout per Rva00212A5AInsert precedent.
class AsciiString
{
	char *m_text;
};

template <typename T>
class StringBase
{
public:
	int compare(const StringBase<T> &other) const;
};

struct FindElem002B68AA
{
	char m_pad[0x10];
	AsciiString m_key10;
};

class Rva002B68AA
{
public:
	FindElem002B68AA *rva002B68AA(const AsciiString &name);
private:
	char m_pad[0xBC];
	FindElem002B68AA **m_beginBC;
	FindElem002B68AA **m_endC0;
};

FindElem002B68AA *Rva002B68AA::rva002B68AA(const AsciiString &name)
{
	for (unsigned int i = 0; i < (unsigned int)(m_endC0 - m_beginBC); ++i)
	{
		if (((const StringBase<char> *)&m_beginBC[i]->m_key10)->compare(*(const StringBase<char> *)&name) == 0)
			return m_beginBC[i];
	}
	return 0;
}
