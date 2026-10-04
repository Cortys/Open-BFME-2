// ?rva005E0E99@Rva005E0E99@@QAEX_N@Z
// partial score=0.98 date=2026-10-04
// ?rva005E0E99@Rva005E0E99@@QAEX_N@Z
// Chain via rowed Fire 0x005277D9 with level +0x08 prefix +0x0C from +8 else
// g_Rva0107301CEmptyString plus flags +0x40 +0x41 and incoming bool param.
// Same Fire shape as Rva005E1008Method.cpp; ret 4 bool.
//
// /O2 (not the sibling's /O1) is what puts the incoming bool in ebx: retail
// opens `push ebx / mov bl,[esp+8]`, so the parameter is loaded after its own
// save push and stays in bl across the call, with no reload in the tail. /O1
// emits a push ebp frame because the addressable local needs a stable home.
//
// The flag out-param is UNINITIALIZED, not `bool flag = b`: retail takes its
// address (`lea ecx,[esp+0xc]`) without any store into the slot, which an
// initialized local cannot produce because cl must materialize the value first
// (`mov [esp+0xc],bl`, the 4-byte tail the banked body carried). That store
// was the whole 77B-vs-72B gap; dropping the initializer gives 73B.
// cl: /O2 /G7 /MD /arch:SSE
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
void __cdecl Rva005277D9Fire(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, bool *flagPtr);

struct Rva005E0E99Inner
{
	char m_pad8[8];
	char m_name[1];
};

class Rva005E0E99
{
public:
	void rva005E0E99(bool b);
private:
	char m_pad00[8];
	void *m_level08;
	Rva005E0E99Inner *m_inner0C;
	char m_pad10[0x40 - 0x10];
	bool m_flag40;
	bool m_flag41;
};

// ?rva005E0E99@Rva005E0E99@@QAEX_N@Z present-unmatched
void Rva005E0E99::rva005E0E99(bool b)
{
	if (b == m_flag41)
		return;
	if (m_flag40 != 0)
	{
		bool flag;
		const char *prefix = m_inner0C ? m_inner0C->m_name : g_Rva0107301CEmptyString;
		Rva005277D9Fire(TheRva00222A8BTarget, m_level08, prefix, "Enable", &flag);
	}
	m_flag41 = b;
}