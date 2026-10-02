// cl: /O1 /DNDEBUG /MD
//
// ?Rva004D54C1@Transport@@QAE_N_N@Z, retail 0x004D54C1 (115B).
// Zero Hour's Transport::update (Transport.cpp) for BFME 2's transport, which
// owns eight UDP sockets (12-byte slots from +0x40E0C) instead of one: a failed
// receive or send makes the update fail only when some socket reports
// ADDRNOTAVAIL (UDP status -7, rowed 0x00594A06). The receive takes the
// caller's flag. The callers' pinned address-derived spelling is kept; the
// receive and send halves (0x004D4D08 / 0x004D4BA7) are pinned.

typedef bool Bool;

class UDP
{
public:
	enum SockStatus { ADDRNOTAVAIL = -7 };
	int rva00594A06();
};

struct TransportSocketSlot
{
	UDP *m_udpsock;
	unsigned int m_ip;
	unsigned int m_port;
};

class Transport
{
public:
	Bool Rva004D54C1(Bool flag);
	Bool rva004D4D08(Bool flag);
	Bool rva004D4BA7();

private:
	char m_pad00000[0x40E0C];
	TransportSocketSlot m_sockets[8]; // +0x40E0C
};

Bool Transport::Rva004D54C1(Bool flag)
{
	Bool retval = true;
	if (rva004D4D08(flag) == false)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (m_sockets[i].m_udpsock && m_sockets[i].m_udpsock->rva00594A06() == UDP::ADDRNOTAVAIL)
			{
				retval = false;
				break;
			}
		}
	}
	if (rva004D4BA7() == false)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (m_sockets[i].m_udpsock && m_sockets[i].m_udpsock->rva00594A06() == UDP::ADDRNOTAVAIL)
			{
				retval = false;
				break;
			}
		}
	}
	return retval;
}
