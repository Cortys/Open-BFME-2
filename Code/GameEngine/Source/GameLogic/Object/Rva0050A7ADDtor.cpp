// cl: /O1 /MD /EHsc /DNDEBUG
//
// ??1Rva0050A7AD@@UAE@XZ retail 0x0050A7AD 56B dtor with filter.
// Evidence: member dtor 0x00360D26 at +0x160; base dtor 0x00507823; caller deleting 0x0050A791.
class Rva00360D26Member
{
public:
	~Rva00360D26Member();
private:
	int m_x;
};

class Rva00507823
{
public:
	virtual ~Rva00507823();
private:
	unsigned char m_pad[0x128 - 4];
};

class __declspec(novtable) Rva0050A7AD : public Rva00507823
{
public:
	virtual ~Rva0050A7AD();
private:
	char m_pad128[0x160 - 0x128];
	Rva00360D26Member m_160;
};

Rva0050A7AD::~Rva0050A7AD()
{
}
