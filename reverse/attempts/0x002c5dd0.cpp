// ?Rva002C5DD0Parse@@YAHPBD@Z
// partial score=0.92 date=2026-09-29
// ?Rva002C5DD0Parse@@YAHPBD@Z
// partial score=0.92 date=2026-09-29
// ?Rva002C5DD0Parse@@YAHPBD@Z retail 0x002C5DD0 112B
// Evidence: callers 0x002C5E6C 0x002C5EA0 unblocks 0x002C5E40 plus 0x002C5E8F; rowed StringBase compare 0x69B1 plus release 0x36410 plus INIException 0x2F681 plus CxxThrow pin; 5 names at 0x00DBC1A8
template<typename T> class StringBase
{
public:
	StringBase(const char *s);
	~StringBase() { releaseBuffer(); }
	int compare(const char *s) const;
private:
	void releaseBuffer();
	T *m_data;
};

struct INIException { char *message; int code; };
extern "C" void rva002f681_fill(void *, int, const char *, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *, void *);
struct ThrowInfo { int a, b, c, d; };

// ?Rva002C5DD0Parse@@YAHPBD@Z present-unmatched
int __cdecl Rva002C5DD0Parse(const char *token)
{
	int i = 0;
	if (!token)
		goto fail;
	for (; i < 5; ++i) {
		StringBase<char> tmp(((const char **)0x00DBC1A8)[i]);
		unsigned char found = (tmp.compare(token) == 0);
		if (found)
			return i;
	}
fail:
	INIException e;
	rva002f681_fill(&e, 2, (const char *)0x00C004B4);
	_CxxThrowException(&e, (void *)0x00CFE2FC);
}
