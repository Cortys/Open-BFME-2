// cl: /O1 /MD
// ?rva005FD48E@Rva005FD48E@@QAEXXZ retail 0x005FD48E 28B
// Evidence: loop over 2 entries at +0x20 stride 0x18 calling rowed 0x001FF3A9; tail-jmp wrapper 0x005FD4F7 adjusts this+4; qualified call reproduces retail direct E8 to virtual forwarder
class Rva001FF3A9
{
public:
	virtual void rva001FF3A9_slot0();
	virtual void rva001FF3A9();
};
struct Rva005FD48EEntry
{
	Rva001FF3A9 *m_p;
	char m_pad[0x14];
};
struct Rva005FD48E
{
	char m_pad0[0x20];
	Rva005FD48EEntry m_e[2];
	void rva005FD48E();
};
void Rva005FD48E::rva005FD48E()
{
	Rva005FD48EEntry *e = m_e;
	for (int i = 2; i != 0; --i, ++e)
	{
		if (e->m_p)
			e->m_p->Rva001FF3A9::rva001FF3A9();
	}
}
