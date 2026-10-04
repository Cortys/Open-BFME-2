// ??0Rva00355B61@@QAE@XZ
// partial score=0.91 date=2026-10-04
// stlport
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// Retail RVA 0x00355B61, 85 bytes.
// Rva00355B61::Rva00355B61: SubsystemInterface base via retail 0x001B4E63,
// second base Snapshot inline (retail transient vtable 0x7BB554 at +0xC),
// derived vtables 0x814E14 at +0 and 0x814E04 at +0xC,
// members ArmorTemplateMap at +0x10 and +0x24 via retail 0x00355B42.
// Near miss: layout and EH exact (85B/23 insns, 0 reg diffs); vtables gate-filled;
// two hash_map calls go to TU-local copy (positive disp) not retail abutting
// twin 0x00355B42 (negative disp). Same-file TU keeps one copy far; needs
// abutting twin layout.

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

#include "ascii_string.h"

class SubsystemInterface
{
public:
	SubsystemInterface();
	virtual ~SubsystemInterface();
	virtual void init() = 0;
	virtual void reset() = 0;
	virtual void update() = 0;

private:
	unsigned char m_bfme04[8];
};

typedef std::hash_map<
	NameKeyType,
	ArmorTemplate,
	rts::hash<NameKeyType>,
	std::equal_to<NameKeyType> > ArmorTemplateMap;

class SnapshotBase
{
public:
	virtual ~SnapshotBase();
};

class Rva00355B61 : public SubsystemInterface, public SnapshotBase
{
public:
	Rva00355B61();
	virtual ~Rva00355B61();
	void init() { }
	void reset() { }
	void update() { }

private:
	ArmorTemplateMap m_map1;
	ArmorTemplateMap m_map2;
};

// ??0Rva00355B61@@QAE@XZ present-unmatched
Rva00355B61::Rva00355B61()
{
}
