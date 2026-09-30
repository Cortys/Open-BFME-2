// ?reserve@?$vector@VRva0040CB11Entry@@V?$allocator@VRva0040CB11Entry@@@_STL@@@_STL@@QAEXI@Z
// partial score=0.99 date=2026-09-30
// ?reserve@?$vector@VRva0040CB11Entry@@V?$allocator@VRva0040CB11Entry@@@_STL@@@_STL@@QAEXI@Z
// partial score=0.99 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?reserve@?$vector@VRva0040CB11Entry@@V?$allocator@VRva0040CB11Entry@@@_STL@@@_STL@@QAEXI@Z 0x0040E135 104B evidence: unlock vector reserve 8B with allocate_and_copy rowed plus clear plus allocate; prev FamilyDeletingDtors
class Rva004F6093Holder
{
public:
	Rva004F6093Holder(const Rva004F6093Holder &other);
private:
	void *m_ptr;
};
class Rva0040CB11Entry
{
public:
	Rva0040CB11Entry();
	Rva0040CB11Entry(const Rva0040CB11Entry &other);
	~Rva0040CB11Entry();
private:
	int m_first;
	Rva004F6093Holder m_second;
};
#include <memory>
namespace _STL {
template<> void _Construct<Rva0040CB11Entry, Rva0040CB11Entry>(Rva0040CB11Entry *, const Rva0040CB11Entry &);
template<> void _Destroy<Rva0040CB11Entry *>(Rva0040CB11Entry *, Rva0040CB11Entry *);
}
#include <vector>
template <>
void _STL::vector<Rva0040CB11Entry, _STL::allocator<Rva0040CB11Entry> >::reserve(size_type __n)
{
  if (capacity() < __n) {
    const size_type __old_size = size();
    pointer __tmp;
    if (this->_M_start) {
      __tmp = _M_allocate_and_copy(__n, (const_pointer)this->_M_start, (const_pointer)this->_M_finish);
      _M_clear();
    } else {
      __tmp = this->_M_end_of_storage.allocate(__n);
    }
    _M_set(__tmp, __tmp + __old_size, __tmp + __n);
  }
}
// ?reserve@?$vector@VRva0040CB11Entry@@V?$allocator@VRva0040CB11Entry@@@_STL@@@_STL@@QAEXI@Z present-unmatched
