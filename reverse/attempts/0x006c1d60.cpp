// ?rva006C1D60@Rva006C1D60@@QAE_NI_N@Z
// partial score=0.92 date=2026-10-04
// ?rva006C1D60@Rva006C1D60@@QAE_NI_N@Z 0x006C1D60 (93B, chain from 0x006C18A0)
// Enable-guarded hash-table find-then-remove wrapper around Rva006C1850.
// Banked 0.90 had the whole body behind early returns; retail keeps the
// m_enabled test as a COLD forward branch to a shared tail (`mov al,[ecx+0x680];
// test al,al; je <end>`), which only the outer `if (m_enabled) { ... }` form
// reproduces. That form is now byte-identical through +0x9 (the enabled
// branch itself), where the previous bank diverged at +0x8 (jne vs je).
// Residual: the `!table` return binds edi and is emitted inline
// (`jne over; xor al,al; pop esi; ret`) where retail forwards it to the shared
// pop-edi false block; the compiler also rotates the key loop. Every guard
// spelling that merges the false exits instead hoists the callee-saves and
// fuses the table load, so the two are not simultaneously reachable.
struct Rva006C1850Node
{
	unsigned int m_key;
	void *m_value;
	Rva006C1850Node *m_next;
};
class Rva006C1850
{
public:
	bool rva006C18A0(unsigned int key, bool freeValue);
	friend class Rva006C1D60;
private:
	Rva006C1850Node **m_table;
	int m_pad04;
	unsigned int m_bucketCount;
	int m_pad0C;
	int m_count;
	int m_pad14;
	void (__cdecl *m_freeFn)(void *block, void *allocator);
	void *m_allocator;
};
class Rva006C1D60
{
public:
	bool rva006C1D60(unsigned int key, bool freeValue);
private:
	unsigned char m_pad[0x680];
	bool m_enabled;
	unsigned char m_pad681[3];
	Rva006C1850 m_table;
};
bool Rva006C1D60::rva006C1D60(unsigned int key, bool freeValue)
{
	if (m_enabled)
	{
		Rva006C1850 *t = &m_table;
		Rva006C1850Node **table = t->m_table;
		if (!table)
			return false;
		int h = (key >> 3) % t->m_bucketCount;
		Rva006C1850Node *node = table[h];
		if (!node)
			return false;
		for (; node != 0; node = node->m_next)
			if (node->m_key == key)
				break;
		if (!node)
			return false;
		bool result = true;
		t->rva006C18A0(key, freeValue);
		return result;
	}
	return false;
}
