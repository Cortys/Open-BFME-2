// ??1Rva005F2B22@@UAE@XZ
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ??1Rva005F2B22@@UAE@XZ, retail 0x005F2B22, 84 bytes.
// Evidence: chain via 0x005F2792; callers 0x005F2F67 0x005F32A7; vtable 0x00879218 at [this] then base s_first20 0x0084EF80; member at +0x20 clear via rowed 0x000AD6F4; global TheRva00222A8BTarget guard at 0x009FE4CC.
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;

class Rva005F2792
{
public:
	void rva005F2792();
};

class Rva000AD6F4
{
public:
	void clear();
	int m_ptr;
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Rva005F2B22Dummy
{
	~Rva005F2B22Dummy() { _ReadWriteBarrier(); }
};

class Rva005F2B22Base
{
public:
	virtual ~Rva005F2B22Base() {}
};

class Rva005F2B22 : public Rva005F2B22Base
{
public:
	virtual ~Rva005F2B22();
private:
	char m_pad04[0x20 - 4];
	Rva000AD6F4 m_member20;
};

// ??1Rva005F2B22@@UAE@XZ present-unmatched
Rva005F2B22::~Rva005F2B22()
{
	{
		Rva005F2B22Dummy dummy;
		if (m_member20.m_ptr == 0 && TheRva00222A8BTarget != 0)
			((Rva005F2792 *)this)->rva005F2792();
	}
	m_member20.clear();
}
