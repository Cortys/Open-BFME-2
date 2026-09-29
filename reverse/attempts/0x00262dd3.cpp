// ?rva00262DD3@Rva00262DD3@@QAE_NPAURva00262DD3Arg@@@Z
// partial score=0.93 date=2026-09-29
// ?rva00262DD3@Rva00262DD3@@QAE_NPAURva00262DD3Arg@@@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
// ?rva00262DD3@Rva00262DD3@@QAE_NPAURva00262DD3Arg@@@Z @0x00262DD3 81B. Predicate
// with two sentinel-guarded ID loads (null -> 999999) compared against 26,
// then identity check of +0x198/+0x19C against arg +0x74. Evidence: callers
// at 0x002F4055 and 0x00498DF3 test al; neighbours are AIUpdateInterface TUs.
struct Rva00262DD3Inner {
	char m_pad00[4];
	int m_val;
};
struct Rva00262DD3Holder {
	char m_pad00[4];
	Rva00262DD3Inner *m_04;
	char m_pad08[0x48];
	Rva00262DD3Inner *m_50;
};
struct Rva00262DD3Arg {
	char m_pad00[0x74];
	int m_74;
};
class Rva00262DD3 {
public:
	bool rva00262DD3(Rva00262DD3Arg *arg);
private:
	char m_pad00[0x30];
	Rva00262DD3Holder *m_30;
	char m_pad34[0x164];
	int m_198;
	int m_19c;
};
// ?rva00262DD3@Rva00262DD3@@QAE_NPAURva00262DD3Arg@@@Z present-unmatched
bool Rva00262DD3::rva00262DD3(Rva00262DD3Arg *arg)
{
	int esi = arg->m_74;
	int edx = m_30->m_50 ? m_30->m_50->m_val : 999999;
	if (edx == 26)
		goto check;
	int eax = m_30->m_04 ? m_30->m_04->m_val : 999999;
	if (eax != 26)
		return false;
check:
	if (m_198 != esi && m_19c != esi)
		return false;
	return true;
}
