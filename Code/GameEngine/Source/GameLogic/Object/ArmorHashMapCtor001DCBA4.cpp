// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
// ?rva001DCBA4@Rva001DCBA4@@QAEXXZ @0x001DCBA4 31B evidence: caller 0x001DCBEA; hashtable ctor 0x001DCB64 calls rts _M_initialize_buckets 0x00148DDF like 0x002896AA; 100 buckets
// NOTE: emitted as ??0Rva001DCBA4@@QAE@XZ (ctor returns this via mov eax esi)
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

template <typename T> struct equal_to
{
	bool operator()(const T &a, const T &b) const;
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

typedef _STL::hashtable<
	ArmorTemplateMap::value_type,
	NameKeyType,
	rts::hash<NameKeyType>,
	_STL::_Select1st<ArmorTemplateMap::value_type>,
	rts::equal_to<NameKeyType>,
	_STL::allocator<ArmorTemplateMap::value_type> > ArmorHashtable;

class Rva001DCBA4
{
public:
	Rva001DCBA4();
private:
	ArmorHashtable m_table;
};

Rva001DCBA4::Rva001DCBA4() : m_table(100, rts::hash<NameKeyType>(), rts::equal_to<NameKeyType>(), std::allocator<ArmorTemplateMap::value_type>())
{
}
