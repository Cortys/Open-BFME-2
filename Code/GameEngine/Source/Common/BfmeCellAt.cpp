// BFME1 Bfme5SeventySeven.cpp row-major lookup adapted to target stride.
// Donor labels are provisional; target 0x73BD70 directly calls this lookup.
// The cell record is incomplete here: retail evidence establishes its 0xA8 stride,
// but this function only returns its address.
// cl: /O2 /DNDEBUG /MD
class BfmeCellFD;

class Gen_008F7CD0
{
public:
	BfmeCellFD *bfmeAt(int x, int y) const;
	void rva0073A2A0(BfmeCellFD **first, BfmeCellFD **last, int x1, int x2, int y);

private:
	char m_bfmeHead[0x24];
	int m_bfmeWidth;
	int m_bfmeHeight;
	BfmeCellFD *m_bfmeCells;
};

BfmeCellFD *Gen_008F7CD0::bfmeAt(int x, int y) const
{
	if (x < 0 || x >= m_bfmeWidth || y < 0 || y >= m_bfmeHeight)
		return 0;

	unsigned char *base = reinterpret_cast<unsigned char *>(m_bfmeCells);
	return reinterpret_cast<BfmeCellFD *>(base + (y * m_bfmeWidth + x) * 0xA8);
}

// ?rva0073A2A0@Gen_008F7CD0@@QAEXPAPAVBfmeCellFD@@0HHH@Z @0x0073A2A0 135B: row-range sibling of bfmeAt; same width+0x24 height+0x28 cells+0x2C and 0xA8 stride; callers 0x73A650 0x73AAE0 0x73BAA0 0x73BB40 0x73BBE0 pass grid as this; donor BfmeGridRasterCircle.cpp bfmeGetCellRange plus x2<x1 clamp and *last reload.
void Gen_008F7CD0::rva0073A2A0(BfmeCellFD **first, BfmeCellFD **last, int x1, int x2, int y)
{
	if (x2 < 0 || x1 >= m_bfmeWidth || y < 0 || y >= m_bfmeHeight)
	{
		*last = 0;
		*first = 0;
		return;
	}

	unsigned char *base = reinterpret_cast<unsigned char *>(m_bfmeCells);
	unsigned char *row = base + (y * m_bfmeWidth) * 0xA8;
	*last = reinterpret_cast<BfmeCellFD *>(row);
	*first = reinterpret_cast<BfmeCellFD *>(row);
	if (x2 < x1)
		x2 = x1;
	if (x1 > 0)
		*first = reinterpret_cast<BfmeCellFD *>(row + x1 * 0xA8);
	*last = reinterpret_cast<BfmeCellFD *>(reinterpret_cast<unsigned char *>(*last) + (x2 < m_bfmeWidth ? x2 + 1 : m_bfmeWidth) * 0xA8);
}
