// cl: /O1 /MD
// stlport
//
// ?rva003EE900@Rva003EE900@@QAEXH@Z @0x003EE900 26B.
// Forwarder to map-dispatch notify0C at 0x004E35D5: passes static
// AsciiString at 0x00E02E7C (HomeRegionHighlight) with (arg+0x54, 0).
// Owner map-holder sits at this+8 (same layout as Rva004E35D5Notify).
// Chain of Rva004E35D5Notify (160B); retail pushes 0, arg+0x54, string.
#include <map>

typedef int Int;

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL
{
template <> struct less<AsciiString>
{
	bool operator()(const AsciiString &left, const AsciiString &right) const
	{
		return left < right;
	}
};
}

class Rva004E35D5
{
public:
	void rva004E35D5(const AsciiString &key, Int a, Int b);
private:
	_STL::map<AsciiString, AsciiString> m_map;
};

class Rva004E35AF
{
public:
	void rva004E35AF(const AsciiString &key, Int a);
private:
	_STL::map<AsciiString, AsciiString> m_map;
};

class Rva004E35FF
{
public:
	void rva004E35FF(const AsciiString &key, Int a, Int b);
private:
	_STL::map<AsciiString, AsciiString> m_map;
};

extern AsciiString g_Rva00E02E7C;
extern AsciiString g_Rva00E02E78;
extern AsciiString g_Rva00E02E80;
extern AsciiString g_Rva00E02E68;

class Rva003EE900
{
public:
	void rva003EE900(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EE884
{
public:
	void rva003EE884(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EE966
{
public:
	void rva003EE966(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EEA9D
{
public:
	void rva003EEA9D(Int arg);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

class Rva003EE84A
{
public:
	void rva003EE84A(Int a, Int b);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};

void Rva003EE900::rva003EE900(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E7C, (Int)((char *)arg + 0x54), 0);
}

void Rva003EE884::rva003EE884(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E78, (Int)((char *)arg + 0x54), 0);
}

void Rva003EE966::rva003EE966(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E80, (Int)((char *)arg + 0x54), 0);
}

void Rva003EEA9D::rva003EEA9D(Int arg)
{
	m_owner.rva004E35D5(g_Rva00E02E68, (Int)((char *)arg + 0x54), 0);
}

void Rva003EE84A::rva003EE84A(Int a, Int b)
{
	char *p = (char *)a + 0x54;
	m_owner.rva004E35D5(g_Rva00E02E78, (Int)p, 1);
	((Rva004E35FF *)&m_owner)->rva004E35FF(g_Rva00E02E78, (Int)p, b);
	((Rva004E35AF *)&m_owner)->rva004E35AF(g_Rva00E02E78, 0);
}

// ?rva003EEAB7@Rva003EEAB7@@QAEXXZ retail 0x003EEAB7 8B. Chain lane: tail-jmp
// thunk adjusting this by +8 into rowed Rva004E1F62::rva004E1F62 at
// 0x004E1F62; caller at 0x002123DC. Same m_pad[8]+owner layout as the
// Rva003EE900 family above; unblocks 0x002123BE/175.
struct Rva004E1F62 {
	void rva004E1F62();
};
class Rva003EEAB7
{
public:
	void rva003EEAB7();
private:
	char m_pad[8];
	Rva004E1F62 m_owner;
};
void Rva003EEAB7::rva003EEAB7()
{
	m_owner.rva004E1F62();
}

// ?rva003EE89E@Rva003EE89E@@QAEXHH@Z retail 0x003EE89E 58B. Unlock lane: same
// three-call forward as rva003EE84A above but with string g_Rva00E02E7C;
// callers at 0x003EE8F6/0x003EF120/0x0057DD5A; unblocks 3. Prev/next are the
// Rva003EE884/900 family in this TU.
class Rva003EE89E
{
public:
	void rva003EE89E(Int a, Int b);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};
void Rva003EE89E::rva003EE89E(Int a, Int b)
{
	char *p = (char *)a + 0x54;
	m_owner.rva004E35D5(g_Rva00E02E7C, (Int)p, 1);
	((Rva004E35FF *)&m_owner)->rva004E35FF(g_Rva00E02E7C, (Int)p, b);
	((Rva004E35AF *)&m_owner)->rva004E35AF(g_Rva00E02E7C, 0);
}

// ?rva003EEA63@Rva003EEA63@@QAEXHH@Z retail 0x003EEA63 58B. Unlock lane: same
// three-call forward as rva003EE84A/89E above but with string g_Rva00E02E68;
// callers at 0x003EEBE2/0x003EEF7F; unblocks 0x003EEBC4/0x003EEF38. Prev/next
// are the Rva003EE966/A9D family in this TU.
class Rva003EEA63
{
public:
	void rva003EEA63(Int a, Int b);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
};
void Rva003EEA63::rva003EEA63(Int a, Int b)
{
	char *p = (char *)a + 0x54;
	m_owner.rva004E35D5(g_Rva00E02E68, (Int)p, 1);
	((Rva004E35FF *)&m_owner)->rva004E35FF(g_Rva00E02E68, (Int)p, b);
	((Rva004E35AF *)&m_owner)->rva004E35AF(g_Rva00E02E68, 0);
}

// ?rva003EEBC4@Rva003EEBC4@@QAEXHH@Z retail 0x003EEBC4 43B. Chain lane: calls
// rowed 0x004E3629 with string g_Rva00E02E68 then this session's 0x003EEA63,
// stores first arg at this+0x14; callers at 0x003EEE85/0x003EEF2E.
class Rva004E3629
{
public:
	void rva004E3629(const AsciiString &key, Int a);
private:
	_STL::map<AsciiString, AsciiString> m_map;
};
class Rva003EEBC4
{
public:
	void rva003EEBC4(Int a, Int b);
private:
	char m_pad[8];
	Rva004E35D5 m_owner;
	Int m_saved;
};
void Rva003EEBC4::rva003EEBC4(Int a, Int b)
{
	((Rva004E3629 *)&m_owner)->rva004E3629(g_Rva00E02E68, 1);
	((Rva003EEA63 *)this)->rva003EEA63(a, b);
	m_saved = a;
}
