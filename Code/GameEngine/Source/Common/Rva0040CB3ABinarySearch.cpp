// cl: /O1
// ?find@Rva0040CB3AIndexedField@@QBEHH@Z @0x0040CB3A 63B
// Binary search over sorted 8-byte entries at +0x40/+0x44 keyed by first dword; returns index or -1.
// Evidence: 3 callers incl 0x0040CBBF and 0x0040CBE5; shared +0x40/+0x44 vector layout with twin getters 0x0040CC0E/0x0040CB2C.
struct Rva0040CB3AEntry
{
	int first;
	int second;
};

class Rva0040CB3AIndexedField
{
public:
	int find(int key) const;
private:
	char m_pad[0x40];
	Rva0040CB3AEntry *m_begin;
	Rva0040CB3AEntry *m_end;
};

int Rva0040CB3AIndexedField::find(int key) const
{
	const Rva0040CB3AEntry *low = m_begin;
	const Rva0040CB3AEntry *high = m_end;
	while (low != high) {
		const Rva0040CB3AEntry *mid = low + (high - low) / 2;
		if (key == mid->first)
			return mid - m_begin;
		if (key > mid->first)
			low = mid + 1;
		else
			high = mid;
	}
	return -1;
}
