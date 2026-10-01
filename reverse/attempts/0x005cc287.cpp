// ??0Rva005CC287@@QAE@XZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /EHsc
// ??0Rva005CC287@@QAE@XZ @0x005CC287 62B ctor stores vtables and calls rowed 0x002B7250 erase.
// Evidence: callees rowed __EH_prolog plus 0x002B7250; callers 0x00574DAF; vtable stores 0x00C74E04 then 0x00C6E330.
extern const void *const g_00C74E04[];
extern const void *const g_00C6E330[];
class CreateAHeroData;
class Rva002B7250
{
public:
	void rva002B7250(CreateAHeroData *v);
};
struct Holder002B7250
{
	char m_pad[4];
	Rva002B7250 m_list04;
};
class EmptyBase005CC287
{
public:
	EmptyBase005CC287() {}
	~EmptyBase005CC287();
};
class Rva005CC287 : public EmptyBase005CC287
{
public:
	Rva005CC287();
private:
	char m_pad[8];
	Holder002B7250 *m_holder08;
};
// ??0Rva005CC287@@QAE@XZ present-unmatched
Rva005CC287::Rva005CC287()
{
	*(const void **)this = g_00C74E04;
	if (m_holder08)
		m_holder08->m_list04.rva002B7250((CreateAHeroData *)this);
	*(const void **)this = g_00C6E330;
}
