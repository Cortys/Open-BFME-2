// ?rva0041AAA4@Rva0041AAA4@@QAE_NPAUBfmeNarrowRecord0041A5D2@@@Z
// partial score=0.93 date=2026-09-28
// ?rva0041AAA4@Rva0041AAA4@@QAE_NPAUBfmeNarrowRecord0041A5D2@@@Z
// partial score=0.93 date=2026-09-28
#include <memory>
#include <string>
class MutexClass
{
public:
	MutexClass(const char *name);
	class LockClass
	{
	public:
		LockClass(MutexClass &mutex, int timeout);
		~LockClass();
		bool Failed() { return m_failed; }
	private:
		MutexClass &m_mutex;
		bool m_failed;
	};
private:
	void *m_handle;
	unsigned int m_locked;
};
struct BfmeNarrowRecord0041A5D2 {
    _STL::basic_string<char> text0; unsigned short short0; _STL::basic_string<char> text1;
    BfmeNarrowRecord0041A5D2 &operator=(const BfmeNarrowRecord0041A5D2 &o);
};
struct Rva0041A3C4 {
    BfmeNarrowRecord0041A5D2 *_M_cur;
    BfmeNarrowRecord0041A5D2 *_M_first;
    BfmeNarrowRecord0041A5D2 *_M_last;
    BfmeNarrowRecord0041A5D2 **_M_node;
    void rva0041A486();
};
struct Rva0041AAA4 {
    unsigned char m_pad0[0xC];
    MutexClass m_mutex;
    unsigned char m_pad1[0x8];
    Rva0041A3C4 m_iter;
    BfmeNarrowRecord0041A5D2 *m_end;
    bool rva0041AAA4(BfmeNarrowRecord0041A5D2 *out);
};
// ?rva0041AAA4@Rva0041AAA4@@QAE_NPAUBfmeNarrowRecord0041A5D2@@@Z present-unmatched
bool Rva0041AAA4::rva0041AAA4(BfmeNarrowRecord0041A5D2 *out)
{
	bool ok = false;
	MutexClass::LockClass lock(m_mutex, 0);
	BfmeNarrowRecord0041A5D2 *end = m_end;
	if (!lock.Failed() && end != m_iter._M_cur)
	{
		out->operator=(*m_iter._M_cur);
		m_iter.rva0041A486();
		ok = true;
	}
	return ok;
}
