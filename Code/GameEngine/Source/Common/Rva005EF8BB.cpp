// cl: /O1 /MD /EHsc /D_CRTIMP=
// Address-named range teardown at 0x005EF8BB (63 bytes). Target calls the
// rowed Rva005EF5EFClear range destroyer, then null-guards the same buffer
// release through 0x00030830. Scope-owned release preserves cleanup if range
// destruction throws. Element/application identity is intentionally opaque.
struct Rva005F0647;
void __cdecl Rva005EF5EFClear(Rva005F0647 *first, Rva005F0647 *last);
namespace _STL { void __cdecl free(void *block); }
class Rva005EF8BB
{
public:
	void rva005EF8BB();

	Rva005F0647 *m_first;
	Rva005F0647 *m_last;
};
// ?Rva005EF8BBGuard::Rva005EF8BBGuard present-unmatched
// ?Rva005EF8BBGuard::~Rva005EF8BBGuard present-unmatched
struct Rva005EF8BBGuard
{
	Rva005EF8BB *m_owner;
	Rva005EF8BBGuard(Rva005EF8BB *o) : m_owner(o) {}
	~Rva005EF8BBGuard() { if (m_owner->m_first != 0) _STL::free(m_owner->m_first); }
};
void Rva005EF8BB::rva005EF8BB()
{
	{
		Rva005EF8BBGuard guard(this);
		Rva005EF5EFClear(m_first, m_last);
	}
}
