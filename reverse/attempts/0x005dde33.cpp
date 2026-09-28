// ?rva005DDE33@Rva005DDE33@@QAEMIII@Z
// partial score=0.95 date=2026-09-28
// ?rva005DDE33@Rva005DDE33@@QAEMIII@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc

// ?rva005DDE33@Rva005DDE33@@QAEMIII@Z, RVA 0x005DDE33, 54B. Chain lane:
// bounds-checked delegate; count is ([end]-[start])/0x18 via push/pop idiv,
// out of range returns pooled 0.0f g_Va00BBAEAC, else calls the rowed float
// range-sum 0x005DDC6B on the indexed 0x18 element head with (lo,hi).
// 12 callers in 0x005DE100. Owner unknown so honest address-derived method
// name; element head overlaps the callee layout at +4 by construction.
// Flags copy the prev neighbour allocate_copy TU (frameless-friendly, no EH).
extern float g_Va00BBAEAC;

class Rva005DDC6B
{
public:
	float rva005DDC6B(unsigned lo, unsigned hi);
private:
	int m_00;
	char *m_04;
};

struct Rva005DDE33Elem {
	Rva005DDC6B m_head;
	char m_tail[0x10];
};

class Rva005DDE33
{
public:
	float rva005DDE33(unsigned idx, unsigned lo, unsigned hi);
private:
	int m_00;
	Rva005DDE33Elem *m_04;
	Rva005DDE33Elem *m_08;
};

// ?rva005DDE33@Rva005DDE33@@QAEMIII@Z present-unmatched
float Rva005DDE33::rva005DDE33(unsigned idx, unsigned lo, unsigned hi)
{
	Rva005DDE33Elem *start = m_04;
	Rva005DDE33Elem *finish = m_08;
	if (idx >= (unsigned)(finish - start))
		return g_Va00BBAEAC;
	return start[idx].m_head.rva005DDC6B(lo, hi);
}
