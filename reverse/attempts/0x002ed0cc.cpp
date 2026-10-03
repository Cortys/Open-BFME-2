// ?rva002ED0CC@Rva002ED0CC@@QAEPAV1@HPAVObject@@H@Z
// partial score=0.9 date=2026-10-03
// cl: /O1 /MD
// ?rva002ED0CC@Rva002ED0CC@@QAEPAV1@HPAVObject@@H@Z @0x002ED0CC 142B unlock init via clearer Split and Object bools.
// Evidence: rowed clearer 0x002E6FDF rowed Split 0x002EBCA7 rowed Object bools 0x0028AC62 0x0028AFBB; caller 0x002F1BB5; prev/next share /O1.
class Object
{
public:
	bool rva0028AC62() const;
	bool rva0028AFBB() const;
};

class Rva002E6FDF
{
public:
	Rva002E6FDF *rva002E6FDF();
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	unsigned char m_10;
	unsigned char m_11;
	char m_pad12[2];
	int m_14;
	int m_18;
	int m_1C;
	unsigned char m_20;
	unsigned char m_21;
	char m_pad22[2];
	int m_24;
	unsigned char m_28;
	char m_pad29[3];
	int m_2C;
	unsigned char m_30;
	unsigned char m_31;
	unsigned char m_32;
	char m_pad33[1];
	int m_34;
};

void __cdecl Rva002EBCA7Split(void *p, int *outHalf, unsigned char *outOdd);

struct Rva002ED0CCInner
{
	char m_pad[0x56C];
	int m_56C;
	char m_pad2[0x634 - 0x56C - 4];
	unsigned char m_634;
};

struct Rva002ED0CCBlock16
{
	int m_00;
	unsigned char m_04;
	unsigned char m_05;
	char m_pad06[2];
	int m_08;
	unsigned char m_0C;
	char m_pad0D[3];
};

class Rva002ED0CC
{
public:
	Rva002ED0CC *rva002ED0CC(int a, Object *b, int c);
private:
	int m_00;
	Object *m_04;
	Rva002E6FDF m_08;
	char m_40[8];
	Rva002ED0CCBlock16 m_48;
	int m_58;
};

// ?rva002ED0CC@Rva002ED0CC@@QAEPAV1@HPAVObject@@H@Z present-unmatched
Rva002ED0CC *Rva002ED0CC::rva002ED0CC(int a, Object *b, int c)
{
	m_00 = a;
	m_04 = b;
	m_08.rva002E6FDF();
	Rva002ED0CCInner *inner = *(Rva002ED0CCInner **)((char *)b + 4);
	unsigned char ok1;
	unsigned char v634;
	int v56c = inner->m_56C;
	v634 = inner->m_634;
	ok1 = b->rva0028AC62();
	bool ok2 = b->rva0028AFBB();
	Rva002ED0CCBlock16 *p48 = &m_48;
	p48->m_00 = c;
	bool isZero = (v634 == 0);
	p48->m_05 = ok2;
	p48->m_0C = ok1;
	p48->m_08 = v56c - 1;
	p48->m_04 = isZero;
	*(Rva002ED0CCBlock16 *)&m_08.m_1C = m_48;
	m_58 = 0;
	m_08.m_11 = 0;
	m_08.m_14 = 12;
	Rva002EBCA7Split(m_04, &m_08.m_0C, &m_08.m_10);
	return this;
}
