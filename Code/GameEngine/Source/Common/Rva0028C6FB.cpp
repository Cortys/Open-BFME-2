// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0028C6FB@Rva0028C6FB@@QAEPAXI@Z @0x0028C6FB 42B
// Bit-present table lookup: if bit (idx&31) of word (idx>>5) at +0 is set return table[idx] else 0.
// Evidence: test [this+word*4] mask plus mov eax [idx*4+VA 0x00DC828C]; sole caller 0x00292414;
// neighbours V3PolyCopyCtors and ConstIntGetters5 give TU and flags.
#define BfmeTable0028C6FB ((void **)0x00DC828C)

class Rva0028C6FB
{
public:
	void *rva0028C6FB(unsigned int idx);

private:
	unsigned int m_bits[8];
};

void *Rva0028C6FB::rva0028C6FB(unsigned int idx)
{
	return (m_bits[idx >> 5] & (1u << (idx & 31))) ? BfmeTable0028C6FB[idx] : 0;
}
