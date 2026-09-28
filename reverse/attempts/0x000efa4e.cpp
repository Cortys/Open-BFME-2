// ??0Rva000EFA4E@@QAE@XZ
// partial score=0.98 date=2026-09-28
// ??0Rva000EFA4E@@QAE@XZ
// partial score=0.98 date=2026-09-28
// cl: /O1 /arch:SSE
// ??0Rva000EFA4E@@QAE@XZ @0x000EFA4E 132B
// Base __thiscall ctor (no vtable store) called by derived ctors at 0x000F0F19
// 0x000F0F2B 0x00109D8C which store vtable 0x00BCEFA0 (9 slots: deleting dtor
// 0x000EFAD2 empty 0x000B3FD0 Vector Resize/Clear/ID). Evidence: 5 callers pass
// same this; float 1.0 at 0x00BBB8D8; two RvaVec3 copies via movsd; or-mem -1
// idiom; up to +0x54 with derived extending to +0x64 (20.0 at 0x00BC5CCC).
struct RvaVec3
{
	float x;
	float y;
	float z;
};

class Rva000EFA4E
{
public:
	Rva000EFA4E();
private:
	char m_pad00[4];
	unsigned char m_04;
	unsigned char m_05;
	char m_pad06[2];
	RvaVec3 m_08;
	RvaVec3 m_14;
	float m_20;
	int m_24;
	int m_28;
	int m_2C;
	unsigned char m_30;
	char m_pad31[3];
	int m_34;
	int m_38;
	int m_3C;
	int m_40;
	int m_44;
	int m_48;
	int m_4C;
	int m_50;
	int m_54;
};

// ??0Rva000EFA4E@@QAE@XZ present-unmatched
Rva000EFA4E::Rva000EFA4E()
{
	RvaVec3 tmp;
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	tmp.z = 0.0f;
	m_28 = -1;
	m_24 = -1;
	m_08 = tmp;
	tmp.x = 0.0f;
	tmp.y = 0.0f;
	tmp.z = 1.0f;
	m_14 = tmp;
	m_04 = 1;
	m_05 = 0;
	m_20 = 0.0f;
	m_2C = 0xFF;
	m_30 = 1;
	m_34 = 0;
	m_38 = 0;
	m_3C = -1;
	m_40 = 0;
	m_44 = 0;
	m_48 = 0;
	m_4C = 0;
	m_50 = 0;
	m_54 = 0;
}
