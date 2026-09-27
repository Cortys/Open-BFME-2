// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva004CA167@AnimationSoundTree@@QAEXPAX@Z, retail 0x004CA167, 53 bytes.
// AnimationSoundTree node free helper: if the node is null returns; otherwise
// recurses on the child at +0x0C with the same tree, saves the sibling at +8,
// runs the rowed ??1Rva002390CB at 0x004C9F38 on the payload at +0x10, frees
// the node through the rowed _free at 0x00030830, then advances to the saved
// sibling until null. The tree itself (header at +0 plus count at +4) is only
// threaded through for the recursion, matching retail's preserved ebx.
// Evidence: callees all rowed (plus self); callers at 0x004CA179 (self) and
// 0x004CA278 in FUN_008CA26A (tree clear checking count at +4); prev/next
// after ??0Rva004C9FBF / ??0Rva004CA125 with the same // cl: line.

class Rva002390CB
{
public:
	~Rva002390CB();
};

extern "C" void free(void *);

namespace _STL
{
void __cdecl free(void *block);
template <class _Tp> class allocator
{
public:
	static _Tp *allocate(unsigned int __n, void const *__hint);
};
template <class _P, class _T, class _A> class _STLP_alloc_proxy
{
public:
	_STLP_alloc_proxy(const _A &__a, _P __p);
	_P _M_data;
};
}

inline void *__cdecl operator new(unsigned int, void *__p)
{
	return __p;
}

typedef unsigned int ProxyUInt;

class AnimationSoundTreeHeaderHandle
{
public:
	~AnimationSoundTreeHeaderHandle()
	{
		if (m_header)
			_STL::free(m_header);
	}

	void *m_header;
};

class AnimationSoundTree
{
public:
	~AnimationSoundTree();
	void rva004CA167(void *node);
	void rva004CA26A();
	AnimationSoundTree *rva004CA018(void const *dummy);
	AnimationSoundTree *rva004CA13D(void const *d1, void const *d2);

private:
	AnimationSoundTreeHeaderHandle m_handle;
	unsigned int m_count;
};

void AnimationSoundTree::rva004CA167(void *nodeIn)
{
	if (!nodeIn)
		return;
	char *cur = (char *)nodeIn;
	do
	{
		char *child = *(char **)(cur + 0x0C);
		rva004CA167(child);
		char *next = *(char **)(cur + 8);
		((Rva002390CB *)(cur + 0x10))->~Rva002390CB();
		free(cur);
		cur = next;
	} while (cur);
}

// ?rva004CA26A@AnimationSoundTree@@QAEXXZ, retail 0x004CA26A, 41 bytes.
// AnimationSoundTree clear: returns when the count at +4 is zero; otherwise
// frees the list at header+4 through the rowed rva004CA167 helper above,
// then repairs the 0xB8 header sentinel (self at +8 and +0x0C, zero at +4)
// and zeroes the count. Prev is the helper itself with the same // cl: line.
// Evidence: callees all rowed after 0x004CA167 landed; sole caller at
// 0x004CA668 in FUN_008CA653.

void AnimationSoundTree::rva004CA26A()
{
	if (m_count == 0)
		return;
	void *first = *(void **)((char *)m_handle.m_header + 4);
	rva004CA167(first);
	*(void **)((char *)m_handle.m_header + 8) = m_handle.m_header;
	*(unsigned int *)((char *)m_handle.m_header + 4) = 0;
	*(void **)((char *)m_handle.m_header + 0x0C) = m_handle.m_header;
	m_count = 0;
}

// ??1AnimationSoundTree@@QAE@XZ, retail 0x004CA653, 56 bytes.
// AnimationSoundTree dtor: clears via rowed rva004CA26A then frees header.
// Evidence: caller at 0x004CA780 in pinned ??1AnimationSoundClientBehaviorModuleData 0x004CA768 with ECX=this+8; layout header+0 count+4 from ctor 0x004CA6DA.
AnimationSoundTree::~AnimationSoundTree()
{
	rva004CA26A();
}

// ?rva004CA018@AnimationSoundTree@@QAEPAV1@PBX@Z, retail 0x004CA018, 39 bytes.
// Header-handle alloc helper: proxy at this with a stack uint allocator temp
// and null, then the 0xB8 header via the rowed byte allocator stored at +0,
// returning this. Called once from 0x004CA13D. Evidence: callees rowed
// 0x0014F3C4 proxy and 0x000307F0 allocate; caller at 0x004CA144;
// prev/next with the same // cl: line.
AnimationSoundTree *AnimationSoundTree::rva004CA018(void const *dummy)
{
	(void)dummy;
	_STL::allocator<ProxyUInt> tmp;
	_STL::_STLP_alloc_proxy<ProxyUInt *, ProxyUInt, _STL::allocator<ProxyUInt> > *proxy =
		(_STL::_STLP_alloc_proxy<ProxyUInt *, ProxyUInt, _STL::allocator<ProxyUInt> > *)this;
	__assume(proxy != 0);
	new (proxy) _STL::_STLP_alloc_proxy<ProxyUInt *, ProxyUInt, _STL::allocator<ProxyUInt> >(tmp, (ProxyUInt *)0);
	*(char **)this = _STL::allocator<char>::allocate(0xb8, 0);
	return this;
}

// ?rva004CA13D@AnimationSoundTree@@QAEPAV1@PBX0@Z, retail 0x004CA13D, 42 bytes.
// Header init: runs the rowed rva004CA018 alloc with the second dummy, then
// zeroes count at +4 and repairs the 0xB8 header sentinel (zero at +0/+4,
// self at +8/+0xC), returning this. Called once from the pinned ctor 0x004CA6DA.
// Evidence: callee rowed 0x004CA018; caller at 0x004CA6E9; prev/next same // cl:.
AnimationSoundTree *AnimationSoundTree::rva004CA13D(void const *d1, void const *d2)
{
	(void)d1;
	rva004CA018(d2);
	m_count = 0;
	*(char *)m_handle.m_header = 0;
	*(unsigned int *)((char *)m_handle.m_header + 4) = 0;
	*(void **)((char *)m_handle.m_header + 8) = m_handle.m_header;
	*(void **)((char *)m_handle.m_header + 0x0C) = m_handle.m_header;
	return this;
}
