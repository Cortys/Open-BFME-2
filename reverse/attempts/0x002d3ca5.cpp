// ??0Rva002D3CA5@@QAE@PAURva002D3CA5First@@PAURva002D3CA5Second@@ABVAsciiString@@@Z
// partial score=0.95 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /arch:SSE
// ??0Rva002D3CA5@@QAE@PAURva002D3CA5First@@PAURva002D3CA5Second@@ABVAsciiString@@@Z @ 0x002D3CA5 133B
// Ctor with vtable plus StringBase copy plus counter wrap plus backpointer.
// Evidence: EH prolog 0x777465 plus StringBase copy pin 0x000365F0 plus floats via SSE plus caller 0x002D504B plus Rva0052BEF0CopyCtor vtable recipe.
#include "ascii_string.h"

struct Rva002D3CA5First
{
	char m_pad[0x144];
	int m_144;
};

struct Rva002D3CA5Second
{
	char m_pad[8];
	void *m_08;
};

class EmptyBase
{
public:
	EmptyBase(Rva002D3CA5First *first) : m_04(0), m_first(first) {}
	~EmptyBase();
	int m_04;
	Rva002D3CA5First *m_first;
};

class Rva002D3CA5 : public EmptyBase
{
public:
	virtual ~Rva002D3CA5();
	Rva002D3CA5(Rva002D3CA5First *first, Rva002D3CA5Second *second, const AsciiString &name);
private:
	Rva002D3CA5Second *m_0c;
	AsciiString m_10;
	bool m_14;
	bool m_15;
	int m_18;
	float m_1c;
	float m_20;
};

// ??0Rva002D3CA5@@QAE@PAURva002D3CA5First@@PAURva002D3CA5Second@@ABVAsciiString@@@Z present-unmatched
Rva002D3CA5::Rva002D3CA5(Rva002D3CA5First *first, Rva002D3CA5Second *second, const AsciiString &name)
	: EmptyBase(first)
	, m_0c(second)
	, m_10(name)
	, m_14(false)
	, m_15(false)
{
	m_18 = first->m_144;
	++first->m_144;
	Rva002D3CA5Second *s = m_0c;
	m_1c = 0.0f;
	m_20 = 0.0f;
	s->m_08 = this;
	if (first->m_144 >= 0xffff)
	{
		first->m_144 = 0;
	}
}
