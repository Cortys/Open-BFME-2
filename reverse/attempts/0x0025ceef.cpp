// ?Rva0025CEEFCheck@@YA_N_N@Z
// partial score=0.95 date=2026-09-29
// ?Rva0025CEEFCheck@@YA_N_N@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD
// ?Rva0025CEEFCheck@@YA_N_N@Z, retail 0x0025CEEF, 59 bytes.
// Scans the 8-byte records between the host's +0x10/+0x14 bounds (host object
// behind global 0x009FE720, refreshed first via vtable slot 10) and reports
// whether any record has byte0 == 1 with byte2 & 1 while the wanted flag
// differs from the accumulated result.
// Evidence: sole caller at 0x0025D7B6 (unclaimed 527B body); no Code/ TU names
// global 0x009FE720 yet; prev/next rows use /O1 family flags.
struct Item0025CEEF
{
	char m_b0;
	char m_b1;
	char m_b2;
	char m_b3;
	int m_rest;
};

class Rva0025CEEFHost
{
public:
	virtual void slot00();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual void refresh();
	char m_pad[0x0c];
	Item0025CEEF *m_begin;
	Item0025CEEF *m_end;
};

#define TheHost0025CEEF (*(Rva0025CEEFHost **)0x009FE720)

// ?Rva0025CEEFCheck@@YA_N_N@Z present-unmatched
bool Rva0025CEEFCheck(bool wanted)
{
	Rva0025CEEFHost *host = TheHost0025CEEF;
	bool found = false;
	host->refresh();
	host = TheHost0025CEEF;
	Item0025CEEF *end = host->m_end;
	Item0025CEEF *it = host->m_begin;
	while (it != end)
	{
		if (it->m_b0 == 1 && (it->m_b2 & 1) && wanted != found)
			found = true;
		++it;
	}
	return found;
}
