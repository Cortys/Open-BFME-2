// ?rva0043F20C@Rva0043F20C@@QAEXUTreeHintRef00217D4C@@@Z
// partial score=0.93 date=2026-09-27
// ?rva0043F20C@Rva0043F20C@@QAEXUTreeHintRef00217D4C@@@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);
struct TreeHintRef00217D4C
{
	TargetRef00217D4C *m_ptr;
	TreeHintRef00217D4C &operator=(const TreeHintRef00217D4C &other);
	~TreeHintRef00217D4C() { if (m_ptr) ReleaseTreeHintRef00217D4C(m_ptr); }
};
class Rva0043F20C
{
public:
	void rva0043F20C(TreeHintRef00217D4C arg);
private:
	char m_pad00[0x6C];
	TreeHintRef00217D4C m_holder;
};
void Rva0043F20C::rva0043F20C(TreeHintRef00217D4C arg)
{
	m_holder = arg;
}
