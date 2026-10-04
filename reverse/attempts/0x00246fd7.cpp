// ??0Rva00246FD7@@QAE@XZ
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_NO_EXCEPTIONS
// stlport
// ??0Rva00246FD7@@QAE@XZ @ 0x00246FD7 (31B) honest default ctor building Armor
// hashtable member at +0 with 100 buckets plus three empty params. Evidence:
// 31B body pushes 0x64 with three copies of [ebp-1] then calls dup twin
// 0x0024619A of rowed Armor hashtable ctor 0x00360B59; callers at 0x002470E7
// and 0x002471F9 in 0x002470AE 714B. Same shape as landed twin 0x003A393A/31
// calling dup 0x003A37FA.
#include <hash_map>
#include <cstddef>

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	NAMEKEY_MAX = 1 << 23,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

namespace rts
{

template <typename T> struct hash
{
	size_t operator()(const T &value) const;
};

}

class ArmorTemplate
{
public:
	float m_damageCoefficient[38];
};

typedef std::hash_map<
	NameKeyType,
	ArmorTemplate,
	rts::hash<NameKeyType>,
	std::equal_to<NameKeyType> > ArmorTemplateMap;

typedef ArmorTemplateMap::value_type ArmorPair00246FD7;
typedef ArmorTemplateMap::hasher ArmorHasher00246FD7;
typedef ArmorTemplateMap::key_equal ArmorEqual00246FD7;
typedef ArmorTemplateMap::allocator_type ArmorAlloc00246FD7;

typedef _STL::hashtable<
	ArmorPair00246FD7,
	NameKeyType,
	ArmorHasher00246FD7,
	_STL::_Select1st<ArmorPair00246FD7>,
	ArmorEqual00246FD7,
	ArmorAlloc00246FD7> ArmorHashtable00246FD7;

class Rva00246FD7
{
public:
	Rva00246FD7();
private:
	ArmorHashtable00246FD7 m_table;
};

// ??0Rva00246FD7@@QAE@XZ present-unmatched
Rva00246FD7::Rva00246FD7() : m_table(100, ArmorHasher00246FD7(), ArmorEqual00246FD7(), ArmorAlloc00246FD7()) {}
