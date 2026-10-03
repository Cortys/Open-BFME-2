// ??0Rva005CB35A@@QAE@XZ
// partial score=0.95 date=2026-10-03
// ??0Rva005CB35A@@QAE@XZ
// partial score=0.95 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ??0Rva005CB35A@@QAE@XZ @0x005CB35A 100B.
// Class Rva005CB3BE (dtor rowed at 0x005CB3BE: six strings at +0x08..+0x1C
// released through 0x36410, then an 8-byte polymorphic first member through
// 0x22167C). The ctor constructs the 8-byte first member by calling the pinned
// base ctor 0x00221635 with the address of a temporary AsciiString
// "RegionDisplay" (VA 0x00C74D98), lets the temporary unwind through the
// cookie-SEH state machine (states 0 then 2 via 0x36410), installs the
// derived table 0x00C74D90 at +0, then zeroes the six pointer members.
//
// Structure taken verbatim from the matched sibling Rva005E74CF.cpp, which
// has the same shape (SEH prologue, double push ecx, push esi, mov [ebp-0x14],
// temp AsciiString, base ctor, state 2, release) and byte-matches. Declaring
// ~Rva00221635 is REQUIRED: dropping it removes the extra push ecx and the
// body collapses to 96B. The six zeroes are one member subobject so they land
// as a unit after the vptr set, as in Rva005E16DA.cpp.
//
// REMAINING GAP (the whole of it): MSVC /O1 sinks the DIR32 table store
// `mov [esi],0x00C74D90` BELOW all six zero stores; retail emits it first, at
// +0x3F. Everything before that byte is exact (100B, single diff site). Tried
// and refuted: six separate one-pointer subobjects; two three-int subobjects;
// six int scalars; six raw pointers; POD void*[6] zeroed in the body; setting
// the table through a noinline-free helper called first in the body; body
// order swapped; /O2 and /Ot (both over-inline to 121B); /O1 -Ob2 (same).
// Rva005E74CF gets its vptr first only because its two members are an
// immediate store and an `and`, not six identical register zero-stores; with
// six identical `mov [esi+N],edi` the /O1 store scheduler always issues the
// register stores ahead of the constant one.
//
// t=25min model=space-bunny-alpha
#include "ascii_string.h"

class Rva00221635
{
public:
	Rva00221635(int arg);
	~Rva00221635();
	virtual void _pure() = 0;
	int m_4;
};

extern const void *const g_00C74D90[];

struct Rva005CB35AM8
{
	void *m_8;
	void *m_c;
	void *m_10;
	void *m_14;
	void *m_18;
	void *m_1c;
	Rva005CB35AM8()
	{
		m_8 = 0;
		m_c = 0;
		m_10 = 0;
		m_14 = 0;
		m_18 = 0;
		m_1c = 0;
	}
};

class Rva005CB35A : public Rva00221635
{
public:
	Rva005CB35A();

private:
	Rva005CB35AM8 m_08;
};

// ??0Rva005CB35A@@QAE@XZ
Rva005CB35A::Rva005CB35A()
	: Rva00221635((int)&AsciiString("RegionDisplay"))
{
	*(const void **)this = g_00C74D90;
}