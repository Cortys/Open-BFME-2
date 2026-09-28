// ?Rva00591062Get@@YAHPAURva00591062Host@@@Z
// partial score=0.93 date=2026-09-28
// ?Rva00591062Get@@YAHPAURva00591062Host@@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?Rva00591062Get@@YAHPAURva00591062Host@@@Z @0x00591062, 82B.
// Length sum of two AsciiString members at +0x1C/+0x20 via rowed
// CDDrive::getPath 0x002D9BA6 and Rva002D9BC1 getter 0x002D9BC1,
// plus 0x11. Lengths read inline from header length at +4 with
// null check; temps release via rowed releaseBuffer 0x00036410.
// Caller at 0x00592A1D proves free-function shape. Honest address
// name; host class unproven.
typedef int Int;

template <typename T>
class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	int getLength() const { return m_data ? m_data->length : 0; }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

class CDDrive
{
public:
	AsciiString getPath();
};

class Rva002D9BC1AsciiField
{
public:
	AsciiString get() const;
};

struct Rva00591062Host
{
	char m_pad[0x1C];
	AsciiString m_s1C; // +0x1C
	AsciiString m_s20; // +0x20
};

// ?Rva00591062Get@@YAHPAURva00591062Host@@@Z present-unmatched
int Rva00591062Get(Rva00591062Host *p)
{
	int l1 = ((CDDrive *)p)->getPath().getLength();
	int l2 = ((Rva002D9BC1AsciiField *)p)->get().getLength();
	return l1 + l2 + 0x11;
}
