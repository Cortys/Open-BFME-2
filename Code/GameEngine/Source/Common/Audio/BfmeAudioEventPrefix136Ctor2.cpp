// cl: /Ireference/shims/bfme2_ascii /ICode/GameEngine/Include /arch:SSE /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
//
// ??0BfmeAudioEventPrefix136@@QAE@ABUOpaqueRefElement4@@ABUBfmeEventPositionView@@H@Z, retail 0x002D982A 105B: ctor over
// OpaqueRefElement4 plus position view plus int. HEAD START from 13150e829 (verified body, header change unpublishable);
// re-homed here with TU-local class to avoid staging the shared header. Same vptr and initializer as 0x002D97D6;
// position to +0x3c and value to +0x30 with flag +0x48; callers at nine sites.
#include "ascii_string.h"

class OpaqueRefCounted
{
public:
	void Release_Ref();
};

typedef long Long;
extern "C" __declspec(dllimport) Long __stdcall InterlockedIncrement(Long volatile *addend);

struct BfmePoolHolder88
{
	unsigned char m_pad[0x88];
	OpaqueRefCounted m_ref;
};

class BfmePoolRef08
{
	OpaqueRefCounted *m_target;
public:
	__forceinline BfmePoolRef08() : m_target(0) {}
	__forceinline ~BfmePoolRef08() { if (m_target != 0) m_target->Release_Ref(); }
};

class BfmePoolRef10
{
	BfmePoolHolder88 *m_target;
public:
	__forceinline ~BfmePoolRef10() { if (m_target != 0) m_target->m_ref.Release_Ref(); }
	__forceinline BfmePoolRef10() : m_target(0) {}
};

struct OpaqueRefElement4 { OpaqueRefCounted *referent; OpaqueRefElement4 &operator=(const OpaqueRefElement4 &); };

struct BfmeEventPositionView {
	float x, y, z;
};

struct BfmeAudioEventPrefix136
{
	BfmeAudioEventPrefix136(const OpaqueRefElement4 &, const BfmeEventPositionView &, int);
	virtual ~BfmeAudioEventPrefix136();
	AsciiString m_string04;
	BfmePoolRef08 m_pool08;
	int m_int0C;
	BfmePoolRef10 m_pool10;
	int m_int14;
	int m_int18;
	AsciiString m_string1C;
	AsciiString m_string20;
	float m_f24;
	float m_f28;
	float m_f2C;
	int m_int30;
	int m_int34;
	int m_int38;
	BfmeEventPositionView m_position;
	unsigned char m_b48;
	unsigned char m_b49;
	unsigned char m_b4A;
	unsigned char m_b4B;
	unsigned char m_b4C;
	unsigned char m_b4D;
	unsigned char m_b4E;
	unsigned char m_b4F;
	unsigned char m_b50;
	unsigned char m_b51;
	unsigned char m_b52;
	unsigned char m_b53;
	float m_f54;
	float m_f58;
	float m_f5C;
	float m_f60;
	float m_f64;
	int m_int68;
	int m_int6C;
	int m_int70;
	int m_int74;
	int m_int78;
	int m_int7C;
	int m_int80;
	AsciiString m_string84;
	void rva002D96D3(const OpaqueRefElement4 &);
};

BfmeAudioEventPrefix136::BfmeAudioEventPrefix136(const OpaqueRefElement4 &arg, const BfmeEventPositionView &pos, int value30)
{
	rva002D96D3(arg);
	m_position = pos;
	m_int38 = 0;
	m_int30 = value30;
	m_b48 = 1;
}
