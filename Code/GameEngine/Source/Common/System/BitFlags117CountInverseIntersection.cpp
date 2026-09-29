// cl: /O1 /DNDEBUG /MD
//
// ?countInverseIntersection@?$BitFlags@$0HF@@@QBEHABV1@@Z @0x0033AE53 89B
// BitFlags<117> (ModelConditionSetFlags) inverse-intersection popcount over
// four dwords. Evidence: pinned caller findBestInfoSlow for
// SparseMatchFinder<UModelConditionInfo, BitFlags<$0HF>> at 0x0033BDF8 calls
// this (second call, tie-break) next to countIntersection at 0x0033ADFC;
// retail computes (~mine & theirs) SWAR popcount summed over 4 words.

template <int NUMBITS>
class BitFlags
{
public:
	int countInverseIntersection(const BitFlags &that) const;

private:
	unsigned m_words[4];
};

template <>
int BitFlags<117>::countInverseIntersection(const BitFlags &that) const
{
	int total = 0;
	const unsigned *mine = m_words;
	const unsigned *theirs = that.m_words;
	for (unsigned i = 0; i < 4; i++) {
		unsigned v = (~mine[i]) & theirs[i];
		v = v - ((v >> 1) & 0x55555555);
		v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
		v = (v + (v >> 4)) & 0x0F0F0F0F;
		total += (int)((v * 0x01010101u) >> 24);
	}
	return total;
}
