// ?rva0010F28D@Rva0010EE4F@@UAEXXZ
// partial score=0.94 date=2026-10-04
// cl: /O1 /MD
// ?rva0010F28D@Rva0010EE4F@@UAEXXZ @0x0010F28D 88B.
// Vtable slot 1 of Rva0010EE4F (vtable 0x007CFA4C from rowed ctor 0x0010EE4F):
// guarded AIL_close_stream on the +0x08 inner stream nulled after close.
// Guard target is +0x38 of the +0x0C outer (null-checked pair) locked via
// rowed 0x0010F24F and unlocked via rowed 0x0010F26E when the guard flag
// is set. Shape follows landed siblings Rva0010F33C (0x0010F33C) and
// Rva0010F38A (0x0010F38A). Callees rowed.
extern "C" __declspec(dllimport) void __stdcall AIL_close_stream(void *stream);

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

struct Rva0010F28DMid
{
	char pad[0x38];
};

struct Rva0010F28DInner
{
	char pad0[8];
	void *m_stream;
	Rva0010F28DMid *m_outer;
};

class Rva0010EE4F
{
public:
	virtual void rva0010F28D();
private:
	char m_pad[4];
	Rva0010F28DInner *m_inner;
};

struct Rva0010F28DGuard
{
	Rva00041004 *m_target;
	unsigned char m_locked;
};

// ?rva0010F28D@Rva0010EE4F@@UAEXXZ present-unmatched
void Rva0010EE4F::rva0010F28D()
{
	Rva00041004 *p;
	Rva0010F28DInner *inner = m_inner;
	if (inner != 0)
	{
		Rva0010F28DMid *o = inner->m_outer;
		if (o == 0)
			p = 0;
		else
			p = (Rva00041004 *)((char *)o + 0x38);
	}
	else
		p = 0;
	Rva0010F28DGuard g;
	g.m_target = p;
	g.m_locked = 0;
	((Rva0010F24F *)&g)->rva0010F24F();
	void *s = m_inner->m_stream;
	if (s != 0)
	{
		AIL_close_stream(s);
		m_inner->m_stream = 0;
	}
	if (g.m_locked != 0)
		((Rva0010F26E *)&g)->rva0010F26E();
}
