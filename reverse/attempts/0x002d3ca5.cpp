// ??0Rva002D3CA5@@QAE@PAURva002D3CA5First@@PAURva002D3CA5Second@@ABVAsciiString@@@Z
// partial score=0.9 date=2026-09-30
// ??0Rva002D3CA5@@QAE@PAURva002D3CA5First@@PAURva002D3CA5Second@@ABVAsciiString@@@Z
// partial score=0.9 date=2026-09-30
// cl: /O1 /MD /EHsc /arch:SSE
// ??0Rva002D3CA5@@QAE@PAURva002D3CA5First@@PAURva002D3CA5Second@@ABVAsciiString@@@Z @ 0x002D3CA5 133B
// Ctor with vtable plus StringBase copy plus counter wrap plus backpointer.
// Evidence: EH prolog 0x777465 plus StringBase copy pin 0x000365F0 plus floats via SSE plus caller 0x002D504B plus Rva0052BEF0CopyCtor vtable recipe.
template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase() { m_data = 0; }
	StringBase(const StringBase<T> &other);
	void *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString();
};

extern const void *const g_00C02C1C[];

class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};

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

class Rva002D3CA5 : public EmptyBase
{
public:
	Rva002D3CA5(Rva002D3CA5First *first, Rva002D3CA5Second *second, const AsciiString &name);
private:
	const void *m_vtable;
	int m_04;
	Rva002D3CA5First *m_08;
	Rva002D3CA5Second *m_0c;
	AsciiString m_10;
	bool m_14;
	bool m_15;
	int m_18;
	float m_1c;
	float m_20;
};

Rva002D3CA5::Rva002D3CA5(Rva002D3CA5First *first, Rva002D3CA5Second *second, const AsciiString &name)
	: m_vtable(g_00C02C1C)
	, m_04(0)
	, m_08(first)
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
