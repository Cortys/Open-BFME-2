// cl: /O1 /MD
//
// ?rva000AD9AB@Rva000AD9AB@@QAEXHH_N@Z @0x000AD9AB 83B
// Rectangular-grid bit setter: bounds-check x/y against width (+0x08) and
// height (+0x0c), form the byte index pitch(+0x34)*y + (x>>3), range-check it
// against the begin/end byte pointers (+0x44/+0x48), then set/clear bit (x&7).
// Address-derived name; near-twin of the BFME1 BfmeMaskAX::bfmeMarkAX family.

struct Rva000AD9ABBytes
{
	unsigned char *m_begin;
	unsigned char *m_end;

	unsigned size() const { return (unsigned)(m_end - m_begin); }
	unsigned char &operator[](int index) { return m_begin[index]; }
};

class Rva000AD9AB
{
public:
	void rva000AD9AB(int x, int y, bool value);

private:
	char m_pad00[8];
	int m_width;
	int m_height;
	char m_pad10[0x24];
	int m_pitch;
	char m_pad38[0x0c];
	Rva000AD9ABBytes m_bits;
};

void Rva000AD9AB::rva000AD9AB(int x, int y, bool value)
{
	Rva000AD9AB *self = this;

	if (x < 0)
		return;
	if (y < 0)
		return;
	if (y >= self->m_height)
		return;
	if (x >= self->m_width)
		return;

	int index = self->m_pitch * y + (x >> 3);
	if ((unsigned int)index >= self->m_bits.size())
		return;

	unsigned char *slot = self->m_bits.m_begin + index;
	if (value)
		*slot |= (unsigned char)(1 << (x & 7));
	else
		*slot &= (unsigned char)~(1 << (x & 7));
}
