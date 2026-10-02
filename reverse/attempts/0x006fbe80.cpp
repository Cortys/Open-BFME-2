// ?find2@Rva006FBE80@@QAEPAVBfmeN1034@@H@Z
// partial score=0.91 date=2026-10-02
// cl: /O2 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// 0x006FBE80 (66B) near miss: compiled 60B, every instruction identical except
// that retail keeps the redundant `test esi,esi` at the top of the inlined
// global-list loop (from inlining Rva006FBBE0::find), while this cl propagates
// the preceding non-null test and drops the check. Semantics are identical.
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

BfmeN1034 *Rva006FBE80::find2(int key)
{
	Rva006FBBE0 *node = g_Va00E1835C;
	if (node == 0) {
		Rva006FBBE0 *member = m_member28;
		return member != 0 ? member->find(key) : 0;
	}
	while (node != 0) {
		BfmeN1034 *found = node->m_table.bfmeFind1034F(key);
		if (found != 0)
			return found;
		node = node->m_next;
	}
	return 0;
}
