// ?Rva004E43F2Find@@YAHH@Z
// partial score=0.93 date=2026-10-04
// ?Rva004E43F2Find@@YAHH@Z
// partial score=0.93 date=2026-10-04
// cl: /O1 /MD
// stlport
// ?Rva004E43F2Find@@YAHH@Z @0x004E43F2 84B.
// Nth-match index finder over the Rva004266A1 8-byte record vector: if
// global 0x00A031E8 or its ptr at +0x10 is null return -1; else scan the
// vector count, skipping skip matches of rowed rva0042680D, returning the
// index or -1. Callers at 0x004E4483 0x004E4587; callee rowed in
// Rva0042680DGetter.cpp.
// 2026-10-04 re-bank: dropping the redundant `if (count <= 0) return -1;`
// pre-test (the while guard already handles count<=0) drops the first diff
// from +0x22 to +0x1B and the differing-instruction count from 24 to 19,
// size 86 vs retail 84. The remaining wall is register-save/scheduling:
// retail pushes esi then ebp at +0x14 (ebp first used as `cur` in the loop
// body) and keeps a single top-of-loop `cmp ebx,esi / jge`; this build
// pushes ebp before esi and duplicates the guard at the loop bottom as
// `cmp ebx,esi / jl`, which costs the two extra bytes.
// ?Rva004E43F2Find@@YAHH@Z present-unmatched
#include <vector>
class AsciiString { public: AsciiString(const AsciiString &); AsciiString &operator=(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
struct Rva004266A1Rec { AsciiString text; unsigned char flag0; unsigned char flag1; unsigned char flag2; };
struct Rva004266A1 { char pad[4]; _STL::vector<Rva004266A1Rec> vec; bool rva004266A1(int index); unsigned char rva0042680D(int index); };
struct GlobalA031E8 { char pad[0x10]; Rva004266A1 *ptr; };
extern GlobalA031E8 *g_Va00A031E8;
int Rva004E43F2Find(int skip)
{
	GlobalA031E8 *g = g_Va00A031E8;
	if (!g)
		return -1;
	Rva004266A1 *v = g->ptr;
	if (!v)
		return -1;
	Rva004266A1 *vec = v;
	int i = 0;
	int count = (int)vec->vec.size();
	while (i < count)
	{
		int cur = i;
		i++;
		if (vec->rva0042680D(cur))
		{
			if (skip > 0)
				--skip;
			else
				return cur;
		}
	}
	return -1;
}
