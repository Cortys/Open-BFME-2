// cl: /O1
// ?rva005659CA@Rva005659CA@@QAEXXZ retail 0x005659CA 30B: tidy destroying [m_00,m_04) via 0x005A6EDA then freeing m_00. Callers include 0x0015031B.

struct Rva0052BF33Elem
{
	virtual ~Rva0052BF33Elem();
};

void Rva005A6EDADestroyRange(Rva0052BF33Elem *first, Rva0052BF33Elem *last);

extern "C" void __cdecl free(void *block);

class Rva005659CA
{
public:
	void rva005659CA();
private:
	Rva0052BF33Elem *m_00;
	Rva0052BF33Elem *m_04;
};

void Rva005659CA::rva005659CA()
{
	Rva005A6EDADestroyRange(m_00, m_04);
	Rva0052BF33Elem *buf = m_00;
	if (buf != 0)
		free(buf);
}

struct Rva0052BF4DElem
{
	virtual ~Rva0052BF4DElem();
};

void Rva0052C266DestroyRange(Rva0052BF4DElem *first, Rva0052BF4DElem *last);

class Rva005659E8
{
public:
	void rva005659E8();
private:
	Rva0052BF4DElem *m_00;
	Rva0052BF4DElem *m_04;
};

void Rva005659E8::rva005659E8()
{
	Rva0052C266DestroyRange(m_00, m_04);
	Rva0052BF4DElem *buf = m_00;
	if (buf != 0)
		free(buf);
}
