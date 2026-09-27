// cl: /O1 /DNDEBUG /MD /EHsc
// ?top@Shell@@QAEPAVWindowLayout@@XZ @ 0x0035BD7E (13B). Donor ZH GeneralsMD Shell.h top plus BFME1 Shell.cpp top; caller Shell push @0x0035C74A calls top then hidden check then runShutdown slot 3; prev Rva0035BD7BGet next GadgetTextEntryValidateCharacter.
class WindowLayout
{
public:
	virtual void runInit(void *userData) = 0;
	virtual void *deleteInstance(int flags) = 0;
	virtual void s02() = 0;
	virtual void s03() = 0;
	virtual void s04() = 0;
	virtual void s05() = 0;
	virtual void s06() = 0;
	virtual void s07() = 0;
	virtual void destroyWindows() = 0;
};

class IMEManager
{
public:
	virtual void m00() = 0;
	virtual void m04() = 0;
	virtual void m08() = 0;
	virtual void m0C() = 0;
	virtual void m10() = 0;
	virtual void m14() = 0;
	virtual void m18() = 0;
	virtual void m1C() = 0;
	virtual void m20() = 0;
	virtual void m24() = 0;
	virtual void m28() = 0;
	virtual void m2C() = 0;
	virtual void m30() = 0;
	virtual void m34() = 0;
	virtual void m38() = 0;
	virtual void m3C() = 0;
	virtual void m40() = 0;
	virtual void m44() = 0;
	virtual void m48() = 0;
	virtual void m4C() = 0;
	virtual void *m50() = 0;
};

extern IMEManager *TheIMEManager;

typedef bool Bool;

class GameWindow;
enum AnimTypes
{
	WIN_ANIMATION_NONE = 0,
	WIN_ANIMATION_SLIDE_LEFT = 1
};

class AnimateWindowManager
{
public:
	void registerGameWindow(GameWindow *win, AnimTypes animType, Bool needsToFinish, unsigned int ms, unsigned int delayMs);
};

struct GlobalData
{
	unsigned char _pad[0xB00];
	Bool m_animateWindows;
};

extern GlobalData *TheGlobalData;

class AsciiString
{
private:
	char *m_text;
};

class Shell
{
private:
	unsigned char _pad[12];
	WindowLayout *m_screenStack[16];
	int m_screenCount;
	Bool m_pendingPush;
	Bool m_pendingPop;
	unsigned char _pad5253[2];
	Bool m_clearBackground;
	unsigned char _pad5557[3];
	AsciiString m_pendingPushName;
	Bool m_isShellActive;
	Bool m_shellMapOn;
	unsigned char _pad5E5F[2];
	AnimateWindowManager *m_animateWindowManager;
protected:
	void linkScreen(WindowLayout *screen);
	void unlinkScreen(WindowLayout *screen);
	void doPop(Bool impendingPush);
public:
	WindowLayout *top();
	void registerWithAnimateManager(GameWindow *win, AnimTypes animType, Bool needsToFinish, unsigned int delayMS);
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

// ?doPop@Shell@@IAEX_N@Z @ 0x0035BDC2 (97B). Donor BFME1 Shell.cpp doPop plus ZH Shell.h protected doPop; callers Shell pop path; vtable WindowLayout runInit slot0 deleteInstance slot1 destroyWindows slot8 and IMEManager detatch slot15.
void Shell::doPop(Bool impendingPush)
{
	WindowLayout *currentTop = top();
	unlinkScreen(currentTop);
	currentTop->destroyWindows();
	::operator delete(currentTop->deleteInstance(0));
	WindowLayout *newTop = top();
	if (newTop && !impendingPush && !m_clearBackground)
		newTop->runInit(0);
	else
		m_clearBackground = false;
	if (TheIMEManager)
		TheIMEManager->m3C();
}

// ?registerWithAnimateManager@Shell@@QAEXPAVGameWindow@@W4AnimTypes@@_NI@Z @ 0x0035BE23 (50B). Donor BFME1 Shell.cpp registerWithAnimateManager plus ZH Shell.h public; GlobalData animateWindows at +0xB00 and animateManager at +0x60; callee AnimateWindowManager registerGameWindow.
void Shell::registerWithAnimateManager(GameWindow *win, AnimTypes animType, Bool needsToFinish, unsigned int delayMS)
{
	if (!m_animateWindowManager)
		return;
	if (!TheGlobalData->m_animateWindows)
		return;
	m_animateWindowManager->registerGameWindow(win, animType, needsToFinish, 500, delayMS);
}
