// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z
// partial score=0.93 date=2026-10-04
// cl: /O1 /MD /EHsc
// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z
// retail 0x005CE3F9, 50 bytes. Free __cdecl creator: `new Rva005CE327(src)`
// stored to out+0 with an AddRef inc, returning out.
// Evidence: guarded prolog (push ecx / and [ebp-4],0) with a single balancing
// pop ecx is retail's throwing-new form -- operator new 0x2fda0, null test
// routed to `xor eax,eax`, ctor call 0x005CE327, [ecx]=eax, inc [eax+4].
// Twin of 0x005CE2A1. /EHsc is required: it is the only setting that emits the
// `and [ebp-4],0` state-zero at all, and /O1 for the `pop ecx` arg pop.
#include <new>

class Rva005CE327
{
public:
	struct Payload { int v[3]; };
	Rva005CE327(const Payload *src);
	virtual ~Rva005CE327();
public:
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
	Rva005CE327 *p = new Rva005CE327(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}