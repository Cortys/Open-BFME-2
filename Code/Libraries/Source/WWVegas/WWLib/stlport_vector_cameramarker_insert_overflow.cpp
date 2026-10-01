// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@VCameraMarker@@V?$allocator@VCameraMarker@@@_STL@@@_STL@@IAEXPAVCameraMarker@@ABV3@ABU__false_type@2@I_N@Z @0x000D05C1 178B
// Evidence: STLport vector<CameraMarker> false_type growth path; 8B stride sar 3; new_size old plus max(old fill_len); allocate plus uninitialized_copy plus Construct-or-fill_n plus conditional second copy plus CameraMarker _M_clear 0xC060A; caller push_back 0xD068F with fill_len 1 atend true unblocks 0xD068F.
#include <vector>
#include "ascii_string.h"
class CameraMarker {
public:
	CameraMarker *m_next;
	AsciiString m_name;
	~CameraMarker();
	CameraMarker(const CameraMarker &other);
	CameraMarker &operator=(const CameraMarker &other);
};
namespace _STL {
template <> void _Construct<class CameraMarker, class CameraMarker>(class CameraMarker *, const class CameraMarker &);
}
template void _STL::vector<class CameraMarker>::_M_insert_overflow(class CameraMarker *, const class CameraMarker &, const _STL::__false_type &, unsigned int, bool);
