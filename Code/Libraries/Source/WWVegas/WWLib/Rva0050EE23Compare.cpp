// cl: /O1 /EHsc
// ?rva0050EE23@Rva0050EE23@@QAEHPBDHUCharCompare@@@Z @0x0050EE23
// (53B): StringBase<char> compareNoCase wrapper extracting data/len with
// empty fallback then tail-calling rowed compareRangeNoCase; unblocks 41B.
// Identity via compareRangeNoCase 0x00005841 plus empty string
// g_Rva0107301CEmptyString plus caller 0x0050F210; /O1 frameless.

struct CharCompare
{
	char m_unused;
};

int __cdecl compareRangeNoCase(const char *a, int alen, const char *b, int blen, CharCompare tag);

extern const char g_Rva0107301CEmptyString;

class Rva0050EE23
{
public:
	int rva0050EE23(const char *b, int blen, CharCompare tag);
private:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		char data[1];
	};
	Header *m_data;
};

int Rva0050EE23::rva0050EE23(const char *b, int blen, CharCompare tag)
{
	int alen;
	if (m_data)
		alen = m_data->length;
	else
		alen = 0;
	const char *a;
	if (m_data)
		a = (const char *)&m_data->data[0];
	else
		a = &g_Rva0107301CEmptyString;
	return compareRangeNoCase(a, alen, b, blen, tag);
}
