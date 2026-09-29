class BfmeThingCIC
{
public:
	void bfmeGoCIC(void *one, void *two);
	unsigned char m_bfmeHead[0x10];
	void *m_bfmeA;
	void *m_bfmeB;
	unsigned char m_bfmeGap[0xc];
	int m_bfmeErr;
};

int Rva007ECE60(char *a, int b, const char *one, const char *two);

void BfmeThingCIC::bfmeGoCIC(void *one, void *two)
{
	if (Rva007ECE60((char *)m_bfmeA, (int)m_bfmeB, (const char *)one, (const char *)two) < 0)
		m_bfmeErr = -100;
}
