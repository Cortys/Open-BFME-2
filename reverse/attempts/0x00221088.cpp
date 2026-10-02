// ??0Rva00221088@@QAE@XZ
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHs
// ??0Rva00221088@@QAE@XZ @0x00221088 71B
// Subsystem ctor: baseConstruct then own vtable then setName StrategicHUD.
// Evidence: retail EH_prolog baseConstruct row StringBase PBD row setName row
// caller 0x002210F5 vtable VA 0xbe6b5c string StrategicHUD.
#include "ascii_string.h"

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

class SubsystemInterface
{
public:
	void setName(AsciiString name);
};

extern const void *const g_00BE6B5C[];

struct EHTrap
{
	EHTrap() {}
	~EHTrap() { if (m_p) m_p = 0; }
	void *m_p;
};

class __declspec(novtable) Rva00221088
{
public:
	Rva00221088();
private:
	void *m_vptr;
	char m_pad04[4];
	EHTrap m_trap;
};

Rva00221088::Rva00221088()
{
	((BFME2NativeNetwork *)this)->baseConstruct();
	*(const void **)this = g_00BE6B5C;
	((SubsystemInterface *)this)->setName("StrategicHUD");
}
