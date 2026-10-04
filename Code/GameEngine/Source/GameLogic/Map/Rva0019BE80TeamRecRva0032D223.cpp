// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/open-bfme-1/inputs/reference/shims/stringbaseascii /Ireference/open-bfme-1/inputs/reference/shims/buildlistinfo /Ireference/open-bfme-1/inputs/reference/shims/moduledata /Ireference/open-bfme-1/inputs/reference/shims/sweep /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/game/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/game/GameEngine/Source/GameLogic/Map
// stlport
//
// ?rva0032D223@Rva0019BE80TeamRec@@QAEXHABVAsciiString@@0@Z
// retail 0x0032D223, 86 bytes. Same TeamRecord layout as the rowed
// Rva0019BE80TeamRec::updateTeam in
// Rva0019B850TeamRecUpdate_Rva0019BE80TeamRec_updateTeam.cpp: vector at +0x0C
// of 16-byte records (shorts at +0/+2/+4/+6, tree link at +8, Dict at +0x0C).
// Sets two Dict strings then re-links via updateTeam. First call is the rowed
// BfmeIndexedNodesFM::bfmePrepareRelease which shares the tree+nodes prefix.
// Dict::setAsciiString is declared with int to mangle to the rowed
// ?setAsciiString@Dict@@QAEXHABVAsciiString@@@Z; the cache get() returns the
// real NameKeyType enum (W4) and converts implicitly to int. Operands use
// field0c[index] which emits the retail mov ecx+lea shape.

#define _STLP_NO_EXCEPTIONS 1
#include "ascii_string.h"
#include <map>
#include <vector>

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

class Rva00148F5ECache
{
public:
	NameKeyType get();
};

extern Rva00148F5ECache g_00DBD9FC;
extern Rva00148F5ECache g_00DBD9F4;

class BfmeIndexedNodesFM
{
public:
	void bfmePrepareRelease(int index);
};

class Dict
{
public:
	void setAsciiString(int key, const AsciiString &value);
private:
	void *m_data;
};

typedef _STL::pair<AsciiString, AsciiString> TeamKey0032D223;
struct TeamLess0032D223 : _STL::less<TeamKey0032D223> {};
struct TeamRecord0032D223
{
	short field00, field02, field04, field06;
	void *field08;
	Dict field0c;
};

class Rva0019BE80TeamRec
{
	_STL::map<TeamKey0032D223, int, TeamLess0032D223> field00;
	_STL::vector<TeamRecord0032D223> field0c;
public:
	void updateTeam(int index);
	void rva0032D223(int index, const AsciiString &a, const AsciiString &b);
};

typedef char RecordWidth0032D223[(sizeof(TeamRecord0032D223) == 16) ? 1 : -1];

void Rva0019BE80TeamRec::rva0032D223(int index, const AsciiString &a, const AsciiString &b)
{
	((BfmeIndexedNodesFM *)this)->bfmePrepareRelease(index);
	Dict *d = &field0c[index].field0c;
	d->setAsciiString(g_00DBD9FC.get(), a);
	d->setAsciiString(g_00DBD9F4.get(), b);
	updateTeam(index);
}
