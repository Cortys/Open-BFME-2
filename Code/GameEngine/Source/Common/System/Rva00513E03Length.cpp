// cl: /O1 /EHsc
// ?length@Rva00513E03@@QBEHXZ @0x00513E03 34B: four-part narrow concat length (Text+String+Text+String); base TextPlusString length at 0x00513B94 plus third pair len at +0x10 plus fourth string len at +0x14; chain from 0x00513B94 landing; callers 0x00513E6F 0x005E3693 0x005E36EA.
template <typename T>
class StringBase
{
	friend class AsciiString;
	StringBase(const T *text);
	StringBase(const StringBase &src);
public:
	StringBase() : m_data(0) {}
	~StringBase();
	T *getBufferForRead(int len);
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
protected:
	Header *m_data;
};
class UnicodeString;
class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &src) : StringBase<char>(src) {}
	AsciiString &operator=(const AsciiString &src);
	int getLength() const { return m_data ? m_data->length : 0; }
	const char *str() const { return m_data ? m_data->data : ""; }
	void translate(const UnicodeString &src);
};
class Rva000B3F84Pair
{
public:
	Rva000B3F84Pair() {}
	Rva000B3F84Pair *init(const char *src);
	int write(char *dst);
	const char *m_ptr;
	int m_len;
};
struct Rva002226E5TextPlusString
{
	int length() const;
	Rva000B3F84Pair m_left;
	const AsciiString *m_right;
};
struct Rva00513E03
{
	int length() const;
	Rva000B3F84Pair m_first;
	const AsciiString *m_second;
	Rva000B3F84Pair m_third;
	const AsciiString *m_fourth;
};
int Rva00513E03::length() const
{
	int third = m_third.m_len;
	int fourth = m_fourth->getLength();
	int base = ((const Rva002226E5TextPlusString *)this)->length();
	return base + fourth + third;
}

// ?length@Rva005E3693@@QBEHXZ @0x005E3693 13B: five-part extension (four-part base at 0x00513E03 plus fifth pair len at +0x1C); chain from 0x00513E03 landing.
struct Rva005E3693 : Rva00513E03
{
	int length() const;
	Rva000B3F84Pair m_fifth;
};
int Rva005E3693::length() const
{
	return Rva00513E03::length() + m_fifth.m_len;
}

// ?length@Rva005E366A@@QBEHXZ @0x005E366A 13B: three-part extension (TextPlusString base at 0x00513B94 plus third pair len at +0x10); chain from 0x00513B94 landing.
struct Rva005E366A : Rva002226E5TextPlusString
{
	int length() const;
	Rva000B3F84Pair m_third;
};
int Rva005E366A::length() const
{
	return Rva002226E5TextPlusString::length() + m_third.m_len;
}

// ?length@Rva005F1B75@@QBEHXZ @0x005F1B75 27B: three-part string extension (TextPlusString base at 0x00513B94 plus third string len at +0x0C); chain from 0x00513B94 landing; callers 0x005F1BAA 0x005F1D47.
struct Rva005F1B75 : Rva002226E5TextPlusString
{
	int length() const;
	const AsciiString *m_third;
};
int Rva005F1B75::length() const
{
	int third = m_third->getLength();
	int base = Rva002226E5TextPlusString::length();
	return base + third;
}
