// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002329D3@AIPlayer@@QAE_NXZ @0x002329D3 111B unlock lane.
// Evidence: prev AIPlayerDestructor same flags; caller 0x00232A42 same layout; callee push_back 0x00539A2E rowed.
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
	bool rva002329D3();
};
bool AIPlayer::rva002329D3()
{
	bool done = false;
	AIEntry *p = m_arr1C;
	for (int i = 0; i < 256; ++i, ++p) {
		if ((p->m_flag1E & 2) == 0)
			continue;
		if ((unsigned)(m_tailE1C - p->m_val) <= 10)
			continue;
		BfmeE8 e;
		e.m0 = (unsigned char)i;
		e.m2 = 0x102;
		e.m1 = 0;
		m_vec10.push_back(e);
		for (int j = 0; j < 256; ++j)
			m_arr1C[j].m_val = m_tailE1C;
		m_arr1C[i].m_val = m_tailE1C - 12;
		done = true;
		break;
	}
	return done;
}
