// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva0022356C@Rva0022356C@@QAEPAXPBX@Z @0x0022356C 37B
// Eva hashtable new-node for 16-byte node (4 next + 12 BfmeStringRecord00222E08).
// Evidence: caller at 0x002237F2 loads ecx plus one record-pointer arg;
// allocate 0x000307F0 with (0x10 0) then true _Construct 0x00223195 via rowed
// BfmeStringRecord00222E08 copy; unlocks 0x002237C7. Same shape and flags as
// siblings 0x002230FF 0x00223124 0x00223547. Private minimal AsciiString
// (declared-only copy) keeps _Construct out-of-line.
#define _STLP_NO_EXCEPTIONS 1
#include <memory>

class AsciiString
{
public:
	AsciiString(const AsciiString &other);
private:
	char m_pad[4];
};

struct Rva00468520Val
{
	void *m_00;
	int m_04;
};

struct BfmeStringRecord00222E08
{
	AsciiString m_text;
	Rva00468520Val m_ref;
};

namespace _STL
{
template <> void _Construct(BfmeStringRecord00222E08 *,
	const BfmeStringRecord00222E08 &);
}

struct Rva0022356CNode
{
	void *_M_next;
	BfmeStringRecord00222E08 _M_val;
};

class Rva0022356C
{
public:
	void *rva0022356C(const void *obj);
};

void *Rva0022356C::rva0022356C(const void *obj)
{
	Rva0022356CNode *n = (Rva0022356CNode *)_STL::allocator<char>().allocate(16, 0);
	n->_M_next = 0;
	_STL::_Construct(&n->_M_val, *(const BfmeStringRecord00222E08 *)obj);
	return n;
}
