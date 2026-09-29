// ??0Made002CCC90@@QAE@XZ
// partial score=0.91 date=2026-09-29
// ??0Made002CCC90@@QAE@XZ
// partial score=0.91 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ??0Made002CCC90@@QAE@XZ retail 0x0050BD45 55B
// Evidence: pin ??0Made002CCC90; callee base Rva00507823 0x0050775B;
// caller parseLuaEventNugget 0x002CCCB5; prev Made002CCC90Parse same
// /O1 DNDEBUG MD plus arch:SSE for xorps float zero; vtable 0x00864F78
// plus dword +0x128 zero plus float +0x12C zero plus bytes +0x130-132
// zero; dtor 0x0050BD9D destroys string at +0x128.
class Rva00507823
{
public:
	Rva00507823();
	virtual ~Rva00507823();
private:
	char m_pad[0x128 - 4];
};
class Made002CCC90 : public Rva00507823
{
public:
	Made002CCC90();
	virtual ~Made002CCC90();
private:
	int m_128;
	float m_12C;
	unsigned char m_130;
	unsigned char m_131;
	unsigned char m_132;
};
Made002CCC90::Made002CCC90()
{
	m_128 = 0;
	m_130 = 0;
	m_131 = 0;
	m_132 = 0;
	m_12C = 0.0f;
}
