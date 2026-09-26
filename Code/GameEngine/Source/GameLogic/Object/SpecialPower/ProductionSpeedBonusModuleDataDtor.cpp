// cl: /O1 /DNDEBUG /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE /GX
// stlport
//
// ??1ProductionSpeedBonusModuleData@@UAE@XZ, retail 0x004C3064, 56 bytes.
// ProductionSpeedBonus ModuleData dtor over the pinned Rva004930A0 base
// (0x4930A0, 0x7C bytes): destroys the Type string list at +0x84 through the
// rowed vector<AsciiString> dtor at 0x0002CC70 (state 0) then the base through
// the rowed 0x0049334F dtor. Layout from the matched ctor 0x004C2FE6
// (NumberOfFrames at +0x7C plus SpeedMultiplier at +0x80 plus Type at +0x84
// size 0x90 via factory 0x00251AFE) and table 0x00C5C9A0. Own vtable
// 0x00C5CA80 (??_7 pin); caller is the slot-0 ??_G at 0x004C3048. Shape follows
// InvisibilitySpecialPowerModuleDataDtor (novtable derived suppressing the
// entry store retail lacks plus single member plus base call).

#include <vector>

class AsciiString
{
public:
	~AsciiString();

private:
	char *m_data;
};

class Rva004930A0
{
public:
	virtual ~Rva004930A0();

private:
	unsigned char m_pad[0x7C - 4];
};

class __declspec(novtable) ProductionSpeedBonusModuleData : public Rva004930A0
{
public:
	virtual ~ProductionSpeedBonusModuleData();

private:
	int m_numberOfFrames; // +0x7C NumberOfFrames
	float m_speedMultiplier; // +0x80 SpeedMultiplier
	_STL::vector<AsciiString, _STL::allocator<AsciiString> > m_type; // +0x84 Type
};

ProductionSpeedBonusModuleData::~ProductionSpeedBonusModuleData()
{
}
