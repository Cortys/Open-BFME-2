// ?Rva00215EF7Collect@@YAXPAPAIPAI111@Z
// partial score=0.95 date=2026-09-28
// ?Rva00215EF7Collect@@YAXPAPAIPAI111@Z
// partial score=0.95 date=2026-09-28
// cl: /O1
//
// ?rva00215E6F@Rva00215E6F@@QAEXPAI@Z, retail 0x00215E6F, 24 bytes.
// Two-slot pointer holder: stores the parameter when its leading index is 0
// or 1 and that slot is still empty. Caller at 0x00215EF7 walks 0x1C-sized
// records and collects two slots into its [ebp+0x14]/[ebp+0x18] locals.
// Layout is two pointers at +0/+4; the index is the dword at param+0.

class Rva00215E6F
{
public:
	void rva00215E6F(unsigned int *p);

private:
	unsigned int *m_slots[2];
};

void Rva00215E6F::rva00215E6F(unsigned int *p)
{
	unsigned int idx = *p;
	if (idx >= 2)
		return;
	if (m_slots[idx] == 0)
		m_slots[idx] = p;
}

// ?Rva00215EF7Collect@@YAXPAPAIPAI111@Z present-unmatched
// Chain of 0x00215E6F: free __cdecl collector over 0x1C records from begin
// to end, reusing the two-slot holder over arg4/arg5 ([ebp+0x14]/[ebp+0x18])
// and copying both slots to out. Caller at 0x00216E01 passes 5 args
// (add esp,0x14). Near miss is only the final two loads swapped:
// retail mov ecx,[ebp+0x14] then mov eax,[ebp+8]; ours the reverse.
void Rva00215EF7Collect(unsigned int **out, unsigned int *begin, unsigned int *end, unsigned int *slot0, unsigned int *slot1)
{
	Rva00215E6F *holder = (Rva00215E6F *)&slot0;
	for (unsigned int *p = begin; p != end; p = (unsigned int *)((char *)p + 0x1c))
		holder->rva00215E6F(p);
	out[0] = slot0;
	out[1] = slot1;
}
