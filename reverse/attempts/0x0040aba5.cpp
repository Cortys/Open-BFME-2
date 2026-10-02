// ?Rva0040ABA5Find@@YAPBURva0040ABA5Item@@PBU1@0PBVRva0040A7D5@@H@Z
// partial score=0.96 date=2026-10-02
// cl: /O1
// ?Rva0040ABA5Find@@YAPBURva0040ABA5Item@@PBU1@0PBVRva0040A7D5@@H@Z @0x0040ABA5 179B
// Evidence: chain lane; 4-wide unrolled find over 0x10 items via 0x0040A937 row; caller 0x0040AD6B.
class Rva0040A7D5
{
public:
	int rva0040A7D5(int index) const;
private:
	const int *m_begin;
	const int *m_end;
};
bool Rva0040A937Equal(const Rva0040A7D5 *a, const Rva0040A7D5 *b);
struct Rva0040ABA5Item
{
	const int *m_begin;
	const int *m_end;
	int m_u08;
	int m_u0C;
};

// ?Rva0040ABA5Find@@YAPBURva0040ABA5Item@@PBU1@0PBVRva0040A7D5@@H@Z present-unmatched
const Rva0040ABA5Item *Rva0040ABA5Find(const Rva0040ABA5Item *first, const Rva0040ABA5Item *last, const Rva0040A7D5 *val, int tag)
{
	(void)tag;
	const Rva0040ABA5Item *f = first;
	const char *e = (const char *)last;
	int n = (int)((const char *)last - (const char *)first) >> 6;
	while (n > 0) {
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
		++f;
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
		++f;
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
		++f;
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
		++f;
		--n;
	}
	switch ((int)(e - (const char *)f) >> 4) {
	case 3:
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
		++f;
	case 2:
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
		++f;
	case 1:
		if (Rva0040A937Equal((const Rva0040A7D5 *)f, val))
			return f;
	}
	return last;
}
