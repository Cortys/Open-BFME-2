// cl: /O1 /MD /GX /arch:SSE
//
// ai.cpp holds the donor-flag ports; these are built with BFME2 flags.
//
// Members of the AI singleton (TheAI, 0x00DFF0F8) that query the partition
// manager through a filter chain.
//
//   0x002FDBC4  the closest object to `me` within range that passes six
//               filters (the 0x002611F2 one first; the 0x002619C1 one only
//               with flag bit 0), never `me` itself; called by 0x003423C8
//               with flags 2 and twice the owner's vision range
//   0x002FDC9A  AI::findClosestRepulsor (the pinned name; Zero Hour's
//               AI.cpp): nothing unless the AI data enables repulsors (+0x64),
//               else the closest object to `me` passing the repulsor filter
//               and the 0x00261058 one, from the 2D centre
//
// BFME2's partition filters (the view AIStructureCreepTactic.cpp documents):
// a vptr, the +0x04 link to the next filter of a chain (PartitionFilter::link
// 0x00625790 appends its argument and returns this), then each filter's own
// members. Names are address-derived: after the out-of-line ctor, else after
// allow (slot 1). Slot 0 of each vftable is the shared deleting dtor
// 0x00395A19. The inline destructors only restore the base vftable, which cl
// drops when nothing follows.
class Object;
class Player;

class Rva000421C8
{
public:
	Rva000421C8() : m_next(0) {}
	virtual ~Rva000421C8() {}
	virtual bool allow(Object *obj) = 0;
	virtual int getPlayerMask();
	Rva000421C8 *link(Rva000421C8 *next);	// 0x00625790
	Rva000421C8 *m_next;
};

// vftable 0x00BFAD10, allow 0x0026119D: not effectively dead (status bit 0),
// ZH's PartitionFilterAlive.
class Rva0026119DFilter : public Rva000421C8
{
public:
	virtual bool allow(Object *obj);
};

// vftable 0x00BF8FE4, allow 0x0026109D: +0x08 the object's controlling player
// (or none), +0x0C a flag.
class Rva00261058 : public Rva000421C8
{
public:
	Rva00261058(Object *obj, bool flag);
	virtual bool allow(Object *obj);
	Player *m_player;
	bool m_flag;
};

// vftable 0x00BF8FF0: +0x08 the object, +0x0C whether its controlling
// player's +0x5C is 1.
class Rva002611F2 : public Rva000421C8
{
public:
	Rva002611F2(Object *obj);
	virtual bool allow(Object *obj);
	Object *m_obj;
	bool m_flag;
};

// vftable 0x00BFBC90, allow 0x00260EB1, getPlayerMask 0x00260E6A: the object,
// relationship flags and whether a hit allows.
class Rva00260EB1Filter : public Rva000421C8
{
public:
	Rva00260EB1Filter(const Object *obj, int flags, bool match)
		: m_obj(obj), m_flags(flags), m_match(match) {}
	virtual bool allow(Object *obj);
	virtual int getPlayerMask();
	const Object *m_obj;
	int m_flags;
	bool m_match;
};

// vftable 0x00BF91BC, allow 0x002611BF.
class Rva002611BFFilter : public Rva000421C8
{
public:
	Rva002611BFFilter(const Object *obj) : m_obj(obj) {}
	virtual bool allow(Object *obj);
	const Object *m_obj;
};

// vftable 0x00C07190, allow 0x002614DF.
class Rva002614DFFilter : public Rva000421C8
{
public:
	Rva002614DFFilter(const Object *obj) : m_obj(obj) {}
	virtual bool allow(Object *obj);
	const Object *m_obj;
};

// vftable 0x00C07150, allow 0x002619C1.
class Rva002619C1Filter : public Rva000421C8
{
public:
	Rva002619C1Filter(const Object *obj) : m_obj(obj) {}
	virtual bool allow(Object *obj);
	const Object *m_obj;
};

// vftable 0x00C07178, allow 0x00261BFB: the repulsor filter of
// AI::findClosestRepulsor (ZH's PartitionFilterRepulsor).
class Rva00261BFBFilter : public Rva000421C8
{
public:
	Rva00261BFBFilter(const Object *obj) : m_obj(obj) {}
	virtual bool allow(Object *obj);
	const Object *m_obj;
};

// The base filter's slot 2 is the trivial virtual retail shares across many
// vftable slots (0x0036CC7A); bind the declaration to that row.
#pragma comment(linker, "/alternatename:?getPlayerMask@Rva000421C8@@UAEHXZ=?Get_File_Handle@FileClass@@UAEPAXXZ")

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Object
{
public:
	char m_pad000[0x38];
	Coord3D m_pos;		// +0x38
};

enum DistanceCalculationType
{
	FROM_CENTER_3D = 0,
	FROM_CENTER_2D = 1
};

class PartitionManager
{
public:
	Object *getClosestObject(const Coord3D *pos, float maxDist, int dc,
		Rva000421C8 *filters);	// 0x00625360
};
extern PartitionManager *ThePartitionManager;

struct TAiData
{
	char m_pad00[0x64];
	bool m_enableRepulsors;	// +0x64
};

class AI
{
public:
	Object *rva002FDBC4(const Object *me, float range, unsigned int flags);
	Object *findClosestRepulsor(const Object *me, float range);

private:
	char m_pad00[0x18];
	TAiData *m_aiData;	// +0x18
};

Object *AI::rva002FDBC4(const Object *me, float range, unsigned int flags)
{
	Rva002611F2 first((Object *)me);
	Rva00260EB1Filter relationship(me, 4, false);
	Rva0026119DFilter alive;
	Rva002611BFFilter second(me);
	Rva002619C1Filter optional(me);
	Rva002614DFFilter last(me);
	first.link(relationship.link(alive.link(second.link(&last))));
	if (flags & 1)
		first.link(&optional);
	Object *obj = ThePartitionManager->getClosestObject(&me->m_pos, range, FROM_CENTER_2D, &first);
	if (obj == me)
		obj = 0;
	return obj;
}

Object *AI::findClosestRepulsor(const Object *me, float range)
{
	if (!m_aiData->m_enableRepulsors)
		return 0;
	return ThePartitionManager->getClosestObject(&me->m_pos, range, FROM_CENTER_2D,
		Rva00261BFBFilter(me).link(&Rva00261058((Object *)me, false)));
}
