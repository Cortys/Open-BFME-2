// ?rva005DB145@Rva005DB145@@QAEXABURva0039B2E6Input@@H@Z
// partial score=0.92 date=2026-09-30
// ?rva005DB145@Rva005DB145@@QAEXABURva0039B2E6Input@@H@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
// ?rva005DB145@Rva005DB145@@QAEXABURva0039B2E6Input@@H@Z @0x005DB145 163B
// Evidence: chain from landed 0x39B2E6; input array +0x4c/+0x50 of elems with
// id at +0x38 accumulates bits into 128B local via rowed BfmeFixedStorage128
// copy 0x4548B then rep movsd writeback to holder at +0x38+0x10; +0xfc>1 sets
// flag at +0x20; tail calls rowed 0x39B2E6 on input; second arg unread.
class AsciiString
{
private:
	void *m_data;
};

struct Rva0039B2E6Input;

class Rva0039B2E6
{
public:
	void rva0039B2E6(const struct Rva0039B2E6Input &input);
};

struct BfmeFixedStorage128
{
	BfmeFixedStorage128(const BfmeFixedStorage128 &other);
	unsigned int m_w[32];
};

struct Db145Holder
{
	char m_pad00[0x10];
	BfmeFixedStorage128 m_stor10;
};

struct Db145Elem
{
	char m_pad00[0x38];
	unsigned int m_val38;
};

struct Db145Input
{
	char m_pad00[0x10];
	AsciiString m_str10;
	char m_pad14[0x1C - 0x14];
	int m_1C;
	int m_20;
	char m_pad24[0x4C - 0x24];
	volatile int m_begin4C;
	volatile int m_end50;
	char m_pad54[0xFC - 0x54];
	int m_cntFC;
};

class Rva005DB145
{
public:
	void rva005DB145(const struct Rva0039B2E6Input &input, int);
private:
	char m_pad00[8];
	AsciiString m_str08;
	int m_key0C;
	char m_pad10[0x20 - 0x10];
	bool m_flag20;
	char m_pad21[0x38 - 0x21];
	Db145Holder *m_holder38;
};

// ?rva005DB145@Rva005DB145@@QAEXABURva0039B2E6Input@@H@Z present-unmatched
void Rva005DB145::rva005DB145(const struct Rva0039B2E6Input &input, int)
{
	const Db145Input *in = (const Db145Input *)&input;
	if (in->m_end50 != in->m_begin4C) {
		BfmeFixedStorage128 bits(m_holder38->m_stor10);
		unsigned int i = 0;
		if (((in->m_end50 - in->m_begin4C) >> 2) != 0) {
			Db145Elem **pp = (Db145Elem **)in->m_begin4C;
			do {
				Db145Elem *e = *pp;
				if (e != 0) {
					unsigned int v = e->m_val38;
					bits.m_w[v >> 5] |= (1u << (v & 31));
				}
				++i;
				++pp;
			} while (i < (unsigned)((in->m_end50 - in->m_begin4C) >> 2));
		}
		m_holder38->m_stor10 = bits;
	}
	if (in->m_cntFC > 1)
		m_flag20 = true;
	((Rva0039B2E6 *)this)->rva0039B2E6(input);
}
