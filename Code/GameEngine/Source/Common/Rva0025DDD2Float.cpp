// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva0025DDD2@Rva0025DDD2@@QBEMXZ @0x0025DDD2 46B: float wrapper over
// Transport::rva004D5046. Follows +0x0C to holder then +0x12024 to Transport
// per BFMEConnectionManager layout; null at either step yields 0.0f.
// Evidence: retail mov/test/je chain plus rowed call 0x004D5046 plus
// fstp/xorps/movss/fld tails; owner unproven so honest address name.
class Transport
{
public:
	float rva004D5046() const;
};

class BFMEConnectionManager
{
public:
	char m_pad[0x12024];
	Transport *m_transport12024;
};

class Rva0025DDD2
{
	char m_pad0C[0x0C];
	BFMEConnectionManager *m_mgr0C;

public:
	float rva0025DDD2() const;
};

float Rva0025DDD2::rva0025DDD2() const
{
	volatile float result;
	BFMEConnectionManager *mgr = m_mgr0C;
	Transport *t = 0;
	if (mgr != 0)
		t = mgr->m_transport12024;
	if (t != 0)
		result = t->rva004D5046();
	else
		result = 0.0f;
	return result;
}
