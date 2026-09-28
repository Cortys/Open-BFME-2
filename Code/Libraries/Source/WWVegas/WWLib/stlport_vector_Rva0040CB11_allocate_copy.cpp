// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??$_M_allocate_and_copy@PBVRva0040CB11Entry@@@?$vector@VRva0040CB11Entry@@V?$allocator@VRva0040CB11Entry@@@_STL@@@_STL@@IAEPAVRva0040CB11Entry@@IPBV2@0@Z, retail 0x0040D077, 45 bytes.
// Vector<Rva0040CB11Entry> allocate-and-copy: allocate N via 0x00523D6C then
// uninitialized_copy range via rowed 0x004F6AD3. Entry is int key plus
// Rva004F6093Holder value matching rowed entry ctor 0x0040CB11 and copy
// 0x004F6335. Same 45B ebp-tag shape as 0x00426B46. Caller at 0x0040E167.
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
private:
	int m_first;
	Rva004F6093Holder m_second;
};

#include <memory>
namespace _STL {
template<> void _Construct<Rva0040CB11Entry, Rva0040CB11Entry>(Rva0040CB11Entry *, const Rva0040CB11Entry &);
}
#include <vector>
template class _STL::vector<Rva0040CB11Entry, _STL::allocator<Rva0040CB11Entry> >;
