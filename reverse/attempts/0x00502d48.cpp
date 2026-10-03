// ?rva00502D48@Rva00502D48@@QAEPAV1@XZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /EHs-c- /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
//
// ?rva00502D48@Rva00502D48@@QAEPAV1@XZ @0x00502D48 25B: re-init tree member at +0
// via rowed Rva004FF6FF ctor with shared stack dummy. Retail pushes ebp frame,
// reserves one dword, passes [ebp-1] twice to 0x004FF6FF then returns this.
// Caller 0x00502EC6 constructs member at +4 through here.
#include <new>

class Rva004FF6FF
{
public:
	Rva004FF6FF(unsigned dummy0, unsigned dummy1) throw();
};

class Rva00502D48
{
	Rva004FF6FF m_tree;
public:
	Rva00502D48 *rva00502D48();
};

// ?rva00502D48@Rva00502D48@@QAEPAV1@XZ present-unmatched
Rva00502D48 *Rva00502D48::rva00502D48()
{
	unsigned char tmp1;
	unsigned char tmp2;
	m_tree.Rva004FF6FF::Rva004FF6FF((unsigned)&tmp1, (unsigned)&tmp2);
	return this;
}
