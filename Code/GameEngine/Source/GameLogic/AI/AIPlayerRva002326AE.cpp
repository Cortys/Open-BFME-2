// cl: /O1 /DNDEBUG /MD /EHsc /G7
// ?rva002326AE@AIPlayer@@QAEGEH@Z @0x002326AE 77B unlock lane.
// Evidence: same TU as AIPlayer ctor/dtor/rva00232683; table m_block81C 0x600 at +0x81C as 256 6-byte entries; callers 0x00325AC6 0x0035962B; imul 6 needs /G7.
struct AIPlayerEntry {
	unsigned short a;
	unsigned short b;
	unsigned short c;
};

class AIPlayer {
	char m_pad[0x81C];
public:
	AIPlayerEntry m_entries[256];
	unsigned short rva002326AE(unsigned char code, int which);
};

unsigned short AIPlayer::rva002326AE(unsigned char code, int which)
{
	if (code >= 0x100)
		return 0;
	if (which < 0 || which >= 3)
		return 0;
	if (which == 0)
		return m_entries[code].a;
	if (which == 1)
		return m_entries[code].b;
	return m_entries[code].c;
}
