// ?framesUntilNext@ObjectSMCHelper@@AAEHXZ
// partial score=0.95 date=2026-10-03
// ?rva004DE700@ObjectSMCHelper@@QAEHXZ
// partial score=0.95 date=2026-10-01
// ?rva004DE700@ObjectSMCHelper@@QAEHXZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHs /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc /Ireference/shims/bfmelist
// stlport
// ?rva004DE700@ObjectSMCHelper@@QAEHXZ, retail 0x004DE700, 77 bytes.
// Donor: reference/open-bfme-1/game/GameEngine/Source/GameLogic/Object/Helper/ObjectSMCHelperFramesUntilNext.cpp plus UPDATE_SLEEP 0x3fffffff.
// Evidence: unlock lane, TheGameLogic 0x009FE78C slot 0x40 frame, m_timers list at +0x20, callers 0x004DE7C2 0x004DE85F, next ObjectSMCHelperDtor /O1 list.
class GameLogic
{
public:
	unsigned char m_pad[0x40];
	int m_frame;
};
extern GameLogic *TheGameLogic;
struct TimerNode
{
	TimerNode *m_next;
	TimerNode *m_prev;
	int m_field8;
	unsigned m_wake;
};
struct TimerList
{
	TimerNode *m_node;
	bool empty() const { return m_node->m_next == m_node; }
	TimerNode *begin() const { return m_node->m_next; }
	TimerNode *end() const { return m_node; }
};
// ?rva004DE700@ObjectSMCHelper@@QAEHXZ present-unmatched
class ObjectSMCHelper
{
public:
	int rva004DE700();
private:
	unsigned char m_pad[0x20];
	TimerList m_timers;
};
int ObjectSMCHelper::rva004DE700()
{
	if (m_timers.empty())
		return 0x3fffffff;
	int frame = TheGameLogic->m_frame;
	unsigned minWake = 0x5f5e0ff;
	for (TimerNode *n = m_timers.begin(); n != m_timers.end(); n = n->m_next)
	{
		volatile int dummy = n->m_field8;
		unsigned w = n->m_wake;
		minWake = w < minWake ? w : minWake;
	}
	int d = (int)(minWake - (unsigned)frame);
	if (d > 0)
		return d;
	return 1;
}
