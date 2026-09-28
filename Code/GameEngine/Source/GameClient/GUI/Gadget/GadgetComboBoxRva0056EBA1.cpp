// cl: /O1 /DNDEBUG /MD
// ?rva0056EBA1@Rva0056EBA1@@QAE_NABVUnicodeString@@@Z @0x0056EBA1 47B.
// Chain of just-landed GadgetComboBoxSetText 0x322D63: null member +0xA4 guard
// then SetText with text copy. Retail calls 0x00037050 StringBase copy then
// 0x00322D63 SetText; no callers; honest thiscall wrapper returning Bool.
typedef unsigned short wchar_t;
typedef int Int;

#ifndef NULL
#define NULL 0
#endif

template <typename T>
class StringBase
{
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

void GadgetComboBoxSetText(GameWindow *comboBox, UnicodeString text);

class Rva0056EBA1
{
public:
	bool rva0056EBA1(const UnicodeString &text);
private:
	unsigned char m_pad[0xA4];
	GameWindow *m_combo;
};

bool Rva0056EBA1::rva0056EBA1(const UnicodeString &text)
{
	bool ok = false;
	if (m_combo != NULL)
	{
		GadgetComboBoxSetText(m_combo, text);
		ok = true;
	}
	return ok;
}
