// cl: /O1 /GX-
//
// ?rva005C7A29@Rva005C7A29@@QAEX_N@Z @0x005C7A29 (92B).
// AutoAbility overlay show/hide via AptCall 0x0050E9FE with _show/_hide.
// Skips when +0x4C clear or state at +0x54 already equals the bool arg.
// Prefix is +0x0C plus 8 else g_Rva0107301CEmptyString; level is +0x08.
// Evidence: strings _show _hide SetAutoAbilityOverlayState; externs
// g_Rva0107301CEmptyString and TheRva00222A8BTarget; caller 0x005C7C5D
// adjusts this by +4 then tail-jmps; callee row Rva0050E9FE.cpp.
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
int Rva0050E9FEAptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, const char **a0ptr);

class Rva005C7A29
{
public:
	void rva005C7A29(bool show);

private:
	char _pad0[8];
	void *m_08;
	void *m_0C;
	char _pad1[0x3C];
	bool m_4C;
	char _pad2[7];
	bool m_54;
};

void Rva005C7A29::rva005C7A29(bool show)
{
	if (!m_4C)
		return;
	if (show == m_54)
		return;
	const char *which = "_show";
	if (!show)
		which = "_hide";
	const char *prefix = m_0C ? (const char *)((char *)m_0C + 8) : g_Rva0107301CEmptyString;
	Rva0050E9FEAptCall(TheRva00222A8BTarget, m_08, prefix, "SetAutoAbilityOverlayState", &which);
	m_54 = show;
}
