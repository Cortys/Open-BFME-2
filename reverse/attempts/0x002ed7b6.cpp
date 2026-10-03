// ?rva002ED7B6@Rva002ED7B6@@QAEPAV1@HPAXHHHH@Z
// partial score=0.9 date=2026-10-03
// cl: /O1 /MD
// ?rva002ED7B6@Rva002ED7B6@@QAEPAV1@HPAXHHHH@Z @0x002ED7B6 65B unlock init via Split.
// Evidence: rowed Split 0x002EBCA7; caller 0x002F3BE8; prev shares /O1 /MD.
void __cdecl Rva002EBCA7Split(void *p, int *outHalf, unsigned char *outOdd);

class Rva002ED7B6
{
public:
	Rva002ED7B6 *rva002ED7B6(int a, void *b, int c, int d, int e, int f);
private:
	int m_00;
	void *m_04;
	unsigned char m_08;
	char m_pad09[3];
	int m_0C;
	int m_10;
	int m_14;
	int m_18;
	int m_1C;
};

// ?rva002ED7B6@Rva002ED7B6@@QAEPAV1@HPAXHHHH@Z present-unmatched
Rva002ED7B6 *Rva002ED7B6::rva002ED7B6(int a, void *b, int c, int d, int e, int f)
{
	m_10 = f;
	m_14 = c;
	m_18 = d;
	m_1C = e;
	m_00 = a;
	m_04 = b;
	Rva002EBCA7Split(m_04, &m_0C, &m_08);
	return this;
}
