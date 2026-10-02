// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /DNDEBUG /Ireference/shims/moduledata
//
// ?rva00498DF3@Rva00498DF3@@QAEXPAURva00498DF3Arg@@M@Z, retail 0x00498DF3, 59 bytes.
// Evidence: calls rowed 0x00262DD3 AIUpdateInterface::rva00262DD3 and rowed 0x0026C411 AICommandInterface::rva0026C411; Object+0x38 Coord3D and CMD_FROM_AI=2 match donors; caller at 0x00498F9E pushes ebp plus float and tests nothing; this+0xC Object pattern matches caller 0x00498F46.

struct Coord3D
{
	float x;
	float y;
	float z;
};

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT = 1,
	CMD_FROM_AI = 2
};

class Object
{
public:
	char m_pad[0x38];
	Coord3D m_pos38;
};

class AIUpdateInterface
{
public:
	bool rva00262DD3(const Object *obj) const;
};

class AICommandInterface
{
public:
	void rva0026C411(Object *victim, const Coord3D *pos, CommandSourceType cmdSource);
};

struct Rva00498DF3Mid
{
	char m_pad[0x20];
	char m_cmd20[1];
};

struct Rva00498DF3Arg
{
	char m_pad[0x258];
	Rva00498DF3Mid *m_mid258;
};

class Rva00498DF3
{
public:
	char m_pad[0xC];
	Object *m_objC;
public:
	void rva00498DF3(Rva00498DF3Arg *arg, float flt);
};

void Rva00498DF3::rva00498DF3(Rva00498DF3Arg *arg, float flt)
{
	Object *obj = m_objC;
	if (!obj)
		return;
	if (!arg)
		return;
	Rva00498DF3Mid *mid = arg->m_mid258;
	if (!mid)
		return;
	if (((AIUpdateInterface *)mid)->rva00262DD3(obj))
		return;
	((AICommandInterface *)((char *)mid + 0x20))->rva0026C411(obj, &obj->m_pos38, CMD_FROM_AI);
}
