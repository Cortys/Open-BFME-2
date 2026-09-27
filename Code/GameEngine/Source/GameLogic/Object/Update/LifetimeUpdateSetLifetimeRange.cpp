// cl: /O1 /MD
//
// ?setLifetimeRange@LifetimeUpdate@@QAEXII@Z, retail 0x003A4AB3 (31 bytes).
// LifetimeUpdate::setLifetimeRange (DeletionUpdate precedent at 0x00488450
// which is also 31B): delay = calcSleepDelay(min max) then
// setWakeFrame(getObject delay). Callees are the rowed LifetimeUpdate calc
// at 0x003A49F0 and the rowed UpdateModule::setWakeFrame at 0x0044DF71.
// Layout follows the rowed xfer ?xfer@Rva003A49D1@@MAEXPAVXfer@@@Z at
// 0x003A4AFA: UpdateModule base 0x20 with Object at +0x08 so getObject
// inlines to [esi+0x08]. Vtable immediates need no patching here.
typedef unsigned int UnsignedInt;

class Thing;
class ModuleData;
class Object;

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class ObjectModule
{
public:
	ObjectModule(Thing *thing, const ModuleData *moduleData);
	virtual ~ObjectModule();

protected:
	Object *getObject() const { return m_object; }

	const ModuleData *m_moduleData; // +0x04
	Object *m_object; // +0x08
};

class BehaviorModuleInterface
{
public:
	virtual void behaviorSlot();
};

class UpdateModuleInterface
{
public:
	virtual void updateSlot();
};

class UpdateModule : public ObjectModule, public BehaviorModuleInterface, public UpdateModuleInterface
{
protected:
	void setWakeFrame(Object *obj, UpdateSleepTime wakeDelay);
};

class LifetimeUpdate : public UpdateModule
{
public:
	void setLifetimeRange(UnsignedInt minFrames, UnsignedInt maxFrames);

private:
	UnsignedInt calcSleepDelay(UnsignedInt minFrames, UnsignedInt maxFrames);
};

void LifetimeUpdate::setLifetimeRange(UnsignedInt minFrames, UnsignedInt maxFrames)
{
	UnsignedInt delay = calcSleepDelay(minFrames, maxFrames);
	setWakeFrame(getObject(), (UpdateSleepTime)delay);
}
