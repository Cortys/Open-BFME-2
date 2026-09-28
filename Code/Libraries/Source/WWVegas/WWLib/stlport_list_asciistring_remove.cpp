// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?remove@?$list@VAsciiString@@V?$allocator@VAsciiString@@@_STL@@@_STL@@QAEXABVAsciiString@@@Z 0x005C9E90 67B
// Evidence: iterates list erasing AsciiString matches via rowed StringBase compare 0x000069D6 and rowed list erase 0x000BC67A; callers 0x005CADD3/0x005CAE72; retail calls compare (int test eax) so operator== is inlined here to compare==0.
#include <list>

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	__forceinline ~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	int compare(const StringBase<T> &other) const;
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString();
	AsciiString(const char *text);
	AsciiString(const AsciiString &other);
	~AsciiString();
};

__forceinline bool operator==(const AsciiString &a, const AsciiString &b)
{
	return a.compare(b) == 0;
}
bool operator<(const AsciiString &a, const AsciiString &b);

template void _STL::list<AsciiString, _STL::allocator<AsciiString> >::remove(const AsciiString &);
