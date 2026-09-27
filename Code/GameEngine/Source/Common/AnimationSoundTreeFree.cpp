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

class AnimationSoundTree
{
public:
	void rva004CA167(void *node);
	void rva004CA26A();

private:
	void *m_header;
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
	void *first = *(void **)((char *)m_header + 4);
	rva004CA167(first);
	*(void **)((char *)m_header + 8) = m_header;
	*(unsigned int *)((char *)m_header + 4) = 0;
	*(void **)((char *)m_header + 0x0C) = m_header;
	m_count = 0;
}
