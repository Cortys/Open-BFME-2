// ??0CallHelpOnDamageModuleData@@QAE@XZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /arch:SSE /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
// CallHelpOnDamageModuleData default constructor @0x4BB3A7 (116B). INI tables
// 0x00C6BB18 and 0x00C59F70 name the members (DamageTypes +8, CallRadius +C,
// CallDelay +10, MoveToAttacker +14, ValidObjects +18). Retail unwind map:
// state 0 destroys the polymorphic base, state 1 the filter at +0x18 through
// the pinned Rva003623E5Filter dtor 0x360D26, so the filter is a real member
// (its ctor 0x3623E5 and applyFilter 0x362120 are pinned under that class)
// and the shared fixed storage 0x009FEFA4 is copied by value. Honest model:
// real vtable, named externs, no fake dtors. The damage mask at +8 must be
// initialised before the state-0 store in retail, which only a second base
// (or a base member) gives; as a second base the sole gap is that retail
// hoists the 100.0f literal load above the or [esi+8],-1 while cl orders the
// or first. Refuted: derived member (or after vtable), 12-byte single base
// (or above the this save), base order, |= spellings, /G5-/G7 /Os /Op /Oy-
// /Oi /Ob1 /Ob2 /arch:SSE2 /GS-.
extern const int g_009BA4E4;
class BfmeFixedStorage0004543D
{
public:
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other);
	~BfmeFixedStorage0004543D() {}
private:
	unsigned char m_bytes[28];
};
extern const BfmeFixedStorage0004543D g_009FEFA4;
class Rva003623E5Filter
{
public:
	Rva003623E5Filter();
	~Rva003623E5Filter();
	void applyFilter(BfmeFixedStorage0004543D storage);
private:
	int m_x;
};
struct DamageTypeMask
{
	DamageTypeMask() : m_mask(0xFFFFFFFF) {}
	unsigned int m_mask;
};
class UpdateModuleData
{
public:
	UpdateModuleData() {}
	virtual ~UpdateModuleData();
private:
	int m_gap04;
};
class CallHelpOnDamageModuleData : public UpdateModuleData, public DamageTypeMask
{
public:
	CallHelpOnDamageModuleData();
	virtual ~CallHelpOnDamageModuleData();
private:
	float m_callRadius;
	int m_callDelay;
	bool m_moveToAttacker;
	Rva003623E5Filter m_validObjects;
};
// ??0CallHelpOnDamageModuleData@@QAE@XZ @0x004BB3A7
CallHelpOnDamageModuleData::CallHelpOnDamageModuleData() :
	m_callRadius(100.0f),
	m_callDelay(4 * g_009BA4E4),
	m_moveToAttacker(false)
{
	m_validObjects.applyFilter(g_009FEFA4);
}
