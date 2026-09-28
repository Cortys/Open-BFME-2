// cl: /O1 /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP=
// stlport
// ?rva0043D3DA@Rva0043D3DA@@QAEXH@Z @0x0043D3DA 68B
// Conditional clear of +0x288 sub-object and +0x27C void-ptr vector.
// Evidence: caller @0x0043D452; callee rowed ?rva0043D3A8@Rva0043D3A8@@QAEXXZ
// @0x0043D3A8 via outer+0x288 and rowed void-ptr erase @0x0031BD55 via
// outer+0x27C; globals 0x009FE78C+0x110 and 0x009FEDF0+0x16 gate the clear.
#include <vector>

enum ScienceType
{
	SCIENCE_INVALID = 0
};

class Rva0043D3A8
{
public:
	void rva0043D3A8();

private:
	char m_unk0[8];
	_STL::vector<ScienceType> m_sciences;
	int m_unk14;
};

extern int g_Va009FE78C;
extern int g_Va009FEDF0;

class Rva0043D3DA
{
public:
	void rva0043D3DA(int unused);

private:
	char m_pad0[0x27c];
	_STL::vector<void *> m_ptrs;
	Rva0043D3A8 m_sub;
	char m_pad1[2];
	bool m_flag;
};

void Rva0043D3DA::rva0043D3DA(int unused)
{
	(void)unused;
	if (*(int *)(g_Va009FE78C + 0x110) == 6) {
		if (*(unsigned char *)(g_Va009FEDF0 + 0x16) == 0)
			return;
	}
	if (m_flag)
		return;
	m_sub.rva0043D3A8();
	_STL::vector<void *> &slot = m_ptrs;
	slot.erase(slot.begin(), slot.end());
}
