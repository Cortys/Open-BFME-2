// ??0Rva0008A234@@QAE@ABV?$StringBase@D@@PBUThreeInts@@MMMMMM@Z
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /MD /arch:SSE
// ??0Rva0008A234@@QAE@ABV?$StringBase@D@@PBUThreeInts@@MMMMMM@Z @0x0008A234 111B
// Init zeroes +0, copy-constructs StringBase at +4 via pinned public
// StringBase copy-ctor 0x000365F0, copies three ints from info to +8/+C/+10,
// six floats in retail order to +14/+18/+1C/+20/+24/+28, zeroes byte +2C.
// Evidence: unlock lane, callers at 0x0008A5FA/0x000AFD23/0x005B11C2.
// Owning class unproven. Started from reverse/attempts/0x0008a234.cpp
// (score 0.9, float load-store phase shift plus t2-store position).
#include "ascii_string.h"

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct ThreeInts
{
	int v00;
	int v04;
	int v08;
};

class Rva0008A234
{
public:
	Rva0008A234(const StringBase<char> &str, const ThreeInts *info,
		float f10, float f14, float f18, float f1c, float f20, float f24);

private:
	int m_00;
	AsciiString m_04;
	int m_08;
	int m_0C;
	int m_10;
	float m_14;
	float m_18;
	float m_1C;
	float m_20;
	float m_24;
	float m_28;
	unsigned char m_2C;
};

// ??0Rva0008A234@@QAE@ABV?$StringBase@D@@PBUThreeInts@@MMMMMM@Z present-unmatched
Rva0008A234::Rva0008A234(const StringBase<char> &str, const ThreeInts *info,
	float f10, float f14, float f18, float f1c, float f20, float f24)
	: m_00(0), m_04(*(const AsciiString *)&str)
{
	float t10 = f10;
	m_08 = info->v00;
	m_0C = info->v04;
	m_10 = info->v08;
	_ReadWriteBarrier();
	m_14 = t10;
	m_18 = f14;
	m_1C = f18;
	m_20 = f24;
	m_24 = f1c;
	m_28 = f20;
	m_2C = 0;
}
