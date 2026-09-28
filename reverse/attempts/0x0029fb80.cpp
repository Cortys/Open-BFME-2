// ?Rva0029FB80Store@@YGXPAPAX@Z
// partial score=0.9 date=2026-09-28
// ?Rva0029FB80Store@@YGXPAPAX@Z
// partial score=0.90 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// ?Rva0029FB80Store@@YGXPAPAX@Z @0x0029FB80 28B
// Freelist store via rowed pop 0x002393E2 on pool 0xDA60E8 plus *arg into
// node+8. Caller 0x002A131A; prev init; unblocks 0x002A1316.
class FreelistPool
{
public:
	void *pop();
};

extern FreelistPool g_freelistPool;

// ?Rva0029FB80Store@@YGXPAPAX@Z present-unmatched
void __stdcall Rva0029FB80Store(void **p)
{
	void *node = g_freelistPool.pop();
	void ** volatile q = (void **)((char *)node + 8);
	if (q)
		*q = *p;
}
