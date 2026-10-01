// ??0Rva00985E4@@QAE@XZ
// partial score=0.96 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /DNDEBUG /arch:SSE
// ??0Rva00985E4@@QAE@XZ 0x0030AFC4 55B evidence: vtable 0x00BC8318 same as dtor 0x985E4; base ctor 0x1B4E63; caller 0x98667
#include "ascii_string.h"

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

class __declspec(novtable) BFME2NativeNetworkBase
{
public:
	__forceinline BFME2NativeNetworkBase() { ((BFME2NativeNetwork *)this)->baseConstruct(); }
	virtual ~BFME2NativeNetworkBase() { _ReadWriteBarrier(); }
private:
	char m_flag;
	int m_value;
};

class SubsystemInterface : public BFME2NativeNetworkBase
{
};

class Rva00985E4 : public SubsystemInterface
{
public:
	Rva00985E4();

private:
	AsciiString m_0C;
	AsciiString m_10;
	int m_pad14[7];
	volatile int m_30;
	volatile float m_34;
	volatile float m_38;
	volatile int m_3C;
	volatile float m_40;
	volatile float m_44;
};

// ??0Rva00985E4@@QAE@XZ present-unmatched
Rva00985E4::Rva00985E4()
	: m_30(0), m_34(0.0f), m_38(0.0f), m_3C(0), m_40(0.0f), m_44(0.0f)
{
}
