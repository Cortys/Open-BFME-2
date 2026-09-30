// ?rva005E818E@Rva005E818E@@QAEXPAURef4@@ABU2@ABUFalseTag@@I_N@Z
// partial score=0.95 date=2026-09-30
// ?rva005E818E@Rva005E818E@@QAEXPAURef4@@ABU2@ABUFalseTag@@I_N@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?rva005E818E@Rva005E818E@@QAEXPAURef4@@ABU2@ABUFalseTag@@I_N@Z, retail 0x005E818E (178 bytes).
// _M_insert_overflow for 4B Rva005E71C6Ref records (STLport vector
// reallocation, __false_type path): new capacity is size plus max(size n),
// allocate through the end-storage allocator, copy [start pos), single
// assign when fill_len is 1 else fill, copy [pos finish) unless atend,
// tear down old storage through the rowed 0x005E8077 helper, then publish.
// Evidence: sar-2 size(), max-by-reference growth, allocate with null hint,
// two uninitialized_copy sites plus fill vs single assign, atend-guarded
// second copy, callers at 0x005E8289 and 0x005E8335.
#include <stddef.h>

struct Ref4
{
	void *m_object;
};

struct FalseTag
{
	FalseTag() {}
};

Ref4 *_CdeclUninitCopy(Ref4 *first, Ref4 *last, Ref4 *result, const FalseTag &tag);
void _CdeclAssign(Ref4 *pos, const Ref4 &val);
Ref4 *_CdeclFill(Ref4 *first, unsigned n, const Ref4 &val, const FalseTag &tag);

class PtrAlloc
{
public:
	Ref4 *allocate(unsigned n, const void *hint) const;
};

static const unsigned &my_max(const unsigned &a, const unsigned &b)
{
	return a < b ? b : a;
}

class Rva005E8077
{
public:
	void rva005E8077();
};

class Rva005E818E
{
public:
	void rva005E818E(Ref4 *pos, const Ref4 &val, const FalseTag &tag, unsigned n, bool atend);
	Ref4 *m_start;
	Ref4 *m_finish;
	Ref4 *m_end;
};

// ?rva005E818E@Rva005E818E@@QAEXPAURef4@@ABU2@ABUFalseTag@@I_N@Z present-unmatched
void Rva005E818E::rva005E818E(Ref4 *pos, const Ref4 &val, const FalseTag &tag, unsigned n, bool atend)
{
	unsigned oldSize = (unsigned)(m_finish - m_start);
	unsigned len = oldSize + my_max(oldSize, n);
	Ref4 *newStart = ((PtrAlloc *)&m_end)->allocate(len, 0);
	Ref4 *newFinish = newStart;
	newFinish = _CdeclUninitCopy(m_start, pos, newStart, FalseTag());
	if (n == 1)
	{
		_CdeclAssign(newFinish, val);
		++newFinish;
	}
	else
		newFinish = _CdeclFill(newFinish, n, val, FalseTag());
	if (!atend)
		newFinish = _CdeclUninitCopy(pos, m_finish, newFinish, FalseTag());
	((Rva005E8077 *)this)->rva005E8077();
	m_start = newStart;
	m_finish = newFinish;
	m_end = newStart + len;
}
