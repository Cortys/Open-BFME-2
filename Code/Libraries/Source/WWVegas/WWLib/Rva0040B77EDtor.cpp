// cl: /O1 /EHs /Ireference/shims/bfme2_ascii
// ??1Rva0040B77E@@QAE@XZ @ 0x0040B77E (99B). Dtor for 0x28-byte element with vector 0x0040B560 plus three strings plus free of +4.
// Evidence: unlock lane calls rowed vector dtor 0x0040B560 and rowed releaseBuffer 0x00036410 thrice plus rowed free 0x00030830; callers 0x0040BA1A deleting dtor plus 0x0040BEAA loop stride 0x28; EH states 3-2-1-0-minus1.
#include "ascii_string.h"

extern "C" void __cdecl free(void *block);

struct Rva0040B560
{
	void *m_start;
	void *m_finish;
	void *m_end;
	~Rva0040B560();
};

struct Base0040B77E
{
	int m_00;
	void *m_04;
	int m_08;
	int m_0C;
	inline ~Base0040B77E();
};

// ??1Base0040B77E@@QAE@XZ present-unmatched
inline Base0040B77E::~Base0040B77E()
{
	if (m_04)
		free(m_04);
}

class Rva0040B77E : public Base0040B77E
{
public:
	~Rva0040B77E();
private:
	AsciiString m_10;
	AsciiString m_14;
	AsciiString m_18;
	Rva0040B560 m_1C;
};

Rva0040B77E::~Rva0040B77E()
{
}
