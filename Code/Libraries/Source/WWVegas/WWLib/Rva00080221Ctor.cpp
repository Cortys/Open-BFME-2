// cl: /O1 /MD
// ??0Rva00080221@@QAE@PBH@Z, retail 0x00080221 (53B).
// Honest-address ctor for an unknown ref-counted wrapper (12B impl with
// vtable VA 0x00BC6FF4 at +0, refcount at +4, int value at +8). Evidence:
// stores vtable 0x007C6FF4, calls rowed operator new ??2@YAPAXI@Z at
// 0x0002FDA0 with null check (push 0xC + test + je + xor), copies *arg to
// +8, publishes impl to [this+0] then bumps refcount 0->1 via inc [eax+4],
// returns this (mov eax,esi, ret 4). 19 callers including 0x0007FFED which
// builds a stack temp for ReflectionTexture/BlendUsingTerrainAlpha/
// TransparentWaterDepth dispatch. Neighbours are STLport WWLib TUs; new TU
// uses /O1 /MD per manual-vtable ctor precedent Rva00575540Ctor.cpp.
void *__cdecl operator new(unsigned int size);

struct Rva007C6FF4Impl
{
	void *m_vtable;
	int m_refcount;
	int m_value;
};

class Rva00080221
{
public:
	Rva00080221(const int *arg);
private:
	Rva007C6FF4Impl *m_impl;
};

Rva00080221::Rva00080221(const int *arg)
{
	Rva007C6FF4Impl *p = (Rva007C6FF4Impl *)operator new(12);
	if (p != 0) {
		p->m_refcount = 0;
		p->m_vtable = (void *)0x00BC6FF4;
		p->m_value = *arg;
	} else {
		p = 0;
	}
	m_impl = p;
	if (p != 0) {
		++p->m_refcount;
	}
}
