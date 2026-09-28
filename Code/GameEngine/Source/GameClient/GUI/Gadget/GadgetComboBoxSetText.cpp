// cl: /O1 /DNDEBUG /MD /EHsc
// ?GadgetComboBoxSetText@@YAXPAVGameWindow@@VUnicodeString@@@Z @0x00322D63 98B.
// BFME1 donor GadgetComboBoxAccessors.cpp GadgetComboBoxSetText: null guard then
// ListBoxSetSelected(listBox -1) then TextEntrySetText(entry text).
// Retail calls 0x002C0315 listBox accessor at +0x2c rowed as bfmeGo925A then
// 0x00324798 SetSelected then 0x002C032C entry accessor at +0x28 rowed as
// GetListBox then 0x002C17EB TextEntrySetText; 8 callers include 0x0043F88F.
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
class BfmeKeyLC;

void *bfmeGo925A(BfmeKeyLC *k);
GameWindow *GadgetComboBoxGetListBox(GameWindow *comboBox);
void GadgetListBoxSetSelected(GameWindow *listbox, Int selectIndex);
void GadgetTextEntrySetText(GameWindow *g, UnicodeString text);

void GadgetComboBoxSetText(GameWindow *comboBox, UnicodeString text)
{
	if (comboBox == NULL)
		return;
	GadgetListBoxSetSelected((GameWindow *)bfmeGo925A((BfmeKeyLC *)comboBox), -1);
	GadgetTextEntrySetText(GadgetComboBoxGetListBox(comboBox), text);
}
