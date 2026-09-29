// ?rva005EF8BB@Rva005EF8BB@@QAEXXZ
// partial score=0.94 date=2026-09-29
// ?rva005EF8BB@Rva005EF8BB@@QAEXXZ
// partial score=0.94 date=2026-09-29
// cl: /O1 /MD /EHsc
struct Rva005F0647;
void __cdecl Rva005EF5EFClear(Rva005F0647 *first, Rva005F0647 *last);
extern "C" void __cdecl free(void *block) throw();
class Rva005EF8BB
{
public:
	void rva005EF8BB();

	Rva005F0647 *m_first;
	Rva005F0647 *m_last;
};
struct Rva005EF8BBGuard
{
	Rva005EF8BB *m_owner;
	Rva005EF8BBGuard(Rva005EF8BB *o) : m_owner(o) {}
	~Rva005EF8BBGuard() { if (m_owner->m_first != 0) free(m_owner->m_first); }
};
void Rva005EF8BB::rva005EF8BB()
{
	{
		Rva005EF8BBGuard guard(this);
		Rva005EF5EFClear(m_first, m_last);
	}
}
