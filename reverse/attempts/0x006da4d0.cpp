// ??0BfmeAptValue006DCD20@@QAE@HPAPAV0@@Z
// partial score=0.97 date=2026-10-03
// cl: /O2 /MD
// Banked near miss: ??0BfmeAptValue006DCD20@@QAE@HPAPAV0@@Z @0x006DA4D0 (138B).
// All bytes, relocation targets, the SEH frame, base-ctor call, member stores,
// resize and set loop match; only `m_bits` is emitted differently: retail uses
// a memory RMW (`mov byte [esi+1Ch], bl; and dword [esi+1Ch], 0FFFFFCFFh`)
// while VC7.1 /O2 loads into a register and defers the store
// (`mov byte [esi+1Ch],bl; mov edx,[esi+1Ch]; and edx,imm; ... mov [esi+1Ch],edx`),
// which also removes the 16-byte loop-align nop. Tried: plain unsigned int
// compound assign, nested bitfield struct (plain and volatile), volatile field,
// volatile-qualified and cast, removing the derived virtuals. The identical
// pattern matches at 0x006D6410 (Rva006D6360Ctor.cpp), so this is a local
// register-allocation difference.
extern "C" void *__cdecl memmove(void *, const void *, unsigned int);

class BfmeAptValue006DCD20;

class Rva006D6360
{
public:
	Rva006D6360(int type, int size);
	virtual ~Rva006D6360();

	char m_pad[0x18];
};

class BfmeAptValue006DCD20 : public Rva006D6360
{
public:
	virtual void slot0();
	virtual void slot1();

	int isArray() const;
	BfmeAptValue006DCD20 *rva006DCFA0();
	void rva006D9500(int nCapacity);
	void rva006D8AD0(int nIndex, BfmeAptValue006DCD20 *pNewValue);
	void rva006D95E0(int nIndex, BfmeAptValue006DCD20 *pValue);

	BfmeAptValue006DCD20(int count, BfmeAptValue006DCD20 **pValues);

	unsigned int m_bits; // +0x1C
	BfmeAptValue006DCD20 **m_data; // +0x20
	int mnCapacity; // +0x24
	int mnLength; // +0x28
};

BfmeAptValue006DCD20::BfmeAptValue006DCD20(int count, BfmeAptValue006DCD20 **pValues)
	: Rva006D6360(0x16, count)
{
	*(unsigned char *)&m_bits = 0;
	m_bits &= 0xFFFFFCFF;
	mnCapacity = 0;
	m_data = 0;
	mnLength = count;
	rva006D9500(count);

	for (int i = 0; i < mnLength; ++i)
		rva006D8AD0(i, pValues[i]);
}
