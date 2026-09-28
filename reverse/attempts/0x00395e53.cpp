// ?rva00395E53@Rva00395E53@@QAEPAXI@Z
// partial score=0.92 date=2026-09-28
// ?rva00395E53@Rva00395E53@@QAEPAXI@Z
// partial score=0.92 date=2026-09-28
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
struct Rva00395E53Vec
{
	char *m_start;
	char *m_finish;
	void *m_end;
};
class Rva00395E53
{
public:
	void *rva00395E53(unsigned int index);
private:
	char m_pad[0x80];
	Rva00395E53Vec m_vec;
};
// ?rva00395E53@Rva00395E53@@QAEPAXI@Z present-unmatched
void *Rva00395E53::rva00395E53(unsigned int index)
{
	Rva00395E53Vec *vec = &m_vec;
	int count = (int)(vec->m_finish - vec->m_start) >> 2;
	if (index >= (unsigned int)count)
		return 0;
	return ((void **)vec->m_start)[index];
}
