// cl: /O1 /GX-
// ?Rva0050E9D3Enable@@YAXXZ @0x0050E9D3 43B.
// One-shot enabler: if global 0x00A046B4 is null or its byte at +0x278 is
// set, return; else set it and the byte at +0x54 of global 0x00A01E48, then
// tail-jmp to rowed enable 0x00222479 on global 0x009FE4CC. Callers at
// 0x00376D56 0x0043CC61 0x0050EBBD 0x0050EC17 0x0051B46C. /O1 for the tail
// jmp; /GX- matches the frameless ColdGlobal neighbours.
struct GlobalA046B4 { char pad[0x278]; unsigned char flag; };
extern GlobalA046B4 *g_Va00A046B4;
struct GlobalA01E48 { char pad[0x54]; unsigned char flag; };
extern GlobalA01E48 *g_Va00A01E48;
class Rva00222479ByteOneSetter { public: void enable(); };
extern Rva00222479ByteOneSetter *g_Va009FE4CC;
void Rva0050E9D3Enable(void)
{
	GlobalA046B4 *p = g_Va00A046B4;
	if (!p)
		return;
	if (p->flag)
		return;
	p->flag = 1;
	g_Va00A01E48->flag = 1;
	g_Va009FE4CC->enable();
}

// ?Rva004E400DEnable@@YAXXZ @0x004E400D 43B.
// One-shot enabler, twin of 0x0050E9D3 above on global 0x00A04450: if it is
// null or its byte at +0x278 is set, return; else set it and the byte at
// +0x54 of global 0x00A01E48, then tail-jmp to rowed enable 0x00222479 on
// global 0x009FE4CC. Callers at 0x00376D51 0x003CEC9F 0x0043CC5C 0x004E40BF
// 0x004E4342 0x00512DFC 0x0051B467 plus jmp 0x003BD41F. Unlock lane.
struct GlobalA04450 { char pad[0x278]; unsigned char flag; };
extern GlobalA04450 *g_Va00A04450;
void Rva004E400DEnable(void)
{
	GlobalA04450 *p = g_Va00A04450;
	if (!p)
		return;
	if (p->flag)
		return;
	p->flag = 1;
	g_Va00A01E48->flag = 1;
	g_Va009FE4CC->enable();
}

// ?Rva004E40A6Enable@@YGXH@Z @0x004E40A6 33B.
// Guarded enabler, chain lane on 0x004E400D above: call it unless global
// 0x009FE78C has 6 at +0x110 and global 0x009FEDF0 has 0 at +0x16. The int
// parameter is dead (ret 4, never read); __stdcall for the callee cleanup.
// One caller at 0x004E44EF.
struct Global9FE78C { char m_pad[0x110]; int m_val; };
extern Global9FE78C *g_Va009FE78C;
struct Global9FEDF0 { char m_pad[0x16]; unsigned char m_flag; };
extern Global9FEDF0 *g_Va009FEDF0;
void __stdcall Rva004E40A6Enable(int unused)
{
	if (g_Va009FE78C->m_val != 6 || g_Va009FEDF0->m_flag != 0)
		Rva004E400DEnable();
}

// ?Rva004E4179Get@@YAPAXXZ @0x004E4179 50B.
// One-shot guarded singleton getter: unless guard byte at 0x00A04464 is
// set, set it, point 0x00A0445C at 0x008621F0 (encoded 0x00C621F0) and set
// byte at 0x00A04460, registering cleanup RVA 0x007B8F26 (encoded
// 0x00BB8F26) via rowed _atexit, then return address of 0x00A0445C.
// Callers at 0x004E41BF 0x004E4317 0x004E4321 0x004E432C plus jmp thunk
// 0x004E4312; caller 0x004E432A uses +4 as flag byte.
extern "C" int __cdecl atexit(void (__cdecl *routine)(void));
extern void *g_Va00A0445C;
extern unsigned char g_Va00A04460;
extern int g_Va00A04464;
void *Rva004E4179Get(void)
{
	if ((g_Va00A04464 & 1) == 0)
	{
		g_Va00A04464 |= 1;
		g_Va00A0445C = (void *)0x00C621F0;
		g_Va00A04460 = 1;
		atexit((void (__cdecl *)(void))0x00BB8F26);
	}
	return &g_Va00A0445C;
}

