// cl: /O1 /DNDEBUG /MD

// ?rva00111F0E@Rva00111F0E@@QAEXXZ, retail 0x00111F0E, 97 bytes.
// Unlock lane: releases four refcounted holders at +0x24 +0x2C +0x68 +0x70
// and zeroes ints at +0x48 +0x4C +0x78 +0x7C. Callers at 0x00111F7B
// 0x00112272 0x001122AD 0x00115A26 prove __thiscall method shape.
// Owner unproven so address-derived Rva00111F0E holder.

class RvaRef
{
public:
	virtual void Delete_This();
	void Release_Ref()
	{
		if (--m_refs == 0)
			Delete_This();
	}
private:
	int m_refs;
};

class Rva00111F0E
{
public:
	void rva00111F0E();
private:
	char m_pad00[0x24];
	RvaRef *m_24;
	char m_pad28[0x2C - 0x28];
	RvaRef *m_2C;
	char m_pad30[0x48 - 0x30];
	int m_48;
	int m_4C;
	char m_pad50[0x68 - 0x50];
	RvaRef *m_68;
	int m_6C;
	RvaRef *m_70;
	char m_pad74[0x78 - 0x74];
	int m_78;
	int m_7C;
};

void Rva00111F0E::rva00111F0E()
{
	if (m_24) {
		m_24->Release_Ref();
		m_24 = 0;
	}
	if (m_2C) {
		m_2C->Release_Ref();
		m_2C = 0;
	}
	m_48 = 0;
	m_4C = 0;
	if (m_68) {
		m_68->Release_Ref();
		m_68 = 0;
	}
	if (m_70) {
		m_70->Release_Ref();
		m_70 = 0;
	}
	m_78 = 0;
	m_7C = 0;
}
