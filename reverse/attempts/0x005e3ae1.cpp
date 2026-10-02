// ?rva005E3AE1@Rva005E3AE1@@QAEXH@Z
// partial score=0.9 date=2026-10-02
// cl: /O1 /MD
// ?rva005E3AE1@Rva005E3AE1@@QAEXH@Z @0x005E3AE1 57B.
// Conditional init of +4/+8/+0xC when arg nonzero then vptr at +0 plus virtual-base-style store via offset at [m_04+4].
// Evidence: chain/unlock lane disassembly calls rowed? none callers 0x005E4FBA; externs s_slot3E4first g_00BC6F20 g_00C77C70 plus vbtable VA 0x00C74ED4; sibling Rva005CC803 shape.
extern "C" char s_slot3E4first;
extern const void *const g_00C74ED4[];
extern const void *const g_00BC6F20[];
extern const void *const g_00C77C70[];
struct Rva005E3AE1Off {
	char m_pad[4];
	int m_off04;
};
class Rva005E3AE1 {
public:
	void rva005E3AE1(int x);
	void *m_00;
	Rva005E3AE1Off *m_04;
	void *m_08;
	int m_0C;
};
// ?rva005E3AE1@Rva005E3AE1@@QAEXH@Z present-unmatched
void Rva005E3AE1::rva005E3AE1(int x)
{
	volatile int dummy = 0;
	if (x != 0) {
		m_04 = (Rva005E3AE1Off *)g_00C74ED4;
		m_08 = (void *)g_00BC6F20;
		m_0C = 0;
	}
	m_00 = (void *)&s_slot3E4first;
	*(void **)((char *)this + m_04->m_off04 + 4) = (void *)g_00C77C70;
}
