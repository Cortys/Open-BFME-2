// cl: /O1 /DNDEBUG /MD
//
// Object::setWeaponSetFlag / Object::clearWeaponSetFlag, retail 0x00290963
// (173 bytes) and 0x00290A10 (177 bytes), adjacent in retail Object.cpp.
// Identity: Zero Hour Object.cpp and the BFME1 donor Object.cpp name these two
// methods with this shape: set or clear the WeaponSetType bit in
// m_curWeaponSetFlags, then m_weaponSet.updateWeaponSet(this), then mirror the
// flag onto the model condition from TheWeaponSetTypeToModelConditionTypeMap.
// Target evidence for the layout: the matched getter 0x0028B7AE (lea eax,
// [ecx+0x370]) is getWeaponSetFlags, the +0x330 member passed as this to
// 0x002C8C97 is m_weaponSet (that body is ZH WeaponSet::updateWeaponSet:
// findWeaponTemplateSet on the template with getWeaponSetFlags, compared with
// the current set at +4; pinned here), and the map is the int table at VA
// 0x00C006C8 indexed by the weapon set type.
// BFME2 deltas: the model condition bits live on the Object (word array at
// +0x10C, the base the variable-index test uses here) instead of the
// Drawable; MODELCONDITION_INVALID (-1) entries are skipped; and the model
// conditions 0x12D/0x12E/0x12F additionally queue 0x1BD/0x1BE/0x1BF on the
// helper module at +0x230 for g_Va00DBA4E4 frames (0x004DE85F, which sets that
// condition and records its expiry frame; pinned by address, class unknown).
// Bit indexes are unsigned (shr) as in a bitset; the masked-word test makes cl
// keep the mask in a register and test/or the word in memory.

enum WeaponSetType
{
	WEAPONSET_NONE = 0
};
enum ModelConditionFlagType
{
	MODELCONDITION_INVALID = -1
};
class Object;
class WeaponSet
{
public:
	void updateWeaponSet(const Object *obj);
private:
	unsigned char m_data[0x40];
};
class WeaponSetFlags
{
public:
	void set(unsigned int i)
	{
		m_words[i >> 5] |= 1U << (i & 0x1f);
	}
	void clear(unsigned int i)
	{
		m_words[i >> 5] &= ~(1U << (i & 0x1f));
	}
private:
	unsigned int m_words[2];
};
class Rva0010CConditionBits
{
public:
	unsigned int test(unsigned int bit) const
	{
		return m_words[bit >> 5] & (1U << (bit & 0x1f));
	}
	void set(unsigned int bit)
	{
		m_words[bit >> 5] |= 1U << (bit & 0x1f);
	}
	void clear(unsigned int bit)
	{
		m_words[bit >> 5] &= ~(1U << (bit & 0x1f));
	}
private:
	unsigned int m_words[20];
};
class Rva004DE85FModule
{
public:
	void rva004DE85F(int condition, int frames);
};
extern const ModelConditionFlagType TheWeaponSetTypeToModelConditionTypeMap[];
extern int g_Va00DBA4E4;
class Object
{
public:
	void rva0028AE6D();
	void setWeaponSetFlag(WeaponSetType wst);
	void clearWeaponSetFlag(WeaponSetType wst);
private:
	unsigned char m_pad000[0x10C];
	Rva0010CConditionBits m_conditionBits; // +0x10C
	unsigned char m_pad15C[0x230 - 0x15C];
	Rva004DE85FModule *m_230; // +0x230
	unsigned char m_pad234[0x330 - 0x234];
	WeaponSet m_weaponSet; // +0x330
	WeaponSetFlags m_curWeaponSetFlags; // +0x370
};
void Object::setWeaponSetFlag(WeaponSetType wst)
{
	m_curWeaponSetFlags.set(wst);
	m_weaponSet.updateWeaponSet(this);
	ModelConditionFlagType mc = TheWeaponSetTypeToModelConditionTypeMap[wst];
	if (mc != MODELCONDITION_INVALID)
	{
		if (m_conditionBits.test(mc) == 0)
		{
			m_conditionBits.set(mc);
			rva0028AE6D();
		}
	}
	if (mc == 0x12D)
		m_230->rva004DE85F(0x1BD, g_Va00DBA4E4);
	else if (mc == 0x12E)
		m_230->rva004DE85F(0x1BE, g_Va00DBA4E4);
	else if (mc == 0x12F)
		m_230->rva004DE85F(0x1BF, g_Va00DBA4E4);
}
void Object::clearWeaponSetFlag(WeaponSetType wst)
{
	m_curWeaponSetFlags.clear(wst);
	m_weaponSet.updateWeaponSet(this);
	ModelConditionFlagType mc = TheWeaponSetTypeToModelConditionTypeMap[wst];
	if (mc != MODELCONDITION_INVALID)
	{
		if (m_conditionBits.test(mc) != 0)
		{
			m_conditionBits.clear(mc);
			rva0028AE6D();
		}
	}
	if (mc == 0x12D)
		m_230->rva004DE85F(0x1BD, g_Va00DBA4E4);
	else if (mc == 0x12E)
		m_230->rva004DE85F(0x1BE, g_Va00DBA4E4);
	else if (mc == 0x12F)
		m_230->rva004DE85F(0x1BF, g_Va00DBA4E4);
}
