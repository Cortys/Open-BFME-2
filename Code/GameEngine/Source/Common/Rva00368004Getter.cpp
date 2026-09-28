// cl: /O1 /MD
// ?rva00368004@Rva00368004@@QAE_NXZ @0x00368004 17B
// Null-checked virtual forward: if +0x3C pointer is null return false else
// tail-jmp to its virtual slot 0x48 (19th virtual returning bool).
// Evidence: retail cmp [ecx+0x3C],0 plus xor al,al null path plus mov ecx,[ecx+0x3C]
// plus mov eax,[ecx] plus jmp [eax+0x48]; callers at 0x0036A5A7/0x0036A7C7.
// Owner unproven so honest address class names used.
class Rva00368004Inner
{
public:
	virtual void slot00() = 0;
	virtual void slot04() = 0;
	virtual void slot08() = 0;
	virtual void slot0C() = 0;
	virtual void slot10() = 0;
	virtual void slot14() = 0;
	virtual void slot18() = 0;
	virtual void slot1C() = 0;
	virtual void slot20() = 0;
	virtual void slot24() = 0;
	virtual void slot28() = 0;
	virtual void slot2C() = 0;
	virtual void slot30() = 0;
	virtual void slot34() = 0;
	virtual void slot38() = 0;
	virtual void slot3C() = 0;
	virtual void slot40() = 0;
	virtual void slot44() = 0;
	virtual bool slot48() = 0;
};
class Rva00368004
{
public:
	bool rva00368004();
	char m_lead[0x3C];
	Rva00368004Inner *m_ptr;
};
bool Rva00368004::rva00368004()
{
	if (!m_ptr)
		return false;
	return m_ptr->slot48();
}
