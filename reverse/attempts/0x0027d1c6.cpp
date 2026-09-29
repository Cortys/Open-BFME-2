// ?rva0027D1C6@Rva0027D1C6@@QAEXXZ
// partial score=0.95 date=2026-09-29
// ?rva0027D1C6@Rva0027D1C6@@QAEXXZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /G7 /arch:SSE /MD
// ?rva0027D1C6@Rva0027D1C6@@QAEXXZ, retail 0x0027D1C6, 41 bytes.
// Thiscall void init: clears +0/+4/+8 to 0.0f, +0xc/+0x14 to 0,
// sets +0x10 from global float VA 0x00BC876C (data 0x007C876C).
// Callers 0x27F0DF/0x27F114, local struct 0x18 at ebp-0x18 in 0x27F0D3.
// Volatile float forces retail movss xmm0,[global]; remaining diff is
// base register only: retail mov eax,ecx + stores via eax, ours via ecx.
#define TheFloat0027D1C6 (*(volatile float *)0x00BC876C)

class Rva0027D1C6
{
public:
	void rva0027D1C6();
private:
	float m_00;
	float m_04;
	float m_08;
	int m_0C;
	float m_10;
	int m_14;
};

void Rva0027D1C6::rva0027D1C6()
{
	m_10 = TheFloat0027D1C6;
	m_0C = 0;
	m_14 = 0;
	m_00 = 0.0f;
	m_04 = 0.0f;
	m_08 = 0.0f;
}
