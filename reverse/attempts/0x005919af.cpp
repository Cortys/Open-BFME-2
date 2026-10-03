// ?rva005919AF@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.93 date=2026-10-03
// ?rva005919AF@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.92 date=2026-10-03
// ?rva005919AF@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.92 date=2026-10-03 seat8
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?rva005919AF@NetPacket@@QAEEPAVNetCommandRef@@@Z @0x005919AF (182B).
// NetPacket room check with wide-string term: charges type 2 timestamp 5
// frame 5 relay 2 player 2 ID 3 plus fixed 2, adds UnicodeString length*2
// from the wide getter (rowed as Rva004D6119 0x004D6119) and fixed 4
// against MAX 0x1DC. Evidence: NetPacket tail +0x1E0/+0x1F4/+0x1F8/
// +0x1FC/+0x1FE/+0x1FF/+0x200 and NetCommandMsg +0x04/+0x08/+0x0C/+0x10/+0x14
// as siblings; callers 0x00593404; callees rowed.
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned char UnsignedByte;
typedef bool Bool;
enum { MAX_PACKET_SIZE = 0x1DC };

template <typename T> class StringBase
{
	friend class UnicodeString;
public:
	UnsignedByte getLength() const
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
		UnsignedByte length;
		UnsignedByte pad5;
		UnsignedShort capacity;
		T data[1];
	};
	Header *m_data;
};

class UnicodeString : public StringBase<unsigned short>
{
public:
	~UnicodeString() {}
};

class Rva004D6119
{
public:
	UnicodeString rva004D6119() const;
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
	UnsignedByte rva005919AF(NetCommandRef *msg);
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

// ?rva005919AF@NetPacket@@QAEEPAVNetCommandRef@@@Z present-unmatched
UnsignedByte NetPacket::rva005919AF(NetCommandRef *msg)
{
	Int len = 0;
	Bool needNewCommandID = false;
	NetCommandMsg *cmdMsg = msg->getCommand();
	if (m_lastCommandType != cmdMsg->m_commandType) {
		len += sizeof(UnsignedByte) + sizeof(UnsignedByte);
	}
	if (m_lastTimestamp != cmdMsg->m_timestamp) {
		len += sizeof(UnsignedInt) + sizeof(UnsignedByte);
	}
	if (m_lastFrame != cmdMsg->m_executionFrame) {
		len += sizeof(UnsignedInt) + sizeof(UnsignedByte);
	}
	if (m_lastRelay != msg->getRelay()) {
		len += sizeof(UnsignedByte) + sizeof(UnsignedByte);
	}
	if (m_lastPlayerID != cmdMsg->m_playerID) {
		len += sizeof(UnsignedByte) + sizeof(UnsignedByte);
		needNewCommandID = true;
	}
	if (((m_lastCommandID + 1) != cmdMsg->m_id) ||
		(needNewCommandID == true)) {
		len += sizeof(UnsignedByte) + sizeof(UnsignedShort);
	}
	len += sizeof(UnsignedByte) + sizeof(UnsignedByte);
	UnsignedByte strLen = ((Rva004D6119 *)cmdMsg)->rva004D6119().getLength();
	return m_packetLen + len + strLen * 2 + 4 <= MAX_PACKET_SIZE;
}
