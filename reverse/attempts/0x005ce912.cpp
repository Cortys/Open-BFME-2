// ?rva005CE912@Rva005CE912@@QAEXHHHHHH@Z
// partial score=0.94 date=2026-10-02
// cl: /O1 /G7 /MD
// ?rva005CE912@Rva005CE912@@QAEXHHHHHH@Z, retail 0x005CE912, 44 bytes.
// __thiscall copy of six dwords: m_00..m_10 from args 2..6, m_14 from arg1.
// Evidence: packet disassembly, ret 0x18 (6 stack args), EBP frame,
// caller 0x005CF2FE in FUN_009cf27a, prev/next Disp0DwordImmSetters neighbours.
class Rva005CE912
{
public:
	void rva005CE912(int a1, int a2, int a3, int a4, int a5, int a6);

private:
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
};

// ?rva005CE912@Rva005CE912@@QAEXHHHHHH@Z present-unmatched
void Rva005CE912::rva005CE912(int a1, int a2, int a3, int a4, int a5, int a6)
{
	m_00 = a2;
	m_04 = a3;
	m_08 = a4;
	m_0C = a5;
	m_10 = a6;
	m_14 = a1;
}
