// ?_M_insert_overflow@?$vector@VRva003A6360Record@@V?$allocator@VRva003A6360Record@@@_STL@@@_STL@@IAEXPAVRva003A6360Record@@ABV3@ABU__false_type@2@I_N@Z
// partial score=0.9 date=2026-10-04
// cl: /O1 /G7 /MD /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
namespace _STL {
struct __false_type { __false_type() {} };
template<class T> class allocator { public: T* allocate(unsigned int,const void*) const; };
template<class P,class T,class A> struct _STLP_alloc_proxy : A {
    P _M_data;
    T* allocate(unsigned int n) { return A::allocate(n,0); }
};
template<class T,class A=allocator<T> > class vector {
public:
    void push_back(const T&);
    unsigned int size() const { return (unsigned int)(_M_finish-_M_start); }
protected:
    void _M_insert_overflow(T*,const T&,const __false_type&,unsigned int,bool);
    void _M_clear();
    void _M_set(T* a,T* b,T* c) { _M_start=a;_M_finish=b;_M_end_of_storage._M_data=c; }
    T* _M_start;T* _M_finish;_STLP_alloc_proxy<T*,T,A> _M_end_of_storage;
};
template<class T> inline const T& max(const T& a,const T& b) { return a<b?b:a; }
template<class I,class F> F __uninitialized_copy(I,I,F,const __false_type&);
template<class F,class N,class T> F __uninitialized_fill_n(F,N,const T&,const __false_type&);
}
class Rva003A6360Record {
public:
    Rva003A6360Record(const Rva003A6360Record&);
    int m_vtable; int m_word04; unsigned char m_byte08; int m_word0C;
};
// Target565FC1 follows STLport overflow allocation/copy/fill and caller ABI.
namespace _STL {
template<> Rva003A6360Record* __uninitialized_copy<Rva003A6360Record*,Rva003A6360Record*>(Rva003A6360Record*,Rva003A6360Record*,Rva003A6360Record*,const __false_type&);
template<> Rva003A6360Record* __uninitialized_fill_n<Rva003A6360Record*,unsigned int,Rva003A6360Record>(Rva003A6360Record*,unsigned int,const Rva003A6360Record&,const __false_type&);
template<> void vector<Rva003A6360Record>::_M_clear();
template<> void vector<Rva003A6360Record>::_M_insert_overflow(Rva003A6360Record* position, const Rva003A6360Record& x, const __false_type&, unsigned int fill_len, bool atend) {
    const unsigned int old_size = size();
    const unsigned int len = old_size + (max)(old_size,fill_len);
    Rva003A6360Record* new_start = _M_end_of_storage.allocate(len);
    Rva003A6360Record* new_finish = __uninitialized_copy(_M_start,position,new_start,__false_type());
    if (fill_len == 1) {
        if (new_finish) new_finish->Rva003A6360Record::Rva003A6360Record(x);
        ++new_finish;
    } else new_finish = __uninitialized_fill_n(new_finish,fill_len,x,__false_type());
    if (!atend) new_finish = __uninitialized_copy(position,_M_finish,new_finish,__false_type());
    _M_clear();
    _M_set(new_start,new_finish,new_start+len);
}
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

template void _STL::vector<Rva003A6360Record>::_M_insert_overflow(Rva003A6360Record*,const Rva003A6360Record&,const _STL::__false_type&,unsigned int,bool);
