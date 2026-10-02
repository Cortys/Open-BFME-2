// ?rva00538DEA@Rva00538DEA@@QAEPAVRva00318B5C@@PAV2@@Z
// partial score=0.96 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
// ?rva00538DEA@Rva00538DEA@@QAEPAURva00318B5C@@PAU2@@Z 0x00538DEA 56 chain copy-one-back-plus-virtual-zero; callers 0x00538EA0; callee rowed Rva0031968ACopy 0x0031968A
class Rva00318B5C
{
public:
	virtual ~Rva00318B5C();
	int m_4;
	int m_8;
	int m_C;
};
Rva00318B5C *Rva0031968ACopy(const Rva00318B5C *first, const Rva00318B5C *last, Rva00318B5C *result);
struct VCall
{
	virtual void vf(int x);
};
class Rva00538DEA
{
public:
	Rva00318B5C *rva00538DEA(Rva00318B5C *arg);
private:
	char m_pad[4];
	union
	{
		Rva00318B5C *m_4;
		VCall *m_v;
	};
};

// ?rva00538DEA@Rva00538DEA@@QAEPAVRva00318B5C@@PAV2@@Z present-unmatched
Rva00318B5C *Rva00538DEA::rva00538DEA(Rva00318B5C *arg)
{
	Rva00318B5C *first = arg + 1;
	const Rva00318B5C *last = m_4;
	if (last != first)
	{
		char tag;
		((Rva00318B5C *(__cdecl *)(const Rva00318B5C *, const Rva00318B5C *, Rva00318B5C *, void *))Rva0031968ACopy)(first, m_4, arg, &tag);
	}
	m_4 -= 1;
	m_v->vf(0);
	return arg;
}
