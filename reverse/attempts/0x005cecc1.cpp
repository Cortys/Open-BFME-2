// ?Rva005CECC1Create@@YAPAVRva005CECC1@@PAV1@PBUPayload@Rva005CEB57@@@Z
// partial score=0.92 date=2026-10-04
// Rva005CECC1Create, retail 0x005CECC1, 50 bytes.
// Free __cdecl creator: guarded new of the payload class with +4 refcount and
// 6-dword payload from *src, stores to out+0 with AddRef inc, returns out.
// Evidence: packet disassembly, push size call ??2@YAPAXI@Z row, test je xor null
// path, push arg call Rva005CEB57 row, store to [ecx] with inc [eax+4], leave ret.
// new (std::nothrow) at /O1 /Oy- reaches 51B (one over); retail's guard is
// push ecx + and [ebp-4],0 around a single operator new call.
// cl: /O1 /MD /Oy-
#include <new>

class Rva005CEB57
{
public:
	struct Payload { int v[6]; };
	Rva005CEB57(const Payload *src) throw();
	virtual ~Rva005CEB57() throw() {}
	int m_ref; // +4
	Payload m_data; // +8
};

class Rva005CECC1
{
public:
	Rva005CEB57 *m_00;
};

// ?Rva005CECC1Create@@YAPAVRva005CECC1@@PAV1@PBUPayload@Rva005CEB57@@@Z present-unmatched
Rva005CECC1 * __cdecl Rva005CECC1Create(Rva005CECC1 *out, const Rva005CEB57::Payload *src)
{
	Rva005CEB57 *p = new (std::nothrow) Rva005CEB57(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}
