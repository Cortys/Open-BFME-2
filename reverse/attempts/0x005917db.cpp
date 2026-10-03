// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.99 date=2026-10-03
// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.99 date=2026-10-03
// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.99 date=2026-10-03
// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.99 date=2026-10-01
// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.99 date=2026-10-01
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z @0x005917DB (177B).
// NetPacket room check with string-length term plus wrapper data offset:
// charges type 2 relay 2 timestamp 5 player 2 ID 3 plus fixed 1, adds
// AsciiString length from the +0x1C getter (rowed as CDDrive::getPath
// 0x002D9BA6 via identical bytes) and NetWrapperCommandMsg::getDataOffset
// 0x00091A56 plus fixed 5 against MAX 0x1DC. Evidence: NetPacket tail
// +0x1E0/+0x1F8/+0x1FC/+0x1FE/+0x1FF/+0x200 and NetCommandMsg
// +0x04/+0x0C/+0x10/+0x14 as siblings 0x0059188C/0x00591D0D; callees rowed.
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned char UnsignedByte;
typedef bool Bool;
enum { MAX_PACKET_SIZE = 0x1DC };

template <typename T> class StringBase
{
	friend class AsciiString;
public:
	int getLength() const
	{
		return m_data ? m_data->length : 0;
	}
private:
	~StringBase()
	{
		releaseBuffer();
	}
	void releaseBuffer();
	struct Header {
		Int ref_count;
		UnsignedShort length;
		UnsignedShort capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	~AsciiString() {}
};

class CDDrive
{
public:
	virtual AsciiString getPath();
};

class NetCommandMsg
{
public:
	void *m_vptr;
	UnsignedInt m_timestamp;
	UnsignedInt m_executionFrame;
	UnsignedInt m_playerID;
	UnsignedShort m_id;
	UnsignedShort m_pad12;
	UnsignedInt m_commandType;
	UnsignedInt m_referenceCount;
};

class NetWrapperCommandMsg : public NetCommandMsg
{
public:
	UnsignedInt getDataOffset();
};

class NetCommandRef
{
public:
	NetCommandMsg *getCommand() { return m_msg; }
	UnsignedByte getRelay() const { return m_relay; }
	NetCommandMsg *m_msg;
	NetCommandRef *m_next;
	NetCommandRef *m_prev;
	UnsignedByte m_relay;
	UnsignedInt m_timeLastSent;
};

struct NetPacketAddress
{
	NetPacketAddress() { ip = 0; port = 0; }

	UnsignedInt ip;
	UnsignedShort port;
};

class NetPacket
{
public:
	virtual ~NetPacket();
	UnsignedByte rva005917DB(NetCommandRef *msg);
	UnsignedByte m_packet[0x1DC];
	Int m_packetLen;
	NetPacketAddress m_dest;
	Int m_numCommands;
	NetCommandRef *m_lastCommand;
	UnsignedInt m_lastFrame;
	UnsignedInt m_lastTimestamp;
	UnsignedShort m_lastCommandID;
	UnsignedByte m_lastPlayerID;
	UnsignedByte m_lastCommandType;
	UnsignedByte m_lastRelay;
};

// ?rva005917DB@NetPacket@@QAEEPAVNetCommandRef@@@Z present-unmatched
UnsignedByte NetPacket::rva005917DB(NetCommandRef *msg)
{
	Int len = 0;
	Bool needNewCommandID = false;
	NetWrapperCommandMsg *cmdMsg = (NetWrapperCommandMsg *)(msg->getCommand());
	if (m_lastCommandType != cmdMsg->m_commandType) {
		len += sizeof(UnsignedByte) + sizeof(UnsignedByte);
	}
	if (m_lastRelay != msg->getRelay()) {
		++len;
		++len;
	}
	if (m_lastTimestamp != cmdMsg->m_timestamp) {
		len += sizeof(UnsignedInt) + sizeof(UnsignedByte);
	}
	if (m_lastPlayerID != cmdMsg->m_playerID) {
		++len;
		++len;
		needNewCommandID = true;
	}
	if (((m_lastCommandID + 1) != cmdMsg->m_id) ||
		(needNewCommandID == true)) {
		len += sizeof(UnsignedByte) + sizeof(UnsignedShort);
	}
	++len;
	Int strLen = ((CDDrive *)cmdMsg)->CDDrive::getPath().getLength();
	Int dataOff = (Int)cmdMsg->getDataOffset();
	Int tmp = (Int)((UnsignedInt)strLen + (UnsignedInt)dataOff);
	Int extra = tmp + len + 5;
	return extra + m_packetLen <= MAX_PACKET_SIZE;
}
