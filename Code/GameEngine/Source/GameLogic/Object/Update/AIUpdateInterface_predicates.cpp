// cl: /O1 /DNDEBUG /MD
//
// ?rva00262D40@AIUpdateInterface@@QAEXH@Z, retail 0x00262D40, 59 bytes.
// ?rva00262D7B@AIUpdateInterface@@UBE_NXZ, retail 0x00262D7B, 20 bytes.
// ?rva00262D8F@AIUpdateInterface@@UBE_NXZ, retail 0x00262D8F, 20 bytes.
// ?rva00262DA3@AIUpdateInterface@@UBE_NXZ, retail 0x00262DA3, 8 bytes.
// ?rva00262DAB@AIUpdateInterface@@UBE_NXZ, retail 0x00262DAB, 20 bytes.
// ?rva00262DBF@AIUpdateInterface@@UBE_NXZ, retail 0x00262DBF, 20 bytes.

struct Coord3D
{
	float x, y, z;
};

class Object
{
public:
	char m_pad00[0x38];
	Coord3D m_position; // +0x38
	float m_angle; // +0x44
};

class State
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8();
	virtual bool pred9() const;
	virtual void v10();
	virtual bool pred11() const;
	virtual bool pred12() const;
	virtual bool pred13() const;
};

class StateMachine
{
public:
	virtual void sm0(); virtual void sm1(); virtual void sm2(); virtual void sm3();
	virtual void sm4(); virtual void sm5(); virtual void sm6(); virtual void sm7();
	virtual void setState(int state); // slot 8 -> offset 0x20
	virtual void sm9(); virtual void sm10(); virtual void sm11();
	virtual bool pred12() const;

	State *m_currentState; // +0x04

	bool isInPred9() const { return m_currentState ? m_currentState->pred9() : true; }
	bool isInPred11() const { return m_currentState ? m_currentState->pred11() : true; }
	bool isInPred12() const { return m_currentState ? m_currentState->pred12() : true; }
	bool isInPred13() const { return m_currentState ? m_currentState->pred13() : true; }
};

#define VM10(p) \
	virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
	virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

class AIUpdateInterfaceBase
{
public:
	VM10(v0_)
	VM10(v1_)
	VM10(v2_)
	VM10(v3_)
	VM10(v4_)
	VM10(v5_)
	VM10(v6_)
	VM10(v7_)
	VM10(v8_)
	VM10(v9_)
	VM10(v10_)
	virtual void v110();
	virtual bool rva00262D8F() const; // slot 111
	virtual void v112();
	virtual bool rva00262DA3() const; // slot 113
	virtual bool rva00262DAB() const; // slot 114
	virtual bool rva00262DBF() const; // slot 115
	virtual bool rva00262D7B() const; // slot 116
};

class AIUpdateInterface : public AIUpdateInterfaceBase
{
	char m_pad04[4];
	Object *m_obj; // +0x08
	char m_pad0C[0x30 - 0x0C];
	StateMachine *m_machine; // +0x30
	char m_pad34[0x4C - 0x34];
	int m_guardMode; // +0x4C
	char m_pad50[0x54 - 0x50];
	int m_guardTargetType; // +0x54
	Coord3D m_guardPos; // +0x58
	char m_pad64[0x1A0 - 0x64];
	float m_guardAngle; // +0x1A0
public:
	void rva00262D40(int mode);
	virtual bool rva00262D7B() const;
	virtual bool rva00262D8F() const;
	virtual bool rva00262DA3() const;
	virtual bool rva00262DAB() const;
	virtual bool rva00262DBF() const;
};

void AIUpdateInterface::rva00262D40(int mode)
{
	m_guardMode = mode;
	Object *obj = m_obj;
	if (!obj)
		return;
	if (m_guardTargetType != 3)
		m_guardTargetType = 0;
	m_guardPos = obj->m_position;
	m_guardAngle = obj->m_angle;
	m_machine->setState(16);
}

bool AIUpdateInterface::rva00262D7B() const
{
	return m_machine->isInPred13();
}

bool AIUpdateInterface::rva00262D8F() const
{
	return m_machine->isInPred9();
}

bool AIUpdateInterface::rva00262DA3() const
{
	return m_machine->pred12();
}

bool AIUpdateInterface::rva00262DAB() const
{
	return m_machine->isInPred11();
}

bool AIUpdateInterface::rva00262DBF() const
{
	return m_machine->isInPred12();
}
