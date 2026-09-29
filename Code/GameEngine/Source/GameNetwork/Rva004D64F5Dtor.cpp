// cl: /O1 /DNDEBUG /MD /EHsc
// ??1Rva004D64F5@@UAE@XZ @0x004D65A6 54B
// Dtor: vptr 0x86050C then releaseBuffer at +0x1c then vptr 0x860130; caller 0x004D6AF4 for ??_G.
// Same recipe as Rva004D62A9 dtor at 0x004D62F7 (AsiiString at +0x1c, base NetCommandMsg, no base call).
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef int Int;
enum NetCommandType
{
	NETCOMMANDTYPE_UNKNOWN = -1
};
class NetCommandMsg
{
public:
	NetCommandMsg();
protected:
	virtual ~NetCommandMsg() {}
protected:
	UnsignedInt m_timestamp;
	UnsignedInt m_executionFrame;
	UnsignedInt m_playerID;
	UnsignedShort m_id;
	NetCommandType m_commandType;
	Int m_referenceCount;
};
class AsciiString
{
public:
	AsciiString() : m_data(0) {}
	~AsciiString();
private:
	void *m_data;
};
class Rva004D64F5 : public NetCommandMsg
{
public:
	virtual ~Rva004D64F5();
private:
	AsciiString m_str1c;
};

Rva004D64F5::~Rva004D64F5() {}
