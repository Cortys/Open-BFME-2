// ?find2@Rva006FBE80@@QAEPAVBfmeN1034@@H@Z
// partial score=0.93 date=2026-10-03
// ?find2@Rva006FBE80@@QAEPAVBfmeN1034@@H@Z @0x006FBE80 66B.
// Global linked-list find: walk the 0x00E1835C chain calling the rowed table
// lookup on each node's +0x14 table; if the chain head is null fall back to this
// object's +0x28 member. Names are address-derived; every callee is rowed.
// The retail body keeps the redundant `test esi,esi` at the top of the loop,
// which /O2 propagates away from this source -- see the attempt evidence.
// cl: /O2 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
class BfmeN1034;

class BfmeTab1034
{
public:
	BfmeN1034 *bfmeFind1034F(int key);
private:
	char m_pad[0x14];
};

struct Rva006FBBE0
{
	BfmeN1034 *find(int key);
	char m_pad00[8];
	BfmeTab1034 m_table;
	Rva006FBBE0 *m_next;
};

BfmeN1034 *Rva006FBBE0::find(int key)
{
	Rva006FBBE0 *node = this;
	while (node != 0) {
		BfmeN1034 *found = node->m_table.bfmeFind1034F(key);
		if (found != 0)
			return found;
		node = node->m_next;
	}
	return 0;
}

struct Rva006FBE80
{
	BfmeN1034 *find2(int key);
	char m_pad00[0x28];
	Rva006FBBE0 *m_member28;
};

Rva006FBBE0 *g_Va00E1835C;

// ?find2@Rva006FBE80@@QAEPAVBfmeN1034@@H@Z present-unmatched
BfmeN1034 *Rva006FBE80::find2(int key)
{
	Rva006FBBE0 *node = g_Va00E1835C;
	if (node == 0) {
		Rva006FBBE0 *member = m_member28;
		return member != 0 ? member->find(key) : 0;
	}
	while (node != 0) {
		if (node == 0)
			return 0;
		BfmeN1034 *found = node->m_table.bfmeFind1034F(key);
		if (found != 0)
			return found;
		node = node->m_next;
	}
	return 0;
}