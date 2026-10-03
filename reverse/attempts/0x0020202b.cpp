// ?rva0020202B@Rva0020202B@@QAEPAXH@Z
// partial score=0.94 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva0020202B@Rva0020202B@@QAEPAXH@Z
// retail 0x0020202B, 45 bytes. Unlock lane: landing it makes 0x00202E23 ready.
// Fixed-slot pool allocator: counts at +0x17AC, 32-byte slots at +0x208.
// Counts[5] at 0x17AC ends at 0x17C0 (sibling count offset); pool 5x32x32B
// at 0x208 gives (index*32+count)*32 stride matching shl/add/shl/lea shape.
// Neighbours: prev 0x0020200D RetailBenchProfileAllocator, next 0x002025AC.
// Caller 0x00202E23 (226B, too big to show per budget rule) not inspected.
class Rva0020202B
{
public:
	struct Slot
	{
		char data[32];
	};
	char m_pad0[0x208];
	Slot m_pool[160];
	char m_pad1[0x1A4];
	int m_counts[5];
	void* rva0020202B(int index);
};

// ?rva0020202B@Rva0020202B@@QAEPAXH@Z present-unmatched
void* Rva0020202B::rva0020202B(int index)
{
	int* pc = &m_counts[index];
	int count = *pc;
	if (count < 32)
	{
		count++;
		*pc = count;
		return (void*)&m_pool[index * 32 + count];
	}
	return 0;
}
