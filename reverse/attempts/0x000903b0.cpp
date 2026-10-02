// ?rva000903B0@Rva00090360@@QAEXXZ
// partial score=0.93 date=2026-10-02
// cl: /O1 /MD /G7
//
// ?rva000903B0@Rva00090360@@QAEXXZ, retail 0x000903B0, 103 bytes.
// Vtable slot 10 of 0x007C7E20 (class Rva00090360); neighbours are landed
// ctor 0x00090360 and deleting dtor in OpaqueScalarDeletingDtors.
// Evidence: TheGameClient extern in use, vtable slot 10, caller class layout
// from Rva00090360Ctor (size 0x40, +0xC/+0x10 chain, +0x14[10], +0x3C).

class ClientFrameSubsystem
{
public:
	virtual int s00();
	virtual int s01();
	virtual int s02();
	virtual int s03();
	virtual int s04();
	virtual int s05();
	virtual int s06();
	virtual int s07();
	virtual int s08();
	virtual int s09();
	virtual int s10();
	virtual int s11();
	virtual int s12();
	virtual int s13();
	virtual int s14();
	virtual int s15();
	virtual int s16();
	virtual int s17();
	virtual int s18();
	virtual int s19();
	virtual int s20();
	virtual int s21();
	virtual int s22();
	virtual int s23();
	virtual int s24();
	virtual int s25();
	virtual int s26();
	virtual int s27();
	virtual int s28();
	virtual int s29();
	virtual int s30();
	virtual int s31();
};

extern ClientFrameSubsystem *TheGameClient;

struct Elem14
{
	virtual void s00();
};

struct ElemD8
{
	virtual void t00();
};

struct Elem
{
	char m_pad0[0xC];
	Elem *m_next;
	int m_10;
	Elem14 m_14;
	char m_pad18[0xD8 - 0x18];
	ElemD8 m_d8;
	char m_padDC[0x1A0 - 0xDC];
	unsigned char m_1A0;
	char m_pad1A1[0x1F4 - 0x1A1];
	unsigned int m_1F4;
};

class Rva00090360
{
public:
	virtual ~Rva00090360();
	void rva000903B0();
private:
	char m_pad4[8];
	Elem *m_0C;
	Elem *m_10;
	int m_14[10];
	int m_3C;
};

// ?rva000903B0@Rva00090360@@QAEXXZ present-unmatched
void Rva00090360::rva000903B0()
{
	Elem *cur = m_10 ? m_10 : m_0C;
	unsigned int now = (unsigned int)TheGameClient->s31();
	for (int i = 10; i > 0; --i) {
		if (!cur)
			break;
		if (cur->m_1F4 != 0) {
			if (now - cur->m_1F4 > 0x3C) {
				cur->m_14.s00();
				cur->m_d8.t00();
				cur->m_1F4 = 0;
				cur->m_1A0 = 1;
			}
		}
		cur = cur->m_next;
	}
	m_10 = cur;
}
