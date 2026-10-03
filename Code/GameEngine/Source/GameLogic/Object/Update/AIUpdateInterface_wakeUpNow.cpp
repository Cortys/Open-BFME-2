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

class Object
{
public:
	void setEffectivelyDead(bool dead) throw();
};

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
	char m_pad0C[0x3BD - 0x0C];
	bool m_dead3BD;
	char m_pad3BE[0x3C2 - 0x3BE];
	bool m_isInUpdate;
public:
	void markAsDead();
protected:
	void wakeUpNow();
};

void AIUpdateInterface::wakeUpNow()
{
	UpdateModule *base = (UpdateModule *)this;
	if (base->getWakeFrame() > UPDATE_SLEEP_NONE && !m_isInUpdate)
		base->setWakeFrame(m_object, UPDATE_SLEEP_NONE);
}

// ?markAsDead@AIUpdateInterface@@QAEXXZ, retail 0x0026296D, 28 bytes.
// BFME1 donor AIUpdate.cpp markAsDead simplified: sets m_dead3BD at +0x3BD
// then Object at +8 effectively dead via pinned 0x0028D2FB, tail-jumps to
// rowed wakeUpNow 0x00262871. Layout from wakeUpNow TU (+8 object, +0x3C2).
// Evidence: donor plus callees rowed/pinned plus callers at 0x004A4695 etc.
void AIUpdateInterface::markAsDead()
{
	m_dead3BD = true;
	m_object->setEffectivelyDead(true);
	return wakeUpNow();
}
