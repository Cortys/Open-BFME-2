// cl: /O1 /DNDEBUG /MD
//
// ?Rva00286116Free@@YAXPAX@Z @0x00286116 22B and ?Rva00286136Free@@YAXPAX@Z @0x00286136 22B.
// Null-checked pooled-object frees via rowed ?FreeObject@Rva00065964ObjectPool@@QAEXPAX@Z @0x00065964.
// Pools at 0x009FEC94 and 0x009FECA8 (DIR32 filled by the gate). Callers are the 0x00286CC4-class
// teardown loops at 0x00286CF0/0x00286DEA and 0x002864BB/0x00286D07. Recipe from PathDtor.cpp
// FreePooledNode @0x00265488 (same 22B shape, same callee).

#define NULL 0

struct Rva00065964ObjectPool
{
	void FreeObject(void *obj);
};

extern Rva00065964ObjectPool g_pool00286116;
extern Rva00065964ObjectPool g_pool00286136;

void __cdecl Rva00286116Free(void *p)
{
	if (p == NULL)
		return;
	g_pool00286116.FreeObject(p);
}

void __cdecl Rva00286136Free(void *p)
{
	if (p == NULL)
		return;
	g_pool00286136.FreeObject(p);
}
