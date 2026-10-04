// ?Rva005CE2A1Create@@YAPAVRva005CE2A1@@PAV1@PBUPayload@Rva005CE259@@@Z
// partial score=0.92 date=2026-10-04
// ?Rva005CE2A1Create@@YAPAVRva005CE2A1@@PAV1@PBUPayload@Rva005CE259@@@Z, retail 0x005CE2A1, 50 bytes.
// Free __cdecl creator: news 0x10-byte Rva005CE259 with +4 refcount and 8B
// payload from *src, stores to out+0 with AddRef inc, returns out.
// Evidence: packet disassembly, push 0x10 call ??2@YAPAXI@Z row,
// test je xor null path, push arg call 0x005CE259 row, store to [ecx] with
// inc [eax+4], leave ret (caller cleans 8B); twin of banked 0x005CE3F9 45/50.
// Retail prolog is a guarded new-expression (push ecx / and [ebp-4],0 around the
// operator new call with a single balancing pop ecx); new (std::nothrow) is the
// closest source form (51B at /O1 /Oy-), still 1 byte off.
// cl: /O1 /MD /Oy-
#include <new>

class Rva005CE259
{
public:
	struct Payload { int v[2]; };
	Rva005CE259(const Payload *src) throw();
	virtual ~Rva005CE259() throw() {}
	int m_ref; // +4
	Payload m_data; // +8
};

class Rva005CE2A1
{
public:
	Rva005CE259 *m_00;
};

// ?Rva005CE2A1Create@@YAPAVRva005CE2A1@@PAV1@PBUPayload@Rva005CE259@@@Z present-unmatched
Rva005CE2A1 * __cdecl Rva005CE2A1Create(Rva005CE2A1 *out, const Rva005CE259::Payload *src)
{
	Rva005CE259 *p = new (std::nothrow) Rva005CE259(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}