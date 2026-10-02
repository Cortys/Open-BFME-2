// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
//
// ?rva005FE047@Rva005FE047@@QAEXXZ @ 0x005FE047 66B
// First-fire guard at +0x34 with player-name fallback and APT Fire for SetPlayerNameVisibility.
// Evidence: refcount inc at +0x34 with jne return; bool false at ebp-1 from al; holder at +8 with +8 name or g_Rva0107301CEmptyString; level at +4; Fire 0x005277D9 row with TheRva00222A8BTarget and string literal; callers 0x005FE140 0x005FE1EA 0x005FE6A4; precedent Rva005F921FButton.cpp holder+8-empty pattern.
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
void __cdecl Rva005277D9Fire(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, bool *flagPtr);

struct Rva005FE047Holder
{
	char m_pad[8];
	char m_name[1];
};

class Rva005FE047
{
public:
	void rva005FE047();
	void rva005FE00C();
private:
	char m_pad00[4];
	void *m_level04;
	Rva005FE047Holder *m_holder08;
	char m_pad0C[0x34 - 0x0C];
	int m_count34;
};

void Rva005FE047::rva005FE047()
{
	if (m_count34++ != 0)
		return;
	bool flag = false;
	const char *name = m_holder08 ? (const char *)m_holder08 + 8 : g_Rva0107301CEmptyString;
	Rva005277D9Fire(TheRva00222A8BTarget, m_level04, name, "SetPlayerNameVisibility", &flag);
}

void Rva005FE047::rva005FE00C()
{
	if (--m_count34 != 0)
		return;
	bool flag = true;
	const char *name = m_holder08 ? (const char *)m_holder08 + 8 : g_Rva0107301CEmptyString;
	Rva005277D9Fire(TheRva00222A8BTarget, m_level04, name, "SetPlayerNameVisibility", &flag);
}
