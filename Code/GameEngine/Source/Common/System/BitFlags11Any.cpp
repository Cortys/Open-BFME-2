// cl: /O1 /DNDEBUG /MD
//
// ?any@?$BitFlags@$0L@@@QBE_NXZ @0x0023C58B, 20B.
// BitFlags<11>::any() (DisabledMaskType::any). Retail loops one dword and
// returns true when the word is non-zero, false otherwise.
// Evidence: callers pass Object+0x1C8 (the disabled mask): 0x0027532F
// lea esi,[eax+0x1C8], 0x005891A3 add ecx,0x1C8, 0x00245ACB lea ecx,[eax+0x1C8].
// Donor: ZH BitFlags::any() via bitset plus BFME2 BitFlags<11> one-word layout
// (BitFlags11DisabilityCtors.cpp proves DISABLED_COUNT 11). Sibling shape:
// BitFlags69Test.cpp test() over seven words; this is the one-word any().

template <int N>
class BitFlags
{
public:
	bool any() const;

private:
	unsigned m_words[1];
};

template <>
bool BitFlags<11>::any() const
{
	const unsigned *mine = m_words;
	for (unsigned i = 0; i < 1; i++) {
		if (mine[i] != 0)
			return true;
	}
	return false;
}
