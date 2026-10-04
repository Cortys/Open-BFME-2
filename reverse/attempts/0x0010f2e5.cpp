// ?rva0010F2E5@Rva0010EE67@@UAEXXZ
// partial score=0.97 date=2026-10-04
// cl: /O1 /MD
// ?rva0010F2E5@Rva0010EE67@@UAEXXZ @0x0010F2E5 87B.
// Vtable slot 1 of Rva0010EE67 (vtable 0x007CFA54 from rowed ctor 0x0010EE67):
// guarded _AIL_service_stream on the +0x08 inner stream. Guard target is
// +0x38 of the +0x0C outer (null-checked pair), locked via rowed 0x0010F24F,
// unlocked via rowed 0x0010F26E when the guard flag is set. Stream at
// [[this+8]+8] serviced via IAT _AIL_service_stream@8 with ([this+0xC]==0).
// Shape follows landed sibling Rva0010F33C (0x0010F33C 78B). Callees rowed.
extern "C" __declspec(dllimport) void __stdcall AIL_service_stream(void *stream, int flag);

class Rva00041004;

class Rva0010F24F
{
public:
	void rva0010F24F();
};

class Rva0010F26E
{
public:
	void rva0010F26E();
};

struct Rva0010F2E5Mid
{
	char pad[0x38];
};

struct Rva0010F2E5Inner
{
	char pad0[8];
	void *m_stream;
	Rva0010F2E5Mid *m_outer;
};

class Rva0010EE67
{
public:
	virtual void rva0010F2E5();
private:
	char m_pad[4];
	Rva0010F2E5Inner *m_inner;
	int m_flagC;
};

struct Rva0010F2E5Guard
{
	Rva00041004 *m_target;
	unsigned char m_locked;
};

// ?rva0010F2E5@Rva0010EE67@@UAEXXZ present-unmatched
void Rva0010EE67::rva0010F2E5()
{
	Rva00041004 *p;
	Rva0010F2E5Inner *inner = m_inner;
	if (inner != 0)
	{
		Rva0010F2E5Mid *o = inner->m_outer;
		if (o == 0)
			p = 0;
		else
			p = (Rva00041004 *)((char *)o + 0x38);
	}
	else
		p = 0;
	Rva0010F2E5Guard g;
	g.m_target = p;
	g.m_locked = 0;
	((Rva0010F24F *)&g)->rva0010F24F();
	void *s = m_inner->m_stream;
	if (s != 0)
		AIL_service_stream(s, (m_flagC == 0) ? 1 : 0);
	if (g.m_locked != 0)
		((Rva0010F26E *)&g)->rva0010F26E();
}
