// cl: /O1 /DNDEBUG /MD /EHsc
// ?top@Shell@@QAEPAVWindowLayout@@XZ @ 0x0035BD7E (13B). Donor ZH GeneralsMD Shell.h top plus BFME1 Shell.cpp top; caller Shell push @0x0035C74A calls top then hidden check then runShutdown slot 3; prev Rva0035BD7BGet next GadgetTextEntryValidateCharacter.
class WindowLayout
{
public:
	virtual void runInit(void *userData) = 0;
	virtual void *deleteInstance(int flags) = 0;
	virtual void s02() = 0;
	virtual void s03(bool *flag) = 0;
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
	virtual void *deleteInstance(int flags) = 0;
	void registerGameWindow(GameWindow *win, AnimTypes animType, Bool needsToFinish, unsigned int ms, unsigned int delayMs);
};

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
private:
	char m_pad04[8];
};

class Rva0035BD3F
{
public:
	void rva0035BD3F();
};

class Rva002007D5
{
public:
	~Rva002007D5();
};

struct GlobalData
{
	unsigned char _pad[0xB00];
	Bool m_animateWindows;
};

extern GlobalData *TheGlobalData;

class ShellMenuSchemeManager;

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

class Shell : public GameEngineDeletingBase
{
private:
	WindowLayout *m_screenStack[16]; // +0x0C
	int m_screenCount; // +0x4C
	Bool m_pendingPush; // +0x50
	Bool m_pendingPop; // +0x51
	unsigned char _pad5253[2];
	Bool m_clearBackground; // +0x54
	unsigned char _pad5557[3];
	AsciiString m_pendingPushName; // +0x58
	Bool m_isShellActive; // +0x5C
	Bool m_shellMapOn; // +0x5D
	unsigned char _pad5E5F[2];
	AnimateWindowManager *m_animateWindowManager; // +0x60
	ShellMenuSchemeManager *m_schemeManager; // +0x64
	unsigned int m_musicHandle; // +0x68
	unsigned int _pad6C; // +0x6C
	WindowLayout *m_saveLoadMenuLayout; // +0x70
	WindowLayout *m_popupReplayLayout; // +0x74
protected:
	void linkScreen(WindowLayout *screen);
	void unlinkScreen(WindowLayout *screen);
	void doPop(Bool impendingPush);
public:
	virtual ~Shell();
	WindowLayout *top();
	void registerWithAnimateManager(GameWindow *win, AnimTypes animType, Bool needsToFinish, unsigned int delayMS);
	void loadScheme(AsciiString name);
	void rva0035BF0E();
};

class ShellMenuSchemeManager
{
public:
	void setShellMenuScheme(AsciiString name);
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

// ?loadScheme@Shell@@QAEXVAsciiString@@@Z @0x0035C49C 74B donor BFME1 Shell.cpp loadScheme forwards by-value name to m_schemeManager+0x64 setShellMenuScheme; callers none; chain via 0x002005DE.
void Shell::loadScheme(AsciiString name)
{
	if (!m_schemeManager)
		return;
	m_schemeManager->setShellMenuScheme(name);
}

// ?rva0035BF0E@Shell@@QAEXXZ retail 0x0035BF0E 62B
// Unlock: top then WindowLayout slot 0xC with bool flag then m_pendingPop=0 then doPop(false) then TheIMEManager m3C.
// Evidence: callees top 0x0035BD7E doPop 0x0035BDC2 rowed, TheIMEManager extern in use, member +0x51 pendingPop, callers 0x0035C087 0x005A20A7.
void Shell::rva0035BF0E()
{
	WindowLayout *layout = top();
	if (!layout)
		return;
	m_pendingPop = false;
	bool flag = true;
	layout->s03(&flag);
	doPop(false);
	if (TheIMEManager)
		TheIMEManager->m3C();
}

// ??1Shell@@UAE@XZ @ 0x0035C087 (227B). Shell dtor: pops screens via top/rva0035BF0E loop then animate deleteInstance+delete scheme delete layouts destroy+deleteInstance+delete audio string base. Evidence: vtable 0x00816208 callers 0x0035C54A deleting dtor callees top rva0035BF0E scheme 0x002007D5 releaseBuffer 0x00036410 base 0x001B4E74 audio 0x0035BD3F BFME1 ShellDestructor donor.
Shell::~Shell()
{
	WindowLayout *cur = top();
	while (cur != 0) {
		rva0035BF0E();
		cur = top();
	}
	if (m_animateWindowManager)
		::operator delete(m_animateWindowManager->deleteInstance(0));
	m_animateWindowManager = 0;
	if (m_schemeManager)
		delete (Rva002007D5 *)m_schemeManager;
	m_schemeManager = 0;
	if (m_saveLoadMenuLayout) {
		m_saveLoadMenuLayout->destroyWindows();
		::operator delete(m_saveLoadMenuLayout ? m_saveLoadMenuLayout->deleteInstance(0) : 0);
		m_saveLoadMenuLayout = 0;
	}
	if (m_popupReplayLayout) {
		m_popupReplayLayout->destroyWindows();
		::operator delete(m_popupReplayLayout ? m_popupReplayLayout->deleteInstance(0) : 0);
		m_popupReplayLayout = 0;
	}
	((Rva0035BD3F *)this)->rva0035BD3F();
}

// ?TheGlobalData@@3PAUGlobalData@@A: the global at this VA is ?TheGlobalData@@3PAVGlobalData@@A; this name is an alias for it.
#pragma comment(linker, "/alternatename:?TheGlobalData@@3PAUGlobalData@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?W3DGCData00DFE758@@3PAXA=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?TheRva00DFE758@@3PAVRva00DFE758Holder@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?g_Va009FE758@@3PAVGlobal9FE758@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?g_Rva009FE758@@3PAURva009FE758Obj@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?g_00DFE758@@3PAURva00DFE758Holder@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?TheWritableGlobalData@@3PAUGlobalData@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?g_Rva0023DCCEGlobal@@3PAURva0023DCCEGlobal@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?g_rampageGlobal@@3PAUGlobalWithB8@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?g_Rva0023D339A@@3PAURva0023D339A@@A=?TheGlobalData@@3PAVGlobalData@@A")
#pragma comment(linker, "/alternatename:?TheGameLogic@@3PAUGameLogicMirror@@A=?TheGlobalData@@3PAVGlobalData@@A")
// ?TheGlobalData@@3PAUGlobalData@@A: the global at VA 0xdfe758 is ?TheGlobalData@@3PAVGlobalData@@A.
#pragma comment(linker, "/alternatename:?TheGlobalData@@3PAUGlobalData@@A=?TheGlobalData@@3PAVGlobalData@@A")
