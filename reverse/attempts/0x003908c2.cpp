// ??1Rva003908C2@@UAE@XZ
// partial score=0.96 date=2026-09-30
// ??1Rva003908C2@@UAE@XZ
// partial score=0.96 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHs
//
// ??1Rva003908C2@@UAE@XZ, retail 0x003908C2, 79 bytes.
// Evidence: vtable 0x00819F74 plus s_secondary0C at +0x0C plus g_00C19F68
// at +0x10 plus _free of +0x20 via rowed 0x00030830 plus base dtor
// ??1Rva0024A797 rowed 0x0024A797; EH prolog 0x00629188; caller 0x003909DE.
static int s_secondary0C;

extern "C" void _free(void *p);
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

extern const void *const g_00C19F68[];

class Rva0024A797
{
public:
	virtual ~Rva0024A797();

protected:
	char m_pad[8];
};

class Rva003908C2 : public Rva0024A797
{
public:
	virtual ~Rva003908C2();

private:
	const void *m_p0C;
	const void *m_p10;
	char m_pad14[0x20 - 0x14];
	void *m_p20;
};

// ??1Rva003908C2@@UAE@XZ present-unmatched
Rva003908C2::~Rva003908C2()
{
	m_p0C = &s_secondary0C;
	m_p10 = g_00C19F68;
	_ReadWriteBarrier();
	if (m_p20)
		_free(m_p20);
}
