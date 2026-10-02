// ?Rva005CEC8FCreate@@YAPAVRva005CEC8F@@PAV1@PBUPayload@Rva005CEAE6@@@Z
// partial score=0.9 date=2026-10-02
// cl: /Os /MD /Oy-
// ?Rva005CEC8FCreate@@YAPAVRva005CEC8F@@PAV1@PBUPayload@Rva005CEAE6@@@Z, retail 0x005CEC8F, 50 bytes.
// Free __cdecl creator: news 0x14-byte Rva005CEAE6 with +4 refcount and 12B
// payload from *src, stores to out+0 with AddRef inc, returns out.
// Evidence: packet disassembly, push 0x14 call ??2@YAPAXI@Z row,
// test je xor null path, push arg call 0x005CEAE6 row, store to [ecx] with
// inc [eax+4], leave ret (caller cleans 8B); twin of banked 0x005CE3F9 45/50.
class Rva005CEAE6
{
public:
	struct Payload { int v[3]; };
	Rva005CEAE6(const Payload *src) throw();
	virtual ~Rva005CEAE6();
	int m_ref; // +4
	Payload m_data; // +8
};

class Rva005CEC8F
{
public:
	Rva005CEAE6 *m_00;
};

Rva005CEC8F * __cdecl Rva005CEC8FCreate(Rva005CEC8F *out, const Rva005CEAE6::Payload *src)
{
	Rva005CEAE6 *p = new Rva005CEAE6(src);
	out->m_00 = p;
	if (p != 0)
		p->m_ref++;
	return out;
}
