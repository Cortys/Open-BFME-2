// cl: /O1 /MD /arch:SSE
// ??0Rva00391667@@QAE@PBX@Z @0x00391667 44B ctor stores vtable 0x00C1A068 copies 3 dwords from param clears +4/+8 caller 0x003948CB
struct Rva00391667Base
{
	int m_04;
	Rva00391667Base();
};
// ??0Rva00391667Base@@QAE@XZ present-unmatched
inline Rva00391667Base::Rva00391667Base() : m_04(0) {}
class Rva00391667 : public Rva00391667Base
{
public:
	Rva00391667(void const *p);
	virtual void unk();
private:
	float m_08;
	int m_0c;
	int m_10;
	int m_14;
};
Rva00391667::Rva00391667(void const *p)
{
	int const *q = (int const *)p;
	m_0c = q[0];
	m_10 = q[1];
	m_14 = q[2];
	m_08 = 0.0f;
}
// ?unk@Rva00391667@@UAEXXZ present-unmatched
void Rva00391667::unk() {}
