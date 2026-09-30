// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ?Rva005D2FD0Set@@YAXHPAURva005D2FD0Outer@@PBDABVUnicodeString@@@Z retail 0x005D2FD0 106B
// Evidence: format APT:_level%u.%s_%s via 0x00038150; bfmeSetText via pin 0x00225301; releaseBuffer 0x00036410; globals 0x009FE4CC 0x007BAC1C 0x008758A8; callers 0x005D3128 0x005D318D 0x005D31F2
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

#include "ascii_string.h"


class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString() {}
	~UnicodeString() {}
};

struct Rva005D2FD0Inner
{
	char m_pad8[8];
	char m_name[1];
};

struct Rva005D2FD0Outer
{
	Rva005D2FD0Inner *m_ptr;
};

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};

extern BfmeAptWindowManager *g_Va009FE4CC;
extern char g_Va007BAC1C;

void __cdecl Rva005D2FD0Set(int level, Rva005D2FD0Outer *outer, const char *suffix, const UnicodeString &text)
{
	AsciiString key;
	const char *mid = outer->m_ptr ? outer->m_ptr->m_name : &g_Va007BAC1C;
	key.format("APT:_level%u.%s_%s", level, mid, suffix);
	g_Va009FE4CC->bfmeSetText(key, text, true);
}

void __cdecl Rva005D366ASet(int level, Rva005D2FD0Outer *outer, const UnicodeString &text)
{
	AsciiString key;
	const char *mid = outer->m_ptr ? outer->m_ptr->m_name : &g_Va007BAC1C;
	key.format("APT:_level%u.%s_RegionName", level, mid);
	g_Va009FE4CC->bfmeSetText(key, text, false);
}

// ?rva005D3846@Rva005D3846@@QAEXABVUnicodeString@@@Z retail 0x005D3846 53B
// Evidence: chain from 0x005D366A; compare 0x00006A7A; set pin 0x00037150; caller jmp 0x00578611
class Rva005D3846
{
public:
	void rva005D3846(const UnicodeString &text);
private:
	int m_level;
	Rva005D2FD0Outer m_outer;
	char m_pad[0x18 - 8];
	UnicodeString m_cached;
};

void Rva005D3846::rva005D3846(const UnicodeString &text)
{
	if (((const StringBase<unsigned short> *)(const void *)&text)->compare(*(const StringBase<unsigned short> *)(const void *)&m_cached) != 0) {
		Rva005D366ASet(m_level, &m_outer, text);
		((StringBase<unsigned short> *)(void *)&m_cached)->set(*(const StringBase<unsigned short> *)(const void *)&text);
	}
}

// ??1Rva005D3731@@QAE@XZ @0x005D3731 69B
// Evidence: chain via rowed 0x005242D7 and releaseBuffers 0x00036E70 0x00036410;
// members +0x04 ansi +0x08 vector-wrapper +0x18 wide; callers 0x0057856D 0x005786F3 0x00578714
class Rva005242D7
{
public:
	~Rva005242D7();
private:
	char m_pad[12];
};

class Rva005D3731
{
public:
	~Rva005D3731();
private:
	int m_00;
	AsciiString m_04;
	Rva005242D7 m_08;
	int m_14;
	UnicodeString m_18;
};

Rva005D3731::~Rva005D3731()
{
}
