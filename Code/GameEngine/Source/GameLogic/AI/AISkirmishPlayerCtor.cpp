// cl: /O1 /DNDEBUG /MD
// ??0AISkirmishPlayer@@QAE@XZ retail 0x00098B55 54B ctor installs vtable 0x007C8688
// Evidence: calls rowed ??0AIPlayer@@QAE@XZ 0x00232920; zeroes +0xE20/+0xE24 with
// and-zero idiom; CapsLock GetKeyState 0x14 toggles bit 1 of byte +0xD (flags word
// +0xC high byte); next row 0x00098B8B is ??1AISkirmishPlayer@@UAE@XZ; caller 0x0004C6D4.

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey) throw();

class AIPlayer
{
public:
	AIPlayer() throw();

protected:
	virtual ~AIPlayer() throw();

protected:
	char m_pad04[8]; // +0x04..+0x0B
	unsigned short m_flags0C; // +0x0C (high byte +0x0D holds CapsLock bit 0x0200)
	char m_pad0E[0xE20 - 0x0E]; // +0x0E..+0xE1F
};

class AISkirmishPlayer : public AIPlayer
{
public:
	AISkirmishPlayer();
	virtual ~AISkirmishPlayer();

private:
	void *m_slotE20; // +0xE20
	void *m_slotE24; // +0xE24
};

AISkirmishPlayer::AISkirmishPlayer()
{
	m_slotE20 = 0;
	m_slotE24 = 0;
	if (GetKeyState(0x14) & 1)
		m_flags0C |= 0x0200;
	else
		m_flags0C &= ~0x0200;
}
