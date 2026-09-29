// ?rva0058F7D8@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.88 date=2026-09-29
?rva0058F7D8@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.88 date=2026-09-29
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?rva0058F7D8@NetPacket@@IAE_NPAVNetCommandRef@@@Z @0x0058F7D8 (423B).
// NetPacket progress-message add: room check via rva0058D4BA then delta
// serializes type T relay R timestamp S playerID P plus always percentage
// D via rowed getPercentage 0x004C54EC with memcpy 0x006291A8 for relay
// and timestamp values. Rotates m_lastCommand via rowed detach 0x0058B8AE
// delete and new NetCommandRef 0x0058B88A. Same layout and flags as the
// isRoomFor siblings. Caller at 0x00594591.
#include <string.h>

typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned char UnsignedByte;
typedef bool Bool;
enum { MAX_PACKET_SIZE = 0x1DC };

class NetCommandMsg
{
public:
	virtual ~NetCommandMsg();
	Int getNetCommandType() { return m_commandType; }
	UnsignedInt getPlayerID() { return m_playerID; }
	void *m_vptr;
	UnsignedInt m_timestamp;
	UnsignedInt m_executionFrame;
	UnsignedInt m_playerID;
	UnsignedShort m_id;
	Int m_commandType;
	Int m_referenceCount;
};

class NetProgressCommandMsg : public NetCommandMsg
{
public:
	UnsignedByte getPercentage();
};

class NetCommandNode
{
public:
	void detach();
	NetCommandMsg *m_msg;
	NetCommandNode *m_next;
	NetCommandNode *m_prev;
};

class NetCommandRef
{
public:
	NetCommandRef(NetCommandMsg *msg);
	NetCommandMsg *getCommand() { return m_msg; }
	UnsignedByte getRelay() const { return m_relay; }
	NetCommandMsg *m_msg;
	NetCommandRef *m_next;
	NetCommandRef *m_prev;
	UnsignedByte m_relay;
	UnsignedInt m_timeLastSent;
};

class NetPacket
{
public:
	virtual ~NetPacket();
protected:
	UnsignedByte m_packet[0x1DC];
	Int m_packetLen;
	UnsignedInt m_destAddress;
	UnsignedShort m_destPort;
	UnsignedShort m_unknown1EA;
	Int m_numCommands;
	NetCommandRef *m_lastCommand;
	UnsignedInt m_unknown1F4;
	UnsignedInt m_lastCommandTimestamp;
	UnsignedShort m_lastCommandID;
	UnsignedByte m_lastPlayerID;
	UnsignedByte m_lastCommandType;
	UnsignedByte m_lastRelay;
	Bool rva0058D461(NetCommandRef *msg);
	Bool rva0058D4BA(NetCommandRef *msg);
	Bool rva0058F7D8(NetCommandRef *msg);
};

// ?rva0058F7D8@NetPacket@@IAE_NPAVNetCommandRef@@@Z present-unmatched
Bool NetPacket::rva0058F7D8(NetCommandRef *ref)
{
	if (!rva0058D4BA(ref)) {
		return false;
	}
	NetProgressCommandMsg *cmd = (NetProgressCommandMsg *)ref->getCommand();
	if (m_lastCommandType != cmd->m_commandType) {
		m_packet[m_packetLen] = 0x54;
		++m_packetLen;
		m_packet[m_packetLen] = (UnsignedByte)cmd->m_commandType;
		++m_packetLen;
		m_lastCommandType = (UnsignedByte)cmd->m_commandType;
	}
	if (m_lastRelay != ref->getRelay()) {
		m_packet[m_packetLen] = 0x52;
		++m_packetLen;
		UnsignedByte relay = ref->getRelay();
		memcpy(&m_packet[m_packetLen], &relay, sizeof(relay));
		++m_packetLen;
		m_lastRelay = relay;
	}
	if (m_lastCommandTimestamp != cmd->m_timestamp) {
		m_packet[m_packetLen] = 0x53;
		++m_packetLen;
		UnsignedInt timestamp = cmd->m_timestamp;
		memcpy(&m_packet[m_packetLen], &timestamp, sizeof(timestamp));
		m_packetLen += sizeof(timestamp);
		m_lastCommandTimestamp = timestamp;
	}
	if (m_lastPlayerID != cmd->getPlayerID()) {
		m_packet[m_packetLen] = 0x50;
		++m_packetLen;
		m_packet[m_packetLen] = (UnsignedByte)cmd->getPlayerID();
		++m_packetLen;
		m_lastPlayerID = (UnsignedByte)cmd->getPlayerID();
	}
	m_packet[m_packetLen] = 0x44;
	++m_packetLen;
	m_packet[m_packetLen] = cmd->getPercentage();
	++m_packetLen;
	++m_numCommands;
	NetCommandNode *old = (NetCommandNode *)m_lastCommand;
	if (old != 0) {
		old->detach();
		delete old;
		m_lastCommand = 0;
	}
	NetCommandRef *node = new NetCommandRef(ref->getCommand());
	m_lastCommand = node;
	node->m_relay = ref->getRelay();
	return true;
}
