// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// Two STLport sort families over MapMetaData pointers, side by side in
// 0x00301BDD-0x00304573, one per comparator:
//   sort<MapMetaData**, Rva0030145CCmp> 0x00304530 (callers 0x003058A2,
//     0x005BBEC1): the comparator at 0x0030145C orders by the dword at +0x20,
//     then by the rowed MapMetaData::bfme_getDisplayName strings;
//   sort<MapMetaData**, Rva003014D6Cmp> 0x003044ED (caller 0x0030492F): the
//     comparator at 0x003014D6 orders by the rowed MapMetaData::rva00300D0E
//     strings.
// The element type is fixed by those rowed MapMetaData member calls inside
// the comparators; the comparators keep address-derived functor names and
// are pinned, not rowed (each has exactly the 12 call sites inside its own
// family). The two families are byte-identical modulo relocations, so each
// body was placed by masked search plus REL32 agreement with its own
// comparator, starting from the comparator calls in median and partition.
// Every body comes from the vendored header through the two sort
// instantiations below.
#include <algorithm>

class MapMetaData;

struct Rva0030145CCmp
{
	bool operator()(MapMetaData *a, MapMetaData *b) const;
};

struct Rva003014D6Cmp
{
	bool operator()(MapMetaData *a, MapMetaData *b) const;
};

// ??$sort@PAPAVMapMetaData@@URva0030145CCmp@@@_STL@@YAXPAPAVMapMetaData@@0URva0030145CCmp@@@Z @0x00304530 and its callees
template void _STL::sort<MapMetaData **, Rva0030145CCmp>(MapMetaData **, MapMetaData **, Rva0030145CCmp);

// ??$sort@PAPAVMapMetaData@@URva003014D6Cmp@@@_STL@@YAXPAPAVMapMetaData@@0URva003014D6Cmp@@@Z @0x003044ED and its callees
template void _STL::sort<MapMetaData **, Rva003014D6Cmp>(MapMetaData **, MapMetaData **, Rva003014D6Cmp);
