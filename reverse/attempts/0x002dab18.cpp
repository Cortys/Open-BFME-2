// ??0Rva002DAB18@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??0Rva002DAB18@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /EHsc /MD
// ??0Rva002DAB18@@QAE@XZ @0x002DAB18 70B evidence: vtable 0x007BB554 at +0 then member +4 baseConstruct 0x001B4E63 then vtables 0x008039A0/0x00803910 and zero +0x10; caller 0x00091A83.
// Honest-address ctor (naming rule).
extern const void *const g_00BBB554[];
extern const void *const g_00C039A0[];
extern const void *const g_00C03910[];

class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
private:
	const void *m_vt;
	char _flag;
	char _pad[3];
	int _value;
};

class Rva002DAB18 : public EmptyBase
{
public:
	Rva002DAB18();
private:
	const void *m_vt;
	BFME2NativeNetwork m_net;
	int m_10;
};

// ??0Rva002DAB18@@QAE@XZ present-unmatched
Rva002DAB18::Rva002DAB18()
{
	*(const void **)this = g_00BBB554;
	m_net.baseConstruct();
	*(const void **)&m_net = g_00C039A0;
	*(const void **)this = g_00C03910;
	m_10 = 0;
}
