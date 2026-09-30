// ??0Rva0010ED4C@@QAE@HABVAsciiString@@@Z
// partial score=0.95 date=2026-09-30
// ??0Rva0010ED4C@@QAE@HABVAsciiString@@@Z
// partial score=0.95 date=2026-09-30
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ??0Rva0010ED4C@@QAE@HABVAsciiString@@@Z at 0x0010ED4C (118B).
// Ctor with AsciiString at +0 via pinned StringBase copy 0x365F0, int at +4,
// 0x24-byte memset at +8, zeros at +0x2C/+0x30/+0x34/+0x38/+0x3C and byte at +0x40,
// plus two Rva0040F9D events at +0x44/+0x4C as (1 0 0 0). Evidence: retail push
// [ebp+0xC] + call 0x365F0, mov [esi+4] from [ebp+8], EH 0/1 around 0x40F64 x2,
// memset via E8 to 0x6291AE. Callers at 0x000A8028 0x000A85E9.
#include "ascii_string.h"

class Rva0040F9D
{
public:
	virtual ~Rva0040F9D();
	Rva0040F9D(int a1, int a2, char const *a3, void *a4);
private:
	void *m_handle;
};

extern "C" void *memset(void *dst, int val, unsigned size);

class Rva0010ED4C
{
public:
	Rva0010ED4C(int a1, const AsciiString &a2);
private:
	AsciiString m_00;
	int m_04;
	char m_08[0x24];
	int m_2C;
	int m_30;
	int m_34;
	int m_38;
	int m_3C;
	unsigned char m_40;
	Rva0040F9D m_44;
	Rva0040F9D m_4C;
};

// ??0Rva0010ED4C@@QAE@HABVAsciiString@@@Z present-unmatched
Rva0010ED4C::Rva0010ED4C(int a1, const AsciiString &a2)
	: m_00(a2)
	, m_04(a1)
	, m_2C(0)
	, m_30(0)
	, m_34(0)
	, m_38(0)
	, m_3C(0)
	, m_40(0)
	, m_44(1, 0, 0, 0)
	, m_4C(1, 0, 0, 0)
{
	memset(m_08, 0, 0x24);
}
