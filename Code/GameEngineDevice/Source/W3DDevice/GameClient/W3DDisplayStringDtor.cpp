// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ??1W3DDisplayString@@UAE@XZ, retail 0x00106162, 92 bytes (pinned; rowed
// deleting wrapper 0x0010625B). The Zero Hour destructor is empty; what
// retail runs is member and base teardown. Retail's unwind map destroys
// the DisplayString base (rowed dtor 0x00358994) in state 0 and two
// Render2DSentenceClass members at +0x14 and +0xD8 in states 1 and 2
// (m_textRenderer, m_textRendererHotKey), whose destructor is 0x00157C70.
// The UnicodeString released first at +0x19C directly follows them, so
// Render2DSentenceClass is 0xC4 bytes here. 0x00157C70 restores vtable
// 0x007D3C80, whose only slot is the rowed Render2DSentenceClass::Reset, so
// it is that class's non-virtual destructor, pinned from these calls.
// Supersedes the blocked BFME1 transfer, which had those members at
// +0xE0/+0x1B0.
#include "unicode_string.h"


class DisplayString
{
public:
	virtual ~DisplayString();
private:
	char m_pad04[0x10];
};

class Render2DSentenceClass
{
public:
	~Render2DSentenceClass();
	virtual void Reset();
private:
	char m_pad04[0xC0];
};

class W3DDisplayString : public DisplayString
{
public:
	virtual ~W3DDisplayString();
private:
	Render2DSentenceClass m_textRenderer;
	Render2DSentenceClass m_textRendererHotKey;
	UnicodeString m_hotkey;
};

W3DDisplayString::~W3DDisplayString()
{
}
