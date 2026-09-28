// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0039B20C@Rva0039B20C@@QAEXPAX@Z @0x0039B20C 27B conditional setter
// caching a pointer at +0x24 and refreshing the BfmeThingEFC at +0x2C via the
// rowed rva0039B1F9 at 0x0039B1F9. Evidence: chain from just-landed 0xB1F9;
// four callers pass [input+0xFC] with no extra args.

class BfmeThingEFC
{
public:
	void rva0039B1F9(void);
};

class Rva0039B20C
{
public:
	void rva0039B20C(void *src);

private:
	char m_pad00[0x24];
	void *m_ptr24;
	char m_pad28[0x4];
	BfmeThingEFC *m_efc2C;
};

void Rva0039B20C::rva0039B20C(void *src)
{
	if (src == 0)
		return;
	if (m_ptr24 == src)
		return;
	m_ptr24 = src;
	m_efc2C->rva0039B1F9();
}
