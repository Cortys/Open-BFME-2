// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z
// partial score=0.9 date=2026-10-02
// cl: /Os /MD /Oy-
// ?Rva005CE3F9Create@@YAPAVRva005CE3F9@@PAV1@PBUPayload@Rva005CE327@@@Z, retail 0x005CE3F9, 50 bytes.
// Free __cdecl creator: news 0x14-byte Rva005CE327 with +4 refcount and 12B
// payload from *src, stores to out+0 with AddRef inc, returns out.
// Evidence: packet disassembly, push 0x14 call ??2@YAPAXI@Z row,
// test je xor null path, push arg call 0x005CE327 row, store to [ecx] with
// inc [eax+4], leave ret (caller cleans 8B); unblocks 0x005CE5B3.
class Rva005CE327
{
public:
	struct Payload { int v[3]; };
	Rva005CE327(const Payload *src) throw();
	virtual ~Rva005CE327();
	int m_ref; // +4
	Payload m_data; // +8
};

class Rva005CE3F9
{
public:
	Rva005CE327 *m_00;
};

Rva005CE3F9 * __cdecl Rva005CE3F9Create(Rva005CE3F9 *out, const Rva005CE327::Payload *src)
{
	int pad = 0;
	Rva005CE327 *p = new Rva005CE327(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	(void)pad;
	return out;
}
