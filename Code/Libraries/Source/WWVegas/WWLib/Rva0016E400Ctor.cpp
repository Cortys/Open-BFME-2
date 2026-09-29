// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
// stlport
//
// ??0Rva0016E400@@QAE@XZ @ 0x0016E400 (72B). Default ctor for non-virtual wrapper with hash_map<int int> at +0.
// Evidence: push 0x64 matches hash_map() default 100 in vendor/stlport/stl/_hash_map.h; callee is _M_initialize_buckets for hashtable<pair<const int int> hash<int>> rowed at 0x00622410 in stlport_hash_map_int.cpp; zeros at +4 +8 +0xC +0x10 are buckets vector plus num_elements; no vtable store; caller is unclaimed 0x0016E450 which becomes ready.

#include <hash_map>

class Rva0016E400
{
public:
    Rva0016E400();
private:
    _STL::hash_map<int, int> m_map;
};

Rva0016E400::Rva0016E400() : m_map() {}
