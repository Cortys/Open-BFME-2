// ?rva004D5C2B@Rva004CEEC3@@QAE?AVAsciiString@@XZ
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva004D5C2B@Rva004CEEC3@@QAE?AVAsciiString@@XZ, retail 0x004D5C2B, 147 bytes.
// Rva004CEEC3 (type 3, +0x1c/+0x20/+0x24) contents: base
// NetCommandMsg::rva004D5B4C plus ", logicFrame=%d, clientFrame=%d, totalCommands=%d".
// Identity from vtable slot 3 of 0x00860140, ctor 0x004CEEC3 init +0x1c=0 +0x20=0 +0x24=-1,
// format 0x008602FC, callee base 0x004D5B4C, format 0x00038150,
// and empty fallback g_Rva0107301CEmptyString.
#include "ascii_string.h"

typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef int Int;

enum NetCommandType
{
	NETCOMMANDTYPE_UNKNOWN = -1
};

class MemoryPool;

extern const char g_Rva0107301CEmptyString[];

__forceinline const char *GetStr004D5C2B(const AsciiString &s)
{
	char *t = *(char * *)(void *)&s;
	return t ? t + 8 : g_Rva0107301CEmptyString;
}

class NetCommandMsg
{
public:
	AsciiString rva004D5B4C();
protected:
	virtual ~NetCommandMsg();
private:
	virtual MemoryPool *getObjectMemoryPool();
public:
	virtual Int getSortNumber();
	virtual AsciiString getContentsAsAsciiString();
protected:
	UnsignedInt m_timestamp;
	UnsignedInt m_executionFrame;
	UnsignedInt m_playerID;
	UnsignedShort m_id;
	NetCommandType m_commandType;
	Int m_referenceCount;
};

class Rva004CEEC3 : public NetCommandMsg
{
public:
	AsciiString rva004D5C2B();
private:
	Int m_1c;
	Int m_20;
	Int m_24;
};

AsciiString Rva004CEEC3::rva004D5C2B()
{
	AsciiString result;
	{
		AsciiString tmp = ((NetCommandMsg *)this)->rva004D5B4C();
		Int totalCommands = m_24;
		Int clientFrame = m_20;
		Int logicFrame = m_1c;
		result.format("%s, logicFrame=%d, clientFrame=%d, totalCommands=%d", GetStr004D5C2B(tmp), logicFrame, clientFrame, totalCommands);
	}
	return result;
}
