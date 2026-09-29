// cl: /O2 /MD
//
// ?rva006E34D0@Rva006E34D0@@QAEXH@Z @0x006E34D0 88B
// Bounded int append with consecutive-dup guard plus data-pointer notify:
// if count>=cap return; if count>0 and arr[count-1]==v return;
// arr[count]=v; ++count; if ready flag set build 8-byte {value, v} record
// on the stack and call the slot function with (&record, 8).
// Evidence: unlock lane, callers 0x006E3530 (packs 3 ints then passes
// through ecx) and 0x006E3580 plus 0x006CEC90 and 0x006E4390; neighbour
// AptAnimationPoolDataBIL clearBIL/appendButtonToBIL; callback slots
// 0x00A17740/44 are .data pointers per Rva00891FA0Diagnostics.
#define G_Ready (*(int *const)0x00E17708)
#define G_Value (*(int *const)0x00E176F0)
#define G_Send (*(void (__cdecl **)(void *, int))0x00E17740)

struct Rva006E34D0Record
{
	int a;
	int b;
};

class Rva006E34D0
{
public:
	void rva006E34D0(int v);
private:
	char m_pad0[0x3C];
	int m_count;
	int *m_arr;
	char m_pad1[0xAC - 0x44];
	int m_cap;
};

void Rva006E34D0::rva006E34D0(int v)
{
	if (m_count >= m_cap)
		return;
	if (m_count > 0 && m_arr[m_count - 1] == v)
		return;
	m_arr[m_count] = v;
	++m_count;
	int ready = G_Ready;
	if (ready) {
		Rva006E34D0Record r;
		r.a = G_Value;
		r.b = v;
		(*G_Send)(&r, 8);
	}
}
