// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
//
// ?rva003A105B@Team@@QAEPAVObject@@XZ, retail 0x003A105B (101 bytes).
// Team::rva003A105B: returns the validated target Object for Team+0x114,
// clearing the target when invalid. Follows donor Team target handling:
// Team+0x114 holds the target ObjectID (prev TU TeamGetControllingPlayer
// shows +0x114 target, +0x30 proto). Validates via rowed GameLogic::
// findObjectByID 0x00049DC5 (TheGameLogic at 0x00DFE78C), rowed Team::
// getControllingPlayer 0x0039D7CF and rowed Object::rva002943B2 0x002943B2,
// then Object+0x438 bit0 and Object+0x274 null checks. Callers include
// 0x0034667F 0x0034860F 0x005461C3. Honest Team method name.

enum ObjectID
{
	INVALID_OBJECT_ID = 0
};

class Player;
class Object
{
public:
	bool rva002943B2(const Player *other);
	unsigned char m_pad00[0x274];
	void *m_ptr274; // +0x274, must be null
	unsigned char m_pad278[0x438 - 0x278];
	unsigned char m_flag438; // +0x438 bit0 veto
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

class Team
{
public:
	Player *getControllingPlayer() const;
	Object *rva003A105B();
private:
	unsigned char m_pad00[0x114];
	ObjectID m_target; // +0x114
};

Object *Team::rva003A105B()
{
	if (m_target == INVALID_OBJECT_ID)
		return 0;
	Object *obj = TheGameLogic->findObjectByID(m_target);
	if (obj != 0)
	{
		if (obj->rva002943B2(getControllingPlayer()))
			obj = 0;
		if (obj != 0)
		{
			if ((obj->m_flag438 & 1) != 0)
				obj = 0;
			if (obj != 0)
			{
				if (obj->m_ptr274 != 0)
					obj = 0;
				if (obj != 0)
					return obj;
			}
		}
	}
	m_target = INVALID_OBJECT_ID;
	return obj;
}
