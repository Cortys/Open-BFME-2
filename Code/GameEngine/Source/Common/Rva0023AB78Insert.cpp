// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva0023AB78@Rva0023AB78@@QAEXVAsciiString@@G@Z @0x0023AB78 101B: build BfmeStringRecord00239B46 from AsciiString plus short then list insert via rowed 0x0023A014. Evidence: caller 0x0023ACD6 0x0023AD69; same record as 0x00239B46 with text plus short0.
#include <list>
#include "ascii_string.h"
struct BfmeStringRecord00239B46 {
	AsciiString text;
	unsigned short short0;
};
class Rva0023A014
{
	_STL::list<BfmeStringRecord00239B46> m_list;
public:
	void rva0023A014(const BfmeStringRecord00239B46 *arg);
};
class Rva0023AB78
{
	char m_pad[0xF4];
	Rva0023A014 m_holder;
public:
	void rva0023AB78(AsciiString s, unsigned short v);
};
void Rva0023AB78::rva0023AB78(AsciiString s, unsigned short v)
{
	BfmeStringRecord00239B46 tmp;
	tmp.text = s;
	tmp.short0 = v;
	m_holder.rva0023A014(&tmp);
}
