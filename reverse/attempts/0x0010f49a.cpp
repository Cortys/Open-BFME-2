// ?rva0010F49A@Rva0010EEF1@@UAEXXZ
// partial score=0.97 date=2026-10-04
// cl: /O1 /MD
// ?rva0010F49A@Rva0010EEF1@@UAEXXZ @0x0010F49A 96B.
// Vtable slot 1 of Rva0010EEF1 (vtable 0x007CFA7C from rowed ctor 0x0010EEF1
// taking string plus one float): guarded AIL_set_stream_volume_pan on the
// +0x08 inner stream with the +0x0C float and the shared global float
// g_Va007C26F0. Guard target is +0x38 of the +0x0C outer (null-checked pair)
// locked via rowed 0x0010F24F and unlocked via rowed 0x0010F26E when the
// guard flag is set. Shape follows landed siblings Rva0010F33C and
// Rva0010F38A. Callees rowed.
extern "C" __declspec(dllimport) void __stdcall AIL_set_stream_volume_pan(void *stream, float a, float b);

extern float g_Va007C26F0;

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

struct Rva0010F49AMid
{
	char pad[0x38];
};

struct Rva0010F49AInner
{
	char pad0[8];
	void *m_stream;
	Rva0010F49AMid *m_outer;
};

class Rva0010EEF1
{
public:
	virtual void rva0010F49A();
private:
	char m_pad[4];
	Rva0010F49AInner *m_inner;
	float m_a;
};

struct Rva0010F49AGuard
{
	Rva00041004 *m_target;
	unsigned char m_locked;
};

// ?rva0010F49A@Rva0010EEF1@@UAEXXZ present-unmatched
void Rva0010EEF1::rva0010F49A()
{
	Rva00041004 *p;
	Rva0010F49AInner *inner = m_inner;
	if (inner != 0)
	{
		Rva0010F49AMid *o = inner->m_outer;
		if (o == 0)
			p = 0;
		else
			p = (Rva00041004 *)((char *)o + 0x38);
	}
	else
		p = 0;
	Rva0010F49AGuard g;
	g.m_target = p;
	g.m_locked = 0;
	((Rva0010F24F *)&g)->rva0010F24F();
	void *s = m_inner->m_stream;
	if (s != 0)
		AIL_set_stream_volume_pan(s, m_a, g_Va007C26F0);
	if (g.m_locked != 0)
		((Rva0010F26E *)&g)->rva0010F26E();
}
