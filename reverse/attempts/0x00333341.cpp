// ?Rva00333341Fill@@YAPAVRva00332EC8@@PAV1@IABV1@@Z
// partial score=0.97 date=2026-09-30
// ?Rva00333341Fill@@YAPAVRva00332EC8@@PAV1@IABV1@@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
// ?Rva00333341Fill@@YAPAVRva00332EC8@@PAV1@IABV1@@Z @0x00333341 37B
// retail 0x00333341 37 bytes chain fill_n loop via rowed Construct 0x00333295 stride 0x24
// caller 0x00336234 unblocks 0x003361C6 neighbours prev 0x003332D6 fill_n and next 0x00333374 Get

class BfmeObject872Header
{
public:
	BfmeObject872Header(const BfmeObject872Header &that) throw();
private:
	char m_data[16];
};

class Rva00332EC8
{
public:
	Rva00332EC8(const Rva00332EC8 &that) throw();
private:
	unsigned int m_key;
	BfmeObject872Header m_a;
	BfmeObject872Header m_b;
};

void Rva00333295Construct(Rva00332EC8 *dest, const Rva00332EC8 &src) throw();

Rva00332EC8 *Rva00333341Fill(Rva00332EC8 *dest, unsigned count, const Rva00332EC8 &src)
{
	Rva00332EC8 *d = dest;
	while (count--)
		Rva00333295Construct(d++, src);
	return d;
}
