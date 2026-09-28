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
