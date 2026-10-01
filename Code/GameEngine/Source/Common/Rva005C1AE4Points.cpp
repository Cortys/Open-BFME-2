// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHs
// ?rva005C1AE4@Rva005C1A36@@QAEHH@Z @0x005C1AE4 73B
// Slot 2 of Rva005C1A36's vtable 0x008743DC: the Points value for a faction
// index. Builds a by-value AsciiString from the faction table 0x009BE9B0,
// fetches the UserPreferences from the object held at +0x2C through its
// slot 2 (0x08), and calls the rowed Points getter 0x005358C3.
// Retail keeps the argument temporary live (state 0) across the slot-2 call
// and disarms it only before the final call. A direct `m_held->v2()->...`
// disarms before the slot-2 call (the banked 0.90 attempt); an inline
// accessor gives retail's order. Retail also keeps that accessor out of line
// at 0x005C1A85 (8B, `mov ecx,[ecx+0x2c]; mov eax,[ecx]; jmp [eax+8]`, no
// references).
#include "ascii_string.h"


class UserPreferences
{
public:
	int rva005358C3(AsciiString arg);
};

class Holder
{
public:
	virtual void v0();
	virtual void v1();
	virtual UserPreferences *v2();
};

class Rva005C1A36
{
public:
	virtual void v0();
	virtual void v1();
	virtual int v2(int idx);
	int rva005C1AE4(int idx);
	UserPreferences *prefs() { return m_held->v2(); }
private:
	char m_pad[0x28];
	Holder *m_held;
};

static const char *kFactions[] = { "Men", "Elves", "Dwarves", "Isengard", "Mordor", "Wild" };

int Rva005C1A36::rva005C1AE4(int idx)
{
	return prefs()->rva005358C3(AsciiString(kFactions[idx]));
}
