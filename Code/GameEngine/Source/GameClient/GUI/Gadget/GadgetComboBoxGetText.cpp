// cl: /O1 /DNDEBUG /MD
// ?GadgetComboBoxGetText@@YA?AVUnicodeString@@PAVGameWindow@@@Z @0x00322D21 66B.
// ZH donor GadgetComboBox.cpp GadgetComboBoxGetText: null -> empty,
// GWS_COMBO_BOX 0x8000 check via winGetStyle, else TextEntryGetText of child.
// Retail calls 0x002C032C +0x28 child and 0x00320AAB TextEntryGetText;
// 11 callers include 0x0043E3AA 0x0056EAC8 0x0057F3D8. Empty at 0xA0C898.
typedef unsigned short wchar_t;
typedef unsigned int UnsignedInt;
#define BitTest(x, i) (((x) & (i)) != 0)
#define GWS_COMBO_BOX 0x00008000
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
	static const UnicodeString TheEmptyString;
	UnicodeString() {}
	UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
	~UnicodeString() { m_data.releaseBuffer(); }
private:
	StringBase<wchar_t> m_data;
};
class GameWindow
{
public:
	UnsignedInt winGetStyle();
};
GameWindow *GadgetComboBoxGetListBox(GameWindow *comboBox);
UnicodeString GadgetTextEntryGetText(GameWindow *textEntry);
UnicodeString GadgetComboBoxGetText(GameWindow *comboBox)
{
	if (comboBox == NULL)
		return UnicodeString::TheEmptyString;
	if (BitTest(comboBox->winGetStyle(), GWS_COMBO_BOX) == 0)
		return UnicodeString::TheEmptyString;
	return GadgetTextEntryGetText(GadgetComboBoxGetListBox(comboBox));
}
