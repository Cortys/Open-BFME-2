// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??$__copy@PAVRva0040D0A4Entry@@PAV1@H@_STL@@YAPAVRva0040D0A4Entry@@PAV1@00ABUrandom_access_iterator_tag@0@PAH@Z, retail 0x0040D564, 47 bytes.
// Forward __copy for 8-byte Rva0040D0A4Entry via rowed assign 0x0040D0A4.
// Same 47B loop shape as copy_backward 0x0040D251 and __copy 0x00426A82.
// Caller is 29B wrapper at 0x0040D8FB pushing tag plus distance.
class Rva002B2F97
{
public:
	Rva002B2F97 &operator=(const Rva002B2F97 &other);
private:
	void *m_ptr;
};

class Rva0040D0A4Entry
{
public:
	Rva0040D0A4Entry &operator=(const Rva0040D0A4Entry &other);
private:
	int m_first;
	Rva002B2F97 m_second;
};

#include <vector>
template Rva0040D0A4Entry* _STL::__copy<Rva0040D0A4Entry*, Rva0040D0A4Entry*, int>(Rva0040D0A4Entry*, Rva0040D0A4Entry*, Rva0040D0A4Entry*, const _STL::random_access_iterator_tag&, int*);
