// ??0Rva0041F8F4@@QAE@XZ
// partial score=0.96 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0041F8F4@@QAE@XZ, retail 0x0041F8F4, 31 bytes.
// Default ctor for hash_map wrapper: constructs ArmorTemplateMap member with
// 100 buckets via hashtable row 0x0041F720. Caller 0x0041F936 builds member
// at +0xC after vtable 0x0083B8C8. Returns this in eax.

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

typedef _STL::hashtable<
	_STL::pair<const NameKeyType, ArmorTemplate>,
	NameKeyType,
	rts::hash<NameKeyType>,
	_STL::_Select1st<_STL::pair<const NameKeyType, ArmorTemplate> >,
	_STL::equal_to<NameKeyType>,
	_STL::allocator<_STL::pair<const NameKeyType, ArmorTemplate> > > Ht0041F8F4;

class Rva0041F8F4
{
public:
	Rva0041F8F4();
private:
	Ht0041F8F4 m_ht;
};

// ??0Rva0041F8F4@@QAE@XZ present-unmatched
Rva0041F8F4::Rva0041F8F4() :
	m_ht(100, rts::hash<NameKeyType>(), _STL::equal_to<NameKeyType>(), _STL::allocator<_STL::pair<const NameKeyType, ArmorTemplate> >())
{
}
