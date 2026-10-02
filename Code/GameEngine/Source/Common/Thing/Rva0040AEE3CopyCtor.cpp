// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva0040AEE3@@QAE@ABV0@@Z @0x0040AEE3 27B
// Evidence: unlock lane; calls rowed vector<ScienceType> copy 0x0054878E; copies int at +0xC; caller 0x0040B16A.
#include <vector>

enum ScienceType
{
	SCIENCE_NONE = 0
};

class Rva0040AEE3
{
public:
	Rva0040AEE3(const Rva0040AEE3 &other);
private:
	_STL::vector<ScienceType> m_0000;
	int m_000C;
};

Rva0040AEE3::Rva0040AEE3(const Rva0040AEE3 &other)
	: m_0000(other.m_0000)
	, m_000C(other.m_000C)
{
}
