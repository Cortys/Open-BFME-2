// ??0Rva004DF418@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.95 date=2026-10-03
// ??0Rva004DF418@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /GX
class Thing;
class ModuleData;
class Object;

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class UpdateModule
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
protected:
	void setWakeFrame(Object *obj, UpdateSleepTime when);
public:
	const void *m_vtable;
	int m_pad04;
	Object *m_object;
};

class ObjectHelper : public UpdateModule
{
public:
	ObjectHelper(Thing *thing, const ModuleData *moduleData);
	~ObjectHelper();
public:
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_tailPad[0x20 - 0x14];
};

class Rva0029FB3BMember
{
public:
	Rva0029FB3BMember(void *context) { init(context); }
	~Rva0029FB3BMember();
	void *init(void *context);
	void *m_head;
};

static int s_secondary0C;
static int s_10;
extern const void *const g_00C61588[];

class Rva004DF418 : public ObjectHelper
{
public:
	Rva004DF418(Thing *thing, const ModuleData *moduleData);
private:
	int m_20;
	Rva0029FB3BMember m_24;
};

// ??0Rva004DF418@@QAE@PAVThing@@PBVModuleData@@@Z present-unmatched
Rva004DF418::Rva004DF418(Thing *thing, const ModuleData *moduleData)
	: ObjectHelper(thing, moduleData)
	, m_24((void *)((char *)&moduleData + 3))
{
	m_vtable = g_00C61588;
	m_p0C = &s_secondary0C;
	m_p10 = &s_10;
	m_20 = 0;
	setWakeFrame(m_object, UPDATE_SLEEP_FOREVER);
}
