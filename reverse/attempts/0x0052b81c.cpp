// ??0Rva0052B81C@@QAE@XZ
// partial score=0.97 date=2026-10-02
// stlport
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// ??0Rva0052B81C@@QAE@XZ Retail RVA 0x0052B81C 31 bytes.
// Honest-address default ctor whose body is byte-identical to the Armor
// hash_map default ctor at 0x00360B99 (push 0x64 plus three empty params
// forwarded to the Armor hashtable ctor). Callee is the Armor hashtable
// copy at 0x0052B7B8 (dup of rowed 0x00360B59). Caller 0x0052B84F unclaimed.
#include <hash_map>
#include <cstddef>

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	NAMEKEY_MAX = 1 << 23,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

class ArmorTemplate
{
public:
	float m_damageCoefficient[38];
};

namespace rts
{

template <typename T> struct hash
{
	size_t operator()(const T &value) const;
};

}

typedef _STL::hashtable<
	_STL::pair<const NameKeyType, ArmorTemplate>,
	NameKeyType,
	rts::hash<NameKeyType>,
	_STL::_Select1st<_STL::pair<const NameKeyType, ArmorTemplate> >,
	_STL::equal_to<NameKeyType>,
	_STL::allocator<_STL::pair<const NameKeyType, ArmorTemplate> > > ArmorHashtableForRva;

class Rva0052B81C
{
public:
	Rva0052B81C();
private:
	ArmorHashtableForRva m_table;
};

Rva0052B81C::Rva0052B81C()
	: m_table(100, rts::hash<NameKeyType>(), _STL::equal_to<NameKeyType>(), _STL::allocator<_STL::pair<const NameKeyType, ArmorTemplate> >())
{
}
