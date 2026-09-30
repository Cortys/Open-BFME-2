// cl: /O1 /MD
//
// ?rva00512CE9@Rva00512CE9@@QAEXH_N@Z, retail 0x00512CE9, 94 bytes.
// Kick-button UI: formats player index via sprintf %d then invokes Apt
// ShowKickButton/HideKickButton with 1 plus buffer plus 0s plus owner at
// +0x274 via TheAptPlayer at 0x9FE4CC (SubsystemInterface registers it)
// and stores bool to +0x286 indexed array. Callers at 0x4D45F6 etc.
// Flags /O1 /MD (EBP frame, sprintf IAT, no EH, no STL).

extern "C" __declspec(dllimport) int __cdecl sprintf(char *buffer, const char *format, ...);

class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern Rva00222A8BTarget *g_Va009FE4CC;

class Rva00512CE9
{
public:
	void rva00512CE9(int player, bool show);
private:
	char m_pad00[0x274];
	void *m_274;
	char m_pad278[0x286 - 0x278];
	bool m_286[8];
};

void Rva00512CE9::rva00512CE9(int player, bool show)
{
	char buf[32];
	sprintf(buf, "%d", player);
	const char *which = show ? "ShowKickButton" : "HideKickButton";
	g_Va009FE4CC->invoke(m_274, which, 1, buf, 0, 0, 0, 0);
	m_286[player] = show;
}
