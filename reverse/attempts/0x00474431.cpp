// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z
// partial score=0.93 date=2026-09-30
// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z, retail 0x00474431, 82 bytes.
// Build record from pair plus int via rowed Rva004691A5 ctor, push into
// vector at +0x188, return size-1. Callees rowed 0x004691A5 plus push_back
// 0x00473F4A. Callers 0x004744CE 0x004747F7.
#include <vector>

class Rva004691A5
{
public:
	Rva004691A5();
private:
	int m_00;
	char m_pad04[0x10];
	float m_14;
	int m_18;
};

class Rva00064640Record
{
public:
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	float m_10;
	float m_14;
	unsigned int m_18;
};

struct Rva00474431Pair
{
	int m_00;
	int m_04;
};

class Rva00474431
{
public:
	int rva00474431(const Rva00474431Pair &p, int v);
	char m_pad[0x188];
	_STL::vector<Rva00064640Record> m_vec;
};

int Rva00474431::rva00474431(const Rva00474431Pair &p, int v)
{
	Rva004691A5 u;
	Rva00064640Record &r = *(Rva00064640Record *)&u;
	r.m_0C = p.m_00;
	*(int *)&r.m_10 = p.m_04;
	r.m_08 = p.m_04;
	r.m_00 = v;
	r.m_04 = p.m_00;
	m_vec.push_back(r);
	return m_vec.size() - 1;
}
