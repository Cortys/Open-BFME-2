// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva0054D8D8@@QAE@XZ @0x0054D8D8 128B. Non-virtual dtor with EH: three
// UnicodeString at +0x00/+0x04/+0x08, two list<AsciiString> at +0x1C/+0x20,
// three AsciiString at +0x24/+0x28/+0x30. Evidence: 8 calls in descending
// offset order with EH states 6..0 then -1; rowed releaseBuffer D 0x00036410
// G 0x00036E70 and List_base 0x002FECBC; unblocks deleting dtor 0x0054D958.
#include <list>

template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString();
	AsciiString(const AsciiString &other);
	~AsciiString();
};

class Rva0054D8D8
{
public:
	~Rva0054D8D8();
private:
	StringBase<unsigned short> m00;
	StringBase<unsigned short> m04;
	StringBase<unsigned short> m08;
	int m0C;
	int m10;
	int m14;
	int m18;
	_STL::list<AsciiString, _STL::allocator<AsciiString> > m1C;
	_STL::list<AsciiString, _STL::allocator<AsciiString> > m20;
	StringBase<char> m24;
	StringBase<char> m28;
	int m2C;
	StringBase<char> m30;
};

Rva0054D8D8::~Rva0054D8D8()
{
}
