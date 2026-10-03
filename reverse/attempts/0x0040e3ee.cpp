// ??0Rva0040E3EE@@QAE@XZ
// partial score=0.98 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_STLP_USE_MALLOC /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
#include <vector>
struct BfmeE16 { float x, y, z, w; };
template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class Rva0040E3EE;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
private:
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
	struct Header { int ref_count; unsigned short length; unsigned short capacity; T data[1]; };
	Header *m_data;
};
class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
};
extern AsciiString TheEmptyString;
class Rva00330757Member
{
public:
	Rva00330757Member();
private:
	_STL::vector<BfmeE16> m_items;
	int m_flags;
};
class Rva0040E3EEBase
{
public:
	Rva0040E3EEBase() {}
	~Rva0040E3EEBase();
};
class Rva0040E3EE : public Rva0040E3EEBase
{
public:
	Rva0040E3EE();
private:
	const void *m_vtable;
	Rva00330757Member m_04;
	unsigned char m_14;
	char m_pad15[3];
	StringBase<char> m_18;
	int m_1c;
	StringBase<char> m_20;
	int m_24;
	int m_28;
	int m_2c;
	int m_30;
	int m_34;
	int m_38;
	int m_3c;
	_STL::vector<BfmeE16> m_40;
	_STL::vector<BfmeE16> m_4c;
	float m_58;
	float m_5c;
	int m_60;
	int m_64;
};

// ??0Rva0040E3EE@@QAE@XZ present-unmatched
Rva0040E3EE::Rva0040E3EE()
	: Rva0040E3EEBase(), m_14(0), m_18(TheEmptyString), m_1c(0), m_20(TheEmptyString), m_24(0xFF000000), m_28(0xFF000000), m_2c(1), m_30(0), m_34(0), m_38(0), m_3c(1), m_40(_STL::allocator<BfmeE16>()), m_4c(_STL::allocator<BfmeE16>()), m_58(0.0f), m_5c(0.0f), m_60(0), m_64(0)
{
	m_vtable = reinterpret_cast<const void *>(0x00C394F0);
}