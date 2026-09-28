// cl: /O1 /G7
// ?rva00568920@Rva00568920@@QBE_NXZ @0x00568920 25B: all-nonzero test over
// four dwords at +0x2C. Returns false on first zero else true. Same +0x2C
// 4-entry layout as indexed getter 0x005686C1. Caller at 0x00568939 tests al.
// Prev stlport advance and next rb-tree copy share page.
class Rva00568920
{
public:
	bool rva00568920() const;
private:
	char m_pad[0x2C];
	int m_vals[4];
};
bool Rva00568920::rva00568920() const
{
	for (int i = 0; i < 4; ++i)
		if (m_vals[i] == 0)
			return false;
	return true;
}
