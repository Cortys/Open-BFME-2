// ??0AnimationSoundTree@@QAE@XZ
// partial score=0.97 date=2026-10-04
// ??0AnimationSoundTree@@QAE@XZ
// cl: /O1 /DNDEBUG /MD /EHsc
// Pinned ctor for AnimationSoundTree, retail 0x004CA6DA, 25 bytes.
// The header init is done by the rowed ?rva004CA13D@AnimationSoundTree (0x004CA13D),
// which takes two unused dummy addresses; retail materialises a separate one-byte
// local for each argument, which is why the body pushes two distinct
// `lea eax,[ebp-1]` forms instead of reusing one. Passing the SAME local twice
// (the earlier banked attempt) lets cl 7.1 CSE the two addresses into a single
// lea + two pushes and emits a 22-byte body; two distinct locals reproduce retail
// exactly, including the redundant recomputation of the same stack slot.
// Evidence: sole caller 0x004CA72B in
// Code/GameEngine/Source/GameClient/Drawable/Update/AnimationSoundClientBehaviorModuleDataCtor.cpp;
// prev 0x004CA653 dtor and the 0x004CA13D header-init body share this // cl: line.
// Recovered from the banked attempt reverse/attempts/0x004ca6da.cpp (score 0.93).
// Its single reusable fix is two DISTINCT dummies instead of one reused dummy:
// cl 7.1 CSEs `rva004CA13D(&d, &d)` into one lea plus two pushes and emits a
// 22-byte body, while two distinct locals restore retail's two-lea shape and the
// exact 25-byte size. Remaining residue is a single disp8: retail recomputes the
// SAME slot twice (lea eax,[ebp-1] / push / lea eax,[ebp-1] / push), and two live
// one-byte locals always occupy adjacent slots (ebp-1 then ebp-2), so the second
// lea is one byte off. See the re_log row for the spellings ruled out.

namespace _STL
{
template <class _Tp> class allocator
{
public:
	static _Tp *allocate(unsigned int __n, void const *__hint);
};
}

class AnimationSoundTreeHeaderHandle
{
public:
	void *m_header;
};

class AnimationSoundTree
{
public:
	AnimationSoundTree();

private:
	AnimationSoundTreeHeaderHandle m_handle;
	unsigned int m_count;

public:
	AnimationSoundTree *rva004CA13D(void const *d1, void const *d2) throw();
};

// ??0AnimationSoundTree@@QAE@XZ present-unmatched
AnimationSoundTree::AnimationSoundTree()
{
	char firstDummy;
	char secondDummy;
	rva004CA13D(&firstDummy, &secondDummy);
}