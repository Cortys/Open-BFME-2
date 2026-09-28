// ?rva0039B683@Rva0039B683@@QAEXM@Z
// partial score=0.9 date=2026-09-28
// ?rva0039B683@Rva0039B683@@QAEXM@Z
// partial score=0.90 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva0039B683@Rva0039B683@@QAEXM@Z @0x0039B683 37B conditional float add: when
// the global byte at [0x00DFE78C+0x98] is nonzero add the float arg to +0xF8.
// Evidence: callers 0x002AA6BD with ecx lea esi+0x3BC and float push plus 0x002AA736.

struct Global98Flag
{
	char m_pad00[0x98];
	unsigned char m_flag98;
};

#define Global98Ptr (*(Global98Flag *const *)0x00DFE78C)

class Rva0039B683
{
public:
	void rva0039B683(float delta);

private:
	char m_pad00[0xF8];
	float m_valF8;
};

// ?rva0039B683@Rva0039B683@@QAEXM@Z present-unmatched
void Rva0039B683::rva0039B683(float delta)
{
	if (Global98Ptr->m_flag98 == 0)
		return;
	m_valF8 += delta;
}
