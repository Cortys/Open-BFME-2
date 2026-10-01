// ?Rva00381618Populate@@YAXPAVGameWindow@@H@Z
// partial score=0.95 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /arch:SSE /G7 /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// Rva00381618 0x00381618 133B: listbox populate from BfmeStringRecord vector.
// Evidence: GadgetListBoxReset 0x003247E5; GadgetListBoxAddEntryText 0x00326BEC;
// BfmeStringRecord copy 0x005DDD40; StringBase copy 0x00037050; releaseBuffer 0x00036E70;
// g_00E022F8 array; callers 0x005AFC40; prev/next stlport_vector_stringrecord.
// ?Rva00381618Populate@@YAXPAVGameWindow@@H@Z present-unmatched

#include "ascii_string.h"
#include "unicode_string.h"

class GameWindow;

void __cdecl GadgetListBoxReset(GameWindow *win);
int __cdecl GadgetListBoxAddEntryText(GameWindow *win, UnicodeString text, int a, int b, int c, bool d);

struct BfmeStringRecord005DDD40
{
	UnicodeString text;
	unsigned int word;
	BfmeStringRecord005DDD40(const BfmeStringRecord005DDD40 &other);
};

struct Rva00381618Vec
{
	BfmeStringRecord005DDD40 *m_begin;
	BfmeStringRecord005DDD40 *m_end;
	BfmeStringRecord005DDD40 *m_cap;
};

extern Rva00381618Vec g_00E022F8[2];

// ?Rva00381618Populate@@YAXPAVGameWindow@@H@Z present-unmatched
void __cdecl Rva00381618Populate(GameWindow *win, int idx)
{
	if (!win)
		return;
	if ((unsigned int)idx >= 2)
		return;
	GadgetListBoxReset(win);
	Rva00381618Vec *vec = &g_00E022F8[idx];
	for (BfmeStringRecord005DDD40 *p = vec->m_begin; p != vec->m_end; ++p)
	{
		BfmeStringRecord005DDD40 rec(*p);
		GadgetListBoxAddEntryText(win, rec.text, rec.word, -1, -1, true);
	}
}
