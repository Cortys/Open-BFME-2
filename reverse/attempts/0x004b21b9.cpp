// ??0EmotionTrackerUpdate@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /O1 /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP=
// stlport
//
// ??0EmotionTrackerUpdate@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x004B21B9, 420 bytes.
// EmotionTrackerUpdate ctor over BFME1 donor game/GameEngine/Source/GameLogic/Object/Update/EmotionTrackerUpdateCtor.cpp
// plus retail evidence: rowed UpdateModule base 0x253390 (0x20), iface at +0x20 (early s_slot3E4first then
// derived 0xC565AC, ProductionUpdate precedent with pure-virtual iface folding), 12-bool at +0x24,
// 12-int at +0x30/+0x60, vector at +0x90 via rowed BfmeE16 Vector_base 0x211E58, set at +0xA4 via rowed
// AsciiString set 0xD3A71, tail -1/0s, distributionIndex from ModuleData+0xC and Thing id+0x74, entry loop
// with shared createEmotion/push_back (tooltip/findNugget branch shares the single create site).
// LINK BONUS caller 0x24FADF names this mangling.
#include <vector>
#include <set>
#include "ascii_string.h"

class Object;
class ModuleData;
class Thing;
class Emotion;
class EmotionNugget;
class EmotionTrackerUpdateEntry;
class BfmeEmotionName;

class Thing
{
public:
	virtual void unused00();
	virtual void unused04();
	virtual Object *asObject();

	unsigned char m_pad04[0x70];
	unsigned int m_id;
};

class BehaviorModuleBase
{
public:
	virtual void behaviorModuleBaseAnchor();
	const ModuleData *m_moduleData;
	Thing *m_object;
};

class BehaviorModuleOther
{
public:
	virtual void behaviorModuleOtherAnchor();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};

class UpdateModuleInterface
{
public:
	virtual void update() = 0;
};

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();

private:
	unsigned int m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;
};

class Rva004B21B9Iface20
{
public:
	Rva004B21B9Iface20() {}
	virtual void slot20() = 0;
};

struct BfmeE16 { float x, y, z, w; };

class BfmeEmotionName
{
public:
	~BfmeEmotionName();

private:
	char *m_data;
};

class MultiplayerColorDefinition
{
public:
	AsciiString getTooltipName() const;
};

class EmotionSystem
{
public:
	EmotionNugget *findNugget(const BfmeEmotionName &name);
	Emotion *createEmotion(EmotionTrackerUpdateEntry *entry, Object *object);
};

extern EmotionSystem *g_00E031DC;

class EmotionTrackerUpdateModuleDataView
{
public:
	unsigned char m_pad00[0x0C];
	unsigned int m_distributionCount;
	unsigned char m_pad10[0x24];
	_STL::vector<EmotionTrackerUpdateEntry *> m_entries;
};

class EmotionTrackerUpdateEntryView
{
public:
	unsigned char m_pad[0x18D];
	bool m_hasColor;
};

class EmotionTrackerUpdate : public UpdateModule, public Rva004B21B9Iface20
{
public:
	EmotionTrackerUpdate(Thing *thing, const ModuleData *moduleData);
	virtual ~EmotionTrackerUpdate();

private:
	bool m_active[12];
	int m_startFrame[12];
	int m_endFrame[12];
	_STL::vector<BfmeE16> m_emotions;
	int m_unknown9C;
	unsigned int m_distributionIndex;
	_STL::set<AsciiString> m_emotionTypes;
	int m_B0;
	int m_B4;
	int m_B8;
	int m_BC;
	bool m_enabled;
	unsigned char m_padC1[3];
	int m_C4;
};

// ??0EmotionTrackerUpdate@@QAE@PAVThing@@PBVModuleData@@@Z @0x004B21B9
EmotionTrackerUpdate::EmotionTrackerUpdate(Thing *thing, const ModuleData *moduleData)
	: UpdateModule(thing, moduleData)
	, m_unknown9C(0)
{
	m_B0 = -1;
	m_C4 = -1;
	const EmotionTrackerUpdateModuleDataView *data = (const EmotionTrackerUpdateModuleDataView *)m_moduleData;
	m_B4 = 0;
	m_B8 = 0;
	m_BC = 0;
	m_enabled = false;

	for (int i = 0; i < 12; ++i)
	{
		m_active[i] = false;
		m_startFrame[i] = 0;
		m_endFrame[i] = 0;
	}

	if (data->m_distributionCount > 0)
		m_distributionIndex = m_object->m_id % data->m_distributionCount + 1;
	else
		m_distributionIndex = 1;

	for (unsigned int i = 0; i < data->m_entries.size(); ++i)
	{
		EmotionTrackerUpdateEntry *entry = data->m_entries[i];
		if (entry == 0)
			continue;
		EmotionTrackerUpdateEntry *toCreate;
		Object *obj;
		if (((EmotionTrackerUpdateEntryView *)entry)->m_hasColor)
		{
			obj = thing != 0 ? thing->asObject() : 0;
			toCreate = entry;
		}
		else
		{
			EmotionNugget *nugget;
			{
				AsciiString tooltip = ((MultiplayerColorDefinition *)entry)->getTooltipName();
				nugget = g_00E031DC->findNugget((const BfmeEmotionName &)tooltip);
			}
			if (nugget == 0)
				continue;
			obj = thing != 0 ? thing->asObject() : 0;
			toCreate = (EmotionTrackerUpdateEntry *)nugget;
		}
		Emotion *emotion = g_00E031DC->createEmotion(toCreate, obj);
		if (emotion == 0)
			continue;
		((_STL::vector<const ModuleData *> *)&m_emotions)->push_back((const ModuleData *&)emotion);
	}
}
