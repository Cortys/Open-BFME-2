// cl: /O1 /EHsc
// ??1Rva004F6986@@QAE@XZ, retail 0x004F6986, 61 bytes.
// Dtor of 8-byte holder with two inline member dtors each releasing TargetRef via rowed fastcall 0x0007DEEF with EH.
// Evidence: destroy-loop caller 0x004F8373 stride 8 plus 0x004F6E2B 0x004F9C50 plus jmp 0x004F73E5 and Unwind 0x00793281; prev copy ctor 0x004F6966 next dtor 0x004F69C3 both /O1.

struct TargetRef00217D4C
{
	virtual void *destroy(unsigned int flags);
	int references;
};

void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);

struct Rva004F6986Member
{
	~Rva004F6986Member()
	{
		if (m_ptr)
			ReleaseTreeHintRef00217D4C(m_ptr);
	}
	TargetRef00217D4C *m_ptr;
};

struct Rva004F6986
{
	~Rva004F6986();
	Rva004F6986Member m_00;
	Rva004F6986Member m_04;
};

Rva004F6986::~Rva004F6986()
{
}
