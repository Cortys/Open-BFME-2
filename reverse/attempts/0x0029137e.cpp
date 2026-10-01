// ?rva0029137E@Object@@QAE_NAAVAsciiString@@@Z
// partial score=0.93 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// ?rva0029137E@Object@@QAE_NAAVAsciiString@@@Z
// 0x0029137E 109B unlock Object bool fill AsciiString via template plus Team check.
// Evidence: rowed rva0028F518 0x0028F518; ThePlayerList 0x009FEEE8; bfmeAskRV 0x002AA231;
// getRelationship 0x003A0FD2 cmp 2; set 0x000366F0 isEmpty 0x00001E2F neg-sbb-inc;
// callers 0x0029EE98 0x004E769E; prev ObjectRva00291298.
#include "ascii_string.h"

enum Relationship
{
	REL_ENEMY = 0,
	REL_NEUTRAL = 1,
	REL_ALLY = 2
};

class Team
{
public:
	Relationship getRelationship(const Team *other) const;
};

class BfmeMemberRV
{
public:
	bool bfmeAskRV();
public:
	char m_pad00[0x2ec];
	Team *m_team2ec;
};

class PlayerList
{
public:
	char m_pad00[0x10];
	BfmeMemberRV *m_p10;
};

extern PlayerList *ThePlayerList;

struct ObjectTmplPart
{
	char m_pad00[0x5c];
	AsciiString m_str5c;
};

class Object
{
public:
	bool rva0029137E(AsciiString &out);
	bool rva0028F518();
private:
	char m_pad00[4];
	ObjectTmplPart *m_p04;
	char m_pad08[0x304 - 8];
	Team *m_team304;
};

// ?rva0029137E@Object@@QAE_NAAVAsciiString@@@Z present-unmatched
bool Object::rva0029137E(AsciiString &out)
{
	if (!rva0028F518())
		return false;
	PlayerList *pl = ThePlayerList;
	Team *myTeam = m_team304;
	BfmeMemberRV *member = pl->m_p10;
	if (!member || !myTeam)
		return false;
	if (member->bfmeAskRV()) {
		if (myTeam->getRelationship(member->m_team2ec) == REL_ALLY)
			return false;
	}
	ObjectTmplPart *tmpl = m_p04;
	if (!tmpl)
		return false;
	((StringBase<char> *)&out)->set(*(const StringBase<char> *)&tmpl->m_str5c);
	return !((const StringBase<char> *)&out)->isEmpty();
}
