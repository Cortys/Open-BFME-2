// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0039B795@Rva0039B795@@QAEXH@Z @0x0039B795 24B conditional add: when the
// global byte at [0x00DFE78C+0x98] is nonzero add the int arg to +0x08.
// Evidence: sole caller 0x003B0D65; global 0xDFE78C shared with 0x0039B718.

struct Global98Flag
{
	char m_pad00[0x98];
	unsigned char m_flag98;
};

#define Global98Ptr (*(Global98Flag *const *)0x00DFE78C)

class Rva0039B795
{
public:
	void rva0039B795(int delta);

private:
	char m_pad00[0x8];
	int m_val08;
};

void Rva0039B795::rva0039B795(int delta)
{
	if (Global98Ptr->m_flag98 == 0)
		return;
	m_val08 += delta;
}
