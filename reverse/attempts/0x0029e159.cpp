// ?rva0029E159@Rva0029E159@@QAEPAU1@ABUSource0029E159@@@Z
// partial score=0.96 date=2026-09-28
// cl: /O1 /Og /arch:SSE /MD /EHsc /DNDEBUG
// ?rva0029E159@Rva0029E159@@QAEXABUSource0029E159@@@Z @0x0029E159 150B
// Audio handle from source string plus two floats: empty check via 0x1E2F;
// AudioEventRTS temp via ctor 0x79514 plus AsciiString assign 0x366F0 plus
// floats and consts; manager at 0x009EC2D4 slot 8; dtor 0x793FA; caller 0x2A3ED8.
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
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	bool isEmpty() const;
private:
	BfmeStringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &that) : StringBase<char>(that) {}
	~AsciiString() {}
	AsciiString &operator=(const AsciiString &other);
};

class AudioEventRTS
{
public:
	AudioEventRTS();
	~AudioEventRTS();
	AsciiString m_first;
	AsciiString m_second;
	Int m_unknown8;
	float m_floatC;
	float m_float10;
	float m_float14;
	float m_float18;
	float m_float1C;
	float m_float20;
	unsigned char m_byte24;
	unsigned char m_byte25;
	unsigned char m_byte26;
};

struct Source0029E159
{
	AsciiString m_name;
	float m_x;
	float m_y;
};

class AudioManager0029E159
{
public:
	virtual ~AudioManager0029E159() {}
	virtual void s04() = 0;
	virtual int play(AudioEventRTS *ev) = 0;
};

#define TheAudio0029E159 (*(AudioManager0029E159 **)0x00DEC2D4)

struct Rva0029E159
{
	int m_handle;
	Rva0029E159 *rva0029E159(const Source0029E159 &src);
};

// ?rva0029E159@Rva0029E159@@QAEPAU1@ABUSource0029E159@@@Z present-unmatched
Rva0029E159 *Rva0029E159::rva0029E159(const Source0029E159 &src)
{
	m_handle = 0;
	if (src.m_name.isEmpty())
		return this;
	AudioEventRTS ev;
	*(AsciiString *)&ev = src.m_name;
	ev.m_floatC = src.m_x;
	AudioManager0029E159 *mgr = TheAudio0029E159;
	ev.m_float10 = src.m_y;
	ev.m_byte25 = 0;
	ev.m_byte26 = 1;
	ev.m_unknown8 = 0x20;
	ev.m_float14 = 0.0f;
	ev.m_float18 = 0.0f;
	m_handle = mgr->play(&ev);
	return this;
}
