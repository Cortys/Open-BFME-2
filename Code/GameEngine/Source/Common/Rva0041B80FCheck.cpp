// cl: /O1 /MD
// ?Rva0041B80FCheck@@YA_NPAVObject@@0@Z @0x0041B80F 78B
// Free static helper at 0x0041B80F (78B): vis/team relationship check with MSVC private static convention (first Object in EAX, second in EDI).
// Evidence: rowed callees ?getControllingPlayer@Object@@QBEPAVPlayer@@XZ and ?getRelationship@Team@@QBE?AW4Relationship@@PBV1@@Z; virtual slots +0x114 (CheckActive unsigned, jbe) and +0x4c on Object+0x250; offsets +0x250/+0x304/+0x2ec like Rva0041C21BIsVisible; caller 0x0041C95C sets EDI=[ebp+8] EAX=ESI with no pushes and plain ret.
enum Relationship
{
	ENEMIES = 0,
	NEUTRAL = 1,
	ALLIES = 2
};
class Team;
class Player;
class Object;
class HasTeam2EC
{
public:
	char m_pad[0x2ec];
	Team *m_team2ec;
};
class VisIface
{
public:
	virtual void d00();
	virtual void d01();
	virtual void d02();
	virtual void d03();
	virtual void d04();
	virtual void d05();
	virtual void d06();
	virtual void d07();
	virtual void d08();
	virtual void d09();
	virtual void d10();
	virtual void d11();
	virtual void d12();
	virtual void d13();
	virtual void d14();
	virtual void d15();
	virtual void d16();
	virtual void d17();
	virtual void d18();
	virtual HasTeam2EC *GetThing(Player *p);
	virtual void d20();
	virtual void d21();
	virtual void d22();
	virtual void d23();
	virtual void d24();
	virtual void d25();
	virtual void d26();
	virtual void d27();
	virtual void d28();
	virtual void d29();
	virtual void d30();
	virtual void d31();
	virtual void d32();
	virtual void d33();
	virtual void d34();
	virtual void d35();
	virtual void d36();
	virtual void d37();
	virtual void d38();
	virtual void d39();
	virtual void d40();
	virtual void d41();
	virtual void d42();
	virtual void d43();
	virtual void d44();
	virtual void d45();
	virtual void d46();
	virtual void d47();
	virtual void d48();
	virtual void d49();
	virtual void d50();
	virtual void d51();
	virtual void d52();
	virtual void d53();
	virtual void d54();
	virtual void d55();
	virtual void d56();
	virtual void d57();
	virtual void d58();
	virtual void d59();
	virtual void d60();
	virtual void d61();
	virtual void d62();
	virtual void d63();
	virtual void d64();
	virtual void d65();
	virtual void d66();
	virtual void d67();
	virtual void d68();
	virtual unsigned int CheckActive(int v);
};
class Team
{
public:
	Relationship getRelationship(const Team *that) const;
};
class Player
{
public:
	int dummy;
};
class Object
{
public:
	Player *getControllingPlayer() const;
public:
	void *m_vtbl;
	char m_pad04[0x250 - 4];
	VisIface *m_vis;
	char m_pad254[0x304 - 0x254];
	Team *m_team;
};
static __declspec(noinline) bool Rva0041B80FCheck(Object *visObj, Object *teamObj);
static __declspec(noinline) bool Rva0041B80FCheck(Object *visObj, Object *teamObj)
{
	VisIface *vis = visObj->m_vis;
	if (vis && vis->CheckActive(0) > 0)
	{
		HasTeam2EC *h = vis->GetThing(teamObj->getControllingPlayer());
		if (h)
		{
			Team *t1 = h->m_team2ec;
			Team *t2 = teamObj->m_team;
			if (t2->getRelationship(t1) != ENEMIES)
				return true;
		}
	}
	return false;
}
// ?Rva0041B80FDummy@@YA_NPAVObject@@0@Z present-unmatched
bool Rva0041B80FDummy(Object *a, Object *b)
{
	return Rva0041B80FCheck(a, b);
}
