// ?rva002AAC74@Rva002AAC74@@QAEXXZ
// partial score=0.9 date=2026-10-01
// cl: /Ireference/shims/bfmelist /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva002AAC74@Rva002AAC74@@QAEXXZ @0x002AAC74 42B: pooled list clear via free-list g_00DBBD34; sentinel reset; callers 0x002ABB44 0x002AF747 0x002B11FA 0x002B1790.
struct PoolNode002AAC74
{
	PoolNode002AAC74* m_next;
	PoolNode002AAC74* m_prev;
};

extern PoolNode002AAC74* g_00DBBD34;

class Rva002AAC74
{
public:
	PoolNode002AAC74* m_head;
	void rva002AAC74();
};

// ?rva002AAC74@Rva002AAC74@@QAEXXZ present-unmatched
void Rva002AAC74::rva002AAC74()
{
	PoolNode002AAC74* cur = m_head->m_next;
	if (cur != m_head) {
		do {
			PoolNode002AAC74* freeHead = g_00DBBD34;
			PoolNode002AAC74* next = cur->m_next;
			cur->m_next = freeHead;
			g_00DBBD34 = cur;
			cur = next;
		} while (cur != m_head);
	}
	m_head->m_next = m_head;
	m_head->m_prev = m_head;
}
