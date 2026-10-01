// ?Rva000A98BACleanup@@YAXXZ
// partial score=0.91 date=2026-10-01
// cl: /Os /DNDEBUG /MD
// ?Rva000A98BACleanup@@YAXXZ @0x000A98BA 34B
// Free singleton destroy: if g_00DE6170 non-null call virtual dtor at 0x0011018B then operator delete at 0x0002FD60 and clear with and [m],0.
// Evidence: frameless mov ecx test je; push esi mov esi ecx call ??1Rva0011018B UAE; push esi call ??3 mem_ops; and global 0 pop ecx pop esi ret; callers at 0x0006290B 0x000668FC.
extern void *g_00DE6170;
class Rva0011018B
{
public:
	virtual ~Rva0011018B();
};
void __cdecl operator delete(void *p);

// ?Rva000A98BACleanup@@YAXXZ present-unmatched
void __cdecl Rva000A98BACleanup(void)
{
	void *p = g_00DE6170;
	if (p == 0)
		return;
	((Rva0011018B *)p)->Rva0011018B::~Rva0011018B();
	::operator delete(p);
	g_00DE6170 = 0;
}
