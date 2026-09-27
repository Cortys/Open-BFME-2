// ?rva00056DA2@Rva00056DA2@@QAEXXZ
// partial score=0.93 date=2026-09-27
// ?rva00056DA2@Rva00056DA2@@QAEXXZ
// partial score=0.93 date=2026-09-27
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva00056DA2@Rva00056DA2@@QAEXXZ, retail 0x00056DA2 (73B).
// Honest-address hashtable clear twin of unclaimed 0x00057FC1 (same bytes
// except the free reloc): bucket-vector at +4/+8 with size at +0x10, freeing
// each chain via rowed ?Rva00055864Free@@YGXPAURva00055864Node@@@Z at
// 0x00055864, clearing buckets and size. Callers at 0x00057B03/0x00058851.

struct Rva00055864Node
{
	Rva00055864Node *m_next;
};

void __stdcall Rva00055864Free(Rva00055864Node *node);

class Rva00056DA2
{
public:
	void rva00056DA2();
	void *m_unused00;
	union {
		Rva00055864Node **m_begin;
		Rva00055864Node ** volatile m_beginVolatile;
	};
	Rva00055864Node **m_end;
	void *m_pad0C;
	unsigned m_size;
};

// ?rva00056DA2@Rva00056DA2@@QAEXXZ present-unmatched
void Rva00056DA2::rva00056DA2()
{
	unsigned i = 0;
	unsigned count = (unsigned)(((char *)m_end - (char *)m_begin) >> 2);
	if (count != 0) {
		do {
			Rva00055864Node *cur = m_beginVolatile[i];
			while (cur != 0) {
				Rva00055864Node *next = cur->m_next;
				Rva00055864Free(cur);
				cur = next;
			}
			m_beginVolatile[i] = 0;
			++i;
		} while (i < (unsigned)(((char *)m_end - (char *)m_begin) >> 2));
	}
	m_size = 0;
}
