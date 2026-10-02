// ?_M_insert_overflow@?$vector@VRva0040AF66@@V?$allocator@VRva0040AF66@@@_STL@@@_STL@@IAEXPAVRva0040AF66@@ABV3@ABU__false_type@2@I_N@Z
// partial score=0.95 date=2026-10-02
// cl: /G7 /arch:SSE /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@VRva0040AF66@@V?$allocator@VRva0040AF66@@@_STL@@@_STL@@IAEXPAVRva0040AF66@@ABV3@ABU__false_type@2@I_N@Z @ 0x0040B8E8 (183B). Vector fill insert overflow.
// Evidence: same shape as rowed 0x0040B834 calling rowed copy 0x0040B1CD construct 0x0040B17B fill 0x0040B1F3 clear 0x0040B5FC allocate 0x0040A673; stride 0x68; caller 0x0040BA6A.
#include <vector>

enum ScienceType
{
	SCIENCE_NONE = 0
};

class BfmeFixedStorage0004543D
{
public:
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other);
private:
	char m_pad[0x1C];
};

class AsciiString
{
public:
	AsciiString(const AsciiString &o);
	~AsciiString();
private:
	char m_pad[4];
};

class Rva0040AF66
{
public:
	Rva0040AF66(const Rva0040AF66 &other);
	Rva0040AF66 &operator=(const Rva0040AF66 &other);
private:
	int m_00;
	_STL::vector<ScienceType> m_04;
	_STL::vector<ScienceType> m_10;
	BfmeFixedStorage0004543D m_1C;
	BfmeFixedStorage0004543D m_38;
	AsciiString m_54;
	AsciiString m_58;
	int m_5C;
	int m_60;
	unsigned char m_64;
};

namespace _STL
{
template <> void _Construct<Rva0040AF66, Rva0040AF66>(Rva0040AF66 *, const Rva0040AF66 &);
}

template void _STL::vector<Rva0040AF66>::_M_insert_overflow(
	Rva0040AF66 *,
	const Rva0040AF66 &,
	const _STL::__false_type &,
	unsigned int,
	bool);
