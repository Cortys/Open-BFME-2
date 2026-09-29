// ?rva0058F078@NetPacket@@QAE_NPAVNetCommandRef@@@Z
// partial score=0.96 date=2026-09-29
// ?rva0058F078@NetPacket@@QAE_NPAVNetCommandRef@@@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// ?rva0058F078@NetPacket@@QAE_NPAVNetCommandRef@@@Z, retail 0x0058F078, 594 bytes.
// NetPacket add-wrapper sibling of isRoomForMessage 0x0058D310: charges
// type/relay/timestamp/player/ID deltas (tags T/R/S/P/C) plus D plus wrapped
// ID word plus data length, bumps count, replaces last command.
// Evidence: identical NetPacket tail layout +0x1E0/+0x1EC/+0x1F0/+0x1F8/
// +0x1FC/+0x1FE/+0x1FF/+0x200 as init/isRoom siblings; callee isRoomFor
// 0x0058D310 rowed; wrapper getters 0x004D5767 and getDataLength rowed;
// caller 0x005945C9. Honest address method of NetPacket.
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned char UnsignedByte;
typedef bool Bool;

extern "C" void *__cdecl memcpy(void *dest, const void *src, unsigned int count);
void *__cdecl operator new(UnsignedInt size);
void __cdecl operator delete(void *p);

class NetCommandMsg
{
public:
	UnsignedInt getTimestamp() { return m_timestamp; }
	UnsignedInt getPlayerID() { return m_playerID; }
	UnsignedShort getID() { return m_id; }
	UnsignedInt getNetCommandType() { return m_commandType; }
	UnsignedByte m_pad0[4];
	UnsignedInt m_timestamp;
	UnsignedInt m_executionFrame;
	UnsignedInt m_playerID;
	UnsignedShort m_id;
	UnsignedShort m_pad12;
	UnsignedInt m_commandType;
	UnsignedInt m_refCount;
	UnsignedByte m_data1C[32];
};

class Rva004D5767WordField
{
public:
	UnsignedShort get() const;
};

class NetWrapperCommandMsg : public NetCommandMsg
{
public:
	UnsignedInt getDataLength();
};

class NetCommandNode
{
public:
	void detach();
};

class NetCommandRef : public NetCommandNode
{
public:
	NetCommandRef(NetCommandMsg *msg);
	NetCommandMsg *getCommand() { return m_msg; }
	UnsignedByte getRelay() const { return m_relay; }
	void setRelay(UnsignedByte relay) { m_relay = relay; }
	NetCommandMsg *m_msg;
	NetCommandRef *m_next;
	NetCommandRef *m_prev;
	UnsignedByte m_relay;
	UnsignedByte m_pad0D[3];
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
	Bool rva0058F078(NetCommandRef *msg);
	Bool rva0058D310(NetCommandRef *msg);
	virtual ~NetPacket();

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

// ?rva0058F078@NetPacket@@QAE_NPAVNetCommandRef@@@Z present-unmatched
Bool NetPacket::rva0058F078(NetCommandRef *msg)
{
	Bool needNewCommandID = false;
	if (rva0058D310(msg)) {
	NetCommandMsg *cmdMsg = msg->getCommand();
	if (m_lastCommandType != cmdMsg->getNetCommandType()) {
		m_packet[m_packetLen++] = 0x54;
		m_packet[m_packetLen++] = cmdMsg->getNetCommandType();
		m_lastCommandType = cmdMsg->getNetCommandType();
	}
	if (m_lastRelay != msg->getRelay()) {
		m_packet[m_packetLen++] = 0x52;
		UnsignedByte newRelay = msg->getRelay();
		memcpy(&m_packet[m_packetLen], &newRelay, 1);
		m_packetLen += 1;
		m_lastRelay = newRelay;
	}
	if (m_lastTimestamp != cmdMsg->getTimestamp()) {
		m_packet[m_packetLen++] = 0x53;
		UnsignedInt newTimestamp = cmdMsg->getTimestamp();
		memcpy(&m_packet[m_packetLen], &newTimestamp, 4);
		m_packetLen += 4;
		m_lastTimestamp = newTimestamp;
	}
	if (m_lastPlayerID != cmdMsg->getPlayerID()) {
		m_packet[m_packetLen++] = 0x50;
		m_packet[m_packetLen++] = cmdMsg->getPlayerID();
		m_lastPlayerID = cmdMsg->getPlayerID();
		needNewCommandID = true;
	}
	if (((m_lastCommandID + 1) != cmdMsg->getID()) || (needNewCommandID == true)) {
		m_packet[m_packetLen++] = 0x43;
		UnsignedShort newID = cmdMsg->getID();
		memcpy(&m_packet[m_packetLen], &newID, 2);
		m_packetLen += 2;
	}
	m_lastCommandID = cmdMsg->getID();
	m_packet[m_packetLen++] = 0x44;
	UnsignedInt wrappedID = ((Rva004D5767WordField*)cmdMsg)->get();
	memcpy(&m_packet[m_packetLen], &wrappedID, 2);
	m_packetLen += 2;
	UnsignedInt dataLength = ((NetWrapperCommandMsg*)cmdMsg)->getDataLength();
	memcpy(&m_packet[m_packetLen], &dataLength, 4);
	m_packetLen += 4;
	m_numCommands++;
	NetCommandRef *lastCmd = m_lastCommand;
	if (lastCmd != 0) {
		lastCmd->detach();
		delete lastCmd;
		m_lastCommand = 0;
	}
	m_lastCommand = new NetCommandRef(msg->getCommand());
	m_lastCommand->setRelay(msg->getRelay());
	return true;
	}
	return false;
}
