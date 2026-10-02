// ?rva0057CA78@Rva0057CA78@@QAEHH@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva0057CA78@Rva0057CA78@@QAEHH@Z retail 0x0057CA78 142B
// Evidence: this+0x18 via rowed 0x0043DA65 to GameInfo; virt +0x30 bool gate and +0x34 getLocalSlotNum; rowed getConstSlot/isAI; +0x10 startPos -1 +0x18 template -2; callers 0x0043E705/0x00442EC1/0x00442F18/0x0057CCC6
class Rva0043DA65
{
public:
	int rva0043DA65();
};

class GameSlot
{
public:
	virtual void reset();
	bool isAI() const;
	int m_state; // +0x04
	char m_pad08[4]; // +0x08..+0x0B
	int m_color; // +0x0C
	int m_startPos; // +0x10
	char m_pad14[4]; // +0x14
	int m_playerTemplate; // +0x18
};

class GameInfo
{
public:
	virtual void v00() = 0;
	virtual void v01() = 0;
	virtual void v02() = 0;
	virtual void v03() = 0;
	virtual void v04() = 0;
	virtual void v05() = 0;
	virtual void v06() = 0;
	virtual void v07() = 0;
	virtual void v08() = 0;
	virtual void v09() = 0;
	virtual void v10() = 0;
	virtual void v11() = 0;
	virtual bool v30() const = 0;
	virtual int v34() const = 0;
	const GameSlot *getConstSlot(int slotNum) const;
};

struct Rva0057CA78
{
	char m_pad0[0x18];
	Rva0043DA65 *m_ptr18;
	int rva0057CA78(int start);
};

// ?rva0057CA78@Rva0057CA78@@QAEHH@Z present-unmatched
int Rva0057CA78::rva0057CA78(int start)
{
	GameInfo *info = (GameInfo *)m_ptr18->rva0043DA65();
	if (!info)
		return -1;
	if (!info->v30())
	{
		int local = info->v34();
		const GameSlot *slot = info->getConstSlot(local);
		if (!slot)
			return -1;
		if (slot->m_startPos != -1)
			return -1;
		return local;
	}
	int i = start;
	const GameSlot *slot;
	while (i < 8)
	{
		slot = info->getConstSlot(i);
		if (!slot)
		{
			++i;
			continue;
		}
		if (slot->m_startPos != -1)
		{
			++i;
			continue;
		}
		if (slot->m_playerTemplate == -2)
		{
			++i;
			continue;
		}
		if (i == info->v34())
			return i;
		if (slot->isAI())
			return i;
		++i;
	}
	return -1;
}
