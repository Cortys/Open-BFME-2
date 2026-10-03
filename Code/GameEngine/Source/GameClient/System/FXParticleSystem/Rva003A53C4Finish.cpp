// cl: /O1 /GX- /arch:SSE2 /DNDEBUG /MD /Ireference/shims/moduledata
// ??0WindModuleInfo@FXParticleSystem@@QAE@XZ @0x003A53C4 186B: WindModuleInfo
// default ctor. Vtable 0x00BE15A4; +0x04 int 1; the ten float slots and the
// +0x3C bool and the two trailing zero floats are all constants, read from
// .rdata globals rather than materialised.
//
// The recovered shape, and why it is this shape: retail is a strictly
// alternating load/store sequence -- every `movss xmm,[global]` is immediately
// followed by the `movss [eax+off],xmm` that consumes it, with no hoisting.
// Writing the ctor as an INIT LIST does not reproduce that: MSVC emits the
// members in DECLARATION order after folding the constants into globals, and
// it hoists the loads. Assigning in the BODY, in retail's order, does.
//
// Two ordering facts that the byte match pins and that declaration order would
// have hidden:
//   - +0x24 is stored AFTER +0x2C, and +0x30 after +0x38
//   - the global at 0xC1B2F8 is named twice, for +0x18 and +0x1C, and retail
//     reloads it rather than reusing the register
// Both are unrecoverable from declaration order alone.
//
// One `xorps xmm0,xmm0` supplies all four zeros (+0x14, +0x28, +0x40, +0x44);
// xmm0 carries the first three globals and xmm1 the rest. That split falls out
// of the assignment order rather than being requested.
#include "Common/Snapshot.h"

namespace FXParticleSystem {
class WindModuleInfo : public Snapshot
{
public:
    WindModuleInfo();
    virtual ~WindModuleInfo() {}
    virtual void v1() = 0;
    int m04; float m08; float m0C; float m10; float m14; float m18; float m1C; float m20;
    float m24; float m28; float m2C; float m30; float m34; float m38; bool m3C; float m40; float m44;
};
extern "C" const float kG1; const float kG1 = 2.0;
extern "C" const float kG2; const float kG2 = 75.0;
extern "C" const float kG3; const float kG3 = 200.0;
extern "C" const float kG4; const float kG4 = 0.15;
extern "C" const float kG5; const float kG5 = 0.45;
extern "C" const float kG6; const float kG6 = 0.78539818525314331;
extern "C" const float kG7; const float kG7 = 5.4977874755859375;
extern "C" const float kG8; const float kG8 = 5.4977874755859375;
extern "C" const float kG9; const float kG9 = 6.2831854820251465;
extern "C" const float kGA; const float kGA = 5.4977874755859375;

WindModuleInfo::WindModuleInfo()
{
	*(unsigned int *)this = 0x00BE15A4;
	m04 = 1;
	m08 = kG1;
	m0C = kG2;
	m10 = kG3;
	m14 = 0.0f;
	m18 = kG4;
	m1C = kG4;
	m20 = kG5;
	m28 = 0.0f;
	m2C = kG6;
	m24 = kG7;
	m34 = kG8;
	m38 = kG9;
	m30 = kGA;
	m3C = true;
	m40 = 0.0f;
	m44 = 0.0f;
}
}