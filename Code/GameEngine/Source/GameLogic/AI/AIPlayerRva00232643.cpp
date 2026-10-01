// cl: /O1 /DNDEBUG /MD /EHsc /G7
// ?rva00232643@AIPlayer@@QAE_NE@Z @0x00232643 17B unlock lane.
// Evidence: AIEntry layout from AIPlayerRva002329D3.cpp (m_arr1C[256] 8B entries at +0x1C, flag byte at +0x1E, bit1 tested there); neighbours AIPlayerDestructor.cpp / AIPlayerRva002326AE.cpp same flags; callers 0x0042F8AF +0x005B1FFA.
struct BfmeE8 {
	unsigned char m0;
	unsigned char m1;
	unsigned short m2;
	int m3;
};
namespace _STL {
template <class T> class allocator {
public:
	allocator() {}
};
template <class T, class A> class vector {
	void *_M_start;
	void *_M_finish;
	void *_M_end;
public:
	void push_back(const T &);
};
}
struct AIEntry {
	unsigned char m_idx;
	unsigned char m_b1D;
	unsigned char m_flag1E;
	unsigned char m_pad1F;
	int m_val;
};
class AIPlayer {
	char m_pad00[0x10];
	_STL::vector<BfmeE8, _STL::allocator<BfmeE8> > m_vec10;
	AIEntry m_arr1C[256];
	char m_block81C[0x600];
	int m_tailE1C;
public:
	bool rva00232643(unsigned char idx);
};

bool AIPlayer::rva00232643(unsigned char idx)
{
	return (m_arr1C[idx].m_flag1E >> 1) & 1;
}
