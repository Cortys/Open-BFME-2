// cl: /O1 /MD /EHs /D_CRTIMP=
// Target 0x005F11D0 (63 bytes) destroys the first/end range via rowed
// Rva005EF5EFClear, then frees the first pointer through 0x00030830. Scoped
// ownership preserves the target unwind transition and exception cleanup.
// Same observed operations as 0x005EF8BB; application/element name unknown.
struct Rva005F0647;
void __cdecl Rva005EF5EFClear(Rva005F0647 *first, Rva005F0647 *last);
namespace _STL { void __cdecl free(void *block); }
class Rva005F11D0
{
public:
	void rva005F11D0();

	Rva005F0647 *m_first;
	Rva005F0647 *m_last;
};
// ?Rva005F11D0Guard::Rva005F11D0Guard present-unmatched
// ?Rva005F11D0Guard::~Rva005F11D0Guard present-unmatched
struct Rva005F11D0Guard
{
	Rva005F11D0 *m_owner;
	Rva005F11D0Guard(Rva005F11D0 *o) : m_owner(o) {}
	~Rva005F11D0Guard() { if (m_owner->m_first != 0) _STL::free(m_owner->m_first); }
};
void Rva005F11D0::rva005F11D0()
{
	{
		Rva005F11D0Guard guard(this);
		Rva005EF5EFClear(m_first, m_last);
	}
}
