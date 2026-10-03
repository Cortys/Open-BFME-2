// cl: /O1
//
// ?rva0059ECAD@Rva0059ECAD@@QAEXH@Z @0x0059ECAD 20B: 2-to-9 dword setter at +0x488.
// If int at this plus 0x488 equals 2 store 9; stack arg is ignored but still
// cleaned via ret 4. Evidence: retail lea/cmp/jne/mov/ret-4, neighbours
// Disp0/Disp32 setter TU same page, caller 0x005A547E.
class Rva0059ECAD
{
public:
	void rva0059ECAD(int unused);
private:
	char m_pad00[0x488];
	int m_val488;
};

void Rva0059ECAD::rva0059ECAD(int /*unused*/)
{
	int *p = (int *)((char *)this + 0x488);
	if (*p == 2)
		*p = 9;
}
