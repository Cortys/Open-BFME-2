// ?rva002AF438@Rva002AF438@@QAE@IIII@Z
// partial score=0.92 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
//
// ?rva002AF438@Rva002AF438@@QAE@IIII@Z, retail 0x002AF438, 64 bytes.
// Hashtable ctor shape: vector<unsigned int> at +4 via rowed vector ctor,
// hashtable buckets init via rowed _M_initialize_buckets, num_elements at
// +0x10 cleared to 0, EH prolog with scopetable plus state 0.
// Evidence: callers plus rowed vector 0x00025100 plus rowed hashtable init
// 0x00148DDF plus ret 0x10 four args plus prev/next TU flags.
#include <vector>

class Rva002AF438
{
public:
	Rva002AF438(unsigned int n, unsigned int a, unsigned int b, unsigned int c);
	void _M_initialize_buckets(unsigned int n);
private:
	char m_00[4];
	_STL::vector<unsigned int> m_04;
	unsigned int m_10;
};

// ??0Rva002AF438@@QAE@IIII@Z present-unmatched
Rva002AF438::Rva002AF438(unsigned int n, unsigned int a, unsigned int b, unsigned int c)
	: m_04((_STL::allocator<unsigned int> &)c), m_10(0)
{
	_M_initialize_buckets(n);
	(void)a;
	(void)b;
	(void)c;
}
