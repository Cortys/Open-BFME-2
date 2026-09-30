// cl: /O1 /MD
// ?Rva0002BBC9Update@@YAXXZ @0x0002BBC9 21B
// Refreshes global SaveDate g_00DDF5B8 via rowed 0x0002BB1C then copies
// g_00DDF5AC to g_00DDF5B0. Caller at 0x001B511B ignores the return.
typedef unsigned short WORD;

struct SaveDate
{
	WORD year;
	WORD month;
	WORD day;
	WORD dayOfWeek;
	WORD hour;
	WORD minute;
	WORD second;
	WORD milliseconds;
public:
	void rva0002BB1C();
};

extern SaveDate g_00DDF5B8;
extern int g_00DDF5AC;
extern int g_00DDF5B0;

void Rva0002BBC9Update()
{
	g_00DDF5B8.rva0002BB1C();
	g_00DDF5B0 = g_00DDF5AC;
}
