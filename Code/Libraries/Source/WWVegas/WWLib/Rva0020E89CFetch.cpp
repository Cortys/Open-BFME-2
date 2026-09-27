// cl: /O1 /Ob1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Oy-
// ?rva0020E89C@Rva0020E89C@@QAE?AVUnicodeString@@XZ @0x0020E89C 63B
// Honest-address method returning the translated label at this+0x38:
// empty AsciiString returns UnicodeString::TheEmptyString (data 0x00A0C898
// via rowed wide copy 0x00037050) else TheGameText->fetch Ascii overload at
// slot 0x38 (char overload at 0x3C per VersionUnicode/DownloadManager precedent,
// reverse-order virtuals). Callees isEmpty 0x00001E2F rowed. Callers include
// LivingWorld hero cutoff 0x002BA235 and wrapper 0x005C95EC.

typedef unsigned short wchar_t;
typedef bool Bool;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	friend class Rva0020E89C;

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
	virtual UnicodeString fetch(const char *label, Bool *exists = 0) = 0;
	virtual UnicodeString fetch(const AsciiString &label, Bool *exists = 0) = 0;
};

extern GameTextInterface *TheGameText;

class Rva0020E89C
{
public:
	UnicodeString rva0020E89C();

private:
	char m_pad[0x38];
	AsciiString m_label;
};

UnicodeString Rva0020E89C::rva0020E89C()
{
	if (m_label.isEmpty())
		return UnicodeString::TheEmptyString;
	return TheGameText->fetch(m_label);
}
