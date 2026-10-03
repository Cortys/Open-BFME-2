// ?push_back@?$vector@VRva003A6360Record@@V?$allocator@VRva003A6360Record@@@_STL@@@_STL@@QAEXABVRva003A6360Record@@@Z
// partial score=1.0 date=2026-10-04
// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <vector>
class Rva003A6360Record {
public:
    Rva003A6360Record(const Rva003A6360Record&);
    int m_vtable; int m_word04; unsigned char m_byte08; int m_word0C;
};
// Target565FC1 follows STLport overflow allocation/copy/fill and caller ABI.
namespace _STL {
template<> __forceinline void _Construct<Rva003A6360Record,Rva003A6360Record>(Rva003A6360Record* p,const Rva003A6360Record& x) throw() { new(p) Rva003A6360Record(x); }
template<> void vector<Rva003A6360Record>::_M_insert_overflow(Rva003A6360Record*, const Rva003A6360Record&, const __false_type&, unsigned int, bool);
}
template<> void _STL::vector<Rva003A6360Record>::push_back(const Rva003A6360Record& x) {
    if (_M_finish != _M_end_of_storage._M_data) {
        if (_M_finish != 0) _M_finish->Rva003A6360Record::Rva003A6360Record(x);
        ++_M_finish;
    } else {
        _STL::__false_type tag;
        _M_insert_overflow(_M_finish, x, tag, 1, true);
    }
}

template void _STL::vector<Rva003A6360Record>::push_back(const Rva003A6360Record&);
