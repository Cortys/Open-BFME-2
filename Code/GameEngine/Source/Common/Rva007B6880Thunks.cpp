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
extern unsigned g_Va00DEAF18;

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

// ?rva007B6CFF@@YAXXZ @ 0x007B6CFF (10B). Global AsciiString dtor thunk: ecx=&g_Va00DEAF18 then tail-jmp to rowed ??1AsciiString@@QAE@XZ (0x0048BA39).
void __cdecl rva007B6CFF()
{
	AsciiString *p = (AsciiString *)&g_Va00DEAF18;
	return p->~AsciiString();
}

namespace _STL
{
template <class T>
class char_traits {};

template <class T>
class allocator {};

template <class CharT, class Alloc>
class _String_base
{
public:
	~_String_base();
};

template <class CharT, class Traits, class Alloc>
class basic_string
{
public:
	~basic_string();
};
}

typedef _STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> > StlNarrowString;
typedef _STL::_String_base<char, _STL::allocator<char> > StlNarrowStringBase;

extern unsigned g_Va00DDEB2C;
extern unsigned g_Va00DDEF08;
extern unsigned g_Va00DDEEFC;
extern unsigned g_Va00DDEF14;
extern unsigned g_Va00DDEEE4;
extern unsigned g_Va00DDEF38;
extern unsigned g_Va00DDEEF0;
extern unsigned g_Va00DDEF20;
extern unsigned g_Va00DDEF2C;

// ?rva007B68C0@@YAXXZ @ 0x007B68C0 (10B). Global string dtor thunk: ecx=&g_Va00DDEB2C then tail-jmp to rowed ??1?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@XZ (0x00142D70).
void __cdecl rva007B68C0()
{
	StlNarrowString *p = (StlNarrowString *)&g_Va00DDEB2C;
	return p->~basic_string();
}

// ?rva007B6A00@@YAXXZ @ 0x007B6A00 (10B). Global string base dtor thunk: ecx=&g_Va00DDEEF0 then tail-jmp to rowed ??1?$_String_base@DV?$allocator@D@_STL@@@_STL@@QAE@XZ (0x0000B3C0).
void __cdecl rva007B6A00()
{
	StlNarrowStringBase *p = (StlNarrowStringBase *)&g_Va00DDEEF0;
	return p->~_String_base();
}

// ?rva007B6A10@@YAXXZ @ 0x007B6A10 (10B). Global string base dtor thunk: ecx=&g_Va00DDEF20 then tail-jmp to rowed ??1?$_String_base@DV?$allocator@D@_STL@@@_STL@@QAE@XZ (0x0000B3C0).
void __cdecl rva007B6A10()
{
	StlNarrowStringBase *p = (StlNarrowStringBase *)&g_Va00DDEF20;
	return p->~_String_base();
}

// ?rva007B6A40@@YAXXZ @ 0x007B6A40 (10B). Global string base dtor thunk: ecx=&g_Va00DDEF2C then tail-jmp to rowed ??1?$_String_base@DV?$allocator@D@_STL@@@_STL@@QAE@XZ (0x0000B3C0).
void __cdecl rva007B6A40()
{
	StlNarrowStringBase *p = (StlNarrowStringBase *)&g_Va00DDEF2C;
	return p->~_String_base();
}

// ?rva007B69D0@@YAXXZ @ 0x007B69D0 (10B). Global string dtor thunk: ecx=&g_Va00DDEF08 then tail-jmp to rowed ??1?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@XZ (0x00142D70).
void __cdecl rva007B69D0()
{
	StlNarrowString *p = (StlNarrowString *)&g_Va00DDEF08;
	return p->~basic_string();
}

// ?rva007B69E0@@YAXXZ @ 0x007B69E0 (10B). Global string dtor thunk: ecx=&g_Va00DDEEFC then tail-jmp to rowed ??1?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@XZ (0x00142D70).
void __cdecl rva007B69E0()
{
	StlNarrowString *p = (StlNarrowString *)&g_Va00DDEEFC;
	return p->~basic_string();
}

