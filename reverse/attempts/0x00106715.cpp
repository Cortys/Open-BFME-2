// ?rva00106715@Rva00106715@@QAE_NPAXPAIPA_N@Z
// partial score=0.95 date=2026-09-29
// ?rva00106715@Rva00106715@@QAE_NPAXPAIPA_N@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD /EHsc
//
// ?rva00106715@Rva00106715@@QAE_NPAXPAHPA_N@Z, retail 0x00106715, 108 bytes.
// Stream read with overflow flag: reads 4B via slot +0xC twice, size via
// slot +0x30, bounds-checks the int at arg2 against end-size and sets the
// bool at arg3. Evidence: virtuals +0xC/+0x30 on this+4, ret-0xC three-arg
// bool/al shape, callers 0x0010679D 0x0010682B 0x001068E8 0x001069C2.
// Honest address name.
class Stream
{
public:
	virtual ~Stream();
	virtual void pad04();
	virtual void pad08();
	virtual int read(void *dst, int len);
	virtual void pad10();
	virtual void pad14();
	virtual void pad18();
	virtual void pad1C();
	virtual void pad20();
	virtual void pad24();
	virtual void pad28();
	virtual void pad2C();
	virtual int size();
};
class Rva00106715
{
public:
	bool rva00106715(void *dst1, unsigned int *p2, bool *overflow);
private:
	char m_pad0[4];
	Stream *m_stream04;
	int m_08;
	int m_end0C;
};

// ?rva00106715@Rva00106715@@QAE_NPAXPAIPA_N@Z present-unmatched
bool Rva00106715::rva00106715(void *dst1, unsigned int *p2, bool *overflow)
{
	int got = m_stream04->read(dst1, 4);
	*overflow = false;
	if (got != 4) {
		if (got == 0)
			return false;
		*overflow = true;
		return false;
	}
	int got2 = m_stream04->read(p2, 4);
	int sz = m_stream04->size();
	int avail = m_end0C;
	avail -= sz;
	if (got2 == 4 && *p2 >= 8) {
		unsigned int v = *p2 - 8;
		if (v <= (unsigned int)avail)
			return true;
	}
	*overflow = true;
	return false;
}
