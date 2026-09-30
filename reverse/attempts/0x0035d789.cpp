// ??0Rva0035D74A@@QAE@XZ
// partial score=0.93 date=2026-09-30
// ??0Rva0035D74A@@QAE@XZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD /arch:SSE
//
// ??0Rva0035D74A@@QAE@XZ @0x0035D789 (72B):
// Ctor calls rowed base 0x001DBAA4 then stores derived vtable, zeroes six
// ints at +0x10..+0x24, sets +0x30 to -1 via or, +0x34 to 0, re-zeroes base
// +0x0C, two floats at +0x28/+0x2C to 0.0f via xorps/movss, base +9 to 1 and
// base +4 to 0x16. Caller 0x0035D80F. Evidence: unlock lane, all callees
// rowed, prev/next dtors prove class, vtable store implicit.
class Rva001DBAA4
{
public:
	virtual ~Rva001DBAA4();
	Rva001DBAA4();
	int m_4;
	bool m_8;
	bool m_9;
	bool m_A;
	int m_C;
};
class Rva0035D74A : public Rva001DBAA4
{
public:
	Rva0035D74A();
	virtual ~Rva0035D74A();
private:
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	float m_28;
	float m_2c;
	int m_30;
	int m_34;
};
// ??0Rva0035D74A@@QAE@XZ present-unmatched
Rva0035D74A::Rva0035D74A()
{
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
	m_1c = 0;
	m_20 = 0;
	m_24 = 0;
	m_30 = -1;
	m_34 = 0;
	m_C = 0;
	m_28 = 0.0f;
	m_2c = 0.0f;
	m_9 = true;
	m_4 = 0x16;
}
