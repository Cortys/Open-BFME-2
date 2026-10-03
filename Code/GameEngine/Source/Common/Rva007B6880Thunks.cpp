// cl: /Ireference/shims/bfme2_ascii /O1 /MD
// ?rva007B6880@@YAXXZ @ 0x007B6880 (10B). Global setter thunk: ecx=&g_Va00DDEB24 then tail-jmp to rowed ?apply@Rva00019EC0DwordImmSetter@@QAEXXZ (0x00019EC0) which sets [ecx],0xBBC8D4. No callers. Prev 0x007B5860 (Rva00CE12FCMutex.cpp) next 0x007B7270 (BfmeConv804.cpp). Honest address name; no donor.
class Rva00019EC0DwordImmSetter
{
public:
	void apply();
};

extern unsigned g_Va00DDEB24;
// g_Va00DDEB24: matched references place it at VA 0xddeb24 (zero-filled .bss).
unsigned int g_Va00DDEB24;

void __cdecl rva007B6880()
{
	Rva00019EC0DwordImmSetter *p = (Rva00019EC0DwordImmSetter *)&g_Va00DDEB24;
	return p->apply();
}

// ?clear@Rva0009990D@@QAEXXZ pin-only target for next thunk (26B @0x0009990D).
class Rva0009990D
{
public:
	void clear();
};

extern unsigned g_Va009E5DF8;
// g_Va009E5DF8: matched references place it at VA 0xde5df8 (zero-filled .bss).
unsigned int g_Va009E5DF8;

// ?rva007B6C9B@@YAXXZ @ 0x007B6C9B (10B). Global clear thunk: ecx=&g_Va009E5DF8 then tail-jmp to pinned ?clear@Rva0009990D@@QAEXXZ (0x0009990D). No callers. Prev is our 0x007B6880 row in this TU. Honest address name.
void __cdecl rva007B6C9B()
{
	Rva0009990D *p = (Rva0009990D *)&g_Va009E5DF8;
	return p->clear();
}

class CriticalSectionClass
{
public:
	~CriticalSectionClass();
};

extern unsigned g_Va00DE4B34;

// ?rva007B6C66@@YAXXZ @ 0x007B6C66 (10B). Global CriticalSectionClass dtor thunk: ecx=&g_Va00DE4B34 then tail-jmp to rowed ??1CriticalSectionClass@@QAE@XZ (0x00613B10).
void __cdecl rva007B6C66()
{
	CriticalSectionClass *p = (CriticalSectionClass *)&g_Va00DE4B34;
	return p->~CriticalSectionClass();
}

class MutexClass
{
public:
	~MutexClass();
};

extern unsigned g_Va00DE5DA0;

// ?rva007B6C70@@YAXXZ @ 0x007B6C70 (10B). Global MutexClass dtor thunk: ecx=&g_Va00DE5DA0 then tail-jmp to rowed ??1MutexClass@@QAE@XZ (0x00613A20).
void __cdecl rva007B6C70()
{
	MutexClass *p = (MutexClass *)&g_Va00DE5DA0;
	return p->~MutexClass();
}

// ?Free_String@StringClass@@AAEXXZ rowed target for next thunks (0x00610A40).
class StringClass
{
	friend void __cdecl rva007B7050();
	friend void __cdecl rva007B7070();
private:
	void Free_String();
};

extern unsigned g_Va009EE91C;
// ?g_Va009EE91C@@3IA: the global at this VA is ?texture_statistics_string@@3VStringClass@@A; this name is an alias for it.
#pragma comment(linker, "/alternatename:?g_Va009EE91C@@3IA=?texture_statistics_string@@3VStringClass@@A")
extern unsigned g_Va009EE938;
// g_Va009EE938: matched references place it at VA 0xdee938 (zero-filled .bss).
unsigned int g_Va009EE938;

// ?rva007B7050@@YAXXZ @ 0x007B7050 (10B). Global Free_String thunk: ecx=&g_Va009EE91C then tail-jmp to rowed ?Free_String@StringClass@@AAEXXZ (0x00610A40). No callers. Prev is our 0x007B6C9B row in this TU. Honest address name.
void __cdecl rva007B7050()
{
	StringClass *p = (StringClass *)&g_Va009EE91C;
	return p->Free_String();
}

// ?rva007B7070@@YAXXZ @ 0x007B7070 (10B). Global Free_String thunk: ecx=&g_Va009EE938 then tail-jmp to rowed ?Free_String@StringClass@@AAEXXZ (0x00610A40). No callers. Same target as 0x007B7050, different global. Honest address name.
void __cdecl rva007B7070()
{
	StringClass *p = (StringClass *)&g_Va009EE938;
	return p->Free_String();
}

