// ??0Rva0042FD9E@@QAE@XZ
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /Os /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// stlport
// ??0Rva0042FD9E@@QAE@XZ, retail 0x0042FD9E, 129 bytes.
// Ctor with vtable 0x00C3C960, map<int,void*> at +0x28, ints/floats zeroed, int at +0x0C set to -1, global 0x00E03220 stores this.
// Evidence: target bytes only; callees map ctor 0x0033C432 and clear 0x00357416 rowed; vtable and global from immediates.
// ??0Rva0042FD9E@@QAE@XZ present-unmatched
#include <map>
extern const void *const g_00C3C960[];
extern void *g_00E03220;
class Rva0042FD9EBase
{
public:
	Rva0042FD9EBase() {}
	~Rva0042FD9EBase();
};
class Rva0042FD9E : public Rva0042FD9EBase
{
public:
	Rva0042FD9E();
private:
	const void *m_vtable;
	bool m_b04;
	bool m_b05;
	bool m_b06;
	bool m_b07;
	int m_i08;
	int m_i0C;
	int m_i10;
	int m_i14;
	int m_i18;
	int m_i1C;
	bool m_b20;
	int m_i24;
	_STL::map<int, void *> m_map28;
	float m_f34;
	float m_f38;
	float m_f3C;
};
Rva0042FD9E::Rva0042FD9E()
	: Rva0042FD9EBase()
	, m_vtable(reinterpret_cast<const void *>(g_00C3C960))
{
	m_i0C = -1;
	m_b04 = false;
	m_b05 = false;
	m_b06 = false;
	m_b07 = false;
	m_i08 = 0;
	m_i10 = 0;
	m_i14 = 0;
	m_i18 = 0;
	m_i1C = 0;
	m_i24 = 0;
	m_f34 = 0.0f;
	m_f38 = 0.0f;
	m_f3C = 0.0f;
	m_b20 = false;
	m_map28.clear();
	g_00E03220 = this;
}
