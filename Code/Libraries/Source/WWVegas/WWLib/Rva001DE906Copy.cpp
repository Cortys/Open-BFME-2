// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?Rva001DE906Copy@@YAPAVRva001DE727@@PAV1@00@Z @0x001DE906 50B array copy of 0x30-sized Rva001DE727 via rowed operator= 0x001DE727.
// Evidence: chain lane callee rowed; caller 0x001DEE1F; count via sub plus idiv 0x30; loop via operator= plus add 0x30.
#define _STLP_NO_EXCEPTIONS 1
#include <map>
#include <vector>

class Rva001DE727
{
public:
	Rva001DE727 &operator=(const Rva001DE727 &that);
private:
	char m_body[0x30];
};

Rva001DE727 *Rva001DE906Copy(Rva001DE727 *first, Rva001DE727 *last, Rva001DE727 *result)
{
	int n = (int)(last - first);
	if (n <= 0)
		return result;
	int count = n;
	do
	{
		*result = *first;
		++first;
		++result;
	} while (--count != 0);
	return result;
}
