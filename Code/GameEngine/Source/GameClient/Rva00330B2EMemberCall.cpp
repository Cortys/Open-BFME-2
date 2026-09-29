// cl: /O1 /MD
// ?rva00330B2E@Rva00330B2E@@QAEXXZ, retail 0x00330B2E, 19 bytes.
// Thiscall: calls member+8 Rva0030B9CA::rva0030B9CA (rowed 0x30B9CA) then
// tail-jmps own virtual slot12 (0x30). Chain via 0x30B9CA. No donor.
struct Rva0030B9CA
{
	void rva0030B9CA();
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
private:
	int m_04;
	Rva0030B9CA m_08;
};

void Rva00330B2E::rva00330B2E()
{
	m_08.rva0030B9CA();
	_slot12();
}
