// ?rva0028F6EB@Rva0028F6EB@@QAEHXZ
// partial score=0.88 date=2026-09-29
// ?rva0028F6EB@Rva0028F6EB@@QAEHXZ
// partial score=0.88 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0028F6EB@Rva0028F6EB@@QAEHXZ — retail 0x0028F6EB, 72 bytes.
// SWAR popcount of the four dwords at +0x00..+0x0C, summed into eax.
// Evidence: three E8 callers (0x002914FC, 0x0029259D, 0x00494CA4); caller
// 0x00494C81 tests the same four dwords as a bitfield right after the call.
// Owner unproven: honest address name. New TU beside the 0x0028F68F
// neighbour with its // cl: line.

class Rva0028F6EB
{
public:
	int rva0028F6EB();

private:
	unsigned int m_words[4];
};

// ?rva0028F6EB@Rva0028F6EB@@QAEHXZ present-unmatched
int Rva0028F6EB::rva0028F6EB()
{
	int count = 0;
	for (unsigned int i = 0; i < 4; i++)
	{
		unsigned int v = m_words[i];
		v = v - ((v >> 1) & 0x55555555);
		v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
		count += (((v + (v >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	}
	return count;
}
