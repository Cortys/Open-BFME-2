// ?rva0005A3FA@Rva0005A3FA@@QAEXABVAsciiString@@M@Z
// partial score=0.92 date=2026-09-29
// ?rva0005A3FA@Rva0005A3FA@@QAEXABVAsciiString@@M@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?rva0005A3FA@Rva0005A3FA@@QAEXABVAsciiString@@M@Z, RVA 0x0005A3FA, 87 bytes.
// __thiscall map insert into map at +0x1b8 via rowed tree insert_unique
// 0x00058CB3 with AsciiString copy at +8 plus float at +0xC as payload.
// Evidence: EH_prolog plus StringBase<D> copy pin 0x000365F0 plus movss
// plus insert_unique row plus releaseBuffer 0x00036410 plus ret8 plus caller
// at 0x0005CA41. Flags from STLport neighbour stlport_vector_unicode_reserve.
#include <map>

class AsciiString
{
public:
	AsciiString(const AsciiString &other);
	~AsciiString();
private:
	void *m_data;
};

bool operator<(const AsciiString &a, const AsciiString &b);

struct TreeHintPayload0005808E
{
	TreeHintPayload0005808E(float f) : m_value(f) {}
	float m_value;
};

typedef _STL::pair<const AsciiString, TreeHintPayload0005808E> TreeHintPair0005808E;

class Rva0005A3FA
{
public:
	void rva0005A3FA(const AsciiString &key, float value);

private:
	char m_pad[0x1b8];
	_STL::map<AsciiString, TreeHintPayload0005808E, _STL::less<AsciiString>, _STL::allocator<TreeHintPair0005808E> > m_map1b8;
};

// ?rva0005A3FA@Rva0005A3FA@@QAEXABVAsciiString@@M@Z present-unmatched
void Rva0005A3FA::rva0005A3FA(const AsciiString &key, float value)
{
	m_map1b8.insert(TreeHintPair0005808E(key, value));
}
