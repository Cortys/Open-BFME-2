// ?rva000A987D@Rva000A987D@@QAEXPBX@Z
// partial score=0.86 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?rva000A987D@Rva000A987D@@QAEXPBX@Z @0x000A987D 44B
// __thiscall 16B pair copy: 2 iterations of float+int via fld-fstp and mov-mov with dst-src offset in edi and dst+4 in esi; push 2 pop ecx loop.
// Evidence: frameless mov edx arg ret4; push ebx esi edi; mov eax ecx mov edi eax push 2 lea esi eax+4 sub edi edx pop ecx; loop fld [edx] fstp [edi+edx] mov ebx [edx+4] mov [esi] ebx add edx 8 add esi 8 dec ecx jne; caller at 0x000A9E16.
class Rva000A987D
{
public:
	void rva000A987D(const void *src);
private:
	float m_f0;
	int m_i0;
	float m_f1;
	int m_i1;
};
struct Rva000A987DPair
{
	float f;
	int i;
};

// ?rva000A987D@Rva000A987D@@QAEXPBX@Z present-unmatched
void Rva000A987D::rva000A987D(const void *src)
{
	Rva000A987DPair *d = (Rva000A987DPair *)this;
	const Rva000A987DPair *s = (const Rva000A987DPair *)src;
	int n = 2;
	do {
		d->f = s->f;
		d->i = s->i;
		++s;
		++d;
	} while (--n != 0);
}
