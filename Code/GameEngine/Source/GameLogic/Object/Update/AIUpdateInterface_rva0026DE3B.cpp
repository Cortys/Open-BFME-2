// cl: /O1 /DNDEBUG /MD
//
// ?rva0026DE3B@AIUpdateInterface@@QAEXH@Z,
// retail 0x0026DE3B, 60 bytes. Dedicated TU.
// Chain of getCurrentVictim 0x00268D71 and setCurrentVictim 0x00268D1F:
// stores int arg to +0x218; if arg == -3, fetches current victim, pokes
// the +0x30 slot14(0), idles via AICommandInterface at +0x20 with CMD_FROM_AI,
// then clears victim. Callers at 0x295301 0x29748F 0x299AFC 0x36DD34.

template <int N>
class BfmeVirtualSlots : public BfmeVirtualSlots<N - 1>
{
public:
	virtual void unused(char (*)[N]) = 0;
};

template <>
class BfmeVirtualSlots<0>
{
};

class Object;

class AIUpdateInterface
{
public:
	Object *getCurrentVictim() const;
	void setCurrentVictim(const Object *victim);
	void rva0026DE3B(int arg);
};

enum CommandSourceType
{
	CMD_FROM_AI = 2
};

class AICommandInterface
{
public:
	void aiIdle(CommandSourceType cmd);
};

class Slot14Obj : public BfmeVirtualSlots<14>
{
public:
	virtual void slot14(int x);
};

class AIUpdateInterfaceLayout
{
public:
	char m_pad00[0x30];
	Slot14Obj *m_30;
	char m_pad34[0x218 - 0x34];
	int m_218;
};

// ?rva0026DE3B@AIUpdateInterface@@QAEXH@Z
void AIUpdateInterface::rva0026DE3B(int arg)
{
	AIUpdateInterfaceLayout *self = (AIUpdateInterfaceLayout *)this;
	self->m_218 = arg;
	if (arg == -3)
	{
		Object *victim = getCurrentVictim();
		if (victim)
		{
			self->m_30->slot14(0);
			((AICommandInterface *)((char *)this + 0x20))->aiIdle(CMD_FROM_AI);
		}
		setCurrentVictim(0);
	}
}
