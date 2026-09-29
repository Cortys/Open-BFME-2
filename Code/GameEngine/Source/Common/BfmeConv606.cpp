class BfmeThingCIB
{
public:
	void bfmeGoCIB(void *one, void *two);
	unsigned char m_bfmeHead[0x10];
	void *m_bfmeA;
	void *m_bfmeB;
	unsigned char m_bfmeGap[0xc];
	int m_bfmeErr;
};

int Rva007EC5C0(char *a, int b, const char *c, int d);

void BfmeThingCIB::bfmeGoCIB(void *one, void *two)
{
	if (Rva007EC5C0((char *)m_bfmeA, (int)m_bfmeB, (const char *)one, (int)two) < 0)
		m_bfmeErr = -100;
}
