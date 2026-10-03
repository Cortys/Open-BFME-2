// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.96 date=2026-10-04
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.95 date=2026-10-03
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?rva0059192A@NetPacket@@IAE_NPAVNetCommandRef@@@Z, retail 0x0059192A, 133 bytes.
// Packet-size fit check: packetLen + 2*textLen + len <= 0x1DC, where len is the
// per-field delta header (2 if the type differs, +2 relay, +5 timestamp, +2 player,
// +2 constant). Evidence: string temp via rowed rva004D6119 0x004E6119 plus the
// rowed wide releaseBuffer 0x00036E6D on the temporary; layout +0x1E0..+0x200 via
// the vtable-shifted m_pad0/m_pad1.
// The type byte and relay byte are read into named UnsignedByte locals so MSVC
// keeps the type in ebx (as retail does) and, with the total inlined into the
// return expression rather than held in a `total` local, frees a register so the
// prolog pushes only ebx and esi instead of a third saved register.
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
	UnsignedByte curType = m_lastType1FF;
	UnsignedByte curRelay = m_lastRelay200;
	Int len = 2;
	if (curType != cmdMsg->m_commandType) len += 2;
	if (curRelay != msg->getRelay()) len += 2;
	if (m_lastTimestamp1F8 != cmdMsg->m_timestamp) len += 5;
	if (m_lastPlayer1FE != cmdMsg->m_playerID) len += 2;
	Int textLen = (Int)((const Rva004D6119 *)(const void *)cmdMsg)->rva004D6119().getLenByte();
	Int total = m_packetLen + textLen * 2 + len;
	return (UnsignedInt)total <= (UnsignedInt)MAX_PACKET_SIZE;
}
