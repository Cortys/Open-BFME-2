// ?rva005747B2@Rva00575125@@UAEPAXPAX@Z
// partial score=0.9 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva005747B2@Rva00575125@@UAEPAXPAX@Z retail 0x005747B2 26B
// Virtual slot 6 (0x18) of 0x0086E4C4 (class Rva00575125 ctor 0x00575125).
// Evidence: vtable slot 6; ecx+0x14 mgr forward to slot 0x30 with mgr arg for early path; ret 4 one arg returning arg; neighbours share /O1 /EHsc.
// Honest Rva name on proven vtable class.
class MgrTarget
{
public:
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
	virtual void s6();
	virtual void s7();
	virtual void s8();
	virtual void s9();
	virtual void s10();
	virtual void s11();
	virtual void slot12(void *arg);
};
class Rva005746AF
{
public:
	virtual ~Rva005746AF();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
private:
	int m_04;
	unsigned long m_08;
	int m_0C;
};
class Rva00575125Second
{
public:
	virtual ~Rva00575125Second();
};
class Rva00575125 : public Rva005746AF, public Rva00575125Second
{
public:
	virtual void *rva005747B2(void *arg);
private:
	void *m_14;
};
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

// ?rva005747B2@Rva00575125@@UAEPAXPAX@Z present-unmatched
void *Rva00575125::rva005747B2(void *arg)
{
	volatile int keep = 0;
	((MgrTarget *)m_14)->slot12(arg);
	return arg;
}
