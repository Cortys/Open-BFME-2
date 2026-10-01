// cl: /O1 /DNDEBUG /MD /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /G7
// stlport
// _STL::sort family over the 8-byte Rva0040CB11Entry (int plus refcounted
// holder) with a descending float comparator, retail 0x0040CF36..0x0040F497.
//
// Target evidence: sort 0x0040F454 (one caller 0x0040F501) reaches every
// placed body through REL32 calls that agree with this TU's own call graph:
// __introsort_loop 0x0040F34E -> __median 0x0040D0C1, partial_sort 0x0040E952;
// __final_insertion_sort 0x0040E908 -> __insertion_sort 0x0040E77A,
// __unguarded_insertion_sort 0x0040D98E -> _aux 0x0040D598; partial_sort ->
// make_heap 0x0040DD0A -> __make_heap 0x0040DA0A -> __adjust_heap 0x0040D5C5;
// sort_heap 0x0040E3B4 -> pop_heap 0x0040DD23 -> __pop_heap_aux 0x0040DA74 ->
// __pop_heap 0x0040D9A5. Element copies call the rowed Rva0040CB11Entry copy
// ctor 0x004F6335; element assignment calls 0x0040D0A4 (rowed as
// Rva0040D0A4Entry::operator=, the same 8-byte entry under a second
// placeholder name, pinned here as this class's operator=). The inlined value
// destructor releases the TargetRef at +0xAC of the pointee through the rowed
// fastcall 0x0007DEEF, the body rowed out of line as Rva004F69C3's dtor.
// The comparator reads the float at +8 of each holder's pointee and orders
// descending (comiss/ja in __median); its out-of-line copy 0x0040CF36 is
// unreferenced in retail as here and unique in .text.
//
// Structural inference: the two float locals in the comparator are what keep
// both operands in xmm registers (comiss reg,reg) in the heap bodies, as
// retail does. Not landed (by-value pivot/value kept in a callee-saved
// register across the assignment calls in retail, reloaded here; register
// order): __unguarded_linear_insert 0x0040D170, __push_heap 0x0040D1CE,
// __unguarded_partition 0x0040D918, __linear_insert 0x0040E333,
// __partial_sort 0x0040E7B2 -- pinned by call-site agreement only.
#include <algorithm>

struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};

void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);

struct Rva0040F454Target
{
	char m_pad00[8];
	float m_value; // +0x08
	char m_pad0C[0xAC - 0xC];
	TargetRef00217D4C m_ac; // +0xAC
};

class Rva004F6093Holder
{
	friend struct Rva0040F454Cmp;

public:
	Rva004F6093Holder(const Rva004F6093Holder &other);
	~Rva004F6093Holder()
	{
		if (m_ptr)
			ReleaseTreeHintRef00217D4C(&m_ptr->m_ac);
	}

private:
	Rva0040F454Target *m_ptr;
};

class Rva0040CB11Entry
{
	friend struct Rva0040F454Cmp;

public:
	Rva0040CB11Entry(const Rva0040CB11Entry &other);
	Rva0040CB11Entry &operator=(const Rva0040CB11Entry &other);

private:
	int m_first;
	Rva004F6093Holder m_second;
};

struct Rva0040F454Cmp
{
	bool operator()(const Rva0040CB11Entry &a, const Rva0040CB11Entry &b) const
	{
		float x = a.m_second.m_ptr->m_value;
		float y = b.m_second.m_ptr->m_value;
		return x > y;
	}
};

template void _STL::sort<Rva0040CB11Entry *, Rva0040F454Cmp>(Rva0040CB11Entry *, Rva0040CB11Entry *, Rva0040F454Cmp);
