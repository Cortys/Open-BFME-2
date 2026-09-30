// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?setWindowText@@YAXPAVGameWindow@@VAsciiString@@@Z, retail 0x003161F2,
// 355 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameClient/GUI/GameWindowManagerScript.cpp,
// setWindowText): reject an empty label, fetch the translated UnicodeString
// from TheGameText, then dispatch on the window style to the matching gadget
// setter, falling back to GameWindow::winSetText.
// BFME2 facts (all retail-measured):
// - The body is a file-static compiled with MSVC's private parser ABI: the
//   caller createWindow at 0x00316CCE hands the GameWindow in ESI and the
//   by-value AsciiString label on the stack. A visible caller is required to
//   make MSVC pick that convention, so this TU carries the external
//   setWindowTextCaller scaffold; without it the function is dead-stripped.
// - AsciiString isEmpty is inlined as m_text == 0 || *(u16*)(m_text+4) == 0
//   (the bfme2_ascii view of StringBase's Header), verified against the
//   0x00316210 cmp WORD PTR [eax+4],bx.
// - UnicodeString is a one-pointer StringBase<wchar_t> wrapper whose copy
//   constructor body is visible; retail records esp before loading it into ecx
//   at each by-value temporary, which only happens when the ctor makes a call.
// - Callees (retail call targets): TheGameText fetch slot 0x3C, StringBase
//   <wchar_t>::set 0x37150, releaseBuffer wide 0x36E70, narrow 0x36410,
//   StringBase<wchar_t> copy ctor 0x37050, translate 0x6CB6A0,
//   winGetStyle 0x5C4AF1, winSetText 0x31484A, GadgetButtonSetText 0x3283F7,
//   GadgetRadioSetText 0x3278F1, GadgetCheckBoxSetText 0x327BD4,
//   GadgetStaticTextSetText 0x321552, GadgetTextEntrySetText 0x2C17EB.
// - Identity: the only caller at 0x00316CCE is createWindow's textLabel tail,
//   and the source-order/size agree; the name is carried from the reference.

typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;
typedef unsigned short wchar_t;

#ifndef NULL
#define NULL 0
#endif

class AsciiString;
class UnicodeString;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;

private:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};

	Header *m_data;

	StringBase(const StringBase &that);
	void releaseBuffer();

public:
	StringBase() : m_data(0) {}
	void set(const StringBase &that);
};

class AsciiString
{
public:
	AsciiString() : m_text(0) {}
	~AsciiString() { ((StringBase<char> *)this)->releaseBuffer(); }
	const char *str() const { return m_text ? m_text + 8 : ""; }
	bool isEmpty() const { return m_text == 0 || *(const unsigned short *)(m_text + 4) == 0; }

private:
	char *m_text;
};

class UnicodeString
{
public:
	UnicodeString() { m_text = 0; }
	UnicodeString(const UnicodeString &that)
	{
		((StringBase<wchar_t> *)this)->StringBase<wchar_t>::StringBase(*(const StringBase<wchar_t> *)&that);
	}
	~UnicodeString() { ((StringBase<wchar_t> *)this)->releaseBuffer(); }
	UnicodeString &operator=(const UnicodeString &that)
	{
		((StringBase<wchar_t> *)this)->set(*(const StringBase<wchar_t> *)&that);
		return *this;
	}
	void translate(const AsciiString &that);

private:
	wchar_t *m_text;
};

// Retail fetch call uses vtable offset 0x3c (VersionUnicode.cpp recipe).
class GameTextInterface
{
public:
	virtual ~GameTextInterface() {}
	virtual void slot00() = 0;
	virtual void slot04() = 0;
	virtual void slot08() = 0;
	virtual void slot0c() = 0;
	virtual void slot10() = 0;
	virtual void slot14() = 0;
	virtual void slot18() = 0;
	virtual void slot1c() = 0;
	virtual void slot20() = 0;
	virtual void slot24() = 0;
	virtual void slot28() = 0;
	virtual void slot2c() = 0;
	virtual void slot30() = 0;
	virtual void slot34() = 0;
	virtual UnicodeString fetch(const char *label, bool *exists = 0) = 0;
};

extern GameTextInterface *TheGameText;

class GameWindow
{
public:
	UnsignedInt winGetStyle(void);
	Int winSetText(UnicodeString newText);
};

void GadgetButtonSetText(GameWindow *window, UnicodeString text);
void GadgetRadioSetText(GameWindow *window, UnicodeString text);
void GadgetCheckBoxSetText(GameWindow *window, UnicodeString text);
void GadgetStaticTextSetText(GameWindow *window, UnicodeString text);
void GadgetTextEntrySetText(GameWindow *window, UnicodeString text);

enum
{
	GWS_PUSH_BUTTON = 0x00000001,
	GWS_RADIO_BUTTON = 0x00000002,
	GWS_CHECK_BOX = 0x00000004,
	GWS_ENTRY_FIELD = 0x00000040,
	GWS_STATIC_TEXT = 0x00000080
};

#define BitTest(value, bit) ((value) & (bit))

// ?setWindowText@@YAXPAVGameWindow@@VAsciiString@@@Z
static void setWindowText(GameWindow *window, AsciiString textLabel)
{
	// sanity
	if (textLabel.isEmpty())
		return;

	UnicodeString theText, entryText;
	// Translate the text
	theText = TheGameText->fetch((char *)textLabel.str());
	// set the text in the window based on what it is
	if (BitTest(window->winGetStyle(), GWS_PUSH_BUTTON))
		GadgetButtonSetText(window, theText);
	else if (BitTest(window->winGetStyle(), GWS_RADIO_BUTTON))
		GadgetRadioSetText(window, theText);
	else if (BitTest(window->winGetStyle(), GWS_CHECK_BOX))
		GadgetCheckBoxSetText(window, theText);
	else if (BitTest(window->winGetStyle(), GWS_STATIC_TEXT))
		GadgetStaticTextSetText(window, theText);
	else if (BitTest(window->winGetStyle(), GWS_ENTRY_FIELD))
	{
		entryText.translate(textLabel);
		GadgetTextEntrySetText(window, entryText);
	}
	else
		window->winSetText(theText);
}

// Codegen scaffold: MSVC only assigns the private parser ABI to a static with a
// visible caller, and setWindowText's only caller is createWindow (0x00316BD2).
// External linkage keeps the scaffold emitted.
GameWindow *setWindowTextCaller(GameWindow *w, AsciiString textLabel)
{
	GameWindow *window = w;
	if (window)
		setWindowText(window, textLabel);
	return window;
}
