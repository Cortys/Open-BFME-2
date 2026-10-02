// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHsc /MD
// ??1Rva00221B42@@QAE@XZ @0x00221B0D 53B
// Dtor of Rva00221B42: AsciiString at +0x1C via releaseBuffer plus
// Rva00221A58 at +0 via its dtor (ICF twin of Open2Dtor4793C0 at 0x002218D0).
// Layout from rowed ctor 0x00221B42. Caller 0x00221C96. Evidence: retail
// bytes and member offsets.
#include "ascii_string.h"

class Rva0022185A
{
public:
	Rva0022185A(const Rva0022185A &other);
	~Rva0022185A();
private:
	AsciiString m_str;
	int m_04;
	unsigned char m_08;
};

class Rva00221A58
{
public:
	Rva00221A58(const Rva00221A58 &other);
	~Rva00221A58();
private:
	AsciiString m_00;
	AsciiString m_04;
	AsciiString m_08;
	Rva0022185A m_0C;
	int m_18;
};

class Rva00221B42
{
public:
	Rva00221B42(const AsciiString &a, const Rva00221A58 &b, class INI *ini);
	~Rva00221B42();
private:
	Rva00221A58 m_00;
	AsciiString m_1C;
};

Rva00221B42::~Rva00221B42()
{
}
