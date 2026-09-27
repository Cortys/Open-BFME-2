// ?rva0056EC54@Rva0056EC54@@QAE_NABVUnicodeString@@_N@Z
// partial score=0.92 date=2026-09-27
// ?rva0056EC54@Rva0056EC54@@QAE_NABVUnicodeString@@_N@Z
// partial score=0.92 date=2026-09-27
// cl: /O1 /G7 /DNDEBUG /MD /EHsc
// ?rva0056EC54@Rva0056EC54@@QAE_NABVUnicodeString@@_N@Z @0x0056EC54 90B
// Chain on 0x002C17EB GadgetTextEntrySetText; honest-address __thiscall
// returning true; m_window +0xAC m_checkBox +0xB0; checkbox gets !empty when
// flag set then text forwarded; callees isEmpty 0x35740 SetChecked 0x327AEE
// SetText 0x002C17EB copy 0x37050; true class unknown.

typedef unsigned short wchar_t;
typedef bool Bool;

class GameWindow;

template <typename T>
class StringBase
{
	friend class UnicodeString;
private:
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
public:
	StringBase() { m_data = 0; }
	~StringBase() { releaseBuffer(); }
	bool isEmpty() const;
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
	~UnicodeString() {}
private:
	StringBase<wchar_t> m_data;
};

void GadgetCheckBoxSetChecked(GameWindow *window, bool checked);
void GadgetTextEntrySetText(GameWindow *g, UnicodeString text);

class Rva0056EC54
{
public:
	bool rva0056EC54(const UnicodeString &text, bool flag);
private:
	char m_pad[0xAC];
	GameWindow *m_window;
	GameWindow *m_checkBox;
};

bool Rva0056EC54::rva0056EC54(const UnicodeString &text, bool flag)
{
	GameWindow *box = m_checkBox;
	if (m_window == 0)
		return true;
	if (box != 0 && flag)
		GadgetCheckBoxSetChecked(box, (unsigned char)!((const StringBase<wchar_t> &)text).isEmpty());
	GadgetTextEntrySetText(m_window, text);
	return true;
}
