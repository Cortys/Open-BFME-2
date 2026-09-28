// cl: /O1 /DNDEBUG /MD /EHsc
// ??0NetCommandMsg@@QAE@XZ, retail 0x004D5593, 37 bytes. Base message ctor:
// m_executionFrame=-1 (+8), m_timestamp=-1 (+4), m_id=0 (+0x10 word),
// m_playerID=0 (+0xC), m_commandType=UNKNOWN (-1, +0x14), vtable 0x860130,
// m_referenceCount=1 (+0x18). Donor is BFME1
// Code/GameEngine/Source/GameNetwork/NetCommandMsg_ctors.cpp
// (NetCommandMsg::NetCommandMsg, same field order; BFME2 starts timestamp at
// -1 rather than 0). Called by 33 derived ctors (0x004D55D6 NetGameCommandMsg
// shape, Ack family at 0x004D565D/0x004D568F, 30 become ready on landing).
// Vtable 0x860130 slot0 is the deleting dtor at 0x004CEEA6 rowed below.
// ??_GNetCommandMsg@@MAEPAXI@Z, retail 0x004CEEA6, 29 bytes. Deleting dtor:
// reinstalls vtable 0x860130 then frees via rowed ??3@YAXPAX@Z at 0x0002FD60.
// Abbuts the word getter at 0x004CEEA1 (prev ret) and the next body at
// 0x004CEEC3; same TU emits it byte-exact from the inline empty dtor.
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef int Int;

enum NetCommandType
{
	NETCOMMANDTYPE_UNKNOWN = -1,
	NETCOMMANDTYPE_KEEPALIVE = 12,
	NETCOMMANDTYPE_DISCONNECTKEEPALIVE = 0x19
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

// ??0NetCommandMsg@@QAE@XZ
NetCommandMsg::NetCommandMsg()
{
	m_executionFrame = (UnsignedInt)-1;
	m_timestamp = (UnsignedInt)-1;
	m_id = 0;
	m_playerID = 0;
	m_commandType = NETCOMMANDTYPE_UNKNOWN;
	m_referenceCount = 1;
}

// ??0NetKeepAliveCommandMsg@@QAE@XZ, retail 0x004D57C7, 21 bytes. Calls the
// base above then stamps KEEPALIVE (12, +0x14) and its vtable 0x860244. Donor
// is BFME1 NetCommandMsg_ctors.cpp (NetKeepAliveCommandMsg, no members).
class NetKeepAliveCommandMsg : public NetCommandMsg
{
public:
	NetKeepAliveCommandMsg();
};

// ??0NetKeepAliveCommandMsg@@QAE@XZ
NetKeepAliveCommandMsg::NetKeepAliveCommandMsg() : NetCommandMsg()
{
	m_commandType = NETCOMMANDTYPE_KEEPALIVE;
}

// ??0NetDisconnectKeepAliveCommandMsg@@QAE@XZ @0x004D57DC 21B: calls base plus stamps DISCONNECTKEEPALIVE (0x19) plus vtable 0x860244 shared via ICF.
// Donor BFME1 NetCommandMsg_ctors.cpp DisconnectKeepAlive (no members).
class NetDisconnectKeepAliveCommandMsg : public NetCommandMsg
{
public:
	NetDisconnectKeepAliveCommandMsg();
};

NetDisconnectKeepAliveCommandMsg::NetDisconnectKeepAliveCommandMsg() : NetCommandMsg()
{
	m_commandType = NETCOMMANDTYPE_DISCONNECTKEEPALIVE;
}

// ??0Rva004D5795@@QAE@XZ @0x004D5795 25B: calls base plus vtable 0x860224 plus byte 0 at +0x1c plus type 10 at +0x14.
// Vtable 0x860224 names unknown owner; honest-address ctor with 1-byte derived member.
class Rva004D5795 : public NetCommandMsg
{
public:
	Rva004D5795();
private:
	bool m_1c;
};

Rva004D5795::Rva004D5795() : NetCommandMsg()
{
	m_1c = 0;
	m_commandType = (NetCommandType)10;
}

// ??0Rva004D57AE@@QAE@XZ @0x004D57AE 25B: calls base plus dword 0 at +0x1c via And plus vtable 0x860234 plus type 11 at +0x14.
// Honest-address ctor with 4-byte derived member; And is /O1 size form of =0.
class Rva004D57AE : public NetCommandMsg
{
public:
	Rva004D57AE();
private:
	unsigned int m_1c;
};

Rva004D57AE::Rva004D57AE() : NetCommandMsg()
{
	m_1c = 0;
	m_commandType = (NetCommandType)11;
}
