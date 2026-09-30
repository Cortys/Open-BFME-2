// ??0Rva002DAB18@@QAE@XZ
// partial score=0.97 date=2026-09-30
// ??0Rva002DAB18@@QAE@XZ
// partial score=0.97 date=2026-09-30
// cl: /O1 /EHsc /MD
//
// ??0Rva002DAB18@@QAE@XZ @0x002DAB18 (70B):
// Dual-vptr ctor: Snapshot base at +0 (vtable 0x00BBB554 via implicit ctor,
// gate patches), BFME2NativeNetwork member at +4 via rowed baseConstruct
// 0x001B4E63, then derived vtables 0x00C039A0 at +4 and 0x00C03910 at +0
// plus zero at +0x10. Empty base arms EH state 0 before the throwing call.
// Caller 0x00091A83. Evidence: unlock lane, all callees rowed.
class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};
class SnapBase
{
public:
	virtual void keep();
};
class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};
struct NetData
{
	void *m_vptr;
	unsigned char m_flag;
	unsigned char m_pad[3];
	int m_val;
};
extern const void *const g_00C03910[];
extern const void *const g_00C039A0[];
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class __declspec(novtable) Rva002DAB18 : public SnapBase, public EmptyBase
{
public:
	Rva002DAB18();
private:
	NetData m_net;
	int m_10;
};
Rva002DAB18::Rva002DAB18()
{
	((BFME2NativeNetwork *)((char *)this + 4))->baseConstruct();
	*(const void **)((char *)this + 4) = g_00C039A0;
	*(const void **)this = g_00C03910;
	_ReadWriteBarrier();
	m_10 = 0;
}
