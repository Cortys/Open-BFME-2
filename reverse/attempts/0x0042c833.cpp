// ??1Rva0042C833@@UAE@XZ
// partial score=0.94 date=2026-10-03
// cl: /O1 /EHsc /MD
// ??1Rva0042C833@@UAE@XZ @0x0042C833 70B via virtual dtor with member unregister plus clear
// Evidence: vtable stores 0x00C3C6EC then 0x00BDBA74; calls 0x0042CAEB via +0xC ptr plus 0x000AD6F4 clear via +0x14; caller 0x0042C97A; chain lane
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva0042CBB6
{
public:
	void rva0042CAEB(int y);
};

class Rva000AD6F4
{
public:
	void clear();
	int m_ptr;
};

class Rva0042C833Base
{
public:
	virtual ~Rva0042C833Base() {}
	int m_04;
	int m_08;
};

struct Rva0042C833OneByte
{
	~Rva0042C833OneByte();
	char m_c;
};

class Rva0042C833 : public Rva0042C833Base
{
public:
	virtual ~Rva0042C833();
private:
	Rva0042CBB6 *m_0C;
	Rva0042C833OneByte m_10;
	Rva000AD6F4 m_14;
};

// ??1Rva0042C833OneByte@@QAE@XZ present-unmatched
Rva0042C833OneByte::~Rva0042C833OneByte()
{
	_ReadWriteBarrier();
}

// ??1Rva0042C833@@UAE@XZ present-unmatched
Rva0042C833::~Rva0042C833()
{
	m_0C->rva0042CAEB((int)this);
	m_14.clear();
}
