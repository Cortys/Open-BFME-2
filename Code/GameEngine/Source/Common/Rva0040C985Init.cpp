// cl: /O1
// ?rva0040C985@Rva0040C985@@QAEXH@Z, retail 0x0040C985, 31 bytes.
// Target evidence: leaf with 3 callers at 0x002B7A97 0x0040D3AE 0x0040F860; no vtable slot;
// touches +0x2C +0x30 +0x34 +0x38; prev ringobj.cpp next Disp8SubDwordFieldGetters.cpp.
class Rva00DFE78C
{
public:
	char m_pad[0x40];
	int m_40;
};
#define TheGameLogic (*(Rva00DFE78C *const *)0x00DFE78C)
class Rva00DFE758
{
public:
	char m_pad[0x134];
	int m_134;
};
#define TheGlobalData (*(Rva00DFE758 *const *)0x00DFE758)
class Rva0040C985
{
public:
	void rva0040C985(int x);
	int rva0040C9F4();
	void rva0040CA09();
	int rva0040CA24();

private:
	char m_pad[0x24];
	int m_24;
	int m_28;
	int m_2C;
	int m_30;
	int m_34;
	int m_38;
};

void Rva0040C985::rva0040C985(int x)
{
	if (m_2C == 0) {
		m_2C = 2;
		m_38 = x;
		m_34 = m_30 + x;
	}
}
int Rva0040C985::rva0040C9F4()
{
	int frame = TheGameLogic->m_40;
	int val = m_34;
	if (frame < val)
		return val - frame;
	return 0;
}
void Rva0040C985::rva0040CA09()
{
	int frame = TheGameLogic->m_40;
	if ((unsigned)frame < (unsigned)m_34)
		return;
	if (m_2C != 2)
		return;
	m_2C = 3;
}
int Rva0040C985::rva0040CA24()
{
	if (TheGlobalData->m_134 == 4)
		return m_28;
	return m_24;
}
