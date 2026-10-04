// ?rva004D5112@Transport@@QAEH_N@Z
// partial score=0.9 date=2026-10-03
// cl: /O1 /G7 /DNDEBUG /MD
// ?rva004D5112@Transport@@QAE_N_N@Z @ 0x004D5112 33B evidence: Transport wrapper over UDP rva00594B2E broadcast via 0x40e0c; callees rowed; callers 0x00449C10 0x0044AA5D
class UDP
{
public:
	int rva00594B2E(bool on);
};

class Transport
{
public:
	int rva004D5112(bool on);
private:
	char m_pad[0x40E0C];
	UDP *m_udp;
};

// ?rva004D5112@Transport@@QAEH_N@Z present-unmatched
int Transport::rva004D5112(bool on)
{
	UDP *udp = m_udp;
	if (!udp)
		return 0;
	if (!udp->rva00594B2E(on))
		return 0;
	return 1;
}
