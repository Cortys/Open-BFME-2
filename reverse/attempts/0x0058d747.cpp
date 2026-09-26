// ?isAckBothRepeat@NetPacket@@IAE_NPAVNetCommandRef@@@Z
// partial score=0.7 date=2026-09-26
// cl: /DNDEBUG /MD /EHsc
// BFME1 donor: reference/open-bfme-1/Code/GameEngine/Source/GameNetwork/NetPacket.cpp.
// Target identity evidence: 0x58D747 calls the disp8 word/byte getters also
// used for command ID and original-player fields, compares current and previous
// command records, then compares NetCommandRef relay bytes. The target's
// +0x20/+0x24 dword comparisons are byte evidence; their field meanings remain
// unresolved.
typedef unsigned short UnsignedShort;
typedef unsigned char UnsignedByte;
typedef unsigned int UnsignedInt;
typedef bool Bool;

class Rva004D5767WordField { public: UnsignedShort get() const; };
class Rva004543C6ByteField { public: UnsignedByte get() const; };

class NetCommandRef
{
public:
	void *m_command;
	UnsignedInt m_unknown04;
	UnsignedInt m_unknown08;
	UnsignedByte m_relay;
};

class NetPacket
{
protected:
	char m_unknown000[0x1F0];
	NetCommandRef *m_lastCommand;
	Bool isAckBothRepeat(NetCommandRef *msg);
};

Bool NetPacket::isAckBothRepeat(NetCommandRef *msg)
{
	void *ack = msg->m_command;
	void *lastAck = m_lastCommand->m_command;
	if ((((Rva004D5767WordField *)ack)->get() - 1) ==
		((Rva004D5767WordField *)lastAck)->get()) {
		if (((Rva004543C6ByteField *)lastAck)->get() ==
			((Rva004543C6ByteField *)ack)->get()) {
			if (*(UnsignedInt *)((char *)lastAck + 0x24) ==
				*(UnsignedInt *)((char *)ack + 0x24)) {
				if (*(UnsignedInt *)((char *)lastAck + 0x20) ==
					*(UnsignedInt *)((char *)ack + 0x20)) {
					return m_lastCommand->m_relay == msg->m_relay;
				}
			}
		}
	} else {
		return false;
	}
	return false;
}
