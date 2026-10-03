// cl: /O1 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfme_windowvideo /Ireference/open-bfme-1/Code/GameEngine/Source/Common/System /Ireference/open-bfme-1/Code/GameEngine/Source/GameClient /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
// stlport
// ??0Rva00427157@@QAE@ABVAsciiString@@PBV0@@Z @0x00427157 62B ctor copies AsciiString at +0 via rowed StringBase copy 0x000365F0 fills 8 floats at +4 with 1.0f if src null else copies 8 floats from src+4 caller 0x004273FF
#include <hash_map>
#include "ascii_string.h"

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

namespace rts
{
template <typename T> struct hash;
template <> struct hash<NameKeyType>
{
	unsigned int operator()(const NameKeyType &v) const;
};
}

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const AsciiString &name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class Rva00427157
{
public:
	Rva00427157(const AsciiString &name, const Rva00427157 *src);
	float rva004270FA(int index);
	friend void Rva00427114Parse(class INI *ini, Rva00427157 *store);
private:
	AsciiString m_name;
	float m_vals[8];
};

typedef const char *ConstCharPtr;
typedef const ConstCharPtr *ConstCharPtrArray;

class INI
{
public:
	const char *getNextToken(const char *seps);
	float dup_002EE10(const char *token);
	int scanIndexList(const char *token, ConstCharPtrArray nameList);
};

extern ConstCharPtr g_00DC85C4[];

Rva00427157::Rva00427157(const AsciiString &name, const Rva00427157 *src) : m_name(name)
{
	if (!src) {
		for (int i = 0; i < 8; ++i)
			m_vals[i] = 1.0f;
	} else {
		for (int i = 0; i < 8; ++i)
			m_vals[i] = src->m_vals[i];
	}
}

float Rva00427157::rva004270FA(int index)
{
	return m_vals[index];
}

void Rva00427114Parse(INI *ini, Rva00427157 *store)
{
	const char *key = ini->getNextToken(0);
	const char *val = ini->getNextToken(0);
	float f = ini->dup_002EE10(val);
	int idx = ini->scanIndexList(key, g_00DC85C4);
	store->m_vals[idx] = f;
}

typedef _STL::hash_map<NameKeyType, const Rva00427157 *, rts::hash<NameKeyType>, _STL::equal_to<NameKeyType> > ArmorMap;

class LivingWorldAutoResolveArmorStore
{
public:
	const Rva00427157 *find(const AsciiString &name);
	const Rva00427157 *getDefault();
private:
	char m_pad[0xC];
	ArmorMap m_map;
};

const Rva00427157 *LivingWorldAutoResolveArmorStore::find(const AsciiString &name)
{
	NameKeyType key = TheNameKeyGenerator->nameToKey(name);
	ArmorMap::const_iterator it = m_map.find(key);
	if (it != m_map.end())
		return it->second;
	return (const Rva00427157 *)it._M_cur;
}



const Rva00427157 *LivingWorldAutoResolveArmorStore::getDefault()
{
	AsciiString name("AutoResolve_DefaultArmor");
	return find(name);
}


