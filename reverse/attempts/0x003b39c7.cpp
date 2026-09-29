// ??0Rva003B39C7@@QAE@XZ
// partial score=0.9 date=2026-09-29
// ??0Rva003B39C7@@QAE@XZ
// partial score=0.90 date=2026-09-29
// cl: /O1 /EHsc /MD
// ??0Rva003B39C7@@QAE@XZ @0x003B39C7 113B. Default ctor: int 1 at +0x00,
// StringBase D from "UNUSED/(placeholder)/placeholder" at +0x04, ints 0,
// array of 4x12B with UnicodeString at +0x18 via ??_L, zeros, rep stosd 12
// at +0x4C, returns this. Evidence: literal plus rowed StringBase ctor plus
// UnicodeString ctor plus ??_L plus rep; callers 0x00204615 etc.
template <typename T> class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	__forceinline ~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	T *m_data;
public:
	const T *str() const { return m_data ? m_data : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text);
	AsciiString(const AsciiString &other);
	~AsciiString();
};

class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString();
	~UnicodeString();
};

struct Elem12
{
	UnicodeString u;
	int a;
	int b;
};

class Rva003B39C7
{
public:
	Rva003B39C7();
private:
	int m00;
	AsciiString m04;
	int m08;
	int m0C;
	int m10;
	int m14;
	Elem12 m18[4];
	int m48;
	int m4C[12];
	int m7C;
};

// ??0Rva003B39C7@@QAE@XZ present-unmatched
Rva003B39C7::Rva003B39C7()
	: m00(1), m04("UNUSED/(placeholder)/placeholder"), m08(0), m0C(0), m10(0), m14(0), m48(0), m7C(0)
{
	for (int i = 0; i < 12; i++)
		m4C[i] = 0;
}
