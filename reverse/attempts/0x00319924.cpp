// ?rva00319924@Rva00319924@@QAEHABVAsciiString@@@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva00319924@Rva00319924@@QAEHABVAsciiString@@@Z @0x00319924 73B via indexed get plus StringBase compare count
// Evidence: rowed get@Rva0040CB2CIndexedField 0x0040CB2C plus rowed compare@StringBase@D 0x000069D6; this+0x78 holder; 8-byte entries sar-3
#include "ascii_string.h"
class Rva0040CB2CIndexedField
{
public:
	int get(int index) const;
	char m_pad[0x40];
	char *m_begin;
	char *m_end;
};
struct Rec00319924
{
	int m_unk;
	AsciiString m_str;
};
class Rva00319924
{
public:
	int rva00319924(const AsciiString &key);
private:
	char m_pad[0x78];
	Rva0040CB2CIndexedField *m_78;
};
// ?rva00319924@Rva00319924@@QAEHABVAsciiString@@@Z present-unmatched
int Rva00319924::rva00319924(const AsciiString &key)
{
	int matches = 0;
	for (int i = 0; i < ((m_78->m_end - m_78->m_begin) >> 3); ++i) {
		const Rec00319924 *r = (const Rec00319924 *)m_78->get(i);
		if (r->m_str.compare(key) == 0)
			++matches;
	}
	return matches;
}
