// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/GameClient/AssetListOperatorInsert.cpp): only the
// placed AssetList::operator<<(const AssetList&) body is defined here. The
// AsciiString overload stays declared-only so the unmatched-definition gate
// passes. Layout is the donor's: prototype pointer set + layout pad + changed
// flag.

#define _BFME_RETAIL_TREE_INSERT_LAYOUT
#include <set>

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/AsciiString.h
#include "ascii_string.h"

struct Rva001408C0Target;

typedef Rva001408C0Target *Rva001408C0Key;
typedef _STL::set<Rva001408C0Key, _STL::less<Rva001408C0Key>,
	_STL::allocator<Rva001408C0Key> > Rva001408C0Set;

class AssetList
{
public:
	AssetList &operator <<(const AssetList &other);
	AssetList &operator <<(const AsciiString &name);

private:
	Rva001408C0Set m_prototypes;
	unsigned int m_treeLayoutPad;
	bool m_changed;
};

// ??6AssetList@@QAEAAV0@ABV0@@Z
AssetList &AssetList::operator <<(const AssetList &other)
{
	m_prototypes.insert(other.m_prototypes.begin(),
		other.m_prototypes.end());
	m_changed = true;
	return *this;
}
