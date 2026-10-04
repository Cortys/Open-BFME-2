// ?rva0010F4FA@Rva0010EF14@@UAEXXZ
// partial score=0.97 date=2026-10-04
// cl: /O1 /MD
// ?rva0010F4FA@Rva0010EF14@@UAEXXZ @0x0010F4FA 93B.
// Vtable slot 1 of Rva0010EF14 (vtable 0x007CFA84 from rowed ctor 0x0010EF14
// taking string plus two floats): guarded AIL_set_stream_reverb_levels on
// the +0x08 inner stream with the +0x0C/+0x10 floats. Guard target is +0x38
// of the +0x0C outer (null-checked pair) locked via rowed 0x0010F24F and
// unlocked via rowed 0x0010F26E when the guard flag is set. Shape follows
// landed siblings Rva0010F33C and Rva0010F38A. Callees rowed.
extern "C" __declspec(dllimport) void __stdcall AIL_set_stream_reverb_levels(void *stream, float a, float b);

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

struct Rva0010F4FAMid
{
	char pad[0x38];
};

struct Rva0010F4FAInner
{
	char pad0[8];
	void *m_stream;
	Rva0010F4FAMid *m_outer;
};

class Rva0010EF14
{
public:
	virtual void rva0010F4FA();
private:
	char m_pad[4];
	Rva0010F4FAInner *m_inner;
	float m_a;
	float m_b;
};

struct Rva0010F4FAGuard
{
	Rva00041004 *m_target;
	unsigned char m_locked;
};

// ?rva0010F4FA@Rva0010EF14@@UAEXXZ present-unmatched
void Rva0010EF14::rva0010F4FA()
{
	Rva00041004 *p;
	Rva0010F4FAInner *inner = m_inner;
	if (inner != 0)
	{
		Rva0010F4FAMid *o = inner->m_outer;
		if (o == 0)
			p = 0;
		else
			p = (Rva00041004 *)((char *)o + 0x38);
	}
	else
		p = 0;
	Rva0010F4FAGuard g;
	g.m_target = p;
	g.m_locked = 0;
	((Rva0010F24F *)&g)->rva0010F24F();
	void *s = m_inner->m_stream;
	if (s != 0)
		AIL_set_stream_reverb_levels(s, m_a, m_b);
	if (g.m_locked != 0)
		((Rva0010F26E *)&g)->rva0010F26E();
}
