// ??0Rva002105A6@@QAE@H@Z
// partial score=0.93 date=2026-09-29
// ??0Rva002105A6@@QAE@H@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /arch:SSE
// stlport
//
// ??0Rva002105A6@@QAE@H@Z @ 0x00210973 133B
// Ctor for Rva002105A6 (0x58 bytes via factory 0x00210AB8). Evidence: ID at
// +0 from counter 0x009FE1BC via caller 0x00210AE5; Rva000D1930 at +4 via
// rowed 0x0020E42C; vectors at +0x20 plus 0x2C via rowed Vector_base BfmeE16
// 0x00211E58; strings at +0x38 plus 0x44 emptied plus -1 at +0x3C plus 0x40;
// floats 0 at +0x48 plus 0x4C plus 0x50 plus table 0x007CCB3C at +0x54; tail
// Clear via rowed 0x00210749; dtor rowed 0x002105A6.

#include <vector>

struct BfmeE16 { float x, y, z, w; };

class AsciiString
{
public:
	AsciiString();
	~AsciiString();
private:
	void *m_data;
};

template <class T> class StringBase
{
	void *m_data;
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
};

class Rva000D1930
{
public:
	Rva000D1930();
	~Rva000D1930() {}
};

class Rva00210749
{
public:
	void rva00210749();
};

extern const float g_007CCB3C;

class Rva002105A6
{
public:
	Rva002105A6(int id);
private:
	int m_id;
	Rva000D1930 m_rva04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
	int m_18;
	int m_1C;
	_STL::vector<BfmeE16> m_vec20;
	_STL::vector<BfmeE16> m_vec2C;
	StringBase<char> m_str38;
	int m_3C;
	int m_40;
	StringBase<char> m_str44;
	float m_48;
	float m_4C;
	float m_50;
	float m_54;
};

// ??0Rva002105A6@@QAE@H@Z present-unmatched
Rva002105A6::Rva002105A6(int id)
	: m_id(id)
	, m_3C(-1)
	, m_40(-1)
{
	m_48 = 0.0f;
	m_4C = 0.0f;
	m_50 = 0.0f;
	m_54 = g_007CCB3C;
	((Rva00210749 *)this)->rva00210749();
}
