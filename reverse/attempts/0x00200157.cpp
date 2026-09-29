// ?rva00200157@RankInfo@@QAEHABV?$StringBase@D@@@Z
// partial score=0.95 date=2026-09-29
// ?rva00200157@RankInfo@@QAEHABV?$StringBase@D@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
// stlport
//
// ?rva00200157@RankInfo@@QAEHABV?$StringBase@D@@@Z — RVA 0x00200157, 195B.
// Faction-gated slot lookup: when the 0x009FE78C object is present and its
// 0x00200084 predicate holds, return m_bfme18 unless -1 (then skillPoints);
// else map Men/Elves/Dwarves/Isengard/Mordor/Wild to +0x1C..+0x30, skipping
// -1 slots, defaulting to skillPoints.
// Evidence: chain lane (calls landed 0x00200084); RankInfo layout +0x14..+0x30
// matches RankInfoCtor TU; six StringBase::compare callers; string literals.

#include <vector>

typedef int Int;

class Overridable
{
public:
	Overridable() : m_nextOverride(0), m_isAllocatedOverride(0), m_extra0C(-1) {}
	virtual void overridableAnchor();
	Overridable &operator=(const Overridable &that);

private:
	Overridable *m_nextOverride; // +0x04
	unsigned char m_isAllocatedOverride; // +0x08
	Int m_extra0C; // +0x0C, -1 (BFME2-new third Overridable word)
};

template <typename T>
class StringBase
{
public:
	StringBase() : m_data(0) {}
	void set(const StringBase &that);
	int compare(const char *str) const;

private:
	void *m_data;
};

class Rva0023C6A4
{
public:
	bool rva00200084();
};
extern Rva0023C6A4 *g_Rva0023C6A4ForRank;

class RankInfo : public Overridable
{
public:
	RankInfo();
	int rva00200157(const StringBase<char> &faction);

private:
	StringBase<wchar_t> m_rankName; // +0x10, null
	Int m_skillPointsNeeded; // +0x14, 0
	Int m_bfme18; // +0x18, -1
	Int m_bfme1C; // +0x1C, -1
	Int m_bfme20; // +0x20, -1
	Int m_bfme24; // +0x24, -1
	Int m_bfme28; // +0x28, -1
	Int m_bfme2C; // +0x2C, -1
	Int m_bfme30; // +0x30, -1
	Int m_sciencePurchasePointsGranted; // +0x34, 0
	_STL::vector<Int> m_sciencesGranted; // +0x38
};

int RankInfo::rva00200157(const StringBase<char> &faction)
{
	Rva0023C6A4 *g = g_Rva0023C6A4ForRank;
	int result;
	if (g != 0 && g->rva00200084())
	{
		result = m_bfme18;
		if (result == -1)
			result = m_skillPointsNeeded;
		return result;
	}
	if (faction.compare("Men") == 0 && m_bfme1C != -1)
		return m_bfme1C;
	if (faction.compare("Elves") == 0 && m_bfme20 != -1)
		return m_bfme20;
	if (faction.compare("Dwarves") == 0 && m_bfme24 != -1)
		return m_bfme24;
	if (faction.compare("Isengard") == 0 && m_bfme28 != -1)
		return m_bfme28;
	if (faction.compare("Mordor") == 0 && m_bfme2C != -1)
		return m_bfme2C;
	if (faction.compare("Wild") == 0 && m_bfme30 != -1)
		return m_bfme30;
	return m_skillPointsNeeded;
}
