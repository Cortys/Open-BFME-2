// ??1Rva004D58DE@@UAE@XZ
// partial score=0.93 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHs-c-
// ??1Rva004D58DE@@UAE@XZ @0x004D5902 35B: dtor freeing array member +0x24 then restoring base vtable.
// Target evidence: mov eax [esi+0x24] test je; vtable 0x00860264 then delete[] 0x0002FD80 and [esi+0x24]=0 then vtable 0x00860130; caller 0x004D5B17 for its deleting dtor; donor ctor NetCommandMsgCtor.cpp.
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
	virtual ~NetCommandMsg() {}
protected:
	UnsignedInt m_timestamp; // +4
	UnsignedInt m_executionFrame; // +8
	UnsignedInt m_playerID; // +0xC
	UnsignedShort m_id; // +0x10
	NetCommandType m_commandType; // +0x14
	Int m_referenceCount; // +0x18
};
class Rva004D58DE : public NetCommandMsg
{
public:
	virtual ~Rva004D58DE();
private:
	unsigned int m_1c; // +0x1C
	unsigned short m_20; // +0x20
	char *m_24; // +0x24 array pointer
	unsigned int m_28; // +0x28
};
// ??1Rva004D58DE@@UAE@XZ present-unmatched
Rva004D58DE::~Rva004D58DE()
{
	if (m_24)
	{
		delete[] m_24;
		m_24 = 0;
	}
}
