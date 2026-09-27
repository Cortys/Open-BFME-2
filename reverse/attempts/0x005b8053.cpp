// ?rva005B8053@Rva005B8053@@QAEPAXPBE@Z
// partial score=0.93 date=2026-09-27
// ?rva005B8053@Rva005B8053@@QAEPAXPBE@Z
// partial score=0.93 date=2026-09-27
// cl: /O1
// ?rva005B8053@Rva005B8053@@QAEPAXPBE@Z @ 0x005B8053 (58B). Unlock lane tree
// lookup shared by 0x005B808D/0x005B80AF/0x005B80D0/0x005B80F2 plus 0x00559DA0
// and 0x00553CDE. Evidence: lower_bound walk over byte key at node+0x10 with
// left at +8 right at +0xC root at header+4, end sentinel is header itself,
// equality_tail returns header on miss. Callers compare result to [container]
// and read word at +0x12 dword-float at +0x14.

struct Rva005B8053Node
{
	int _plus0;
	int _plus4;
	Rva005B8053Node *_left;
	Rva005B8053Node *_right;
	unsigned char _key;
};

struct Rva005B8053Header
{
	int _plus0;
	Rva005B8053Node *_root;
};

class Rva005B8053
{
	Rva005B8053Header *m_header;
public:
	void *rva005B8053(unsigned char const *key);
};

// ?rva005B8053@Rva005B8053@@QAEPAXPBE@Z present-unmatched
void *Rva005B8053::rva005B8053(unsigned char const *key)
{
	Rva005B8053Header *h = m_header;
	Rva005B8053Node *cur = h->_root;
	Rva005B8053Node *best = (Rva005B8053Node *)h;
	unsigned char const volatile *vkey = key;
	while (cur != 0) {
		if (cur->_key >= *vkey) {
			best = cur;
			cur = cur->_left;
		} else
			cur = cur->_right;
	}
	if (best != (Rva005B8053Node *)h) {
		if (*vkey < best->_key)
			best = (Rva005B8053Node *)h;
	}
	return best;
}
