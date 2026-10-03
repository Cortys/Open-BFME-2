// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.94 date=2026-10-03
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef unsigned short WideChar;
typedef unsigned char UnsignedByte;
typedef bool Bool;
enum { MAX_PACKET_SIZE = 0x1DC };

template <typename T> class StringBase
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
	Bool rva0059192A(NetCommandRef *msg);
private:
	UnsignedByte m_pad0[0x1E0 - 4];
	Int m_packetLen;
	UnsignedByte m_pad1[0x1F4 - 0x1E4];
	UnsignedInt m_lastFrame1F4;
	UnsignedInt m_lastTimestamp1F8;
	UnsignedShort m_lastID1FC;
	UnsignedByte m_lastPlayer1FE;
	UnsignedByte m_lastType1FF;
	UnsignedByte m_lastRelay200;
};
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z present-unmatched
Bool NetPacket::rva0059192A(NetCommandRef *msg)
{
	NetCommandMsg *cmdMsg = msg->getCommand();
	Int len;
	len = (m_lastType1FF != cmdMsg->m_commandType) ? 2 : 0;
	if (m_lastRelay200 != msg->getRelay()) {
		len += 2;
	}
	if (m_lastTimestamp1F8 != cmdMsg->m_timestamp) {
		len += 5;
	}
	if (m_lastPlayer1FE != cmdMsg->m_playerID) {
		len += 2;
	}
	len += 2;
	UnsignedByte textLen = ((const Rva004D6119 *)(const void *)cmdMsg)->rva004D6119().getLenByte();
	Int total = m_packetLen + (Int)textLen * 2 + len;
	return total <= MAX_PACKET_SIZE;
}
