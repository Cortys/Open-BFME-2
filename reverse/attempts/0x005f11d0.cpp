// ?rva005F11D0@Rva005F11D0@@QAEXXZ
// partial score=0.94 date=2026-09-29
// ?rva005F11D0@Rva005F11D0@@QAEXXZ
// partial score=0.94 date=2026-09-29
// cl: /O1 /MD /EHs
struct Rva005F0647;
void __cdecl Rva005EF5EFClear(Rva005F0647 *first, Rva005F0647 *last);
extern "C" void __cdecl free(void *block) throw();
class Rva005F11D0
{
public:
	void rva005F11D0();

	Rva005F0647 *m_first;
	Rva005F0647 *m_last;
};
struct Rva005F11D0Guard
{
	Rva005F11D0 *m_owner;
	Rva005F11D0Guard(Rva005F11D0 *o) : m_owner(o) {}
	~Rva005F11D0Guard() { if (m_owner->m_first != 0) free(m_owner->m_first); }
};
void Rva005F11D0::rva005F11D0()
{
	{
		Rva005F11D0Guard guard(this);
		Rva005EF5EFClear(m_first, m_last);
	}
}
