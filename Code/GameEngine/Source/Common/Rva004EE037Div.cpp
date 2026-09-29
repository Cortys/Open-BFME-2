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
class Rva004EE037
{
public:
	unsigned rva004EE037();
	int rva004EE043();
	void rva004EE072(const class Rva004E06FBPtrChase32Field *a, int b);
private:
	char m_pad[0x74];
	unsigned m_74;
	int m_78;
	char m_mid[0x10];
	int m_8C;
	int m_90;
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
		++m_8C;
	if (b == m_EC)
		++m_90;
}
