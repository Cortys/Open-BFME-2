// ?rva0040DDD6@Rva0040DDD6@@QAEHXZ
// partial score=0.93 date=2026-09-28
// ?rva0040DDD6@Rva0040DDD6@@QAEHXZ
// partial score=0.93 date=2026-09-28
// cl: /O1
struct Rva004F69C3
{
	int m_00;
	void *m_04;
	~Rva004F69C3();
};
namespace _STL {
template<class T> class allocator {};
template<class T, class A> class vector {
public:
	typedef T *iterator;
	iterator erase(iterator pos);
	T *m_start;
	T *m_finish;
	T *m_end;
};
}
struct Pointee090C4
{
	char m_pad[0x90];
	int m_90;
	char m_pad2[0xC4 - 0x90 - 4];
	unsigned char m_C4;
};
class Rva0040DDD6
{
public:
	int rva0040DDD6();
private:
	char m_pad[0x40];
	_STL::vector<Rva004F69C3, _STL::allocator<Rva004F69C3> > m_vec;
};
int Rva0040DDD6::rva0040DDD6()
{
	int sum = 0;
	int n = m_vec.m_finish - m_vec.m_start;
	for (int i = n - 1; i >= 0; --i) {
		if (((Pointee090C4*)m_vec.m_start[i].m_04)->m_C4 == 0)
			continue;
		sum += ((Pointee090C4*)m_vec.m_start[i].m_04)->m_90;
		m_vec.erase(&m_vec.m_start[i]);
	}
	return sum;
}
