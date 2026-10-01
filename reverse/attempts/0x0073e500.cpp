// ?rva0073E500@Rva0073E500@@QAEXHHPAURva0073E500Arg@@HPAX@Z
// partial score=0.92 date=2026-10-01
// cl: /O2 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?rva0073E500@Rva0073E500@@QAEXHHPAURva0073E500Arg@@HPAX@Z @0x0073E500 158B
// Evidence: unlock deque BfmeE32 32B rep-movs x8 plus _M_push_back_aux_v 0x0073E200 rowed in prev TU; abuts prev push_back 0x0073E480; 5 stack args ret 0x14 plus thiscall ecx; caller 0x00739F84 passes 5 dwords plus this from [esi]; LINK BONUS via 0x00739F50.
#include <deque>

struct BfmeE32 { int a[8]; };
struct Rva0073E500Arg { int v0; int v1; int v2; };

class Rva0073E500
{
public:
	void rva0073E500(int a1, int a2, Rva0073E500Arg *a3, int a4, void *a5);
private:
	int m00;
	char m_pad[0x34];
	int m38;
	_STL::deque<BfmeE32> m_deque;
};

extern "C" void __cdecl free(void *);

// ?rva0073E500@Rva0073E500@@QAEXHHPAURva0073E500Arg@@HPAX@Z present-unmatched
void Rva0073E500::rva0073E500(int a1, int a2, Rva0073E500Arg *a3, int a4, void *a5)
{
	if (!a5)
		return;
	if (a3->v0 < 0)
		return;
	BfmeE32 v;
	int a5m = ((int)a5) & 0xfffff;
	v.a[1] = (int)a3;
	v.a[2] = a4;
	v.a[3] = a3->v0;
	v.a[4] = a3->v1;
	v.a[5] = a3->v2;
	v.a[6] = a2;
	v.a[7] = a5m;
	v.a[0] = m00 + m38;
	m_deque.push_back(v);
	(void)a1;
}
