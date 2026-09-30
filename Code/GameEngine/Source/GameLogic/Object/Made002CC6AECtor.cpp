// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /DNDEBUG
// stlport
//
// ??0Made002CC6AE@@QAE@XZ @0x00508E11 (90B).
// SpecialModelConditionNugget ctor: base Rva00507823 at 0x0050775B, vtable
// 0x00864404, AsciiString vector at +0x128 via pinned Vector_base 0x00211E58
// cleared with rowed erase 0x0002CCFC, int at +0x134 zeroed. Size 0x138 from
// WeaponNuggetParse news. Caller parseSpecialModelConditionNugget 0x002CC6D3.
// Same vector-erase-in-ctor idiom as Rva004E364F precedent.
#include <vector>

#include "ascii_string.h"

class Rva00507823
{
public:
	virtual ~Rva00507823();
	Rva00507823();
private:
	unsigned char m_pad[0x128 - 4];
};

class Made002CC6AE : public Rva00507823
{
public:
	Made002CC6AE();
private:
	_STL::vector<AsciiString> m_vec128;
	int m_134;
};

Made002CC6AE::Made002CC6AE()
{
	m_vec128.clear();
	m_134 = 0;
}
