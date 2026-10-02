// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /DWIN32 /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP= /EHsc
// stlport
// ??1Rva002E66F2@@UAE@XZ 0x002E66F2 89B
// Evidence: chain from 0x002E6551 clear plus vectorAscii 0x0002CC70 plus wide release 0x00036E70 plus base 0x001B4E74; vtables 0x00804FA8 0x00804E90; caller 0x002E67D1.
#include <vector>
#include "ascii_string.h"
#include "unicode_string.h"

class AsciiStringMember
{
public:
	~AsciiStringMember();
};

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

extern const void *const g_00804E90[];

class Rva002E66F2Mid : public GameEngineDeletingBase
{
public:
	virtual ~Rva002E66F2Mid() { *(const void **)this = g_00804E90; }
};

class Rva002E6551
{
public:
	void rva002E6551();
};

class Rva002E66F2 : public Rva002E66F2Mid
{
public:
	virtual ~Rva002E66F2();

private:
	char m_pad0C[0x11];
	unsigned char m_flag1d;
	char m_pad1e[0x02];
	UnicodeString m_wide20;
	void *m_list24;
	char m_pad28[0x04];
	void *m_ptr2c;
	void *m_ptr30;
	_STL::vector<AsciiString> m_vec34;
};

Rva002E66F2::~Rva002E66F2()
{
	((Rva002E6551 *)this)->rva002E6551();
}

// Retail's data references in this unit's matched rows land on globals defined
// under other spellings at the same addresses (addend-corrected DIR32). Bind them.
#pragma comment(linker, "/alternatename:?g_00804E90@@3QBQBXB=??_7Rva002E55D8@@6B@")
