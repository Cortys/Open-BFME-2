// cl: /O1 /G7 /MD
// ?rva00527890@Rva00527890@@QAEXH@Z @ 0x00527890 (77B): guarded Move fire via rowed 0x005277D9 with bool v==1 and prefix from +8 else empty. Evidence: callees rowed 0x005277D9; strings Move empty fallback g_Rva0107301CEmptyString; global TheRva00222A8BTarget; guard m_10 vs arg; caller 0x002D66FD.
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
void __cdecl Rva005277D9Fire(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, bool *flagPtr);
struct Rva00527890Inner
{
	char m_pad8[8];
	char m_name[1];
};
class Rva00527890
{
public:
	void rva00527890(int v);
private:
	char m_pad00[4];
	void *m_level04;
	Rva00527890Inner *m_inner08;
	char m_pad0C[0x10 - 0x0C];
	int m_10;
};
void Rva00527890::rva00527890(int v)
{
	if (v == m_10)
		return;
	bool flag = (v == 1);
	const char *prefix = m_inner08 ? m_inner08->m_name : g_Rva0107301CEmptyString;
	Rva005277D9Fire(TheRva00222A8BTarget, m_level04, prefix, "Move", &flag);
	m_10 = v;
}
