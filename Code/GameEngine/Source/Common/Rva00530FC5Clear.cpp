// cl: /O1 /DNDEBUG /MD
// ?rva00530FC5@Rva00530FC5@@QAEXXZ, retail 0x00530FC5, 67 bytes.
// Bitmask-guarded clear of 128B chunks: m_count at +0, m_data at +4, m_bits at +8.
// bitsEnd = m_bits + (m_count>>5); early out when empty; loop from the top clearing
// 128B via memset only when the bit word is non-zero then clearing the word.
// Callers 0x00533F3D 0x00534031 0x005341B9 in 0x00533BEC 1759B unclaimed.
// Neighbours Disp32FloatGetters/Disp8ByteOneSetters carry no // cl: line so defaults apply.
void *__cdecl ji_006291ae(void *dest, int val, unsigned int count);
#pragma comment(linker, "/alternatename:?ji_006291ae@@YAPAXPAXHI@Z=?ji_006291ae@@YAXXZ")

class Rva00530FC5
{
public:
	void rva00530FC5();
private:
	unsigned int m_count;
	int *m_data;
	unsigned int *m_bits;
};

void Rva00530FC5::rva00530FC5()
{
	unsigned int count = m_count;
	int *base = m_data;
	int *end = base + count;
	unsigned int *bits = m_bits;
	unsigned int *bitsEnd = bits + (count >> 5);
	if (bitsEnd == bits)
		return;
	while (true) {
		--bitsEnd;
		end -= 32;
		if (*bitsEnd != 0) {
			ji_006291ae(end, 0, 128);
			*bitsEnd = 0;
		}
		if (bitsEnd == m_bits)
			break;
	}
}
