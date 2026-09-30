// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva00546982@@QAE@XZ @0x00546982 59B evidence: stores vtable 0x0086A314; base SpecialPowerModuleData default rowed 0x005488C5; set<AsciiString> at +0x18 via rowed 0x000D3A71; bool at +0x24 false; caller 0x00355060.
// Honest-address ctor via vtable store (naming rule).
#include <set>

#include "ascii_string.h"


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
	SpecialPowerModuleData(const SpecialPowerModuleData &other);
	virtual ~SpecialPowerModuleData();
private:
	unsigned char m_pad04[0x18 - 4];
};

class Rva00546982 : public SpecialPowerModuleData
{
public:
	Rva00546982();
	Rva00546982(const Rva00546982 &other);
	virtual ~Rva00546982();
	Rva00546982 *rva005469FD();
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

Rva00546982::Rva00546982(const Rva00546982 &other)
	: SpecialPowerModuleData(other)
	, m_18()
{
	m_24 = false;
}

Rva00546982 *Rva00546982::rva005469FD()
{
	return new Rva00546982(*this);
}
