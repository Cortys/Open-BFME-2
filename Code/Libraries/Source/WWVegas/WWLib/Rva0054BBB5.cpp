// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// ?rva0054BBB5@Rva0054BBB5@@QAEXHM@Z, retail 0x0054BBB5, 37 bytes.
// Packs (int, float) into BfmeE8 temp and deque push_back at this+0x14.
// Evidence: prev 0x0054B850 deque push_back rowed, retail movss plus
// lea [ebp-8] plus add ecx 0x14 plus ret 8, 15 callers.

#include <deque>

struct BfmeE8
{
	int a;
	float b;
};

class Rva0054BBB5
{
public:
	void rva0054BBB5(int a, float b);
	void rva0054B414();

private:
	unsigned char m_pad00[0x14];
	_STL::deque<BfmeE8> m_deque;
};

void Rva0054BBB5::rva0054BBB5(int a, float b)
{
	BfmeE8 tmp;
	tmp.a = a;
	tmp.b = b;
	m_deque.push_back(tmp);
}

void Rva0054BBB5::rva0054B414()
{
	return m_deque.clear();
}
