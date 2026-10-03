// ?Rva002165EBFill@@YAXPAU?$pair@$$CBVAsciiString@@VGen_003A8BE0@@@_STL@@PBU12@@Z
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHs /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?Rva002165EBFill@@YAXPAU?$pair@$$CBVAsciiString@@VGen_003A8BE0@@@_STL@@PBU13@@Z @0x002165EB 45B guarded pair copy.
// Evidence: null-checked dst at +8 with EH state 0 then rowed pair copy 0x002161DE with src at +0xC; caller 0x00216779 allocates 0x14 zeroes +0 and constructs pair at +4; pair Gen_003A8BE0 from stlport_pair_asciistring_twins.
#include "ascii_string.h"
#include <utility>
#include <memory>

class Gen_003A8BE0
{
public:
	Gen_003A8BE0(const Gen_003A8BE0 &other);
	~Gen_003A8BE0();
};

// ?Rva002165EBFill@@YAXPAU?$pair@$$CBVAsciiString@@VGen_003A8BE0@@@_STL@@PBU13@@Z present-unmatched
void __cdecl Rva002165EBFill(_STL::pair<const AsciiString, Gen_003A8BE0> *dst, const _STL::pair<const AsciiString, Gen_003A8BE0> *src)
{
	if (dst != 0)
		new (dst) _STL::pair<const AsciiString, Gen_003A8BE0>(*src);
}
