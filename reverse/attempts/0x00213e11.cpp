// ??0Rva00213E11@@QAE@XZ
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
// ??0Rva00213E11@@QAE@XZ retail 0x00213E11 31 bytes.
// Default ctor forwarding to rowed hashtable ctor 0x002138E5 with 100 buckets
// plus empty hash equal allocator temporaries sharing the [ebp-1] slot.
// Class proven by same-this hashtable call and this-return shape. Callers in
// UNCLAIMED 0x00213EEF. Precedent: ArmorStoreCtor hashtable layout.
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

class Rva00213E11
{
public:
	Rva00213E11();
	ArmorTemplateMap m_map;
};

Rva00213E11::Rva00213E11()
	: m_map(100, rts::hash<NameKeyType>(), std::equal_to<NameKeyType>(), std::allocator<void *>())
{
}
