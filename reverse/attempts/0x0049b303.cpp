// ?rva0049B303@Rva0049B303@@QAEHXZ
// partial score=0.92 date=2026-09-29
// ?rva0049B303@Rva0049B303@@QAEHXZ
// partial score=0.92 date=2026-09-29
// cl: /O1 /MD
// ?rva0049B303@Rva0049B303@@QAEHXZ, retail 0x0049B303, 13 bytes.
// Frame delta: m_20 minus TheGameLogic frame at +0x40 via global 0x00DFE78C.
// Evidence: caller 0x0053E310; prev ModuleNameGetters next OCLUpdatePoolKey; same TheGameLogic shape as ObjectRva002900E0.
class GameLogic
{
public:
	char m_pad[0x40];
	int m_frame;
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class Rva0049B303
{
public:
	int rva0049B303();
private:
	char m_pad[0x20];
	int m_20;
};

// ?rva0049B303@Rva0049B303@@QAEHXZ present-unmatched
int Rva0049B303::rva0049B303()
{
	int t = m_20;
	GameLogic *g = TheGameLogic;
	return t - g->m_frame;
}
