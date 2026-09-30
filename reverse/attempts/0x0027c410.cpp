// ??0Rva0027C36A@@QAE@ABV0@@Z
// partial score=0.99 date=2026-09-30
// cl: /O1 /MD /Op /Oi /Oy-
// ??0Rva0027C36A@@QAE@ABV0@@Z @0x0027C410 228B
// Evidence: copy ctor of Rva0027C36A (default ctor 0x0027C36A); head 0x58 via 22 int moves; m_58 via movsd x4; m_68 byte; 4x12B loop int-int-float (fld); m_9c via movsd x3; caller 0x0027F8B0.
#include <cstring>

struct Region12
{
	int m_0;
	int m_4;
	float m_8;
};

struct Six12
{
	char m_d[6];
};

class Rva0027C36A
{
public:
	Rva0027C36A(const Rva0027C36A &other);
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	int m_28;
	int m_2c;
	int m_30;
	int m_34;
	int m_38;
	int m_3c;
	int m_40;
	int m_44;
	int m_48;
	int m_4c;
	int m_50;
	int m_54;
	int m_58[4];
	unsigned char m_68;
	char m_pad69[3];
	Region12 m_6c[4];
	Six12 m_9c[2];
};

// ??0Rva0027C36A@@QAE@ABV0@@Z present-unmatched
Rva0027C36A::Rva0027C36A(const Rva0027C36A &other)
{
	m_00 = other.m_00;
	m_04 = other.m_04;
	m_08 = other.m_08;
	m_0c = other.m_0c;
	m_10 = other.m_10;
	m_14 = other.m_14;
	m_18 = other.m_18;
	m_1c = other.m_1c;
	m_20 = other.m_20;
	m_24 = other.m_24;
	m_28 = other.m_28;
	m_2c = other.m_2c;
	m_30 = other.m_30;
	m_34 = other.m_34;
	m_38 = other.m_38;
	m_3c = other.m_3c;
	m_40 = other.m_40;
	m_44 = other.m_44;
	m_48 = other.m_48;
	m_4c = other.m_4c;
	m_50 = other.m_50;
	m_54 = other.m_54;
	memcpy(m_58, other.m_58, sizeof(m_58));
	m_68 = other.m_68;
	for (int i = 0; i < 4; ++i) {
		m_6c[i].m_0 = other.m_6c[i].m_0;
		m_6c[i].m_4 = other.m_6c[i].m_4;
		m_6c[i].m_8 = other.m_6c[i].m_8;
	}
	memcpy(m_9c, other.m_9c, sizeof(m_9c));
}
