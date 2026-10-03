// ?rva002911B7@Object@@QAEPAXXZ
// partial score=0.96 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// ?rva002911B7@Object@@QAEPAXXZ, retail 0x002911B7, 225 bytes.
// Evidence: Object method between ObjectRva00290FBB and ObjectRva00291298; calls isKindOf findModule rva0028F4BC rva004B0333 getRelationship nameToKey; string SpecialDisguiseUpdate; globals ThePlayerList TheNameKeyGenerator. Callee rva002A7DD0 row says int but retail tests al so decl as uchar.
// ?rva002911B7@Object@@QAEPAXXZ present-unmatched
enum KindOfType
{
	KIND_12C = 0x12c
};

enum Relationship
{
	REL_0 = 0
};

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class Team;
class Player
{
public:
	Relationship getRelationship(const Team *team) const;
};

class PlayerList
{
public:
	char m_pad[0x10];
	Player *m_player;
};

extern PlayerList *ThePlayerList;

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class Module;
class Rva004B0333
{
public:
	void *rva004B0333();
};

class Rva002A7DD0
{
public:
	unsigned char rva002A7DD0();
};

class Rva00373EC6
{
public:
	char m_pad[0x3c];
	void *m_ptr3c;
};

class Object
{
public:
	void *rva002911B7();
	bool isKindOf(KindOfType k) const;
	Rva00373EC6 *rva0028F4BC();
protected:
	Module *findModule(NameKeyType key) const;
private:
	char m_pad[0x304];
	Team *m_team304;
};

void *Object::rva002911B7()
{
	if (isKindOf(KIND_12C)) {
		if (((Rva002A7DD0 *)ThePlayerList)->rva002A7DD0())
			return 0;
		Team *team = m_team304;
		Player *pl = ThePlayerList->m_player;
		if (pl->getRelationship(team) != REL_0)
			return 0;
		static NameKeyType s_key = TheNameKeyGenerator->nameToKey("SpecialDisguiseUpdate");
		Module *mod = findModule(s_key);
		if (mod == 0)
			return 0;
		return ((Rva004B0333 *)mod)->rva004B0333();
	} else {
		Rva00373EC6 *p = rva0028F4BC();
		if (p == 0)
			return 0;
		if (p->m_ptr3c == 0)
			return 0;
		if (((Rva002A7DD0 *)ThePlayerList)->rva002A7DD0())
			return 0;
		Team *team2 = m_team304;
		Player *pl2 = ThePlayerList->m_player;
		if (pl2->getRelationship(team2) != REL_0)
			return 0;
		return p->m_ptr3c;
	}
}
