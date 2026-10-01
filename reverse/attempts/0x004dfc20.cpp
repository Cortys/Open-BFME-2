// ??1?$hashtable@U?$pair@$$CBW4NameKeyType@@VArmorTemplate@@@_STL@@W4NameKeyType@@U?$hash@W4NameKeyType@@@rts@@U?$_Select1st@U?$pair@$$CBW4NameKeyType@@VArmorTemplate@@@_STL@@@2@U?$equal_to@W4NameKeyType@@@5@V?$allocator@U?$pair@$$CBW4NameKeyType@@VArmorTemplate@@@_STL@@@2@@_STL@@QAE@XZ
// partial score=0.99 date=2026-10-01
// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
// ?rva004DFC20@Rva004DFC20@@QAEXXZ RVA 0x004DFC20 size 57
// 57B clear+free-buckets shape (same as ArmorStore hashtable dtor 0x003609BE
// and WindowVideo 0x0053F378, MALLOC config). Calls rowed Armor hashtable
// clear 0x001DBCDC and rowed free 0x00030830. Caller 0x004E01CF lea
// ecx,[esi+0x14]. Trying holder-emitted hashtable dtor first.
#include <hash_map>
#include <cstddef>

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

namespace rts
{
template <typename T> struct hash
{
	size_t operator()(const T &value) const { return (size_t)value; }
};
template <typename T> struct equal_to
{
	bool operator()(const T &a, const T &b) const { return a == b; }
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
	rts::equal_to<NameKeyType> > ArmorTemplateMap;

class Rva004DFC20Holder
{
public:
	Rva004DFC20Holder();
	~Rva004DFC20Holder();
private:
	ArmorTemplateMap m_map;
};

// ??0Rva004DFC20Holder@@QAE@XZ present-unmatched
Rva004DFC20Holder::Rva004DFC20Holder()
{
	m_map.clear();
}

// ??1Rva004DFC20Holder@@QAE@XZ present-unmatched
Rva004DFC20Holder::~Rva004DFC20Holder()
{
	m_map.clear();
}
