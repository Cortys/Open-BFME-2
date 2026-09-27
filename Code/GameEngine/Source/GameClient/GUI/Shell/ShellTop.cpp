// cl: /O1 /DNDEBUG /MD /EHsc
// ?top@Shell@@QAEPAVWindowLayout@@XZ @ 0x0035BD7E (13B). Donor ZH GeneralsMD Shell.h top plus BFME1 Shell.cpp top; caller Shell push @0x0035C74A calls top then hidden check then runShutdown slot 3; prev Rva0035BD7BGet next GadgetTextEntryValidateCharacter.
class WindowLayout;
class Shell
{
private:
	unsigned char _pad[12];
	WindowLayout *m_screenStack[16];
	int m_screenCount;
protected:
	void linkScreen(WindowLayout *screen);
	void unlinkScreen(WindowLayout *screen);
public:
	WindowLayout *top();
};

WindowLayout *Shell::top()
{
	if (m_screenCount == 0)
		return 0;
	return m_screenStack[m_screenCount - 1];
}

// ?linkScreen@Shell@@IAEXPAVWindowLayout@@@Z @ 0x0035BD8B (26B). Donor BFME1 Shell.cpp linkScreen plus ZH Shell.h protected linkScreen; callee of Shell doPush path; prev top next unlink.
void Shell::linkScreen(WindowLayout *screen)
{
	if (screen == 0)
		return;
	if (m_screenCount == 16)
		return;
	m_screenStack[m_screenCount++] = screen;
}

// ?unlinkScreen@Shell@@IAEXPAVWindowLayout@@@Z @ 0x0035BDA5 (29B). Donor BFME1 Shell.cpp unlinkScreen plus ZH Shell.h protected unlinkScreen; callee of Shell doPop path; prev linkScreen next Shell pop work.
void Shell::unlinkScreen(WindowLayout *screen)
{
	if (screen == 0)
		return;
	if (m_screenStack[m_screenCount - 1] == screen)
		m_screenStack[--m_screenCount] = 0;
}
