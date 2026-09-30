// ??1Rva004A69BF@@UAE@XZ
// partial score=0.96 date=2026-09-30
// ??1Rva004A69BF@@UAE@XZ
// partial score=0.96 date=2026-09-30
// cl: /O1 /MD /EHsc
// ??1Rva004A69BF@@UAE@XZ @ 0x004A69BF 123B: dtor installing primary vtable
// 0x00852FB0 plus 4 secondary vptrs via Rva0026E836 base, extra store of
// 0x00852F38 at +0x3E4, deleting +0x3E8 via scalarDeletingDestructor(0) plus
// operator delete, base ??1Rva0026E836 via pin 0x0026E836. Evidence: vtable
// store plus rowed delete plus pin base plus caller 0x004A6E72 deleting dtor.
void __cdecl operator delete(void *ptr);

extern const void *const g_00C52F38[];

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva0026E836_Root
{
public:
	virtual ~Rva0026E836_Root();
private:
	char m_pad04[8];
};

class Rva0026E836_M1
{
public:
	virtual void f1();
};

class Rva0026E836_B2
{
public:
	virtual void f2();
private:
	char m_pad08[12];
};

class Rva0026E836_M3
{
public:
	virtual void f3();
};

class Rva0026E836_M4
{
public:
	virtual void f4();
};

class Rva0026E836 : public Rva0026E836_Root, public Rva0026E836_M1, public Rva0026E836_B2, public Rva0026E836_M3, public Rva0026E836_M4
{
public:
	virtual ~Rva0026E836();
};

class Rva004A69BFMember
{
public:
	virtual void *scalarDeletingDestructor(unsigned int flags);
};

class Rva004A69BF : public Rva0026E836
{
public:
	virtual ~Rva004A69BF();
private:
	char m_pad0028[0x3E4 - 0x28];
	const void *m_p03E4;
	Rva004A69BFMember *m_ptr03E8;
};

// ??1Rva004A69BF@@UAE@XZ present-unmatched
Rva004A69BF::~Rva004A69BF()
{
	m_p03E4 = g_00C52F38;
	_ReadWriteBarrier();
	::operator delete(m_ptr03E8 ? m_ptr03E8->scalarDeletingDestructor(0) : 0);
	m_ptr03E8 = 0;
}
