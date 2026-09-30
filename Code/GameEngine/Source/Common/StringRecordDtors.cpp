// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /DNDEBUG
//
// Non-virtual record destructors built from string members (0x00036410 is
// the folded AsciiString/StringBase<char> teardown, 0x00036E70 the wide one,
// 0x0002CC70 the AsciiString vector dtor). None of these bodies stores a
// vptr, and each tears down a member at +0x00, so the records are
// non-polymorphic; the older ??1Rva...@@UAE@XZ pin spelling at 0x00111B25
// cannot describe this body and is left as recorded. Owner types are
// unrecovered: the names are address-derived, and only the member offsets
// and callees are target facts.
//
// ??1Rva00111B25Record@@QAE@XZ         @0x00111B25 53B: strings +0x18, +0x00
// ??1Rva0007BB16Record@@QAE@XZ         @0x0007BB16 53B: strings +0x08, +0x00,
//   0x24-byte element proven by the rowed range destroy at 0x0007C2D7 (steps
//   0x24 via this dtor) and its vector callers at 0x0007C5D5/0x0007C614; tail
//   bytes past +0x0C are unrecovered. The 0x24 stride also matches the retail
//   copy at 0x00151336 (two strings at +0x00/+0x08 plus tail).
// ??1BfmeStringRecord000B94D2@@QAE@XZ  @0x000B6CF1 53B: strings +0x04, +0x00
// ??1Rva000543F5Record@@QAE@XZ         @0x000543F5 53B: wide +0x04, narrow +0x00
// ??1Rva000BEDF0Record@@QAE@XZ         @0x000BEDF0 53B: vector +0x04, string +0x00
// ??1Rva0033B352Record@@QAE@XZ         @0x0033B352 53B: wide +0x04, narrow +0x00

#include "ascii_string.h"

class BfmeWideString000543F5
{
public:
	~BfmeWideString000543F5();

private:
	void *m_data;
};

class RvaVecAscii
{
public:
	~RvaVecAscii();

private:
	int m_x[3];
};

struct Rva00111B25Record
{
	~Rva00111B25Record();
	AsciiString m_00;
	int m_pad04[5];
	AsciiString m_18;
};
Rva00111B25Record::~Rva00111B25Record() {}

struct Rva0007BB16Record
{
	~Rva0007BB16Record();
	AsciiString m_00;
	int m_04;
	AsciiString m_08;
	int m_tail0C[6];
};
Rva0007BB16Record::~Rva0007BB16Record() {}

struct BfmeStringRecord000B94D2
{
	~BfmeStringRecord000B94D2();
	AsciiString m_00;
	AsciiString m_04;
};
BfmeStringRecord000B94D2::~BfmeStringRecord000B94D2() {}

struct Rva000543F5Record
{
	~Rva000543F5Record();
	AsciiString m_00;
	BfmeWideString000543F5 m_04;
};
Rva000543F5Record::~Rva000543F5Record() {}

struct Rva000BEDF0Record
{
	~Rva000BEDF0Record();
	AsciiString m_00;
	RvaVecAscii m_04;
};
Rva000BEDF0Record::~Rva000BEDF0Record() {}

struct Rva0033B352Record
{
	~Rva0033B352Record();
	AsciiString m_00;
	BfmeWideString000543F5 m_04;
};
Rva0033B352Record::~Rva0033B352Record() {}
