// ??0Rva001DED2B@@QAE@XZ
// partial score=0.96 date=2026-10-03
// stlport
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// ??0Rva001DED2B@@QAE@XZ @0x001DED2B 31B: Armor hash_map-shape default ctor twin of 0x00360B99.
// Identical 31B pushing 0x64 with three empty params calling the Armor hashtable ctor
// (dup 0x001DE80F, twin of rowed 0x00360B59). Evidence: same bytes except call target;
// callers at 0x001DF91B (sites 0x001DF97A/0x001DF986) construct two members through
// this body. Honest ctor name for an unknown owner; hashtable layout matches
// ArmorStoreCtor's ArmorTemplateMap.
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

typedef ArmorTemplateMap::value_type ArmorPair001DED2B;
typedef ArmorTemplateMap::hasher ArmorHasher001DED2B;
typedef ArmorTemplateMap::key_equal ArmorEqual001DED2B;
typedef ArmorTemplateMap::allocator_type ArmorAlloc001DED2B;

typedef _STL::hashtable<
	ArmorPair001DED2B,
	NameKeyType,
	ArmorHasher001DED2B,
	_STL::_Select1st<ArmorPair001DED2B>,
	ArmorEqual001DED2B,
	ArmorAlloc001DED2B> ArmorHashtable001DED2B;

class Rva001DED2B
{
public:
	Rva001DED2B();
private:
	ArmorHashtable001DED2B m_ht;
};

// ??0Rva001DED2B@@QAE@XZ present-unmatched
Rva001DED2B::Rva001DED2B() : m_ht(100, ArmorHasher001DED2B(), ArmorEqual001DED2B(), ArmorAlloc001DED2B())
{
}
