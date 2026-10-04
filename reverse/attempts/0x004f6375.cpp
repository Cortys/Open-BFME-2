// ??$__median@UTreeHintRef00217D4C@@URva004F9185Cmp@@@_STL@@YAABUTreeHintRef00217D4C@@ABU1@00URva004F9185Cmp@@@Z
// partial score=0.93 date=2026-10-04
// cl: /O1 /G7 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
// ??$__median@UTreeHintRef00217D4C@@URva004F9185Cmp@@@_STL@@YAABUTreeHintRef00217D4C@@ABU1@00URva004F9185Cmp@@@Z @0x004F6375 391B _STL::__median for TreeHintRef.
// Evidence: pin names this median; caller 0x004F91C0 in introsort_loop; contiguous with /O1 /Ob0 neighbours but body needs /G7 /EHsc like sort caller.
struct Key004F9185 { int _00[3]; int m_key; };
struct TargetRef00217D4C { virtual void *destroy(unsigned flags); int references; Key004F9185 *m_08; };
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *);
struct TreeHintRef00217D4C
{
	TargetRef00217D4C *m_ptr;
	TreeHintRef00217D4C(const TreeHintRef00217D4C &other) : m_ptr(other.m_ptr) { if (m_ptr) ++m_ptr->references; }
	TreeHintRef00217D4C &operator=(const TreeHintRef00217D4C &other);
	__forceinline ~TreeHintRef00217D4C() { if (m_ptr) ReleaseTreeHintRef00217D4C(m_ptr); }
};
struct Rva004F9185Cmp
{
	__forceinline bool operator()(TreeHintRef00217D4C a, TreeHintRef00217D4C b) const { int ka = a.m_ptr->m_08->m_key; int kb = b.m_ptr->m_08->m_key; return ka > kb; }
};
namespace _STL
{
template <class Tp, class Compare>
const Tp &__median(const Tp &a, const Tp &b, const Tp &c, Compare comp)
{
	if (comp(a, b))
		if (comp(b, c))
			return b;
		else if (comp(a, c))
			return c;
		else
			return a;
	else if (comp(a, c))
		return a;
	else if (comp(b, c))
		return c;
	else
		return b;
}
template const TreeHintRef00217D4C &__median<TreeHintRef00217D4C, Rva004F9185Cmp>(const TreeHintRef00217D4C &, const TreeHintRef00217D4C &, const TreeHintRef00217D4C &, Rva004F9185Cmp);
}
