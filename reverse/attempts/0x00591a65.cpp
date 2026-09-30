// ?rva00591A65@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.97 date=2026-09-30
// ?rva00591A65@NetPacket@@QAEEPAVNetCommandRef@@@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?rva00591A65@NetPacket@@QAEEPAVNetCommandRef@@@Z @0x00591A65 (182B).
// NetPacket room check with Unicode-string term: charges type 2 timestamp 5
// frame 5 relay 2 player 2 ID 3 plus fixed 2, adds wide length from the
// +0x24 RVO getter (rowed Rva0023E928 0x0023E928) as base + slen*2+8 against
// MAX 0x1DC. Evidence: NetPacket tail +0x1E0/+0x1F4/+0x1F8/+0x1FC/+0x1FE/
// +0x1FF/+0x200 and NetCommandMsg +0x04/+0x08/+0x0C/+0x10/+0x14 as siblings
// NetPacket_rva0059188C/NetPacket_rva00591D0D; caller 0x005936F4; callees rowed.
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned char UnsignedByte;
typedef bool Bool;
enum { MAX_PACKET_SIZE = 0x1DC };

template <typename T> class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
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

class UnicodeString : public StringBase<unsigned short>
{
public:
	~UnicodeString() {}
};

class Rva0023E928
{
public:
	UnicodeString rva0023E928() const;
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
	UnsignedByte rva00591A65(NetCommandRef *msg);
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

// ?rva00591A65@NetPacket@@QAEEPAVNetCommandRef@@@Z present-unmatched
UnsignedByte NetPacket::rva00591A65(NetCommandRef *msg)
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
		++len;
		++len;
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
	++len;
	UnsignedByte slen = ((Rva0023E928 *)cmdMsg)->rva0023E928().getLength() & 0xFF;
	Int total = m_packetLen + slen * 2 + 8 + len;
	return total <= MAX_PACKET_SIZE;
}
