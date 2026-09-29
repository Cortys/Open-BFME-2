// ??0Rva003B417E@@QAE@XZ
// partial score=0.95 date=2026-09-29
// ??0Rva003B417E@@QAE@XZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD /arch:SSE /Oi
//
// ??0Rva003B417E@@QAE@XZ, retail 0x003B417E, 122 bytes.
// Ctor storing vtable 0x0081F424 plus int and flag inits plus float zeros
// plus 8-byte stosd pair plus BfmeFixedStorage002CF0F0 copy from 0x00A02D64.

typedef unsigned int UnsignedInt;

extern "C" void *memset(void *dst, int val, unsigned int n);

class BfmeFixedStorage002CF0F0
{
	char m_bytes[4];
public:
	BfmeFixedStorage002CF0F0() {}
	BfmeFixedStorage002CF0F0(const BfmeFixedStorage002CF0F0 &other);
};

#define FixedStorageSource (*(const BfmeFixedStorage002CF0F0 *)0x00A02D64)

class Rva003B417E
{
	virtual void _pure() = 0;
	int m_04;
	int m_08;
	int m_0c;
	bool m_10;
	bool m_11;
	int m_14;
	bool m_18;
	int m_1c;
	int m_20;
	BfmeFixedStorage002CF0F0 m_24;
	bool m_28;
	bool m_29;
	bool m_2a;
	bool m_2b;
	bool m_2c;
	bool m_2d;
	int m_30;
	unsigned char m_34[8];
	int m_3c;
	bool m_40;
	bool m_41;
	int m_44;
	float m_48;
	float m_4c;
	int m_50;
public:
	Rva003B417E();
};

// ??0Rva003B417E@@QAE@XZ present-unmatched
Rva003B417E::Rva003B417E()
{
	m_04 = 0;
	m_08 = 0;
	m_0c = 0;
	m_10 = false;
	m_11 = false;
	m_14 = 0;
	m_18 = true;
	m_1c = 0;
	m_20 = 0;
	m_24.BfmeFixedStorage002CF0F0::BfmeFixedStorage002CF0F0(FixedStorageSource);
	m_2a = false;
	m_30 = 0;
	m_3c = 0;
	m_41 = false;
	m_28 = true;
	m_29 = true;
	m_2b = true;
	m_2c = true;
	m_2d = true;
	m_40 = true;
	m_44 = 0;
	m_50 = 0;
	m_48 = 0.0f;
	m_4c = 0.0f;
	memset(m_34, 0, 8);
}
