// ??0Rva00161050@@QAE@ABU0@@Z
// partial score=0.9 date=2026-10-04
// ??0Rva00161050@@QAE@ABU0@@Z
// partial score=0.9 date=2026-10-02
// cl: /O2 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
//
// Best-effort candidate for retail 0x00161050 (77 bytes), banked by seat 2.
//
// The target is an /O2 copy constructor of a 0x24-byte record that copies
// +0x00 (one word), +0x04..+0x13 (four words), +0x14..+0x1F (three words) and
// the byte at +0x20, with no calls. Matching that member grouping with three
// nested /O2 copy constructors reproduces the exact instruction sequence and
// grouping but at 73 bytes against 77: the target keeps the source pointer in
// esi and uses ebx+ebp as copy temporaries, while MSVC 7.1 here allocates
// ecx/edx/esi/edi and needs one fewer callee-saved register. The remaining
// gap is register allocation, not identity or layout.
// Target bytes: 53 55 56 8b 74 24 10 57 8b c1 8b 0e 89 08 8d 4e 04 8d 50 04
//               8b f9 8b 2f 8b da 89 2b ...

struct Rva00161050Big16
{
	int a, b, c, d;
	Rva00161050Big16() {}
	Rva00161050Big16(const Rva00161050Big16 &o) { a = o.a; b = o.b; c = o.c; d = o.d; }
};

struct Rva00161050Small12
{
	float x, y, z;
	Rva00161050Small12() {}
	Rva00161050Small12(const Rva00161050Small12 &o) { x = o.x; y = o.y; z = o.z; }
};

struct Rva00161050
{
	int m0;					// +0x00
	Rva00161050Big16 m4;			// +0x04
	Rva00161050Small12 m14;			// +0x14
	unsigned char m20;			// +0x20
	char m_pad[3];				// +0x21

	Rva00161050();
	Rva00161050(const Rva00161050 &other);
};

Rva00161050::Rva00161050(const Rva00161050 &other)
{
	m0 = other.m0;
	m4 = other.m4;
	m14 = other.m14;
	m20 = other.m20;
}
