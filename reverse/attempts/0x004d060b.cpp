// ??1Rva004D060B@@QAE@XZ
// partial score=0.95 date=2026-10-03
// ??1Rva004D060B@@QAE@XZ
// partial score=0.91 date=2026-10-03
// ??1Rva004D060B@@QAE@XZ
// partial score=0.91 date=2026-09-29
// ??1Rva004D060B@@QAE@XZ
// partial score=0.91 date=2026-09-29
// cl: /O1 /EHa /MD /D_STLP_USE_STATIC_LIB
// ??1Rva004D060B@@QAE@XZ @0x004D060B 66B
// Dtor: wide string at +0x14 via releaseBuffer 0x36E70 plus iface ptr at +0x18
// via virtual slot0 with 0 then operator delete 0x2FD60. Evidence: deleting
// dtor caller at 0x004D064D plus array delete loop at 0x004D06AE plus EH prolog.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};
class Rva004D060BIface
{
public:
	virtual void *Get(int v);
};
class Rva004D060B
{
public:
	~Rva004D060B();
private:
	unsigned char m_pad[0x14];
	StringBase<unsigned short> m_text;
	Rva004D060BIface *m_ptr;
};
// ??1Rva004D060B@@QAE@XZ present-unmatched
Rva004D060B::~Rva004D060B()
{
	void *block = 0;
	Rva004D060BIface *p = m_ptr;
	if (p)
		block = p->Get(0);
	::operator delete(block);

}
