// ?rva003B3EEA@Rva003B3EEA@@QAEXXZ
// partial score=0.94 date=2026-10-03
// cl: /O1 /G7 /DNDEBUG /MD /EHsc
// ?rva003B3EEA@Rva003B3EEA@@QAEXXZ @0x003B3EEA 31B
// Clears a chain of 20-byte table entries: head index at +0x1C, table at +0xC.
// Each entry links via int at +0x0 and carries a byte flag at +0xC set to 0.
// Evidence: unlock lane all callees rowed, 0x14 imul with +0xC byte store and
// +0x0 next-index load, callers 0x3B695D/0x3B6970 in 0x3B693A, neighbour
// Rva003B3F09Lookup uses same 0x14 entries with table at +0x0C, sibling
// 0x3B3ECB same shape with flag 1 (SIB wall banked 0x94).
struct Rva003B3EEAEntry
{
	int m_next; // +0x00 next index, -1 terminates
	int m_u1; // +0x04 unseen
	int m_u2; // +0x08 unseen
	unsigned char m_flag; // +0x0C cleared to 0
	char m_pad[7]; // +0x0D..+0x13 filler to 0x14 bytes
}; // 0x14 bytes

class Rva003B3EEA
{
public:
	void rva003B3EEA();

private:
	char m_pad0[0x0C]; // +0x00..+0x0B
	Rva003B3EEAEntry *m_entries; // +0x0C
	char m_pad1[0x0C]; // +0x10..+0x1B
	int m_head; // +0x1C
};

// ?rva003B3EEA@Rva003B3EEA@@QAEXXZ present-unmatched
void Rva003B3EEA::rva003B3EEA()
{
	int i = m_head;
	if (i == -1)
		return;
	do {
		m_entries[i].m_flag = 0;
		i = m_entries[i].m_next;
	} while (i != -1);
}
