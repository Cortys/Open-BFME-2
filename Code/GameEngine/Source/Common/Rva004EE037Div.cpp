// cl: /O1 /MD
//
// ?rva004EE037@Rva004EE037@@QAEIXZ retail 0x004EE037 12B unsigned div.
// Evidence: [ecx+0x74] div by LogicFramesPerSecond 0x009BA4E4; callers 0x005BE3D6 0x005BFDE4.
#define LogicFramesPerSecond (*(const unsigned *)0x00DBA4E4)
class Rva004EE037
{
public:
	unsigned rva004EE037();
private:
	char m_pad[0x74];
	unsigned m_74;
};

unsigned Rva004EE037::rva004EE037()
{
	return m_74 / LogicFramesPerSecond;
}
