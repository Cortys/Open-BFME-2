// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva00511730@@YAXH@Z @0x00511730 135B.
// Free cdecl helper saving text-entry text into a global UnicodeString.
// Evidence: 11 retail callers all push 0 and pop ecx (cdecl 1 int arg, always
// 0, ignored; callee ends leave/ret with no return value, callers discard EAX).
// Callees GadgetTextEntryGetText rowed 0x00320AAB, StringBase<G>::set pinned
// 0x00037150, releaseBuffer rowed 0x00036E70, EH_prolog rowed 0x00629188.
// Globals g_Va00E046B8 (state with flag +0x278, field +0x27C, window +0x298),
// g_Va00E048C0 (target UnicodeString), empty via UnicodeString::TheEmptyString
// data 0x00A0C898. Flag/model donor TU GadgetComboBoxAddEntry.cpp
// (same dir, /O1 /DNDEBUG /MD /EHsc, UnicodeString/GameWindow); /O1 for the
// EBP frame plus and/or EH states, /EHsc for __EH_prolog. push ecx after the
// prolog is /O1 stack allocation, not a this-save: callers do not set ECX
// (e.g. 0x0044127C saves this in ESI), so this is YA not QAE. Volatile window
// member pins retail's add+cmp [eax]/push [eax] shape (two memory reads) over
// mov+test/push eax; precedent Debug_FrameCommands.cpp and INIFileTableGetName.cpp.
typedef unsigned short wchar_t;

template <typename T>
class StringBase
{
	friend class UnicodeString;
	friend class AsciiString;
private:
	StringBase();
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
public:
	void set(const StringBase<T> &that);
};

class UnicodeString
{
public:
	static const UnicodeString TheEmptyString;
	UnicodeString() {}
	UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
	~UnicodeString() { m_data.releaseBuffer(); }
	void set(const UnicodeString &that) { m_data.set(that.m_data); }
private:
	StringBase<wchar_t> m_data;
};

class GameWindow
{
public:
	unsigned int winGetStyle();
};

UnicodeString GadgetTextEntryGetText(GameWindow *textentry);

struct Rva00511730State
{
	char m_pad00[0x278];
	unsigned char m_flag278;
	char m_pad279[3];
	int m_field27C;
	char m_pad280[0x298 - 0x280];
	GameWindow * volatile m_window298;
};

extern Rva00511730State *g_Va00E046B8;
extern UnicodeString g_Va00E048C0;

void __cdecl Rva00511730(int unused)
{
	if (!g_Va00E046B8)
		return;
	if (g_Va00E046B8->m_flag278)
		return;
	g_Va00E046B8->m_field27C = 2;
	g_Va00E046B8->m_flag278 = 1;
	if (g_Va00E046B8->m_window298)
	{
		g_Va00E048C0.set(GadgetTextEntryGetText(g_Va00E046B8->m_window298));
	}
	else
	{
		g_Va00E048C0.set(UnicodeString::TheEmptyString);
	}
}
