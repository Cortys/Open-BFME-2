// cl: /O1 /MD
//
// ?rva004EE037@Rva004EE037@@QAEIXZ retail 0x004EE037 12B unsigned div.
// Evidence: [ecx+0x74] div by LogicFramesPerSecond 0x009BA4E4; callers 0x005BE3D6 0x005BFDE4.
#define LogicFramesPerSecond (*(const unsigned *)0x00DBA4E4)
class Rva004E06FBPtrChase32Field
{
public:
	int get() const;
	char m_pad[0x20];
	int m_20;
	void *m_ptr;
};
class Rva00DFEF10
{
public:
	char m_pad[0xFC];
	int m_FC;
};
#define TheThing (*(Rva00DFEF10 *const *)0x00DFEF10)
extern "C" __declspec(dllimport) long __cdecl time(long *value);
class Rva004EE037
{
public:
	unsigned rva004EE037();
	int rva004EE043();
	void rva004EE072(const class Rva004E06FBPtrChase32Field *a, int b);
	void rva004EE0A6(int a, int b);
	int rva004EE057(int i);
	int rva004EE016();
private:
	char m_pad[0x5C];
	int m_5C;
	int m_60;
	char m_low0[0x08];
	int m_6C;
	int m_70;
	unsigned m_74;
	int m_78;
	char m_mid0[0x04];
	int m_80[5];
	char m_high[0x58];
	int m_EC;
};

unsigned Rva004EE037::rva004EE037()
{
	return m_74 / LogicFramesPerSecond;
}

int Rva004EE037::rva004EE043()
{
	if (m_78 == -1)
		return TheThing->m_FC;
	return m_78;
}

void Rva004EE037::rva004EE072(const Rva004E06FBPtrChase32Field *a, int b)
{
	if (a->m_20 == -1)
		return;
	if (a->get() == m_EC)
		++m_80[3];
	if (b == m_EC)
		++m_80[4];
}

void Rva004EE037::rva004EE0A6(int a, int b)
{
	if (m_60 == 0)
		return;
	int now = time(0);
	m_5C += now - m_60;
	m_60 = 0;
}

int Rva004EE037::rva004EE057(int i)
{
	if (i < 0 || (unsigned)i >= 5)
		return 0;
	return m_80[i];
}

int Rva004EE037::rva004EE016()
{
	if (m_70 != 0)
		return time(0) + m_6C - m_70;
	return m_6C;
}
