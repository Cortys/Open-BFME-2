// cl: /O1 /G7 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /Ireference/shims/bfmealloc
// stlport
//
// ?_M_insert_overflow@?$vector@VRva0054103E@@V?$allocator@VRva0054103E@@@_STL@@@_STL@@IAEXPAVRva0054103E@@ABV3@ABU__false_type@2@I_N@Z @0x005417C6 189B.
// STLport 4.5.3 vector<Rva0054103E>::_M_insert_overflow false_type growth path.
// Element is 0x14 bytes with Region2D at +4 proven by the rowed copy ctor at
// 0x0054103E. Calls rowed allocate-fold 0x00395960 via new pin plus rowed
// uninit copy 0x005411EE plus Construct 0x0054106D plus fill_n 0x00541108 plus
// free 0x00030830. Callers 0x00541DD5 and 0x00541E64 become ready. /G7 emits
// retail imul and register choice. Trivial dtor keeps _M_clear inline with
// null check. Nontrivial assignment keeps false_type. Default keeps whole
// class compiling.
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
template class _STL::vector<Rva0054103E, _STL::allocator<Rva0054103E> >;
