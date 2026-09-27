// cl: /O1
//
// ?rva0039D73A@TeamPrototype@@QAEXXZ @0x0039D73A (13B).
// TeamPrototype priority decrement: subtracts the dword at +0x224 from the
// dword at +0x21C. Retail shape is mov eax plus disp32 sub plus ret.
// Caller at 0x003BFC5D passes the TeamPrototype at Team+0x30 and then logs
// Team priority decreased with the updated +0x21C value, proving the owner
// is TeamPrototype and the +0x21C field is its priority.

class TeamPrototype
{
public:
	void rva0039D73A();

private:
	char m_pad00[0x21C];
	int m_priority21C; // +0x21C
	char m_pad220[0x224 - 0x220];
	int m_delta224; // +0x224
};

void TeamPrototype::rva0039D73A()
{
	m_priority21C -= m_delta224;
}
