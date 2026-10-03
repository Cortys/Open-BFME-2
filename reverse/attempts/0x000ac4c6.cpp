// ?rva000AC4C6@WorldHeightMap@@QAEHH@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /G7 /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS
typedef int Int;
class WorldHeightMap
{
public:
	Int rva000AC4C6(Int arg);
private:
	struct E { Int result; Int start; Int extent; unsigned char pad[0x28-12]; };
	unsigned char m_pad0[0x80c8];
	Int m_intervalCount;
	E m_intervals[1];
};
// ?rva000AC4C6@WorldHeightMap@@QAEHH@Z present-unmatched
Int WorldHeightMap::rva000AC4C6(Int arg)
{
	arg >>= 2;
	Int n = m_intervalCount;
	for (Int i = 0; i < n; ++i) {
		Int s = m_intervals[i].start;
		if (s >= 0) {
			if (arg >= s) {
				Int e = s + m_intervals[i].extent;
				if (arg < e)
					return m_intervals[i].result;
			}
		}
	}
	return -1;
}
