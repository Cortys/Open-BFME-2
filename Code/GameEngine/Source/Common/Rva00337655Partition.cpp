// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ?Rva00337655Partition@@YAPAUS4SortElem20@@PAU1@0VRva003371B1@@@Z @0x00337655 101B: unguarded partition over 20-byte sort records with AsciiString pivot
// Evidence: caller 0x00337D6D pushes first last plus on-stack Rva003371B1 pivot from median row 0x00335CFD via ctor row 0x003371B1; compare row 0x000069D6 swap pin 0x003373D9 dtor row 0x003372B7; 0x14 step swap return-esi plus donor BFME1 stlport_sort_s4sortelem20.cpp Intro match retail.
#include "ascii_string.h"

struct S4SortElem20
{
	AsciiString m_str;
	char m_pad[16];
};

class Rva003371B1
{
public:
	~Rva003371B1();
	AsciiString m_str;
private:
	char m_pad[16];
};

namespace _STL
{
	template <class T> void swap(T &, T &);
}

S4SortElem20 *Rva00337655Partition(S4SortElem20 *first, S4SortElem20 *last, Rva003371B1 pivot)
{
	while (true) {
		while (first->m_str.compare(pivot.m_str) < 0)
			++first;
		--last;
		while (pivot.m_str.compare(last->m_str) < 0)
			--last;
		if (!(first < last))
			return first;
		_STL::swap(*first, *last);
		++first;
	}
}
