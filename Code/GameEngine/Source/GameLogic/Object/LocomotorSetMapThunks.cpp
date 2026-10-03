// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ??1Rva004FFE81@@QAE@XZ @0x004FFE81 8B: pair-value style destructor thunk.
// Retail is add ecx 4 then jmp to the rowed LocomotorSet map Rb_tree dtor
// at 0x004FF5F3 (rowed via Code/GameEngine/Source/GameLogic/Object/LocomotorSetMapSubscript.cpp).
// Caller 0x00500CB8 destroys an array with stride 0x14 calling here with
// ecx set to each element so the map sits at +4 and the element size is 0x14.
// LocomotorSetType values from the Zero Hour donor
// (GameEngine/Include/GameLogic/Module/AIUpdate.h).

#include <map>
#include <vector>

class LocomotorTemplate;

enum LocomotorSetType
{
	LOCOMOTORSET_INVALID = -1,

	LOCOMOTORSET_NORMAL = 0,
	LOCOMOTORSET_NORMAL_UPGRADED,
	LOCOMOTORSET_FREEFALL,
	LOCOMOTORSET_WANDER,
	LOCOMOTORSET_PANIC,
	LOCOMOTORSET_TAXIING,
	LOCOMOTORSET_SUPERSONIC,
	LOCOMOTORSET_SLUGGISH,

	LOCOMOTORSET_COUNT
};

typedef _STL::vector<const LocomotorTemplate *> BfmeLocomotorTemplateVector;

typedef _STL::map<LocomotorSetType, BfmeLocomotorTemplateVector, _STL::less<LocomotorSetType>, _STL::allocator<_STL::pair<const LocomotorSetType, BfmeLocomotorTemplateVector> > > BfmeLocomotorSetMap;

struct Rva004FFE81
{
	int m_first;
	BfmeLocomotorSetMap m_second;
	~Rva004FFE81();
};

Rva004FFE81::~Rva004FFE81()
{
}

struct Rva004FFE89
{
	int m_first;
	int m_second;
	BfmeLocomotorSetMap m_map;
	~Rva004FFE89();
};

Rva004FFE89::~Rva004FFE89()
{
}
