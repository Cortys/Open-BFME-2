// ??0Rva004DF418@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva004DF418@@QAE@PAVThing@@PBVModuleData@@@Z, RVA 0x004DF418, 104 bytes.
// Helper-family ctor over rowed ObjectHelper base 0x0028C8DF: re-stores three
// vtable slots then inits member at +0x24 via rowed 0x0029FB3B plus zero at
// +0x20 plus setWakeFrame FOREVER via rowed 0x0044DF71.
// Evidence: rowed base/init/wake callees plus vtable immediates plus ret 8.
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
	const void *m_vtable;
	int m_pad04;
	Object *m_object;
};

class ObjectHelper : public UpdateModule
{
public:
	ObjectHelper(Thing *thing, const ModuleData *moduleData);
	~ObjectHelper();
protected:
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_tailPad[0x20 - 0x14];
};

class Rva0029FB3BMember
{
public:
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
{
	m_vtable = g_00C61588;
	m_p0C = &s_secondary0C;
	m_p10 = &s_10;
	m_24.init((void *)((char *)&moduleData + 3));
	m_20 = 0;
	setWakeFrame(m_object, UPDATE_SLEEP_FOREVER);
}
