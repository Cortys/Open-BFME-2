// cl: /O1 /DNDEBUG /MD
// ??4Rva0021915B@@QAEAAV0@ABV0@@Z @0x0021915B 31B
// Honest-address copy-assignment for an 8-byte AsciiString-plus-byte entry.
// Retail: self-check (cmp this,other; je skip), AsciiString::operator= at +0
// via pinned 0x000366F0, byte copy at +4, return *this (mov eax,esi; ret 4).
// Evidence: element stride 8 in copy_backward caller 0x002195B7 (47B loop with
// sar 3); swap callers 0x0021ACB9/0x0021BAA3/0x0021BB61/0x0021C798/0x0021C8D7/
// 0x0021D39E drive per-element *dest=*src over the same 8B layout; temp pair
// copy ctor 0x005117F6 (pair<const AsciiString,char>) and releaseBuffer
// 0x00036410 in those callers prove AsciiString at +0 plus 1-byte mapped at
// +4 (size 8 with padding). No donor; honest Rva name (never guess template args).

class AsciiString
{
public:
	AsciiString &operator=(const AsciiString &other);

private:
	void *m_data;
};

class Rva0021915B
{
public:
	Rva0021915B &operator=(const Rva0021915B &other);

private:
	AsciiString m_str;
	unsigned char m_byte;
};

Rva0021915B &Rva0021915B::operator=(const Rva0021915B &other)
{
	if (this != &other) {
		m_str = other.m_str;
		m_byte = other.m_byte;
	}
	return *this;
}
