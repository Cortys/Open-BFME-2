// ??0Rva00391667@@QAE@PBX@Z
// partial score=0.93 date=2026-09-29
// ??0Rva00391667@@QAE@PBX@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD /arch:SSE
// ??0Rva00391667@@QAE@PBX@Z @0x00391667 44B ctor stores vtable 0x00C1A068 copies 3 dwords from param clears +4/+8 caller 0x003948CB
class Rva00391667
{
public:
	Rva00391667(void const *p);
	virtual void unk();
private:
	int m_04;
	float m_08;
	int m_0c;
	int m_10;
	int m_14;
};
// ??0Rva00391667@@QAE@PBX@Z present-unmatched
Rva00391667::Rva00391667(void const *p)
{
	m_04 = 0;
	int const *q = (int const *)p;
	m_0c = q[0];
	m_10 = q[1];
	m_14 = q[2];
	m_08 = 0.0f;
}
void Rva00391667::unk() {}
