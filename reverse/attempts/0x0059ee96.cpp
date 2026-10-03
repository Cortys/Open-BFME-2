// ?rva0059EE96@Rva0059EE96@@QAEXEE@Z
// partial score=0.96 date=2026-10-03
// ?rva0059EE96@Rva0059EE96@@QAEXEE@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /MD
//
// ?rva0059EE96@Rva0059EE96@@QAEXEE@Z @0x0059EE96 76B: guarded Enable/Disable AptCall.
// If force a1 is clear and flag +0x4C1 already equals value a0 return; else
// store flag, pick literal EnableButtonPlayGame vs DisableButtonPlayGame by a0,
// get prefix via virtual slot 0x28, load level via m58 plus 0x274, then rowed
// 0x00524EF4 AptCall with TheRva00222A8BTarget.
// Evidence: retail cmp/je early plus test/je string select plus call-indirect
// plus three pushes to 0x00524EF4, neighbours Disp32Clearer plus Rva0059EF62Set,
// callers 0x0059EF29 0x005A27DC 0x005A62CF 0x005A655B.
// ?rva0059EE96@Rva0059EE96@@QAEXEE@Z present-unmatched
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
int __cdecl Rva00524EF4AptCall(Rva00222A8BTarget *t, void *a1, const char *a2, const char *a3);

struct Mid0059EE96
{
	char m_pad00[0x274];
	void *m_level274;
};

class Rva0059EE96
{
public:
	virtual void f00();
	virtual void f01();
	virtual void f02();
	virtual void f03();
	virtual void f04();
	virtual void f05();
	virtual void f06();
	virtual void f07();
	virtual void f08();
	virtual void f09();
	virtual const char *f10();
	void rva0059EE96(unsigned char a0, unsigned char a1);
private:
	char m_pad04[0x58 - 4];
	Mid0059EE96 *m_mid58;
	char m_pad5C[0x4C1 - 0x5C];
	unsigned char m_flag4C1;
};

void Rva0059EE96::rva0059EE96(unsigned char a0, unsigned char a1)
{
	if (!a1)
	{
		if (m_flag4C1 == a0)
			return;
	}
	m_flag4C1 = a0;
	void *lvl = m_mid58->m_level274;
	Rva00524EF4AptCall(TheRva00222A8BTarget, lvl, f10(), a0 ? "EnableButtonPlayGame" : "DisableButtonPlayGame");
}
