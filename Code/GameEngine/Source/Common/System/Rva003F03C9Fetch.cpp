// cl: /O1 /Ob1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Oy-
// ?rva003F03C9@Rva003F03C9@@QAE?AVUnicodeString@@XZ @0x003F03C9 58B
// Honest-address thiscall returning UnicodeString via holder at
// singleton 0x00DFEF10 +0xB0 method 0x0020EDD5 with index at this+0x5c,
// else UnicodeString::TheEmptyString. Evidence: chain lane calls rowed
// 0x0020EDD5, null holder returns empty via rowed wide copy 0x00037050,
// empty VA 0x00A0C898, fetch-family flags like Rva0020EDD5Fetch.cpp.
typedef unsigned short wchar_t;
typedef bool Bool;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	friend class Rva003F03C9;

	StringBase(const StringBase<T> &that);
	void releaseBuffer();

public:
	Bool isEmpty() const;
	StringBase() { m_data = 0; }
	~StringBase() { releaseBuffer(); }

private:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString : public StringBase<char>
{
};

class UnicodeString
{
public:
	static const UnicodeString TheEmptyString;
	UnicodeString() {}
	UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
	~UnicodeString() {}

private:
	StringBase<wchar_t> m_data;
};

class Rva0020EDD5
{
public:
	UnicodeString rva0020EDD5(int index);
};

struct RvaLogicHolder
{
	char m_pad[0xB0];
	Rva0020EDD5 *m_holder;
};

extern RvaLogicHolder *g_00DFEF10;

class Rva003F03C9
{
public:
	UnicodeString rva003F03C9();
private:
	char m_pad[0x5C];
	int m_index;
};

UnicodeString Rva003F03C9::rva003F03C9()
{
	Rva0020EDD5 *holder = g_00DFEF10->m_holder;
	if (holder != 0)
		return holder->rva0020EDD5(m_index);
	return UnicodeString::TheEmptyString;
}
