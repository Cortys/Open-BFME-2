// ??0Rva0070A2C0@@QAE@PAVAptValue@@000000@Z
// partial score=0.85 date=2026-10-04
// cl: /O2 /DNDEBUG /MD /EHsc
#include <new.h>
// Retail body 0x0070A2C0, 71 bytes. An AptValue-derived constructor taking six
// stack arguments (ret 0x1C), calling the shared base constructor at 0x00709870
// and then installing the class vtable and five copied fields.
//
// Evidence (retail bytes):
//   mov eax,[esp+0x18]        sixth stack argument
//   push esi; push 0; mov esi,ecx ; esi = this, 0 is the base ctor's first slot
//   mov ecx,[esp+0x24]; push eax; push ecx; push 0x2d
//   mov ecx,esi; call 0x00709870   base ctor (type 0x2d, arg3, arg6)
//   mov eax,[esp+0xc]; mov edx,[esp+8]; mov ecx,[esp+0x18]
//   mov [esi+0x34],eax; mov [esi+0x30],edx; mov [esi+0x40],eax(from [esp+0x14])
//   mov dword ptr [esi],0x00CEEAE8   class vtable
//   mov [esi+0x38],ecx; mov [esi+0x3c],edx
//   mov eax,esi; pop esi; ret 0x1C
//
// The base constructor 0x00709870 is not recovered here; it is declared under
// an address-derived name and resolves through its symbols.csv pin. That body
// forwards to the rowed Rva006D6360 ctor at 0x006D6360, installs the base
// vtable 0x00CEE8C8, clears the +0x1C bits and stores its third argument at
// +0x20, which is why this constructor copies its own fields only from +0x30 up.
class AptValue
{
public:
	virtual void AddRef();
	virtual void Release();
};

class Rva00709870Base : public AptValue
{
protected:
	unsigned int m_flags;     // +0x04
	char m_pad30[0x30 - 0x08]; // AptNativeHash at +8 (0x14B), bits at +0x1C
	AptValue *m_p30;           // +0x30
	AptValue *m_p34;           // +0x34
	AptValue *m_p38;           // +0x38
	AptValue *m_p3c;           // +0x3C
	AptValue *m_p40;           // +0x40
public:
	void rva00709870(int type, AptValue *a2, AptValue *a3, AptValue *a4);
};

// 0x0070A2C0: base-ctor type 0x2d, class vtable 0x00CEEAE8.
// thiscall with SEVEN stack arguments; ret 0x1C. Retail pushes a literal 0 as
// the base constructor's fourth argument (see the header comment).
class Rva0070A2C0 : public Rva00709870Base
{
public:
	Rva0070A2C0(AptValue *a1, AptValue *a2, AptValue *a3, AptValue *a4,
		AptValue *a5, AptValue *a6, AptValue *a7);
};

// ??0Rva0070A2C0@@QAE@PAVAptValue@@00000@Z  0x0070A2C0 71B
Rva0070A2C0::Rva0070A2C0(AptValue *a1, AptValue *a2, AptValue *a3, AptValue *a4,
	AptValue *a5, AptValue *a6, AptValue *a7)
{
	rva00709870(0x2d, a3, a6, 0);
	m_p34 = a1;
	m_p30 = a2;
	m_p40 = a3;
	m_p38 = a4;
	m_p3c = a2;
	(void)a5;
	(void)a7;
}

// Referencing the constructor keeps cl from dropping it as an unreferenced
// COMDAT in this object-only unit.
Rva0070A2C0 *rva0070A2C0Anchor(Rva0070A2C0 *p, AptValue *a1, AptValue *a2,
	AptValue *a3, AptValue *a4, AptValue *a5, AptValue *a6, AptValue *a7)
{
	new (p) Rva0070A2C0(a1, a2, a3, a4, a5, a6, a7);
	return p;
}