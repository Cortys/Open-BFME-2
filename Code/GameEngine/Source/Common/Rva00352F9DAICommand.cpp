// cl: /O1 /EHs /MD
// ?rva00352F9D@Rva00352F9D@@QAEXPBXHW4CommandSourceType@@@Z @0x00352F9D 110B
// Stack AICommandParms 0xC0 via rowed ctor 0x00351BD0 with 0x11 and src,
// m_waypoint from param1 plus m_intValue from param2, virtual slot 0 call,
// then inlined vector-free of m_coords start via rowed free 0x00030830.
// Evidence: immediates 0x11 0x00351BD0 0x00030830; unblocks 0x0036FAF8 0x00353F13 0x0036FB57;
// precedent Rva0047ED64AICommand.cpp same recipe with 0x2E and m_obj.
#include <stddef.h>

extern "C" void __cdecl free(void *p);

typedef int Int;
typedef float Real;

enum AICommandType
{
	AICMD_DUMMY_17 = 17
};

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0
};

struct Coord3D
{
	Real x;
	Real y;
	Real z;
};

struct RvaCoords
{
	Coord3D *m_start;
	Coord3D *m_finish;
	Coord3D *m_end;

	~RvaCoords()
	{
		if (m_start)
			free(m_start);
	}
};

struct AICommandParms
{
	AICommandParms(AICommandType cmd, CommandSourceType cmdSource);

	AICommandType m_cmd;
	CommandSourceType m_cmdSource;
	Coord3D m_pos;
	void *m_obj;
	void *m_otherObj;
	const void *m_team;
	RvaCoords m_coords;
	const void *m_waypoint;
	const void *m_polygon;
	Int m_intValue;
	char m_rest[0xC0 - 0x38];
};

class Rva00352F9D
{
public:
	virtual void rvaVirtual(AICommandParms *parms) = 0;
	void rva00352F9D(const void *waypoint, Int intVal, CommandSourceType src);
};

void Rva00352F9D::rva00352F9D(const void *waypoint, Int intVal, CommandSourceType src)
{
	AICommandParms parms((AICommandType)0x11, src);
	parms.m_waypoint = waypoint;
	parms.m_intValue = intVal;
	rvaVirtual(&parms);
}
