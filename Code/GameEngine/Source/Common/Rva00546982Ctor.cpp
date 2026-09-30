// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva00546982@@QAE@XZ @0x00546982 59B evidence: stores vtable 0x0086A314; base SpecialPowerModuleData default rowed 0x005488C5; set<AsciiString> at +0x18 via rowed 0x000D3A71; bool at +0x24 false; caller 0x00355060.
// Honest-address ctor via vtable store (naming rule).
#include <set>

template <typename T> class StringBase {
	friend class AsciiString;
public:
	StringBase() : m_data(0) {}
	StringBase(const StringBase &);
	~StringBase();
protected:
	void *m_data;
};

class AsciiString : public StringBase<char> {
public:
	AsciiString() {}
	AsciiString(const AsciiString &other);
	~AsciiString();
};

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL {
template <> struct less<AsciiString> {
	bool operator()(const AsciiString &left, const AsciiString &right) const {
		return left < right;
	}
};
}

class SpecialPowerModuleData
{
public:
	SpecialPowerModuleData();
	virtual ~SpecialPowerModuleData();
private:
	unsigned char m_pad04[0x18 - 4];
};

class Rva00546982 : public SpecialPowerModuleData
{
public:
	Rva00546982();
	virtual ~Rva00546982();
private:
	_STL::set<AsciiString> m_18;
	bool m_24;
};

Rva00546982::Rva00546982()
	: SpecialPowerModuleData()
	, m_18()
{
	m_24 = false;
}
