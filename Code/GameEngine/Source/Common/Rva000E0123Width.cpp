// cl: /O1 /MD
// ?rva000E0123@Rva000E0123@@QAEXM@Z @0x000E0123 71B
// Evidence: unlock 4x Set_Width 0x0015E290 rowed; callers 0x000E09E8 0x000E0A0E in 0x000E0856; this+4 +8 +c +10 SegmentedLineClass ptrs; ret 4 float arg.
class SegmentedLineClass
{
public:
	void Set_Width(float width);
};

class Rva000E0123
{
public:
	void rva000E0123(float width);
private:
	char m_pad[4];
	SegmentedLineClass *m_line0;
	SegmentedLineClass *m_line1;
	SegmentedLineClass *m_line2;
	SegmentedLineClass *m_line3;
};

void Rva000E0123::rva000E0123(float width)
{
	m_line0->Set_Width(width);
	m_line1->Set_Width(width);
	m_line2->Set_Width(width);
	m_line3->Set_Width(width);
}