// ?Rva004E432ASet@@YAXE@Z @0x004E432A 34B.
// Flag setter on the 0x004E4179 singleton block: if the byte arg equals the
// flag byte at +4 of the block, return; if arg is 0, call rowed enable
// 0x004E400D, then store arg. Caller 0x003BD412 forwards one dword.
void Rva004E432ASet(unsigned char val)
{
	unsigned char *flag = (unsigned char *)Rva004E4179Get() + 4;
	if (val == *flag)
		return;
	if (val == 0)
		Rva004E400DEnable();
	*flag = val;
}

// ?Rva00444040Enable@@YAXXZ @0x00444040 21B.
// Guarded enabler: if int at 0x00A03354 is 0 return else tail-jmp to rowed
// enable 0x00222479 on global 0x009FE4CC. Callers at 0x00444342 0x0044529B
// 0x0044674E. Unlock lane.
extern int g_Va00A03354;
void Rva00444040Enable(void)
{
	if (g_Va00A03354 == 0)
		return;
	g_Va009FE4CC->enable();
}

// ?Rva0052340DEnable@@YAXXZ @0x0052340D 43B.
// One-shot enabler, twin of 0x0050E9D3 above on global 0x00A04934: if it is
// null or its byte at +0x278 is set, return; else set it and the byte at
// +0x54 of global 0x00A01E48, then tail-jmp to rowed enable 0x00222479 on
// global 0x009FE4CC. Callers at 0x00523481 0x005235C9 0x005CD60B 0x005CD67A
// 0x005CD6C4 0x005CD6EF plus jmp 0x0052359B. Unlock lane.
struct GlobalA04934 { char pad[0x278]; unsigned char flag; };
extern GlobalA04934 *g_Va00A04934;
void Rva0052340DEnable(void)
{
	GlobalA04934 *p = g_Va00A04934;
	if (!p)
		return;
	if (p->flag)
		return;
	p->flag = 1;
	g_Va00A01E48->flag = 1;
	g_Va009FE4CC->enable();
}

// ?Rva0043C96FEnable@@YAXXZ @0x0043C96F 43B.
// One-shot enabler, twin of 0x0050E9D3 above on global 0x00A03314: if it is
// null or its byte at +0x278 is set, return; else set it and the byte at
// +0x54 of global 0x00A01E48, then tail-jmp to rowed enable 0x00222479 on
// global 0x009FE4CC. Callers at 0x0031C787 0x0043C9F1 0x0043CCF2 0x0051B45D
// plus jmps 0x0031AD8F 0x0031ADA9. Unlock lane.
struct GlobalA03314 { char pad[0x278]; unsigned char flag; };
extern GlobalA03314 *g_Va00A03314;
void Rva0043C96FEnable(void)
{
	GlobalA03314 *p = g_Va00A03314;
	if (!p)
		return;
	if (p->flag)
		return;
	p->flag = 1;
	g_Va00A01E48->flag = 1;
	g_Va009FE4CC->enable();
}

// ?Rva0043C9B3Get@@YAPAXXZ @0x0043C9B3 50B.
// One-shot guarded singleton getter, twin of 0x004E4179 above: unless guard
// byte at 0x00A03320 is set, set it, point 0x00A03318 at 0x0083D690
// (encoded 0x00C3D690) and set byte at 0x00A0331C, registering cleanup RVA
// 0x007B83E1 (encoded 0x00BB83E1) via rowed _atexit, then return address of
// 0x00A03318. Caller 0x0043CCD1 uses +4 as flag byte. Unlock lane.
extern void *g_Va00A03318;
extern unsigned char g_Va00A0331C;
extern int g_Va00A03320;
void *Rva0043C9B3Get(void)
{
	if ((g_Va00A03320 & 1) == 0)
	{
		g_Va00A03320 |= 1;
		g_Va00A03318 = (void *)0x00C3D690;
		g_Va00A0331C = 1;
		atexit((void (__cdecl *)(void))0x00BB83E1);
	}
	return &g_Va00A03318;
}

// ?Rva0043CCDASet@@YAXE@Z @0x0043CCDA 34B.
// Flag setter on the 0x0043C9B3 singleton block, twin of 0x004E432A above:
// if the byte arg equals the flag byte at +4 of the block, return; if arg
// is 0, call rowed enable 0x0043C96F, then store arg. Caller 0x003BD405
// forwards one dword. Chain lane on 0x0043C9B3.
void Rva0043CCDASet(unsigned char val)
{
	unsigned char *flag = (unsigned char *)Rva0043C9B3Get() + 4;
	if (val == *flag)
		return;
	if (val == 0)
		Rva0043C96FEnable();
	*flag = val;
}
