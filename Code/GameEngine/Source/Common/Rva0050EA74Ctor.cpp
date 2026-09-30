// cl: /O1 /EHsc /MD
// ??0Rva0050EA74@@QAE@HABVAsciiString@@@Z @0x0050EA74 69B
// Ctor with vtable 0x0086551C plus int at +8 plus AsciiString at +0xc via
// rowed StringBase copy 0x000365F0 plus zeroed +4 and byte +0x10; ret 8.
template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
	StringBase(const T *s);
	void releaseBuffer();
public:
	void set(const StringBase<T> &other);
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString
{
public:
	AsciiString(const AsciiString &that) : m_data(that.m_data) {}
	~AsciiString() { m_data.releaseBuffer(); }
	StringBase<char> m_data;
};

class Rva0050EA74Base
{
public:
	Rva0050EA74Base() : m_04(0) {}
	~Rva0050EA74Base();
	int m_04;
};

class Rva0050EA74 : public Rva0050EA74Base
{
public:
	Rva0050EA74(int a, const AsciiString &b);
	virtual ~Rva0050EA74();
	int m_08;
	AsciiString m_0c;
	unsigned char m_10;
};

Rva0050EA74::Rva0050EA74(int a, const AsciiString &b) : m_08(a), m_0c(b)
{
	m_10 = 0;
}
