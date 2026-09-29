// cl: /O1
// ?rva003638BA@Rva003638BA@@QAE_NXZ retail 0x003638BA 67B.
// Unlock lane: missing callee of 2 frees; landing makes 2 ready (0x0046A6C1 0x00363AD7).
// Evidence: callers at 0x00262C04 0x00363AD7 0x0046A6F9 pass same this proving method; caller 0x00363AD7 tests al proving bool.
// ?rva00363AD7@Rva003638BA@@QAE_NXZ retail 0x00363AD7 77B.
// Chain lane: calls rowed 0x003638BA which you just landed; same this plus TerrainLogic slot 0x8c plus rowed get.
// Evidence: same this offsets plus global 0x00DFEC50 plus rowed get 0x002E6ECA; callers at 0x002E704A 0x0047000A.

class Rva002E6ECA
{
public:
	int get() const;
};

class TerrainLogic
{
public:
	virtual void slot00();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual void slot10();
	virtual void slot11();
	virtual void slot12();
	virtual void slot13();
	virtual void slot14();
	virtual void slot15();
	virtual void slot16();
	virtual void slot17();
	virtual void slot18();
	virtual void slot19();
	virtual void slot20();
	virtual void slot21();
	virtual void slot22();
	virtual void slot23();
	virtual void slot24();
	virtual void slot25();
	virtual void slot26();
	virtual void slot27();
	virtual void slot28();
	virtual void slot29();
	virtual void slot30();
	virtual void slot31();
	virtual void slot32();
	virtual void slot33();
	virtual void slot34();
	virtual Rva002E6ECA *slot35(int val);
};

#define TheTerrainLogic (*(TerrainLogic **)0x00DFEC50)

class Rva003638BANode
{
public:
	Rva003638BANode *m_next0;
	char m_pad4[4];
	Rva003638BANode *m_next8;
	char m_padC[0x14];
	int m_val20;
};

class Rva003638BA
{
public:
	bool rva003638BA();
	bool rva00363AD7();
private:
	char m_pad0[4];
	Rva003638BANode *m_ptr4;
	char m_pad8[8];
	int m_flag10;
	char m_pad14[0x10];
	int m_state24;
};

bool Rva003638BA::rva003638BA()
{
	if (m_ptr4 == 0)
		return false;
	if (m_flag10 == 0)
		return false;
	int state = m_state24;
	if (state >= 0)
		return state > 0;
	m_state24 = 0;
	for (Rva003638BANode *node = m_ptr4; node != 0; node = node->m_next8) {
		if (node->m_val20 != 0x7fffffff) {
			m_state24 = 1;
			break;
		}
	}
	return m_state24 > 0;
}

bool Rva003638BA::rva00363AD7()
{
	if (!rva003638BA())
		return false;
	Rva003638BANode *node = (Rva003638BANode *)m_flag10;
	if (node == 0)
		node = m_ptr4;
	for (; node != 0; node = node->m_next0) {
		int val = node->m_val20;
		if (val == 0x7fffffff)
			continue;
		Rva002E6ECA *obj = TheTerrainLogic->slot35(val);
		if (obj == 0)
			return true;
		if ((unsigned char)obj->get() == 0)
			return true;
	}
	return false;
}
