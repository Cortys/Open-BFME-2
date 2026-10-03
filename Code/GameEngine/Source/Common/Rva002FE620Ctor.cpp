// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /O1 /Ob2
// ??0Rva002FE620@@QAE@XZ @0x002FE620 123B: ctor storing vtable 0x00807240. Evidence: callers at 0x002FE9A7 0x002FFE38; two AsciiString members at +4 +0x1B8.
#include "ascii_string.h"

class Rva002FE620
{
public:
	virtual ~Rva002FE620();
	Rva002FE620();
	AsciiString m_s1; // +4
	int m_08; // +8
	int m_0C; // +0xC
	int m_10; // +0x10
	int m_14; // +0x14
	char _pad18[0x50]; // +0x18..+0x67
	int m_68; // +0x68
	char _pad6C[0x50];
	int m_BC; // +0xBC
	char _padC0[0x50];
	int m_110; // +0x110
	char _pad114[0x50];
	int m_164; // +0x164
	char _pad168[0x50];
	AsciiString m_1B8; // +0x1B8
	int m_1BC; // +0x1BC
};

Rva002FE620::Rva002FE620() :
	m_s1(),
	m_08(0),
	m_0C(1),
	m_10(2),
	m_1B8(),
	m_1BC(0)
{
	m_s1.clear();
	m_1B8.clear();
	m_14 = 0;
	m_68 = 0;
	m_BC = 0;
	m_110 = 0;
	m_164 = 0;
}
