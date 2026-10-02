// cl: /MD
//
// Profile::RemovePatternEntry, candidate retail 0x006C5310 (103 bytes,
// ghidra). BFME2-new helper (no ZH donor): unlinks one pattern entry from
// Profile::firstPatternEntry, frees its pattern string and the entry itself
// with GlobalFree, then repairs Profile::lastPatternEntry. Called by
// Profile::StartRange when a pattern's frame budget runs out.

extern "C" __declspec(dllimport) int __stdcall GlobalFree(void *mem);

class Profile
{
private:
	struct PatternListEntry
	{
		PatternListEntry *next;   // +0x00
		bool isActive;            // +0x04
		char *pattern;            // +0x08
		int framesLeft;           // +0x0C, <= 0: unlimited
	};

	static void RemovePatternEntry(PatternListEntry *entry);

	static PatternListEntry *firstPatternEntry;
	static PatternListEntry *lastPatternEntry;
};

// Profile::lastPatternEntry: matched DIR32 witnesses (w=2) place this
// zero-initialized four-byte pointer at VA 0x00E0C1E0 (.data BSS); it ends at
// the next known global, firstPatternEntry at VA 0x00E0C1E4.
Profile::PatternListEntry *Profile::lastPatternEntry;

// ?RemovePatternEntry@Profile@@CAXPAUPatternListEntry@1@@Z
void Profile::RemovePatternEntry(PatternListEntry *entry)
{
	PatternListEntry **link = &firstPatternEntry;
	if (*link)
	{
		do
		{
			if (*link == entry)
				break;
			link = (PatternListEntry **)*link;
		} while (*link);
	}
	PatternListEntry *victim = *link;
	*link = victim->next;
	if (victim->pattern)
		GlobalFree(victim->pattern);
	GlobalFree(victim);
	if (firstPatternEntry)
	{
		PatternListEntry *last = firstPatternEntry;
		while (last->next)
			last = last->next;
		lastPatternEntry = last;
	}
	else
		lastPatternEntry = 0;
}
