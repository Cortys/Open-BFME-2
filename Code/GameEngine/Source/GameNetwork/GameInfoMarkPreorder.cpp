// cl: /O1 /DNDEBUG /MD /EHsc
// ?markPlayerAsPreorder@GameInfo@@QAEXH@Z @0x003FF1FE (26B):
// GameInfo::markPlayerAsPreorder. BFME1 GameInfo.cpp donor verbatim:
// bounds 0..7 then m_preorderMask |= 1<<index with mask at +0x08.
// Three callers. No callees.

typedef int Int;

enum { MAX_SLOTS = 8 };

class GameInfo
{
public:
	void markPlayerAsPreorder(Int index);

private:
	char m_pad[0x08];
	Int m_preorderMask;   // +0x08
};

void GameInfo::markPlayerAsPreorder(Int index)
{
	if (index >= 0 && index < MAX_SLOTS)
		m_preorderMask |= 1 << index;
}
