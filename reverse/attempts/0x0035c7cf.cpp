// ?rva0035C7CF@Shell@@QAEX_N@Z
// partial score=0.96 date=2026-09-29
// ?rva0035C7CF@Shell@@QAEX_N@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0035C7CF@Shell@@QAEX_N@Z @0x0035C7CF 163B
// Shell show path: empty/abort checks via TheGlobalData +0xABC/+0xAC5, flag-gated top runInit,
// screenCount +0x4C and headless env selects MainMenu vs LanLobby push, sets +0x5C.
// Evidence: isEmpty 0x00001E2F, top 0x0035BD7E slot0 runInit, getenv IAT, StringBase PBD 0x00037BA0,
// push pin 0x0035C74A, ret 4, unblocks 10, callers 16.
#include <stddef.h>

template <typename T>
class StringBase
{
	friend class AsciiString;
public:
	bool isEmpty() const;
private:
	StringBase() : m_data(0) {}
	StringBase(const char *s);
	struct Header
	{
		int ref_count;
		unsigned len;
		unsigned cap;
		T data[1];
	};
	Header *m_data;
};

class AsciiString
{
public:
	AsciiString(const char *s) : m_data(s) {}
	bool isEmpty() const { return m_data.isEmpty(); }
private:
	StringBase<char> m_data;
};

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

struct GlobalData
{
	unsigned char _pad1[0xabc];
	AsciiString m_unk_abc;
	unsigned char _pad2[0xac5 - (0xabc + 4)];
	bool m_unk_ac5;
	unsigned char _pad3[0xaf0 - (0xac5 + 1)];
	bool m_unk_af0;
	unsigned char _pad4[0xB00 - (0xaf0 + 1)];
	bool m_animateWindows;
};

extern GlobalData *TheGlobalData;
extern class Shell *TheShell;

class Shell
{
private:
	unsigned char _pad[12];
	WindowLayout *m_screenStack[16];
	int m_screenCount;
	bool m_pendingPush;
	bool m_pendingPop;
	unsigned char _pad5253[2];
	bool m_clearBackground;
	unsigned char _pad5557[3];
	AsciiString m_pendingPushName;
	bool m_isShellActive;
	bool m_shellMapOn;
	unsigned char _pad5E5F[2];
	void *m_animateWindowManager;
public:
	WindowLayout *top();
	void push(AsciiString name, bool flag);
	void rva0035C7CF(bool flag);
};

extern "C" __declspec(dllimport) char *__cdecl getenv(const char *name);

// ?rva0035C7CF@Shell@@QAEX_N@Z present-unmatched
void Shell::rva0035C7CF(bool flag)
{
	GlobalData *g = TheGlobalData;
	if (!g->m_unk_abc.isEmpty() && !g->m_unk_ac5)
		return;
	if (flag)
	{
		WindowLayout *t = top();
		if (t != 0)
			t->runInit(0);
		g = TheGlobalData;
	}
	if (g->m_unk_af0)
	{
		m_isShellActive = true;
		return;
	}
	if (m_screenCount != 0)
	{
		m_isShellActive = true;
		return;
	}
	if (getenv("_EA_RTS_HEADLESS") != 0)
	{
		TheShell->push(AsciiString("Menus/LanLobbyMenu.wnd"), false);
		m_isShellActive = true;
		return;
	}
	if (TheGlobalData->m_unk_ac5)
	{
		TheShell->push(AsciiString("Menus/LanLobbyMenu.wnd"), false);
		m_isShellActive = true;
		return;
	}
	TheShell->push(AsciiString("MainMenu.apt"), false);
	m_isShellActive = true;
}
