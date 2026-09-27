// cl: /O1 /MD /DNDEBUG
// stlport

// ?Rva004C7542Destroy@@YAXPAU?$pair@$$CBW4LocomotorSetType@@V?$vector@PBVLocomotorTemplate@@V?$allocator@PBVLocomotorTemplate@@@_STL@@@_STL@@@_STL@@0@Z RVA 0x004C7542 size 25
// Evidence: callee pair dtor rowed at 0x000796BC; callers at 0x004C7781 and 0x004C77AE; stride 0x10 proves 16-byte pair; explicit loop exact mod reloc.
#include <vector>
#include <map>

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

class LocomotorTemplate;

typedef _STL::vector<const LocomotorTemplate *> LocomotorVec;
typedef _STL::pair<const LocomotorSetType, LocomotorVec> LocoPair;

void Rva004C7542Destroy(LocoPair *first, LocoPair *last)
{
	for (; first != last; ++first)
		first->~LocoPair();
}
