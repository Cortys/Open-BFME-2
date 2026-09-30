// cl: /O1 /MD
// ?Rva002DBC97Get@@YGPAXH@Z @0x002DBC97 51B
// Evidence: unlock lane; 8 callers push 1 int and use pointer result; globals g_00DBD03C g_00DBD040 g_00DBD044 g_00DBD048; ret 4 stdcall.
extern void *g_00DBD03C;
extern void *g_00DBD040;
extern void *g_00DBD044;
extern void *g_00DBD048;
void *__stdcall Rva002DBC97Get(int id)
{
	void *r = g_00DBD03C;
	if (id == 2)
		r = g_00DBD040;
	else if (id == 3 || id == 4)
		r = g_00DBD044;
	else if (id == 6)
		r = g_00DBD048;
	return r;
}
