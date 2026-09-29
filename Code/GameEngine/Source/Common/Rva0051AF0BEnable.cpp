// cl: /O1 /GX-
// ?Rva0051AF0BEnable@@YAXH@Z @0x0051AF0B 59B.
// One-shot enabler with stored int: if global 0x00A04910 is null or its byte
// at +0x278 is set, return; else set it, store the arg at +0x280, set the byte
// at +0x54 of global 0x00A01E48, then tail-jmp to rowed enable 0x00222479 on
// global 0x009FE4CC. Same idiom as rowed Rva0050E9D3Enable plus the stored
// value; small callers at 0x0051B11E 0x0051B502 pass 0.
// Evidence: unlock lane, unblocks 0x0051B11C 0x00435DE7 0x0051B90B 0x0051B4F7.
struct GlobalA04910 { char pad[0x278]; unsigned char flag; char pad2[7]; int val; };
extern GlobalA04910 *g_Va00A04910;
struct GlobalA01E48 { char pad[0x54]; unsigned char flag; };
extern GlobalA01E48 *g_Va00A01E48;
class Rva00222479ByteOneSetter { public: void enable(); };
extern Rva00222479ByteOneSetter *g_Va009FE4CC;
void __cdecl Rva0051AF0BEnable(int val)
{
	GlobalA04910 *p = g_Va00A04910;
	if (!p)
		return;
	if (p->flag)
		return;
	p->flag = 1;
	g_Va00A04910->val = val;
	g_Va00A01E48->flag = 1;
	g_Va009FE4CC->enable();
}
