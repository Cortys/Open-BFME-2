// ?insert@?$vector@VRva0054103E@@V?$allocator@VRva0054103E@@@_STL@@@_STL@@QAEPAVRva0054103E@@PAV3@ABV3@@Z
// partial score=0.97 date=2026-10-02
// cl: /O1 /G7 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /Ireference/shims/bfmealloc
// stlport
//
// ?insert@?$vector@VRva0054103E@@V?$allocator@VRva0054103E@@@_STL@@@_STL@@QAEPAVRva0054103E@@PAV3@ABV3@@Z @0x00541DDF 152B.
// STLport 4.5.3 vector<Rva0054103E>::insert single-element insert via vendor
// _vector.h. Element 0x14 bytes with Region2D at +4 proven by rowed copy ctor
// 0x0054103E. Calls rowed Construct 0x0054106D plus copy ctor 0x0054103E plus
// copy_backward_ptrs 0x005412C5 plus overflow 0x005417C6. Chain lane: calls
// 0x005412C5 landed this session. Near miss 154 vs 152B banks as partial.
#include <vector>
struct Region2D
{
	Region2D(const Region2D &that);
	float x_min;
	float y_min;
	float x_max;
	float y_max;
};
class Rva0054103E
{
public:
	Rva0054103E();
	Rva0054103E(const Rva0054103E &that);
	Rva0054103E &operator=(const Rva0054103E &that);
private:
	int m_00;
	Region2D m_04;
};
template _STL::vector<Rva0054103E>::iterator _STL::vector<Rva0054103E>::insert(Rva0054103E *, const Rva0054103E &);
