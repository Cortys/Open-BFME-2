// ??0Rva000C6A4D@@QAE@XZ
// partial score=0.93 date=2026-09-29
// ??0Rva000C6A4D@@QAE@XZ
// partial score=0.93 date=2026-09-29
// cl: /Ireference/shims/bfmelist /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ??0Rva000C6A4D@@QAE@XZ retail 0x000C6A4D 202 bytes.
// Chain-lane ctor: Rva0042526Member at +4 via rowed 0x00042526, four
// _STL::vector<BfmeE16> at +0x50/+0x78/+0x84/+0x90 via rowed 0x00211E58,
// _STL::list<BfmePod32> at +0x74 via rowed 0x000B92D2, PristineBoneInfoMap
// at +0xA0 via rowed 0x004260FD, array[6] of single-vector wrappers at
// +0xAC via ??_L, scalars zeroed with -1 at +0x70. Evidence: chain lane
// (calls 0x004260FD just landed); callers 0x000C8EEF/0x000C9146; same
// PristineBoneInfoMap anchor as W3DModelDrawO1Inlines.cpp.
#include <vector>
#include <list>
#include <map>

struct BfmeE16 { float x, y, z, w; };

struct BfmePod32 { int a[8]; };
inline bool operator==(const BfmePod32 &x, const BfmePod32 &y) { return x.a[0] == y.a[0]; }
inline bool operator<(const BfmePod32 &x, const BfmePod32 &y) { return x.a[0] < y.a[0]; }

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

struct PristineBoneInfo
{
	unsigned char m_data[52];
};

class Rva0042526Member
{
public:
	Rva0042526Member();
	~Rva0042526Member();
private:
	unsigned char m_pad[0x4C];
};

struct Rva000C6A4DEmptyBase
{
	Rva000C6A4DEmptyBase() : m_0(0) {}
	~Rva000C6A4DEmptyBase();
	int m_0;
};

struct Rva000C6A4DMid
{
	Rva000C6A4DMid() : m_5c(0), m_60(0), m_64(0), m_68(0), m_6c(0), m_70(-1) {}
	int m_5c;
	int m_60;
	unsigned char m_64;
	int m_68;
	int m_6c;
	int m_70;
};

class Rva000C6A4D : public Rva000C6A4DEmptyBase
{
public:
	Rva000C6A4D();
private:
	Rva0042526Member m_4;
	_STL::vector<BfmeE16> m_50;
	Rva000C6A4DMid m_mid;
	_STL::list<BfmePod32> m_74;
	_STL::vector<BfmeE16> m_78;
	_STL::vector<BfmeE16> m_84;
	_STL::vector<BfmeE16> m_90;
	unsigned char m_9c;
	unsigned char m_9d;
	_STL::map<NameKeyType, PristineBoneInfo> m_a0;
	_STL::vector<BfmeE16> m_ac[6];
	unsigned char m_f4;
};

// ??0Rva000C6A4D@@QAE@XZ present-unmatched
Rva000C6A4D::Rva000C6A4D() :
	m_9c(0),
	m_9d(0),
	m_f4(0)
{
}
