// cl: /O1 /MD
// ?rva00330B2E@Rva00330B2E@@QAEXXZ, retail 0x00330B2E, 19 bytes.
// Thiscall: calls member+8 Rva0030B9CA::rva0030B9CA (rowed 0x30B9CA) then
// tail-jmps own virtual slot12 (0x30). Chain via 0x30B9CA. No donor.
// ?rva00330B41@Rva00330B2E@@QAEXH@Z, retail 0x00330B41, 15 bytes.
// Same class: stores arg at +0x30 (right after 0x28-sized m_08) then calls
// slot12. Caller 0x30817D (jmp). Abuts 0x30B2E (tail jmp ends FF 60 30).
struct Rva0030B9CA
{
	void rva0030B9CA();
	char m_pad[0x28 - 1];
};

class Rva00330B2E
{
public:
	virtual void _slot00();
	virtual void _slot01();
	virtual void _slot02();
	virtual void _slot03();
	virtual void _slot04();
	virtual void _slot05();
	virtual void _slot06();
	virtual void _slot07();
	virtual void _slot08();
	virtual void _slot09();
	virtual void _slot10();
	virtual void _slot11();
	virtual void _slot12();
	void rva00330B2E();
	void rva00330B41(int v);
private:
	int m_04;
	Rva0030B9CA m_08;
	int m_30;
};

void Rva00330B2E::rva00330B2E()
{
	m_08.rva0030B9CA();
	_slot12();
}

void Rva00330B2E::rva00330B41(int v)
{
	m_30 = v;
	_slot12();
}
