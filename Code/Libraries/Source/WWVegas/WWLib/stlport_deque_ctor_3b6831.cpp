// cl: /O1 /G7 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <deque>

// ??0Rva003B6831@@QAE@XZ @0x003B6831 (21B): default ctor for a deque holder.
// Calls rowed _Deque_base<BfmeWordValue4> ctor with 0; returns this in eax.
// Evidence: 21B push-ecx/esi shape with base-ctor call 0x00605464, leaf with
// one unclaimed caller; deque layout from StlportNestedWordDeque.

struct BfmeWordValue4
{
	unsigned int bits;
	BfmeWordValue4();
	~BfmeWordValue4() {}
};

class Rva003B6831
{
public:
	Rva003B6831();
private:
	_STL::deque<BfmeWordValue4, _STL::allocator<BfmeWordValue4> > m_deque; // +0x00
};

Rva003B6831::Rva003B6831()
{
}
