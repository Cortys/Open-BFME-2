// ?rva005EA8E3@Rva005EA8E3@@QAEXHH@Z
// partial score=0.96 date=2026-10-03
// cl: /O1 /G7 /DNDEBUG /MD /EHs-c-
// ?rva005EA8E3@Rva005EA8E3@@QAEXHH@Z @0x005EA8E3 55B thiscall bounded clear via ranges
// Clears Rva002BED91 at elem+0x20 for index j in range i when 0<=j<count; sizes 0xC and 0x24 match siblings; callers 0x005EA990 0x005EA9A1
class Rva002BED91
{
public:
	void clear();
private:
	void *m_ptr;
};
struct Rva005EA8E3Elem
{
	char m_pad[0x20];
	Rva002BED91 m_holder;
};
struct Rva005EA8E3Range
{
	Rva005EA8E3Elem *m_begin;
	Rva005EA8E3Elem *m_end;
	int m_pad;
};
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class Rva005EA8E3
{
public:
	void rva005EA8E3(int i, int j);
private:
	char m_pad[0x1c];
	Rva005EA8E3Range m_ranges[2];
};
// ?rva005EA8E3@Rva005EA8E3@@QAEXHH@Z present-unmatched
void Rva005EA8E3::rva005EA8E3(int i, int j)
{
	if (j < 0)
		return;
	Rva005EA8E3Range *r = m_ranges + i;
	int count = ((char *)r->m_end - (char *)r->m_begin) / 36;
	if ((unsigned int)j >= (unsigned int)count)
		return;
	_ReadWriteBarrier();
	Rva005EA8E3Elem *begin = r->m_begin;
	_ReadWriteBarrier();
	begin[j].m_holder.clear();
}
