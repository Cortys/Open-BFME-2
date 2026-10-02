// cl: /GX-
class GenAlloc
{
public:
	virtual void v0();
	virtual void v1();
	virtual void *acquire(int size, int flags);
	virtual void release(void *block, int flags);
};
extern "C" int __cdecl printf(const char *fmt, ...);
GenAlloc *g_genAlloc;
GenAlloc *Gen007EFFC0()
{
	if (g_genAlloc == 0)
		printf("no FESL allocator defined\n");
	return g_genAlloc;
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?bfmeGo929C@@YAPAXXZ=?Gen007EFFC0@@YAPAVGenAlloc@@XZ")
#pragma comment(linker, "/alternatename:?Rva007EFFC0Get@@YAPAVRva007EFFC0Allocator@@XZ=?Gen007EFFC0@@YAPAVGenAlloc@@XZ")
