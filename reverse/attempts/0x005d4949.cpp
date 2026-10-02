// ?rva005D4949@Rva005D4949@@QAEX_N@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /G7 /MD
// ?rva005D4949@Rva005D4949@@QAEX_N@Z retail 0x005D4949 66B
// Evidence: unlock callee of 0x005D49CD jmp; same Fire shape as Rva00527890Move 77B via rowed 0x005277D9 with prefix from +8 else empty plus TheRva00222A8BTarget plus SetEnabled literal; guard m_24 vs bool arg
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
void __cdecl Rva005277D9Fire(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, bool *flagPtr);
struct Rva005D4949Inner
{
	char m_pad8[8];
	char m_name[1];
};
class Rva005D4949
{
public:
	void rva005D4949(bool v);
private:
	char m_pad00[4];
	void *m_level04;
	Rva005D4949Inner *m_inner08;
	char m_pad0C[0x24 - 0x0C];
	bool m_24;
};
// ?rva005D4949@Rva005D4949@@QAEX_N@Z present-unmatched
void Rva005D4949::rva005D4949(bool v)
{
	if (v == m_24)
		return;
	const char *prefix = m_inner08 ? m_inner08->m_name : g_Rva0107301CEmptyString;
	Rva005277D9Fire(TheRva00222A8BTarget, m_level04, prefix, "SetEnabled", &v);
	m_24 = v;
}
