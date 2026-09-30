// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ?Rva003C4570Do@@YGXABVAsciiString@@0@Z @0x003C4570 100B.
// Team-plus-ExperienceLevel script helper: getTeamNamed kir teamizmi level find
// via NameKey plus rowed rva0028951F then two Team::rva0039DD12 iterates.
// Retail pushes level ptr plus 0x6886A7 then 0 plus 0x688726 callbacks.
// Evidence: chain lane via 0x28951F just landed; prev doTeamAttackNamed same
// two-AsciiString void shape plus same ScriptEngine global 0xDFE16C.
typedef int Int;
typedef bool Bool;

class Object;
class Team;

#include "ascii_string.h"


class ScriptEngine
{
public:
	Team *getTeamNamed(AsciiString, bool);
};

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	NAMEKEY_MAX = 1 << 23
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const AsciiString &s);
};

class Overridable
{
public:
	void *m_v0;
};

class Rva0028951F
{
public:
	const Overridable *rva0028951F(int key);
};

class DLINK_ITERATOR_Object;
typedef int (__cdecl *TeamPredicate)(Object *obj, void *userData);

class Team
{
public:
	int rva0039DD12(TeamPredicate pred, void *userData) const;
};

static int __cdecl CbA(Object *, void *)
{
	return 1;
}

static int __cdecl CbB(Object *, void *)
{
	return 1;
}

#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
#define TheNameKeyGen (*(NameKeyGenerator **)0x00DF36A4)
#define TheLevelSys (*(Rva0028951F **)0x00DFECC4)

void __stdcall Rva003C4570Do(const AsciiString &teamName, const AsciiString &levelName)
{
	Team *team = TheScriptEngine->getTeamNamed(teamName, false);
	if (!team)
		return;
	int key = TheNameKeyGen->nameToKey(levelName);
	const Overridable *lvl = TheLevelSys->rva0028951F(key);
	if (!lvl)
		return;
	team->rva0039DD12(CbA, (void *)lvl);
	team->rva0039DD12(CbB, 0);
}
