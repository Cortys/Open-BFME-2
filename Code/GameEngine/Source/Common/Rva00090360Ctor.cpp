// cl: /O1 /MD
// ??0Rva00090360@@QAE@XZ 33B @0x00090360: ctor calling rowed base 0x00262002 then storing vtable 0x007C7E20 then zeroing +0x14 (10 dwords) and +0x3C. Size 0x40 per caller alloc at 0x0004C55E. Evidence: rowed base callee plus vtable plus caller.
class Rva0026201C
{
public:
	Rva0026201C();
	virtual ~Rva0026201C();
private:
	char m_pad04[16];
};

class Rva00090360 : public Rva0026201C
{
public:
	Rva00090360();
	virtual ~Rva00090360();
private:
	int m_14[10];
	int m_3C;
};

Rva00090360::Rva00090360()
{
	for (int i = 0; i < 10; ++i)
		m_14[i] = 0;
	m_3C = 0;
}
