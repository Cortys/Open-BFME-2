// cl: /O1 /MD
// ?rva004E592C@Rva004E592C@@QAEXPAURva004E592CPair@@@Z @0x004E592C (34B)
// __thiscall method over a node-pointer range [m_first, m_last): forwards to
// the rowed Rva004E588DFill with the pair's (init, stamp); the out[2] result
// is stack scratch. Evidence: chain lane, single caller 0x004E616F;
// callee row 0x004E588D; prev/next share // cl: /O1 /MD.
struct Rva004E588DNode {
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
};
void __cdecl Rva004E588DFill(int *out, Rva004E588DNode **first, Rva004E588DNode **last, int acc, int stamp);
struct Rva004E592CPair {
	int m_0;
	int m_4;
};
class Rva004E592C {
	Rva004E588DNode **m_first;
	Rva004E588DNode **m_last;
public:
	void rva004E592C(Rva004E592CPair *pair);
};

void Rva004E592C::rva004E592C(Rva004E592CPair *pair)
{
	int out[2];
	Rva004E588DFill(out, m_first, m_last, pair->m_0, pair->m_4);
}
