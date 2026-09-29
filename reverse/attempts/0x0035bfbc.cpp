// ??0Shell@@QAE@XZ
// partial score=0.93 date=2026-09-29
// ??0Shell@@QAE@XZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHs
// ??0Shell@@QAE@XZ @0x0035BFBC (203B): chain ctor calls baseConstruct 0x001B4E63 then sets vtable 0x00816208; clears stack +0xC-0x4B; String set at +0x58 with empty string; NEW AnimateWindowManager 0x38 at +0x60 via 0x0053B550; NEW Rva002007D5 8 at +0x64 via 0x00200774.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

class __declspec(novtable) BFME2NativeNetworkBase
{
public:
	__forceinline BFME2NativeNetworkBase() { ((BFME2NativeNetwork *)this)->baseConstruct(); }
	virtual ~BFME2NativeNetworkBase() { _ReadWriteBarrier(); }
private:
	char m_flag;
	int m_value;
};

class WindowLayout;
class AnimateWindowManager
{
public:
	AnimateWindowManager();
private:
	char m_pad[0x38];
};

class Rva002007D5
{
public:
	Rva002007D5();
private:
	char m_pad[8];
};

template <typename T>
class StringBase
{
public:
	StringBase() : m_data(0) {}
	void set(const T *str);
private:
	T *m_data;
};

class Shell : public BFME2NativeNetworkBase
{
public:
	Shell();
	virtual void init();
	virtual void reset();
	virtual void update();
private:
	WindowLayout *m_screenStack[16];
	int m_screenCount;
	unsigned char m_50;
	unsigned char m_51;
	unsigned char m_52;
	unsigned char m_53;
	unsigned char m_54;
	unsigned char m_pad55[3];
	StringBase<char> m_pendingPushName;
	bool m_isShellActive;
	bool m_shellMapOn;
	unsigned char m_pad5E[2];
	AnimateWindowManager *m_animate;
	Rva002007D5 *m_scheme;
	int m_68;
	bool m_6c;
	bool m_6d;
	unsigned char m_pad6E[2];
	int m_70;
	int m_74;
};

// ??0Shell@@QAE@XZ present-unmatched
Shell::Shell()
{
	int i;
	m_screenCount = 0;
	for (i = 0; i < 16; i++)
		m_screenStack[i] = 0;
	m_52 = 0;
	m_53 = 0;
	m_50 = 0;
	m_51 = 0;
	m_54 = 0;
	m_pendingPushName.set("");
	m_isShellActive = true;
	m_shellMapOn = false;
	m_animate = new AnimateWindowManager;
	m_scheme = new Rva002007D5;
	m_68 = 1;
	m_6c = true;
	m_6d = true;
	m_70 = 0;
	m_74 = 0;
	m_screenCount = 0;
}
