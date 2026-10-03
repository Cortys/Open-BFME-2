// ?alloc@Rva000353B0@@QAEPAXPAXHHHH@Z @0x000353B0 57B.
// Address-derived PANS allocate-or-recognise hook, sibling of the Rva00033E90
// PANS block methods in Code/GameEngine/Source/Common/System/. A non-null first
// argument must carry the "PANS" block signature and is returned as-is, else
// NULL; a null first argument reaches the private four-argument allocator
// pinned at 0x00034D10 and stamps +0x0D on success. Names are address-derived;
// the default /O2 shape has no frame, so there is no // cl: line.
class Rva000353B0
{
public:
	void *rva00034d10(int a, int b, int c, int d);
	void *alloc(void *block, int a, int b, int c, int d);
};

void *Rva000353B0::alloc(void *block, int a, int b, int c, int d)
{
	void *result;
	if (block != 0)
	{
		result = block;
		if (*(int *)block != 0x534e4150)
			result = 0;
	}
	else
	{
		result = rva00034d10(a, b, c, d);
		if (result)
			*((char *)result + 0xd) = 1;
	}
	return result;
}