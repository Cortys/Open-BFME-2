// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva0035BE55@Shell@@QAE_NXZ @0x0035BE55 58B: honest-address Shell predicate.
// Evidence: neighbors Shell +0x60 in ShellTop.cpp; callees rowed AudioManager 0x001DBFEE and globals TheAudio plus TheWritableGlobalData +0xB00; callers 0x0050D145 0x0050D162; returns bool.

class AudioManager
{
public:
	bool rva001DBFEE();
};

extern AudioManager *TheAudio;

class GlobalData
{
public:
	unsigned char m_pad[0xB00];
	bool m_animateWindows;
};

extern GlobalData *TheWritableGlobalData;

struct AnimateState
{
	unsigned char m_pad[0x14];
	unsigned char m_14;
};

class Shell
{
public:
	bool rva0035BE55();

private:
	char m_pad[0x60];
	AnimateState *m_60;
};

bool Shell::rva0035BE55()
{
	if (!TheAudio->rva001DBFEE())
		return false;
	if (m_60 == 0)
		return true;
	if (TheWritableGlobalData->m_animateWindows)
		return m_60->m_14 == 0;
	return true;
}
