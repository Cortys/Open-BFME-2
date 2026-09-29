// ?Rva005AA05APick@@YGXPAURva005AA05AVec@@PAURva005AA05AArg@@H0@Z
// partial score=0.83 date=2026-09-29
// ?Rva005AA05APick@@YGXPAURva005AA05AVec@@PAURva005AA05AArg@@H0@Z
// partial score=0.83 date=2026-09-29
// cl: /O1 /MD /arch:SSE
// ?Rva005AA05APick@@YGXPAURva005AA05AVec@@PAURva005AA05AArg@@H0@Z @0x005AA05A 112B: free __stdcall
// picker over two 12-byte float vectors. dx = sub+0x558 minus a+0x10 and
// dy = sub+0x554 minus a+0xC land in xmm1/xmm0 via the dy-first line order;
// d2 = dx*dx+dy*dy; d2 >= float at 0x00871EA8 (extern, gate-filled) copies
// the sub vector (fallthrough), else the fallback at +0x10; z stores share
// one tail. ret 0x10 (4 stack args, +0xC unread). Verified 112B/28insns
// structural-0; only diff is a total eax<->ecx mirror (a/sub/out/fb in
// ecx/eax/ecx/eax vs retail eax/ecx/eax/ecx) stable across direct, hoisted
// and param-copy shapes, plus the gate-filled comiss address.
extern const float g_00871EA8;

struct Rva005AA05ASub
{
	unsigned char m_pad[0x554];
	float m_v554;
	float m_v558;
	float m_v55C;
};

struct Rva005AA05AArg
{
	unsigned char m_pad0[0xC];
	float m_fC;
	float m_f10;
	unsigned char m_pad1[0x10];
	Rva005AA05ASub *m_sub;
};

struct Rva005AA05AVec
{
	float m_x;
	float m_y;
	float m_z;
};

// ?Rva005AA05APick@@YGXPAURva005AA05AVec@@PAURva005AA05AArg@@H0@Z present-unmatched
void __stdcall Rva005AA05APick(Rva005AA05AVec *out, Rva005AA05AArg *a, int unused, Rva005AA05AVec *fb)
{
	float dy = a->m_sub->m_v554 - a->m_fC;
	float dx = a->m_sub->m_v558 - a->m_f10;
	Rva005AA05ASub *sub = a->m_sub;
	float d2 = dx * dx + dy * dy;
	if (d2 >= g_00871EA8) {
		out->m_x = sub->m_v554;
		out->m_y = sub->m_v558;
		out->m_z = sub->m_v55C;
	} else {
		out->m_x = fb->m_x;
		out->m_y = fb->m_y;
		out->m_z = fb->m_z;
	}
}
