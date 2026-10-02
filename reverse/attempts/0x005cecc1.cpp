// ?Rva005CECC1Create@@YAPAVRva005CECC1@@PAV1@PBUPayload@Rva005CEB57@@@Z
// partial score=0.9 date=2026-10-02
// cl: /Os /MD /Oy-
// ?Rva005CECC1Create@@YAPAVRva005CECC1@@PAV1@PBUPayload@Rva005CEB57@@@Z, retail 0x005CECC1, 50 bytes.
// Free __cdecl creator: news 0x20-byte Rva005CEB57 with +4 refcount and 24B
// payload from *src, stores to out+0 with AddRef inc, returns out.
// Evidence: packet disassembly, push 0x20 call ??2@YAPAXI@Z row,
// push arg call 0x005CEB57 row, store to [ecx] with inc [eax+4], leave ret;
// chain from just-landed 0x005CEB57; twin of stashed 0x005CE3F9/0x005CEC8F/0x005CE2A1.
class Rva005CEB57
{
public:
	struct Payload { int v[6]; };
	Rva005CEB57(const Payload *src) throw();
	virtual ~Rva005CEB57() throw();
	int m_ref; // +4
	Payload m_data; // +8
};

class Rva005CECC1
{
public:
	Rva005CEB57 *m_00;
};

// ?Rva005CECC1Create@@YAPAVRva005CECC1@@PAV1@PBUPayload@Rva005CEB57@@@Z present-unmatched
struct ZeroPad { int v; ZeroPad() : v(0) {} };
Rva005CECC1 *__cdecl Rva005CECC1Create(Rva005CECC1 *out, const Rva005CEB57::Payload *src)
{
	ZeroPad pad;
	Rva005CEB57 *p = new Rva005CEB57(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}
