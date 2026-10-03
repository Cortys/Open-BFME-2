// ?rva00216F3B@Rva00216F3B@@QAEPBVAsciiString@@PBV2@@Z
// partial score=0.96 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
// ?rva00216F3B@Rva00216F3B@@QAEPBVAsciiString@@PBV2@@Z @0x00216F3B 86B banner lookup with BannerMen default.
// Evidence: lea esi [ecx+0xC] table via rowed IterFind 0x0041534B and rowed find 0x00056F61; BannerMen literal via rowed StringBase ctor 0x00037BA0 and rowed releaseBuffer 0x00036410; TheEmptyString default; caller 0x005EB025.
#include "ascii_string.h"

struct Rva0041534BIter
{
	void *m_node;
	void *m_table;
};

struct Rva00056F61Node
{
	Rva00056F61Node *m_next;
	AsciiString m_name;
};

class Rva00056F61
{
public:
	void *rva00056F61(const AsciiString *key);
	Rva0041534BIter rva0041534B(const AsciiString *key);
	void *m_unused;
	Rva00056F61Node **m_begin;
	Rva00056F61Node **m_end;
};

class Rva00216F3B
{
public:
	const AsciiString *rva00216F3B(const AsciiString *key);
private:
	char _pad[0xC];
	Rva00056F61 m_table;
};

// ?rva00216F3B@Rva00216F3B@@QAEPBVAsciiString@@PBV2@@Z present-unmatched
const AsciiString *Rva00216F3B::rva00216F3B(const AsciiString *key)
{
	Rva0041534BIter it = m_table.rva0041534B(key);
	void *node = it.m_node;
	if (node == 0) {
		AsciiString tmp = "BannerMen";
		node = m_table.rva00056F61(&tmp);
		if (node == 0)
			return &AsciiString::TheEmptyString;
	}
	return (const AsciiString *)((const char *)node + 0x10);
}
