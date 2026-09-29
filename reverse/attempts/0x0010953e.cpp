// ?rva0010953E@Rva0010959E@@QAEXXZ
// partial score=0.96 date=2026-09-29
// ?rva0010953E@Rva0010959E@@QAEXXZ
// partial score=0.96 date=2026-09-29
// cl: /Os /DNDEBUG /MD /arch:SSE
struct ShadowObj
{
	char m_pad0[8];
	float m_8;
	float m_C;
	float m_10;
	char m_pad14[12];
	float m_20;
	char m_pad24[4];
	int m_28;
	char m_pad2C[60];
	int m_68;
};
class Rva0010959E
{
public:
	void rva0010953E();
private:
	char m_pad0[4];
	unsigned char m_4;
	unsigned char m_5;
	char m_pad6[2];
	float m_8;
	float m_C;
	float m_10;
	char m_pad14[12];
	float m_20;
	char m_pad24[52];
	ShadowObj *m_58;
	ShadowObj *m_5c;
	int m_60;
};
extern "C" void _ReadWriteBarrier();
// ?rva0010953E@Rva0010959E@@QAEXXZ present-unmatched
void Rva0010959E::rva0010953E()
{
	m_4 = 1;
	_ReadWriteBarrier();
	m_5 = 0;
	m_10 = 0.0f;
	m_C = 0.0f;
	m_8 = 0.0f;
	_ReadWriteBarrier();
	ShadowObj *p1 = m_58;
	m_20 = 0.0f;
	m_60 = 0;
	p1->m_28 = -1;
	p1->m_68 = 0;
	p1->m_10 = 0.0f;
	p1->m_C = 0.0f;
	p1->m_8 = 0.0f;
	p1->m_20 = 0.0f;
	_ReadWriteBarrier();
	ShadowObj *p2 = m_5c;
	p2->m_28 = -1;
	p2->m_68 = 0;
	p2->m_10 = 0.0f;
	p2->m_C = 0.0f;
	p2->m_8 = 0.0f;
	p2->m_20 = 0.0f;
}
