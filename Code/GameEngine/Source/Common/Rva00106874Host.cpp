// cl: /O1 /MD
//
// ?rva00106874@Rva00106874Host@@QAE_NXZ, retail 0x00106874, 27 bytes.
// Target evidence: frameless release-if-nonnull at +0x04 via virtual slot 2
// then null plus bool return; callers 0x00106A3F and 0x00106B68 unclaimed.
// Prev is dup_0010670b MessageStream.cpp, next is invokeForMode
// Rva007E3410VirtualCall.cpp. True class name unproven so honest Rva
// address name stands in.

struct Rva00106874Pointee
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
};

class Rva00106874Host
{
public:
	bool rva00106874();
private:
	int m_00;
	Rva00106874Pointee *m_04;
};

bool Rva00106874Host::rva00106874()
{
	if (m_04)
	{
		m_04->v2();
		m_04 = 0;
		return true;
	}
	return false;
}