// ??1?$VectorClass@UTextureStatisticsStruct@@@@UAE@XZ rowed target for next thunk (67B @0x0012A4D0).
struct TextureStatisticsStruct;
template<class T>
class VectorClass
{
public:
	virtual ~VectorClass();
};

extern unsigned g_Va009EE920;
// g_Va009EE920: matched references place it at VA 0xdee920 (zero-filled .bss).
unsigned int g_Va009EE920;

// ?rva007B7060@@YAXXZ @ 0x007B7060 (10B). Global VectorClass dtor thunk: ecx=&g_Va009EE920 then tail-jmp to rowed ??1?$VectorClass@UTextureStatisticsStruct@@@@UAE@XZ (0x0012A4D0). No callers. Prev 0x007B7050 next 0x007B7070 in this TU. Honest address name.
void __cdecl rva007B7060()
{
	VectorClass<TextureStatisticsStruct> *p = (VectorClass<TextureStatisticsStruct> *)&g_Va009EE920;
	return p->VectorClass<TextureStatisticsStruct>::~VectorClass();
}

// ??1AsciiString@@QAE@XZ rowed target for next thunk (5B @0x0048BA39, ICF with StringBase clear/dtor).
#include "ascii_string.h"

extern unsigned g_Va00DE0878;
extern unsigned g_Va00DDF5B4;

// ?rva007B6A5A@@YAXXZ @ 0x007B6A5A (10B). Global AsciiString dtor thunk: ecx=&g_Va00DDF5B4 then tail-jmp to rowed ??1AsciiString@@QAE@XZ (0x0048BA39). No callers. Honest address name.
void __cdecl rva007B6A5A()
{
	AsciiString *p = (AsciiString *)&g_Va00DDF5B4;
	return p->~AsciiString();
}

// ?rva007B6AA0@@YAXXZ @ 0x007B6AA0 (10B). Global AsciiString dtor thunk: ecx=&g_Va00DE0878 then tail-jmp to rowed ??1AsciiString@@QAE@XZ (0x0048BA39). No callers. Prev is our 0x007B7070 row in this TU (same page). Honest address name.
void __cdecl rva007B6AA0()
{
	AsciiString *p = (AsciiString *)&g_Va00DE0878;
	return p->~AsciiString();
}

// ??1SortingRenderStateStruct@@QAE@XZ rowed target for next thunks (184B @0x0011C5C0).
class SortingRenderStateStruct
{
public:
	~SortingRenderStateStruct();
};

extern unsigned g_Va00DEDC80;
// g_Va00DEDC80: matched references place it at VA 0xdedc80 (zero-filled .bss).
unsigned int g_Va00DEDC80;
extern unsigned ScreenCurrentShader;

// ?rva007B6FC0@@YAXXZ @ 0x007B6FC0 (10B). Global SortingRenderStateStruct dtor thunk: ecx=&g_Va00DEDC80 then tail-jmp to rowed ??1SortingRenderStateStruct@@QAE@XZ (0x0011C5C0). No callers. Same page. Honest address name.
void __cdecl rva007B6FC0()
{
	SortingRenderStateStruct *p = (SortingRenderStateStruct *)&g_Va00DEDC80;
	return p->~SortingRenderStateStruct();
}

// ?rva007B6FD0@@YAXXZ @ 0x007B6FD0 (10B). Global SortingRenderStateStruct dtor thunk: ecx=&ScreenCurrentShader then tail-jmp to rowed ??1SortingRenderStateStruct@@QAE@XZ (0x0011C5C0). No callers. Same target as 0x007B6FC0, different global. Honest address name.
void __cdecl rva007B6FD0()
{
	SortingRenderStateStruct *p = (SortingRenderStateStruct *)&ScreenCurrentShader;
	return p->~SortingRenderStateStruct();
}

// ??1SegLineRendererClass@@QAE@XZ rowed target for next thunk (0x001911C0).
class SegLineRendererClass
{
public:
	~SegLineRendererClass();
};

extern unsigned g_Va009F6F30;
// g_Va009F6F30: matched references place it at VA 0xdf6f30 (zero-filled .bss).
unsigned int g_Va009F6F30;

// ?rva007B71C0@@YAXXZ @ 0x007B71C0 (10B). Global SegLineRenderer dtor thunk: ecx=&g_Va009F6F30 then tail-jmp to rowed ??1SegLineRendererClass@@QAE@XZ (0x001911C0). No callers. Prev is our 0x007B6FD0 row in this TU (same page). Honest address name.
// The deleting-dtor COMDAT copy this TU emits must match part_buf.cpp's /O2-style (add esp,4) copy, while the file stays /O1 for the other thunks: pragma on the caller controls the compiler-generated ??_G.
#pragma optimize("t", on)
void __cdecl rva007B71C0()
{
	SegLineRendererClass *p = (SegLineRendererClass *)&g_Va009F6F30;
	return p->~SegLineRendererClass();
}
#pragma optimize("", on)
