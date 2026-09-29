// ?Read@UDP@@QAEHPAEIPAUsockaddr_in@@@Z
// partial score=0.93 date=2026-09-29
// ?Read@UDP@@QAEHPAEIPAUsockaddr_in@@@Z
// partial score=0.93 date=2026-09-29
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX
//
// ?Read@UDP@@QAEHPAEIPAUsockaddr_in@@@Z, retail 0x005949AB 91B.
// BFME2 UDP::Read transferred from BFME1 donor
// (game/GameEngine/Source/GameNetwork/udp.cpp UDP::Read): recvfrom with
// optional sockaddr_in, WSAEWOULDBLOCK maps to 0, other errors store
// WSAGetLastError in m_lastError at +0x1c. Layout from donor header:
// fd +0, myIP +4, myPort +8, addr +0xc, m_lastError +0x1c.
// Callers 0x004D4EA0 0x00594E3F, prev 0x0059495D getLocalAddr.

struct in_addr
{
	union
	{
		unsigned long S_addr;
	} S_un;
};

struct sockaddr
{
	unsigned short sa_family;
	char sa_data[14];
};

struct sockaddr_in
{
	short sin_family;
	unsigned short sin_port;
	in_addr sin_addr;
	char sin_zero[8];
};

#define SOCKET_ERROR (-1)
#define WSAEWOULDBLOCK 10035

extern "C" __declspec(dllimport) int __stdcall recvfrom(
	int s, char *buf, int len, int flags, sockaddr *from, int *fromlen);
extern "C" __declspec(dllimport) int __stdcall WSAGetLastError(void);

class UDP
{
public:
	int getLocalAddr(unsigned int &addr, unsigned short &port);
	int Read(unsigned char *msg, unsigned int len, sockaddr_in *from);

private:
	int m_fd;				// +0x00
	unsigned int m_ip;		// +0x04
	unsigned short m_port;	// +0x08
	unsigned short m_pad;
	sockaddr_in m_addr;		// +0x0c
	int m_lastError;		// +0x1c
};

// ?getLocalAddr@UDP@@QAEHAAIAAG@Z
int UDP::getLocalAddr(unsigned int &addr, unsigned short &port)
{
	addr = m_ip;
	port = m_port;
	return 0;
}

// ?Read@UDP@@QAEHPAEIPAUsockaddr_in@@@Z present-unmatched
int UDP::Read(unsigned char *msg, unsigned int len, sockaddr_in *from)
{
	int retval;
	int alen = sizeof(sockaddr_in);

	if (from != 0)
		retval = recvfrom(m_fd, (char *)msg, len, 0, (sockaddr *)from, &alen);
	else
		retval = recvfrom(m_fd, (char *)msg, len, 0, 0, 0);
	if (retval == SOCKET_ERROR)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			retval = -1;
			m_lastError = WSAGetLastError();
		}
		else
			retval = 0;
	}
	return retval;
}
