// ?rva0046152F@Rva0046152F@@QAEXPAULink12@@ABU2@ABUFalseTag@@I_N@Z
// partial score=0.93 date=2026-10-04
// ?rva0046152F@Rva0046152F@@QAEXPAULink12@@ABU2@ABUFalseTag@@I_N@Z
// partial score=0.9 date=2026-09-30
// ?rva0046152F@Rva0046152F@@QAEXPAULink12@@ABU2@ABUFalseTag@@I_N@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
//
// ?rva0046152F@Rva0046152F@@QAEXPAULink12@@ABU2@ABUFalseTag@@I_N@Z, retail 0x0046152F (183 bytes).
// _M_insert_overflow for 12B DynamicPortal Link records (STLport vector
// reallocation, __false_type path): new capacity is size plus max(size n),
// allocate through the end-storage allocator, copy [start pos), single
// construct when fill_len is 1 else fill_n, copy [pos finish) unless atend,
// tear down old storage through the rowed 0x0032E7E2 helper, then publish.
// Evidence: idiv-by-12 size(), max-by-reference growth, allocate with null
// hint, two uninitialized_copy sites plus fill_n vs single construct,
// atend-guarded second copy, caller at 0x004616A7 passing pos value tag 1 1.
#include <stddef.h>

struct Link12
{
	void *m_owned;
	int m_second;
	int m_third;
};

struct FalseTag
{
	FalseTag() {}
};

Link12 *_CdeclUninitCopy(Link12 *first, Link12 *last, Link12 *result, const FalseTag &tag);
void _CdeclConstruct(Link12 *pos, const Link12 &val);
Link12 *_CdeclFillN(Link12 *first, unsigned n, const Link12 &val, const FalseTag &tag);

class LinkAlloc
{
public:
	Link12 *allocate(unsigned n, const void *hint) const;
};

static const unsigned &my_max(const unsigned &a, const unsigned &b)
{
	return a < b ? b : a;
}

class Rva0032E7E2
{
public:
	void rva0032E7E2();
};

class Rva0046152F
{
public:
	void rva0046152F(Link12 *pos, const Link12 &val, const FalseTag &tag, unsigned n, bool atend);
	Link12 *m_start;
	Link12 *m_finish;
	Link12 *m_end;
};

// ?rva0046152F@Rva0046152F@@QAEXPAULink12@@ABU2@ABUFalseTag@@I_N@Z present-unmatched
void Rva0046152F::rva0046152F(Link12 *pos, const Link12 &val, const FalseTag &tag, unsigned n, bool atend)
{
	unsigned oldSize = (unsigned)(m_finish - m_start);
	unsigned len = oldSize + my_max(oldSize, n);
	Link12 *newStart = ((LinkAlloc *)&m_end)->allocate(len, 0);
	Link12 *newFinish = newStart;
	newFinish = _CdeclUninitCopy(m_start, pos, newStart, tag);
	if (n == 1)
	{
		_CdeclConstruct(newFinish, val);
		++newFinish;
	}
	else
		newFinish = _CdeclFillN(newFinish, n, val, tag);
	if (!atend)
		newFinish = _CdeclUninitCopy(pos, m_finish, newFinish, tag);
	((Rva0032E7E2 *)this)->rva0032E7E2();
	m_start = newStart;
	m_finish = newFinish;
	m_end = newStart + len;
}
