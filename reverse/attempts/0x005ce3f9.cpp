// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z
// partial score=0.92 date=2026-10-04
// Rva005CE3F9Create, retail 0x005CE3F9, 50 bytes.
// Free __cdecl creator: guarded new of the payload class with +4 refcount and
// 3-dword payload from *src, stores to out+0 with AddRef inc, returns out.
// Evidence: packet disassembly, push size call ??2@YAPAXI@Z row, test je xor null
// path, push arg call Rva005CE327 row, store to [ecx] with inc [eax+4], leave ret.
// new (std::nothrow) at /O1 /Oy- reaches 51B (one over); retail's guard is
// push ecx + and [ebp-4],0 around a single operator new call.
// cl: /O1 /MD /Oy-
#include <new>

class Rva005CE327
{
public:
	struct Payload { int v[3]; };
	Rva005CE327(const Payload *src) throw();
	virtual ~Rva005CE327() throw() {}
	int m_ref; // +4
	Payload m_data; // +8
};

class Rva005CE3F9
{
public:
	Rva005CE327 *m_00;
};

// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z present-unmatched
Rva005CE3F9 * __cdecl Rva005CE3F9Create(Rva005CE3F9 *out, const Rva005CE327::Payload *src)
{
	Rva005CE327 *p = new (std::nothrow) Rva005CE327(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}
