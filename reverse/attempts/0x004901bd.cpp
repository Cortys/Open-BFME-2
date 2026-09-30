// ??0LargeGroupBonusUpdateModuleData@@QAE@XZ
// partial score=0.9 date=2026-09-30
// cl: /O1 /arch:SSE /GX /Oy- /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// LargeGroupBonusUpdateModuleData default constructor @0x4901BD (104B). Own
// INI table 0x00C4D1A8 names the members (UpdateRate +8, HordeMemberFilter +C,
// Count +10, Radius +14, RubOffRadius +1C, FlagSubObjectNames +20,
// AttributeModifier +2C); retail has a single EH state (the base dtor), so
// the filter has no destructor and nothing after the vector ctor can throw.
// Fixed from the earlier stash: RubOffRadius 20.0f is a compiler literal
// (retail pool 0x007C5CCC), which puts the flag store and the movss load in
// retail order; real vtable, real _STL::vector<AsciiString> (rowed alias
// 0x211E58), no hard-coded addresses. Sole gap: retail loads the UpdateRate
// global 0x00A03994 first, above the state-0 store and the vtable store, while
// cl keeps it at its init-list position. Refuted: const vs plain extern, an
// intermediate base carrying the member (extra vptr store), and a base ctor
// argument (load first but the +8 store then precedes the state store).
#include <vector>
class AsciiString
{
public:
	AsciiString() : m_data(0) {}
private:
	char *m_data;
};
class Rva003623E5Filter
{
public:
	Rva003623E5Filter();
private:
	unsigned char m_data[4];
};
class UpdateModuleData
{
public:
	UpdateModuleData() {}
	virtual ~UpdateModuleData();
};
extern const int g_00A03994;
class LargeGroupBonusUpdateModuleData : public UpdateModuleData
{
public:
	LargeGroupBonusUpdateModuleData();
	virtual ~LargeGroupBonusUpdateModuleData();
private:
	int m_unused04;
	int m_updateRate;
	Rva003623E5Filter m_hordeMemberFilter;
	int m_count;
	float m_radius;
	bool m_alliesOnly;
	float m_rubOffRadius;
	_STL::vector<AsciiString> m_flagSubObjectNames;
	AsciiString m_attributeModifier;
};
// ??0LargeGroupBonusUpdateModuleData@@QAE@XZ @0x004901BD
LargeGroupBonusUpdateModuleData::LargeGroupBonusUpdateModuleData() :
	m_updateRate(g_00A03994),
	m_count(0),
	m_radius(0.0f),
	m_alliesOnly(true),
	m_rubOffRadius(20.0f)
{
}
