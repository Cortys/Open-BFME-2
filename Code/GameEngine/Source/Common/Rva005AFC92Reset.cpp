// cl: /O1 /MD
//
// ?rva005AFC92@Rva005AFC92@@QAE_NXZ, retail 0x005AFC92, 34 bytes. Clears
// +4 via rowed 0x00381C2D then resets +0xC via rowed GadgetListBoxReset
// 0x003247E5 when non-null, returning 1/0. Evidence: chain packet calls
// just-landed 0x00381C2D; caller jmp at 0x0057FD75; same clear-then-reset
// shape as siblings.
void __cdecl Rva00381C2DClear(unsigned int value);

class GameWindow;
void __cdecl GadgetListBoxReset(GameWindow *win);

class Rva005AFC92
{
public:
	bool rva005AFC92();
private:
	char m_pad00[4];
	unsigned int m_val04;
	char m_pad08[4];
	GameWindow *m_win0C;
};

bool Rva005AFC92::rva005AFC92()
{
	Rva00381C2DClear(m_val04);
	GameWindow *win = m_win0C;
	if (win != 0) {
		GadgetListBoxReset(win);
		return true;
	}
	return false;
}
