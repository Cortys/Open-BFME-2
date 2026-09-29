// cl: /O1 /DNDEBUG /MD
//
// ?Rva000A4999Get@@YAXPAVObject@@PAXPAPAX1@Z @0x000A4999 (92B).
// Module-pair fetch for the editor: address bit 3 of the category name
// selects body+stealth, else flag bit 1 at +8 selects AI+skirmish count,
// else behavior array+contain. Pairs stored through the two out params.
// Unblocks 0x000A49F5 and 0x000A52AE. Callees are all rowed Object,
// SidesList and CategoryModuleClass accessors. The category literal is
// spelled 8 because every category getName ICF-folds to the same 4B body
// at 0x0030F45F; the $07 row carries this call while $08/$09 have no rows.
class BodyModuleInterface;
class StealthUpdate;
class AIUpdateInterface;
class BehaviorModule;
class ContainModuleInterface;

class FXParticleSystem
{
public:
	template <int N>
	class CategoryModuleClass
	{
	public:
		const char *getName() const;
	};
};

class SidesList
{
public:
	int getNumSkirmishTeams();
};

class Object
{
public:
	BodyModuleInterface *getBodyModule() const;
	StealthUpdate *getStealth() const;
	AIUpdateInterface *getAI();
	BehaviorModule **getBehaviorModules() const;
	ContainModuleInterface *getContain() const;
};

struct Rva000A4999Flags
{
	char m_pad[8];
	unsigned char m_flag;
};

// ?Rva000A4999Get@@YAXPAVObject@@PAXPAPAX1@Z present-unmatched
void Rva000A4999Get(Object *obj, void *arg, void **out1, void **out2)
{
	const char *name = ((FXParticleSystem::CategoryModuleClass<8> *)obj)->getName();
	if ((((unsigned int)name) & 8) == 0) {
		*out1 = obj->getBodyModule();
		*out2 = obj->getStealth();
	} else if ((((Rva000A4999Flags *)arg)->m_flag & 2) != 0) {
		*out1 = obj->getAI();
		*out2 = (void *)((SidesList *)obj)->getNumSkirmishTeams();
	} else {
		*out1 = obj->getBehaviorModules();
		*out2 = obj->getContain();
	}
}
