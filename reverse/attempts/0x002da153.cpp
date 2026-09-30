// ?rva002DA153@Rva002DA153@@QAEMXZ
// partial score=0.95 date=2026-09-30
// ?rva002DA153@Rva002DA153@@QAEMXZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /MD /arch:SSE
// ?rva002DA153@Rva002DA153@@QAEMXZ @0x002DA153 121B: float getter with mode branches.
// Evidence: TheGameLogic findObjectByID row 0x49DC5, TheGameClient virtual 0x40, BfmeZeroRange, g_00BBB9AC -1.0f, callers 0x59AD0 0x5C931, neighbour stlport_stringtailrecord144 /O1.

typedef int ObjectID;

class Object
{
public:
	unsigned char m_pad[0x98];
	int m_98;
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

class ClientFrameSubsystem
{
public:
	virtual void *slot00();
	virtual void *slot04();
	virtual void *slot08();
	virtual void *slot0C();
	virtual void *slot10();
	virtual void *slot14();
	virtual void *slot18();
	virtual void *slot1C();
	virtual void *slot20();
	virtual void *slot24();
	virtual void *slot28();
	virtual void *slot2C();
	virtual void *slot30();
	virtual void *slot34();
	virtual void *slot38();
	virtual void *slot3C();
	virtual void *slot40(void *a);
};

extern ClientFrameSubsystem *TheGameClient;
extern const float BfmeZeroRange;
extern const float g_00BBB9AC;

struct Sub08
{
	char m_pad[0x1C];
	float m_1C;
};

class Rva002DA153
{
public:
	float rva002DA153();
private:
	char m_pad00[8];
	Sub08 *m_08;
	char m_pad0C[0x1C];
	float m_28;
	float m_2C;
	int m_pad30;
	ObjectID m_34;
	int m_38;
};

// ?rva002DA153@Rva002DA153@@QAEMXZ present-unmatched
float Rva002DA153::rva002DA153()
{
	int t = m_38 - 1;
	if (t != 0)
	{
		t = t - 1;
		if (t == 0)
		{
			Object *obj = TheGameLogic->findObjectByID(m_34);
			if (obj != 0)
			{
				unsigned int v = (unsigned int)obj->m_98;
				v >>= 0x14;
				unsigned char c = (unsigned char)v;
				c = (unsigned char)~c;
				if ((c & 1) == 0)
					return BfmeZeroRange;
			}
		}
	}
	else
	{
		void *p = TheGameClient->slot40((void *)m_34);
		if (p != 0)
		{
			if (*(unsigned char *)((char *)p + 0x44A) == 0)
				return BfmeZeroRange;
		}
	}
	float a = m_28;
	if (a != g_00BBB9AC)
	{
		if (m_08 != 0)
			return m_08->m_1C * m_2C;
		return BfmeZeroRange;
	}
	return m_2C * m_28;
}
