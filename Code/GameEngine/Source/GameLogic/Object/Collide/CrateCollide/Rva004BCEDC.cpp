// cl: /O1 /MD
//
// ?rva004BCEDC@Rva004BCEDC@@QAEHXZ, retail 0x004BCEDC, 20 bytes.
// Null-or-flag helper: returns 1 when the pointer at +4 is null or its byte
// at +0x60 is zero, else 0. Evidence: direct byte shape, ret with no stack
// args, callers in CrateCollide-family bodies.

struct Inner
{
	char m_pad[0x60];
	unsigned char m_flag;
};

class Rva004BCEDC
{
public:
	int rva004BCEDC();
	char m_pad0[4];
	Inner *m_ptr;
};

int Rva004BCEDC::rva004BCEDC()
{
	return m_ptr == 0 || m_ptr->m_flag == 0;
}
