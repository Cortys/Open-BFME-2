// ?rva004CD45C@Rva004CD45C@@QAEPAXXZ
// partial score=0.94 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva004CD45C@Rva004CD45C@@QAEPAXXZ @0x004CD45C (128B).
// Finds the first StoreObjectsSpecialPower module whose +0x88 vector is
// non-empty via static NameKey and virtual slot 0x10 walk.
enum NameKeyType
{
	NK_UNKNOWN = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class Rva004CD45CItem
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual NameKeyType getKey();
	unsigned char m_pad[0x88 - 4];
	unsigned int m_vecBeg;
	unsigned int m_vecEnd;
};

struct Rva004CD45CMid
{
	unsigned char m_pad[0x244];
	Rva004CD45CItem **m_list;
};

class Rva004CD45C
{
public:
	unsigned char m_pad0[8];
	Rva004CD45CMid *m_mid;
	void *rva004CD45C();
};

// ?rva004CD45C@Rva004CD45C@@QAEPAXXZ present-unmatched
void *Rva004CD45C::rva004CD45C()
{
	static NameKeyType s_key = TheNameKeyGenerator->nameToKey("StoreObjectsSpecialPower");
	Rva004CD45CMid *mid = m_mid;
	Rva004CD45CItem **pp = mid->m_list;
	for (;;) {
		Rva004CD45CItem *cur = *pp;
		if (cur == 0)
			return 0;
		if (cur->getKey() != s_key) {
			pp++;
			continue;
		}
		cur = *pp;
		if (cur == 0) {
			pp++;
			continue;
		}
		unsigned int *vec = (unsigned int *)((char *)cur + 0x88);
		int diff = (int)vec[1] - (int)vec[0];
		diff >>= 2;
		if (diff != 0)
			return cur;
		pp++;
	}
}
