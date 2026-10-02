// ?rva00319B97@Rva00319B97@@QAEPAVRva00318B5C@@PAV2@PBV2@@Z
// partial score=0.96 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
// ?rva00319B97@Rva00319B97@@QAEPAVRva00318B5C@@PAV2@PBV2@@Z retail 0x00319B97 51B: copy via rowed 3-arg plus destroy then store returns result.
// Evidence: calls 0x0031968A Rva0031968ACopy and pin 0x00319784 Destroy; chain from 0x0031968A.
class Rva00318B5C
{
public:
	virtual ~Rva00318B5C();
	int m_4;
	int m_8;
	int m_C;
};
Rva00318B5C *Rva0031968ACopy(const Rva00318B5C *first, const Rva00318B5C *last, Rva00318B5C *result, void *tag);
struct BfmeVectorRecord00319C84;
namespace _STL { template <class T> void _Destroy(T, T); }

class Rva00319B97
{
public:
	Rva00318B5C *rva00319B97(Rva00318B5C *result, const Rva00318B5C *src);
private:
	int m_0;
	Rva00318B5C *m_4;
};

// ?rva00319B97@Rva00319B97@@QAEPAVRva00318B5C@@PAV2@PBV2@@Z present-unmatched
Rva00318B5C *Rva00319B97::rva00319B97(Rva00318B5C *result, const Rva00318B5C *src)
{
	char tag;
	Rva00318B5C *newEnd = Rva0031968ACopy(src, m_4, result, &tag);
	_STL::_Destroy((BfmeVectorRecord00319C84 *)newEnd, (BfmeVectorRecord00319C84 *)m_4);
	m_4 = newEnd;
	return result;
}
