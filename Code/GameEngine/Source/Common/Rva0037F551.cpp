// cl: /O1 /MD
// ?rva0037F551@Rva0037F551@@QAEAAV1@ABV1@@Z retail 0x0037F551 45B
// Evidence: chain from 0x0037F51A; copies two 0x20 blocks at +0 and +0x20 via that row then int at +0x40 and bool at +0x44; caller 0x0037F71F
class Rva0037F51A
{
public:
	Rva0037F51A &rva0037F51A(const Rva0037F51A &src);
private:
	int m_00;
	float m_04;
	float m_08;
	float m_0c;
	float m_10;
	float m_14;
	float m_18;
	bool m_1c;
};

class Rva0037F551
{
public:
	Rva0037F551 &rva0037F551(const Rva0037F551 &src);
private:
	Rva0037F51A m_a;
	Rva0037F51A m_b;
	int m_40;
	bool m_44;
};

Rva0037F551 &Rva0037F551::rva0037F551(const Rva0037F551 &src)
{
	m_a.rva0037F51A(src.m_a);
	m_b.rva0037F51A(src.m_b);
	m_40 = src.m_40;
	m_44 = src.m_44;
	return *this;
}
// ?Rva0037F71FCopy@@YAXPAVRva0037F551@@ABV1@@Z retail 0x0037F71F 18B
// Evidence: chain from 0x0037F551; null-checked forward to rva0037F551; callers 0x0037F731 0x0037F757 0x0037FF20 0x0037FFDD
void Rva0037F71FCopy(Rva0037F551 *dst, const Rva0037F551 &src)
{
	if (dst)
		dst->rva0037F551(src);
}
