// ?Rva002D9686Get@@YIHPBUWeightedSoundRange@@I@Z
// partial score=0.93 date=2026-10-01
// ?Rva002D9686Get@@YIHPBUWeightedSoundRange@@I@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD
// ?Rva002D9686Get@@YIHPBUWeightedSoundRange@@I@Z, retail 0x002D9686, 77 bytes.
// Donor: reference/open-bfme-1/game/GameEngine/Source/Common/Audio/AudioEventRTSWeightedChoice.cpp bfmeWeightedChoiceB2430 Audio path.
// Evidence: unlock lane, callees rowed GetGameAudioRandomValue, callers 0x002DA7A3 0x002DA96A 0x002DAA31, prev Rva002D9608AudioCheck /O1 /MD.
extern int GetGameAudioRandomValue(int lo, int hi, char *file, int line);
struct WeightedSoundEntry
{
	void *m_name;
	unsigned m_weight;
};
struct WeightedSoundRange
{
	WeightedSoundEntry *m_begin;
	WeightedSoundEntry *m_end;
};
// ?Rva002D9686Get@@YIHPBUWeightedSoundRange@@I@Z present-unmatched
int __fastcall Rva002D9686Get(const WeightedSoundRange *range, unsigned totalWeight)
{
	unsigned w = totalWeight;
	if (!(w > 0))
		return -1;
	unsigned remainingWeight = GetGameAudioRandomValue(0, w - 1, "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\Common\\Audio\\AudioEventRTS.cpp", 58);
	WeightedSoundEntry *begin = range->m_begin;
	WeightedSoundEntry *end = range->m_end;
	WeightedSoundEntry *soundEntry = begin;
	if (soundEntry != end)
	{
		do
		{
			unsigned wgt = soundEntry->m_weight;
			if (remainingWeight < wgt)
				goto found;
			remainingWeight -= wgt;
			++soundEntry;
		} while (soundEntry != end);
		return 0;
	}
found:
	if (soundEntry == end)
		return 0;
	return (int)(soundEntry - begin);
}
