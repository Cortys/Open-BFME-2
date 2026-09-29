// cl: /O1
// ?rva003638BA@Rva003638BA@@QAE_NXZ retail 0x003638BA 67B.
// Unlock lane: missing callee of 2 frees; landing makes 2 ready (0x0046A6C1 0x00363AD7).
// Evidence: callers at 0x00262C04 0x00363AD7 0x0046A6F9 pass same this proving method; caller 0x00363AD7 tests al proving bool.

class Rva003638BANode
{
public:
	char m_pad0[8];
	Rva003638BANode *m_next8;
	char m_padC[0x14];
	int m_val20;
};

class Rva003638BA
{
public:
	bool rva003638BA();
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
