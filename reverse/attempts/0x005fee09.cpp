// ?rva005FEE09@Rva005FEE09@@QAEHXZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /Ireference/shims/bfme2_ascii /Oy-
//
// ?rva005FEE09@Rva005FEE09@@QAEHXZ @0x005FEE09 131B
// Count helper over table at +0x170/+0x174 with flag at +0x11c. Evidence:
// calls rowed ?isEmpty@?$StringBase@D@@QBE_NXZ at 0x00001E2F and rowed
// ?rva002D06CA@Rva002D06CA@@QAEPAXPBVAsciiString@@@Z at 0x002D06CA via
// global g_009FF000; caller at 0x005FEEB9 passes object in edi.
#include "ascii_string.h"

class Rva002D06CA
{
public:
	void *rva002D06CA(const AsciiString *key);
};

extern Rva002D06CA *g_009FF000;

struct Rva005FEE09Mid
{
	char m_pad[0x28];
	void *m_holder;
};

struct Rva005FEE09Elem
{
	char m_pad1[0x20];
	Rva005FEE09Mid *m_mid;
	char m_pad2[0x34 - 0x20 - 4];
	unsigned char m_flag34;
};

struct Rva005FEE09Payload
{
	char m_pad[0x5c4];
	int m_kind;
};

class Rva005FEE09
{
public:
	int rva005FEE09();
private:
	char m_pad0[0x11c];
	unsigned char m_flag11c;
	char m_pad1[0x170 - 0x11c - 1];
	Rva005FEE09Elem **m_begin;
	Rva005FEE09Elem **m_end;
};

// ?rva005FEE09@Rva005FEE09@@QAEHXZ present-unmatched
int Rva005FEE09::rva005FEE09()
{
	int total = 0;
	int n = (int)(m_end - m_begin);
	for (int i = 0; i < n; ++i)
	{
		Rva005FEE09Elem *e = m_begin[i];
		Rva005FEE09Mid *mid = e->m_mid;
		if (mid == 0)
			continue;
		if (e->m_flag34 != 0)
			continue;
		AsciiString *s = (AsciiString *)((char *)mid->m_holder + 0xc);
		if (((const StringBase<char> *)s)->isEmpty())
			continue;
		void *res = g_009FF000->rva002D06CA(s);
		if (res == 0)
			continue;
		if (((Rva005FEE09Payload *)res)->m_kind != 6)
			continue;
		++total;
	}
	if (m_flag11c != 0)
		++total;
	return total;
}
