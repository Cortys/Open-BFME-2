// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1?$vector@URva005F8F96@@V?$allocator@URva005F8F96@@@_STL@@@_STL@@QAE@XZ, retail 0x001536EA, 63 bytes.
// ?_M_clear@?$vector@URva005F8F96@@V?$allocator@URva005F8F96@@@_STL@@@_STL@@IAEXXZ, retail 0x0015373C, 30 bytes.
// Vector<Rva005F8F96> dtor (EH) plus _M_clear via rowed _Destroy 0x00153470 and _free 0x30830.
// Same 63B+30B pair shape as Owner900 vector dtor+clear; /EHs provides the or [ebp-4],-1 state.
#include <vector>
struct TargetRef00217D4C { virtual void *destroy(unsigned int flags); int references; };
struct Rva005F8F96
{
	~Rva005F8F96();
	TargetRef00217D4C *m_00;
	int m_04;
};

template class _STL::vector<Rva005F8F96, _STL::allocator<Rva005F8F96> >;
