// ?rva0013EA00@Rva0013EA00@@QAEXH@Z
// partial score=0.9 date=2026-09-28
// ?rva0013EA00@Rva0013EA00@@QAEXH@Z
// partial score=0.90 date=2026-09-28
// cl: /O2 /G7 /DNDEBUG /MD
// ?rva0013EA00@Rva0013EA00@@QAEXH@Z retail 0x0013EA00 43B
// Init storing 4 at +0/+4 then branchless (arg-1?4:0) at +8 then zeros at
// +0xC/+0x10 via xor. Evidence: sub-neg-sbb-and sequence for arg==1?0:4,
// sole callers at 0x00131B8F 0x00132109 0x00132887 unblocking 3 bodies.
// Ours 41B mirror eax-ecx missing mov eax-ecx plus add-eax--1 vs sub-ecx-1.
// Tried O1-O2-G7 named-v self levers t=20.
class Rva0013EA00
{
public:
	void rva0013EA00(int arg);
private:
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
};
// ?rva0013EA00@Rva0013EA00@@QAEXH@Z present-unmatched
void Rva0013EA00::rva0013EA00(int arg)
{
	Rva0013EA00 *self = this;
	self->m_0C = 0;
	self->m_10 = 0;
	int v = (arg - 1 ? 4 : 0);
	self->m_00 = 4;
	self->m_04 = 4;
	self->m_08 = v;
}
