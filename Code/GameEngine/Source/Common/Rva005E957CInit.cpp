// cl: /O1 /MD
// ?rva005E957C@Rva005E957C@@QAEXHHHHHH@Z, retail 0x005E957C, 44 bytes.
// 6-dword init: copies 6 stack args to +0..+20; ret 0x18.
// Callers 0x003F5242 and 0x005E9AED pass 6 dwords to a 24-byte local.
class Rva005E957C
{
public:
	Rva005E957C *rva005E957C(int a1, int a2, int a3, int a4, int a5, int a6);
private:
	int m_0; // +0
	int m_1; // +4
	int m_2; // +8
	int m_3; // +12
	int m_4; // +16
	int m_5; // +20
};

Rva005E957C *Rva005E957C::rva005E957C(int a1, int a2, int a3, int a4, int a5, int a6)
{
	m_0 = a1;
	m_1 = a2;
	m_2 = a3;
	m_3 = a4;
	m_4 = a5;
	m_5 = a6;
	return this;
}
