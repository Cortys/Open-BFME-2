// cl: /Od
// Three run-as-pair-of-ends callers recovered from the
// ?bfmeGoPF@BfmeThingPF@@QAEXPBUBfmeRangePF@@PAX@Z recipe at 0x00028C10.
// The body is byte-identical to the template except for its single REL32 call
// site, so this is a wrapper that passes the range start and length through to
// an address-specific callee. The callee is a thiscall spelling of a body the
// ledger holds under another (free-function) name, exactly as the template's
// bfmeDoPF pin at 0x000276B0 coexists with the rowed ?bfmeFindV20@@YGHPBDII@Z.
// Nothing here names the real functions; the class names are address-derived.
struct BfmeRangePF
{
	char *m_bfmeAt;				// 0x0
	char *m_bfmeEnd;			// 0x4
};

class Rva00028B90Thing
{
public:
	void bfmeGoPF(const BfmeRangePF *span, void *what);
	void bfmeDoPF(char *at, void *what, int many);
};

void Rva00028B90Thing::bfmeGoPF(const BfmeRangePF *span, void *what)
{
	bfmeDoPF(span->m_bfmeAt, what, span->m_bfmeEnd - span->m_bfmeAt);
}

class Rva0002A270Thing
{
public:
	void bfmeGoPF(const BfmeRangePF *span, void *what);
	void bfmeDoPF(char *at, void *what, int many);
};

void Rva0002A270Thing::bfmeGoPF(const BfmeRangePF *span, void *what)
{
	bfmeDoPF(span->m_bfmeAt, what, span->m_bfmeEnd - span->m_bfmeAt);
}

class Rva0002ACF0Thing
{
public:
	void bfmeGoPF(const BfmeRangePF *span, void *what);
	void bfmeDoPF(char *at, void *what, int many);
};

void Rva0002ACF0Thing::bfmeGoPF(const BfmeRangePF *span, void *what)
{
	bfmeDoPF(span->m_bfmeAt, what, span->m_bfmeEnd - span->m_bfmeAt);
}
