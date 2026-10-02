// ?rva002B3753@Rva002B3753@@QAEHXZ
// partial score=0.95 date=2026-10-02
// cl: /O1 /MD
// ?rva002B3753@Rva002B3753@@QAEHXZ @0x002B3753 22B: __thiscall int diff of dwords at +0x90/+0x8C masked with ~3 then zero-test via neg-sbb-inc. Evidence: retail mov eax,[ecx+0x90] add ecx,0x8C sub eax,[ecx] and al,0xFC neg sbb inc ret; caller at 0x0051EDE9; no callees.
class Rva002B3753
{
	char m_pad[0x8C];
	int m_8C;
	int m_90;
public:
	int rva002B3753();
};

// ?rva002B3753@Rva002B3753@@QAEHXZ present-unmatched
int Rva002B3753::rva002B3753()
{
	int *p = &m_8C;
	int diff = *(p + 1) - *p;
	return ((diff & 0xFFFFFFFC) == 0) ? 1 : 0;
}
