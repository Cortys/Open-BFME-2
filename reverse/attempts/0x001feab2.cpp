// ??0Rva001FEAB2@@QAE@XZ
// partial score=0.99 date=2026-10-03
// ??0Rva001FEAB2@@QAE@XZ
// partial score=0.99 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport

// ??0Rva001FEAB2@@QAE@XZ, RVA 0x001FEAB2, 31B. Unlock lane: default ctor
// constructing ArmorTemplateMap at +0 via rowed hashtable ctor 0x001FE312
// (100 buckets via inlined hash_map default) then returning this in eax.
// Callers 0x001FEC38 in 0x001FEB8B plus 0x002B101C 0x002B102B in 0x002B0F3C.
// Same map type as ArmorStoreCtor 0x00360B59. Owner unproven so honest name.
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

typedef _STL::hash_map<
	NameKeyType,
	ArmorTemplate,
	rts::hash<NameKeyType>,
	_STL::equal_to<NameKeyType> > ArmorTemplateMap;

class Rva001FEAB2
{
public:
	Rva001FEAB2();

private:
	ArmorTemplateMap m_map;
};

// ??0Rva001FEAB2@@QAE@XZ present-unmatched
Rva001FEAB2::Rva001FEAB2() : m_map(100, rts::hash<NameKeyType>(), _STL::equal_to<NameKeyType>(), _STL::allocator<_STL::pair<const NameKeyType, ArmorTemplate> >())
{
}
