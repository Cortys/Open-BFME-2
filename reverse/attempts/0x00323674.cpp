// ?rva00323674@Rva00323674@@QBEHXZ
// partial score=0.95 date=2026-09-29
// ?rva00323674@Rva00323674@@QBEHXZ
// partial score=0.95 date=2026-09-29
// cl: /O1
class GameWindow
{
public:
	void *winGetUserData();
};
void GadgetListBoxGetSelected(GameWindow *win, int *sel);
struct UserData00323674
{
	char m_pad[8];
	GameWindow *m_8;
};
class Rva00323674
{
public:
	int rva00323674() const;
private:
	GameWindow *m_0;
};
// ?rva00323674@Rva00323674@@QBEHXZ present-unmatched
int Rva00323674::rva00323674() const
{
	GameWindow *win = m_0;
	if (win == 0)
		return -1;
	int sel = -1;
	UserData00323674 *user = reinterpret_cast<UserData00323674 *>(win->winGetUserData());
	GameWindow *listWin = user->m_8;
	GadgetListBoxGetSelected(listWin, &sel);
	return sel;
}
