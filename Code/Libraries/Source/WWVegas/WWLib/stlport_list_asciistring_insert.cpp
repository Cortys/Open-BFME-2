// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// Dedicated unit without the bfmelist __forceinline _M_create_node shim so
// list<AsciiString>::insert calls the out-of-line create_node (pinned at
// 0x001FD682 from the retail REL32), mirroring
// stlport_list_objectptr_insert.cpp. Retail 0x001FD72C (37 bytes) is the
// insert worker; the node is 12 bytes (8 links + 4-byte StringBase-model
// AsciiString) and create delegates per element to the matched StringBase
// _Construct helper at 0x0002C485, which names the element type.
#include <list>

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

#include "ascii_string.h"


bool operator==(const AsciiString &a, const AsciiString &b);
bool operator<(const AsciiString &a, const AsciiString &b);

template class _STL::list<AsciiString, _STL::allocator<AsciiString> >;
