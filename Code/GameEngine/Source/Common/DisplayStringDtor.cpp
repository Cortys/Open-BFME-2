// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ??1DisplayString@@UAE@XZ @0x00358994 57B
// DisplayString virtual dtor; caller W3DDisplayString path 0x001061AC as base,
// donor GameClient/DisplayString.cpp dtor calls reset(); layout UnicodeString
// m_text +0x04 GameFont* m_font +0x08 next/prev; callees via row 0x00358946
// (reset/helper shape) and rowed releaseBuffer 0x00036E70.
class GameFont;
#include "unicode_string.h"
class DisplayString
{
public:
	virtual ~DisplayString();
	virtual void setText(UnicodeString text);
	virtual void pad02();
	virtual void pad03();
	virtual void notifyTextChanged();
	virtual void reset();
private:
	UnicodeString m_text;
	GameFont *m_font;
	void *m_next;
	void *m_prev;
};

DisplayString::~DisplayString()
{
	DisplayString::reset();
}

void DisplayString::setText(UnicodeString text)
{
	if (text.compare(m_text) != 0)
	{
		m_text.set(text);
		notifyTextChanged();
	}
}

// Placeholder virtuals in this unit's vftables: in retail, every vftable that holds
// each one has the same function in that slot (vftable addresses from matched vptr
// stores). Bind them to the rows at those functions.
#pragma comment(linker, "/alternatename:?pad02@DisplayString@@UAEXXZ=?rva0022C4DF@Rva0022C4DF@@QBE?AVUnicodeString@@XZ")
