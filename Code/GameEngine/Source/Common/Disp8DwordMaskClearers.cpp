// cl: /O1 /MD
// Disp8 dword mask clearer: twelve-byte __thiscall member with one shape:
//
//     mov eax,[esp+4] / not eax / and [ecx+<DISP>],eax / ret 4
//
// A dword bitmask at a fixed disp8 displacement from `this` is cleared of the
// bits set in the stack mask argument (`m_flags &= ~mask`). The displacement
// 0x4C fits in a signed byte, hence disp8. Identity is not recovered: the
// name is derived from its address.
//
// ?rva001D9709@Rva001D9709@@QAEXH@Z retail 0x001D9709 12 bytes.
// Evidence: 2 unclaimed callers at 0x004332A2/0x0043344B; neighbours are disp
// lea getter 0x001D96F8 and float setter 0x001D972B.
class Rva001D9709
{
public:
	void rva001D9709(int mask);

	char m_lead[0x4C];
	int m_flags4C;
};

void Rva001D9709::rva001D9709(int mask)
{
	m_flags4C &= ~mask;
}
