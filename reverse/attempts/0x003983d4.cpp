// ??0CastleBehavior@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.88 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /GX /arch:SSE /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// ??0CastleBehavior@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x003983D4, 329 bytes.
// CastleBehavior ctor over rowed FoundationAIUpdate base. Evidence: LINK BONUS
// caller friend_newModuleInstance 0x0024AA5E news 0xAC, donor naked thunk,
// sibling Rva00398E4A proves map at +0xa0, FoundationAIUpdateCtor proves base 0x30.
#include "ascii_string.h"
#include <vector>
#include <set>
#include <map>

class Thing;
class Object;

class ModuleData
{
public:
	char m_pad00[0x10];
	char m_str10[4];
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3FFFFFFF
};

enum ScienceType
{
	SCIENCE_INVALID = 0
};

class UpdateModule
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	~UpdateModule();
protected:
	void setWakeFrame(Object *object, UpdateSleepTime frame);
public:
	const void *m_vtable;
	const ModuleData *m_moduleData;
	Object *m_object;
	const void *m_secondary0C;
	const void *m_secondary10;
	unsigned int m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_reserved1C;
};

class FoundationAIUpdate : public UpdateModule
{
public:
	FoundationAIUpdate(Thing *thing, const ModuleData *moduleData);
public:
	const void *m_20;
	unsigned int m_24;
	unsigned int m_28;
	unsigned char m_2C;
};

static int s_first20;
extern const void *const g_00C1A780[];
extern const void *const g_00C1A6C0[];
extern const void *const g_00C1A6B0[];
extern const void *const g_00C1A690[];
extern const void *const g_00C1A680[];

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL {
template <> struct less<AsciiString> {
	bool operator()(const AsciiString &left, const AsciiString &right) const {
		return left < right;
	}
};
}

class Rva002EE9B7
{
public:
	void rva002EE9B7();
};

class Rva00397E50
{
public:
	void rva00397E50();
};

class CastleMid : public FoundationAIUpdate
{
public:
	CastleMid(Thing *thing, const ModuleData *moduleData)
		: FoundationAIUpdate(thing, moduleData)
	{
		*(volatile unsigned *)&m_30 = (unsigned)&s_first20;
		m_48 = -1;
		m_34 = 0;
		m_38 = 0;
		m_3c = false;
		m_44 = false;
		m_vtable = (const void *)g_00C1A780;
		m_secondary0C = (const void *)g_00C1A6C0;
		m_secondary10 = (const void *)g_00C1A6B0;
		m_20 = (const void *)g_00C1A690;
		m_30 = (const void *)g_00C1A680;
		m_3d = true;
		m_40 = 0.0f;
		m_4c = 0.0f;
	}
public:
	const void *m_30;
	int m_34;
	int m_38;
	bool m_3c;
	bool m_3d;
	char m_pad3E[2];
	float m_40;
	bool m_44;
	char m_pad45[3];
	int m_48;
	float m_4c;
};

class CastleBehavior : public CastleMid
{
public:
	CastleBehavior(Thing *thing, const ModuleData *moduleData);
private:
	_STL::vector<ScienceType> m_v50;
	_STL::vector<ScienceType> m_v5c;
	_STL::vector<ScienceType> m_v68;
	_STL::vector<ScienceType> m_v74;
	_STL::vector<ScienceType> m_v80;
	_STL::set<AsciiString> m_s8c;
	AsciiString m_98;
	int m_9c;
	_STL::map<int, void *> m_mA0;
};

// ??0CastleBehavior@@QAE@PAVThing@@PBVModuleData@@@Z present-unmatched
CastleBehavior::CastleBehavior(Thing *thing, const ModuleData *moduleData)
	: CastleMid(thing, moduleData)
	, m_v50(_STL::allocator<ScienceType>())
	, m_v5c(_STL::allocator<ScienceType>())
	, m_v68(_STL::allocator<ScienceType>())
	, m_v74(_STL::allocator<ScienceType>())
	, m_v80(_STL::allocator<ScienceType>())
	, m_s8c()
	, m_9c(0)
	, m_mA0()
{
	m_v50.clear();
	m_v5c.clear();
	m_v68.clear();
	((Rva002EE9B7 *)&m_s8c)->rva002EE9B7();
	((Rva00397E50 *)this)->rva00397E50();
	if (!((StringBase<char> *)((char *)m_moduleData + 0x10))->isEmpty())
		m_3c = true;
	setWakeFrame(m_object, UPDATE_SLEEP_NONE);
}
