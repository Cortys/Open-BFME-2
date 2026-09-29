// ??0SciVec@@QAE@ABV0@@Z
// partial score=0.95 date=2026-09-29
// ??0SciVec@@QAE@ABV0@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1
// Near miss for 0x002B55AE 68B (unlock lane). Manual vector<AHolder> copy:
// Vector_base(size, get_allocator) then 4-arg uninit-copy with empty tag.
// Ours 69B vs retail 68B: extra push ecx for named tag local; lea [ebp-1]
// vs retail [ebp+0xb] (dead arg slot reuse); leave vs pop ebp. Callee here
// is invented 4-arg MyUninitCopy; retail calls rowed 3-arg Rva003F74CFCopy
// at 0x003F74CF with 4 pushes (tag ignored by body). Next: get tag into dead
// slot with no local (native temporary sharing, cf shape_levers #13 #78) and
// resolve 4-arg callee to 0x003F74CF via ICF/pin evidence from this call site.
// Evidence: get_allocator 0x0021983A row; Vector_base 0x004F62A4 row (ICF fold
// G/I/AsciiString/ScienceType); Rva copy 0x003F74CF row; caller 0x002B90FC
// member at +0xC (12B vector) in 103B EH ctor; scalar twin 0x002CFAB9 67B via
// __copy_trivial; AsciiString twin 0x000BC07E 93B with EH.
class Rva004F6093Holder
{
public:
	Rva004F6093Holder(const Rva004F6093Holder &other) throw();
private:
	void *m_ptr;
};
struct SciAlloc { SciAlloc(); SciAlloc(const SciAlloc &); };
class SciVecBase {
protected:
	Rva004F6093Holder *m_start;
	Rva004F6093Holder *m_finish;
	Rva004F6093Holder *m_end;
public:
	SciVecBase(unsigned int n, const SciAlloc &a);
	SciAlloc get_allocator() const;
};
namespace _STL { struct __false_type {}; }
Rva004F6093Holder *__cdecl MyUninitCopy(Rva004F6093Holder *first, Rva004F6093Holder *last, Rva004F6093Holder *result, const _STL::__false_type &tag);
class SciVec : public SciVecBase {
public:
	SciVec(const SciVec &x);
};
// ?rva002B55AE@Rva002B55AE@@QAE@ABV0@@Z present-unmatched
SciVec::SciVec(const SciVec &x) : SciVecBase((x.m_finish - x.m_start), x.get_allocator())
{
	_STL::__false_type tag;
	m_finish = MyUninitCopy(x.m_start, x.m_finish, m_start, tag);
}
