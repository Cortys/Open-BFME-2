// ?erase@Rva002A75DA@@QAEPAUBfmeE12@@PAU2@@Z
// partial score=0.95 date=2026-09-27
// ?erase@Rva002A75DA@@QAEPAUBfmeE12@@PAU2@@Z
// partial score=0.95 date=2026-09-27
// cl: /O1
//
// Single-element vector erase at retail 0x002A75DA (55 bytes). Dedicated TU.
//
// Retail shifts the tail down via the rowed 4-arg _STL::__copy_ptrs for
// 12-byte BfmeE12 at 0x000B6569 when position+1 != finish, pops finish by one
// element, destroys the popped slot via the rowed dtor ??1Rva002A73B8 at
// 0x002A73B8, and returns position. Shape-identical to the rowed
// BfmeStringRecord erase at 0x00357CA2 (55B ret 4), whose TU supplies the
// self-contained _STL shim and the // cl: line copied above. Sole caller is
// 0x002A763B. The real element type is unproven beyond its 12-byte stride,
// so the ledger name below claims only the address plus the witnessed erase
// shape; BfmeE12 here is the tree's conventional 12-byte stand-in. The
// finish member is pointer-to-const so template deduction yields the rowed
// const-first-arg __copy_ptrs specialization with no explicit template
// arguments (explicit arguments force a value-initialized tag temporary and
// change codegen).
//
// WALL (muse-0410): body is byte-exact 55B but the gate reference comes out
// ABU (const __false_type&) while the rowed copy at 0x000B6569 is U-form
// (by value, per real STLport _algobase.h). By-value decl fixes the name but
// changes the tag push (54B). Do NOT pin an ABU name at 0x000B6569 (additive
// pin proves nothing). Options: land the 29B ABU const-ref forwarder (the
// ModuleInfo Nugget row 15287 pattern: forwarder row supersedes pin) if a
// rowed 5-arg BfmeE12 worker exists, then this body lands as-is. Tricks that
// were required for the exact body: inline end() accessor (forces finish
// into eax), named uninitialized tag local (a __false_type() temporary gets
// value-initialized with stosb and breaks registers), static_cast (not
// explicit template args) for the const-first-arg deduction.

struct BfmeE12
{
	float x, y, z;
};

class Rva002A73B8
{
public:
	~Rva002A73B8();
};

namespace _STL
{

struct __false_type
{
};

template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type &tag);

}

class Rva002A75DA
{
public:
	BfmeE12 *erase(BfmeE12 *position);
	const BfmeE12 *end() { return m_finish; }

private:
	BfmeE12 *m_start;
	const BfmeE12 *m_finish; // +0x04
	BfmeE12 *m_endOfStorage;
};

// ?erase@Rva002A75DA@@QAEPAUBfmeE12@@PAU2@@Z present-unmatched
BfmeE12 *Rva002A75DA::erase(BfmeE12 *position)
{
	_STL::__false_type tag;
	if (position + 1 != end())
		_STL::__copy_ptrs(static_cast<const BfmeE12 *>(position + 1), m_finish,
			position, tag);
	--m_finish;
	((Rva002A73B8 *)m_finish)->~Rva002A73B8();
	return position;
}
