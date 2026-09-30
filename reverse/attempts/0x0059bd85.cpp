// ?Rva0059BD85Find@@YG_NPAURange0059BD85@@HPAX@Z
// partial score=0.9 date=2026-09-30
// ?Rva0059BD85Find@@YG_NPAURange0059BD85@@HPAX@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /MD
// ?Rva0059BD85Find@@YG_NPAURange0059BD85@@HPAX@Z @0x0059BD85 (52B)
// Stdcall range find over 20-byte stride comparing first field with key.
// Count via byte diff idiv 0x14 then unsigned index loop with jb. Middle
// arg unused but kept for ret 0xC. Caller 0x0059C7BC. Evidence leaf lane.
struct Elem0059BD85
{
	void *m_key;
	char m_pad[16];
};
struct Range0059BD85
{
	Elem0059BD85 *m_begin;
	Elem0059BD85 *m_end;
};
// ?Rva0059BD85Find@@YG_NPAURange0059BD85@@HPAX@Z present-unmatched
bool __stdcall Rva0059BD85Find(Range0059BD85 *range, int unused, void *key)
{
	Elem0059BD85 *begin = range->m_begin;
	Elem0059BD85 *end = range->m_end;
	int count = (char *)end - (char *)begin;
	count /= 0x14;
	unsigned int i = 0;
	if ((unsigned int)count == 0)
		return false;
	do {
		if (begin[i].m_key == key)
			return true;
		i++;
	} while (i < (unsigned int)count);
	return false;
}