// ?rva007B69F0@@YAXXZ @ 0x007B69F0 (10B). Global string dtor thunk: ecx=&g_Va00DDEF14 then tail-jmp to rowed ??1?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@XZ (0x00142D70).
void __cdecl rva007B69F0()
{
	StlNarrowString *p = (StlNarrowString *)&g_Va00DDEF14;
	return p->~basic_string();
}

// ?rva007B6A20@@YAXXZ @ 0x007B6A20 (10B). Global string dtor thunk: ecx=&g_Va00DDEEE4 then tail-jmp to rowed ??1?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@XZ (0x00142D70).
void __cdecl rva007B6A20()
{
	StlNarrowString *p = (StlNarrowString *)&g_Va00DDEEE4;
	return p->~basic_string();
}

// ?rva007B6A30@@YAXXZ @ 0x007B6A30 (10B). Global string dtor thunk: ecx=&g_Va00DDEF38 then tail-jmp to rowed ??1?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@XZ (0x00142D70).
void __cdecl rva007B6A30()
{
	StlNarrowString *p = (StlNarrowString *)&g_Va00DDEF38;
	return p->~basic_string();
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

class EvacuateDamage
{
public:
	virtual ~EvacuateDamage();
};

extern unsigned g_Va00DDF58C;

// ?rva007B6A6E@@YAXXZ @ 0x007B6A6E (10B). Global EvacuateDamage dtor thunk: ecx=&g_Va00DDF58C then tail-jmp to rowed ??1EvacuateDamage@@UAE@XZ (0x0002CD7B).
void __cdecl rva007B6A6E()
{
	EvacuateDamage *p = (EvacuateDamage *)&g_Va00DDF58C;
	return p->EvacuateDamage::~EvacuateDamage();
}

#include "../../Include/Common/Rva00041004Lock.h"

extern unsigned g_Va00DE0850;
extern unsigned g_Va00DE0828;

// ?rva007B6A80@@YAXXZ @ 0x007B6A80 (10B). Global Rva00041004 dtor thunk: ecx=&g_Va00DE0850 then tail-jmp to rowed ??1Rva00041004@@UAE@XZ (0x00040FE5).
void __cdecl rva007B6A80()
{
	Rva00041004 *p = (Rva00041004 *)&g_Va00DE0850;
	return p->Rva00041004::~Rva00041004();
}

// ?rva007B6A90@@YAXXZ @ 0x007B6A90 (10B). Global Rva00041004 dtor thunk: ecx=&g_Va00DE0828 then tail-jmp to rowed ??1Rva00041004@@UAE@XZ (0x00040FE5).
void __cdecl rva007B6A90()
{
	Rva00041004 *p = (Rva00041004 *)&g_Va00DE0828;
	return p->Rva00041004::~Rva00041004();
}

class GeometryInfo
{
public:
	virtual ~GeometryInfo();
};

extern unsigned g_Va00DE1D00;
extern unsigned g_Va00DE1D60;

// ?rva007B6B19@@YAXXZ @ 0x007B6B19 (10B). Global GeometryInfo dtor thunk: ecx=&g_Va00DE1D00 then tail-jmp to rowed ??1GeometryInfo@@UAE@XZ (0x00050B2A).
void __cdecl rva007B6B19()
{
	GeometryInfo *p = (GeometryInfo *)&g_Va00DE1D00;
	return p->GeometryInfo::~GeometryInfo();
}

// ?rva007B6B23@@YAXXZ @ 0x007B6B23 (10B). Global GeometryInfo dtor thunk: ecx=&g_Va00DE1D60 then tail-jmp to rowed ??1GeometryInfo@@UAE@XZ (0x00050B2A).
void __cdecl rva007B6B23()
{
	GeometryInfo *p = (GeometryInfo *)&g_Va00DE1D60;
	return p->GeometryInfo::~GeometryInfo();
}

class Rva0090088
{
public:
	virtual ~Rva0090088();
};

extern unsigned g_Va00DE2084;

// ?rva007B6C2A@@YAXXZ @ 0x007B6C2A (10B). Global Rva0090088 dtor thunk: ecx=&g_Va00DE2084 then tail-jmp to rowed ??1Rva0090088@@UAE@XZ (0x00090088).
void __cdecl rva007B6C2A()
{
	Rva0090088 *p = (Rva0090088 *)&g_Va00DE2084;
	return p->Rva0090088::~Rva0090088();
}

class Rva00090771DwordImmSetter
{
public:
	void apply();
};

extern unsigned g_Va00DE4878;

// ?rva007B6C3E@@YAXXZ @ 0x007B6C3E (10B). Global Rva00090771DwordImmSetter thunk: ecx=&g_Va00DE4878 then tail-jmp to rowed ?apply@Rva00090771DwordImmSetter@@QAEXXZ (0x00090771).
void __cdecl rva007B6C3E()
{
	Rva00090771DwordImmSetter *p = (Rva00090771DwordImmSetter *)&g_Va00DE4878;
	return p->apply();
}

class Rva001EAF7B
{
public:
	bool rva001EAF7B();
};

extern unsigned g_Va00DA60E8;

// ?rva007B6850@@YAXXZ @ 0x007B6850 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6850()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6AAA@@YAXXZ @ 0x007B6AAA (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6AAA()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6AB4@@YAXXZ @ 0x007B6AB4 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6AB4()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6ABE@@YAXXZ @ 0x007B6ABE (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6ABE()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6AF1@@YAXXZ @ 0x007B6AF1 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6AF1()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6AFB@@YAXXZ @ 0x007B6AFB (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6AFB()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B0F@@YAXXZ @ 0x007B6B0F (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B0F()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B2D@@YAXXZ @ 0x007B6B2D (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B2D()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B4B@@YAXXZ @ 0x007B6B4B (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B4B()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B55@@YAXXZ @ 0x007B6B55 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B55()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B5F@@YAXXZ @ 0x007B6B5F (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B5F()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B69@@YAXXZ @ 0x007B6B69 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B69()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B7D@@YAXXZ @ 0x007B6B7D (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B7D()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B87@@YAXXZ @ 0x007B6B87 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B87()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6B9B@@YAXXZ @ 0x007B6B9B (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6B9B()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6BA5@@YAXXZ @ 0x007B6BA5 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6BA5()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6BAF@@YAXXZ @ 0x007B6BAF (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6BAF()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6BCD@@YAXXZ @ 0x007B6BCD (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6BCD()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6BD7@@YAXXZ @ 0x007B6BD7 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6BD7()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6BEB@@YAXXZ @ 0x007B6BEB (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6BEB()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6BFF@@YAXXZ @ 0x007B6BFF (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6BFF()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C09@@YAXXZ @ 0x007B6C09 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C09()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C16@@YAXXZ @ 0x007B6C16 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C16()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C20@@YAXXZ @ 0x007B6C20 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C20()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C34@@YAXXZ @ 0x007B6C34 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C34()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C48@@YAXXZ @ 0x007B6C48 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C48()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C52@@YAXXZ @ 0x007B6C52 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C52()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6C5C@@YAXXZ @ 0x007B6C5C (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6C5C()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CA5@@YAXXZ @ 0x007B6CA5 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CA5()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CB9@@YAXXZ @ 0x007B6CB9 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CB9()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CC3@@YAXXZ @ 0x007B6CC3 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CC3()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CCD@@YAXXZ @ 0x007B6CCD (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CCD()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CD7@@YAXXZ @ 0x007B6CD7 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CD7()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CEB@@YAXXZ @ 0x007B6CEB (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CEB()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

// ?rva007B6CF5@@YAXXZ @ 0x007B6CF5 (10B). Global Rva001EAF7B thunk: ecx=&g_Va00DA60E8 then tail-jmp to rowed ?rva001EAF7B@Rva001EAF7B@@QAE_NXZ (0x001EAF7B).
void __cdecl rva007B6CF5()
{
	Rva001EAF7B *p = (Rva001EAF7B *)&g_Va00DA60E8;
	p->rva001EAF7B();
}

