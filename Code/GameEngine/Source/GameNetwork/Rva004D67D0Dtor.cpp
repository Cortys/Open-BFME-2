// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ??1Rva004D67D0@@MAE@XZ retail 0x004D67D0 54B.
// Dtor: vptr 0x00860560 then Wide releaseBuffer at +0x24 then vptr 0x00860130.
// Evidence: caller 0x004D67B4 deleting dtor plus layout Rva004D6806 ints +0x1c/+0x20 UnicodeString +0x24 plus vtable pair.
#include "unicode_string.h"

class NetCommandMsg
{
public:
	NetCommandMsg();
protected:
	virtual ~NetCommandMsg();
private:
	char m_pad04[0x1c - 0x04];
};
// ??1NetCommandMsg@@MAE@XZ present-unmatched
inline NetCommandMsg::~NetCommandMsg() {}

class Rva004D67D0 : public NetCommandMsg
{
protected:
	virtual ~Rva004D67D0();
private:
	int m_action;
	int m_reason;
	UnicodeString m_filename;
};

Rva004D67D0::~Rva004D67D0()
{
}
