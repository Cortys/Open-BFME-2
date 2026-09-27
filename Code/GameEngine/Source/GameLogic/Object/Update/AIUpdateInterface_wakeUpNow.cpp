// cl: /O1 /DNDEBUG /MD
//
// ?wakeUpNow@AIUpdateInterface@@IAEXXZ, retail 0x00262871, 36 bytes.
// BFME1 donor AIUpdate.cpp wakeUpNow plus friend_notify spelled-out guard:
// getWakeFrame greater than UPDATE_SLEEP_NONE and not m_isInUpdate at +0x3C2
// then setWakeFrame with m_object at +0x08 and delay 1. m_queueForPathFrame
// at +0x17C in the sibling setQueue TU and m_turretAI at +0x20C in the turret
// siblings bound this AIUpdateInterface tail. Callees already rowed:
// getWakeFrame 0x0044DF5B and setWakeFrame 0x0044DF71 via UpdateModuleSetWakeFrame.
// Tail-call target of Object helper 0x0028AE6D and wrapper 0x0026296D.

class Object;

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1
};

class UpdateModule
{
	friend class AIUpdateInterface;
protected:
	UpdateSleepTime getWakeFrame() const;
	void setWakeFrame(Object *obj, UpdateSleepTime when);
};

class AIUpdateInterface
{
	char m_pad00[8];
	Object *m_object;
	char m_pad0C[0x3C2 - 0x0C];
	bool m_isInUpdate;
protected:
	void wakeUpNow();
};

void AIUpdateInterface::wakeUpNow()
{
	UpdateModule *base = (UpdateModule *)this;
	if (base->getWakeFrame() > UPDATE_SLEEP_NONE && !m_isInUpdate)
		base->setWakeFrame(m_object, UPDATE_SLEEP_NONE);
}
