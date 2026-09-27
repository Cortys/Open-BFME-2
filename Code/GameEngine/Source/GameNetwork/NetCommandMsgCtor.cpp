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
