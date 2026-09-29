// ??0Rva00496ADE@@QAE@XZ
// partial score=0.93 date=2026-09-29
// ??0Rva00496ADE@@QAE@XZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /EHs /MD
// probe2 init-list 78B/24insns exact size/count; order differs: retail clears +0 before +8 ctor plus lea+and for +54 before +4 vs ours +8 ctor then +0/+4/+54 clears; plus dummy string X vs retail literal at 0x00BBAC1C; vtable none; EHs for memset/set states; StringBase friend for private releaseBuffer
#include <new.h>

template <typename T>
class StringBase
{
	void releaseBuffer();
	friend class Rva00496ADE;
public:
	void set(const char *s);
	~StringBase();
	T *m_data;
};

class Rva0042526Member
{
public:
	Rva0042526Member();
private:
	unsigned char m_pad[0x4C];
};

class Rva00496ADE
{
public:
	Rva00496ADE();
private:
	StringBase<char> m_str00;
	int m_04;
	Rva0042526Member m_mem08;
	StringBase<char> m_str54;
};

// ??0Rva00496ADE@@QAE@XZ present-unmatched
Rva00496ADE::Rva00496ADE()
	: m_mem08()
{
	m_str00.m_data = 0;
	m_04 = 0;
	m_str54.m_data = 0;
	m_str54.set("X");
	m_str00.releaseBuffer();
}
