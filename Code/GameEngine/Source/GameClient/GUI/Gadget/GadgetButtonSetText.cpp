// cl: /O1 /DNDEBUG /MD /EHsc
// ?GadgetButtonSetText@@YAXPAVGameWindow@@VUnicodeString@@@Z @0x003283F7 71B
// GadgetButtonSetText; BFME1 donor GadgetPushButton.cpp GadgetButtonSetText verbatim shape
// (winSendSystemMsg GGM_SET_LABEL 0x4001 with &text and 0); TheWindowManager at
// 0x9FEF1C slot 58 0xE8; UnicodeString by-value param destroyed via
// StringBase-G releaseBuffer 0x36E70; null-guarded like donor; adjacent to
// getNewPushButtonData 0x32843E as in donor; callers pass UnicodeString via G copy
// ctor (0x002C19A3 0x0029D79A 0x00303B59 0x00303B96).

typedef unsigned short wchar_t;
typedef int Int;
typedef unsigned int UnsignedInt;
typedef UnsignedInt WindowMsgData;

enum WindowMsgHandledType
{
	MSG_IGNORED,
	MSG_HANDLED
};

class UnicodeString;
class AsciiString;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;

private:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
	void releaseBuffer();

	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class UnicodeString
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
	~UnicodeString() { m_data.releaseBuffer(); }
private:
	StringBase<wchar_t> m_data;
};

class GameWindow;

class GameWindowManager
{
public:
#define V(n) virtual void pad##n() = 0;
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
	V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
	V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
	V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
	V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
	virtual void windowHiding(GameWindow *window) = 0;
	V(41) V(42) V(43) V(44) V(45) V(46) V(47)
	virtual GameWindow *winGetFocus() = 0;
	virtual Int winSetFocus(GameWindow *window) = 0;
	V(50) V(51) V(52) V(53) V(54) V(55)
	V(56) V(57)
#undef V
	virtual WindowMsgHandledType winSendSystemMsg(GameWindow *window, UnsignedInt msg, WindowMsgData mData1, WindowMsgData mData2) = 0;
};

extern GameWindowManager *TheWindowManager;

void GadgetButtonSetText(GameWindow *g, UnicodeString text)
{
	if (g == 0)
		return;
	TheWindowManager->winSendSystemMsg(g, 0x4001, (WindowMsgData)&text, 0);
}
