// cl: /O1 /MD
// stlport
//
// ?rva003EE900@Rva003EE900@@QAEXH@Z @0x003EE900 26B.
// Forwarder to map-dispatch notify0C at 0x004E35D5: passes static
// AsciiString at 0x00E02E7C (HomeRegionHighlight) with (arg+0x54, 0).
// Owner map-holder sits at this+8 (same layout as Rva004E35D5Notify).
// Chain of Rva004E35D5Notify (160B); retail pushes 0, arg+0x54, string.
#include <map>

typedef int Int;

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
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL
{
template <> struct less<AsciiString>
{
	bool operator()(const AsciiString &left, const AsciiString &right) const
	{
		return left < right;
	}
};
}

class Rva004E35D5
{
public:
	void rva004E35D5(const AsciiString &key, Int a, Int b);
private:
	_STL::map<AsciiString, AsciiString> m_map;
};

extern AsciiString g_Rva00E02E7C;
extern AsciiString g_Rva00E02E78;
extern AsciiString g_Rva00E02E80;
extern AsciiString g_Rva00E02E68;

class Rva003EE900
{
public:
	void rva003EE900(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EE884
{
public:
	void rva003EE884(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EE966
{
public:
	void rva003EE966(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EEA9D
{
public:
	void rva003EEA9D(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

void Rva003EE900::rva003EE900(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E7C, (Int)((char *)arg + 0x54), 0);
}

void Rva003EE884::rva003EE884(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E78, (Int)((char *)arg + 0x54), 0);
}

void Rva003EE966::rva003EE966(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E80, (Int)((char *)arg + 0x54), 0);
}

void Rva003EEA9D::rva003EEA9D(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E68, (Int)((char *)arg + 0x54), 0);
}
