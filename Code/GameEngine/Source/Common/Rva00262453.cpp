// cl: /O1 /DNDEBUG /MD
//
// ?rva00262453@Rva00262453@@QAEXPAVSequentialScript@@_NH@Z, retail 0x00262453, 74 bytes.
// Evidence: same +4/+8/+9/+0A/+0B layout as Rva00262436 setter; old ptr at
// +4 checked at +0x10 then rowed ScriptEngine::rva00205140 0x00205140 via
// g_Va009FE16C; callers 0x0036E2D1 and 0x003B3DAF with (ptr 1 arg2).
class SequentialScript
{
public:
	char m_pad[0x10];
	unsigned char m_10;
};

class ScriptEngine
{
public:
	void rva00205140(SequentialScript *arg);
};

extern ScriptEngine *g_Va009FE16C;

class Rva00262453
{
	int m_00;
	SequentialScript *m_04;
	bool m_08;
	bool m_09;
	bool m_0A;
	bool m_0B;
public:
	void rva00262453(SequentialScript *p, bool b, int dummy);
};

void Rva00262453::rva00262453(SequentialScript *p, bool b, int dummy)
{
	(void)dummy;
	if (m_08 != 0) {
		if (m_0A == 0)
			goto store;
	}
	if (p != m_04 && m_04 != 0 && m_04->m_10 != 0) {
		g_Va009FE16C->rva00205140(m_04);
		m_0A = 0;
	}
store:
	m_04 = p;
	m_08 = 0;
	m_0B = 0;
	m_09 = b;
}
