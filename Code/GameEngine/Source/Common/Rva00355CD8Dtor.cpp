// cl: /O1 /MD /EHsc
// ??1Rva00355CD8@@UAE@XZ @0x00355CD8 62B. Dtor storing vtable 0x00814E54,
// conditional virtual slot1 on base+4 (Gen m_next) with arg +0xC, then base
// ??1Gen_004902A0@@UAE@XZ. Evidence: deleting dtor at 0x00355FC1 calls here,
// shared EH scope 0x00B7D529 with sibling 0x00355D66, same flags.
class Gen_004902A0
{
public:
	virtual ~Gen_004902A0() throw();
	virtual void slot1(int x);
	Gen_004902A0 *m_next; // +4
};

class Rva00355CD8 : public Gen_004902A0
{
public:
	virtual ~Rva00355CD8();
private:
	int m_pad8; // +8 (unused in dtor, places m_argC)
	int m_argC; // +0xC
};

Rva00355CD8::~Rva00355CD8()
{
	if (m_next)
		m_next->slot1(m_argC);
}
