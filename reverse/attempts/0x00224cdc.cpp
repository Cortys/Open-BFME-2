// ??0Rva00224CDC@@QAE@XZ
// partial score=0.95 date=2026-10-02
// stlport
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// ??0Rva00224CDC@@QAE@XZ @0x00224CDC 83B
// Subsystem ctor: baseConstruct then own vtable 0x007E6EE8 then ArmorTemplateMap at +0xC then setName AptButtonTooltipMap.
// Evidence: retail EH_prolog baseConstruct row StringBase PBD row setName row; caller 0x00224D80 new 0x20; vtable store at this; dup map ctor 0x00224C76; string AptButtonTooltipMap.
// Precedent Rva00222061Ctor Shell-pattern base for EH after baseConstruct.
#include "ascii_string.h"
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

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

class __declspec(novtable) BFME2NativeNetworkBase
{
public:
	__forceinline BFME2NativeNetworkBase() { ((BFME2NativeNetwork *)this)->baseConstruct(); }
	virtual ~BFME2NativeNetworkBase() { _ReadWriteBarrier(); }
private:
	char m_flag;
	int m_value;
};

class SubsystemInterface
{
public:
	void setName(AsciiString name);
};

class Rva00224CDC : public BFME2NativeNetworkBase
{
public:
	Rva00224CDC();
	virtual ~Rva00224CDC();
private:
	ArmorTemplateMap m_0C;
};

Rva00224CDC::Rva00224CDC()
{
	((SubsystemInterface *)this)->setName("AptButtonTooltipMap");
}
