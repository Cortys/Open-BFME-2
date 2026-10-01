// ??0Rva005CC803@@QAE@XZ
// partial score=0.9 date=2026-10-01
// cl: /O1 /MD
// ??0Rva005CC803@@QAE@XZ @0x005CC803 28B evidence: stores g_00C74E6C at +0 g_00C74E68 at [off+this+4] where off from [m_04+4] and g_00BC6F20 at +8; caller 0x005CC7EA in 0x005CC788 family
// Ctor inits +0 and +8 plus variable-located slot via offset held at m_04+4.
extern const void *const g_00C74E6C[];
extern const void *const g_00C74E68[];
extern const void *const g_00BC6F20[];
struct Rva005CC803Off {
	char m_pad[4];
	int m_off04;
};
class Rva005CC803 {
public:
	Rva005CC803();
	void *m_00;
	Rva005CC803Off *m_04;
	void *m_08;
};
// ??0Rva005CC803@@QAE@XZ present-unmatched
Rva005CC803::Rva005CC803()
{
	m_00 = (void *)g_00C74E6C;
	Rva005CC803Off *p = m_04;
	int off = p->m_off04;
	*(void **)((char *)this + off + 4) = (void *)g_00C74E68;
	m_08 = (void *)g_00BC6F20;
}
