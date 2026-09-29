// ?Rva005CDC18Create@@YAPAPAVRva005CDB8F@@PAPAV1@PBUPayload@1@@Z
// partial score=0.94 date=2026-09-29
// ?Rva005CDC18Create@@YAPAPAVRva005CDB8F@@PAPAV1@PBUPayload@1@@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /MD /GX- /Oy-
//
// ?Rva005CDC18Create@@YAPAPAVRva005CDB8F@@PAPAV1@PBUPayload@1@@Z retail 0x005CDC18 50B factory.
// Evidence: new(0x1C) via 0x0002FDA0; ctor 0x005CDB8F; store to *out; inc ref +4; caller 0x005CDCB2; ret.
class Rva005CDB8F
{
public:
	struct Payload { int v[5]; };
	Rva005CDB8F(const Payload *src);
	virtual ~Rva005CDB8F();
	int m_ref; // +4
	Payload m_data; // +8
};

Rva005CDB8F **Rva005CDC18Create(Rva005CDB8F **out, const Rva005CDB8F::Payload *src)
{
	volatile int _pad = 0;
	Rva005CDB8F *tmp = new Rva005CDB8F(src);
	*out = tmp;
	if (tmp)
		++tmp->m_ref;
	return out;
}
