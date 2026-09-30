// ?rva00513040@Rva00513040@@QAEXHH@Z
// partial score=0.99 date=2026-09-30
// ?rva00513040@Rva00513040@@QAEXHH@Z
// partial score=0.99 date=2026-09-30
// cl: /O1 /EHsc /MD
//
// ?rva00513040@Rva00513040@@QAEXHH@Z @0x00513040 162B. __thiscall UI firer:
// formats two ints with "%d" into AsciiString locals, then invokes
// "SetBarPercent" with (owner +0x274, 2, str1, str2, 0, 0, 0) through the
// pinned Rva00222A8B target. Evidence: callers 0x004D45BA and 0x0051352B;
// rowed AsciiString::format 0x00038150, rowed empty string
// g_Rva0107301CEmptyString, rowed StringBase releaseBuffer 0x00036410,
// pinned invoke 0x00222A8B. Shape follows Rva003FED66MoveButtonFlash.cpp
// (same 8-arg invoke) and InGameUIDisplayCantBuild.cpp (inline AsciiString
// dtor calling the rowed releaseBuffer).
extern const char g_Rva0107301CEmptyString[];

template <typename T>
class StringBase
{
	friend class AsciiString;

private:
	struct Header
	{
		int m_refCount;
		unsigned short m_length;
		unsigned short m_capacity;
		T m_data[1];
	};

	void releaseBuffer();
	Header *m_data;

public:
	StringBase() : m_data(0) {}
};

class AsciiString
{
public:
	AsciiString() {}
	void format(const char *fmt, ...);
	~AsciiString() { m_data.releaseBuffer(); }
	const char *c_str_or_empty() const
	{
		StringBase<char>::Header *h = m_data.m_data;
		return h ? (const char *)h + 8 : g_Rva0107301CEmptyString;
	}

private:
	StringBase<char> m_data;
};

class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern Rva00222A8BTarget *TheRva00222A8BTarget;

class Rva00513040
{
public:
	void rva00513040(int v1, int v2);

private:
	char m_pad[0x274];
	void *m_owner;
};

// ?rva00513040@Rva00513040@@QAEXHH@Z present-unmatched
void Rva00513040::rva00513040(int v1, int v2)
{
	AsciiString s1;
	s1.format("%d", v1);
	AsciiString s2;
	s2.format("%d", v2);
	TheRva00222A8BTarget->invoke(m_owner, "SetBarPercent", 2, s1.c_str_or_empty(), (void *)s2.c_str_or_empty(), 0, 0, 0);
}
