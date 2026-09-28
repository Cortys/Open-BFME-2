// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0039B709@Rva0039B709@@QAEIXZ @0x0039B709 15B unsigned div getter
// member at +0xF4 divided by LogicFramesPerSecond at 0x00DBA4E4. Evidence:
// sole caller 0x005BEF34 moves edi to ecx with no stack args and pushes eax.

#define LogicFramesPerSecond (*(const unsigned int *)0x00DBA4E4)

class Rva0039B709
{
public:
	unsigned int rva0039B709(void);
	unsigned int rva0039B718(void);
	unsigned int rva0039B6EE(void);

private:
	char m_pad00[0xF0];
	unsigned int m_fieldF0;
	unsigned int m_fieldF4;
};

unsigned int Rva0039B709::rva0039B709(void)
{
	return m_fieldF4 / LogicFramesPerSecond;
}

struct Global40Holder
{
	char m_pad00[0x40];
	unsigned int m_val40;
};

#define Global40Ptr (*(Global40Holder *const *)0x00DFE78C)

// ?rva0039B718@Rva0039B709@@QAEIXZ @0x0039B718 19B fallback getter: member at
// +0xF0 when nonzero else Global40Ptr->m_val40. Evidence: two callers
// 0x004EE95B adds eax to [esi+0x74] and 0x005BFA63; same class as +0xF4 div.
unsigned int Rva0039B709::rva0039B718(void)
{
	if (m_fieldF0 != 0)
		return m_fieldF0;
	return Global40Ptr->m_val40;
}

// ?rva0039B6EE@Rva0039B709@@QAEIXZ @0x0039B6EE 27B fallback then divide: F0 or
// Global40 divided by LogicFramesPerSecond. Evidence: callers 0x0039B9D1 and
// 0x005BEAE8 in the same big function as the div caller; same class.
unsigned int Rva0039B709::rva0039B6EE(void)
{
	unsigned int val = m_fieldF0;
	if (val == 0)
		val = Global40Ptr->m_val40;
	return val / LogicFramesPerSecond;
}
