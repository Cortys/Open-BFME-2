// cl: /O1 /Ob1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
//
// STLport remove_copy for CreateAHeroData pointers, retail 0x0054872C 39B.
// Evidence: caller 0x005487D2 is remove (find then remove_copy with
// found+1) for the same CreateAHeroData registry as find 0x0020E873;
// loop skips value via pointer compare and compacts forward.
#include <vector>
#include <algorithm>
class CreateAHeroData;
template CreateAHeroData **_STL::remove_copy(CreateAHeroData **, CreateAHeroData **, CreateAHeroData **, CreateAHeroData * const &);
