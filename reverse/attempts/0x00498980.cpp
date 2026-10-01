// ?rva00498980@GateOpenAndCloseBehavior@@QAE_NXZ
// partial score=0.93 date=2026-10-01
// ?rva00498980@GateOpenAndCloseBehavior@@QAE_NXZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /arch:SSE
class Thing;
class ModuleData;
struct GateOpenAndCloseModuleData
{
	char m_base[8];
	bool m_openByDefault;
	char m_pad09[3];
	unsigned int m_resetTimeInMilliseconds;
	unsigned int m_percent;
};
class BehaviorModuleBase
{
public:
	virtual void unusedBase();
	int m_a;
	int m_b;
};
class BehaviorModuleOther
{
public:
	virtual void unusedOther();
};
class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};
class UpdateModuleInterface
{
public:
	virtual void update();
};
class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
public:
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();
	virtual void update();
};
class GatePrimary
{
public:
	GatePrimary() {}
	virtual void gatePrimaryFn() = 0;
};
class GateOpenAndCloseBehavior : public GatePrimary, public UpdateModule
{
	int m_24;
	int m_28;
	int m_2C;
	bool m_30;
	float m_34;
	float m_38;
	int m_3C;
	int m_40;
	int m_44;
	bool m_48;
public:
	GateOpenAndCloseBehavior(Thing *thing, const ModuleData *moduleData);
	bool rva00498980();
};
// ?rva00498980@GateOpenAndCloseBehavior@@QAE_NXZ present-unmatched
bool GateOpenAndCloseBehavior::rva00498980()
{
	GateOpenAndCloseModuleData *data = *(GateOpenAndCloseModuleData **)((char *)this + 8);
	switch (m_28)
	{
	case 0:
	{
		if (m_34 > (float)data->m_percent)
			return true;
		return false;
	}
	case 1:
		return true;
	case 2:
	{
		if ((float)(100 - data->m_percent) >= m_34)
			return true;
		return false;
	}
	default:
		return false;
	}
}
