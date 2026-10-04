// ?rva0035385E@Rva0035385E@@QAEXABUCoord3D@@@Z
// partial score=0.95 date=2026-10-04
// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?rva0035385E@Rva0035385E@@QAEXABUCoord3D@@@Z @0x0035385E 64B: chain unique push of Coord3D at +0x3C vector via rowed push_back 0x002CE7DC plus rowed Coord3D equals 0x00003702. Size via pointer difference idiv 12 with push pop plus last via begin size12 minus12 plus equals early-out. Evidence: callees rowed unblocks 0x0036B961 0x0026E074 callers 0x0026E0EC 0x0036B99E.
#include <vector>

struct Coord3DBase
{
	float x;
	float y;
	float z;
};

struct Coord3D : public Coord3DBase
{
	Coord3D(const Coord3D &that) throw();
	bool equals(const Coord3DBase &that) const;
};

class Rva0035385E
{
public:
	void rva0035385E(const Coord3D &src);
private:
	char m_pad[0x3C];
	_STL::vector<Coord3D> m_vec;
};

// ?rva0035385E@Rva0035385E@@QAEXABUCoord3D@@@Z present-unmatched
void Rva0035385E::rva0035385E(const Coord3D &src)
{
	if (m_vec.size() != 0) {
		Coord3D &last = m_vec[m_vec.size() - 1];
		if (last.equals(src)) {
			return;
		}
	}
	m_vec.push_back(src);
}
