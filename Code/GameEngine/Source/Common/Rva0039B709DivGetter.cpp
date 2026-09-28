// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0039B709@Rva0039B709@@QAEIXZ @0x0039B709 15B unsigned div getter
// member at +0xF4 divided by LogicFramesPerSecond at 0x00DBA4E4. Evidence:
// sole caller 0x005BEF34 moves edi to ecx with no stack args and pushes eax.

#define LogicFramesPerSecond (*(const unsigned int *)0x00DBA4E4)

class Rva0039B709
{
public:
	unsigned int rva0039B709(void);

private:
	char m_pad00[0xF4];
	unsigned int m_fieldF4;
};

unsigned int Rva0039B709::rva0039B709(void)
{
	return m_fieldF4 / LogicFramesPerSecond;
}
