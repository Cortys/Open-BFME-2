// ?rva003236A0@Rva003236A0@@QAEXHH@Z
// partial score=0.94 date=2026-09-29
// ?rva003236A0@Rva003236A0@@QAEXHH@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
//
// ?rva003236A0@Rva003236A0@@QAEXHH@Z, retail 0x003236A0, 36 bytes.
// __thiscall void method with 2 int args reading this+0 as GameWindow*.
// Calls rowed winGetUserData then rowed Rva00325388Send just landed.
// Evidence: chain lane calls 0x00325388; callers 0x00323D12 0x00440370.

class GameWindow
{
public:
	void *winGetUserData();
};

void Rva00325388Send(GameWindow *window, int a, int b, int c);

struct Rva003236A0Data
{
	char m_pad[8];
	GameWindow *m_win;
};

class Rva003236A0
{
public:
	void rva003236A0(int a, int b);
private:
	GameWindow *m_win;
};

// ?rva003236A0@Rva003236A0@@QAEXHH@Z present-unmatched
void Rva003236A0::rva003236A0(int a, int b)
{
	if (m_win == 0)
		return;
	Rva003236A0Data *data = (Rva003236A0Data *)m_win->winGetUserData();
	GameWindow *v = data->m_win;
	Rva00325388Send(v, b, a, 0);
}
