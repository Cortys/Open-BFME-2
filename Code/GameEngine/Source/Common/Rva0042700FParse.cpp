// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?Rva0042700FParse@@YAXPAVINI@@HPAV?$vector@UBfmeStringRecord00426A5B@@V?$allocator@UBfmeStringRecord00426A5B@@@_STL@@@_STL@@H@Z @0x0042700F 89B
// retail 0x0042700F 89B: INI token loop filling vector<BfmeStringRecord00426A5B> via rowed getNextTokenOrNull 0x2DEED plus default ctor 0x4267CC plus StringBase::set 0x55F5 plus push_back 0x426EE0 plus releaseBuffer 0x36410; prev Rva00426F17Xfer shares flags; caller 0x427068 passes INI in +8 and vec in +0x10
#include <vector>
#include "ascii_string.h"

struct BfmeStringRecord00426A5B
{
	AsciiString text;
	unsigned char flag0;
	unsigned char flag1;
	unsigned char flag2;
	BfmeStringRecord00426A5B();
};

class INI
{
public:
	const char *getNextTokenOrNull(const char *seps);
};

typedef _STL::vector<BfmeStringRecord00426A5B> BfmeVec00426A5B;

void Rva0042700FParse(INI *ini, int dummy1, BfmeVec00426A5B *vec, int dummy2)
{
	const char *token;
	while ((token = ini->getNextTokenOrNull(0)) != 0)
	{
		BfmeStringRecord00426A5B rec;
		rec.text.set(token);
		vec->push_back(rec);
	}
}

void Rva00427068Parse(INI *ini, int dummy1, BfmeVec00426A5B *vec, int dummy2)
{
	unsigned int oldCount = vec->size();
	Rva0042700FParse(ini, dummy1, vec, dummy2);
	for (unsigned int i = oldCount; i < vec->size(); ++i)
		(*vec)[i].flag0 = 1;
}
