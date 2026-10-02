// ??0Rva002893BA@@QAE@XZ
// partial score=0.94 date=2026-10-02
// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT /Ireference/shims/bfmealloc /arch:SSE
// stlport
// ??0Rva002893BA@@QAE@XZ retail 0x002893BA 232 bytes v1.
// Ctor with vtable 0x007FB840, four BfmeE16 vectors, Rva0042526Member,
// RadiusDecalTemplate, RGBColor via setFromInt, floats 0.0f, tails -1.
// Evidence: callers 0x0028A344 0x0028A390; callees rowed Vector_base
// 0x00211E58 Rva0042526Member 0x00042526 RadiusDecal 0x00330E5D setFromInt
// 0x00004EDF; neighbours stlport_map Rva0028951FFind.
#include <vector>

struct BfmeE16 { float x; float y; float z; float w; };
class Rva0042526Member
{
public:
	Rva0042526Member();
	char m_pad[0x4C];
};
class RadiusDecalTemplate
{
public:
	RadiusDecalTemplate();
	char m_pad[0x34];
};
class RGBColor
{
public:
	void setFromInt(int v);
	int m_c[3];
};

class AsciiString
{
public:
	AsciiString(int zero) : m_data(reinterpret_cast<void *>(zero)) {}
	~AsciiString();
private:
	void *m_data;
};

extern const void *const g_00BFB840[];

class Rva002893BABase
{
public:
	Rva002893BABase() {}
	~Rva002893BABase();
};

// ??0Rva002893BA@@QAE@XZ present-unmatched
class Rva002893BA : public Rva002893BABase
{
public:
	virtual ~Rva002893BA();
	Rva002893BA();
private:
	AsciiString m04;
	unsigned char m08;
	char m_pad09[3];
	int m0C;
	int m10;
	int m14;
	int m18;
	int m1C;
	int m20;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m24;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m30;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m3C;
	int m48;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m4C;
	Rva0042526Member m58;
	RadiusDecalTemplate mA4;
	unsigned char mD8;
	char m_padD9[3];
	RGBColor mDC;
	int mE8;
	int mEC;
	int mF0;
	float mF4;
	float mF8;
	int mFC;
	unsigned char m100;
	unsigned char m101;
	unsigned char m102;
	char m_pad103;
	int m104;
};

Rva002893BA::Rva002893BA()
	: m04(0)
	, m08(0)
	, m0C(-1)
	, m10(0)
	, m14(0)
	, m18(0)
	, m1C(0)
	, m20(-1)
	, m48(0)
	, mD8(0)
	, mE8(0)
	, mEC(0)
	, mF0(0)
	, mF4(0.0f)
	, mF8(0.0f)
	, mFC(0)
	, m100(0)
	, m101(0)
	, m102(0)
	, m104(-1)
{
	mDC.setFromInt(0);
}
