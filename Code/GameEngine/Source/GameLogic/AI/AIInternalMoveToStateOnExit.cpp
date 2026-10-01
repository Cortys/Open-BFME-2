// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// AIInternalMoveToState::onExit, retail 0x003473A4 (188 bytes).
// Identity (target evidence): slot 5 of vtable 0x00C10DE8, whose slot 4 is the
// pinned AIInternalMoveToState::onEnter 0x0034C146; the 28 direct callers are
// derived states chaining to the base onExit (as the 27 onEnter callers do),
// and vtable 0x00C124D8 inherits it unchanged. The body follows the Zero Hour
// AIStates.cpp onExit: TheAudio->removeAudioEvent(m_ambientPlayingHandle) and
// the AI ending-move call when the owner has an AI.
// BFME2 deltas: the owner's model conditions 1*32+29 (unless object status
// 0x4B is set), 4*32+28, 3*32+7 and 3*32+9 are cleared first (Object+0x10C
// words, notifier 0x0028AE6D on change); the handle is reset to 1 after the
// removal (as the FiringTracker dtor does); the ending-move call is the rowed
// AIUpdateInterface::rva00262AEA, and when the +0x4B flag is set the AI float
// +0x1A0 is reset to FLT_MAX; +0x4B is cleared last. The state machine owner
// sits at machine+0x14. ZH supplies the labels only.
typedef int AudioHandle;
enum ObjectStatusTypes
{
	OBJECT_STATUS_NONE = 0
};
enum StateExitType
{
	EXIT_NORMAL = 0
};
enum StateReturnType
{
	STATE_CONTINUE = 0
};
class AudioManager
{
public:
	virtual void _pad00() = 0;
	virtual void _pad01() = 0;
	virtual void _pad02() = 0;
	virtual void _pad03() = 0;
	virtual void _pad04() = 0;
	virtual void _pad05() = 0;
	virtual void _pad06() = 0;
	virtual void _pad07() = 0;
	virtual void _pad08() = 0;
	virtual void _pad09() = 0;
	virtual void _pad10() = 0;
	virtual void _pad11() = 0;
	virtual void _pad12() = 0;
	virtual void _pad13() = 0;
	virtual void _pad14() = 0;
	virtual void _pad15() = 0;
	virtual void _pad16() = 0;
	virtual void _pad17() = 0;
	virtual void _pad18() = 0;
	virtual void _pad19() = 0;
	virtual void _pad20() = 0;
	virtual void _pad21() = 0;
	virtual void _pad22() = 0;
	virtual void _pad23() = 0;
	virtual void _pad24() = 0;
	virtual void _pad25() = 0;
	virtual void _pad26() = 0;
	virtual void removeAudioEvent(AudioHandle handle) = 0;
};
extern AudioManager *TheAudio;
class ModelConditionFlags
{
public:
	unsigned int test(unsigned int bit) const
	{
		return m_words[bit >> 5] & (1U << (bit & 0x1f));
	}
	void clear(unsigned int bit)
	{
		m_words[bit >> 5] &= ~(1U << (bit & 0x1f));
	}
private:
	unsigned int m_words[19];
};
class AIUpdateInterface
{
public:
	void rva00262AEA();
	unsigned char m_pad000[0x1A0];
	float m_1A0; // +0x1A0
};
class Object
{
public:
	void rva0028AE6D();
	bool testStatus(ObjectStatusTypes bit) const;
	AIUpdateInterface *getAI() const { return m_ai; }
	__forceinline void clearModelConditionState(unsigned int mc)
	{
		if (m_modelConditionFlags.test(mc) != 0)
		{
			m_modelConditionFlags.clear(mc);
			rva0028AE6D();
		}
	}
private:
	unsigned char m_pad000[0x10C];
	ModelConditionFlags m_modelConditionFlags; // +0x10C
	unsigned char m_pad158[0x258 - 0x158];
	AIUpdateInterface *m_ai; // +0x258
};
class StateMachine
{
public:
	Object *getOwner() const { return m_owner; }
private:
	unsigned char m_pad00[0x14];
	Object *m_owner; // +0x14
};
class State
{
public:
	virtual ~State();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual StateReturnType onEnter();
	virtual void onExit(StateExitType status);
protected:
	Object *getMachineOwner() const { return m_machine->getOwner(); }
	unsigned char m_pad04[0x18 - 0x04];
	StateMachine *m_machine; // +0x18
};
class AIInternalMoveToState : public State
{
public:
	virtual StateReturnType onEnter();
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x40 - 0x1C];
	AudioHandle m_ambientPlayingHandle; // +0x40
	unsigned char m_pad44[0x4B - 0x44];
	bool m_4B; // +0x4B
};
void AIInternalMoveToState::onExit(StateExitType)
{
	Object *obj = getMachineOwner();
	AIUpdateInterface *ai = obj->getAI();
	if (!obj->testStatus((ObjectStatusTypes)0x4B))
		obj->clearModelConditionState(1 * 32 + 29);
	obj->clearModelConditionState(4 * 32 + 28);
	obj->clearModelConditionState(3 * 32 + 7);
	obj->clearModelConditionState(3 * 32 + 9);
	TheAudio->removeAudioEvent(m_ambientPlayingHandle);
	m_ambientPlayingHandle = 1;
	if (ai)
	{
		ai->rva00262AEA();
		if (m_4B)
			ai->m_1A0 = 3.4028234663852886e+38f;
	}
	m_4B = false;
}
