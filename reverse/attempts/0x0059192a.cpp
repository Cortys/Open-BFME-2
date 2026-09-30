// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.92 date=2026-09-30
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z @0x0059192A (133B):
// NetPacket room check sibling of rva0058D211: charges type 2 relay 2
// timestamp 5 player 2 plus fixed 2 plus wide-text bytes (len*2) against
// base +0x1E0 and returns total<=0x1DC. Evidence: identical NetPacket tail
// layout +0x1F4/+0x1F8/+0x1FC/+0x1FE/+0x1FF/+0x200 and MAX 0x1DC as siblings;
// rowed wide-string getter @0x004D6119 plus rowed wide releaseBuffer @0x36E70.
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned short WideChar;
typedef unsigned char UnsignedByte;
typedef bool Bool;
enum { MAX_PACKET_SIZE = 0x1DC };

template <typename T>
class StringBase
{
public:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
public:
	struct Header
	{
		Int m_refCount;
		UnsignedShort m_length;
		UnsignedShort m_capacity;
		T m_data[1];
	};
	Header *m_data;
};

class UnicodeString : public StringBase<WideChar>
{
public:
	UnsignedByte getLenByte() const
	{
		const Header *h = m_data;
		if (h != 0) {
			return ((const UnsignedByte *)h)[4];
		}
		return 0;
	}
};

class Rva004D6119
{
public:
	UnicodeString rva004D6119() const;
private:
	char m_pad[0x1c];
	UnicodeString m_str1c;
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
	UnicodeString m_text1c;
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
	UnsignedByte m_pad0D[3];
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
	Bool rva0059192A(NetCommandRef *msg);
};

// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z present-unmatched
Bool NetPacket::rva0059192A(NetCommandRef *msg)
{
	NetCommandMsg *cmdMsg = msg->getCommand();
	Int len = 0;
	len = (m_lastCommandType != cmdMsg->m_commandType) ? 2 : len;
	if (m_lastRelay != msg->getRelay()) {
		len += 2;
	}
	if (m_lastCommandTimestamp != cmdMsg->m_timestamp) {
		len += 5;
	}
	if (m_lastPlayerID != cmdMsg->m_playerID) {
		len += 2;
	}
	len += 2;
	UnsignedByte textLen = ((const Rva004D6119 *)(const void *)cmdMsg)->rva004D6119().getLenByte();
	Int total = m_packetLen + (Int)textLen * 2 + len;
	return total <= (Int)MAX_PACKET_SIZE;
}
