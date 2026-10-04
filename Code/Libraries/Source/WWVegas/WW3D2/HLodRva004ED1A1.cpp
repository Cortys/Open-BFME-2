// cl: /O1 /Ireference/shims/bfmevector /G7 /arch:SSE /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
// ?rva004ED1A1@Rva004ECECD@@QAEXHPAVObject@@@Z @0x004ED1A1 92B
// HLod attack helper: find node via rowed 0x004ECF05 then create AI group, fill via Team, attack victim, destroy group, clear +0x10.
// Evidence: chain via 0x004ECF05; callees rowed createGroup 0x002FEC4B getTeamAsAIGroup 0x003A0F62 rva002FE712 0x002FE712 plus pins findInstance 0x0039F761 groupAttackObjectPrivate 0x0036FD64; globals g_Va009FF0F8 TheTeamFactory; ret 8 two args.
class Object;
enum CommandSourceType
{
	CommandSourceType_0 = 0
};
class AIGroup;
class Team;
class AI;
class Rva004ECECD;
class TeamFactory;
extern AI *g_Va009FF0F8;
extern TeamFactory *TheTeamFactory;
class Rva0039F761Owner
{
public:
	Team *findInstance(void *p);
};
struct Rva004ECECDNode
{
	void *m_model;
	char m_pad0[0xC];
	int m_10;
};
class AIGroup
{
private:
	void groupAttackObjectPrivate(bool a, Object *victim, int b, CommandSourceType c);
	friend class Rva004ECECD;
};
class AI
{
public:
	AIGroup *createGroup();
	void rva002FE712(AIGroup *group);
};
class Team
{
public:
	void getTeamAsAIGroup(AIGroup *group);
};
class Rva004ECECD
{
public:
	Rva004ECECDNode *rva004ECF05(int id);
	void rva004ED1A1(int id, Object *victim);
	void rva004ED1FD(int id, const struct Coord3D *p);
	void rva004ED342(void *p);
private:
	char m_pad00[0x14];
	Rva004ECECDNode *m_begin;
	Rva004ECECDNode *m_end;
};
void Rva004ECECD::rva004ED1A1(int id, Object *victim)
{
	Rva004ECECDNode *node = rva004ECF05(id);
	if (node != 0)
	{
		AIGroup *group = g_Va009FF0F8->createGroup();
		Team *team = ((Rva0039F761Owner *)TheTeamFactory)->findInstance(node->m_model);
		team->getTeamAsAIGroup(group);
		group->groupAttackObjectPrivate(false, victim, 0x7fffffff, (CommandSourceType)0);
		g_Va009FF0F8->rva002FE712(group);
		node->m_10 = 0;
	}
}

// ?rva004ED342@Rva004ECECD@@QAEXPAX@Z @ 0x004ED342 (48B). Loop over Rva004ECECDNode range calling rowed rva004ED1A1-style helper rva004ED1FD. Count is (m_end-m_begin)/0x14 via idiv. No donor. Callers 0x005A9BB4 0x005AA66A. Honest pin name.
void Rva004ECECD::rva004ED342(void *p)
{
	unsigned int count = (unsigned int)(m_end - m_begin);
	for (unsigned int i = 0; i < count; ++i)
		rva004ED1FD((int)i, (const struct Coord3D *)p);
}

// Retail's data references in this unit's matched rows land on globals defined
// under other spellings at the same addresses (addend-corrected DIR32). Bind them.
#pragma comment(linker, "/alternatename:?g_Va009FF0F8@@3PAVAI@@A=?TheAI@@3PAVAI@@A")
