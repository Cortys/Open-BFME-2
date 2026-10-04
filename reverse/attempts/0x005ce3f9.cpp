// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z
// partial score=0.96 date=2026-10-04
// cl: /O1 /MD /EHs-c-
// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z
// retail 0x005CE3F9, 50 bytes. Free __cdecl creator: `new Rva005CE327(src)`
// stored to out+0 with an AddRef inc, returning out.
// Target evidence: prolog `push ebp / mov ebp,esp / push ecx / and [ebp-4],0`
// then `push 0x10 / call 0x2fda0` (operator new), null test routed to
// `xor eax,eax`, ctor 0x005CE259, `mov [ecx],eax`, `inc [eax+4]`, leave/ret.
// Twin of 0x005CE2A1 (3-dword payload; retail allocates 0x14 here).
//
// The `and [ebp-4],0` state slot is written and never read back. Under /EHsc-
// this toolchain emits that state-zero TOGETHER with a SEH registration
// (`mov eax,0 / call __EH_prolog 0x00629188` plus the `mov fs:[0],ecx`
// epilogue), which retail does not have. /EHs-c- drops the registration and
// keeps retail's exact frame, argument addressing and epilogue, but spells
// the slot's zero-init `mov dword [ebp-4],0`. See reverse/re_attempts.log.
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
	volatile int state = 0;
	Rva005CE327 *p = new Rva005CE327(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}